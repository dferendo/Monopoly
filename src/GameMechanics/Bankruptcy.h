//
// Created by dylan on 29/11/2016.
//

#ifndef MONOPOLY_BANKRUPTCY_H
#define MONOPOLY_BANKRUPTCY_H


#include "../Player/Participant.h"
#include "Game.h"

class Bankruptcy {
public:
    static void transferProperties(GameMechanics::Game * game, Player::Participant * currentOwner, Player::Participant * newOwner);
};


#endif //MONOPOLY_BANKRUPTCY_H
