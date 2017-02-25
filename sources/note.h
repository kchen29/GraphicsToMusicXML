#ifndef NOTE_H
#define NOTE_H


class Note
{
public:
    Note();

    int step;
    int octave;
    Note *nextNote;
};

#endif // NOTE_H
