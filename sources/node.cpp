#include <QBrush>
#include "node.h"

Node::Node(QPointF center, QGraphicsItem *parent) :
    QGraphicsEllipseItem(center.x() - RADIUS / 2, center.y() - RADIUS / 2, RADIUS, RADIUS, parent)
{
    setBrush( QBrush(Qt::blue) );
}
