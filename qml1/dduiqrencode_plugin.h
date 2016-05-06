#ifndef DDUIQRENCODE_PLUGIN_H
#define DDUIQRENCODE_PLUGIN_H

#include <QDeclarativeExtensionPlugin>

class DDuiQREncodePlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
#endif

public:
    void registerTypes(const char *uri);
};

#endif // DDUIQRENCODE_PLUGIN_H
