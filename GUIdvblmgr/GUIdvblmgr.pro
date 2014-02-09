#-------------------------------------------------
#
# Project created by QtCreator 2014-02-08T23:20:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIdvblmgr
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    button.cpp \
    carddvb.cpp \
    listcards.cpp \
    listcardsdelegate.cpp \
    listmachines.cpp \
    listmachinesdelegate.cpp \
    machine.cpp

HEADERS  += mainwindow.h \
    button.h \
    carddvb.h \
    listcards.h \
    listcardsdelegate.h \
    listmachines.h \
    listmachinesdelegate.h \
    machine.h

FORMS    += mainwindow.ui
