//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "../GameMechanics/Game.h"
#include "HousesPrice.h"

namespace GameBoard {
    const int MAX_HOUSES = 4;

    class UpgradableProperty: public Property {
    private:
        HousesPrice housesPrice;
        int currentHousesBuild = 0;
        void setCurrentHousesBuild(int currentHousesBuild);
    public:
        UpgradableProperty(const string &name, double propertyPrice, double rentCost, const Colour &colour,
                           GameBoard::HousesPrice housesPrice, double mortgage);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        void payRent(Player::Participant *player, GameMechanics::Game * game) override;
        void addHouseToProperty(Player::Participant *player);
        void removeHouseFromProperty(Player::Participant *player);
        const HousesPrice &getHousesPrice() const;
        string getName();
        void doActionWithoutBeingOnProperty(GameMechanics::Game *game) override;
        int getCurrentHousesBuild() const;
        double getRentCost(GameMechanics::Game *game) override;

        string toString(Property &property) override;
    };
}

#endif //MONOPOLY_UPGRADABLEPROPERTY_H
