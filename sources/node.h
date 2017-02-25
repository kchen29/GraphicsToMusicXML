#ifndef NODE_H
#define NODE_H

#include <QGraphicsEllipseItem>

class Node : public QGraphicsEllipseItem
{
public:
    enum {
        PartType = UserType + 1,
        MeasureType,
    };

    Node(QPointF center, QGraphicsItem *parent = 0);

    static constexpr qreal RADIUS = 8;
};

#endif // NODE_H
