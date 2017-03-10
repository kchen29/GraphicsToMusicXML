#ifndef TIME_H
#define TIME_H

#include "node.h"

class Time : public Node
{
    Q_OBJECT
    Q_PROPERTY(int beats MEMBER beats)
    Q_PROPERTY(int beatType MEMBER beatType)

public:
    Time(QObject *parent = 0) : Node(parent) {}

    int beats = 4;
    int beatType = 4;

    int type() const {return TimeType;}
};
#endif // TIME_H
