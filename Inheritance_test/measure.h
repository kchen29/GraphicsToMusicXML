//=================================
// include guard
#ifndef __MEASURE_H_INCLUDED__
#define __MEASURE_H_INCLUDED__

//=================================
// forward declared dependencies
#include "note.h"

class Measure{
public:
    int number;
    Note *n;
    Measure *m;
};

#endif // __MEASURE_H_INCLUDED__ 
