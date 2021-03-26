//
//  Card.hpp
//  ATM_controller
//
//  Created by Jongwoo Jeon on 3/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include "Account.hpp"
class Card{
public:
    Card() {};
    Card(std::string cardNum, int pinNum, int spendBlance, int reserveBlance, int growthBalance);
    Account spend;
    Account reserve;
    Account growth;
    std::string cardNumber;
    int pin;
    int getPin();
    std::string getCardNumber();
};

#endif /* Card_hpp */
