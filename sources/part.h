#ifndef PART_H
#define PART_H

#include "node.h"
#include "measure.h"

class Part : public Node
{
public:
    Part(QPointF center, QGraphicsItem *parent = 0);

    int part;
    Measure *firstMeasure;

    int type() const {return PartType;}
};

#endif // PART_H
