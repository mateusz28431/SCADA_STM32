#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T14:35:22
#
#-------------------------------------------------

QT       += core gui serialport printsupport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCADA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    smtp.cpp \

HEADERS  += mainwindow.h \
    qcustomplot.h \
    smtp.h \

FORMS    += mainwindow.ui
