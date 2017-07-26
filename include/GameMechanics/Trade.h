//
// Created by dylan on 27/11/2016.
//

#ifndef MONOPOLY_TRADE_H
#define MONOPOLY_TRADE_H

#include "Game.h"
#include <set>

namespace GameMechanics {

    class Trade {
    private:
        /**
         * Determine the other person that wants to trade. For every trade a buyer or seller is
         * known and thus that trader is removed from the list of the participants currently playing.
         * @param participants All the participants playing.
         * @param trader The player that is already known for trading.
         * @return The player that wants to trade.
         */
        Player::Participant *determineTrader(std::vector<Player::Participant *> participants,
                                             Player::Participant *trader);

        /**
         * Offering single/multiple property or cash to buy a property from the seller. The buyer can cancel
         * the transaction or ask the seller whether he likes the trade or not. If the seller likes the
         * trade, the cash and properties offered will be transferred. If the seller does not like the
         * trade, the buyer can add to the offer and offer it to the seller again.
         * @param buyer The person that wants to buy the property from the seller.
         * @param seller The person accepting property, cash or both for one of his property.
         * @param propertyForSale The property that the buyer wants to buy from the seller.
         */
        void transactionTrade(Player::Participant *buyer, Player::Participant *seller,
                              GameBoard::Property *propertyForSale);

        /**
         * Make a cash offer to buy the property. The buyer cannot offer more than he can afford.
         * @param buyer The participant that wants to buy a property.
         * @return The cash amount offered.
         */
        double offerCash(Player::Participant *buyer);

        /**
         * Offer property to the seller from the properties the buyer has. Returns the property
         * the buyer wants to offer. If buyer has no properties the exception is caught and handled
         * in which returns him to the previous screen where he can offer money instead.
         * @param buyer The participant that wants to buy a property.
         * @return The Property offered by the buyer.
         */
        GameBoard::Property * offerProperty(Player::Participant *buyer);

        /**
         * Asks the seller if he accepts the offer from the buyer for his property. If the seller does
         * not accepts, the buyer can re-offer a transaction. If the seller accepts the cash, properties
         * or both will be transferred to the seller. The property of the seller is transferred to the
         * new owner as well.
         * @param buyer The participant making the private transaction to the seller.
         * @param seller The participant accepting the private transaction.
         * @param cashOffered The cash offered by the buyer.
         * @param propertiesOffered The properties offered by the buyer.
         * @param propertyForSale The property of the seller.
         * @return True if the transaction was successful, false otherwise.
         */
        bool makeTransaction(Player::Participant *buyer, Player::Participant *seller,
                             double cashOffered, std::set<GameBoard::Property *> propertiesOffered,
                             GameBoard::Property *propertyForSale);

        /**
         * Returns a string with the information about what the buyer is offering.
         * @param buyer The participant that wants to buy the property.
         * @param cashOffered The amount of cash offered.
         * @param propertiesOffered All the properties offered by the buyer.
         * @return A string with the information about what the buyer is offering.
         */
        std::string buyerOffer(Player::Participant *buyer, double cashOffered,
                          std::set<GameBoard::Property *> &propertiesOffered);
    public:

        /**
         * Trade property or cash for a property another participant has. The buyer in this case is known.
         * The seller is chosen by the buyer and the buyer can trade with any current participant.
         * Mortgaged properties can also be traded and the new owner can remove the mortgage.
         * @param game The game needed to get all participants
         * @param buyer The buyer that wants to set up a trade
         */
        static void tradePropertyBuyerKnown(Game *game, Player::Participant *buyer);

        /**
         * Sell property for a property or cash another participant has. The seller is known in this case.
         * The seller is known in this case and the participants decides whether or not they want to trade
         * with the seller. Mortgaged properties can also be traded.
         * @param game The game needed to get all participants.
         * @param seller The seller that wants to sell a property to another participant.
         */
        static void tradePropertySellerKnown(Game *game, Player::Participant *seller);
    };
}


#endif //MONOPOLY_TRADE_H
