#include <QtGui>
#include <QDebug>

#include "GetPlayerCountDialog.h"
#include "GetPlayerNamesDialog.h"
#include "MainWindow.h"
#include <memory>
#include "Node.h"

MainWindow::MainWindow ()
: QMainWindow (),
    mView (&mScene, this)
{
    setupMenuBar ();
    mView.resize (0,0);
}

MainWindow::~MainWindow ()
{
    if(mGame)
    {
        delete mGame;
    }
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
        std::auto_ptr<Node> tree (buildTree (names));
        qDebug () << "Tree created";
        printTree(const_cast<Node*>(tree.get()), QString(""));
        mGame = new Game (tree.release());
        resetScene ();
        mGame->show (&mScene, &mView);
        mView.resize (this->size ());
    }
}

void MainWindow::resizeEvent (QResizeEvent* event)
{
    if(event)
    {
        mView.resize (this->size ());
    }
}

void MainWindow::resetScene ()
{
    mScene.clear ();
    qDeleteAll (mScene.items ());
    qDeleteAll (mView.items ());
    mView.resize(this->size ());
    mView.setSceneRect (mScene.itemsBoundingRect ());
}
