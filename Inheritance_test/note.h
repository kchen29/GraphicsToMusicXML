//=================================
// include guard
#ifndef __NOTE_H_INCLUDED__
#define __NOTE_H_INCLUDED__

//=================================
// forward declared dependencies
class note{
   public:
      void setPitch(int s, int o) { 
         step = s;
         octave = o;  
      }

      int getStep(){
        return step;
      }
      
      int getOctave(){
        return octave;
      }
      
   private:
      int step;
      int octave;
};


#endif // __NOTE_H_INCLUDED__ 
