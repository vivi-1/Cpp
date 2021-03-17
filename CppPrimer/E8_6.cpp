//E8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its
//transactions from a file. Pass the name of the file as an argument to
//main (§ 6.2.5, p. 218).
//
// g++ was used as a compiler on OS Mac BigSur, the excutable file is default to be
//a.out, I'm using test.txt as parameter that is passed to argv.

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;
#include "Sales_data.hpp"

int main(int argc, char **argv) {
  if (argc == 1) {
    cerr << "Arguments should be more than one\n";
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
    print(cout, total);
    print(cout, temp);
    while (input >> temp){
      print(cout, temp);
      if (total.isbn() == temp.isbn()){
        cout << total.isbn() << endl;
        total = total.sameaddTwo(temp);
        cout << "sameadd\n";
      }
      else {
        cout << "different print: ";
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
