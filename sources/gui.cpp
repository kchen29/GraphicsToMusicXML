#include <QFileDialog>
#include <QAction>
#include "gui.h"
#include "ui_gui.h"
#include "graphicsviewfilter.h"
#include "nodedialog.h"
#include "link.h"
#include "part.h"
#include <QDebug>

GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setBackgroundBrush(QBrush(Qt::gray));

    GraphicsViewFilter *filter = new GraphicsViewFilter(this);
    view->viewport()->installEventFilter(filter);
    connect(filter, &GraphicsViewFilter::leftPressed, this, &GUI::cmdAddNode);
    connect(filter, &GraphicsViewFilter::rightPressRelease, this, &GUI::cmdAddLink);

    connect(ui->action_Open_File, &QAction::triggered, this, &GUI::openPdf);
}

GUI::~GUI()
{
    delete ui;
    delete document;
}

bool GUI::getPdf()
{
    QString filter = "PDF (*.pdf)";
    QString filename = QFileDialog::getOpenFileName(this, "Open File",
                                                    QString(), filter);

    Poppler::Document *tempDocument = Poppler::Document::load(filename);

    if (!tempDocument || tempDocument->isLocked()) {
        qDebug() << "Error opening tempDocument";
        delete tempDocument;
        return false;
    }

    //has previous document
    if (document != 0)
        delete document;

    document = tempDocument;
    //document->setRenderHint(Poppler::Document::Antialiasing);

    return true;
}

void GUI::getPagePixmap()
{
    Poppler::Page *pdfPage = document->page(0);

    if (pdfPage == 0) {
        qDebug() << "Error getting PDF page";
        return;
    }

    //get the smaller resolution
    /*
      QSizeF size = pdfPage->pageSizeF();
      qreal xres = size.width();
      qreal yres = size.height();
      yres = yres > xres ? xres : yres;

      QImage pdfImage = pdfPage->renderToImage(yres, yres);
    */
    QImage pdfImage = pdfPage->renderToImage(physicalDpiX(), physicalDpiY());

    delete pdfPage;

    if (pdfImage.isNull()) {
        qDebug() << "Error rendering pdf image";
        return;
    }

    pagePixmap.convertFromImage(pdfImage);
}

void GUI::updateScene()
{
    getPagePixmap();
    scene->clear();
    scene->addPixmap(pagePixmap);
}

void GUI::openPdf()
{
    if (!getPdf())
        return;

    updateScene();
}

//the mouse event is in view coordinates
void GUI::cmdAddNode(QMouseEvent *m)
{
    //qDebug() << "Putting node at x: " << m->x() << "\ty: " << m->y();
    //Open Dialog to choose type of node
    QPoint viewPos = m->pos();
    QPointF scenePos = view->mapToScene(viewPos);

    NodeDialog *nodeDialog = new NodeDialog(scenePos, this);
    nodeDialog->move(m->globalPos());

    if (!nodeDialog->exec())
        return;

    //add node
    Node *node = nodeDialog->node;
    scene->addItem(node);
}

//points in view coordinates
void GUI::cmdAddLink(QPoint press, QPoint release)
{
    //nodes at press and release?
    Node *pressNode = findFirstNodeAt(press);
    Node *releaseNode = findFirstNodeAt(release);

    if (!pressNode || !releaseNode) {
        qDebug() << "No press/release item(s)";
        return;
    } else if (pressNode == releaseNode) {
        qDebug() << "Error: linking object to itself";
        return;
    }

    //can link?
    if (!link(pressNode, releaseNode)) {
        qDebug() << "Error: Can't link.";
        return;
    }

    //show link in graphics
    new Link(pressNode, releaseNode);
}

//uses view->items and iterates through to find first Node
//returns nullptr if none found
Node *GUI::findFirstNodeAt(QPoint point)
{
    QList<QGraphicsItem *> list = view->items(point);

    for (QGraphicsItem *item : list) {
        Node *node = dynamic_cast<Node *>(item);
        if (node)
            return node;
    }

    return nullptr;
}

//given from and to, see if they can be linked
bool GUI::link(Node *from, Node *to)
{
    /*
    switch (from->type()) {
    case Node::PartType:
        qDebug() << "From is type Part";
        break;
    case Node::MeasureType:
        qDebug() << "From is type Measure";
        break;
    }

    switch (to->type()) {
    case Node::PartType:
        qDebug() << "To is type Part";
        break;
    case Node::MeasureType:
        qDebug() << "To is type Measure";
        break;
    }
    */
    switch (from->type()) {
    case Node::MeasureType:
        Measure *measure = static_cast<Measure *>(from);
        if (to->type() == Node::PartType) {
            Part *part = static_cast<Part *>(to);
            part->firstMeasure = measure;
            return true;
        }
    }

    return false;
}
