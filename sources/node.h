#ifndef NODE_H
#define NODE_H

#include <QGraphicsEllipseItem>

class Node : public QGraphicsEllipseItem
{
public:
    enum {
        PartType = UserType + 1,
        MeasureType,
        NoteType
    };

    Node(QGraphicsItem *parent = nullptr);

    static const QStringList nodeClasses;

    static constexpr qreal RADIUS = 8;
};

#endif // NODE_H
