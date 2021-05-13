#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<utility>
#include <chrono>
#include"Sales_item.h"
using namespace std;

int main() {
/*
//E11.1 Describe the differences between a map and a vector.
//(1) Map is an associative containcer while vector is a sequential container.
//(2) Map contains keys and values while vector only contains values.
//(3) Map find values by keys while vector by subscripts

//E11.2 Give an example of when each of list, vector, deque, map, and set might
//be most useful.
//List: easy insert at random place and hard finding (eg.task list)
//Vector: storage of elements that can be find and easily, not easy to insert at
// random places
//Deque: Hospital waiting line
//Map: Dictionary, find people's phone number by their names
//Set: Find if a value exists, for example, bad_checks set contains all the names
//that has bad record.

//E11.3 Write your own version of the word-counting program.
map<string, size_t> words_count;
set<string> exclude = {"A", "An", "And", "The", "Or", "a", "an", "and", "the", "or"};
string word;
while (cin >> word && word != "end")
  if(exclude.find(word) == exclude.end())
    ++words_count[word];
for (const auto &i : words_count) cout << i.first << " occurs " << i.second << ((i.second > 1) ? " times\n" : " time\n");

//E11.4 Extend your program to ignore case and punctuation. For example,
//“example.” “example,” and “Example” should all increment the same counter.
// map<string, size_t> words_count2;
// set<string> exclude2 = {"A", "An", "And", "The", "Or", "a", "an", "and", "the", "or"};
// string word2;
// while (cin >> word2 && word2 != "end") {
//   cout << word2 << endl;
//   for(auto i = 0; i != word2.length(); i++) {
//     cout << word2[i] << i << endl;
//     if (isupper(word2[i])) word2[i] = tolower(word2[i]);
//     if (ispunct(word2[i])) cout << "punc\n"; word2 = word2.erase(i, 1);
//   }
//   cout << word2 << endl;
//   if (exclude2.find(word2) == exclude2.end()) ++words_count2[word2];
// }
// for (const auto &i : words_count2) cout << i.first << " occurs " << i.second << ((i.second > 1) ? " times\n" : " time\n");
//

//E11.5 Explain the difference between a map and a set. When might you use one
//or the other?
//A set can only have keys and map has{key, value}
//a set can be used when we need to store the keys and cross-comparison with map to add values to the keys counts
//a map can be used in a dictionary

//E11.6 Explain the difference between a set and a list. When might you use one
//or the other?
//A set is an associative container and can't have duplicate keys
// while list is a sequential container and can have replicated elements
//A list is serached in O(N) and set is O(log(N))

//E11.7 Define a map for which the key is the family’s last name and the value
//is a vector of the children’s names. Write code to add new families and to add
//new children to an existing family.
map<string, vector<string>> family;
string name_to_add1 = "Yu";
string name_to_add2 = "Wang";
string member_to_add1 = "Wei Wang";
string member_to_add2 = "Kevin Yu";
family[name_to_add1];
family[name_to_add1].push_back(member_to_add1);
family[name_to_add2];
family[name_to_add2].push_back(member_to_add2);

for(auto i : family) {
  cout << i.first << ": ";
  for(auto j : i.second) cout << j << " ";
  cout << endl;
}

//E11.8 Write a program that stores the excluded words in a vector instead of in
//a set. What are the advantages to using a set?
//faster to search for a value in a set than in a vector
vector<string> exclude_vec = {"A", "An", "And", "The", "Or", "a", "an", "and", "the", "or"};
map<string, size_t> words_count3;
string word3;
while (cin >> word3 && word3 != "end")
  if(find(exclude_vec.begin(), exclude_vec.end(), word3) == exclude_vec.end())
    ++words_count3[word3];
for (const auto &i : words_count3) cout << i.first << " occurs " << i.second << ((i.second > 1) ? " times\n" : " time\n");

//E11.9 Define a map that associates words with a list of line numbers on which
//the word might occur.
map<string, list<int>> word_line;

//E11.10 Could we define a map from vector<int>::iterator to int? What about from
// list<int>::iterator to int? In each case, if not, why not?
//yes to vector<int>::iterator to int
//no to list<int>::iterator to int: the elements in a list is stored not continuously
//so the list<int>::iterator can't be int

//E11.11 Redefine bookstore without using decltype.
using replace = bool (*)(Sales_item const&, Sales_item const&);
multiset<Sales_item, replace)> bookstore(compareIsbn);

//E11.12 Write a program to read a sequence of strings and ints, storing each
//into a pair. Store the pairs in a vector.
string s;
int i;
vector<pair<string, int>> vec;
while(cin >> s >> i) {
  pair<string, int> random{s, i};
  vec.push_back(random);
  for(auto i : vec) {
    cout << i.first << " " << i.second;
  }
  cout << endl;
}

//E11.13 There are at least three ways to create the pairs in the program for
//the previous exercise. Write three versions of that program, creating the pairs
//in each way. Explain which form you think is easiest to write and understand,
//and why.
string s1 = "Kevin";
int i1 = 1;
pair<string, int> random1 = make_pair(s1, i1);
pair<string, int> random2 = {s1, i1};
pair<string, int> random3;
random3.first = s1;
random3.second = i1;

//E11.14 Extend the map of children to their family name that you wrote for the
//exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a
//child’s name and birthday.
map<string, vector<pair<string, string>>> family;
string name_to_add1 = "Yu";
string name_to_add2 = "Wang";
pair<string, string> member_to_add1 = {"Kevin", "May/12/2021"};
pair<string, string> member_to_add2 = {"Wei", "April/12/2021"};
family[name_to_add1];
family[name_to_add1].push_back(member_to_add1);
family[name_to_add2];
family[name_to_add2].push_back(member_to_add2);

for(auto i : family) {
  cout << i.first << ": ";
  for (auto j : i.second) {
    cout << j.first << " " << j.second << " ";
    cout << endl;
  }
  cout << endl;
}

//E11.15 What are the mapped_type, key_type, and value_type of a map from int to
// vector<int>?
//mapped_type: vector<int>
//key_type: int
//value_type: pair<int, vector<int>>

//E11.16 Using a map iterator write an expression that assigns a value to an
//element.
map<string, int> map_assign;
map_assign["Kevin"] = 1;
map<string, int>::iterator m1 = map_assign.begin();
m1->second = 2;
cout << m1->first << " " << m1->second << endl;
*/
//E11.17 Assuming c is a multiset of strings and v is a vector of strings,
//explain the following calls. Indicate whether each call is legal:
// copy(v.begin(), v.end(), inserter(c, c.end()));
//copy each element from v into c's begining
//legal
// copy(v.begin(), v.end(), back_inserter(c));
//illegal
// copy(c.begin(), c.end(), inserter(v, v.end()));
//legal
// copy(c.begin(), c.end(), back_inserter(v));
//legal

//E11.18 Write the type of map_it from the loop on page 430 without using auto
//or decltype.
//map<string, int>::iterator map_it = word_count.cbegin();

//E11.19 Define a variable that you initialize by calling begin() on the multiset
//named bookstore from § 11.2.2 (p. 425). Write the variable’s type without
//using auto or decltype.
using compare = bool (*)(const Sales_data &s1, const Sales_data &s2);
multiset<Sales_data, decltype(compare)*> bookstore(compareIsbn);
multiset<Sales_data>::iterator = bookstore.begin();

return 0;
}
