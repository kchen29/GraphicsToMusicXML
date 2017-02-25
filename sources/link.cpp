#include <QPainter>
#include "link.h"

Link::Link(Node *fromNode, Node *toNode)
    : QGraphicsItem(fromNode), endpoint(toNode->pos() - fromNode->pos())
{

}

QRectF Link::boundingRect() const
{
    QPointF midpoint = endpoint / 2;

    qreal width = qAbs(endpoint.x());
    qreal height = qAbs(endpoint.y());

    return QRectF(midpoint.x() - width / 2, midpoint.y() - height / 2, width, height);
}

void Link::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::green);
    painter->drawLine(QPointF(0, 0), endpoint);
}
