#include <QApplication>
#include "dduiqrwidgets.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DDuiQRWidgets w;
    w.resize(400,400);
    w.show();
    w.setQrSaveFile("xxx.png");
    return app.exec();
}
