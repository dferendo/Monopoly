//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_SPECIALPROPERTY_H
#define MONOPOLY_SPECIALPROPERTY_H

#include "Property.h"

namespace GameBoard {

    class SpecialProperty: public Property {
    private:
        // Rent cost multiplied by dice number is the rent cost
        int diceNumber;
    public:
        SpecialProperty(const string &name, double propertyPrice, double rentCost);
        void setDiceNumber(int diceNumber);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_SPECIALPROPERTY_H