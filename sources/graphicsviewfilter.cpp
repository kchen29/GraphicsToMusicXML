#include "graphicsviewfilter.h"

bool GraphicsViewFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *m = static_cast<QMouseEvent *>(event);
        if (m->button() == Qt::LeftButton) {
            emit clicked(m);
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}
