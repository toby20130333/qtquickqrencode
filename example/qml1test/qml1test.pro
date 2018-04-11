TEMPLATE = app

#QT += qml quick
QT += declarative
CONFIG += c++11

INCLUDEPATH +=$$PWD

SOURCES += $$PWD/main.cpp

RESOURCES += $$PWD/qml.qrc
DESTDIR = .
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
#include(deployment.pri)
