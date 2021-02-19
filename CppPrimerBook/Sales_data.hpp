#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    unsigned total_units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
    double total_revenue = 0.0;
    Sales_data sum_sale_sameBookNo(Sales_data item1, Sales_data item2);
    void Print();
};

Sales_data Sales_data::sum_sale_sameBookNo(Sales_data item1, Sales_data item2) {
  Sales_data total;
  if (item1.bookNo == item1.bookNo){
    total.total_units_sold = item1.units_sold + item1.units_sold;
    total.total_revenue = item1.revenue + item1.revenue;
    return total;
  }
  else {
    cout << "BookNo should be the same\n";
    return total;
  }
}

void Sales_data::print_s() {
  cout << bookNo << " " << units_sold << " " << price << " " << revenue
        << " " << total_units_sold << " " << total_revenue << endl;
}


#endif // SALES_DATA_HPP
