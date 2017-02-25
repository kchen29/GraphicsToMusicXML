#include <QHBoxLayout>
#include "nodedialog.h"
#include "part.h"

NodeDialog::NodeDialog(QPointF setCenter, QWidget *parent) : QDialog(parent), center(setCenter)
{
    label = new QLabel("Choose Node: ");

    combo = new QComboBox();
    combo->addItems(nodeClasses);

    button = new QPushButton("OK");

    connect(button, &QPushButton::clicked, this, &NodeDialog::buttonClicked);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addStretch(1);
    layout->addWidget(label);
    layout->addWidget(combo);
    layout->addWidget(button);
    layout->addStretch(1);

    setLayout(layout);
}

void NodeDialog::buttonClicked()
{
    switch(combo->currentIndex()) {
    case 0:
        node = new Part(center);
        break;
    case 1:
        node = new Measure(center);
        break;
    default:
        break;
    }
    accept();
}
