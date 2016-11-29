//
// Created by dylan on 16/11/2016.
//

#include "Tax.h"
#include "../Exception/NoMoneyException.h"

GameBoard::Tax::Tax(const string &name, const int &taxAmount) : Tile(name), taxAmount(taxAmount) {}

void GameBoard::Tax::action(Player::Participant *player, GameMechanics::Game * game) {
    try {
        player->getMoney().subtractBalance(taxAmount);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + taxAmount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // TODO solve this
    }
}
