#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T10:59:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsToMusicXML
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += core/main.cpp \
    gui/graphicsviewfilter.cpp \
    gui/gui.cpp \
    gui/link.cpp \
    gui/node.cpp \
    gui/nodechooser.cpp \
    gui/propertyeditor.cpp \
    xml/xmlwriter.cpp

HEADERS  += core/clef.h \
    core/key.h \
    core/measure.h \
    core/note.h \
    core/nodes.def \
    core/part.h \
    core/score.h \
    core/time.h \
    gui/graphicsviewfilter.h \
    gui/gui.h \
    gui/link.h \
    gui/node.h \
    gui/nodechooser.h \
    gui/propertyeditor.h \
    xml/xmlwriter.h \
    core/node.h

FORMS    += gui/gui.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += poppler-qt5
