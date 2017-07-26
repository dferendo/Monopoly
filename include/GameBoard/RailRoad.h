//
// Created by dylan on 19/11/2016.
//

#ifndef MONOPOLY_RAILROAD_H
#define MONOPOLY_RAILROAD_H

#include "NonUpgradableProperty.h"

namespace GameBoard {

    class RailRoad: public NonUpgradableProperty {
    public:
        RailRoad(const std::string &name, const double propertyPrice, const double rentCost, const ColourType &colour,
                 const double mortgage);
        /**
         * The only thing that differs from the {@link GameBoard::Utility} property is how the rentCost is calculated.
         * Rent cost is calculated by the amount of railroads owned by this owner. Cost is 25, 50, 100, 200
         * according to the number of railroads owned.
         * @param game The current game
         * @return The rent cost
         */
        double getRentCost(GameMechanics::Game *game) override;
    };
}
#endif //MONOPOLY_RAILROAD_H
