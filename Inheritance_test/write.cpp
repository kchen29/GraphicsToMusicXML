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
   
   //Introduction
   myfile <<"<?xml version=\"1.0\" encoding=\"UTF-8\"?> \n";
   myfile <<"<!DOCTYPE score-partwise PUBLIC \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\" http://www.musicxml.org/dtds/partwise.dtd\">";
   myfile <<"<score-partwise version="3.0">\n";
   myfile << "Measure number (10) is :" << m.getNumber() << "\n";
   myfile.close();
   return 0;
}
