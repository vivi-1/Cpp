#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<sstream>
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



return 0;
}
