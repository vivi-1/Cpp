#ifndef PERSONINFO_HPP
#define PERSONINFO_HPP

#include <iostream>
#include <vector>
using namespace std;

class PersonInfo {
  public://constructors:
    PersonInfo() = default;
    PersonInfo(const string &n, const string &a, const unsigned int &p) : name(n), address(a), population(p){}
    explicit PersonInfo(istream&);

    //Class data members
    string name;
    string address;
    vector<string> phones;
    unsigned int population = 1;

    //class function members
    string readname () const {return name;};
    string readaddress() const{return address;};

  friend istream& read(istream& is, PersonInfo&object);
  friend ostream& print(ostream& os, const PersonInfo& object);
  friend PersonInfo add(PersonInfo object1, PersonInfo object2);
  friend bool valid(const string& number);
  friend string format(const string& number);
};


istream& read(istream&is, PersonInfo&object) {
  is >> object.name >> object.address;
  return is;
}

PersonInfo::PersonInfo(istream& is) {
  read(is, *this);
}

ostream &print(ostream &os, const PersonInfo &object) {
  os << object.readname() << " " << object.readaddress();
  return os;
}

PersonInfo add(PersonInfo object1, PersonInfo object2) {
  PersonInfo combineInfo;
  if (object1.readname() == object2.readname() && object1.readaddress() == object2.readaddress())
      combineInfo.population = object1.population + object2.population;
  return combineInfo;
}

bool valid(const string& number) {
  return (number.length() == 10);
}

string format(const string& number) {
  string result;
  for (int i = 0; i!=number.length(); i++){
    result+=number[i];
    if ((i == 2) || (i==5)) result+="-";
  }
  return result;
}

#endif //PERSONINFO_HPP
