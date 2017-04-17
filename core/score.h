#ifndef SCORE_H
#define SCORE_H

#include "node.h"
#include "part.h"

class Score : public Node
{
    Q_OBJECT

public:
    Score(QObject *parent = nullptr) : Node(parent) {}

    Part *firstPart = nullptr;

    int type() const {return ScoreType;}
};

#endif // SCORE_H
