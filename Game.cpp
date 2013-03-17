#include "Game.h"


Game::Game ()
{
    playerNames = new QList<QString>;
}


void
Game::addPlayer (QString name)
{
    playerNames << name;
}
