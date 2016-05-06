#include "dduiqrencode_plugin.h"
#include "dduiqrencode.h"

#include <qdeclarative.h>

void DDuiQREncodePlugin::registerTypes(const char *uri)
{
    // @uri com.ddui.qmlcomponents
    qmlRegisterType<DDuiQREncode>(uri, 1, 0, "QtQuick1QREncode");
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(DDuiQREncode, DDuiQREncodePlugin)
#endif
