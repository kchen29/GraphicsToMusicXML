//=================================
// include guard
#ifndef __PART_H_INCLUDED__
#define __PART_H_INCLUDED__

//=================================
// forward declared dependencies
#include "measure.h"

class Part  {
public:
    int part;
    Measure *m;

    std::string writeXML();
};

#endif // __PART_H_INCLUDED__ 
