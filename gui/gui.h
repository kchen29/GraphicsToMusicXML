#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <poppler/qt5/poppler-qt5.h>

#include "node.h"
#include "nodechooser.h"
#include "propertyeditor.h"

namespace Ui {
class GUI;
}

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();

signals:
    void selectionChanged(QObject *object);

private slots:
    void openFile();
    void exportMusicXml();
    void runOMR();

    void cmdAddNode(QPoint pos);
    void cmdAddLink(QPoint press, QPoint release);
    void selectNode(QPoint pos);

private:
    bool getPdf(QString filename);
    QPixmap getPagePixmap();

    Node *findFirstNodeAt(QPoint point);
    bool link(Node *from, Node *to);
    void linkSideEffects(Node *from, Node *to);
    void removeLink(Node *from, Node *to);

    Ui::GUI *ui;

    //for PDFs
    Poppler::Document *document = 0;
    QPixmap pixmap;

    QGraphicsScene *scene;
    QGraphicsView *view;
    NodeChooser *nodeChooser;
    PropertyEditor *propertyEditor;
};

#endif // GUI_H
