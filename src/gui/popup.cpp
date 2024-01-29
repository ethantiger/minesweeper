#include "popup.h"

Popup::Popup(const char *title, const char *button) {
  setWindowTitle(title);
  setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
  resize(200,50);
  setModal(true);
  setupGrid();
  createButtons(button);
}

void Popup::createButtons(const char *button) {
  QPushButton *retry = new QPushButton(button, this);
  QPushButton *quit = new QPushButton("Quit", this);
  QObject::connect(retry, &QPushButton::clicked, [this]() {
    emit gameOverSignal();
    close();
  });
  QObject::connect(quit, &QPushButton::clicked, qApp, &QCoreApplication::quit);
  gridLayout->addWidget(retry,0,0);
  gridLayout->addWidget(quit,0,1);
}

void Popup::setupGrid() {
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setContentsMargins(0,0,0,0);

  this->setLayout(gridLayout);
}