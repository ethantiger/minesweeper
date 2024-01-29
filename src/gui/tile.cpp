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
  setIcon(QIcon());
  this->setStyleSheet("QPushButton {background:#222021;}");
  if (isMine) {
    // end game
    setText("M");
    Popup p("Game Over", "Retry");
    QObject::connect(&p, &Popup::gameOverSignal,[this]() {
      emit gameOverReceived();
    });
    p.exec();
    return -1;
  }
  if (minesAdjacent) {
    this->setText(QString("%1").arg(minesAdjacent));
  }
  return minesAdjacent;
}

void Tile::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::RightButton) {
    flag();
  } else {
    QPushButton::mousePressEvent(event);
  }
}

void Tile::flag() {
  if (explored) return;
  if (flagState == BLANK) {
    flagState = FLAGGED;
    setIcon(QIcon("./assets/minesweeper_icons/mine_flag.png"));
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