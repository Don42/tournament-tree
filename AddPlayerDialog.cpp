#include <QtGui>
#include <QIntValidator>

#include "AddPlayerDialog.h"

AddPlayerDialog::AddPlayerDialog (QWidget* parent)
    : QDialog (parent)
{
    QIntValidator validator;
    validator.setBottom (3);
    validator.setTop (32);

    lineEdit = new QLineEdit (NULL);
    pushButton = new QPushButton ("OK", NULL);
    pushButton->setAutoDefault (true);
    QString string("16");
    lineEdit->setText (string);
    lineEdit->setAlignment (Qt::AlignVCenter | Qt::AlignHCenter);
    lineEdit->setGeometry (0, 0, 180, 75);
    lineEdit->setValidator (&validator);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget (lineEdit);
    mainLayout->addWidget (pushButton);
    setLayout (mainLayout);

    connect (pushButton, SIGNAL (clicked ()), this, SLOT (accept ()));
}

int
AddPlayerDialog::getPlayerCount ()
{
    return lineEdit->text().toInt();
}
