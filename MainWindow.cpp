#include <QtGui>

#include "AddPlayerDialog.h"
#include "MainWindow.h"

MainWindow::MainWindow ()
{
    AddPlayerDialog dialog;
    printf ("%d\n", dialog.exec ());
    printf ("%d\n", dialog.getPlayerCount ());
}

void
MainWindow::setupPlayers ()
{

}
