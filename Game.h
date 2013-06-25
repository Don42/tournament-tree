#ifndef GAME
#define GAME

#include <QList>
#include <QString>
#include "Node.h"

class Game
{
    public: enum GameType
    {
        ElimWithLoserBracket,
        ElimWitoutLoserBracket
    };

    public:
        Game (Node* playerTree, GameType type);
        Game (Node* playerTree);
        ~Game ();

    private:
        void init (Node* playerTree, GameType type);
        Node* mPlayerTree;
        GameType mGameType;
};

#endif
