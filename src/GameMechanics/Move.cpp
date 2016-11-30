//
// Created by dylan on 28/11/2016.
//

#include "Move.h"

void GameMechanics::Move::move(Game * game, Participant * participant, Dice *dice) {
    Move move;
    bool anotherTurnForPlayer = true;
    unsigned long totalParticipants = game->getParticipantsPlaying().size();
    int counter = 0;
    while (anotherTurnForPlayer) {
        // Roll dice to move
        game->setDiceCount(move.generateDiceCount(dice));
        anotherTurnForPlayer = move.checkDiceDouble(dice);
        // If player did 2 turns and roll doubles again, move to the jail empty tail
        if (counter == 2 && anotherTurnForPlayer) {
            cout << "Doubles for the third consecutive time!! Moving to jail." << endl;
            participant->setCurrentPosition(JAIL_TILE);
            Util::pressEnterToContinue();
            break;
        }
        move.determineParticipantLocation(game, participant, game->getDiceCount());
        game->getGameBoard()[participant->getCurrentPosition()]->action(participant, game);
        // If a player went bankrupt, he cannot have another turn thus stop moving.
        if (totalParticipants != game->getParticipantsPlaying().size()) {
            return;
        }
        counter++;
        Util::pressEnterToContinue();
    }
}

void GameMechanics::Move::determineParticipantLocation(Game * game, Participant *participant, int diceCount) {
    // Move player, if player reaches end of board go in the beginning of the board
    int newLocation = participant->getCurrentPosition() + diceCount;
    validateGoFunds(participant, newLocation);
    newLocation %= TOTAL_TILES;
    participant->setCurrentPosition(newLocation);
    cout << participant->getName() << " moved to position "
         << game->getGameBoard()[newLocation]->getName()
         << endl;
}

void GameMechanics::Move::validateGoFunds(Participant *participant, int location) {
    if (location >= TOTAL_TILES) {
        cout << "Adding Go Funds!!" << endl;
        participant->getMoney().addBalance(GO_AMOUNT);
        Util::pressEnterToContinue();
    }
}

bool GameMechanics::Move::checkDiceDouble(GameMechanics::Dice *dice) {
    pair<int, int> * diceRoll = dice->getCurrentDiceRoll();
    if (diceRoll->first == diceRoll->second) {
        cout << "Doubles!! Player gets another dice roll after doing a tile action unless it"
                " is the third consecutive time!" << endl;
        return true;
    }
    return false;
}

int GameMechanics::Move::generateDiceCount(GameMechanics::Dice *dice) {
    pair<int,int> * diceRoll = dice->generateNewDiceRoll();
    cout << "Dices rolled: " << diceRoll->first << ", " << diceRoll->second << endl;
    return diceRoll->first + diceRoll->second;
}