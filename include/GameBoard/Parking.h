//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_PARKING_H
#define MONOPOLY_PARKING_H

#include "Tile.h"
#include "../Player/Participant.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {

    class Parking : public Tile {
    public:
        Parking(const std::string &name);

        /**
         * When a participant lands, the participant gets the jackpot found in the Game. Money is being
         * added to the jackpot when participants lands on Tax and Xorti. When a participant lands
         * on the tile, the jackpot is reset.
         * @param participant Participant that landed.
         * @param game Holds the jackpot
         */
        void action(Player::Participant *participant, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_PARKING_H
