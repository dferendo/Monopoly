#include "Monopoly.h"
#include "GameMechanics/Game.h"

Monopoly::Monopoly() {
    GameMechanics::Game game;
    game.play();
}

