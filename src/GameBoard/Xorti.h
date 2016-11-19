//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_XORTI_H
#define MONOPOLY_XORTI_H

#include "Tile.h"
#include "../Player/Participant.h"
#include "../GameMechanics/Game.h"

namespace GameBoard {
    const int MAXIMUM_XORTI = 4;
    const int MAXIMUM_BIRTHDAY_PRICE = 10;
    const int MINIMUM_BIRTHDAY_PRICE = 100;
    const int MAXIMUM_PARKING_FINE = 50;
    const int MINIMUM_PARKING_FINE = 150;
    const int MAXIMUM_MEPA_FINE = 40;
    const int MINIMUM_MEPA_FINE = 180;

    class Xorti: public Tile {
    public:
        Xorti(const string &name);
        void action(Player::Participant *player, GameMechanics::Game * game) override;
        void birthday(Player::Participant &player);
        void parkingFine(Player::Participant &player, GameMechanics::Game * game);
        void mepaFine(Player::Participant &player, GameMechanics::Game * game);
        void moveToRandomPlace(Player::Participant &player);
    };
}
#endif //MONOPOLY_XORTI_H
