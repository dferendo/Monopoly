//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_EMPTYTILE_H
#define MONOPOLY_EMPTYTILE_H

#include "CornerTiles.h"

namespace GameBoard {
    class EmptyTile: public CornerTiles {
    public:
        EmptyTile(const string &name) : CornerTiles(name) {}
        void action(Player::Participant *player, GameMechanics::Game * game) override {
            // Do nothing, should be on to jail or in jail
        }
    };
}
#endif //MONOPOLY_EMPTYTILE_H
