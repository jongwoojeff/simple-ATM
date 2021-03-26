//
//  Account.hpp
//  ATM_controller
//
//  Created by Jongwoo Jeon on 3/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>
class Account{
public:
    Account();
    Account(int amount);
    int getBalance();
    int balance;
    std::string deposit(int toAdd);
    std::string withdraw(int toRemove);
};

#endif /* Account_hpp */
