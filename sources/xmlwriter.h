#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QFile>
#include <QXmlStreamWriter>

class XmlWriter
{
public:
    XmlWriter(QFile &file);

    QXmlStreamWriter stream;
};

#endif // XMLWRITER_H
