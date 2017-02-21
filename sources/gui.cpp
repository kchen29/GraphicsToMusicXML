#include <QFileDialog>
#include <QAction>
#include "gui.h"
#include "ui_gui.h"
#include <QDebug>

GUI::GUI(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::GUI)
      {
      ui->setupUi(this);

      scene = new QGraphicsScene(this);

      ui->graphicsView->setScene(scene);
      ui->graphicsView->setBackgroundBrush(QBrush(Qt::gray));
      ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

      connect(ui->action_Open_File, &QAction::triggered, this, &GUI::openPdf);
      }

GUI::~GUI()
      {
      delete ui;
      delete document;
      }

bool GUI::getPdf()
      {
      QString filename = QFileDialog::getOpenFileName();

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