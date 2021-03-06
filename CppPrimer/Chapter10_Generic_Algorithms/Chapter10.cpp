#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<sstream>
#include<numeric>
#include<iterator>
using namespace std;
using namespace placeholders;
#include"Sales_data.hpp"
#include"Sales_item.h"

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

//E10.16 Write your own version of the biggies function using lambdas.
string make_plural(size_t ctr, const string & word, const string& ending){
  return(ctr>1) ? word+ending : word;
}

void biggies(vector<string>& words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const string&s1, const string&s2){return s1.size()<s2.size();});
  auto wc = find_if(words.begin(), words.end(), [sz](const string& s){return s.size()>sz;});
  auto count = words.end()-wc;
  cout << count << " " << make_plural(count, "word", "s") << " of length" << sz << " or longer\n";
  for_each(wc, words.end(), [](const string&s){cout << s << " ";});
  cout << endl;
}

//E10.18 Rewrite biggies to use partition instead of find_if. We described the
//partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).
void biggies_partition(vector<string>& words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const string&s1, const string&s2){return s1.size()<s2.size();});
  auto iter = partition(words.begin(), words.end(), [sz](const string& s){return s.size()>sz;});
  auto count = words.end()-iter;
  cout << count << " " << make_plural(count, "word", "s") << " of length" << sz << " or longer\n";
  for_each(iter, words.end(), [](const string&s){cout << s << " ";});
  cout << endl;
}

//E10.19 Rewrite the previous exercise to use stable_partition, which like
//stable_sort maintains the original element order in the paritioned sequence.
void biggies_stable_partition(vector<string>& words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const string&s1, const string&s2){return s1.size()<s2.size();});
  auto iter = stable_partition(words.begin(), words.end(), [sz](const string& s){return s.size()>sz;});
  auto count = words.end()-iter;
  cout << count << " " << make_plural(count, "word", "s") << " of length" << sz << " or longer\n";
  for_each(iter, words.end(), [](const string&s){cout << s << " ";});
  cout << endl;
}

//E10.20 The library defines an algorithm named count_if. Like find_if, this
//function takes a pair of iterators denoting an input range and a predicate
//that it applies to each element in the given range. count_if returns a count
//of how often the predicate is true. Use count_if to rewrite the portion of our
// program that counted how many words are greater than length 6.
void biggies_countif(vector<string>& words, vector<string>::size_type sz, ostream&os = cout){
  auto count = count_if(words.begin(), words.end(), [=](const string& s){return s.size()>sz;});
  cout << count << " " << make_plural(count, "word", "s") << " of length" << sz << " or longer\n";
  cout << endl;
}

//E10.22 Rewrite the program to count words of size 6 or less using functions in
//place of the lambdas.
bool check_size(const string& s, string::size_type sz) {
  return s.size() > sz;
}
void biggies_countif_function(vector<string>& words, vector<string>::size_type sz, ostream&os = cout){
  auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
  cout << count << " " << make_plural(count, "word", "s") << " of length" << sz << " or longer\n";
  cout << endl;
}

//E10.24 Use bind and check_size to find the first element in a vector of ints
//that has a value greater than the length of a specified string value.
int find_biggie(vector<int> vec, const string& s){
  auto checki = bind(check_size, s, _1);
  int result;
  for (int i : vec) {
    if(!checki(i)) result = i;
  }
  return result;
}

//E10.25 In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies
//that uses partition. Rewrite that function to use check_size and bind.
void biggies_partition_bind(vector<string>& words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const string&s1, const string&s2){return s1.size()<s2.size();});
  auto iter = partition(words.begin(), words.end(), bind(check_size, _1, sz));
  auto count = words.end()-iter;
  cout << count << " " << make_plural(count, "word", "s") << " of length" << sz << " or longer\n";
  for_each(iter, words.end(), [](const string&s){cout << s << " ";});
  cout << endl;
}

//E10.27 In addition to unique (§ 10.2.3, p. 384), the library defines function
//named unique_copy that takes a third iterator denoting a destination into which
//to copy the unique elements. Write a program that uses unique_copy to copy the
// unique elements from a vector into an initially empty list.
list<int> cp(vector<int> vec){
  list<int> list;
  sort(vec.begin(), vec.end());
  unique_copy(vec.begin(), vec.end(), inserter(list, list.begin()));
  return list;
}

