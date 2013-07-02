#ifndef GET_PLAYER_NAMES_DIALOG
#define GET_PLAYER_NAMES_DIALOG

#include <QDialog>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QWidget>
#include <memory>

class GetPlayerNamesDialog : public QDialog
{
    Q_OBJECT

    public:
        GetPlayerNamesDialog (const int playerCount,
                QWidget* parent = NULL);
        std::auto_ptr< QList<QString> > getPlayerNames ();

    private:
        QWidget* buildPlayerEntryField (const int playerNumber);
        QList<QLineEdit *>* playerNames = 0;
        QScrollArea* scrollArea = 0;
        QVBoxLayout* mainLayout = 0;
        QVBoxLayout* page = 0;
        QGroupBox* vGroupBox = 0;
        QPushButton* okButton = 0;
};

#endif
