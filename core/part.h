#ifndef PART_H
#define PART_H

#include "node.h"
#include "measure.h"

class Part : public Node
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER name)

public:
    Part(QObject *parent = nullptr) : Node(parent) {}

    QString id;
    QString name;

    Part *nextPart = nullptr;
    Measure *firstMeasure = nullptr;

    int type() const {return PartType;}
};

#endif // PART_H
