#include <iostream>
#include <fstream>
#include "part.h"
#include "measure.h"
#include "note.h"
 
using namespace std;


int main(void) {
    part p;
    measure m;
    note n;
        
    //Set values
   p.setPart(5);
   m.setNumber(7);
   n.setPitch(2,3);
   
    //Open file for output
   ofstream myfile;
   myfile.open ("test.xml");//, ios_base::app (for appending to file)
   myfile << "Measure number (7) is :" << m.getNumber() << "\n";
   myfile.close();
   return 0;
}
