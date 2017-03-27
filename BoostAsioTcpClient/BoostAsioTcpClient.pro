QT += core
QT -= gui

CONFIG += c++11

TARGET = BoostAsioTcpClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client.cpp

HEADERS += \
    client.h
