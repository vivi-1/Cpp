#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    unsigned total_units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
    double total_revenue = 0.0;
};
#endif

Sales_data sum_sale_sameBookNo(Sales_data item1, Sales_data item2) {
  Sales_data total;
  if (item1.bookNo == item1.bookNo){
    total.total_units_sold = item1.units_sold + item1.units_sold;
    total.total_revenue = item1.revenue + item1.revenue;
    return total;
  }
  else {
    cout << "BookNo should be the same\n";
    return -1;
  }
}
