#ifndef NODEDIALOG_H
#define NODEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "node.h"

class NodeDialog : public QDialog
{
    Q_OBJECT

public:
    NodeDialog(QPointF setCenter, QWidget *parent = 0);

    //store the result to access outside of class
    Node *node;

public slots:
    void buttonClicked();

private:
    const QStringList nodeClasses = {"Part", "Measure"};
    QLabel *label;
    QComboBox *combo;
    QPushButton *button;

    QPointF center;
};

#endif // NODEDIALOG_H
