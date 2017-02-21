#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T10:59:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = perspicientia
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


SOURCES += main.cpp\
        gui.cpp \
    Inheritance_test/write.cpp \

HEADERS  += gui.h \
    Inheritance_test/measure.h \
    Inheritance_test/note.h \
    Inheritance_test/part.h \
    Inheritance_test/write.h

FORMS    += gui.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += poppler-qt5
