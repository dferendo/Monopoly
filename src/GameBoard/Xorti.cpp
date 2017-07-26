//
// Created by dylan on 16/11/2016.
//

#include "../../include/GameBoard/Xorti.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/GameMechanics/Bankruptcy.h"
using namespace Exception;
using namespace std;
using namespace GameMechanics;

GameBoard::Xorti::Xorti(const string &name) : Tile(name) {}

void GameBoard::Xorti::action(Player::Participant * participant, GameMechanics::Game * game) {
    int xorti = rand() % MAXIMUM_XORTI;
    try {
        if (xorti == 0) {
            birthday(*participant, game);
        } else if (xorti == 1) {
            parkingFine(*participant, game);
        } else if (xorti == 2) {
            mepaFine(*participant, game);
        } else {
            moveToRandomPlace(*participant, game);
        }
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // If participant cannot pay debt, he will be declared bankrupt
        // Owner is nullptr in this case since the player owns money to the bank
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, participant, nullptr);
        // If participant cannot pay the debt, declare bankruptcy
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, participant, nullptr);
        }
    }
}

void GameBoard::Xorti::birthday(Player::Participant &participant, GameMechanics::Game * game) {
    double birthdayMoney = rand() % (MAXIMUM_BIRTHDAY_PRICE - MINIMUM_BIRTHDAY_PRICE) + MINIMUM_BIRTHDAY_PRICE;
    std::cout << "It's your birthday!!! Take " << birthdayMoney << " as a gift from everyone." << std::endl;

    for (auto &player : game->getParticipantsPlaying()) {
        // If participant is the same, skip him
        if (player == &participant) {
            continue;
        }
        // Participant can run out of money, handle the situation here
        try {
            player->getMoney().subtractBalance(birthdayMoney);
            participant.getMoney().addBalance(birthdayMoney);
        } catch (NoMoneyException &noMoneyException) {
            cout << noMoneyException.message << endl;
            // If participant cannot pay debt, he will be declared bankrupt
            bool isPlayerNotBankrupt = noMoneyException.payAmountDue(game, noMoneyException.amountDue, player, &participant);
            // If participant cannot pay the debt, declare bankruptcy
            if (!isPlayerNotBankrupt) {
                Bankruptcy::transferProperties(game, player, &participant);
            }
        }
    }
}

void GameBoard::Xorti::parkingFine(Player::Participant &participant, GameMechanics::Game * game) {
    double parkingFine = rand() % (MAXIMUM_PARKING_FINE - MINIMUM_PARKING_FINE) + MINIMUM_PARKING_FINE;
    std::cout << "You parked at a lecturer's spot!!! You were fined " << parkingFine << "." << std::endl;
    try {
        participant.getMoney().subtractBalance(parkingFine);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + parkingFine);
    } catch (NoMoneyException & noMoneyException) {
        // If participant does not have enough money, handle the exception in action method
        throw NoMoneyException(noMoneyException.amountDue);
    }
}

void GameBoard::Xorti::mepaFine(Player::Participant &participant, GameMechanics::Game * game) {
    double mepaFine = rand() % (MAXIMUM_MEPA_FINE - MINIMUM_MEPA_FINE) + MINIMUM_MEPA_FINE;
    double totalFine = mepaFine * participant.getParticipantProperties().size();
    std::cout << "MEPA fined you!!! You were fined in total: " << totalFine << ". You have in total "
              << participant.getParticipantProperties().size() << " buildings and each building was fined "
              << mepaFine << "." << std::endl;
    // If participant does not have enough money, handle the exception in action method
    try {
        participant.getMoney().subtractBalance(totalFine);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + totalFine);
    } catch (NoMoneyException & noMoneyException) {
        throw NoMoneyException(noMoneyException.amountDue);
    }
}

void GameBoard::Xorti::moveToRandomPlace(Player::Participant &participant, GameMechanics::Game * game) {
    participant.setCurrentPosition(rand() % GameMechanics::TOTAL_TILES);
    std::cout << "You were moved to a random location!!! New location is: "
              << game->getGameBoard()[participant.getCurrentPosition()]->getName() << std::endl;
}
