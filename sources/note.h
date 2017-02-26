#ifndef NOTE_H
#define NOTE_H

#include "node.h"

class Note : public Node
{
public:
    Note(QGraphicsItem *parent = nullptr);

    int step;
    int octave;
    Note *nextNote;

    int type() const {return NoteType;}
};

#endif // NOTE_H
