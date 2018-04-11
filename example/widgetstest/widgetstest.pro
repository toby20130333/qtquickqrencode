QT += gui core widgets

TARGET = widgetsqrencode

INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD/main.cpp

LIBS += -L$$PWD/../../lib/ -ldduiqrwidgets
DESTDIR = .
INCLUDEPATH += $$PWD/../../include/
DEPENDPATH += $$PWD/../../lib/dduiqrwidgets
