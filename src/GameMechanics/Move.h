//
// Created by dylan on 28/11/2016.
//

#ifndef MONOPOLY_MOVE_H
#define MONOPOLY_MOVE_H

#include "Game.h"
using namespace Player;

namespace GameMechanics {
    class Move {
        // TODO ask JP if should be static?
    private:
        void determineParticipantLocation(Game * game, Participant *participant, int diceCount);
        void validateGoFunds(Participant *participant, int location);
        int generateDiceCount(Dice *dice);
        bool checkDiceDouble(Dice *dice);
    public:
        static void move(Game * game, Participant *participant, Dice *dice);
    };
}


#endif //MONOPOLY_MOVE_H
