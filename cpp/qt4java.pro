#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T21:51:06
#
#-------------------------------------------------

QT       += widgets

TARGET = qt4java
TEMPLATE = lib

CONFIG += c++11

DEFINES += QT4JAVA_LIBRARY

INCLUDEPATH += \
    $$(JAVA_HOME)/include/ \
    $$(JAVA_HOME)/include/linux/

SOURCES += \
    qt4java_QApplication.cpp \
    qt4java_QObject.cpp \
    qt4java.cpp \
    qt4java_QMainWindow.cpp \
    qt4java_QWidget.cpp \
    qt4java_QPushButton.cpp

HEADERS += \
    qt4java_QApplication.h \
    qt4java_QObject.h \
    qt4java.hpp \
    qt4java_QMainWindow.h \
    qt4java_QWidget.h \
    qt4java_QPushButton.h

