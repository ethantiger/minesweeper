#include "mainwindow.h"

MainWindow::MainWindow() {
  // Setup
  setupWindow();
  setupGrid();
  createTiles(16,30);
}

void MainWindow::setupWindow() {
  this->resize(1000,540);
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
      Tile *tile = new Tile("", nullptr);
      gridLayout->addWidget(tile,i,j);
      tileGrid[i][j] = tile;
    }
  }
  // Set 99 tiles to mines at random
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrcol(0,29);
  std::uniform_int_distribution<> distrrow(0,15);
  for (int i = 0; i < 99; i++) {
    int random_row = distrrow(gen);
    int random_col = distrcol(gen);
    if (tileGrid[random_row][random_col]->getMine()) {
      i--;
    } else {
      tileGrid[random_row][random_col]->setMine(true);
      tileGrid[random_row][random_col]->setText("M");
    }  
  }
}