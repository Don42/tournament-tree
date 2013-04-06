#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QWidget>
#include <QList>
#include <QGroupBox>
#include <QScrollArea>
#include <QLineEdit>

#include "Game.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow ();
        ~MainWindow (){};

    private:
        Game game;

};

#endif
