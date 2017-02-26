#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <poppler/qt5/poppler-qt5.h>

#include "node.h"

namespace Ui {
class GUI;
}

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();

    void updateScene();

    bool getPdf();
    void getPagePixmap();

private slots:
    void openPdf();
    void cmdAddNode(QMouseEvent *m);
    void cmdAddLink(QPoint press, QPoint release);

private:
    Node *findFirstNodeAt(QPoint point);
    bool link(Node *from, Node *to);

    Ui::GUI *ui;

    Poppler::Document *document = 0;
    QPixmap pagePixmap;

    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // GUI_H
