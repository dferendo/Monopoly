//
// Created by dylan on 16/11/2016.
//

#include "Tax.h"
#include "../Exception/NoMoneyException.h"
#include "../GameMechanics/Bankruptcy.h"

GameBoard::Tax::Tax(const string &name, const int &taxAmount) : Tile(name), taxAmount(taxAmount) {}

void GameBoard::Tax::action(Player::Participant *player, GameMechanics::Game * game) {
    try {
        player->getMoney().subtractBalance(taxAmount);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + taxAmount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // If player cannot pay debt, he will be declared bankrupt
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, player, nullptr);
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, player, nullptr);
        }
    }
}
