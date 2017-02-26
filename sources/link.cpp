#include <QPainter>
#include <QtMath>

#include "link.h"

Link::Link(Node *fromNode, Node *toNode)
    : QGraphicsItem(fromNode), to(toNode)
{
    //local coordinates
    QPointF endpoint = toNode->pos() - fromNode->pos();

    QLineF line = QLineF(QPointF(), endpoint);
    qreal angle = qDegreesToRadians(line.angle());

    qreal r = Node::RADIUS;
    QPointF starting = QPointF(r * qCos(angle), -r * qSin(angle));
    QPointF ending = endpoint - starting;

    path.moveTo(starting);
    path.lineTo(ending);
}

QRectF Link::boundingRect() const
{
    return path.boundingRect();
}

void Link::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QColor(255, 0, 255));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(path);
}