//E10.42 Reimplement the program that eliminated duplicate words that we wrote
//in § 10.2.3 (p. 383) to use a list instead of a vector.
void elimDups(list<string> &words) {
  words.sort();
  words.unique();
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

//E10.14 Write a lambda that takes two ints and returns their sum.
auto f = [](const int a, const int b){return a+b;};
cout << f(1,2) << endl;

//E10.15 Write a lambda that captures an int from its enclosing function and
//takes an int parameter. The lambda should return the sum of the captured int
//and the int parameter.
int b = 10;
auto f2 = [b](const int a){return a+b;};
cout << f2(1) << endl;

//E10.16 Write your own version of the biggies function using lambdas.
//Please check the function outside of the int main scope

//E10.17 Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the
//call to sort instead of the compareIsbn function.
vector<Sales_data> vec4{sd1, sd2, sd3, sd4, sd5};
stable_sort(vec4.begin(), vec4.end(), [](const Sales_data& s1, const Sales_data& s2){return s1.isbn().size() < s2.isbn().size();});
for (const auto& i : vec4) print(cout,i);
cout << endl;

//E10.18 Rewrite biggies to use partition instead of find_if. We described the
//partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).
//Please check the function outside of the int main scope

//E10.19 Rewrite the previous exercise to use stable_partition, which like
//stable_sort maintains the original element order in the paritioned sequence.
//Please check the function outside of the int main scope

//E10.20 The library defines an algorithm named count_if. Like find_if, this
//function takes a pair of iterators denoting an input range and a predicate
//that it applies to each element in the given range. count_if returns a count
//of how often the predicate is true. Use count_if to rewrite the portion of our
// program that counted how many words are greater than length 6.
vector<string> vec5 = {"Kevin", "Yu", "Wei", "Wang", "Kevin", "Wei", "Kev", "NorthCarolina"};
vector<string>::size_type sz = 6;
biggies_countif(vec5, sz, cout);
//E10.22 Rewrite the program to count words of size 6 or less using functions in
//place of the lambdas.
biggies_countif_function(vec5, sz, cout);

//E10.21 Write a lambda that captures a local int variable and decrements that
//variable until it reaches 0. Once the variable is 0 additional calls should no
// longer decrement the variable. The lambda should return a bool that indicates
//whether the captured variable is 0.
int var = 6;
auto result = [&var]()->bool {return var == 0? var:--var;};
cout << var << endl;
while(result()) cout << var << " ";
cout << var << endl;

//E10.23 How many arguments does bind take?
//It takes +1 argument than the argument number of the original function that it calls

//E10.24 Use bind and check_size to find the first element in a vector of ints
//that has a value greater than the length of a specified string value.
vector<int> vec6 = {1,2,3,4,8,5,6,7,8,9};
cout << find_biggie(vec6, "Kevin") << endl;

//E10.25 In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies
//that uses partition. Rewrite that function to use check_size and bind.
//Please check the function outside of the int main scope

//E10.26 Explain the differences among the three kinds of insert iterators.
//inserter insert at the iterator position using insert(t, iter),  front_inserter
// inserts at the front of the container using push_front and back_inserter
//inserts at the end of the container using push_back

//E10.27 In addition to unique (§ 10.2.3, p. 384), the library defines function
//named unique_copy that takes a third iterator denoting a destination into which
//to copy the unique elements. Write a program that uses unique_copy to copy the
// unique elements from a vector into an initially empty list.

//E10.28 Copy a vector that holds the values from 1 to 9 inclusive, into three
//other containers. Use an inserter, a back_inserter, and a front_inserter,
//respectivly to add elements to these containers. Predict how the output
//sequence varies by the kind of inserter and verify your predictions by running
//your programs.
// vector<int> vec7 = {1,2,3,4,5,6,7,8,9};
// vector<int> vec8, vec9, vec10;
// copy(vec7.cbegin(), vec7.cend(), front_inserter(vec8));//9,8,7,6,5,4,3,2,1
// copy(vec7.cbegin(), vec7.cend(), back_inserter(vec9)); //1,2,3,4,5,6,7,8,9
// copy(vec7.cbegin(), vec7.cend(), inserter(vec10, vec10.end()));//1,2,3,4,5,6,7,8,9
// for(auto i : vec8) cout << i << " ";
// cout << endl;
// for(auto i : vec9) cout << i << " ";
// cout << endl;
// for(auto i : vec10) cout << i << " ";
// cout << endl;

//E10.29 Write a program using stream iterators to read a text file into a vector
// of strings.
ifstream txt("test.txt");
istream_iterator<string> test_iter(txt), eof;
vector<string> vec11 (test_iter, eof);
for(auto i :vec11) cout << i << " ";

//E10.30 Use stream iterators, sort, and copy to read a sequence of integers
//from the standard input, sort them, and then write them back to the standard output.
istream_iterator<int> in_iter(cin), eof2;
ostream_iterator<int> out_iter(cout, " ");
vector<int> vec12(in_iter, eof2);
sort(vec12.begin(), vec12.end());
copy(vec12.begin(), vec12.end(), out_iter);
cout << endl;

//E10.31 Update the program from the previous exercise so that it prints
//only the unique elements. Your program should use unqiue_copy (§ 10.4.1, p. 403).
unique_copy(vec12.begin(), vec12.end(), out_iter);

//E10.32 Rewrite the bookstore problem from § 1.6 (p. 24) using a vector to hold
//the transactions and various algorithms to do the processing. Use sort with
//your compareIsbn function from § 10.3.1 (p. 387) to arrange the transactions
//in order, and then use find and accumulate to do the sum.

istream_iterator<Sales_item> Sale_iter(cin), eof3;
vector<Sales_item> vec13(Sale_iter, eof3);

sort(vec13.begin(), vec13.end(), [](const Sales_item& s1, const Sales_item& s2){return s1.isbn() <= s2.isbn();});
auto i = vec13.begin();
while(i != vec13.end()) {
  cout << i->isbn() << "hah" << endl;
  auto start = find(vec13.begin(), vec13.end(), *i);
  auto end = find_if_not(i, vec13.end(), [&i](const Sales_item& s){return s.isbn()== i->isbn();});
  cout << accumulate(start+1, end, *i) << endl;
  i = end;
}

//E10.33 Write a program that takes the names of an input file and two output
//files. The input file should hold integers. Using an istream_iterator read the
// input file. Using ostream_iterators, write the odd numbers into the first
//output file. Each value should be followed by a space. Write the even numbers
//into the second file. Each of these values should be placed on a separate line.
//Please see the file E10_33.cpp

//E10.34 Use reverse_iterators to print a vector in reverse order.
vector<string> vec14{"Kevin", "Yu", "Wei", "Wang", "NC"};
for(auto i = vec14.crbegin(); i != vec14.crend(); ++i) cout << *i << " ";
cout << endl;

//E10.35 Now print the elements in reverse order using ordinary iterators.
vector<string> vec15{"Kevin", "Yu", "Wei", "Wang", "NC"};
for(auto i = vec15.cend() - 1; i >= vec15.cbegin(); --i) cout << *i << " ";
cout << endl;

//E10.36 Use find to find the last element in a list of ints with value 0.
list<int> list1{1, 2, 3, 4, 5, 0, 1, 0, 2, 3, 4, 10};
auto liter1 = find(list1.crbegin(), list1.crend(), 0);
cout << *liter1 << " ";
++liter1;
cout << *liter1 << endl;

//E10.37 Given a vector that has ten elements, copy the elements from positions
//3 through 7 in reverse order to a list.
vector<int> vec16{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
list<int> list2;
copy(vec16.crbegin()+3, vec16.crbegin()+8, back_inserter(list2));
for(auto i : list2) cout << i << " ";
cout << endl;

//E10.38 List the five iterator categories and the operations that each supports.
//input interator: read ++, *, ->, *it++
//output iterators: write ++, *, assignment
//forward iterators:read write ++, *, ->, *it++, assignment
//bidirectional iterators: read write, ++, --, *, ->, *it++, *it--, assignment
//random access iterators: =, >, <, +, -, +=, *(iter+n)

//E10.39 What kind of iterator does a list have? What about a vector?
//Iterators for array, deque, string, and vector are random-access iterators,
//Vector has random access iterator, forward_list has forward iterator, (bidirectional) list
//has bidirectional Iterators

//E10.40 What kinds of iterators do you think copy requires? What about reverse
//or unique?
//copy(input_iter, input_iter, output_iter)
//reverse(bidirectional iter)
//unique(forward iter)

//E10.41 Based only on the algorithm and argument names, describe the operation
//that the each of the following library algorithms performs:
//replace(beg, end, old_val, new_val);
//if element == old_val, element = new_val;
//replace_if(beg, end, pred, new_val);
//if element fit the predicate, element = new_val
//replace_copy(beg, end, dest, old_val, new_val);
//if element == old_val, copy new_val into destination container
//replace_copy_if(beg, end, dest, pred, new_val);
//if element match the predicate, copy new_val into the container that dest points to.

//E10.42 Reimplement the program that eliminated duplicate words that we wrote
//in § 10.2.3 (p. 383) to use a list instead of a vector.
list<string> list3 = {"Kevin", "Yu", "Wei", "Wang", "Kevin", "Wei", "Kev", "NorthCarolina"};
elimDups(list3);
for(auto i : list3) cout << i << " ";
cout << endl;

return 0;
}
