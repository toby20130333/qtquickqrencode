TEMPLATE = subdirs

SUBDIRS +=  \
                      widgets \
                      example/widgetstest
# Taken from Qt Creator project files
defineTest(minQtVersion) {
    maj = $$1
    min = $$2
    patch = $$3
    isEqual(QT_MAJOR_VERSION, $$maj) {
        isEqual(QT_MINOR_VERSION, $$min) {
            isEqual(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
            greaterThan(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
        }
        greaterThan(QT_MINOR_VERSION, $$min) {
            return(true)
        }
    }
    greaterThan(QT_MAJOR_VERSION, $$maj) {
        return(true)
    }
    return(false)
}
#if qt version greaterthan 5.4.0
message(------QT_VERSION--------$$QT_VERSION)
minQtVersion(5,4,0):{
            SUBDIRS +=  qml2\
                        example/qml2test
    message(------greaterThan--------)
}
#if qt version lessthan 5.4.0
!minQtVersion(5,4,0):{
    message(------lessthan--------)
    SUBDIRS +=  qml1\
           example/qml1test
}
CONFIG += ordered
