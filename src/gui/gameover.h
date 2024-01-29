#ifndef GAMEOVER
#define GAMEOVER

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

class GameOverPopup: public QDialog {
  Q_OBJECT
  private:
    QGridLayout *gridLayout;
  public:
    GameOverPopup();
    void createButtons();
    void setupGrid();

  signals:
    void gameOverSignal();
};

#endif