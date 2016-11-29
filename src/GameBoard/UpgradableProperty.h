//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "Property.h"
#include "../GameMechanics/Game.h"
#include "HousesPrice.h"

namespace GameBoard {
    const int MAX_HOUSES = 4;

    class UpgradableProperty: public Property {
    private:
        HousesPrice housesPrice;
    public:
        UpgradableProperty(const string &name, double propertyPrice, double rentCost, const string &colour,
                           GameBoard::HousesPrice housesPrice, double mortgage);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        bool checkIfOwnerHasAllSameColour(Player::Participant *player, GameMechanics::Game *game);
        void upgradeProperty(Player::Participant *player);
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
        void addHouseToProperty(Player::Participant *player);
        void removeHouseFromProperty(Player::Participant *player);
        const HousesPrice &getHousesPrice() const;
        string getName();
    };
}

#endif //MONOPOLY_UPGRADABLEPROPERTY_H
