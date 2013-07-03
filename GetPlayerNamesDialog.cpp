#include <QtGui>
#include <QtAlgorithms>
#include <assert.h>

#include "GetPlayerNamesDialog.h"

GetPlayerNamesDialog::GetPlayerNamesDialog (const int playerCount,
        QWidget* parent) : QDialog (parent)
{
    assert (playerCount >= 2);

    playerNames = new QList<QLineEdit*>;
    scrollArea = new QScrollArea;
    mainLayout = new QVBoxLayout;
    page = new QVBoxLayout;
    vGroupBox = new QGroupBox;
    okButton = new QPushButton( "OK", NULL);
    okButton->setAutoDefault (true);

    scrollArea->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);

    for (int i = 1; i <= playerCount; ++i)
    {
        page->addWidget (buildPlayerEntryField (i));
    }
    vGroupBox->setLayout (page);
    scrollArea->setWidget (vGroupBox);
    mainLayout->addWidget (scrollArea);
    mainLayout->addWidget (okButton);
    setLayout (mainLayout);

    connect (okButton, SIGNAL (clicked ()), this, SLOT (accept ()));
}


std::unique_ptr< QList<QString> >
GetPlayerNamesDialog::getPlayerNames ()
{
    std::unique_ptr< QList<QString> > names ( new QList<QString>());
    for (QList<QLineEdit*>::iterator i = playerNames->begin();
            i != playerNames->end(); ++i)
    {
        names->append((*i)->text ());
    }
    return names;
}

QWidget*
GetPlayerNamesDialog::buildPlayerEntryField (const int playerNumber)
{
    QString string = QString ("Player_%1").arg (playerNumber);
    QLineEdit* editLine = new QLineEdit (string);
    (*playerNames) << editLine;

    return editLine;
}

