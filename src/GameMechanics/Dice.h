//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_DICE_H
#define MONOPOLY_DICE_H

#include <utility>
namespace GameMechanics {
    const int MINIMUM_DICE = 1;
    const int MAXIMUM_DICE = 6;

    class Dice {
    private:
        std::pair<int, int> diceRoll;
    public:
        std::pair<int, int> *generateNewDiceRoll();
        std::pair<int, int> *getCurrentDiceRoll();
    };
}
#endif //MONOPOLY_DICE_H
