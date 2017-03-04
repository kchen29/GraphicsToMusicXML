#include <QBrush>

#include "node.h"

Node::Node(QObject *parent)
    : QObject(parent), QGraphicsEllipseItem(-RADIUS / 2, -RADIUS / 2, RADIUS, RADIUS)
{
    setBrush( QBrush(Qt::blue) );
}

const QStringList Node::nodeClasses = {"Part", "Measure", "Note"};
