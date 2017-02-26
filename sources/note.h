#ifndef NOTE_H
#define NOTE_H

#include "node.h"

class Note : public Node
{
public:
    Note(QPointF center, QGraphicsItem *parent = 0);

    int step;
    int octave;
    Note *nextNote;

    int type() const {return NoteType;}
};

#endif // NOTE_H
