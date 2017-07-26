//
// Created by dylan on 16/11/2016.
//

#include "../../include/GameBoard/Tile.h"
using namespace std;

string GameBoard::Tile::getName() {
    return name;
}

GameBoard::Tile::Tile(const string &name) : name(name) {}

void GameBoard::Tile::action(Player::Participant *participant, GameMechanics::Game *game) {}

GameBoard::Tile::~Tile() {}
