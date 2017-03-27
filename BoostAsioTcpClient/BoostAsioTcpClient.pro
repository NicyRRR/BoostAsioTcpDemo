TEMPLATE = app
QT += qml quick widgets core
CONFIG += c++11
TARGET = BoostAsioTcpClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client.cpp \
    singleApplication.cpp

HEADERS += \
    client.h \
    singleApplication.h
