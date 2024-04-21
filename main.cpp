#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "logic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Logic Backend;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/CS300FinalTask/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    QQmlContext* rootContext = engine.rootContext();
    rootContext->setContextProperty("logicClass", &Backend);

    return app.exec();
}
