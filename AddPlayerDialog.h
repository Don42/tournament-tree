#ifndef ADD_PLAYER_DIALOG
#define ADD_PLAYER_DIALOG

#include <QDialog>
#include <QLineEdit>

class AddPlayerDialog : public QDialog
{
    Q_OBJECT

    public:
        AddPlayerDialog ();
        int getPlayerCount ();

    private:
        QLineEdit *lineEdit;
        QPushButton *pushButton;

};

#endif
