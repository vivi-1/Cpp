#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<sstream>
#include<numeric>
using namespace std;
#include"Sales_data.hpp"

//E10.9 Implement your own version of elimDups. Test your program by printing
//the vector after you read the input, after the call to unique, and after the
//call to erase.
void elimDups(vector<string> &words) {
  sort(words.begin(), words.end());
  auto iter = unique(words.begin(), words.end());
  words.erase(iter, words.end());
}

//E10.11 Write a program that uses stable_sort and isShorter to sort a vector
//passed to your version of elimDups. Print the vector to verify that your
//program is correct.
bool isShorter(const string& s1, const string& s2){
  return s1.size() < s2.size();
}

//E10.12 Write a function named compareIsbn that compares the isbn() members of
//two Sales_data objects. Use that function to sort a vector that holds
//Sales_data objects.
bool compareIsbn(const Sales_data& s1, const Sales_data& s2) {
  return s1.isbn().size() < s2.isbn().size();
}

//E10.13 The library defines an algorithm named partition that takes a predicate
// and partitions the container so that values for which the predicate is true
//appear in the first part and those for which the predicate is false appear in
//the second part. The algorithm returns an iterator just past the last element
//for which the predicate returned true. Write a function that takes a string
//and returns a bool indicating whether the string has five characters or more.
// Use that function to partition words. Print the elements that have five or
//more characters.
bool isBiggerThanFive(const string& s) {
  return s.size() >= 5;
}

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

//E10.9 Implement your own version of elimDups. Test your program by printing
//the vector after you read the input, after the call to unique, and after the
//call to erase.
vector<string> vec1 = {"Kevin", "Yu", "Wei", "Wang", "Kevin", "Wei", "Kev", "NorthCarolina"};
elimDups(vec1);
for (const auto& i : vec1) cout << i << " ";
cout << endl;

//E10.10 Why do you think the algorithms don’t change the size of containers?
//library algorithm operate on the iterators instead of the containers, they can't
//directly add or remove elements;

//E10.11 Write a program that uses stable_sort and isShorter to sort a vector
//passed to your version of elimDups. Print the vector to verify that your
//program is correct.
stable_sort(vec1.begin(), vec1.end(), isShorter);
for (const auto& i : vec1) cout << i << " ";
cout << endl;

//E10.12 Write a function named compareIsbn that compares the isbn() members of
// two Sales_data objects. Use that function to sort a vector that holds
//Sales_data objects.
Sales_data sd1("a12345"), sd2("ab12347"), sd3("abc17892"), sd4("a"), sd5("c12345");
vector<Sales_data> vec2{sd1, sd2, sd3, sd4, sd5};
stable_sort(vec2.begin(), vec2.end(), compareIsbn);
for (const auto& i : vec2) print(cout,i);
cout << endl;

//E10.13 The library defines an algorithm named partition that takes a predicate
// and partitions the container so that values for which the predicate is true
//appear in the first part and those for which the predicate is false appear in
//the second part. The algorithm returns an iterator just past the last element
//for which the predicate returned true. Write a function that takes a string
//and returns a bool indicating whether the string has five characters or more.
// Use that function to partition words. Print the elements that have five or
//more characters.
vector<string> vec3 = {"Kevin", "Yu", "Wei", "Wang", "Kevin", "Wei", "Kev", "NorthCarolina"};
auto iter = partition(vec3.begin(), vec3.end(), isBiggerThanFive);
for(auto i = vec3.begin(); i!=iter; ++i) cout << *i << " ";
cout <<  endl;
for (auto i = iter; i!=vec3.end(); ++i) cout << *i << " ";
cout <<  endl;

return 0;
}
