//
// Created by dylan on 16/11/2016.
//

#include "Tile.h"

const string &GameBoard::Tile::getName() const {
    return name;
}

GameBoard::Tile::Tile(const string &name) : name(name) {}
