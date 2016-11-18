//
// Created by dylan on 17/11/2016.
//

#include "Money.h"

Player::Money::Money(double balance) : balance(balance) {}

double Player::Money::getBalance() const {
    return balance;
}

void Player::Money::addBalance(double balance) {
    Money::balance += balance;
}

// TODO throw exception if no funds?
// TODO when negative
void Player::Money::subtractBalance(double balance) {
    Money::balance -= balance;
}