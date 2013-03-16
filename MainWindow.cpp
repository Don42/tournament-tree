#include <QtGui>

#include "AddPlayerDialog.h"
#include "MainWindow.h"

MainWindow::MainWindow ()
{
    setupScrollArea ();
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
        playerNames = new QList <QLineEdit*>;

        QVBoxLayout* page = new QVBoxLayout;
        vGroupBox = new QGroupBox ("");
        for (int i = 0; i < playerCount; i++)
        {
            QGroupBox* box = buildPlayerEntryFields (i + 1);
            page->addWidget (box);
        }
        vGroupBox->setLayout (page);
        scrollArea->setWidget (vGroupBox);
    }
    mainLayout->addWidget (scrollArea);
    setLayout (mainLayout);
}

void
MainWindow::setupScrollArea ()
{
        scrollArea = new QScrollArea;
        scrollArea->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        scrollArea->setVerticalScrollBarPolicy ( Qt::ScrollBarAsNeeded);
}

QGroupBox*
MainWindow::buildPlayerEntryFields (int playerNumber)
{
    QGroupBox*  hGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout* layout = new QHBoxLayout;

    QString string = QString ("Player %1").arg (playerNumber);
    layout->addWidget (new QLabel (string));
    QLineEdit* editLine = new QLineEdit;
    layout->addWidget (editLine);
    (*playerNames) << editLine;

    hGroupBox->setLayout (layout);
    return hGroupBox;
}
