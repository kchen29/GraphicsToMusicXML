#include "xmlwriter.h"

XmlWriter::XmlWriter(QFile &file)
{
    stream.setDevice(&file);
    stream.setAutoFormatting(true);

    stream.writeStartDocument();
    stream.writeStartElement("root");
    stream.writeTextElement("text", "this is text");
    stream.writeEndDocument();
}


/* leftover from write.cpp
    //Part p;
    Measure m;
    //Note n;

    //Set values
    //p.part = 5;
    m.number = 7;
    //n.octave = 6;
    //n.step = 4;

    //Open file for output
    std::ofstream myfile;
    myfile.open ("new.xml");//, ios_base::app (for appending to file)

    //Introduction
    myfile <<"<?xml version=\"1.0\" encoding=\"UTF-8\"?> \n";
    myfile <<"<!DOCTYPE score-partwise PUBLIC \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\" http://www.musicxml.org/dtds/partwise.dtd\">\n";
    myfile <<"<score-partwise version=\"3.0\">\n";
    myfile << "Measure number (0) is :" << m.number << "\n";
    myfile.close();
    */
