#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T11:03:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nySensorKonf
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sensorwindow.cpp \
    nysensorkonf.cpp \
    SensorConfiguration.cpp \
    DataBank.cpp \
    SensorConfigurationBank.cpp \
    Controller.cpp \
    MsgHandler.cpp \
    SampleBank.cpp \
    PresetBank.cpp \
    MappingScheme.cpp \
    redigersenskonf.cpp \
    redigersenskonf2.cpp \
    fjernsensorkonf.cpp

HEADERS  += mainwindow.h \
    sensorwindow.h \
    nysensorkonf.h \
    SensorConfigurationBank.hpp \
    DataBank.hpp \
    SensorConfiguration.hpp \
    Controller.hpp \
    message.hpp \
    MsgHandler.hpp \
    MidiSignal.h \
    SampleBank.hpp \
    PresetBank.hpp \
    MappingScheme.h \
    redigersenskonf.h \
    redigersenskonf2.h \
    fjernsensorkonf.h

FORMS    += mainwindow.ui \
    sensorwindow.ui \
    nysensorkonf.ui \
    redigersenskonf.ui \
    redigersenskonf2.ui \
    fjernsensorkonf.ui

OTHER_FILES += \
    nySensorKonf.pro.user.16 \
    nySensorKonf.pro.user
