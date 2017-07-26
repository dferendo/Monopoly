//
// Created by dylan on 29/11/2016.
//

#ifndef MONOPOLY_NOMONEYEXCEPTION_H
#define MONOPOLY_NOMONEYEXCEPTION_H

#include <iostream>
#include "../Player/Participant.h"
#include "../GameMechanics/Trade.h"
#include "../GameMechanics/Move.h"

namespace Exception {

    class NoMoneyException {
    public:
        std::string message;

        /**
         * Amount due by the debitor to the creditor.
         */
        double amountDue;

        NoMoneyException(double amountDue);

        /**
         * Debitor tries to get enough money to pay his debt due to the creditor. Debitor tries to get enough
         * money by trading to other participants, selling houses or mortgage properties. The debitor
         * can either pay his debt, which returns true, or declare Bankrupt which returns false.
         * @param game The current game.
         * @param amountDue The amount due.
         * @param debitor The participant that has debt.
         * @param creditor The participant that the debitor needs to give money to.
         * @return True if the debitor pays his debt, false otherwise.
         */
        bool payAmountDue(GameMechanics::Game *game, double amountDue, Player::Participant *debitor,
                          Player::Participant *creditor);

        /**
         * Checks whether the debitor can pay his debt. If he cannot the exception is caught and returns false.
         * If the debitor can pay his debt, the money is subtracted from the debitor account and put to the
         * creditor account and returns true. If the creditor is the banker, it is indicated by a null pointer
         * and no funds are added.
         * @param amountDue The amount due.
         * @param debitor The participant that has debt.
         * @param creditor The participant that the debitor needs to give money to.
         * @return Returns true if the debitor paid his debt, false otherwise.
         */
        bool payDebt(double amountDue, Player::Participant *debitor, Player::Participant *creditor);
    };
}

#endif //MONOPOLY_NOMONEYEXCEPTION_H
