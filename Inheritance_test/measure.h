//=================================
// include guard
#ifndef __MEASURE_H_INCLUDED__
#define __MEASURE_H_INCLUDED__

//=================================
// forward declared dependencies
#include "note.h"

class measure{
   public:
      void setNumber(int n) { 
         number = n; 
      }
      
      int getNumber(){
        return number;
      }
      
   protected:
        int number;
        note n;
};

#endif // __MEASURE_H_INCLUDED__ 