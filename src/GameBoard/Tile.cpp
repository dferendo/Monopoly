//
// Created by dylan on 16/11/2016.
//

#include "Tile.h"

string GameBoard::Tile::getName() {
    return name;
}

GameBoard::Tile::Tile(const string &name) : name(name) {}

void GameBoard::Tile::action(Player::Participant *player, GameMechanics::Game *game) {

}
