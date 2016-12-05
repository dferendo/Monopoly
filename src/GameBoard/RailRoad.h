//
// Created by dylan on 19/11/2016.
//

#ifndef MONOPOLY_RAILROAD_H
#define MONOPOLY_RAILROAD_H

#include "NonUpgradableProperty.h"

namespace GameBoard {
    class RailRoad: public NonUpgradableProperty {
    public:
        RailRoad(const string &name, double propertyPrice, double rentCost, const Colour &colour, double mortgage);
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
        void action(Player::Participant *player, GameMechanics::Game *game) override;
        double getRentCost(GameMechanics::Game *game) override;
    };
}
#endif //MONOPOLY_RAILROAD_H
