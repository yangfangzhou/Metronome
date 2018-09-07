#include <QGuiApplication>
#include <QQuickView>
#include "Dashboard.h"
#include "Ringboard.h"
#include "drawtest.h"
#include <QTranslator>
int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    qmlRegisterType<Dashboard>("Boards", 1, 0, "Dashboard");
    qmlRegisterType<Ringboard>("Boards", 1, 0, "Ringboard");
    QTranslator p_translator ;
    p_translator.load("zh_CN");

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();
    return app.exec();
}
