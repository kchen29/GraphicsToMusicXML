#include <QFileDialog>
#include <QAction>
#include "gui.h"
#include "ui_gui.h"
#include "graphicsviewfilter.h"
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
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    GraphicsViewFilter *filter = new GraphicsViewFilter(this);
    view->viewport()->installEventFilter(filter);
    connect(filter, &GraphicsViewFilter::clicked, this, &GUI::putNode);

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
void GUI::putNode(QMouseEvent *m)
{
    //qDebug() << "Putting node at x: " << m->x() << "\ty: " << m->y();
    //Open Dialog to choose type of node
    //add node
}
