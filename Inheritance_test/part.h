//=================================
// include guard
#ifndef __PART_H_INCLUDED__
#define __PART_H_INCLUDED__

//=================================
// forward declared dependencies
#include "measure.h"

class part  {
   public:
      void setPart(int p) {
         part = p;
      }
      
       int getPart(){
        return part;
      }
		
   protected:
      int part;
      measure m;
};

#endif // __PART_H_INCLUDED__ 
