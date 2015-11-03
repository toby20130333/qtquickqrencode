#include "qtquickqrencode_plugin.h"
#include "qrddencode.h"

#include <qqml.h>

void QtQuickQREncodePlugin::registerTypes(const char *uri)
{
    // @uri com.duoduo.components
    qmlRegisterType<QREnCode>(uri, 1, 0, "QREnCode");
}


