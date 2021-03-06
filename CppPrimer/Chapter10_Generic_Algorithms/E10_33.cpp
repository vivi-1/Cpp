//E10.33 Write a program that takes the names of an input file and two output
//files. The input file should hold integers. Using an istream_iterator read the
// input file. Using ostream_iterators, write the odd numbers into the first
//output file. Each value should be followed by a space. Write the even numbers
//into the second file. Each of these values should be placed on a separate line.
//g++ as compiler

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
using std::ifstream;
using std::ofstream;
int main(int argc, char* argv[]){
  ifstream input (argv[1]);
  ofstream output_odd(argv[2], ofstream::app);
  ofstream output_even(argv[3], ofstream::app);
  if(argc!=4) {
    cerr << "Wrong input, has to have four parameters, including the excutable file and input and output files\n";
    return -1;
  }
  if(!input) {
    cerr << "can't read file " << string(argv[1]) << endl;
    return -2;
  }

  else{
    istream_iterator<int> iter_in(input), eof;
    ostream_iterator<int> iter_odd(output_odd);
    ostream_iterator<int> iter_even(output_even);
    while(iter_in!=eof) (*iter_in%2) ? iter_odd =  *iter_in++ : iter_even = *iter_in++;
  }

return 0;
}
