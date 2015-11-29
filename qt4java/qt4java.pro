#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T21:51:06
#
#-------------------------------------------------

QT       += widgets

TARGET = qt4java
TEMPLATE = lib

DEFINES += QT4JAVA_LIBRARY

SOURCES += qt4java.cpp

HEADERS += qt4java.hpp\
        qt4java_global.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
