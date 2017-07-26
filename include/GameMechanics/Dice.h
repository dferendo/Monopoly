//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_DICE_H
#define MONOPOLY_DICE_H

#include <utility>
namespace GameMechanics {

    class Dice {
    private:
        const int MINIMUM_DICE = 1;
        const int MAXIMUM_DICE = 6;
        std::pair<int, int> diceRoll;
    public:
        /**
         * For every turn, 2 dices are rolled and thus the values are held in a pair. Will generate
         * 2 random numbers between 1 - 6 and returns the result.
         * @return
         */
        std::pair<int, int> *generateNewDiceRoll();

        std::pair<int, int> *getCurrentDiceRoll();
    };
}
#endif //MONOPOLY_DICE_H
