//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
#include <sstream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using namespace std;
struct Sales_data;
istream& operator>>(istream& in, Sales_data& s);
ostream& operator<<(ostream& out, Sales_data& s);
istream& read(istream& is, Sales_data& item);//read should be declared before use
ifstream& read(ifstream& is, Sales_data& item);
ostream& print(ostream &os, const Sales_data &item);


struct Sales_data {
  friend istream& operator>>(istream& in, Sales_data& s);
  friend ostream& operator<<(ostream& out, Sales_data& s);
  friend istream& read(istream& is, Sales_data& item);
  friend ifstream& read(ifstream& is, Sales_data& item);
  friend ostream& print(ostream &os, const Sales_data &item);

    Sales_data () = default;
    Sales_data (const string &s) : bookNo(s){}
    Sales_data (const string &s, unsigned u, double r) : bookNo(s), units_sold(u), price(r), revenue(u*r) {}
    //Sales_data () : bookNo(" "), units_sold(0), price(0.0), revenue(0.0){}//E7.14
    Sales_data(istream &is) {read(is, *this);}

  private:
    string bookNo;
    unsigned units_sold;
    double price;
    double avprice;
    double revenue;
  public:
    string isbn() const {return bookNo;};
    Sales_data sameaddTwo(Sales_data item1);
    void print_s();
    double av_price() {return avprice;};
};


istream& operator>>(istream& in, Sales_data& s) {
  in >> s.bookNo >> s.units_sold >> s.price;
  if (in) s.revenue = s.units_sold * s.price;
  else s = Sales_data();
  return in;
}

ostream& operator<<(ostream& out, Sales_data& s) {
  if (out) s.revenue = s.units_sold * s.price;
  else s = Sales_data();
  out << s.bookNo << " " << s.units_sold << " " << s.price << " " << s.revenue << " "  << s.avprice << " ";
  return out;
}

Sales_data Sales_data::sameaddTwo(Sales_data item1) {
  if (item1.bookNo == bookNo){
    units_sold += item1.units_sold;
    price = item1.price;
    revenue += item1.revenue;
    avprice = revenue / units_sold;
  }
  else {
    cout << "BookNo should be the same\n";
  }
  return *this;
}

istream& read(istream& is, Sales_data& item) {
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.price * item.units_sold;
  item.avprice =  item.revenue / item.units_sold;
  return is;
}

ifstream& read(ifstream& is, Sales_data& item) {
  is >> item.bookNo >> item.units_sold >> item.price;
  item.revenue = item.price * item.units_sold;
  item.avprice =  item.revenue / item.units_sold;
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
}

ostream &print(ostream &os, const Sales_data &item) {
  os << "format: " << "ISBN, total units_sold, total revenue, average price\n"
      << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avprice
        << '\n';
  return os;
}


#endif // SALES_DATA_HPP
