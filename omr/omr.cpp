#include "omr.h"

Omr::Omr(QImage omrImage) : image(omrImage)
{
}

void Omr::runOMR()
{
    binarize();
}

void Omr::binarize()
{
    image = image.convertToFormat(QImage::Format_Mono, Qt::MonoOnly|Qt::ThresholdDither|Qt::AvoidDither);
    image.save("img.jpeg");
}
