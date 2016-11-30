//
// Created by dylan on 27/11/2016.
//

#include <sstream>
#include "Trade.h"
#include "../Exception/NoPropertyException.h"
using namespace Exception;

void GameMechanics::Trade::tradePropertyBuyerKnown(GameMechanics::Game *game, Participant *buyer) {
    Trade trade;
    // Note that mortgage properties can still be traded
    cout << "To whom you want to trade?" << endl;
    Participant * seller = trade.determineTrader(game->getParticipantsPlaying(), buyer);
    try {
        // Display properties
        vector<GameBoard::Property *> &allParticipantsProperties= seller->getParticipantProperties();
        Util::displayHouseForPlayer(seller, allParticipantsProperties);
        int indexOfHouseToBuy = Util::readIntegerWithRange(0, (int) allParticipantsProperties.size() - 1);
        trade.transactionTrade(buyer, seller, allParticipantsProperties[indexOfHouseToBuy]);
    } catch(NoPropertyException &exception) {
        cout << exception.message << " Cancelling trade." << endl;
        return;
    }
}

void GameMechanics::Trade::tradePropertySellerKnown(GameMechanics::Game *game, Participant *seller) {
    Trade trade;
    // Note that mortgage properties can still be traded
    cout << "Anyone wants to trade with " << seller->getName() << "?" << endl;
    Participant * buyer = trade.determineTrader(game->getParticipantsPlaying(), seller);
    try {
        // Display properties
        vector<GameBoard::Property *> &allParticipantProperties = seller->getParticipantProperties();
        Util::displayHouseForPlayer(seller, allParticipantProperties);
        int indexOfHouseToBuy = Util::readIntegerWithRange(0, (int) allParticipantProperties.size() - 1);
        trade.transactionTrade(buyer, seller, allParticipantProperties[indexOfHouseToBuy]);
    } catch(NoPropertyException &exception) {
        cout << exception.message << " Cancelling trade." << endl;
        return;
    }
}

Participant *GameMechanics::Trade::determineTrader(vector<Participant *> participants, Participant *buyer) {
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
    double highestOffer = buyer->getMoney().getBalance();
    cout << buyer->getName() << " highest offer is " << highestOffer << "." << endl;
    cout << "Enter offer amount: ";
    return Util::readPositiveDoubleWithLimit(highestOffer);
}

GameBoard::Property *GameMechanics::Trade::offerProperty(Participant *buyer) {
    try {
        vector<GameBoard::Property *> &allParticipantProperty = buyer->getParticipantProperties();
        Util::displayHouseForPlayer(buyer, allParticipantProperty);
        int indexOfHouseToOffer = Util::readIntegerWithRange(0, (int) allParticipantProperty.size() - 1);
        GameBoard::Property * property = allParticipantProperty[indexOfHouseToOffer];
        return property;
    } catch(NoPropertyException &exception) {
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
            // The NoMoneyException can never be triggered since user can only enter an amount
            // that he has.
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
