#ifndef KEY_H
#define KEY_H

#include "node.h"

class Key : public Node
{
    Q_OBJECT
    Q_PROPERTY(int fifths MEMBER fifths)

public:
    Key(QObject *parent = 0) : Node(parent) {}

    int fifths = 0;

    int type() const {return KeyType;}
};
#endif // KEY_H
