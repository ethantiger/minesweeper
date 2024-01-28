#ifndef TILE
#define TILE

#include <QPushButton>
#include <QString>

class Tile: public QPushButton {
  private:
    bool isMine;
    int minesAdjacent;
  public:
    Tile(const QString &text, QWidget *parent);
    bool getMine();
    void setMine(bool);
    int getMinesAdjacent();
    int incrementMinesAdjacent();
};

#endif