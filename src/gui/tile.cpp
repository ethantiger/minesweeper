#include "tile.h"

Tile::Tile(const QString &text, QWidget *parent = nullptr): QPushButton(text, parent) {
  int size = 50;
  // this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setFixedSize(size,size);
}

bool Tile::getMine() {
  return isMine;
}

void Tile::setMine(bool b) {
  isMine = b;
}

int Tile::getMinesAdjacent() {
  return minesAdjacent;
}

int Tile::incrementMinesAdjacent() {
  minesAdjacent += 1;
  return minesAdjacent;
}