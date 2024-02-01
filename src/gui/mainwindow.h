/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Declaration of the MainWindow class.
 *  MainWindow is the window in which all the other Qt widgets
 *  will reside.
 * 
 * Date:
 *  1 Feb 2024
*/

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
    void showMines();
    ~MainWindow();
    
  private slots:
    void explore(Tile *, int, int);
    void resetGame();
};

#endif
