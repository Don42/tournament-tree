#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QWidget>
class QGroupBox;
class QScrollArea;

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow ();

    private:
        void setupPlayers ();
        QGroupBox* hGroupBox;
        QScrollArea* scrollArea;
        QGroupBox* vGroupBox;
};

#endif
