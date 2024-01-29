#ifndef POPUP
#define POPUP

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QCoreApplication>

class Popup: public QDialog {
  Q_OBJECT
  private:
    QGridLayout *gridLayout;
  public:
    Popup(char *, char *);
    void createButtons(char *);
    void setupGrid();

  signals:
    void gameOverSignal();
};

#endif