#include <QFileDialog>
#include <QToolBar>
#include <QAction>
#include <QDebug>

#include "gui.h"
#include "ui_gui.h"
#include "graphicsviewfilter.h"
#include "link.h"
#include "score.h"
#include "xmlwriter.h"

GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setBackgroundBrush(QBrush(Qt::gray));

    GraphicsViewFilter *filter = new GraphicsViewFilter(view);
    view->viewport()->installEventFilter(filter);
    view->installEventFilter(filter);
    connect(filter, &GraphicsViewFilter::leftPressed, this, &GUI::cmdAddNode);
    connect(filter, &GraphicsViewFilter::rightPressRelease, this, &GUI::cmdAddLink);
    connect(filter, &GraphicsViewFilter::sPressed, this, &GUI::selectNode);

    nodeChooser = new NodeChooser(this);
    ui->mainToolBar->addWidget(nodeChooser);

    propertyEditor = new PropertyEditor();
    addDockWidget(Qt::RightDockWidgetArea, propertyEditor);
    connect(this, &GUI::selectionChanged, propertyEditor, &PropertyEditor::updateEditor);

    connect(ui->action_Open_File, &QAction::triggered, this, &GUI::openFile);
    connect(ui->action_Export_Music_XML, &QAction::triggered, this, &GUI::exportMusicXml);
}

GUI::~GUI()
{
    delete ui;
    delete document;
}

void GUI::openFile()
{
    QStringList filterList;
    filterList << "PDF (*.pdf)"
               << "Images (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)";
    QString filters = filterList.at(0);
    for (int i = 1; i < filterList.length(); i++)
        filters += ";;" + filterList.at(i);

    QString selected;
    QString filename = QFileDialog::getOpenFileName(this, "Open File",
                                                    QString(), filters, &selected);
    if (filename.isNull())
        return;

    switch (filterList.indexOf(selected)) {
    case 0:
        if (!getPdf(filename))
            return;
        getPagePixmap();
        scene->clear();
        scene->addPixmap(pagePixmap);
        break;
    case 1:
    {
        QImage image;
        if (!image.load(filename))
            return;
        QPixmap pixmap;
        pixmap.convertFromImage(image);
        scene->clear();
        scene->addPixmap(pixmap);
    }
        break;
    }
}

bool GUI::getPdf(QString filename)
{
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

void GUI::exportMusicXml()
{
    //find part node (for now)
    QList<QGraphicsItem *> items = scene->items();
    Score *score = nullptr;
    for (QGraphicsItem *item : items) {
        if (item->type() == Node::ScoreType) {
            score = static_cast<Score *>(item);
            break;
        }
    }
    if (score == nullptr) {
        qDebug() << "Error: Couldn't find score";
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this, "Save to file",
                                                    QString(), "XML (*.xml)");

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not write to file";
        return;
    }

    //use namespace only eventually?
    XmlWriter writer(file);
    writer.writeXml(score);
}

//the mouse event is in view coordinates
void GUI::cmdAddNode(QPoint pos)
{
    QPointF scenePos = view->mapToScene(pos);

    Node *node = nodeChooser->currentNode();
    node->setPos(scenePos);
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

void GUI::selectNode(QPoint pos)
{
    //make sure pos is visible (in view)
    if (!view->geometry().contains(pos))
        return;

    Node *node = findFirstNodeAt(pos);

    emit selectionChanged(node);
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

#define UNIQUE_LINK(toClass, toName, toAttribute, from) do { \
        toClass *toName = static_cast<toClass *>(to); \
        if (toName->toAttribute) { \
            if (toName->toAttribute == from) \
                return false; \
            removeLink(toName->toAttribute, to); \
        } \
        toName->toAttribute = from; \
        return true; \
    } while (0)

//given from and to, see if they can be linked
bool GUI::link(Node *from, Node *to)
{
    switch (from->type()) {
    case Node::PartType:
    {
        Part *part = static_cast<Part *>(from);

        switch (to->type()) {
        case Node::ScoreType:
            UNIQUE_LINK(Score, scoreTo, firstPart, part);
        case Node::PartType:
            UNIQUE_LINK(Part, partTo, nextPart, part);
        }
    }
    case Node::MeasureType:
    {
        Measure *measure = static_cast<Measure *>(from);

        switch (to->type()) {
        case Node::PartType:/*
        {
            Part *part = static_cast<Part *>(to);
            if (part->firstMeasure) {
                if (part->firstMeasure == measure)
                    return false;
                removeLink(part->firstMeasure, to);
            }
            part->firstMeasure = measure;
            return true;
        }*/
            UNIQUE_LINK(Part, partTo, firstMeasure, measure);
        case Node::MeasureType:
        {
            Measure *measureTo = static_cast<Measure *>(to);
            if (measureTo->nextMeasure) {
                if (measureTo->nextMeasure == measure)
                    return false;
                removeLink(measureTo->nextMeasure, to);
            }
            measureTo->nextMeasure = measure;
            measure->number = measureTo->number + 1;
            return true;
        }
        }

        break;
    }
    case Node::NoteType:
    {
        Note *note = static_cast<Note *>(from);

        switch (to->type()) {
        case Node::MeasureType:
            UNIQUE_LINK(Measure, measureTo, firstNote, note);
        case Node::NoteType:
            UNIQUE_LINK(Note, noteTo, nextNote, note);
        }

        break;
    }
    case Node::ClefType:
    {
        Clef *clef = static_cast<Clef *>(from);

        switch (to->type()) {
        case Node::MeasureType:
            UNIQUE_LINK(Measure, measureTo, clef, clef);
        }
    }
    case Node::KeyType:
    {
        Key *key = static_cast<Key *>(from);

        switch (to->type()) {
        case Node::MeasureType:
            UNIQUE_LINK(Measure, measureTo, key, key);
        }
    }
    case Node::TimeType:
    {
        Time *time = static_cast<Time *>(from);

        switch (to->type()) {
        case Node::MeasureType:
            UNIQUE_LINK(Measure, measureTo, time, time);
        }
    }
    }

    return false;
}

#undef UNIQUE_LINK

void GUI::removeLink(Node *from, Node *to)
{
    //temporary implementation?
    QList<QGraphicsItem *> children = from->childItems();

    QMutableListIterator<QGraphicsItem *> i(children);

    while (i.hasNext()) {
        Link *link = dynamic_cast<Link *>(i.next());
        if (!link)
            continue;
        if (link->to == to) {
            delete link;
            return;
        }
    }

    qDebug() << "No link connecting?";
}
