//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "Property.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {
    const int maxHouses = 4;

    class UpgradableProperty: public Property {
    private:
        int currentHousesBuild;
    public:
        UpgradableProperty(const string &name, double propertyPrice, double rentCost, const string &colour);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        bool checkIfUpgradeIsAvailable(Player::Participant *player, GameMechanics::Game *game);
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
    };
}

#endif //MONOPOLY_UPGRADABLEPROPERTY_H
