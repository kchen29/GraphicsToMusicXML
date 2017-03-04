#ifndef GRAPHICSVIEWFILTER_H
#define GRAPHICSVIEWFILTER_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>

class GraphicsViewFilter : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsViewFilter(QGraphicsView *parentView) : QObject(parentView), view(parentView), viewport(view->viewport()) {}

signals:
    void leftPressed(QPoint pos);
    void rightPressRelease(QPoint press, QPoint release);
    void spacePressed(QPoint pos);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void zoom(double factor, QPointF targetViewportPos, QPointF targetScenePos);

    QGraphicsView *view;
    QWidget *viewport;

    const double zoomFactorBase = 1.0015;

    //for rightPressRelease
    QPoint lastRightPress;
};

#endif // GRAPHICSVIEWFILTER_H
