#include <QtGui>

#include "AddPlayerDialog.h"
#include "MainWindow.h"

MainWindow::MainWindow ()
{
    setupPlayers ();
}

void
MainWindow::setupPlayers ()
{
    AddPlayerDialog dialog;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    if (dialog.exec() == 1)
    {
        scrollArea = new QScrollArea;
        scrollArea->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        scrollArea->setVerticalScrollBarPolicy ( Qt::ScrollBarAsNeeded);
        int playerCount = dialog.getPlayerCount ();
        QVBoxLayout* page = new QVBoxLayout;
        vGroupBox = new QGroupBox ("");
        for (int i = 0; i < playerCount; i++)
        {
            hGroupBox = new QGroupBox(tr("Horizontal layout"));
            QHBoxLayout *layout = new QHBoxLayout;
            QString string = QString ("Player %1").arg (i + 1);
            layout->addWidget (new QLabel (string));
            layout->addWidget (new QLineEdit);
            hGroupBox->setLayout (layout);
            page->addWidget (hGroupBox);
        }
        vGroupBox->setLayout (page);
        scrollArea->setWidget (vGroupBox);
    }
    mainLayout->addWidget (scrollArea);
    setLayout (mainLayout);
}
