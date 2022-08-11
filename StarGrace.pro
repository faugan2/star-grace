#-------------------------------------------------
#
# Project created by QtCreator 2022-07-10T01:21:21
#
#-------------------------------------------------

QT       += core gui printsupport sql  webkitwidgets widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StarGrace
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    ajouterpointdevente.cpp \
    listeusers.cpp \
    listpointvente.cpp \
    listclients.cpp \
    transfertproduits.cpp \
    depenses.cpp \
    bris.cpp \
    retrait.cpp \
    infoclient.cpp \
    infostockalerte.cpp \
    infopointdevente.cpp \
    listformat.cpp \
    ajoutcarreaux.cpp \
    ajoutautres.cpp \
    dialog.cpp \
    modifierstock.cpp \
    biz.cpp \
    remise.cpp \
    parametres.cpp \
    droits.cpp \
    impaye.cpp \
    detailsvente.cpp \
    allimpayes.cpp \
    allsa.cpp \
    allprepayement.cpp \
    facture.cpp \
    bon.cpp

HEADERS  += mainwindow.h \
    login.h \
    ajouterpointdevente.h \
    includes.h \
    listeusers.h \
    listpointvente.h \
    listclients.h \
    transfertproduits.h \
    depenses.h \
    bris.h \
    retrait.h \
    infoclient.h \
    infostockalerte.h \
    infopointdevente.h \
    listformat.h \
    ajoutcarreaux.h \
    ajoutautres.h \
    dialog.h \
    modifierstock.h \
    biz.h \
    remise.h \
    parametres.h \
    droits.h \
    impaye.h \
    detailsvente.h \
    allimpayes.h \
    allsa.h \
    allprepayement.h \
    facture.h \
    bon.h

FORMS    += mainwindow.ui \
    login.ui \
    ajouterpointdevente.ui \
    listeusers.ui \
    listpointvente.ui \
    listclients.ui \
    transfertproduits.ui \
    depenses.ui \
    bris.ui \
    retrait.ui \
    infoclient.ui \
    infostockalerte.ui \
    infopointdevente.ui \
    listformat.ui \
    ajoutcarreaux.ui \
    ajoutautres.ui \
    dialog.ui \
    modifierstock.ui \
    biz.ui \
    remise.ui \
    parametres.ui \
    droits.ui \
    impaye.ui \
    detailsvente.ui \
    allimpayes.ui \
    allsa.ui \
    allprepayement.ui \
    facture.ui \
    bon.ui

RESOURCES += \
    img.qrc
