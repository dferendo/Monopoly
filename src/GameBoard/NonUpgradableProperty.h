//
// Created by dylan on 30/11/2016.
//

#ifndef MONOPOLY_NONUPGRADABLEPROPERTY_H
#define MONOPOLY_NONUPGRADABLEPROPERTY_H

#include "Property.h"

namespace GameBoard {
    class NonUpgradableProperty : public Property {
    public:
        NonUpgradableProperty(const string &name, double propertyPrice, double rentCost, const Colour &colour,
                              double mortgage);
        virtual void action(Participant *player, GameMechanics::Game *game) = 0;
        virtual void payRent(Participant *player, GameMechanics::Game *game) = 0;
        void doActionWithoutBeingOnProperty(GameMechanics::Game * game) override;
        string toString(Property & property);
    };
}
#endif //MONOPOLY_NONUPGRADABLEPROPERTY_H
