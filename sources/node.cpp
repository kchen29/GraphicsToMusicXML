#include <QBrush>
#include "node.h"

Node::Node(QPointF center, QGraphicsItem *parent) :
    QGraphicsEllipseItem(-(RADIUS / 2), -(RADIUS / 2), RADIUS, RADIUS, parent)
{
    setBrush( QBrush(Qt::blue) );
    setPos(center);
}
