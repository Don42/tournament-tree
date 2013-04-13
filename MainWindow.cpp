#include <QtGui>
#include <QDebug>

#include "GetPlayerCountDialog.h"
#include "GetPlayerNamesDialog.h"
#include "MainWindow.h"

MainWindow::MainWindow ()
{
    GetPlayerCountDialog countDialog;

    if (countDialog.exec () == 1)
    {
        const int playerCount = countDialog.getPlayerCount ();
        GetPlayerNamesDialog namesDialog (playerCount);
        namesDialog.exec ();
        QList<QString> names = namesDialog.getPlayerNames ();
        qDebug () << names;
    }
}
