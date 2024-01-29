#ifndef TILE
#define TILE

#include <QPushButton>
#include <QString>
#include <QDialog>
#include <iostream>
#include <QMouseEvent>
#include "popup.h"

#include <QDebug>

enum FlagStates {
  BLANK,
  FLAGGED,
  QUESTIONMARK
};

class Tile: public QPushButton {
  Q_OBJECT
  private:
    int size;
    bool isMine = false;
    int minesAdjacent;
    bool explored = false;
    FlagStates flagState = BLANK;

  protected:
    void mousePressEvent(QMouseEvent *event);

  public:
    Tile(const QString &text, QWidget *parent);
    bool getMine();
    void setMine(bool);
    int getMinesAdjacent();
    int incrementMinesAdjacent();
    bool getExplored();
    int explore();
    void flag();

  signals:
    void gameOverReceived();

};

#endif