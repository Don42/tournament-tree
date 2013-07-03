#include "Game.h"


Game::Game (std::unique_ptr< QList<QString> > names)
{
    this->init(std::move(names), ElimWithLoserBracket);
}

Game::Game (std::unique_ptr< QList<QString> > names, GameType type)
{
    this->init(std::move(names), type);
}

void Game::init (std::unique_ptr< QList<QString> > names, GameType type)
{
    mPlayerTree = new Tree (std::move (names));
    mGameType = type;
}

void Game::show (QGraphicsScene* scene, QGraphicsView* view) const
{
    mPlayerTree->show (scene, view);
}

Game::~Game ()
{
    if (mPlayerTree)
    {
        delete mPlayerTree;
    }
}
