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
        void show (QGraphicsScene* scene, QGraphicsView* view) const;
        ~Game ();

    private:
        void init (Node* playerTree, GameType type);
        Node* mPlayerTree = 0;
        GameType mGameType;
};

#endif
