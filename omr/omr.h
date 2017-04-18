#ifndef OMR_H
#define OMR_H

#include <QPixmap>
#include <QImage>

class Omr
{
public:
    Omr(QPixmap &pixmap, QImage omrImage);

    void runOMR();

private:
    void binarize();

    //scenePixmap is the pixmap on the scene
    QPixmap scenePixmap;
    //image can be edited
    QImage image;
};

#endif // OMR_H
