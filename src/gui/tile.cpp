#include "tile.h"

Tile::Tile(const QString &text, QWidget *parent = nullptr): QPushButton(text, parent) {
  int size = 35;
  this->setStyleSheet("QPushButton {border:1px solid;}");
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

bool Tile::getExplored() {
  return explored;
}

int Tile::explore() {
  explored = true;
  this->setStyleSheet("QPushButton {background:#222021;}");
  if (isMine) {
    // end game
    QDialog popup;
    popup.setWindowTitle("Game Over");
    popup.setModal(true);

    // Optionally add components to the popup here

    popup.exec();
    return -1;
  }
  if (minesAdjacent) {
    this->setText(QString("%1").arg(minesAdjacent));
  }
  return minesAdjacent;
}