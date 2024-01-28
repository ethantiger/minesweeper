#include "mainwindow.h"

MainWindow::MainWindow() {
  // Setup
  setupWindow();
  setupGrid();
  createTiles(30,16);
}

void MainWindow::setupWindow() {
  this->resize(540,360);
  this->setWindowTitle("Minesweeper");
  this->show();
}

void MainWindow::setupGrid() {
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setContentsMargins(0,0,0,0);

  this->setLayout(gridLayout);
}

void MainWindow::createTiles(int rows, int cols) {
  tileGrid = std::vector<std::vector<Tile*>>(rows, std::vector<Tile*>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Tile *tile = new Tile(QString("%1").arg(i*cols + j + 1), nullptr);
      gridLayout->addWidget(tile,i,j);
      tileGrid[i][j] = tile;
    }
  }
}