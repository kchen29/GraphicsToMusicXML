#ifndef GRAPHICSVIEWFILTER_H
#define GRAPHICSVIEWFILTER_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>

class GraphicsViewFilter : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsViewFilter(QGraphicsView *parentView) : QObject(parentView), view(parentView) {}

signals:
    void leftPressed(QMouseEvent *m);
    void rightPressRelease(QPoint press, QPoint release);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void zoom(double factor, QPointF targetViewportPos, QPointF targetScenePos);

    //for zooming
    QGraphicsView *view;
    const double zoomFactorBase = 1.0015;

    //for rightPressRelease
    QPoint lastRightPress;
};

#endif // GRAPHICSVIEWFILTER_H
