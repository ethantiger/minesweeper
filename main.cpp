/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Entry point of program
 * 
 * Date:
 *  1 Feb 2024
*/

#include <QApplication>
#include "./src/gui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    return app.exec();
}
