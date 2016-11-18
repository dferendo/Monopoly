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
    public:
        Property(const string &name, double propertyPrice);
        const Player::Participant * getOwner() const;
        void setOwner(Player::Participant *owner);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        void noOwner(Player::Participant *player);
        void buyHouse(Player::Participant *player);
    };
}

#endif //MONOPOLY_PROPERTY_H
