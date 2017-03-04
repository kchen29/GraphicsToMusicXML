#ifndef PROPERTYEDITOR_H
#define PROPERTYEDITOR_H

#include <QDockWidget>
#include <QMetaProperty>
#include <QFormLayout>

class PropertyEditor : public QDockWidget
{
public:
    PropertyEditor();

public slots:
    void updateEditor(QObject *object);

private:
    void produceRows();
    void produceRow(QMetaProperty property);
    QWidget *produceWidget(QMetaProperty property);

    QWidget *mainWidget;
    QFormLayout *form;
    QObject *selected;
};

#endif // PROPERTYEDITOR_H
