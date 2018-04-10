#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T13:55:04
#
#-------------------------------------------------

QT       += widgets

TARGET = dduiqrwidgets
TEMPLATE = lib

DEFINES += WIDGETS_LIBRARY

DESTDIR = $$PWD/../lib/
MOC_DIR = $$PWD/../.moc
OBJECTS_DIR = $$PWD/../.obj

INCLUDEPATH += $$PWD

SOURCES += $$PWD/dduiqrwidgets.cpp

HEADERS += $$PWD/dduiqrwidgets.h\
        $$PWD/widgets_global.h

CONFIG += DD_USE_C

DD_USE_C:{
   include($$PWD/../qrencode/qrencode.pri)
}
  CHM.path = $$PWD/../include
  CHM.files +=$$PWD/*.h
  CHM.files +=$$PWD/../qrencode/
  INSTALLS += CHM


