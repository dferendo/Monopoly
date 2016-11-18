//
// Created by dylan on 16/11/2016.
//

#include "Go.h"

GameBoard::Go::Go(const string &name) : CornerTiles(name) {}

void GameBoard::Go::action(Player::Participant *player, GameMechanics::Game * game) {
    player->getMoney().addBalance(GO_AMOUNT);
}
