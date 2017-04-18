#ifndef OMR_H
#define OMR_H

#include <QImage>

class Omr
{
public:
    Omr(QImage omrImage);

    void runOMR();

private:
    void binarize();

    //image can be edited
    QImage image;
};

#endif // OMR_H
