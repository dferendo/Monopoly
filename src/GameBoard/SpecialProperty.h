//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_SPECIALPROPERTY_H
#define MONOPOLY_SPECIALPROPERTY_H

#include "Property.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {

    class SpecialProperty: public Property {
    public:
        SpecialProperty(const string &name, double propertyPrice, double rentCost, const string &colour);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        // Rent cost multiplied by dice number is the rent cost.
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_SPECIALPROPERTY_H
