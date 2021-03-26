//
//  Card.cpp
//  ATM_controller
//
//  Created by Jongwoo Jeon on 3/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//

#include "Card.hpp"
Card::Card(std::string cardNum, int pinNum, int spendAmount, int reserveAmount, int growthAmount) {
    cardNumber = cardNum;
    pin = pinNum;
    spend = Account(spendAmount);
    reserve = Account(reserveAmount);
    growth = Account(growthAmount);
}
std::string Card::getCardNumber() {
    return cardNumber;
}

int Card::getPin() {
    return pin;
}
