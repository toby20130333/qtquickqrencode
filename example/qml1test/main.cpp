#include <QApplication>
#include <QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDeclarativeView *view = new QDeclarativeView;
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setSource(QUrl("qrc:/main.qml"));
    view->show();
    return app.exec();
}
