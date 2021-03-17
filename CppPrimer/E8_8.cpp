//E8.8: Revise the program from the previous exercise to append its output to
//its given file. Run the program on the same output file at least twice to
//ensure that the data are preserved.
// g++ was used as a compiler on OS Mac BigSur, the excutable file is default to be
//a.out, I'm using test.txt and output.txt as parameters that are passed to argv.

#include <iostream>
#include <fstream>
#include <cstring>
#include "Sales_data.hpp"
using namespace std;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv) {
  ofstream output(argv[1], ofstream::app);
  ifstream input (argv[2]);
  if (argc == 1 || argc == 2) {
    cerr << "Wrong input, has to have three parameters, including the excutable file and input and output files\n";
    return -1;
  }
  if(!input) {
    cerr << "can't read file " << string(argv[1]) << endl;
    return -2;
  }
  Sales_data total;
  if(input >> total) {
    Sales_data temp;
    while (input >> temp) {
      if (temp.isbn() == total.isbn()){
        total.sameaddTwo(temp);
      }
      else {
        print(output, total);
        total = temp;
      }
    }
    print(output, total);
  }
  else {
    cerr << "No data in the input file?!\n";
    return -3;
  }
  return 0;
}
