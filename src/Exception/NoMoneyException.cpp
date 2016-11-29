//
// Created by dylan on 29/11/2016.
//

#include <sstream>
#include "NoMoneyException.h"

namespace Exception {
    NoMoneyException::NoMoneyException(double amountDue) : amountDue(amountDue) {
        stringstream messageCompose;
        messageCompose << "You ran out of Money! You need to have " << amountDue << " more.";
        message = messageCompose.str();
    }

    bool NoMoneyException::payAmountDue(GameMechanics::Game *game, double amountDue, Participant *debitor,
                                        Participant *creditor) {
        int selection = 0;
        bool amountIsPaid = false;
        vector<string> displayMenu;

        displayMenu.push_back("Trade");
        displayMenu.push_back("Sell buildings(houses)");
        displayMenu.push_back("Mortgage");
        displayMenu.push_back("Pay debt");
        displayMenu.push_back("Declare Bankruptcy");
        // Trade, sell property, display participant information or move
        while (!amountIsPaid) {
            Util::displayMenu(displayMenu);
            selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
            switch (selection) {
                case 0: {
                    Trade::tradePropertySellerKnown(game, debitor);
                    break;
                }
                case 1: {
                    SellingBuilding::sellBuilding(debitor);
                    break;
                }
                case 2: {
                    game->mortgageProperty(debitor);
                    break;
                }
                case 3: {
                    amountIsPaid = payDebt(amountDue, debitor, creditor);
                    break;
                }
                case 4: {
                    return false;
                }
            }
        }
        return true;
    }

    bool NoMoneyException::payDebt(double amountDue, Participant *debitor, Participant *creditor) {
        try {
            debitor->getMoney().subtractBalance(amountDue);
            // If creditor is nullptr, it is the bank so no addition of funds
            if (creditor != nullptr) {
                creditor->getMoney().addBalance(amountDue);
            }
            return true;
        } catch (NoMoneyException &exception) {
            cout << exception.message << endl;
            return false;
        }
    }
}
