#ifndef NODECHOOSER_H
#define NODECHOOSER_H

#include <QComboBox>
#include "node.h"

class NodeChooser : public QComboBox
{
    Q_OBJECT

public:
    NodeChooser(QWidget *parent = nullptr);

    Node *currentNode();

    QStringList nodeClasses = {"Part", "Measure", "Note", "Clef"};
};

#endif // NODECHOOSER_H
