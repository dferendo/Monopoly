//
// Created by dylan on 27/11/2016.
//

#ifndef MONOPOLY_TRADE_H
#define MONOPOLY_TRADE_H

#include "Game.h"
#include <set>
#include <algorithm>
using namespace Player;

namespace GameMechanics {
    class Trade {
    private:
        Participant *determineSeller(vector<Participant *> participants, Participant *buyer);
        void transactionTrade(Participant *buyer, Participant *seller,
                              GameBoard::Property *propertyForSale);
        double offerCash(Participant *buyer);
        GameBoard::Property * offerProperty(Participant *buyer);
        bool makeTransaction(Participant *buyer, Participant *seller,
                             double cashOffered, set<GameBoard::Property *> propertiesOffered,
                             GameBoard::Property *propertyForSale);
        string buyerOffer(Participant *buyer, double cashOffered,
                          set<GameBoard::Property *> propertiesOffered);
    public:
        static void tradeProperty(Game *game, Participant * buyer);
    };
}


#endif //MONOPOLY_TRADE_H
