//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "Property.h"
#include "../GameMechanics/Game.h"
#include "HousesPrice.h"

namespace GameBoard {
    const int maxHouses = 4;

    class UpgradableProperty: public Property {
    private:
        HousesPrice housesPrice;
        int currentHousesBuild = 0;
    public:
        UpgradableProperty(const string &name, double propertyPrice, double rentCost, const string &colour,
                           GameBoard::HousesPrice housesPrice);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        bool checkIfUpgradeIsAvailable(Player::Participant *player, GameMechanics::Game *game);
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
        const HousesPrice &getHousesPrice() const;
    };
}

#endif //MONOPOLY_UPGRADABLEPROPERTY_H
