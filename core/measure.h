#ifndef MEASURE_H
#define MEASURE_H

#include "node.h"
#include "note.h"
#include "key.h"
#include "time.h"
#include "clef.h"


class Measure : public Node
{
    Q_OBJECT
    Q_PROPERTY(int divisions MEMBER divisions)
    Q_PROPERTY(int number MEMBER number)

public:
    Measure(QObject *parent = nullptr) : Node(parent) {}

    int divisions = 1;
    int number = 1;

    Note *firstNote = nullptr;
    Measure *nextMeasure = nullptr;

    Key *key = nullptr;
    Time *time = nullptr;
    Clef *clef = nullptr;

    int type() const {return MeasureType;}
};

#endif // MEASURE_H
