#-------------------------------------------------
#
# Project created by QtCreator 2022-07-26T13:09:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sample_FileCopyMoveDelete
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cpushbuttondroplistener.cpp

HEADERS  += mainwindow.h \
    macros.h \
    errors.h \
    cpushbuttondroplistener.h

FORMS    += mainwindow.ui
