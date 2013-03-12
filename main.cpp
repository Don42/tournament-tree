#include <QtGui>
#include <stdio.h>
#include "AddPlayerDialog.h"

int
main (int argc, char* argv[])
{
    QApplication app (argc, argv);
    AddPlayerDialog dialog;
    printf ("%d\n", dialog.exec ());
    printf ("%d\n", dialog.getPlayerCount ());
    return (dialog.result() != 0 ? 0 : 1);
    //return (app.exec ());
}
