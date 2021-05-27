#include<iostream>
#include<map>
#include <unordered_map>
#include<set>
#include<string>
#include<vector>
#include<utility>
#include <chrono>
#include <typeinfo>
#include<fstream>
#include"Sales_item.h"
#include <sstream>
using namespace std;

//E11.33
map<string, string> buildMap(ifstream&map_file){
  map<string, string> trans_map;
  string key, value;
  while(map_file >> key && getline(map_file, value))
    if(value.size() > 1)
      trans_map[key] = value.substr(1);
    else
      throw runtime_error("no rule for" + key);
  return trans_map;
}

const string& transform(const string&s, const map<string, string>&m){
  auto map_it = m.find(s);
  if(map_it!=m.cend())
    return map_it->second;
  else
    return s;
}

void word_transform(ifstream &map_file, ifstream& input){
  auto trans_map = buildMap(map_file);
  string text;
  while(getline(input, text)){
    istringstream stream(text);
    string word;
    bool firstword = true;
    while(stream >> word){
      if(firstword) firstword = false;
      else cout<<" ";
      cout << transform(word, trans_map);
    }
    cout << endl;
  }
}

//E11.38 Rewrite the word-counting (§ 11.1, p. 421) and word-transformation
//(§ 11.3.6, p. 440) programs to use an unordered_map.
unordered_map<string, size_t> word_count6(){
  string word;
  unordered_map<string, size_t> word_count;
  while (cin >> word) ++word_count[word];
  for (const auto &w : word_count)
    cout <<  w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  return word_count;
}

const string& transformC(const string&s, const unordered_map<string, string>&m){
  auto map_it = m.find(s);
  if(map_it!=m.cend())
    return map_it->second;
  else
    return s;
}

void word_transformC(ifstream &map_file, ifstream &input){
  unordered_map<string, string> trans_map;
  string key, value;
  while(map_file >> key && getline(map_file, value))
    if(value.size() > 1)
      trans_map[key] = value.substr(1);
    else
      throw runtime_error("no rule for" + key);
  string text;
  while (getline(input, text)) {
    istringstream stream(text);
    string word;
    bool firstword = true;
    while (stream >> word) {
    if (firstword) firstword = false;
    else
      cout << " ";
      cout << transformC(word, trans_map);
    }
    cout << endl;
  }
}

