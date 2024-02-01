/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Function definitions for the Tile class
 * 
 * Date:
 *  1 Feb 2024
*/

#include "tile.h"

/**
 * mousePressEvent()
 * controls the mouse press event for a tile
 * params:
 *  QMouseEvent *event (mouse event)
 * returns: none
*/
void Tile::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::RightButton) {
    flag();
  } else {
    QPushButton::mousePressEvent(event);
  }
}

/**
 * Tile()
 * Constructor for the Tile class
 * params: none
 * returns: Tile
*/
Tile::Tile() {
  size = 35;
  isMine = false;
  minesAdjacent = 0;
  explored = false;
  flagState = BLANK;
  this->setStyleSheet("QPushButton {border:1px solid;}");
  setFixedSize(size,size);
}

/**
 * getMine()
 * returns whether tile is a mine or not
 * params: none
 * returns: bool
*/
bool Tile::getMine() {
  return isMine;
}

/**
 * setMine()
 * sets the isMine data member to a given boolean
 * params:
 *  bool b (whether a tile is a mine or not)
 * returns: none
*/
void Tile::setMine(bool b) {
  isMine = b;
}

/**
 * getMinesAdjacent()
 * returns the number of mines adjacent to the tile
 * params: none
 * returns: int
*/
int Tile::getMinesAdjacent() {
  return minesAdjacent;
}

/**
 * incrementMinesAdjacent()
 * adds 1 to the minesAdjacent data member and returns it
 * params: none
 * returns: int
*/
int Tile::incrementMinesAdjacent() {
  minesAdjacent += 1;
  return minesAdjacent;
}

/**
 * getExplored()
 * returns whether the tile was explored already
 * params: none
 * returns: bool
*/
bool Tile::getExplored() {
  return explored;
}

/**
 * showMine()
 * reveals the Tile as a mine
 * params: none
 * returns: none
*/
void Tile::showMine() {
  if (isMine) {
    setIcon(QIcon(":/assets/minesweeper_icons/bomb.png"));
    setIconSize(QSize(size,size));
  }
}

/**
 * explore()
 * explores a tile. if it is a mine, lose. otherwise reveal number
 *  of adjacent mines.
 * params: none
 * returns: int
*/
int Tile::explore() {
  explored = true;
  setIcon(QIcon());
  this->setStyleSheet("QPushButton {background:#222021;}");
  if (isMine) {
    // end game
    emit showMines();
    setIcon(QIcon(":/assets/minesweeper_icons/bomb_explode.png"));
    setIconSize(QSize(size,size));
    Popup p("Game Over", "Retry");
    QObject::connect(&p, &Popup::gameOverSignal,[this]() {
      emit gameOverReceived();
    });
    p.exec();
    return -1;
  }
  if (minesAdjacent) {
    this->setText(QString("%1").arg(minesAdjacent));
  } else {
    this->setText("");
  }
  return minesAdjacent;
}

/**
 * flag()
 * conditions for right clicking a tile
 * params: none
 * returns: none
*/
void Tile::flag() {
  if (explored) return;
  if (flagState == BLANK) {
    flagState = FLAGGED;
    setIcon(QIcon(":/assets/minesweeper_icons/mine_flag.png"));
    setIconSize(QSize(size-3,size-3));
    return;
  }
  if (flagState == FLAGGED) {
    flagState = QUESTIONMARK;
    setText("?");
    setIcon(QIcon());
    return;
  }
  if (flagState == QUESTIONMARK) {
    flagState = BLANK;
    setText("");
    return;
  }
}

Tile::~Tile() {}
