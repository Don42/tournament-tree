#include <QtGui>
#include <QDebug>

#include "GetPlayerCountDialog.h"
#include "GetPlayerNamesDialog.h"
#include "MainWindow.h"
#include <memory>
#include "Node.h"

MainWindow::MainWindow () : QMainWindow ()
{
    setupMenuBar ();
}

void
MainWindow::setupMenuBar ()
{
    QMenu *menu = menuBar()->addMenu(tr("&Main"));

    QAction *action = menu->addAction(tr("&Create Game"));
    connect(action, SIGNAL(triggered()), this, SLOT(createGame()));

    menu->addAction(tr("&Quit"), this, SLOT(close()));

}

void
MainWindow::createGame ()
{
    GetPlayerCountDialog countDialog;

    if (countDialog.exec () == 1)
    {
        const int playerCount = countDialog.getPlayerCount ();
        GetPlayerNamesDialog namesDialog (playerCount);
        namesDialog.exec ();
        std::auto_ptr< QList<QString> > names = namesDialog.getPlayerNames ();
        qDebug () << *names;
        std::auto_ptr<Node> tree (buildTree (names));
        qDebug () << "Tree created";
    }
}
