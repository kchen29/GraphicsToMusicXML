#ifndef GRAPHICSVIEWFILTER_H
#define GRAPHICSVIEWFILTER_H

#include <QObject>
#include <QMouseEvent>

class GraphicsViewFilter : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsViewFilter(QObject *parent = 0) : QObject(parent) {}

signals:
    void leftPressed(QMouseEvent *m);
    void rightPressRelease(QPoint press, QPoint release);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

    QPoint lastRightPress;
};

#endif // GRAPHICSVIEWFILTER_H
