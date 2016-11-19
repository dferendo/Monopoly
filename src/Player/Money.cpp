//
// Created by dylan on 17/11/2016.
//

#include "Money.h"
#include <iostream>
#include "../Util/ReadInput.h"

Player::Money::Money(double balance) : balance(balance) {}

double Player::Money::getBalance() const {
    return balance;
}

void Player::Money::addBalance(double amount) {
    std::cout << "Current balance: " << balance << " Additional balance: " << amount << std::endl;
    Money::balance += amount;
}

// TODO throw exception if no funds?
// TODO when negative
void Player::Money::subtractBalance(double amount) {
    std::cout << "Current balance: " << balance << " Subtracted balance: " << amount << std::endl;
    Money::balance -= amount;
}