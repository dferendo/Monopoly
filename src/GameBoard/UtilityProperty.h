//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_SPECIALPROPERTY_H
#define MONOPOLY_SPECIALPROPERTY_H

#include "Property.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {

    const double OWNER_OWNS_BOTH_UTILITY = 10;

    class UtilityProperty: public Property {
    public:
        UtilityProperty(const string &name, double propertyPrice, double rentCost, const string &colour, double mortgage);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        // Rent cost multiplied by dice number is the rent cost.
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
        double rentCost(Player::Participant *player);
    };
}
#endif //MONOPOLY_SPECIALPROPERTY_H
