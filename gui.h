#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <poppler/qt5/poppler-qt5.h>

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

private:
      Ui::GUI *ui;

      bool openedDoc;
      Poppler::Document *document;
      QPixmap pagePixmap;

      QGraphicsScene *scene;
      };

#endif // GUI_H
