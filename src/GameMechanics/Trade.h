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
        Participant *determineTrader(vector<Participant *> participants, Participant *buyer);
        void transactionTrade(Participant *buyer, Participant *seller,
                              GameBoard::Property *propertyForSale);
        double offerCash(Participant *buyer);
        GameBoard::Property * offerProperty(Participant *buyer);
        bool makeTransaction(Participant *buyer, Participant *seller,
                             double cashOffered, set<GameBoard::Property *> propertiesOffered,
                             GameBoard::Property *propertyForSale);
        string buyerOffer(Participant *buyer, double cashOffered,
                          set<GameBoard::Property *> &propertiesOffered);
    public:
        static void tradePropertyBuyerKnown(Game *game, Participant *buyer);
        static void tradePropertySellerKnown(Game *game, Participant *seller);
    };
}


#endif //MONOPOLY_TRADE_H
