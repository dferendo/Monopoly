//
// Created by dylan on 16/11/2016.
//

#include "Parking.h"

GameBoard::Parking::Parking(const string &name) : CornerTiles(name) {}

void GameBoard::Parking::action(Player::Participant *player, GameMechanics::Game * game) {
    player->getMoney().addBalance(game->getFreeParkingJackpot());
    game->setFreeParkingJackpot(0);
}
