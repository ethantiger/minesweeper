#ifndef TILE
#define TILE

#include <QPushButton>
#include <QString>
#include <QDialog>
#include <iostream>
#include "gameover.h"
#include <QDebug>

class Tile: public QPushButton {
  Q_OBJECT
  private:
    bool isMine = false;
    int minesAdjacent;
    bool explored = false;

  public:
    Tile(const QString &text, QWidget *parent);
    bool getMine();
    void setMine(bool);
    int getMinesAdjacent();
    int incrementMinesAdjacent();
    bool getExplored();
    int explore();

  signals:
    void gameOverReceived();

};

#endif