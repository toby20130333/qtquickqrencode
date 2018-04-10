
QT += declarative

TEMPLATE = lib
TARGET = QtQuick1QREncode

CONFIG += qt plugin

uri = com.ddui.qmlcomponents


DESTDIR = $$PWD/../plugins/
MOC_DIR = $$PWD/../.moc
OBJECTS_DIR = $$PWD/../.obj

# Input
INCLUDEPATH += $$PWD
SOURCES += \
    $$PWD/dduiqrencode_plugin.cpp \
    $$PWD/dduiqrencode.cpp

HEADERS += \
    $$PWD/dduiqrencode_plugin.h \
    $$PWD/dduiqrencode.h

CONFIG += DD_USE_C

DD_USE_C:{
   include($$PWD/../qrencode/qrencode.pri)
}
DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

    qmldir.files = qmldir
    maemo5 | !isEmpty(MEEGO_VERSION_MAJOR) {
        installPath = /usr/lib/qt4/imports/$$replace(uri, \\., /)
    } else {
        installPath = $$[QT_INSTALL_IMPORTS]/$$replace(uri, \\., /)
    }
    qmldir.path = $$installPath
    target.path = $$installPath
#install this plugin to qt sdk plugin path
INSTALLS += target qmldir
