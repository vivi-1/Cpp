#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<sstream>
#include<numeric>
using namespace std;

int main(){
//E10.1 The algorithm header defines a function named count that, like find,
//takes a pair of iterators and a value. count returns a count of how often that
//value appears. Read a sequence of ints into a vector and print the count of
//how many elements have a given value.
//E10.2 Repeat the previous program, but read values into a list of strings.
int input;
vector<int> vec;
list<string> list;
while(cin >> input) {
  stringstream ss;
  ss << input;
  string sinput;
  ss >> sinput;
  vec.push_back(input);
  list.push_back(sinput);
}
int search_val = 0;
cout << search_val << " is present for " <<  count(vec.cbegin(), vec.cend(),search_val) << " times\n";
cout << search_val << " is present for " << count(list.begin(), list.end(), to_string(search_val)) << " times\n";

//E10.3 Use accumulate to sum the elements in a vector<int>.
vector<int> v = {1,3,5,2,4,6};
int sum = accumulate(v.cbegin(), v.cend(), 0);
cout << sum << endl;

//E10.4 Assuming v is a vector<double>, what, if anything, is wrong with calling
//accumulate(v.cbegin(), v.cend(), 0)?
// The final result from accumulation will be added to integer 0 which is a truncated version of final result

//E10.5 In the call to equal on rosters, what would happen if both rosters held
//C-style strings, rather than library strings?
//"==" on c-type strings only compare pointers not the contents. So its comparing if two
//pointers to the C-strs are the same.



return 0;
}
