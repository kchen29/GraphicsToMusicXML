#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QGraphicsEllipseItem>

class Node : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Node(QObject *parent = nullptr);

    enum {
/*
        PartType = UserType + 1,
        MeasureType,
        NoteType,
        ClefType
*/
#define FIRSTNODE(node) node##Type = UserType + 1,
#define NODE(node) node##Type,
#include "../core/nodes.def"
#undef NODE
#undef FIRSTNODE
    };

    static constexpr qreal RADIUS = 8;
};

#endif // NODE_H
