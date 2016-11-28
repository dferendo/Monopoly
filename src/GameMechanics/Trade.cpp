//
// Created by dylan on 27/11/2016.
//

#include <sstream>
#include "Trade.h"
#include "../Exception/NoHousesException.h"

void GameMechanics::Trade::tradeProperty(GameMechanics::Game *game, Participant * buyer) {
    Participant * seller = determineSeller(game->getParticipantsPlaying(), buyer);
    try {
        // Display properties
        vector<GameBoard::Property *> nonImprovedProperties;
        seller->getNonImprovedParticipantProperties(nonImprovedProperties);
        Util::displayNonImprovedHouseForPlayer(seller, nonImprovedProperties);
        int indexOfHouseToBuy = Util::readIntegerWithRange(0, (int) nonImprovedProperties.size() - 1);
        transactionTrade(buyer, seller, nonImprovedProperties[indexOfHouseToBuy]);
    } catch(NoHousesException &exception) {
        cout << exception.message << " Cancelling trade." << endl;
        return;
    }
}

Participant *GameMechanics::Trade::determineSeller(vector<Participant *> participants, Participant *buyer) {
    cout << "To whom you want to trade?" << endl;
    // Erase is done on a copy of the reference
    participants.erase(remove(participants.begin(), participants.end(), buyer), participants.end());
    Util::displayPlayers(participants);
    int indexOfParticipant = Util::readIntegerWithRange(0, (int) participants.size() - 1);
    return participants[indexOfParticipant];
}

void GameMechanics::Trade::transactionTrade(Participant *buyer, Participant *seller,
                                            GameBoard::Property *propertyForSale) {
    set<GameBoard::Property *> propertiesOffered;
    vector<string> displayTradeOptions;
    double cashOffered = 0;
    int offerChoice = 0;

    displayTradeOptions.push_back("Offer new cash amount");
    displayTradeOptions.push_back("Offer property(Can offer multiple properties)");
    displayTradeOptions.push_back("Make transaction");
    displayTradeOptions.push_back("Quit transaction");

    cout << buyer->getName() << " request to buy " << propertyForSale->getName() << " from " << seller->getName()
         << "." << endl;
    while (offerChoice != 3) {
        cout << buyerOffer(buyer, cashOffered, propertiesOffered) << endl;
        Util::displayMenu(displayTradeOptions);
        offerChoice = Util::readIntegerWithRange(0, (int) displayTradeOptions.size() - 1);
        switch (offerChoice) {
            case 0: {
                cashOffered = offerCash(buyer);
                break;
            }
            case 1: {
                GameBoard::Property *property = offerProperty(buyer);
                if (property != nullptr) {
                    propertiesOffered.insert(property);
                }
                break;
            }
            case 2:  {
                if(makeTransaction(buyer, seller, cashOffered, propertiesOffered, propertyForSale)) {
                    return;
                }
                break;
            }
            default:
                return;
        }
    }
}

double GameMechanics::Trade::offerCash(Participant *buyer) {
    // TODO check if buyer has amount
    cout << "Enter offer amount: ";
    return Util::readPositiveDouble();
}

GameBoard::Property *GameMechanics::Trade::offerProperty(Participant *buyer) {
    try {
        vector<GameBoard::Property *> nonImprovedProperties;
        buyer->getNonImprovedParticipantProperties(nonImprovedProperties);
        Util::displayNonImprovedHouseForPlayer(buyer, nonImprovedProperties);
        int indexOfHouseToOffer = Util::readIntegerWithRange(0, (int) nonImprovedProperties.size() - 1);
        GameBoard::Property * property = nonImprovedProperties[indexOfHouseToOffer];
        return property;
    } catch(NoHousesException &exception) {
        cout << exception.message << " Cancelling property offer. (Make cash only)" << endl;
        return nullptr;
    }
}

bool GameMechanics::Trade::makeTransaction(Participant *buyer, Participant *seller, double cashOffered,
                                           set<GameBoard::Property *> propertiesOffered,
                                           GameBoard::Property *propertyForSale) {
    string input;
    cout << buyerOffer(buyer, cashOffered, propertiesOffered) << endl;
    cout << seller->getName() << " do you accept offer? (Y/n)" << endl;
    getline(cin, input);
    if (input[0] == 'y' || input[0] == 'Y') {
        // Add cash to seller
        if (cashOffered != 0) {
            buyer->getMoney().subtractBalance(cashOffered);
            seller->getMoney().addBalance(cashOffered);
        }
        // Set properties to new owner. Buyer offered properties to seller
        if (propertiesOffered.size() != 0) {
            for (auto &property : propertiesOffered) {
                property->setOwner(buyer);
                seller->addParticipantProperty(property);
                buyer->removeProperty(property);
            }
        }
        // Set property actually trade to new owner
        propertyForSale->setOwner(buyer);
        seller->removeProperty(propertyForSale);
        buyer->addParticipantProperty(propertyForSale);
        return true;
    } else {
        cout << "Offer refused! Offer something more?" << endl;
        return false;
    }
}

string GameMechanics::Trade::buyerOffer(Participant *buyer, double cashOffered,
                                        set<GameBoard::Property *> propertiesOffered) {
    stringstream buyerOffer;
    buyerOffer << buyer->getName() << " offered: ";
    if (cashOffered == 0 && propertiesOffered.size() == 0) {
        buyerOffer << "Nothing";
    } else {
        if (cashOffered != 0) {
            buyerOffer << "Cash amount: " << cashOffered;
        }
        if (propertiesOffered.size() != 0) {
            buyerOffer << " Properties: ";
            for (auto &property : propertiesOffered) {
                // TODO fix comma
                buyerOffer << property->getName() << ", ";
            }
        }
    }
    return buyerOffer.str();
}