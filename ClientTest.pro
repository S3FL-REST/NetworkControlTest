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
    Protocols/rest_network.pb.cc

HEADERS += \
    Protocols/rest_network.pb.h \
    Protocols/network_test.h

unix:!macx: LIBS += -lprotobuf
