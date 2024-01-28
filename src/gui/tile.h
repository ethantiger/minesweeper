#ifndef TILE
#define TILE

#include <QPushButton>
#include <QString>

class Tile: public QPushButton {
  public:
    Tile(const QString &text, QWidget *parent);
};

#endif