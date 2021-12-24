#-------------------------------------------------
#
# Project created by QtCreator 2021-12-20T10:54:52
#
#-------------------------------------------------

QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sample_QSqlConnection
TEMPLATE = app

ICON = :/icons/images/app_logo.png

SOURCES += main.cpp\
        mainwindow.cpp \
    caboutapplication.cpp \
    cpersondetails.cpp

HEADERS  += mainwindow.h \
    macros.h \
    caboutapplication.h \
    structure.h \
    cpersondetails.h

FORMS    += mainwindow.ui \
    caboutapplication.ui \
    cpersondetails.ui

RESOURCES += \
    resources.qrc
