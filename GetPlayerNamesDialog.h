#ifndef GET_PLAYER_NAMES_DIALOG
#define GET_PLAYER_NAMES_DIALOG

#include <QDialog>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QWidget>

class GetPlayerNamesDialog : public QDialog
{
    Q_OBJECT

    public:
        GetPlayerNamesDialog (const int playerCount,
                QWidget* parent = NULL);
        QList<QString> getPlayerNames ();

    private:
        QWidget* buildPlayerEntryField (const int playerNumber);
        QList<QLineEdit *>* playerNames;
        QScrollArea* scrollArea;
        QVBoxLayout* mainLayout;
        QVBoxLayout* page;
        QGroupBox* vGroupBox;
        QPushButton* okButton;
};

#endif
