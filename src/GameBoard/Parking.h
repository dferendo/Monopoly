//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_PARKING_H
#define MONOPOLY_PARKING_H

#include "CornerTiles.h"
#include "../Player/Participant.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {
    class Parking : public CornerTiles {
    public:
        Parking(const string &name);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_PARKING_H
