#-------------------------------------------------
#
# Project created by QtCreator 2022-07-10T01:21:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StarGrace
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    ajouterpointdevente.cpp

HEADERS  += mainwindow.h \
    login.h \
    ajouterpointdevente.h

FORMS    += mainwindow.ui \
    login.ui \
    ajouterpointdevente.ui

RESOURCES += \
    img.qrc
