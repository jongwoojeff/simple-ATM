//
//  ATM.h
//  ATM
//
//  Created by Jongwoo Jeon on 03/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//

#ifndef ATM_h
#define ATM_h
#include <string>

#include "Card.hpp"
#include <vector>
using namespace std;
class ATM{
public:
    ATM(vector<Card> c);
    vector<Card> data;
    Card currentCard;
    std::string accessCard(string cardNumber, int pin);
    int totalBalance();
    int spendBalance();
    int reserveBalance();
    int growthBalance();
    std::string depositSpend(int amount);
    std::string depositReserve(int amount);
    std::string depositGrowth(int amount);
    std::string withdrawSpend(int amount);
    std::string withdrawReserve(int amount);
    std::string withdrawGrowth(int amount);
};

#endif /* ATM_h */
