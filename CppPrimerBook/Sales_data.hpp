#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    unsigned total_units_sold = 0;
    double price = 0.0;
    double avprice = 0.0;
    double revenue = 0.0;
    double total_revenue = 0.0;
    Sales_data sameaddTwo(Sales_data item1);
    void print_s();
};

istream& operator>>(std::istream& in, Sales_data& s) {
  in >> s.bookNo >> s.units_sold >> s.price;
  if (in) s.revenue = s.units_sold * s.price;
  else s = Sales_data();
  return in;
}

Sales_data Sales_data::sameaddTwo(Sales_data item1) {
  Sales_data total;
  if (item1.bookNo == bookNo){
    total.bookNo = bookNo;
    total.total_units_sold = item1.units_sold + units_sold;
    total.total_revenue = item1.revenue + revenue;
    total.avprice = total.total_revenue / total.total_units_sold;
    return total;
  }
  else {
    cout << "BookNo should be the same\n";
    return total;
  }
}

void Sales_data::print_s() {
  cout << bookNo << " " << units_sold << " " << price << " "  << avprice << " " << revenue;
  cout << " " << total_units_sold << " " << total_revenue << endl;
}


#endif // SALES_DATA_HPP
