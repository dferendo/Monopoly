//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_MONEY_H
#define MONOPOLY_MONEY_H

#include <iostream>

namespace Player {

    class Money {
    private:
        std::string owner;
        double balance;
    public:
        Money(std::string owner, double balance);

        double getBalance() const;

        void addBalance(double amount);

        /**
         * Subtract amount from balance. If the balance is negative a NoMoneyException is thrown with the
         * amount required to make the transaction.
         * @param amount The amount to subtract.
         */
        void subtractBalance(double amount);
    };
}
#endif //MONOPOLY_MONEY_H
