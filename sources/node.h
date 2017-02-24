#ifndef NODE_H
#define NODE_H

#include <QGraphicsEllipseItem>

class Node : public QGraphicsEllipseItem
{

public:
    Node(QPointF center, QGraphicsItem *parent = 0);

    static constexpr qreal RADIUS = 5;
};

#endif // NODE_H
