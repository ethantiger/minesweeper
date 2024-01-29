#include "gameover.h"

GameOverPopup::GameOverPopup(): QDialog() {
  setWindowTitle("Game Over");
  setWindowFlags(Qt::CustomizeWindowHint);
  resize(200,50);
  setModal(true);
  setupGrid();
  createButtons();
}

void GameOverPopup::createButtons() {
  QPushButton *retry = new QPushButton("Retry", this);
  QPushButton *quit = new QPushButton("Quit", this);
  QObject::connect(retry, &QPushButton::clicked, [this]() {
    emit gameOverSignal();
    close();
  });
  gridLayout->addWidget(retry,0,0);
  gridLayout->addWidget(quit,0,1);
}

void GameOverPopup::setupGrid() {
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setContentsMargins(0,0,0,0);

  this->setLayout(gridLayout);
}