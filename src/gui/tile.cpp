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