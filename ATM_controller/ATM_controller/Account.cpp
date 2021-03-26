//
//  Account.cpp
//  ATM_controller
//
//  Created by Jongwoo Jeon on 3/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//

#include "Account.hpp"

Account::Account() {
    balance = 0;
}
Account::Account(int amount) {
    balance = amount;
}

int Account::getBalance() {
    return balance;
}
std::string Account::deposit(int amount) {
    balance += amount;
    return "Deposit Successful";
}
std::string Account::withdraw(int amount) {
    balance -= amount;
    return "Withdraw Successful";
}
