#include <QApplication>
#include <QtMath>
#include "graphicsviewfilter.h"

bool GraphicsViewFilter::eventFilter(QObject *obj, QEvent *event)
{
    bool mouse = obj == viewport;
    bool key = obj == view;

    if (mouse && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *m = static_cast<QMouseEvent *>(event);
        if (m->button() == Qt::LeftButton) {
            emit leftPressed(m->pos());
            return true;
        } else if (m->button() == Qt::RightButton) {
            lastRightPress = m->pos();
            return true;
        }
    } else if (mouse && event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *m = static_cast<QMouseEvent *>(event);
        if (m->button() == Qt::RightButton) {
            emit rightPressRelease(lastRightPress, m->pos());
            return true;
        }
    } else if (mouse && event->type() == QEvent::Wheel && QApplication::keyboardModifiers() == Qt::ControlModifier) {
        QWheelEvent *w = static_cast<QWheelEvent *>(event);
        if (w->orientation() == Qt::Vertical) {
            double angle = w->angleDelta().y();
            double factor = qPow(zoomFactorBase, angle);
            QPointF targetViewportPos = w->pos();
            QPointF targetScenePos = view->mapToScene(w->pos());
            zoom(factor, targetViewportPos, targetScenePos);
            return true;
        }
    } else if (key && event->type() == QEvent::KeyPress) {
        QKeyEvent *k = static_cast<QKeyEvent *>(event);
        if (k->key() == Qt::Key_Space) {
            QPoint global = QCursor::pos();
            QPoint local = view->mapFromGlobal(global);
            emit spacePressed(local);
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
