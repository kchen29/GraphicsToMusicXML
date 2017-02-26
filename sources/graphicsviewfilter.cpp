#include <QApplication>
#include <QtMath>
#include "graphicsviewfilter.h"

bool GraphicsViewFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *m = static_cast<QMouseEvent *>(event);
        if (m->button() == Qt::LeftButton) {
            emit leftPressed(m->pos());
            return true;
        } else if (m->button() == Qt::RightButton) {
            lastRightPress = m->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *m = static_cast<QMouseEvent *>(event);
        if (m->button() == Qt::RightButton) {
            emit rightPressRelease(lastRightPress, m->pos());
            return true;
        }
    } else if (event->type() == QEvent::Wheel && QApplication::keyboardModifiers() == Qt::ControlModifier) {
        QWheelEvent *w = static_cast<QWheelEvent *>(event);
        if (w->orientation() == Qt::Vertical) {
            double angle = w->angleDelta().y();
            double factor = qPow(zoomFactorBase, angle);
            QPointF targetViewportPos = w->pos();
            QPointF targetScenePos = view->mapToScene(w->pos());
            zoom(factor, targetViewportPos, targetScenePos);
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}

void GraphicsViewFilter::zoom(double factor, QPointF targetViewportPos, QPointF targetScenePos)
{
    view->scale(factor, factor);
    view->centerOn(targetScenePos);
    QPointF deltaViewportPos = targetViewportPos
            - QPointF(view->viewport()->width(), view->viewport()->height()) / 2.0;
    QPointF viewportCenter = view->mapFromScene(targetScenePos) - deltaViewportPos;
    view->centerOn(view->mapToScene(viewportCenter.toPoint()));
}
