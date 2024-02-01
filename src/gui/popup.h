/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Declarations of the Popup class.
 *  The Popup class is made to produce popup modals
 *  for when the game ends.
 * 
 * Date:
 *  1 Feb 2024
*/

#ifndef POPUP
#define POPUP

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QCoreApplication>
#include <string>

class Popup: public QDialog {
  Q_OBJECT
  private:
    QGridLayout *gridLayout;

  public:
    Popup(QString, QString);
    void createButtons(QString);
    void setupGrid();
    ~Popup();

  signals:
    void gameOverSignal();
};

#endif
