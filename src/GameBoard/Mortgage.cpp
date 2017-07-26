//
// Created by dylan on 28/11/2016.
//

#include "../../include/GameBoard/Mortgage.h"
#include "../../include/Player/Participant.h"
#include "../../include/Exception/PropertyIsAlreadyMortgageException.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/Exception/PropertyIsNotMortgagedException.h"
using namespace Exception;
using namespace std;

GameBoard::Mortgage::Mortgage(double mortgagePrice) : mortgagePrice(mortgagePrice) {}

bool GameBoard::Mortgage::isPropertyMortgage() const {
    return propertyMortgage;
}

double GameBoard::Mortgage::getMortgagePrice() const {
    return mortgagePrice;
}

void GameBoard::Mortgage::makePropertyMortgage(Player::Participant *participant) {
    string input;

    // Cannot mortgaged a property that is already mortgaged
    if (isPropertyMortgage()) {
        throw PropertyIsAlreadyMortgageException();
    }

    cout << "You will receive " << getMortgagePrice() << " for this house to be mortgage. Do you accept? (Y/n)" << endl;
    getline(cin, input);

    // Add balance if and only if the player agrees
    if (input[0] == 'Y' || input[0] == 'y') {
        participant->getMoney().addBalance(mortgagePrice);
        propertyMortgage = true;
    }
}

void GameBoard::Mortgage::removeMortgage(Player::Participant *participant) {
    string input;
    double amount = mortgagePrice * INTEREST_PERCENTAGE;

    // Cannot remove mortgaged if the property is not mortgaged
    if (!isPropertyMortgage()) {
        throw PropertyIsNotMortgagedException();
    }

    cout << "To remove the mortgage it will cost you " << amount << ". Do you accept? (Y/n)" << endl;
    getline(cin, input);

    try {
        if (input[0] == 'Y' || input[0] == 'y') {
            participant->getMoney().subtractBalance(amount);
            propertyMortgage = false;
        }
    } catch (NoMoneyException &exception) {
        // If participant does not have money, return to precious menu
        cout << exception.message << " Returning to previous menu." << endl;
    }
}
