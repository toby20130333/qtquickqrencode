TEMPLATE = lib
TARGET = QtQuickQREncode
QT += qml quick
CONFIG += qt plugin
TARGET = $$qtLibraryTarget($$TARGET)
uri = com.duoduo.components
CONFIG += DD_USE_C
DESTDIR = ./libs
MOC_DIR = ./tmp
OBJECTS_DIR = ./obj

# Input
SOURCES += \
    qtquickqrencode_plugin.cpp \
    qrddencode.cpp \
    quickitemgrabber.cpp

HEADERS += \
    qtquickqrencode_plugin.h \
    qrddencode.h \
    quickitemgrabber.h

DD_USE_C:{
    SOURCES +=\
    qrencode/3rd/bitstream.c \
    qrencode/3rd/mask.c \
    qrencode/3rd/mmask.c \
    qrencode/3rd/mqrspec.c \
    qrencode/3rd/qrencode.c \
    qrencode/3rd/qrinput.c \
    qrencode/3rd/qrspec.c \
    qrencode/3rd/rscode.c \
    qrencode/3rd/split.c

HEADERS += \
    qrencode/3rd/bitstream.h \
    qrencode/3rd/config.h \
    qrencode/3rd/mask.h \
    qrencode/3rd/mmask.h \
    qrencode/3rd/mqrspec.h \
    qrencode/3rd/qrencode_inner.h \
    qrencode/3rd/qrencode.h \
    qrencode/3rd/qrinput.h \
    qrencode/3rd/qrspec.h \
    qrencode/3rd/rscode.h \
    qrencode/3rd/split.h
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
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir

