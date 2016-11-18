//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_CORNERTILES_H
#define MONOPOLY_CORNERTILES_H

#include "Tile.h"

namespace GameBoard {

    class CornerTiles : public Tile {
    public:
        CornerTiles(const string &name) : Tile(name) {}
        virtual void action(Player::Participant *player, GameMechanics::Game * game) = 0;
    };
}
#endif //MONOPOLY_CORNERTILES_H
