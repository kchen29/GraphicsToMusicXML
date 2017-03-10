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
    /*
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
    */
    int index = currentIndex();
    int i = 0;
#define FIRSTNODE(node) if (index == i++) return new node();
#define NODE(node) FIRSTNODE(node)
#include "nodes.def"
#undef NODE
#undef FIRSTNODE

    return nullptr;
}

//const QStringList NodeChooser::nodeClasses = {"Part", "Measure", "Note", "Clef"};
const QStringList NodeChooser::nodeClasses = {
    #define FIRSTNODE(node) #node,
    #define NODE(node) FIRSTNODE(node)
    #include "nodes.def"
    #undef NODE
    #undef FIRSTNODE
};
