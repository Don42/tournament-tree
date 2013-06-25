#include "Game.h"


Game::Game (Node* playerTree)
{
    this->init(playerTree, ElimWithLoserBracket);
}

Game::Game (Node* playerTree, GameType type)
{
    this->init(playerTree, type);
}

void Game::init (Node* playerTree, GameType type)
{
    mPlayerTree = playerTree;
    mGameType = type;
}

Game::~Game ()
{
    delete mPlayerTree;
}
