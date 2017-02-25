#ifndef MEASURE_H
#define MEASURE_H

#include "node.h"
#include "note.h"

class Measure : public Node
{
public:
    Measure(QPointF center, QGraphicsItem *parent = 0);

    int number;
    Note *firstNote;
    Measure *nextMeasure;

    int type() const {return MeasureType;}
};

#endif // MEASURE_H
