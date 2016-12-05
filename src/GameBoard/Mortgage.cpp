//
// Created by dylan on 28/11/2016.
//

#include "Mortgage.h"
#include "../Player/Participant.h"
#include "../Exception/PropertyIsAlreadyMortgageException.h"
#include "../Exception/NoMoneyException.h"
using namespace Exception;

GameBoard::Mortgage::Mortgage(double mortgagePrice) : mortgagePrice(mortgagePrice) {}

bool GameBoard::Mortgage::isPropertyMortgage() const {
    return propertyMortgage;
}

double GameBoard::Mortgage::getMortgagePrice() const {
    return mortgagePrice;
}

void GameBoard::Mortgage::makePropertyMortgage(Player::Participant *participant) {
    string input;

    if (isPropertyMortgage()) {
        throw PropertyIsAlreadyMortgageException();
    }
    cout << "You will receive " << getMortgagePrice() << " for this house to be mortgage. Do you accept? (Y/n)" << endl;
    getline(cin, input);

    if (input[0] == 'Y' || input[1] == 'y') {
        participant->getMoney().addBalance(mortgagePrice);
        propertyMortgage = true;
    }
}

void GameBoard::Mortgage::removeMortgage(Player::Participant *participant) {
    string input;
    double amount = mortgagePrice * INTEREST_PERCENTAGE;
    cout << "To remove the mortgage it will cost you " << amount << ". Do you accept? (Y/n)" << endl;
    getline(cin, input);

    try {
        if (input[0] == 'Y' || input[1] == 'y') {
            participant->getMoney().subtractBalance(amount);
            propertyMortgage = false;
        }
    } catch (NoMoneyException &exception) {
        cout << exception.message << " Returning to previous menu." << endl;
    }
}
