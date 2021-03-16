//E8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its
//transactions from a file. Pass the name of the file as an argument to
//main (§ 6.2.5, p. 218).
#include <iostream>
#include <fstream>
using namespace std;
#include "Sales_data.hpp"

int main(int argc, char **argv) {
  if ((argc - 1)!=1) {
    cerr << "Wrong usage\n";
    return -1;
  }
  ifstream input(argv[1]);
  if(!input) {
    cerr << "can't open file " << string(argv[1]) << endl;
    return -2;
  }
  Sales_data total;
  if(input >> total){
    Sales_data temp;
    while (input >> temp){
      if (total.isbn() == temp.isbn()){
        total.sameaddTwo(temp);
      }
      else {
        print(cout, total);
        total = temp;
      }
    }
  }
  else {
    cerr << "No data inpput?!\n";
    return -3;
  }
  return 0;
}
