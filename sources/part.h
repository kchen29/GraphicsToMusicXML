#ifndef PART_H
#define PART_H

#include "node.h"
#include "measure.h"

class Part : public Node
{
public:
    Part(QObject *parent = nullptr) : Node(parent) {}

    int part;
    Measure *firstMeasure = nullptr;

    int type() const {return PartType;}
};

#endif // PART_H
