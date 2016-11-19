//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_TAX_H
#define MONOPOLY_TAX_H

#include "Tile.h"
#include "../Player/Participant.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {
    class Tax: public Tile {
    private:
        int taxAmount;
    public:
        Tax(const string &name, const int &taxAmount);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_TAX_H
