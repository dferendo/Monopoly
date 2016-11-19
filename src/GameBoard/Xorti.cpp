//
// Created by dylan on 16/11/2016.
//

#include "Xorti.h"

GameBoard::Xorti::Xorti(const string &name) : Tile(name) {}

void GameBoard::Xorti::action(Player::Participant * player, GameMechanics::Game * game) {
    int xorti = rand() % MAXIMUM_XORTI;
    if (xorti == 0) {
        birthday(*player);
    } else if (xorti == 1) {
        parkingFine(*player, game);
    } else if (xorti == 2) {
        mepaFine(*player, game);
    } else {
        moveToRandomPlace(*player, game);
    }
}

void GameBoard::Xorti::birthday(Player::Participant &player) {
    double birthdayMoney = rand() % (MAXIMUM_BIRTHDAY_PRICE - MINIMUM_BIRTHDAY_PRICE) + MINIMUM_BIRTHDAY_PRICE;
    std::cout << "It's your birthday!!! Take " << birthdayMoney << " as a gift." << std::endl;
    player.getMoney().addBalance(birthdayMoney);
}

void GameBoard::Xorti::parkingFine(Player::Participant &player, GameMechanics::Game * game) {
    double parkingFine = rand() % (MAXIMUM_PARKING_FINE - MINIMUM_PARKING_FINE) + MINIMUM_PARKING_FINE;
    std::cout << "You parked at a lecturer's spot!!! You were fined " << parkingFine << "." << std::endl;
    player.getMoney().subtractBalance(parkingFine);
    game->setFreeParkingJackpot(game->getFreeParkingJackpot() + parkingFine);
}

void GameBoard::Xorti::mepaFine(Player::Participant &player, GameMechanics::Game * game) {
    double mepaFine = rand() % (MAXIMUM_MEPA_FINE - MINIMUM_MEPA_FINE) + MINIMUM_MEPA_FINE;
    double totalFine = mepaFine * player.getParticipantProperties().size();
    std::cout << "MEPA fined you!!! You were fined in total" << totalFine << ". You have in total "
              << player.getParticipantProperties().size() << " buildings and each building was fined "
              << mepaFine << std::endl;
    player.getMoney().subtractBalance(totalFine);
    game->setFreeParkingJackpot(game->getFreeParkingJackpot() + totalFine);

}

void GameBoard::Xorti::moveToRandomPlace(Player::Participant &player, GameMechanics::Game * game) {
    player.setCurrentPosition(rand() % GameBoard::TOTAL_TILES);
    std::cout << "You were moved to a random location!!! New location is: "
              << game->getGameBoard()[player.getCurrentPosition()]->getName() << std::endl;
}
