//
// Created by dylan on 28/11/2016.
//

#ifndef MONOPOLY_MORTGAGES_H
#define MONOPOLY_MORTGAGES_H

namespace GameBoard {
    const double INTEREST_PERCENTAGE = 10;

    class Mortgage {
    private:
        bool propertyMortgage = false;
        double mortgagePrice;
    public:
        Mortgage(double mortgagePrice);
        bool isPropertyMortgage() const;
        int getMortgagePrice() const;
        void setPropertyMortgage(bool propertyMortgage);
    };
}


#endif //MONOPOLY_MORTGAGES_H
