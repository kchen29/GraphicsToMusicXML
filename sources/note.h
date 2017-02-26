#ifndef NOTE_H
#define NOTE_H

#include "node.h"

class Note : public Node
{
public:
    Note(QGraphicsItem *parent = nullptr);

    int step;
    int octave;
    Note *nextNote = nullptr;

    int type() const {return NoteType;}
};

#endif // NOTE_H
