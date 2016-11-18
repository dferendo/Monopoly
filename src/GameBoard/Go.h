//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_GO_H
#define MONOPOLY_GO_H

#include "CornerTiles.h"
#include "../Player/Participant.h"

namespace GameBoard {
    const int GO_AMOUNT = 200;

    class Go: public CornerTiles {
    public:
        Go(const string &name);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_GO_H
