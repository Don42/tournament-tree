#include <QtGui>

#include "AddPlayerDialog.h"
#include "MainWindow.h"

MainWindow::MainWindow ()
{
    //AddPlayerDialog dialog;
    //printf ("%d\n", dialog.exec ());
    //printf ("%d\n", dialog.getPlayerCount ());
    setupPlayers ();
}

void
MainWindow::setupPlayers ()
{
    AddPlayerDialog dialog;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    if (dialog.exec() == 1)
    {
        int playerCount = dialog.getPlayerCount ();
        for (int i = 0; i < playerCount; i++)
        {
           mainLayout->addWidget(new QLineEdit);
        }
    }
    setLayout (mainLayout);
}
