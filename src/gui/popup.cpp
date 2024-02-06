/**
 * Ethan Wakefield
 * 251155260
 * 
 * Description:
 *  Function definitions for the Popup class
 * 
 * Date:
 *  1 Feb 2024
*/

#include "popup.h"

/**
 * Popup()
 * Constructor for the Popup class
 * params:
 *  const char *title (the title of the popup class)
 *  const char *button (the name of the first button)
 * returns: Popup
*/
Popup::Popup(QString title, QString button) {
  setWindowTitle(title);
  setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
  resize(200,50);
  setModal(true);
  setupGrid();
  createButtons(button);
}

/**
 * createButtons()
 * instantiates retry and quit buttons and sets up signals
 *  for these buttons
 * params:
 *  const char* button (name for the retry button)
 * returns: none
*/
void Popup::createButtons(QString button) {
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

/**
 * setupGrid()
 * sets up grid layout for the popup
 * params: none
 * returns: none
*/
void Popup::setupGrid() {
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setContentsMargins(0,0,0,0);
  this->setLayout(gridLayout);
}

/**
 * ~Popup()
 * Destructor for the Popup class.
 * params: none
 * returns: None
*/
Popup::~Popup(){}
