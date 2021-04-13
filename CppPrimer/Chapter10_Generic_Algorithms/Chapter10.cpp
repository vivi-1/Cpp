#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main(){
//E10.1 The algorithm header defines a function named count that, like find,
//takes a pair of iterators and a value. count returns a count of how often that
//value appears. Read a sequence of ints into a vector and print the count of
//how many elements have a given value.
int input;
vector<int> vec;
while(cin >> input) vec.push_back(input);
int search_val = 0;
cout << search_val << " is present for " <<  count(vec.cbegin(), vec.cend(),search_val) << " times\n";

//E10.2 Repeat the previous program, but read values into a list of strings.


return 0;
}
