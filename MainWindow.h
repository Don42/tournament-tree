#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QWidget>
#include <QList>
#include <QGroupBox>
#include <QScrollArea>
#include <QLineEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow ();

    private:
        void setupPlayers ();
        QGroupBox* buildPlayerEntryFields (int playerNumber);
        void setupScrollArea ();
        QList<QLineEdit *>* playerNames;
        QScrollArea* scrollArea;
        QGroupBox* vGroupBox;

};

#endif
