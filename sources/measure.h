#ifndef MEASURE_H
#define MEASURE_H

#include "node.h"
#include "note.h"

class Measure : public Node
{
public:
    Measure(QObject *parent = nullptr);

    int number;
    Note *firstNote = nullptr;
    Measure *nextMeasure = nullptr;

    int type() const {return MeasureType;}
};

#endif // MEASURE_H
