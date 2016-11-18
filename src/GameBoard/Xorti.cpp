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
        parkingFine(*player);
    } else if (xorti == 2) {
        mepaFine(*player);
    } else {
        moveToRandomPlace(*player);
    }
}

void GameBoard::Xorti::birthday(Player::Participant &player) {
    double birthdayMoney = rand() % (MAXIMUM_BIRTHDAY_PRICE - MINIMUM_BIRTHDAY_PRICE) + MINIMUM_BIRTHDAY_PRICE;
    player.getMoney().addBalance(birthdayMoney);
}

void GameBoard::Xorti::parkingFine(Player::Participant &player) {
    double parkingFine = rand() % (MAXIMUM_PARKING_FINE - MINIMUM_PARKING_FINE) + MINIMUM_PARKING_FINE;
    player.getMoney().subtractBalance(parkingFine);
}

void GameBoard::Xorti::mepaFine(Player::Participant &player) {
    double mepaFine = rand() % (MAXIMUM_MEPA_FINE - MINIMUM_MEPA_FINE) + MINIMUM_MEPA_FINE;
    mepaFine *= player.getParticipantProperties().size();
    player.getMoney().subtractBalance(mepaFine);
}

void GameBoard::Xorti::moveToRandomPlace(Player::Participant &player) {
    player.setCurrentPosition(rand() % GameBoard::TOTAL_TILES);
}
