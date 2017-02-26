#ifndef PART_H
#define PART_H

#include "node.h"
#include "measure.h"

class Part : public Node
{
public:
    Part(QGraphicsItem *parent = nullptr);

    int part;
    Measure *firstMeasure;

    int type() const {return PartType;}
};

#endif // PART_H
