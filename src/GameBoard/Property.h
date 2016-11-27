//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_PROPERTY_H
#define MONOPOLY_PROPERTY_H

#include "Tile.h"
#include "../Util/ReadInput.h"
#include "../Util/MenuHelper.h"

namespace GameBoard {

    class Property: public Tile {
    private:
        double propertyPrice;
        double rentCost;
        Player::Participant * owner = nullptr;
        int currentHousesBuild = 0;
        string colour;
    public:
        Property(const string &name, double propertyPrice, double rentCost, string colour);
        Player::Participant * getOwner();
        void setOwner(Player::Participant *owner);
        virtual void action(Player::Participant *player, GameMechanics::Game * game) = 0;
        void noOwner(Player::Participant *player, GameMechanics::Game * game);
        void buyHouse(Player::Participant *player);
        void auctionHouse(GameMechanics::Game * game);
        // The 3 types of property pay differently.
        virtual void payRent(Player::Participant *player, GameMechanics::Game * game) = 0;
        const string &getColour() const;
        double getRentCost() const;
        int getCurrentHousesBuild() const;
        void setCurrentHousesBuild(int currentHousesBuild);
    };
}

#endif //MONOPOLY_PROPERTY_H
