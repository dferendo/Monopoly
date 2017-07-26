//
// Created by dylan on 29/11/2016.
//

#ifndef MONOPOLY_BANKRUPTCY_H
#define MONOPOLY_BANKRUPTCY_H


#include "../Player/Participant.h"
#include "Game.h"
namespace GameMechanics {

    class Bankruptcy {
    public:
        /**
         * Transfer properties or money remaining when a participant is declared Bankrupt. If the newOwner is
         * nullptr, it is indicated that the participant owes money to the banker and thus the properties
         * that the participant has are auctioned.
         * @param game The current game.
         * @param currentOwner The participant that went Bankrupt.
         * @param newOwner The new Owner of the items of the currentOwner participant. If it is nullptr, it is
         * indicated that the newOwner is the bank and the properties are auctioned.
         */
        static void transferProperties(GameMechanics::Game *game, Player::Participant *currentOwner,
                                       Player::Participant *newOwner);
    };
}


#endif //MONOPOLY_BANKRUPTCY_H
