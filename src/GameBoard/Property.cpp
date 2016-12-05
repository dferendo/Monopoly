//
// Created by dylan on 16/11/2016.
//

#include "Property.h"
#include "../Exception/NoMoneyException.h"

using namespace Exception;

GameBoard::Property::Property(const string &name, double propertyPrice,
                              double rentCost, Colour colour, double mortgage) : Tile(name), Mortgage(mortgage), propertyPrice(propertyPrice),
                                                                                 rentCost(rentCost), colour(colour){}


Participant* GameBoard::Property::getOwner() {
    return owner;
}

void GameBoard::Property::setOwner(Participant *owner) {
    Property::owner = owner;
}

void GameBoard::Property::noOwner(Participant *player, GameMechanics::Game * game) {
    int choice = 0;
    vector<string> noOwnerChoice;
    noOwnerChoice.push_back("Property details");
    noOwnerChoice.push_back("Buy property");
    noOwnerChoice.push_back("Banker auction property");

    cout << getName() << " is currently on sale for the price of "<< getPropertyPrice()
         << "!!\nChoices available: " << endl;
    try {
        while (choice == 0) {
            Util::displayMenu(noOwnerChoice);
            choice = Util::readIntegerWithRange(0, (int) noOwnerChoice.size());
            if (choice == 0) {
                cout << toString(*this) << endl;
            } else if (choice == 1) {
                buyProperty(player);
            } else {
                auctionHouse(game);
            }
        }
    } catch (NoMoneyException & exception) {
        cout << exception.message << " The house will be auctioned." << endl;
        auctionHouse(game);
    }
}

void GameBoard::Property::buyProperty(Participant *player) {
    try {
        player->getMoney().subtractBalance(propertyPrice);
        player->addParticipantProperty(this);
        setOwner(player);
    } catch (NoMoneyException &exception) {
        // Catching the exception and rethrow it.
        throw NoMoneyException(exception.amountDue);
    }
}

// TODO improve this
void GameBoard::Property::auctionHouse(GameMechanics::Game * game) {
    // Bids can start from any amount including 0
    double currentBid = -1;
    Participant * bidder = nullptr;
    Participant * tempBidder = nullptr;
    string input = "y";

    cout << "Auctioning " << getName() << "." << endl;
    // Will loop until quit
    while (input[0] == 'Y' || input[0] == 'y')  {
        cout << "Current bid: " << currentBid << endl;
        tempBidder = selectBidder(game->getParticipantsPlaying(), bidder);
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
    Util::displayPlayers(participants);
    cout << "Select player number to bid." << endl;
    int participantIndex = Util::readIntegerWithRange(0, (int) participants.size() - 1);
    return participants[participantIndex];
}

const GameBoard::Colour &GameBoard::Property::getColour() const {
    return colour;
}

string GameBoard::Property::getName() {
    if (isPropertyMortgage()) {
        return Tile::getName() + " - Mortgage";
    }
    return Tile::getName();
}

bool GameBoard::Property::checkIfOwnerHasAllSameColour(Player::Participant *player, GameMechanics::Game *game) {
    // TODO fix this
    return player->getSameGroupColourPropertiesAmount(getColour()) == game->getGroupColoursSize(getColour());
}

double GameBoard::Property::getPropertyPrice() const {
    return propertyPrice;
}
