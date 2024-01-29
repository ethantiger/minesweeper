#ifndef MAINWINDOW
#define MAINWINDOW

#include <QWidget>
#include <QGridLayout>
#include <random>
#include "tile.h"
#include "popup.h"

class MainWindow: public QWidget {
  Q_OBJECT
  private:
    QGridLayout *gridLayout;
    std::vector<std::vector<Tile*>> tileGrid;
    int rows;
    int cols;
    int tilesRemaining;

  public:
    MainWindow();
    void setupWindow();
    void setupGrid();
    void createTiles(int, int);
    

  private slots:
    void explore(Tile *, int, int);
    void resetGame();
};

#endif