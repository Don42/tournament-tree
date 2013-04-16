#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QMainWindow>
#include <QList>
#include <QGroupBox>
#include <QScrollArea>
#include <QLineEdit>

#include "Game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow ();
        ~MainWindow (){};

    public slots:
        void createGame ();

    private:
        Game game;
        void setupMenuBar ();

};

#endif
