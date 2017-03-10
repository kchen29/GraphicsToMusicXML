#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QFile>
#include <QXmlStreamWriter>

#include "part.h"

class XmlWriter : public QXmlStreamWriter
{
public:
    XmlWriter(QFile &file);

    void writeXml(Part *part);
    void writePart(Part *part);
    void writeMeasure(Measure *measure);
    void writeNote(Note *note);
    void writeKey(Key *key);
    void writeTime(Time *time);
    void writeClef(Clef *clef);
};

#endif // XMLWRITER_H
