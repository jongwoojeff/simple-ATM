//
//  ATM_Test.cpp
//  ATM
//
//  Created by Jongwoo Jeon on 03/26/21.
//  Copyright © 2021 Jongwoo Jeon. All rights reserved.
//
#define CATCH_CONFIG_MAIN
#include "ATM.h"
#include "catch.hpp"

Card c1("1111-1111-1111-1111", 1111, 0, 1, 0);
Card c2("2222-2222-2222-2222", 2222, 100, 150, 30);
Card c3("3333-3333-3333-3333", 3333, 999, 999, 999);
Card c4("4444-4444-4444-4444", 4444, 3, 5, 7000);
vector<Card> dataBase {c1, c2, c3, c4};

ATM machine(dataBase);

TEST_CASE("insert invalid card") {
    REQUIRE(machine.accessCard("9999-9999-9999-9999", 1234) == "No such card exists");
}

TEST_CASE("valid card but invalid pin") {
    REQUIRE(machine.accessCard("1111-1111-1111-1111", 2222) == "Invalid pin");
}

TEST_CASE("valid card and valid pin") {
    REQUIRE(machine.accessCard("1111-1111-1111-1111", 1111) == "Credentials verified. Accounts now accessible");
}

// testing functions for cards with valid credentials
TEST_CASE("get total balance c1") {
    machine.accessCard("1111-1111-1111-1111", 1111);
    REQUIRE(machine.totalBalance() == 1);
}

TEST_CASE("get total balance c2") {
    machine.accessCard("2222-2222-2222-2222", 2222);
    REQUIRE(machine.totalBalance() == 280);
}

TEST_CASE("deposit 100 to growth account c1") {
    machine.accessCard("1111-1111-1111-1111", 1111);
    machine.depositSpend(100);
    REQUIRE(machine.spendBalance() == 100);
}

TEST_CASE("deposit 100 to spend account c1") {
    machine.accessCard("1111-1111-1111-1111", 1111);
    machine.depositSpend(100);
    REQUIRE(machine.spendBalance() == 100);
}

TEST_CASE("withdraw 100 from spend account c4") {
    machine.accessCard("4444-4444-4444-4444", 4444);
    REQUIRE(machine.withdrawSpend(100) == "Not enough balance");
}


TEST_CASE("withdraw 999 from spend account c3") {
    machine.accessCard("3333-3333-3333-3333", 3333);
    REQUIRE(machine.withdrawSpend(999) == "Withdraw successful. Balance in spend: 0");
    REQUIRE(machine.spendBalance() == 0);
}

TEST_CASE("Illegal deposit to spend acccount c2") {
    machine.accessCard("2222-2222-2222-2222", 2222);
    REQUIRE(machine.depositSpend(-1) == "Deposit must be greater than zero");
}
