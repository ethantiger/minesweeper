#include <QApplication>
#include "./src/gui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.createWindow();
    return app.exec();
}
