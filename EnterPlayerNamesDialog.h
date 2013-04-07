#ifndef ENTER_PLAYER_NAMES_DIALOG
#define ENTER_PLAYER_NAMES_DIALOG

#include <QDialog>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QWidget>

class EnterPlayerNamesDialog : public QDialog
{
    Q_OBJECT

    public:
        EnterPlayerNamesDialog (const int playerCount,
                QWidget* parent = NULL);

    private:
        QWidget* buildPlayerEntryField (const int playerNumber);
        QList<QLineEdit *>* playerNames;
        QScrollArea* scrollArea;
        QVBoxLayout* mainLayout;
        QVBoxLayout* page;
        QGroupBox* vGroupBox;
};

#endif
