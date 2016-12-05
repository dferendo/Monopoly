//
// Created by dylan on 16/11/2016.
//

#include "Xorti.h"
#include "../Exception/NoMoneyException.h"
#include "../GameMechanics/Bankruptcy.h"
using namespace Exception;

GameBoard::Xorti::Xorti(const string &name) : Tile(name) {}

void GameBoard::Xorti::action(Player::Participant * player, GameMechanics::Game * game) {
    int xorti = rand() % MAXIMUM_XORTI;
    try {
        if (xorti == 0) {
            birthday(*player);
        } else if (xorti == 1) {
            parkingFine(*player, game);
        } else if (xorti == 2) {
            mepaFine(*player, game);
        } else {
            moveToRandomPlace(*player, game);
        }
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // If player cannot pay debt, he will be declared bankrupt
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, player, nullptr);
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, player, nullptr);
        }
    }
}

void GameBoard::Xorti::birthday(Player::Participant &player) {
    // TODO collect from every one
    double birthdayMoney = rand() % (MAXIMUM_BIRTHDAY_PRICE - MINIMUM_BIRTHDAY_PRICE) + MINIMUM_BIRTHDAY_PRICE;
    std::cout << "It's your birthday!!! Take " << birthdayMoney << " as a gift." << std::endl;
    player.getMoney().addBalance(birthdayMoney);
}

void GameBoard::Xorti::parkingFine(Player::Participant &player, GameMechanics::Game * game) {
    double parkingFine = rand() % (MAXIMUM_PARKING_FINE - MINIMUM_PARKING_FINE) + MINIMUM_PARKING_FINE;
    std::cout << "You parked at a lecturer's spot!!! You were fined " << parkingFine << "." << std::endl;
    try {
        player.getMoney().subtractBalance(parkingFine);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + parkingFine);
    } catch (NoMoneyException & noMoneyException) {
        throw NoMoneyException(noMoneyException.amountDue);
    }
}

void GameBoard::Xorti::mepaFine(Player::Participant &player, GameMechanics::Game * game) {
    double mepaFine = rand() % (MAXIMUM_MEPA_FINE - MINIMUM_MEPA_FINE) + MINIMUM_MEPA_FINE;
    double totalFine = mepaFine * player.getParticipantProperties().size();
    std::cout << "MEPA fined you!!! You were fined in total: " << totalFine << ". You have in total "
              << player.getParticipantProperties().size() << " buildings and each building was fined "
              << mepaFine << "." << std::endl;
    try {
        player.getMoney().subtractBalance(totalFine);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + totalFine);
    } catch (NoMoneyException & noMoneyException) {
        throw NoMoneyException(noMoneyException.amountDue);
    }
}

void GameBoard::Xorti::moveToRandomPlace(Player::Participant &player, GameMechanics::Game * game) {
    player.setCurrentPosition(rand() % GameMechanics::TOTAL_TILES);
    std::cout << "You were moved to a random location!!! New location is: "
              << game->getGameBoard()[player.getCurrentPosition()]->getName() << std::endl;
}
