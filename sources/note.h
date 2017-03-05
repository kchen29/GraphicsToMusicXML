#ifndef NOTE_H
#define NOTE_H

#include "node.h"

class Note : public Node
{
    Q_OBJECT
    Q_PROPERTY(Step step MEMBER step)
    Q_PROPERTY(double alter MEMBER alter)
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
    Q_ENUM(Step)

    Step step = Step::A;

    qreal alter = 0;
    int octave = 4;

    Note *nextNote = nullptr;

    int type() const {return NoteType;}
};

#endif // NOTE_H
