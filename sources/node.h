#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QGraphicsEllipseItem>

class Node : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Node(QObject *parent = nullptr);

    enum {
        PartType = UserType + 1,
        MeasureType,
        NoteType,
        ClefType
    };

    static const QStringList nodeClasses;

    static constexpr qreal RADIUS = 8;
};

#endif // NODE_H
