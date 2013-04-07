#include <QtGui>
#include <QtAlgorithms>
#include <assert.h>

#include "EnterPlayerNamesDialog.h"

EnterPlayerNamesDialog::EnterPlayerNamesDialog (const int playerCount,
        QWidget* parent) : QDialog (parent)
{
    assert (playerCount >= 2);

    playerNames = new QList<QLineEdit*>;
    scrollArea = new QScrollArea;
    mainLayout = new QVBoxLayout;
    page = new QVBoxLayout;
    vGroupBox = new QGroupBox;

    scrollArea->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);

    for (int i = 1; i <= playerCount; ++i)
    {
        page->addWidget (buildPlayerEntryField (i));
    }
    vGroupBox->setLayout (page);
    scrollArea->setWidget (vGroupBox);
    mainLayout->addWidget (scrollArea);
    setLayout (mainLayout);
}

QWidget*
EnterPlayerNamesDialog::buildPlayerEntryField (const int playerNumber)
{
    QString string = QString ("Player %1").arg (playerNumber);
    QLineEdit* editLine = new QLineEdit (string);
    (*playerNames) << editLine;

    return editLine;
}

