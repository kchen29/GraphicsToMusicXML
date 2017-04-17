#ifndef CLEF_H
#define CLEF_H

#include "node.h"

class Clef : public Node
{
    Q_OBJECT
    Q_PROPERTY(Sign sign MEMBER sign)
    Q_PROPERTY(int line MEMBER line)

public:
    Clef(QObject *parent = 0) : Node(parent) {}

    enum Sign {
        G,
        C,
        F
    };
    Q_ENUM(Sign)

    Sign sign = Sign::G;
    int line = 2;

    int type() const {return ClefType;}
};
#endif // CLEF_H
