#include<iostream>
#include<map>
#include<set>
using namespace std;

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


return 0;
}
