//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_XORTI_H
#define MONOPOLY_XORTI_H

#include "Tile.h"
#include "../Player/Participant.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {

    class Xorti: public Tile {
    private:
        // Prices to avoid magic numbers
        const int MAXIMUM_XORTI = 4;
        const int MAXIMUM_BIRTHDAY_PRICE = 100;
        const int MINIMUM_BIRTHDAY_PRICE = 10;
        const int MAXIMUM_PARKING_FINE = 150;
        const int MINIMUM_PARKING_FINE = 50;
        const int MAXIMUM_MEPA_FINE = 180;
        const int MINIMUM_MEPA_FINE = 40;
        /**
         * Takes a random amount from every participant playing except the participant that
         * landed on the tile a random amount between 10 - 100. If a participant cannot pay
         * the random amount, the {@link Exception::NoMoneyException} is handled within this
         * method since there are other players that need to pay.
         * @param participant The participant that landed on the Tile.
         * @param game Receives all participants.
         */
        void birthday(Player::Participant &participant, GameMechanics::Game * game);

        /**
         * Parking in a lecturer spot. Take a random amount between 50 - 150 and the amount is added
         * to the Parking jackpot price {@link GameBoard::Parking}. Throws exception if participant
         * does not have enough money.
         * @param participant The participant that landed on the Tile.
         * @param game Add the amount to the jackpot.
         */
        void parkingFine(Player::Participant &participant, GameMechanics::Game * game);

        /**
         * Mepa fines you for every building owned. Take a random amount between 40 - 180 for every
         * building owned. The money goes to the Parking jackpot price {@link GameBoard::Parking}.
         * Throws exception if participant does not have enough money.
         * @param participant The participant that landed on the Tile.
         * @param game Add the amount to the jackpot.
         */
        void mepaFine(Player::Participant &participant, GameMechanics::Game * game);

        /**
         * Move to a random location. The total tiles is taken from game.
         * @param participant The participant that landed on the Tile.
         * @param game Get the total tiles amount.
         */
        void moveToRandomPlace(Player::Participant &participant, GameMechanics::Game * game);

    public:
        Xorti(const std::string &name);

        /**
         * When a participant lands on a xorti tile, a random number is generated and depending on
         * the number an action is executed.
         * @param participant The participant that landed on the Tile.
         * @param game The game that holds all participants.
         */
        void action(Player::Participant *participant, GameMechanics::Game * game) override;
    };
}
#endif //MONOPOLY_XORTI_H
