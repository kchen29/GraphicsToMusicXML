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

    bool getPdf(QString filename);
    void getPagePixmap();

signals:
    void selectionChanged(QObject *object);

private slots:
    void openFile();
    void cmdAddNode(QPoint pos);
    void cmdAddLink(QPoint press, QPoint release);
    void selectNode(QPoint pos);

private:
    Node *findFirstNodeAt(QPoint point);
    bool link(Node *from, Node *to);
    void removeLink(Node *from, Node *to);

    Ui::GUI *ui;

    Poppler::Document *document = 0;
    QPixmap pagePixmap;

    QGraphicsScene *scene;
    QGraphicsView *view;
    NodeChooser *nodeChooser;
    PropertyEditor *propertyEditor;
};

#endif // GUI_H
