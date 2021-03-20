//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef CHAPTER7_ACCOUNT_HPP
#define CHAPTER7_ACCOUNT_HPP

#include <iostream>
using namespace std;
class Account {
public:
  void caculate() {amount += amount *interestRate;}
  static double rate() {return interestRate;}
  static void rate(double);
private:
  string owner;
  double amount;
  static double interestRate;
  static double initRate;
  static constexpr int period = 30;
  double daily_tbl[period];
};

void Account::rate(double newRate) {interestRate = newRate;}
double Account::interestRate = initRate;
constexpr int Account::period;

#endif //CHAPTER7_ACCOUNT_HPP
