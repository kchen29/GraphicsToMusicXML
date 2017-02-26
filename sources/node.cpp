#include <QBrush>
#include "node.h"

Node::Node(QGraphicsItem *parent)
    : QGraphicsEllipseItem(-RADIUS / 2, -RADIUS / 2, RADIUS, RADIUS, parent)
{
    setBrush( QBrush(Qt::blue) );
}

const QStringList Node::nodeClasses = {"Part", "Measure", "Note"};
