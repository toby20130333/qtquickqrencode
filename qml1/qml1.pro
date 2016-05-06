
QT += declarative

TEMPLATE = lib
TARGET = QtQuick1QREncode

CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.ddui.qmlcomponents


DESTDIR = $$PWD/../plugins/$$qtLibraryTarget($$TARGET)
MOC_DIR = $$PWD/../.moc
OBJECTS_DIR = $$PWD/../.obj

# Input
SOURCES += \
    dduiqrencode_plugin.cpp \
    dduiqrencode.cpp

HEADERS += \
    dduiqrencode_plugin.h \
    dduiqrencode.h
CONFIG += DD_USE_C

DD_USE_C:{
   include(../qrencode/qrencode.pri)
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
    INSTALLS += target qmldir
