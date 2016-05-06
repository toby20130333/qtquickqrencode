#ifndef QTQUICKQRENCODE_PLUGIN_H
#define QTQUICKQRENCODE_PLUGIN_H

#include <QQmlExtensionPlugin>

class QtQuickQREncodePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QTQUICKQRENCODE_PLUGIN_H

