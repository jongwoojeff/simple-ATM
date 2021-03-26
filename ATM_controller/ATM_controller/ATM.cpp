//
//  ATM.cpp
//  ATM
//
//  Created by Jongwoo Jeon on 03/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//

#include <iostream>
#include "ATM.h"

ATM::ATM(vector<Card> input) {
    data = input;
}

std::string ATM::accessCard(string cardToCheck, int pin) {
    for (auto card : data) {
        if (card.getCardNumber() == cardToCheck) {
            if (card.getPin() == pin) {
                currentCard = Card(cardToCheck, pin, card.spend.getBalance(), card.reserve.getBalance(), card.growth.getBalance());
                return "Credentials verified. Accounts now accessible";
            } else {
                return "Invalid pin";
            }
        }
    }
    return "No such card exists";
}

int ATM::totalBalance() {
    return currentCard.spend.getBalance() + currentCard.reserve.getBalance() + currentCard.growth.getBalance();
}

int ATM::spendBalance() {
    return currentCard.spend.getBalance();
}

int ATM::reserveBalance() {
    return currentCard.reserve.getBalance();
}

int ATM::growthBalance() {
    return currentCard.growth.getBalance();
}

std::string ATM::depositSpend(int amount) {
    if (amount <= 0) {
        return "Deposit must be greater than zero";
    }
    currentCard.spend.deposit(amount);
    return "Deposit successful. Balance in spend: " + to_string(currentCard.spend.getBalance());
}

std::string ATM::depositReserve(int amount) {
    if (amount <= 0) {
        return "Deposit must be greater than zero";
    }
    currentCard.reserve.deposit(amount);
    return "Deposit successful. Balance in reserve: " + to_string(currentCard.reserve.getBalance());
}

std::string ATM::depositGrowth(int amount) {
    if (amount <= 0) {
        return "Deposit must be greater than zero";
    }
    currentCard.growth.deposit(amount);
    return "Deposit successful. Balance in growth: " + to_string(currentCard.growth.getBalance());
}

std::string ATM::withdrawSpend(int amount) {
    if (amount <= 0) {
        return "Amount must be greater than zero";
    }
    if (currentCard.spend.getBalance() < amount) {
        return "Not enough balance";
    }
    currentCard.spend.withdraw(amount);
    return "Withdraw successful. Balance in spend: " + to_string(currentCard.spend.getBalance());
}

std::string ATM::withdrawReserve(int amount) {
    if (amount <= 0) {
        return "Amount must be greater than zero";
    }
    if (currentCard.reserve.getBalance() < amount) {
        return "Not enough balance";
    }
    currentCard.reserve.withdraw(amount);
     return "Withdraw successful. Balance in reserve: " + to_string(currentCard.reserve.getBalance());
}

std::string ATM::withdrawGrowth(int amount) {
    if (amount <= 0) {
        return "Amount must be greater than zero";
    }
    if (currentCard.growth.getBalance() < amount) {
        return "Not enough balance";
    }
    currentCard.growth.withdraw(amount);
     return "Withdraw successful. Balance in growth: " + to_string(currentCard.growth.getBalance());
}

