//
// Created by dylan on 16/11/2016.
//

#include "../../include/GameBoard/Tax.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/GameMechanics/Bankruptcy.h"
using namespace Exception;
using namespace std;

GameBoard::Tax::Tax(const string &name, const int &taxAmount) : Tile(name), taxAmount(taxAmount) {}

void GameBoard::Tax::action(Player::Participant *participant, GameMechanics::Game * game) {
    try {
        participant->getMoney().subtractBalance(taxAmount);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + taxAmount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // If participant cannot pay debt, he will be declared bankrupt
        // Owner is nullptr in this case since the participant owns money to the bank
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, participant, nullptr);
        // If participant cannot pay the debt, declare bankruptcy
        if (!isPlayerNotBankrupt) {
            GameMechanics::Bankruptcy::transferProperties(game, participant, nullptr);
        }
    }
}
