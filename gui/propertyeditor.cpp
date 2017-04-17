#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>

#include "propertyeditor.h"

PropertyEditor::PropertyEditor()
{
    setFeatures(QDockWidget::DockWidgetFloatable);

    setWindowTitle("Property Editor");

    mainWidget = new QWidget();

    form = new QFormLayout();

    QLabel *propertyLabel = new QLabel("Property");
    QLabel *valueLabel = new QLabel("Value");
    form->addRow(propertyLabel, valueLabel);

    mainWidget->setLayout(form);
    setWidget(mainWidget);
}

void PropertyEditor::updateEditor(QObject *object)
{
    //clear form
    while (form->rowCount() > 1) {
        form->removeRow(2);
    }

    if (!object) {
        qDebug() << "No Object?";
        return;
    }

    selected = object;

    produceRows();
}

//produce widgets in form of most derived properties
void PropertyEditor::produceRows() {
    const QMetaObject *meta = selected->metaObject();

    for (int i = meta->propertyOffset(); i < meta->propertyCount(); i++)
        produceRow(meta->property(i));

}

//produce row and add to form layout
void PropertyEditor::produceRow(QMetaProperty property)
{
    //add label of property name
    QLabel *label = new QLabel(property.name());

    //add widget corresponding to each property type
    QWidget *value = produceWidget(property);

    form->addRow(label, value);
}

#define CREATE_WIDGET(widgetClass, widgetVar, setFunc, readFunc, widgetSignal, signalClass) {\
    widgetClass *widgetVar = new widgetClass(); \
    widgetVar->setFunc(property.read(selected).readFunc()); \
    connect(widgetVar, widgetSignal, \
            this, [this, property](signalClass val){ property.write(selected, val); }); \
    return widgetVar; \
    }

//produce value widget
QWidget *PropertyEditor::produceWidget(QMetaProperty property)
{
    //create widget
    //read value
    //connect write

    if (property.isEnumType()) {
        QComboBox *combo = new QComboBox();

        //get all enum items
        const QMetaEnum metaEnum = property.enumerator();
        for (int i = 0; i < metaEnum.keyCount(); i++) {
            combo->addItem(metaEnum.key(i));
        }

        //key or value? If all 0-indexed, then it's fine
        combo->setCurrentIndex(property.read(selected).toInt());

        connect(combo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                this, [this, property](int val){ property.write(selected, val); });

        return combo;
    }

    switch (property.type()) {
    case QMetaType::Int:
    /*{
        QSpinBox *spin = new QSpinBox();
        spin->setValue(property.read(selected).toInt());
        connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                this, [this, property](int val){ property.write(selected, val); });
        return spin;
    }*/

        CREATE_WIDGET(QSpinBox, spin, setValue, toInt, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), int);
    case QMetaType::Double:
    /*{
        QDoubleSpinBox *spin = new QDoubleSpinBox();
        spin->setValue(property.read(selected).toDouble());
        connect(spin, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
                this, [this, property](double val){ property.write(selected, val); });
        return spin;
    }*/
        CREATE_WIDGET(QDoubleSpinBox, spin, setValue, toDouble, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), double);
    case QMetaType::QString:
    /*{
        QLineEdit *line = new QLineEdit();
        line->setText(property.read(selected).toString());
        connect(line, &QLineEdit::textEdited,
                this, [this, property](QString val){ property.write(selected, val); });
        return line;
    }*/
        CREATE_WIDGET(QLineEdit, line, setText, toString, &QLineEdit::textEdited, QString);
    default:
        return nullptr;
    }
}

#undef CREATE_WIDGET
