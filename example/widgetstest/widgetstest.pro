QT += gui core widgets

TARGET = widgetsqrencode

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/dduiqrwidgets/ -ldduiqrwidgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/dduiqrwidgets/ -ldduiqrwidgetsd

INCLUDEPATH += $$PWD/../../include/
DEPENDPATH += $$PWD/../../lib/dduiqrwidgets
