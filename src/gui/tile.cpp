#include "tile.h"

Tile::Tile(const QString &text, QWidget *parent = nullptr): QPushButton(text, parent) {
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  // this->setFixedSize(30,30);
}