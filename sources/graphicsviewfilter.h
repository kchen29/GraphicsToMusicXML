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
    void clicked(QMouseEvent *m);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // GRAPHICSVIEWFILTER_H
