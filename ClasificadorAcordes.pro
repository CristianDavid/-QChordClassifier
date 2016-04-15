#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T22:16:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClasificadorAcordes
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        VentanaClasificadorAcordes.cpp \
    TemperamentoIgual.cpp \
    fuzzyLib/operators.cpp \
    fuzzyLib/membership.cpp

HEADERS  += VentanaClasificadorAcordes.h \
    TemperamentoIgual.h \
    fuzzyLib/operators.h \
    fuzzyLib/membership.h

FORMS    += VentanaClasificadorAcordes.ui
