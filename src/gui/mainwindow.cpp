/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Function definitions for the MainWindow class.
 * 
 * Date:
 *  1 Feb 2024
*/

#include "mainwindow.h"

/**
 * MainWindow()
 * Constructor for the MainWindow class.
 * params: none
 * returns: MainWindow
*/
MainWindow::MainWindow() {
  // Indirectly sets up data members
  setupWindow();
  setupGrid();
  createTiles(16,30);
}

/**
 * setupWindow()
 * Sets up the mainwindow
 * params: none
 * returns: none
*/
void MainWindow::setupWindow() {
  this->resize(1000,540);
  this->setWindowTitle("Minesweeper");
  this->show();
}

/**
 * setupGrid()
 * Sets up the grid layout for the mainwindow
 * params: none
 * returns: none
*/
void MainWindow::setupGrid() {
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setContentsMargins(0,0,0,0);
  this->setLayout(gridLayout);
}

/**
 * createTiles()
 * creates 2d vector of Tiles class, sets which tiles become mines, and
 *  calculates number of mines adjacent to each tile.
 * params: 
 *  int r (number of rows)
 *  int c (number of columns)
 * returns: none
*/
void MainWindow::createTiles(int r, int c) {
  tilesRemaining = r * c - 99;
  rows = r;
  cols = c;
  tileGrid = std::vector<std::vector<Tile*>>(rows, std::vector<Tile*>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Tile *tile = new Tile();
      QObject::connect(tile, &QPushButton::clicked, [this, tile, i, j]() {
          explore(tile,i,j);
      });
      connect(tile, &Tile::gameOverReceived, this, &MainWindow::resetGame);
      gridLayout->addWidget(tile,i,j);
      tileGrid[i][j] = tile;
    }
  }
  // Set 99 tiles to mines at random
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrcol(0,cols-1);
  std::uniform_int_distribution<> distrrow(0,rows-1);
  for (int i = 0; i < 99; i++) {
    int random_row = distrrow(gen);
    int random_col = distrcol(gen);
    if (tileGrid[random_row][random_col]->getMine()) {
      i--;
    } else {
      Tile *tile = tileGrid[random_row][random_col];
      tile->setMine(true);
      connect(tile, &Tile::showMines, this, &MainWindow::showMines);
    }  
  }
  // Calculate adjacent mines
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // Check if isMine
      if (tileGrid[i][j]->getMine()) continue;
      // Check up
      if (i - 1 >= 0 && tileGrid[i-1][j]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check down
      if (i + 1 < rows && tileGrid[i+1][j]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check left
      if (j - 1  >= 0 && tileGrid[i][j-1]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check right
      if (j + 1  < cols && tileGrid[i][j+1]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check diagonal up left
      if (i - 1  >= 0 && j - 1 >= 0 && tileGrid[i-1][j-1]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check diagonal up right
      if (i - 1  >= 0 && j + 1 < cols && tileGrid[i-1][j+1]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check diagonal down left
      if (i + 1  < rows && j - 1 >= 0 && tileGrid[i+1][j-1]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
      // Check diagonal down right
      if (i + 1 < rows && j + 1 < cols && tileGrid[i+1][j+1]->getMine()) tileGrid[i][j]->incrementMinesAdjacent();
    }
  }
}

/**
 * showMines()
 * reveals mines on the loss condition
 * params: none
 * returns: none
*/
void MainWindow::showMines() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (tileGrid[i][j]->getMine()) tileGrid[i][j]->showMine();
    }
  }
}

/**
 * explore()
 * explores the tile, and adjacent tiles if there are no surrounding mines.
 *  if all mines are explored, win condition is invoked
 * params:
 *  Tile *t (a pointer to the tile that is being explored)
 *  int i (the row that this tile appears in)
 *  int j (the column that this tile appears in )
 * returns: none
*/
void MainWindow::explore(Tile *t, int i, int j) {
  if (t->getExplored()) return;
  int mines = t->explore();
  if (mines == 0) {
    // Explore surrounding mines
    // Up
    if (i - 1 >= 0 && !tileGrid[i-1][j]->getMine()) explore(tileGrid[i-1][j], i-1,j);
    // Down
    if (i + 1 < rows && !tileGrid[i+1][j]->getMine()) explore(tileGrid[i+1][j], i+1,j);
    // Left
    if (j - 1  >= 0 && !tileGrid[i][j-1]->getMine()) explore(tileGrid[i][j-1], i,j-1);
    // Right
    if (j + 1  < cols && !tileGrid[i][j+1]->getMine()) explore(tileGrid[i][j+1], i,j+1);
    // diagonal up left
    if (i - 1  >= 0 && j - 1 >= 0 && !tileGrid[i-1][j-1]->getMine()) explore(tileGrid[i-1][j-1], i-1,j-1);
    // diagonal up right
    if (i - 1  >= 0 && j + 1 < cols && !tileGrid[i-1][j+1]->getMine()) explore(tileGrid[i-1][j+1], i-1,j+1);
    // diagonal down left
    if (i + 1  < rows && j - 1 >= 0 && !tileGrid[i+1][j-1]->getMine()) explore(tileGrid[i+1][j-1], i+1,j-1);
    // diagonal down right
    if (i + 1 < rows && j + 1 < cols && !tileGrid[i+1][j+1]->getMine()) explore(tileGrid[i+1][j+1], i+1,j+1);
  }
  tilesRemaining--;
  if (tilesRemaining == 0) {
    // win
    Popup p("You Win", "Play again?");
    QObject::connect(&p, &Popup::gameOverSignal,[this]() {
      resetGame();
    });
    p.exec();
  }
}

/**
 * resetGame()
 * resets the tiles in the grid
 * params: none
 * returns: none
*/
void MainWindow::resetGame() {
  // Remove tiles
  for (auto& row : tileGrid) {
    for (auto& tile : row) {
        if (tile->parent()) {
            tile->setParent(nullptr); // Remove from parent widget
        }
    }
  }
  for (auto& row : tileGrid) {
    row.clear(); // Clear each inner vector
  }
  tileGrid.clear(); // Clear the outer vector
  // // Recreate Tiles
  createTiles(16,30);
}

/**
 * ~MainWindow()
 * Destructor for the MainWindow class.
 * params: none
 * returns: None
*/
MainWindow::~MainWindow() {
}
