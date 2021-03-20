//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef DELEGATING_SALESDATA_HPP
#define DELEGATING_SALESDATA_HPP

#include <iostream>
using namespace std;
class Delegating_SalesData;
istream& read(istream& is, Delegating_SalesData& item);
class Delegating_SalesData {
public:
  friend istream& read(istream& is, Delegating_SalesData& item);
  Delegating_SalesData (const string &s, unsigned u, double r) : bookNo(s), units_sold(u), price(r), revenue(u*r){cout << "delegated constructor\n";}
  Delegating_SalesData () : Delegating_SalesData (" ", 0, 0.0) {cout << "delegating constructor(default version)\n";}
  Delegating_SalesData (const string &s) : Delegating_SalesData(s, 0, 0.0) {cout << "delegating constructor(string version)\n";}
  Delegating_SalesData(istream &is) : Delegating_SalesData() {
    read(is, *this);
    cout << "delegating constructor(istream version)\n";
  }

private:
  string bookNo;
  unsigned units_sold;
  double price;
  double revenue;
};

istream& read(istream& is, Delegating_SalesData& item) {
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.price * item.units_sold;
  return is;
}

#endif // DELEGATING_SALESDATA_HPP
