#ifndef GAME
#define GAME

#include <QList>
#include <QString>
#include "Node.h"
#include "Tree.h"

class Game
{
    public: enum GameType
    {
        ElimWithLoserBracket,
        ElimWitoutLoserBracket
    };

    public:
        Game (std::unique_ptr< QList<QString> > names, GameType type);
        Game (std::unique_ptr< QList<QString> > names);
        void show (QGraphicsScene* scene, QGraphicsView* view) const;
        ~Game ();

    private:
        void init (std::unique_ptr< QList<QString> > names, GameType type);
        Tree* mPlayerTree = 0;
        GameType mGameType;
};

#endif
