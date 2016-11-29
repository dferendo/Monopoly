//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_PROPERTY_H
#define MONOPOLY_PROPERTY_H

#include "Tile.h"
#include "../Util/ReadInput.h"
#include "../Util/MenuHelper.h"
#include "Mortgage.h"
using namespace Player;

namespace GameBoard {

    class Property: public Tile, public Mortgage {
        friend class UpgradableProperty;
    private:
        double propertyPrice;
        double rentCost;
        Participant * owner = nullptr;
        int currentHousesBuild = 0;
        string colour;
        // This can be accessed only by UpgradableProperty
        void setCurrentHousesBuild(int currentHousesBuild);
    protected:
        void noOwner(Participant *player, GameMechanics::Game * game);
        void buyProperty(Participant *player);
        Participant * selectBidder(vector<Participant *> participants, Participant *currentBidder);
    public:
        Property(const string &name, double propertyPrice, double rentCost, string colour, double mortgage);
        Participant * getOwner();
        void setOwner(Participant *owner);
        const string &getColour() const;
        double getRentCost() const;
        int getCurrentHousesBuild() const;
        virtual void action(Participant *player, GameMechanics::Game * game) = 0;
        // The 3 types of property pay differently.
        virtual void payRent(Participant *player, GameMechanics::Game * game) = 0;
        void auctionHouse(GameMechanics::Game * game);
        string getName();
    };
}

#endif //MONOPOLY_PROPERTY_H
