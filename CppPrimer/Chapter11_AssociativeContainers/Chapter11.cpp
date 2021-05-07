#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
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

*/

//E11.9

return 0;
}
