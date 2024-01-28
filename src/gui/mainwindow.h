#ifndef MAINWINDOW
#define MAINWINDOW

#include <QWidget>
#include <QGridLayout>
#include "tile.h"

class MainWindow: public QWidget {
  private:
    QGridLayout *gridLayout;
    std::vector<std::vector<Tile*>> tileGrid;

  public:
    MainWindow();
    void setupWindow();
    void setupGrid();
    void createTiles(int, int);
};

#endif