#ifndef MEASURE_H
#define MEASURE_H

#include "node.h"
#include "note.h"
#include "clef.h"
#include "key.h"

class Measure : public Node
{
    Q_OBJECT
    Q_PROPERTY(int divisions MEMBER divisions)

public:
    Measure(QObject *parent = nullptr) : Node(parent) {}

    int divisions = 1;

    Note *firstNote = nullptr;
    Measure *nextMeasure = nullptr;


    Clef *clef = nullptr;
    Key *key = nullptr;

    int type() const {return MeasureType;}
};

#endif // MEASURE_H
