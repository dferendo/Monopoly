//
// Created by dylan on 16/11/2016.
//

#include "Property.h"
#include "../GameMechanics/Game.h"

GameBoard::Property::Property(const string &name, double propertyPrice,
                              double rentCost, string colour) : Tile(name), propertyPrice(propertyPrice),
                                                                rentCost(rentCost), colour(colour){}


Player::Participant* GameBoard::Property::getOwner() {
    return owner;
}

void GameBoard::Property::setOwner(Player::Participant *owner) {
    Property::owner = owner;
}

void GameBoard::Property::noOwner(Player::Participant *player, GameMechanics::Game * game) {
    vector<string> noOwnerChoice;
    noOwnerChoice.push_back("Buy property");
    noOwnerChoice.push_back("Banker auction property");

    cout << getName() << " is currently on sale!!\nChoices available: " << endl;
    Util::displayMenu(noOwnerChoice);
    int choice = Util::readIntegerWithRange(0, 1);
    if (choice == 0) {
        buyHouse(player);
    } else {
        auctionHouse(game);
    }
}

void GameBoard::Property::buyHouse(Player::Participant *player) {
    player->getMoney().subtractBalance(propertyPrice);
    player->addParticipantProperty(this);
    setOwner(player);
}

// TODO fix this mass
void GameBoard::Property::auctionHouse(GameMechanics::Game * game) {
    double currentBid = 0;
    int highestBidder;
    int temp;
    string input;

    cout << "Auctioning " << getName() << "." << endl;
    cout << "Current bid: " << currentBid << endl;
    Util::displayPlayers(game->getParticipantsPlaying());
    cout << "Select player number to bid." << endl;
    highestBidder = Util::readIntegerWithRange(0, (int) game->getParticipantsPlaying().size());
    cout << "Enter amount: ";
    currentBid = Util::readPositiveInteger();
    // Will loop until quit
    while (true) {
        cout << "Current bid: " << currentBid << endl;
        Util::displayPlayers(game->getParticipantsPlaying());
        cout << "Select player number to bid." << endl;
        temp = Util::readIntegerWithRange(0, (int) game->getParticipantsPlaying().size() - 1);
        cout << "Enter amount: ";
        double amount = Util::readPositiveInteger();
        if (amount > currentBid) {
            currentBid = amount;
            highestBidder = temp;
        } else {
            cout << "It is lower than the current bid, not accepted" << endl;
        }
        cout << "Continue bidding? (q to quit)" << endl;
        getline(cin, input);
        if (input[0] == 'q') {
            break;
        }
    }
    cout << "Congratulations to " << game->getParticipantsPlaying()[highestBidder]->getName() << " for buying " << getName() << endl;
    game->getParticipantsPlaying()[highestBidder]->getMoney().subtractBalance(currentBid);
    game->getParticipantsPlaying()[highestBidder]->addParticipantProperty(this);
    setOwner(game->getParticipantsPlaying()[highestBidder]);
}

const string &GameBoard::Property::getColour() const {
    return colour;
}

double GameBoard::Property::getRentCost() const {
    return rentCost;
}

