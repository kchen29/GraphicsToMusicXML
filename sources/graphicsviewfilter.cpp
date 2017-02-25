#include "graphicsviewfilter.h"

bool GraphicsViewFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *m = static_cast<QMouseEvent *>(event);
        if (m->button() == Qt::LeftButton) {
            emit leftPressed(m);
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
    }

    return QObject::eventFilter(obj, event);
}
