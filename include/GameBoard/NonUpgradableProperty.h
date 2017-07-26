//
// Created by dylan on 30/11/2016.
//

#ifndef MONOPOLY_NONUPGRADABLEPROPERTY_H
#define MONOPOLY_NONUPGRADABLEPROPERTY_H

#include "Property.h"

namespace GameBoard {
    class NonUpgradableProperty : public Property {
    public:
        NonUpgradableProperty(const std::string &name, const double propertyPrice, const double rentCost,
                              const ColourType &colour, const double mortgage);
        /**
         * The NonUpgradableProperty all do the same action, thus can be declared here. If the property
         * does not have an owner, the participant can buy it or let the banker auction it.
         * If the property is owned, the participant has to pay rent if he is not the owner.
         * @param participant The participant that landed on the Tile.
         * @param game The current game board.
         */
        void action(Player::Participant *participant, GameMechanics::Game *game) override;

        /**
         * The NonUpgradableProperty can do some action that does not require the owner to be
         * on the tile. The owner can mortgage a house, remove mortgage from a house
         * or view the details of the house.
         * @param game the current game board.
         */
        void doActionWithoutBeingOnProperty(GameMechanics::Game * game) override;

        /**
         * Display the property details.
         * @return String which has all the property details.
         */
        std::string toString();
    };
}
#endif //MONOPOLY_NONUPGRADABLEPROPERTY_H
