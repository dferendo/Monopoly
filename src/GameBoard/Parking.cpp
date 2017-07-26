//
// Created by dylan on 16/11/2016.
//

#include "../../include/GameBoard/Parking.h"
using namespace std;

GameBoard::Parking::Parking(const string &name) : Tile(name) {}

void GameBoard::Parking::action(Player::Participant *participant, GameMechanics::Game * game) {
    participant->getMoney().addBalance(game->getFreeParkingJackpot());
    game->setFreeParkingJackpot(0);
}
