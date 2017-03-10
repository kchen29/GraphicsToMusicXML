#include "nodechooser.h"
#include "part.h"
#include "clef.h"

NodeChooser::NodeChooser(QWidget *parent) : QComboBox(parent)
{
    addItems(nodeClasses);
}

//keep in line with nodeClasses
Node *NodeChooser::currentNode()
{
    switch (currentIndex()) {
    case 0:
        return new Part();
    case 1:
        return new Measure();
    case 2:
        return new Note();
    case 3:
        return new Clef();
    }

    return nullptr;
}
