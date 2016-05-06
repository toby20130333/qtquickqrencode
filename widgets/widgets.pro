#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T13:55:04
#
#-------------------------------------------------

QT       += widgets

TARGET = dduiqrwidgets
TEMPLATE = lib

DEFINES += WIDGETS_LIBRARY

DESTDIR = $$PWD/../lib/$$qtLibraryTarget($$TARGET)
MOC_DIR = $$PWD/../.moc
OBJECTS_DIR = $$PWD/../.obj

SOURCES += dduiqrwidgets.cpp

HEADERS += dduiqrwidgets.h\
        widgets_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
win32:{
  CHM.path = $$PWD/../include
  CHM.files +=$$PWD/*.h
  CHM.files +=$$PWD/../qrencode/
  INSTALLS += CHM
}
CONFIG += DD_USE_C

DD_USE_C:{
   include(../qrencode/qrencode.pri)
}
