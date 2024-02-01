/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Declaration of the Tile class.
 *  The tile class are the buttons aligned in the grid
 *  of the MainWindow.
 * 
 * Date:
 *  1 Feb 2024
*/

#ifndef TILE
#define TILE

#include <QPushButton>
#include <QString>
#include <QDialog>
#include <iostream>
#include <QMouseEvent>
#include <QDebug>
#include "popup.h"

enum FlagStates {
  BLANK,
  FLAGGED,
  QUESTIONMARK
};

class Tile: public QPushButton {
  Q_OBJECT
  private:
    int size;
    bool isMine;
    int minesAdjacent;
    bool explored;
    FlagStates flagState;

  protected:
    void mousePressEvent(QMouseEvent *event);

  public:
    Tile();
    bool getMine();
    void setMine(bool);
    int getMinesAdjacent();
    int incrementMinesAdjacent();
    bool getExplored();
    void showMine();
    int explore();
    void flag();
    ~Tile();

  signals:
    void gameOverReceived();
    void showMines();
};

#endif
