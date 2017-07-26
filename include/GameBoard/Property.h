//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_PROPERTY_H
#define MONOPOLY_PROPERTY_H

#include "Tile.h"
#include "../Util/ReadInput.h"
#include "../Util/MenuHelper.h"
#include "Mortgage.h"

namespace GameBoard {

    class Property: public Tile, public Mortgage {
    private:
        const double propertyPrice;
        /**
         * Property can be owned by a participant {@link Player::Participant}
         */
        Player::Participant * owner = nullptr;
    protected:
        const double rentCost;
    private:
        const ColourType colour;

        /**
         * Select the next bidder. The current bidder is not shown with the available bidders.
         * @param participants The list of participants that can bid.
         * @param currentBidder The participant that has the current bid.
         * @return The participant that will bid
         */
        Player::Participant * selectBidder(std::vector<Player::Participant *> participants,
                                           Player::Participant *currentBidder);
    protected:
        /**
         * If the property is owned by banker (nullptr) and a player is on the property Tile, the participant
         * can buy the property, let the banker auction the property or view property details.
         * @param participant Participant that landed on the Property.
         * @param game Get all the participants playing.
         */
        void noOwner(Player::Participant *participant, GameMechanics::Game * game);

        /**
         * Will subtract money from participant. If the participant does not have enough money
         * an exception will be thrown and caught in the method. Therefore the property will be
         * auctioned by the banker. If the participant has enough money, the money is taken, the
         * property is added to the vector of properties the participant has and the owner of the
         * property is changed to point to the participant.
         * @param participant The participant that wants to buy te property.
         */
        void buyProperty(Player::Participant *participant);
    public:
        Property(const std::string &name, const double propertyPrice, const double rentCost,
                 const ColourType colour, const double mortgage);

        Player::Participant * getOwner();

        /**
         * Overrides the getName() method found in {@link GameBoard::Tile} to display as well if the
         * property is mortgaged.
         * @return The name of the property and whether or not it is mortgaged.
         */
        std::string getName();

        void setOwner(Player::Participant *owner);

        double getPropertyPrice() const;

        const ColourType &getColourType() const;

        /**
         * To pay get the total cost of rent, the subclasses have different ways to do so but every
         * property needs to have a rent cost.
         * @param game The current game
         * @return The rent cost.
         */
        virtual double getRentCost(GameMechanics::Game * game) = 0;

        /**
         * Properties have different actions depending if they can upgrade or not upgrade but every
         * property has an action.
         * @param participant The participant that landed on the Tile.
         * @param game  The current game to get all participants playing.
         */
        virtual void action(Player::Participant *participant, GameMechanics::Game * game) = 0;

        /**
         * Every property has to pay rent if the participant that landed on the property is not the owner.
         * To pay the rent it is the same thing for every subclass. If the property is mortgaged an exception
         * is thrown and no rent is due. If the participant does not have enough money, the NoMoneyException
         * is caught and handled in this method.
         * @param participant The participant that landed on the Tile.
         * @param game The current game to get the rent cost.
         */
        void payRent(Player::Participant *participant, GameMechanics::Game * game);

        /**
         * Every property can have an action even though a participant has not landed on the property. The
         * actions differs from Upgradable Property and Non Upgradable Property.
         * @param game The current game state
         */
        virtual void doActionWithoutBeingOnProperty(GameMechanics::Game * game) = 0;

        /**
         * Print the details of the property. This needed for all subclasses since name only is not enough.
         * @return A string containing the details of the class.
         */
        virtual std::string toString() = 0;

        /**
         * Banker auctions the property for the highest bidder. The bidding starts from 0.
         * @param game The current game to get all participants playing.
         */
        void auctionHouse(GameMechanics::Game * game);

        /**
         * Will return true if the owner of this property has all of this Colour group. Therefore no
         * arguments are needed since the variables needed are taken from this.
         * @return True if owner has all same Colour, otherwise false.
         */
        bool checkIfOwnerHasAllSameColour();
    };
}

#endif //MONOPOLY_PROPERTY_H
