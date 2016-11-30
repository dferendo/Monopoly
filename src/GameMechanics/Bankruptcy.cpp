//
// Created by dylan on 29/11/2016.
//

#include "Bankruptcy.h"
#include <algorithm>

void Bankruptcy::transferProperties(GameMechanics::Game * game, Player::Participant *currentOwner, Player::Participant *newOwner) {
    vector<Participant *> &participantsPlaying = game->getParticipantsPlaying();
    vector<GameBoard::Property *> &participantProperties = currentOwner->getParticipantProperties();
    double moneyAmount = currentOwner->getMoney().getBalance();

    // Remove bankrupt player from list, Note it is non de-allocated yet
    participantsPlaying.erase(remove(participantsPlaying.begin(), participantsPlaying.end(), currentOwner),
                              participantsPlaying.end());
    cout << "Cleaning " << currentOwner->getName() << " remaining items." << endl;
    // New owner gets the cash, if new Owner is bank ignore it
    if (moneyAmount > 0 && newOwner != nullptr) {
        newOwner->getMoney().addBalance(moneyAmount);
    }
    // New owner gets the property
    for (auto &property : participantProperties) {
        // New owner is bank thus will auction properties
        if (newOwner == nullptr) {
            property->auctionHouse(game);
        } else {
            if (property->isPropertyMortgage()) {
                cout << newOwner->getName() << ": " << property->getName() << "property is mortgage!" << endl;
                property->removeMortgage(newOwner);
            }
            newOwner->addParticipantProperty(property);
            currentOwner->removeProperty(property);
        }
    }
    cout << "Thanks for playing " << currentOwner->getName() << "!!" << endl;
    // Deallocate user
    delete currentOwner;
}
