//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_SPECIALPROPERTY_H
#define MONOPOLY_SPECIALPROPERTY_H

#include "../GameMechanics/Game.h"
#include "NonUpgradableProperty.h"

namespace GameBoard {

    class UtilityProperty: public NonUpgradableProperty {
    private:
        const double OWNER_OWNS_BOTH_UTILITY_COST = 10;
    public:
        UtilityProperty(const std::string &name, const double propertyPrice, const double rentCost,
                        const ColourType &colour, const double mortgage);
        /**
         * The rent cost of Utility is calculated by the number of dice roll the participant rolled
         * to get to this Tile and multiple it by the rentCost variable. If the owner of the Property
         * owns both Utilities the rentCost is increase {@link GameBoard::OWNER_OWNS_BOTH_UTILITY}.
         * @param game The current game to get the dice roll.
         * @return The rent cost.
         */
        double getRentCost(GameMechanics::Game *game) override;
    };
}
#endif //MONOPOLY_SPECIALPROPERTY_H
