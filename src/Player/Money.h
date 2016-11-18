//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_MONEY_H
#define MONOPOLY_MONEY_H

namespace Player {

    class Money {
    private:
        double balance;
    public:
        Money(double balance);
        double getBalance() const;
        void addBalance(double balance);
        void subtractBalance(double balance);
    };
}
#endif //MONOPOLY_MONEY_H
