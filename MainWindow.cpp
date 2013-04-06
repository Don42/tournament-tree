#include <QtGui>

#include "AddPlayerDialog.h"
#include "EnterPlayerNamesDialog.h"
#include "MainWindow.h"

MainWindow::MainWindow ()
{
    AddPlayerDialog countDialog;

    if (countDialog.exec () == 1)
    {
        const int playerCount = countDialog.getPlayerCount ();
        EnterPlayerNamesDialog namesDialog (playerCount);
        namesDialog.exec ();
    }
}
