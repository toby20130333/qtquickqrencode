
QT += gui core widgets quick qml

TEMPLATE = subdirs

SUBDIRS +=  qml2\
                      qml1 \
                      widgets \
                      example/qml1test \
                      example/qml2test \
                      example/widgetstest
CONFIG += ordered
