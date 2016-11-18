//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
}

void GameMechanics::Game::play() {
    Dice dice;
    int turn = 0;
    while (turn < 5) {
        for(auto const& participant : participantsPlaying) {
            cout << participant->getName() << " turns." << endl;
            // Roll dice to move
            std::pair<int, int> * diceRoll = dice.generateNewDiceRoll();
            int diceCount = diceRoll->first + diceRoll->second;
            cout << "Dices rolled " << diceCount << endl;
            // Move player, if player reaches end of board go in the beginning
            participant->moveCurrentPosition(diceCount % GameBoard::TOTAL_TILES);
            cout << participant->getName() << " moved to position "
                 << gameBoard[participant->getCurrentPosition()]->getName()
                 << endl;
            gameBoard[participant->getCurrentPosition()]->action(participant, this);
        }
        turn++;
    }
}
