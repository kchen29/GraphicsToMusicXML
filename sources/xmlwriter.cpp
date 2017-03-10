#include <QMetaEnum>
#include "xmlwriter.h"

XmlWriter::XmlWriter(QFile &file)
{
    setDevice(&file);
    setAutoFormatting(true);
    setAutoFormattingIndent(2);
}

void XmlWriter::writeTextElement(const QString string, int textValue)
{
    writeTextElement(string, QString::number(textValue));
}

void XmlWriter::writeXml(Part *part)
{
    writeStartDocument();

    QString DTD = "<!DOCTYPE score-partwise PUBLIC\n" \
            "    \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\"\n" \
            "    \"http://www.musicxml.org/dtds/partwise.dtd\">";
    writeDTD(DTD);

    writeStartElement("score-partwise");
    writeAttribute("version", "3.0");

    writeStartElement("part-list");
    writeStartElement("score-part");
    writeAttribute("id", "P1");
    writeTextElement("part-name", "Music");
    writeEndElement(); //score-part
    writeEndElement(); //part-list

    writePart(part);

    writeEndDocument();
}

void XmlWriter::writePart(Part *part)
{
    writeStartElement("part");
    writeAttribute("id", "P1");

    if (part->firstMeasure)
        writeMeasure(part->firstMeasure);

    writeEndElement(); //part
}

void XmlWriter::writeMeasure(Measure *measure)
{
    writeStartElement("measure");
    writeAttribute("number", "1");

    writeStartElement("attributes");

    writeTextElement("divisions", measure->divisions);

    if (measure->key)
        writeKey(measure->key);
    if (measure->time)
        writeTime(measure->time);
    if (measure->clef)
        writeClef(measure->clef);

    writeEndElement(); //attributes

    if (measure->firstNote)
        writeNote(measure->firstNote);

    writeEndElement(); //measure
}

void XmlWriter::writeNote(Note *note)
{
    writeStartElement("note");

    writeStartElement("pitch");

    QMetaEnum meta = QMetaEnum::fromType<Note::Step>();
    writeTextElement("step", meta.valueToKey(note->step));
    writeTextElement("octave", note->octave);
    writeEndElement(); //pitch

    writeTextElement("duration", note->duration);

    writeEndElement(); //note
}

void XmlWriter::writeKey(Key *key)
{
    writeStartElement("key");
    writeTextElement("fifths", key->fifths);
    writeEndElement(); //key
}

void XmlWriter::writeTime(Time *time)
{
    writeStartElement("time");
    writeTextElement("beats", time->beats);
    writeTextElement("beat-type", time->beatType);
    writeEndElement(); //time
}

void XmlWriter::writeClef(Clef *clef)
{
    writeStartElement("clef");

    QMetaEnum meta = QMetaEnum::fromType<Clef::Sign>();
    writeTextElement("sign", meta.valueToKey(clef->sign));
    writeTextElement("line", clef->line);

    writeEndElement(); //clef
}
