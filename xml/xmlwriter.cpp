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

void XmlWriter::writeXml(Score *score)
{
    writeStartDocument();

    QString DTD = "<!DOCTYPE score-partwise PUBLIC\n" \
            "    \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\"\n" \
            "    \"http://www.musicxml.org/dtds/partwise.dtd\">";
    writeDTD(DTD);

    writeScore(score);

    writeEndDocument();
}

void XmlWriter::writeScore(Score *score)
{
    writeStartElement("score-partwise");
    writeAttribute("version", "3.0");

    writeStartElement("part-list");

    int i = 1;
    for (Part *part = score->firstPart; part; part = part->nextPart) {
        part->id = "P" + QString::number(i);
        i++;

        writeStartElement("score-part");
        writeAttribute("id", part->id);
        writeTextElement("part-name", part->name);
        writeEndElement(); //score-part
    }

    writeEndElement(); //part-list

    for (Part *part = score->firstPart; part; part = part->nextPart)
        writePart(part);

    writeEndElement(); //score-partwise
}

void XmlWriter::writePart(Part *part)
{
    writeStartElement("part");
    writeAttribute("id", part->id);

    for (Measure *measure = part->firstMeasure; measure; measure = measure->nextMeasure)
        writeMeasure(measure);

    writeEndElement(); //part
}

void XmlWriter::writeMeasure(Measure *measure)
{
    writeStartElement("measure");
    writeAttribute("number", QString::number(measure->number));

    //for now
    if (measure->number == 1) {
        writeStartElement("attributes");

        writeTextElement("divisions", measure->divisions);

        if (measure->key)
            writeKey(measure->key);
        if (measure->time)
            writeTime(measure->time);
        if (measure->clef)
            writeClef(measure->clef);

        writeEndElement(); //attributes
    }

    for (Note *note = measure->firstNote; note; note = note->nextNote)
        writeNote(note);

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
