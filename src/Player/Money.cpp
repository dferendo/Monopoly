//
// Created by dylan on 17/11/2016.
//

#include "../../include/Player/Money.h"
#include "../../include/Util/ReadInput.h"
#include "../../include/Exception/NoMoneyException.h"
using namespace Exception;

Player::Money::Money(std::string owner, double balance) : owner(owner), balance(balance) {}

double Player::Money::getBalance() const {
    return balance;
}

void Player::Money::addBalance(double amount) {
    std::cout << owner << "'s current balance: " << balance << ". Will add: " << amount << std::endl;
    Money::balance += amount;
}

void Player::Money::subtractBalance(double amount) {
    double checkIfInDebt = getBalance() - amount;
    if (checkIfInDebt < 0) {
        throw NoMoneyException(amount);
    }
    std::cout << owner << "'s current balance: " << balance << ". Will subtract: " << amount << std::endl;
    Money::balance -= amount;
}
