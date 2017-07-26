//
// Created by dylan on 16/11/2016.
//

#include "../../include/GameBoard/Property.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/GameMechanics/Bankruptcy.h"

using namespace Exception;
using namespace std;
using namespace Player;
using namespace GameMechanics;

GameBoard::Property::Property(const string &name, const double propertyPrice,
                              const double rentCost, const ColourType colour, const double mortgage)
        : Tile(name), Mortgage(mortgage), propertyPrice(propertyPrice), rentCost(rentCost), colour(colour){}


void GameBoard::Property::noOwner(Participant *participant, GameMechanics::Game * game) {
    int choice = 0;
    vector<string> noOwnerChoice = {"Property details", "Buy property", "Banker auction property"};

    cout << getName() << " is currently on sale for the price of "<< getPropertyPrice()
         << "!!\nChoices available: " << endl;
    try {
        while (choice == 0) {
            // Can view property details as many times as the user wants
            Util::displayMenu(noOwnerChoice);
            choice = Util::readIntegerWithRange(0, (int) noOwnerChoice.size() - 1);
            if (choice == 0) {
                cout << toString() << endl;
            } else if (choice == 1) {
                buyProperty(participant);
            } else {
                auctionHouse(game);
            }
        }
    } catch (NoMoneyException & exception) {
        // If participant cannot buy property, it will be auctioned.
        cout << exception.message << " The house will be auctioned." << endl;
        auctionHouse(game);
    }
}

void GameBoard::Property::buyProperty(Participant *participant) {
    try {
        participant->getMoney().subtractBalance(propertyPrice);
        participant->addParticipantProperty(this);
        setOwner(participant);
    } catch (NoMoneyException &exception) {
        // If participant cannot buy property, throw an exception.
        throw NoMoneyException(exception.amountDue);
    }
}

void GameBoard::Property::auctionHouse(GameMechanics::Game * game) {
    // Bids can start from any amount including 0
    double currentBid = -1;
    Participant * bidder = nullptr;
    Participant * tempBidder = nullptr;
    string input = "y";

    cout << "Auctioning " << getName() << "." << endl;
    // Will loop until quit
    while (input[0] == 'Y' || input[0] == 'y')  {
        if (currentBid != -1) {
            cout << "Current bid: " << currentBid << endl;
        }
        tempBidder = selectBidder(game->getParticipantsPlaying(), bidder);
        // Get balance so that player cannot offer more money than he can afford
        double highestAmount = tempBidder->getMoney().getBalance();
        cout << tempBidder->getName() << " highest offer is " << highestAmount << "." <<endl;
        cout << "Enter amount greater or equal to 0: ";
        double amount = Util::readPositiveDoubleWithLimit(tempBidder->getMoney().getBalance());
        // First bid will always be greater or equal than 0, thus the first bid
        // is always accepted. No nullptr risk.
        if (amount > currentBid) {
            currentBid = amount;
            bidder = tempBidder;
        } else {
            cout << "It is lower than the current bid, not accepted." << endl;
        }
        cout << "Continue bidding? (Y/n)" << endl;
        getline(cin, input);
    }
    // This exception can be thrown since participant can never enter an amount greater then he can afford

    bidder->getMoney().subtractBalance(currentBid);
    bidder->addParticipantProperty(this);
    setOwner(bidder);
    cout << "Congratulations to " << bidder->getName() << " for buying " << getName() << endl;
}

Participant * GameBoard::Property::selectBidder(vector<Participant *> participants, Participant *currentBidder) {
    // Remove current bidder from bidding again
    if (currentBidder != nullptr) {
        participants.erase(remove(participants.begin(), participants.end(), currentBidder), participants.end());
    }
    Util::displayParticipants(participants);
    cout << "Select player number to bid." << endl;
    int participantIndex = Util::readIntegerWithRange(0, (int) participants.size() - 1);
    return participants[participantIndex];
}

bool GameBoard::Property::checkIfOwnerHasAllSameColour() {
    return getOwner()->getSameGroupColourPropertiesAmount(getColourType()) == Colour::getGroupColoursSize(getColourType());
}

string GameBoard::Property::getName() {
    if (isPropertyMortgage()) {
        return Tile::getName() + " - Mortgage";
    }
    return Tile::getName();
}

const GameBoard::ColourType &GameBoard::Property::getColourType() const {
    return colour;
}

double GameBoard::Property::getPropertyPrice() const {
    return propertyPrice;
}

Participant* GameBoard::Property::getOwner() {
    return owner;
}

void GameBoard::Property::setOwner(Participant *owner) {
    Property::owner = owner;
}

void GameBoard::Property::payRent(Participant *participant, GameMechanics::Game *game) {
    double amount = getRentCost(game);

    // If property is mortgaged, no rent is due
    if (isPropertyMortgage()) {
        cout << "Property is mortgage, no rent is due." << endl;
        return;
    }

    try {
        participant->getMoney().subtractBalance(amount);
        getOwner()->getMoney().addBalance(amount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // Check if participant can pay amount by trading, selling and mortgage
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, participant, getOwner());
        // If participant cannot pay debt, he will be declared bankrupt
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, participant, getOwner());
        }
    }
}
