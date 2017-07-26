//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "../GameMechanics/Game.h"
#include "HousesPrice.h"

namespace GameBoard {
    class UpgradableProperty: public Property {
    private:
        /**
         * Maximum houses a property can have is 4.
         */
        const int MAX_HOUSES = 4;
        /**
         * The prices to build a house and the rent for each house owned.
         */
        const HousesPrice housesPrice;
        int currentHousesBuild = 0;
        void setCurrentHousesBuild(int currentHousesBuild);

        /**
        * If the property is not mortgaged and the participant owns all of the same colour
        * he can add a house to his property. If the participant does not have enough money, the game
        * continues without adding a house to the property.
        * @param participant The participant that landed on the Property.
        */
        void addHouseToProperty(Player::Participant *participant);

        /**
         * Remove a house from the Property and returns half of want the owner spent to build it.
         * If there are no houses build on the property an exception is thrown. Participant
         * does not have to land on the property to sell houses.
         * @param participant The owner of the property.
         */
        void removeHouseFromProperty(Player::Participant *participant);
    public:
        UpgradableProperty(const std::string &name, const double propertyPrice, const double rentCost,
                           const ColourType &colour, const GameBoard::HousesPrice housesPrice,
                           const double mortgage);

        const HousesPrice &getHousesPrice() const;

        int getCurrentHousesBuild() const;

        /**
         * Overrides the Property method to also includes the total amount of houses the property has
         * indicated by * for every house. A property cannot have houses built on it if it is mortgaged.
         * @return The name with houses amount or whether it is mortgaged or not.
         */
        std::string getName();

        /**
         * Get the rent cost. If the owner does not owns all of the same colour group, the normal rent cost
         * is returned. If the owner has all the same colour group and does not have any house on this
         * property, the rent cost is doubled. If the property has houses the rent cost is calculated
         * by the {@link GameBoard::HousePrice}.
         * @param game The current game to check whether the owner has all houses of the same colour.
         * @return The rent cost amount.
         */
        double getRentCost(GameMechanics::Game *game) override;

        /**
         * Upgradable property have another action to them. If the banker is the owner (nullptr) the participant
         * that landed on the property can either buy it or auction it. If the participant is the owner
         * he will be offered to add a house to the property if the owners owns all of the same colour
         * group. If the participant is not the owner and the property is owned by someone, he will pay
         * the rent due.
         * @param participant The participant that landed on the Tile.
         * @param game The current game.
         */
        void action(Player::Participant *participant, GameMechanics::Game * game) override;

        /**
         * The actions that a UpgradableProperty can do without a participant landing on the Tile are:
         * View the details of the property, sell houses, make the property mortgaged if and only if
         * the property does not have houses built on it or remove property from being mortgaged. Exceptions
         * caught and handled in this method.
         * @param game The current game.
         */
        void doActionWithoutBeingOnProperty(GameMechanics::Game *game) override;

        /**
         * Override property details to also include the house to build cost and the rent cost if a
         * participant builds to certain house amount.
         * @return The property details.
         */
        std::string toString() override;
    };
}

#endif //MONOPOLY_UPGRADABLEPROPERTY_H
