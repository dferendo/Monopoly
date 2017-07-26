//
// Created by dylan on 28/11/2016.
//

#ifndef MONOPOLY_MOVE_H
#define MONOPOLY_MOVE_H

#include "Game.h"

namespace GameMechanics {

    class Move {
    private:
        /**
         * Determines the new location on the board by adding the dice count of both dices with
         * the current location on the participant. The board has 40 Tiles in total and if the
         * participant new location is greater than that number, the modulus is taken.
         * @param game The current game.
         * @param participant The participant that has his turn.
         * @param diceCount The count of the two dice rolled
         * @return
         */
        int determineParticipantLocation(Game * game, Player::Participant *participant, int diceCount);

        /**
         * Determines if the participant can have his Go funds {@link GameMechanics#GO_AMOUNT}. The Go funds
         * are received if a participant has completed a pass on the board (ie location > Total tiles).
         * @param participant The current participant that has his turn.
         * @param location The new location without using modulus on the new location.
         */
        void validateGoFunds(Player::Participant *participant, int location);

        /**
         * Generates the random number for both dices. Returns the addition on both dices number.
         * @param dice The dice that holds the current dices roll.
         * @return The addition of the two dices.
         */
        int generateDiceCount(Dice *dice);

        /**
         * Check if the dices rolled have the same numbers.
         * @param dice The dice.
         * @return True if the dices have the same numbers, false otherwise.
         */
        bool checkDiceDouble(Dice *dice);
    public:
        /**
         * Moves the participants to a random location by rolling two dices. If dices have the same number
         * the participants will get to roll the dices again after doing the action associated with the
         * previous roll. If the participants rolls doubles for 3 consecutive times, the participant will move to
         * the jail Tile and ending his turn. If a player goes bankrupt and rolled a double, his turn ends.
         * @param game The current game.
         * @param participant The participant that has his turn.
         * @param dice The dice that contains the numbers generated.
         */
        static void move(Game * game, Player::Participant *participant, Dice *dice);
    };
}


#endif //MONOPOLY_MOVE_H
