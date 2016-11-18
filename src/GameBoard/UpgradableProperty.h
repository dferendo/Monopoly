//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "Property.h"

namespace GameBoard {

    class UpgradableProperty: public Property {
    private:
        const int maxHouses = 4;
        int currentHousesBuild;
        string colour;
    public:
        UpgradableProperty(const string &name, double propertyPrice, double rentCost, string colour);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
    };
}

#endif //MONOPOLY_UPGRADABLEPROPERTY_H
