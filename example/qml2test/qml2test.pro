TEMPLATE = app

QT += qml quick
CONFIG += c++11

INCLUDEPATH += $$PWD
SOURCES += $$PWD/main.cpp

RESOURCES += $$PWD/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
DESTDIR = .
# Default rules for deployment.
#include(deployment.pri)
