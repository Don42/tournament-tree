#ifndef GET_PLAYER_COUNT_DIALOG
#define GET_PLAYER_COUNT_DIALOG

#include <QDialog>
#include <QLineEdit>

class GetPlayerCountDialog : public QDialog
{
    Q_OBJECT

    public:
        GetPlayerCountDialog (QWidget* parent = NULL);
        int getPlayerCount ();

    private:
        QLineEdit *lineEdit = 0;
        QPushButton *pushButton = 0;

};

#endif
