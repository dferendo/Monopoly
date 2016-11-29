//
// Created by dylan on 28/11/2016.
//

#ifndef MONOPOLY_MORTGAGES_H
#define MONOPOLY_MORTGAGES_H


namespace Player {
    class Participant;
}

namespace GameBoard {
    const double INTEREST_PERCENTAGE = 1.1;

    class Mortgage {
    private:
        bool propertyMortgage = false;
        double mortgagePrice;
    public:
        Mortgage(double mortgagePrice);
        bool isPropertyMortgage() const;
        double getMortgagePrice() const;
        void makePropertyMortgage(Player::Participant* participant);
        void removeMortgage(Player::Participant* participant);
    };
}


#endif //MONOPOLY_MORTGAGES_H
