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

//E10.6 Using fill_n, write a program to set a sequence of int values to 0.
fill_n(vec.begin(), vec.size(), 0);
for (auto i : vec) cout << i << " ";
cout << endl;

//E10.7 Determine if there are any errors in the following programs and, if so,
//correct the error(s):
// (a)
// vector<int> vec;
// list<int> lst;
// int i;
// while (cin >> i) lst.push_back(i);
// copy(lst.cbegin(), lst.cend(), vec.begin());
// vec should be at least as many elements as lst
//Correction(1):
// list<int> lst;
// int i;
// while (cin >> i) lst.push_back(i);
// vector<int> vec(lst.size());
// copy(lst.cbegin(), lst.cend(), vec.begin());
//Correction(2): copy(lst.cbegin(), lst.cend(), back_inserter(vec));

// (b)
// vector<int> vec;
//  vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
//  fill_n(vec.begin(), 10, 0);
//reserve only make room for 10 int elements for vec but didn't change the number of elements
//Correction:
// vector<int> vec(10);
// fill_n(vec.begin(), 10, 0);

//E10.8 We said that algorithms do not change the size of the containers over
//which they operate. Why doesn’t the use of back_inserter invalidate this claim?
//This function is defined in iterator header instead of algorithm header.
//The function was achieved by calling push_back function which is the container's operation.

return 0;
}
