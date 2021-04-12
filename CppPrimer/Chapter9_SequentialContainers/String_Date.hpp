//E9.51 Write a class that has three unsigned members representing year, month,
//and day. Write a constructor that takes a string representing a date. Your
//constructor should handle a variety of date formats, such as January 1, 1900,
//1/1/1900, Jan 1, 1900, and so on.
#ifndef STRING_DATE_HPP
#define STRING_DATE_HPP
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class String_Date{
  //Members
  unsigned month;
  unsigned day;
  unsigned year;
  const vector<string> months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  //Constructor
public:
  String_Date (const string& date) {
    if (date.find(",") == string::npos) {
      month = stoi(date.substr(0,date.find_first_of("/")));
      day = stoi(date.substr(date.find_first_of("/")+1, date.find_last_of("/")));
      year = stoi(date.substr(date.find_last_of("/")+1));
    }
    else {
      string temp = date.substr(0,3);
      for(int i = 0; i != 12; ++i) {
        if (months[i]==temp) {
          month = i + 1;
          break;
        }
      }
    day = stoi(date.substr(date.find_first_of(' ')+1, date.find_first_of(",")));
    year = stoi(date.substr(date.find_last_of(' ')+1));
    }
  }

  //functions
  void print() {cout << "Month: " << month << " Day: " << day << " year: " << year << endl;}

};

#endif //STRING_DATE_HPP
