#-------------------------------------------------
#
# Project created by QtCreator 2015-01-03T12:04:19
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = ClientTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    protocols/rest_network.cpp

HEADERS += \
    Protocols/network_test.h \
    protocols/rest_network.h

unix:!macx: LIBS += -lprotobuf
