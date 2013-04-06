#include <QtGui>
#include <QtAlgorithms>
#include <assert.h>

#include "EnterPlayerNamesDialog.h"

EnterPlayerNamesDialog::EnterPlayerNamesDialog (const int playerCount)
{
    assert (playerCount > 2);

    playerNames = new QList<QLineEdit*>;

    scrollArea = new QScrollArea;
    scrollArea->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);

    mainLayout = new QVBoxLayout;
    page = new QVBoxLayout;
    vGroupBox = new QGroupBox;

    for (int i = 1; i <= playerCount; ++i)
    {
        page->addWidget (buildPlayerEntryField (i));
    }
    vGroupBox->setLayout (page);
    scrollArea->setWidget (vGroupBox);
    mainLayout->addWidget (scrollArea);
    setLayout (mainLayout);
}

EnterPlayerNamesDialog::~EnterPlayerNamesDialog ()
{
    delete mainLayout;
    delete page;
    delete vGroupBox;
    delete scrollArea;
    qDeleteAll (*playerNames);
    delete playerNames;
}

QWidget*
EnterPlayerNamesDialog::buildPlayerEntryField (const int playerNumber)
{
    QString string = QString ("Player %1").arg (playerNumber);
    QLineEdit* editLine = new QLineEdit (string);
    (*playerNames) << editLine;

    return editLine;
}

