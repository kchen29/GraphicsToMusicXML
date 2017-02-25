#ifndef MEASURE_H
#define MEASURE_H

#include "note.h"

class Measure
{
public:
    Measure();

    int number;
    Note *firstNote;
    Measure *nextMeasure;
};

#endif // MEASURE_H
