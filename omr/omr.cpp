#include "omr.h"

Omr::Omr(QPixmap pixmap, QImage omrImage) : scenePixmap(pixmap), image(omrImage)
{
}

void Omr::runOMR()
{
    binarize();
}

void Omr::binarize()
{

}
