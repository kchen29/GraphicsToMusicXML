#include "omr.h"

Omr::Omr(QPixmap& pixmap, QImage omrImage) : scenePixmap(pixmap), image(omrImage)
{
}

void Omr::runOMR()
{
    binarize();
}

void Omr::binarize()
{
    image = image.convertToFormat(QImage::Format_Mono, Qt::MonoOnly|Qt::ThresholdDither|Qt::AvoidDither);
    scenePixmap.convertFromImage(image);
    //image.save("img.jpeg");
    scenePixmap.save("img2.jpeg");
}