int main() {

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
map<string, size_t>::iterator m1 = map_assign.begin();
m1->second = 2;
cout << m1->first << " " << m1->second << endl;

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

//E11.20 Rewrite the word-counting program from § 11.1 (p. 421) to use insert
//instead of subscripting. Which program do you think is easier to write and
//read? Explain your reasoning.
vector<string> exclude_vec1 = {"A", "An", "And", "The", "Or", "a", "an", "and", "the", "or"};
map<string, size_t> words_count4;
string word4;
while (cin >> word4 && word4 != "end"){
  auto insert1 = words_count4.insert({word4, 1});
  if(!insert1.second) ++insert1.first->second;
}
for (const auto &i : words_count4) cout << i.first << " occurs " << i.second << ((i.second > 1) ? " times\n" : " time\n");

//E11.21 Assuming word_count is a map from string to size_t and word is a string,
// explain the following loop:
// while (cin >> word)
//   ++word_count.insert({word, 0}).first->second;
//precedence: left to right, "." = "->" > Prefix "++"
//increment the values (the counts) of "word"

//E11.22 Given a map<string, vector<int>>, write the types used as an argument
//and as the return value for the version of insert that inserts one element.
//pair<string, vector<int>> element1;
//pair<map<string, vector<int>::iterator>, bool>

//E11.23 Rewrite the map that stored vectors of children’s names with a
//key that is the family last name for the exercises in § 11.2.1 (p. 424) to use
// a multimap.
multimap<string, vector<string>> family1;
string lastname;
while (cin >> lastname && lastname != "end"){
  string childname;
  vector<string>children;
  while(cin >> childname && childname != "end") children.push_back(childname);
  cout << "Another last name to be input:\n";
  family1.insert({lastname, children});
}
for(auto i : family1) {
  cout << i.first << ": ";
  for(auto j : i.second) cout << j << " ";
  cout << endl;
}

//E11.24 What does the following program do?
// map<int, int> m;
// m[0] = 1;
//declare a map m, and if there's no "0" as a key in m, then insert an
//element with key "0" and value initialized to 0, and then the newly inserted
//element was fetched and the value changed to 1

//E11.25 Contrast the following program with the one in the previous exercise
// vector<int> v;
// v[0] = 1;
//For a sequential container, the subscription doesn't insert a new element if
// the subscript element can't be found. So in this case, v[0] doesn't exist and
//can't be inserted

//E11.26 What type can be used to subscript a map? What type does the subscript
//operator return? Give a concrete example—that is, define a map and then write
//the types that can be used to subscript the map and the type that would be
//returned from the subscript operator.
//key_type
//map<key_type, mapped_type>::mapped_type

map<string, int> words_count5 = {{"Kevin", 1},{"Wei", 2},{"Yu", 3}, {"Wang", 4}};
map<string, int>::key_type subscript = "Wei";
cout << words_count5[subscript] << "\n"
        << typeid(words_count5[subscript]).name() << endl;

//E11.27 What kinds of problems would you use count to solve? When might you use
// find instead?
//Using count: Count how many instances there are with a key in a multiset or multimap
//Using find: Find if a key exist, doesn't need to traverse the whole container.
//find is more applicable to set or map that only has unique keys

//E11.28 Define and initialize a variable to hold the result of calling find on
//a map from string to vector of int.
multimap<string, vector<int>> authors1 = {{"Kevin", {1,2,3,4,5}}, {"Wei", {0,5, 6, 7, 8}}, {"Kevin", {7,2,3,4,5}}};
multimap<string, vector<int>>::iterator iter = authors1.find("Kevin");
cout << iter->second[0] << endl;

//E11.29 What do upper_bound, lower_bound, and equal_range return when you pass
//them a key that is not in the container?
//upper_bound = lower_bound: returns an iterator where an element with the key
// can be inserted
//equal_range returns a pair {c.end(), c.end()}

//E11.30 Explain the meaning of the operand pos.first->second used in the output
//expression of the final program in this section.
//pos.first is initially an iterator points to the first position where the
//key=search_item and increment until the one past the element with the same key.
//pos.first->second is the value of the element that has the key as serach_item

//E11.31 Write a program that defines a multimap of authors and their works. Use
//find to find an element in the multimap and erase that element. Be sure your
//program works correctly if the element you look for is not in the map.
//E11.32 Using the multimap from the previous exercise, write a program to print
//the list of authors and their works alphabetically.
multimap<string, string> authors2 = {{"vivi", "cpp primer"}, {"Kevin", "Sony headset"}, {"Kevin", "love letter"}, {"Wei", "sleep pad"}, {"Kevin", "skiing trip"}};
auto iter = authors2.find("Kevin");
auto count = authors2.count("Kevin");
string to_erase= "love letter";
// while(count){
//   if (iter->second == to_erase) authors2.erase(iter);
//   ++iter;
//   --count;
// }
// for(auto i : authors2){
//   cout << i.first << ": " << i.second << endl;
// }
multiset<string> values1;
map<string, multiset<string>> order_map;
for(auto i : authors2) order_map[i.first].insert(i.second);
for(auto i : order_map){
  cout << i.first << endl;
  for (auto j : i.second) cout << j << ", ";
  cout << endl;
}

//E11.34 What would happen if we used the subscript operator instead of find in
//the transform function?
//if the key doesn't exist, an element with the key was inserted with value initilizatioin

//E11.35 In buildMap, what effect, if any, would there be from rewriting
//     trans_map[key] = value.substr(1);
// as trans_map.insert({key, value.substr(1)})?
// if there are many values with the same key, the first one will update the values
// as value.substr(1) for the key, and the second will not insert the new value
//but return an iterator to this existing element

//E11.36 Our program does no checking on the validity of either input file. In
//particular, it assumes that the rules in the transformation file are all
//sensible. What would happen if a line in that file has a key, one space, and
//then the end of the line? Predict the behavior and then check it against your
//version of the program.
//buildMap will get the key as a key, and empty string as a value. Since value.size() > 1
//is false, it will throw a runtime_error and will not add the key into the transformtion map.

//E11.37 What are the advantages of an unordered container as compared to the
//ordered version of that container? What are the advantages of the ordered
//version?
//An unordered container is most useful when we have a key type for which there's
//no obvious ordering relationship among the elements.
//Search and insertion of an element takes up O(1) time in an unordered while the
// ordered one takes up O(logN).
//Hash functions make it faster if the key is strings.


return 0;
}
