#include <QMetaEnum>
#include "xmlwriter.h"

XmlWriter::XmlWriter(QFile &file, Part *part)
{
    stream.setDevice(&file);
    stream.setAutoFormatting(true);
    stream.setAutoFormattingIndent(2);

    stream.writeStartDocument();

    QString DTD = "<!DOCTYPE score-partwise PUBLIC\n" \
            "    \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\"\n" \
            "    \"http://www.musicxml.org/dtds/partwise.dtd\">";
    stream.writeDTD(DTD);

    stream.writeStartElement("score-partwise");
    stream.writeAttribute("version", "3.0");

    stream.writeStartElement("part-list");
    stream.writeStartElement("score-part");
    stream.writeAttribute("id", "P1");
    stream.writeTextElement("part-name", "Music");
    stream.writeEndElement(); //score-part
    stream.writeEndElement(); //part-list

    writePart(part);

    stream.writeEndDocument();
}

void XmlWriter::writePart(Part *part)
{
    stream.writeStartElement("part");
    stream.writeAttribute("id", "P1");

    if (part->firstMeasure)
        writeMeasure(part->firstMeasure);

    stream.writeEndElement(); //part
}

void XmlWriter::writeMeasure(Measure *measure)
{
    stream.writeStartElement("measure");
    stream.writeAttribute("number", "1");

    stream.writeStartElement("attributes");

    stream.writeTextElement("divisions", QString::number(measure->divisions));

    if (measure->key)
        writeKey(measure->key);
    if (measure->clef)
        writeClef(measure->clef);

    stream.writeEndElement(); //attributes

    if (measure->firstNote)
        writeNote(measure->firstNote);

    stream.writeEndElement(); //measure
}

void XmlWriter::writeNote(Note *note)
{
    stream.writeStartElement("note");

    stream.writeStartElement("pitch");

    QMetaEnum meta = QMetaEnum::fromType<Note::Step>();
    stream.writeTextElement("step", meta.valueToKey(note->step));
    stream.writeTextElement("octave", QString::number(note->octave));
    stream.writeEndElement(); //pitch

    stream.writeTextElement("duration", QString::number(note->duration));

    stream.writeEndElement(); //note
}

void XmlWriter::writeClef(Clef *clef)
{
    stream.writeStartElement("clef");

    QMetaEnum meta = QMetaEnum::fromType<Clef::Sign>();
    stream.writeTextElement("sign", meta.valueToKey(clef->sign));
    stream.writeTextElement("line", QString::number(clef->line));

    stream.writeEndElement(); //clef
}

void XmlWriter::writeKey(Key *key)
{
    stream.writeStartElement("key");
    stream.writeTextElement("fifths", QString::number(key->fifths));
    stream.writeEndElement();
}
