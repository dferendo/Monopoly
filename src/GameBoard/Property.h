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
    private:
        double propertyPrice;
        Participant * owner = nullptr;
    protected:
        void noOwner(Participant *player, GameMechanics::Game * game);
        void buyProperty(Participant *player);
        Participant * selectBidder(vector<Participant *> participants, Participant *currentBidder);
        double rentCost;
    private:
        string colour;
    public:
        Property(const string &name, double propertyPrice, double rentCost, string colour, double mortgage);
        Participant * getOwner();
        string getName();
        void setOwner(Participant *owner);
        const string &getColour() const;
        virtual double getRentCost(GameMechanics::Game * game) = 0;
        virtual void action(Participant *player, GameMechanics::Game * game) = 0;
        // The 3 types of property pay differently.
        virtual void payRent(Participant *player, GameMechanics::Game * game) = 0;
        virtual void doActionWithoutBeingOnProperty(GameMechanics::Game * game) = 0;
        void auctionHouse(GameMechanics::Game * game);
        bool checkIfOwnerHasAllSameColour(Player::Participant *player, GameMechanics::Game *game);
    };
}

#endif //MONOPOLY_PROPERTY_H
