#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    unsigned total_units_sold = 0;
    double revenue = 0.0;
    double total_revenue = 0.0;
};
#endif

void sum_sale(Sales_data item1, Sales_data item2) {
  
}
