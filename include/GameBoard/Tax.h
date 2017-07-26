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
        /**
         * Tax amount will not change throughout the game.
         */
        const int taxAmount;
    public:
        Tax(const std::string &name, const int &taxAmount);

        /**
         * Participant pays the tax amount. If participant cannot pay the amount the
         * {@link Exception::noMoneyException} is caught make the participant pay or declare
         * bankruptcy.
         * @param participant the participant that landed on the Tile.
         * @param game Add money to the jackpot that is stored in game.
         */
        void action(Player::Participant *participant, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_TAX_H
