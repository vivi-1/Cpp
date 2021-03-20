#include<iostream>
#include<fstream>
#include <sstream>
using std::istream;
using std::ostream;
using std::istringstream;
#include "Sales_data.hpp"
#include<vector>
using namespace std;
//E8.1: Write a function that takes and returns an istream&. The function should
//read the stream until it hits end-of-file. The function should print what it
//reads to the standard output. Reset the stream so that it is valid before
//returning the stream.
istream& read_until_eof(istream& is) {
  string result;
  while(!is.eof() && is >> result) {
    cout << result << " ";
  }
  cout << endl;
  is.clear();
  return is;
}

istream& read_until_eof_line(istream& is) {
  string result;
  while (getline(is, result)) cout << result << " ";
  cout << endl;
  is.clear();
  return is;
}

//E8.4
vector<string> read_line_into_vector(const string filename) {
  ifstream in(filename, ios::in);
  vector<string> result;
  if (in) {
    string temp;
    while (getline(in,temp)) result.push_back(temp);
  }
  else{
  cerr << "error in opening file: " << filename << endl;
  exit(EXIT_FAILURE);
  }
  return result;
}

//E8.5
vector<string> read_word_into_vector(const string filename) {
  ifstream in(filename, ios::in);
  vector<string> result;
  if (in) {
    string temp;
    while (in >> temp) result.push_back(temp);
  }
  else{
  cerr << "error in opening file: " << filename << endl;
  exit(EXIT_FAILURE);
  }
  return result;
}

//E8.10: Write a program to store each line from a file in a vector<string>.
//Now use an istringstream to read each element from the vector a word at a time.
vector<string> read_sstream_into_vector(ifstream& filename) {
  vector<string> result;
  if(filename) {
    string line, word;
    while (getline(filename, line)) {
      istringstream str(line);
      while (str >> word) {
        result.push_back(word);
        cout << word << " ";
     }
     cout << endl;
    }
      cout << "eof\n";
  }
  return result;
}

int main(){
//E8.1: Write a function that takes and returns an istream&. The function should
//read the stream until it hits end-of-file. The function should print what it
//reads to the standard output. Reset the stream so that it is valid before
//returning the stream.
// istream& read_until_eof(istream& is) {
//  string result;
//   while(!item.eof() && is >> result) {
//     cout << item;
//   }
//   is.clear();
//   return is;
// }

//E8.2: Test your function by calling it, passing cin as an argument.
istream& is = read_until_eof(cin);
cout << is.rdstate() << endl;

//E8.3: What causes the following while to terminate?
// while (cin >> i)

//eofbit: reaching end of file, in this case, reaching the end of whats passed into cin;
//failbit: a recoverable error such as read a character when numeric data was expected;
// in this case, input was different type with i;
//badbit:system-level failure, such as an unrecoverable read or write error

string k;
while (cin >> k) cout << k << endl;

//E8.4: Write a function to open a file for input and read its contents into a
//vector of strings, storing each line as a separate element in the vector.
// vector<string> read_line_into_vector(const string filename) {
//   ifstream in(filename);
//   vector<string> result;
//   if (in) {
//     string temp;
//     while (getline(in,temp)) result.push_back(temp);
//   }
//   else{
//   cerr << "error in opening file: " << filename << endl;
//   exit(EXIT_FAILURE);
//   }
//   return result;
// }

vector<string> test = read_line_into_vector("test.txt");
for (auto i : test) cout << i << "\n";


//E8.5: Rewrite the previous program to store each word in a separate element.
// vector<string> read_word_into_vector(const string filename) {
//   ifstream in(filename);
//   vector<string> result;
//   if (in) {
//     string temp;
//     while (in >> temp) result.push_back(temp);
//   }
//   else{
//   cerr << "error in opening file" << filename << endl;
//   exit(EXIT_FAILURE);
//   }
//   return result;
// }

//E8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its
//transactions from a file. Pass the name of the file as an argument to
//main (§ 6.2.5, p. 218).
//Please see my E8_6.cpp

//E8.7: Revise the bookstore program from the previous section to write its
//output to a file. Pass the name of that file as a second argument to main.
//please check my E8_7.cpp

//E8.8: Revise the program from the previous exercise to append its output to
//its given file. Run the program on the same output file at least twice to
//ensure that the data are preserved.
//please check my E8_8.cpp

//E8.9: Use the function you wrote for the first exercise in § 8.1.2 (E8.1)
//(p. 314) to print the contents of an istringstream object.
// istream& read_until_eof(istream& is) {
//   string result;
//   while(!is.eof() && is >> result) {
//     cout << result << " ";
//   }
//   is.clear();
//   return is;
// }
istringstream iss("isstring print");
read_until_eof(iss);

//E8.10: Write a program to store each line from a file in a vector<string>.
//Now use an istringstream to read each element from the vector a word at a time.
// vector<string> read_sstream_into_vector(ifstream& filename) {
//   vector<string> result;
//   if(filename) {
//     string line, word;
//     while (getline(filename, line)) {
//       istringstream str(line);
//       while (str >> word) {
//         result.push_back(word);
//         cout << word << " ";
//      }
//      cout << endl;
//     }
//       cout << "eof\n";
//   }
//   return result;
// }

fstream createFile("test.txt");
createFile << "Wei 2 5.0\nWei 7 8.0\nKevin 1 2.0\nhahahaha 2 1.0" << endl;
createFile.close();
ifstream input("test.txt");
read_sstream_into_vector(input);

//E8.11: The program in this section defined its istringstream object inside the
//outer while loop. What changes would you need to make if record were defined
//outside that loop? Rewrite the program, moving the definition of record outside
// the while, and see whether you thought of all the changes that are needed.
//Orginal:
// string line, word;
// vector<PersonInfo> people;
// while (getline(cin, line)) {
//     PersonInfo info;
//     istringstream record(line);
//     record >> info.name;
//     while (record >> word)
//         info.phones.push_back(word);
//     people.push_back(info);
// }
//My edit:
// string line, word;
// vector<PersonInfo> people;
// istringstream record;
// while (getline(cin, line)) {
//     record.str(line);
//     PersonInfo info;
//     record >> info.name;
//     while (record >> word)
//         info.phones.push_back(word);
//     people.push_back(info);
// }

//E8.12: Why didn’t we use in-class initializers in PersonInfo?
//It is an aggregate class:"An aggregate is a simple collection of
//data that does not have any invariants the class would have to guarantee.
//Since there is no invariant and thus all combinations of possible values of
//the member make sense, there is no point in making them private since there
//is nothing to protect."
//All of its data members are public
//It does not define any constructors
//It has no in-class initializers (§ 2.6.1, p. 73)
//It has no base classes or virtual functions,

//E8.13 Rewrite the phone number program from this section to read from a named
// file rather than from cin.
// for (const auto &entry : people) {
//     ostringstream formatted, badNums;
//     for (const auto &nums : entry.phones) {
//         if (!valid(nums)) {
//             badNums << " " << nums;
//         } else
//             formatted << " " << format(nums);
//     }
//     if (badNums.str().empty())
//         os << entry.name << " "
//            << formatted.str() << endl;
//     else
//         cerr << "input error: " << entry.name
//              << " invalid number(s) " << badNums.str() << endl;
// }

//E8.14: Why did we declare entry and nums as const auto &?
//We don't want to risk changing the original data in People, so we make it const;

return 0; //return EXIT_SUCCESS
}
