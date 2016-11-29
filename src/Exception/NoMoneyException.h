//
// Created by dylan on 29/11/2016.
//

#ifndef MONOPOLY_NOMONEYEXCEPTION_H
#define MONOPOLY_NOMONEYEXCEPTION_H

#include <iostream>
#include "../Player/Participant.h"
#include "../GameMechanics/Trade.h"
#include "../GameMechanics/Move.h"
#include "../GameMechanics/SellingBuilding.h"

using namespace std;
using namespace Player;
using namespace GameMechanics;

namespace Exception {
    class NoMoneyException {
    public:
        string message;
        double amountDue;
        NoMoneyException(double amountDue);
        bool payAmountDue(GameMechanics::Game *game, double amountDue, Participant *debitor, Participant *creditor);
        bool payDebt(double amountDue, Participant *debitor, Participant *creditor);
    };
}

#endif //MONOPOLY_NOMONEYEXCEPTION_H
