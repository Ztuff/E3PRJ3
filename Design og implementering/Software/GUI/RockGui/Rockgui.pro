#-------------------------------------------------
#
# Project created by QtCreator 2014-10-24T13:35:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sensorwindow.cpp \
    presetwindow.cpp \
    lydpakkerwindow.cpp \
    importerlydpakke.cpp \
    sletlydpakke.cpp \
    nypreset.cpp \
    redigerpreset.cpp \
    sletpreset.cpp \
    nysensorkonf.cpp \
    redigersensorkonfi.cpp \
    sletsensorkonf.cpp \
    sensorliste.cpp \
    msghandling.cpp

HEADERS  += mainwindow.h \
    sensorwindow.h \
    presetwindow.h \
    lydpakkerwindow.h \
    importerlydpakke.h \
    sletlydpakke.h \
    nypreset.h \
    redigerpreset.h \
    sletpreset.h \
    nysensorkonf.h \
    redigersensorkonfi.h \
    sletsensorkonf.h \
    sensorliste.h \
    msghandling.h \
    Controller.hpp

FORMS    += mainwindow.ui \
    sensorwindow.ui \
    presetwindow.ui \
    lydpakkerwindow.ui \
    importerlydpakke.ui \
    sletlydpakke.ui \
    nypreset.ui \
    redigerpreset.ui \
    sletpreset.ui \
    nysensorkonf.ui \
    redigersensorkonfi.ui \
    sletsensorkonf.ui \
    sensorliste.ui
