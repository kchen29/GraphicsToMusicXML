#ifndef NOTE_H
#define NOTE_H

#include "node.h"

class Note : public Node
{
    Q_OBJECT
    Q_PROPERTY(int octave MEMBER octave)
public:
    Note(QObject *parent = nullptr);

    enum Step {
        A,
        B,
        C,
        D,
        E,
        F,
        G
    };

    Step step;

    qreal alter;
    int octave;

    Note *nextNote = nullptr;

    int type() const {return NoteType;}
};

#endif // NOTE_H
