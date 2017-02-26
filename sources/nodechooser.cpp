#include "nodechooser.h"
#include "part.h"

NodeChooser::NodeChooser(QWidget *parent) : QComboBox(parent)
{
    addItems(Node::nodeClasses);
}

//keep in line with Node::nodeClasses
Node *NodeChooser::currentNode()
{
    switch (currentIndex()) {
    case 0:
        return new Part();
    case 1:
        return new Measure();
    case 2:
        return new Note();
    }

    return nullptr;
}
