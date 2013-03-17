#ifndef GAME
#define GAME

#include <QList>
#include <QString>

class Game
{

    public:
        void addPlayer (QString name);

    private:
        QList<QString>* playerNames;
};

#endif
