#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QMainWindow>
#include <QList>
#include <QGroupBox>
#include <QScrollArea>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <memory>

#include "Game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow ();
        ~MainWindow ();
        void resizeEvent (QResizeEvent* event);

    public slots:
        void createGame ();

    private:
        Game* mGame;
        QGraphicsScene mScene;
        QGraphicsView mView;
        void setupMenuBar ();
        void resetScene ();

};

#endif
