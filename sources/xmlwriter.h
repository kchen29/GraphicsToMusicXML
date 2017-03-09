#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QFile>
#include <QXmlStreamWriter>

#include "part.h"

class XmlWriter
{
public:
    XmlWriter(QFile &file, Part *part);

    void writePart(Part *part);
    void writeMeasure(Measure *measure);
    void writeNote(Note *note);

    QXmlStreamWriter stream;
};

#endif // XMLWRITER_H
