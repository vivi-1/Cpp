//This file was written by Wei Wang, github: https://github.com/vivi-1
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
    string isbn() const {return bookNo;};
    Sales_data sameaddTwo(Sales_data item1);
    void print_s();
};

// istream& operator>>(istream& in, Sales_data& s) {
//   in >> s.bookNo >> s.units_sold >> s.price;
//   if (in) s.revenue = s.units_sold * s.price;
//   else s = Sales_data();
//   return in;
// }

Sales_data Sales_data::sameaddTwo(Sales_data item1) {
  Sales_data total;
  if (item1.bookNo == bookNo){
    total.bookNo = bookNo;
    total.units_sold = item1.units_sold;
    total.price = item1.price;
    total.revenue = item1.revenue;
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
istream& read(istream& is, Sales_data& item) {
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.price * item.units_sold;
  item.total_units_sold = item.units_sold;
  item.total_revenue = item.revenue;
  item.avprice =  item.total_revenue / item.total_units_sold;
  return is;
}

Sales_data add(Sales_data item1, Sales_data item2) {
  Sales_data total = item2;
  if (item1.isbn() == item2.isbn()){
    total = item2.sameaddTwo(item1);
  }
  return total;
}

void Sales_data::print_s() {
  cout << bookNo << " " << units_sold << " " << price << " "  << avprice << " " << revenue;
  cout << " " << total_units_sold << " " << total_revenue << endl;
}

ostream &print(ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " "<< item.revenue << " "
      << item.avprice << " " << item.total_units_sold
        << " " << item.total_revenue << endl;
  return os;
}


#endif // SALES_DATA_HPP
