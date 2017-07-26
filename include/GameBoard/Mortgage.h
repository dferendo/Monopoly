//
// Created by dylan on 28/11/2016.
//

#ifndef MONOPOLY_MORTGAGES_H
#define MONOPOLY_MORTGAGES_H


namespace Player {
    class Participant;
}

namespace GameBoard {

    class Mortgage {
    private:
        bool propertyMortgage = false;
        double mortgagePrice;
        // Interest is currently 110%
        const double INTEREST_PERCENTAGE = 1.1;
    public:
        Mortgage(double mortgagePrice);
        bool isPropertyMortgage() const;
        double getMortgagePrice() const;

        /**
         * Make property mortgaged and add funds to participant. Throws exception if mortgaged is
         * already mortgaged.
         * @param participant The participant that wants his property to be mortgaged.
         */
        void makePropertyMortgage(Player::Participant* participant);

        /**
         * Remove mortgaged from property and subtract funds from participant. Throws exception
         * if the property is not mortgaged. If the participant does not have enough money, the
         * NoMoneyException is caught and the user returns to the previous screen.
         * @param participant The participant that wants his property to remove mortgage.
         */
        void removeMortgage(Player::Participant* participant);
    };
}


#endif //MONOPOLY_MORTGAGES_H
