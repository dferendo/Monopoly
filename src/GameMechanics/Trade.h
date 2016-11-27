//
// Created by dylan on 27/11/2016.
//

#ifndef MONOPOLY_TRADE_H
#define MONOPOLY_TRADE_H

#include "Game.h"
#include <set>

namespace GameMechanics {
    class Trade {
    public:
        void tradeProperty(Game *game);
        void transactionTrade(Player::Participant *buyer, Player::Participant *seller,
                              GameBoard::Property *propertyForSale);
        double offerCash(Player::Participant *buyer);
        GameBoard::Property * offerProperty(Player::Participant *buyer);
        bool makeTransaction(Player::Participant *buyer, Player::Participant *seller,
                             double cashOffered, set<GameBoard::Property *> propertiesOffered,
                             GameBoard::Property *propertyForSale);
        string buyerOffer(Player::Participant *buyer, double cashOffered,
                          set<GameBoard::Property *> propertiesOffered);
    };
}


#endif //MONOPOLY_TRADE_H
