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
    Popup(const char *, const char *);
    void createButtons(const char *);
    void setupGrid();

  signals:
    void gameOverSignal();
};

#endif