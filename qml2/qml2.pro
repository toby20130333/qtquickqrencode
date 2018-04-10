
QT += qml quick
TEMPLATE = lib
TARGET = QtQuick2QREncode

CONFIG += qt plugin
#TARGET = $$qtLibraryTarget($$TARGET)
uri = com.duoduo.components
CONFIG += DD_USE_C

DESTDIR = $$PWD/../plugins/
MOC_DIR = $$PWD/../.moc
OBJECTS_DIR = $$PWD/../.obj

# Input
INCLUDEPATH +=$$PWD
SOURCES += \
    $$PWD/qtquickqrencode_plugin.cpp \
    $$PWD/qrddencode.cpp

HEADERS += \
    $$PWD/qtquickqrencode_plugin.h \
    $$PWD/qrddencode.h

greaterThan(QT_MAJOR_VERSION, 4){
    SOURCES +=$$PWD/quickitemgrabber.cpp
    HEADERS +=$$PWD/quickitemgrabber.h
}
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
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir

