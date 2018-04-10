TEMPLATE = subdirs

SUBDIRS +=  \
                      widgets \
                      example/widgetstest

#if qt version greaterthan 5.4.0
greaterThan(QT_MAJOR_VERSION, 4):{
            SUBDIRS +=  qml2\
                        example/qml2test
}
#if qt version lessthan 5.4.0
lessThan(QT_MINOR_VERSION, 5):{
            SUBDIRS +=  qml1\
                        example/qml1test \
}
CONFIG += ordered
