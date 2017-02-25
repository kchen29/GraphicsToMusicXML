#ifndef LINK_H
#define LINK_H

#include <QGraphicsItem>

#include "node.h"

class Link : public QGraphicsItem
{
public:
    //points in scene coordinates
    Link(Node *fromNode, Node *toNode);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //in local coordinates
    QPointF endpoint;
};

#endif // LINK_H
