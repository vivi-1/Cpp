//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
using namespace std;

struct Person {
  private:
  string name;
  string address;
  unsigned int population = 0;
  public:
  string readname () const {return name;};
  string readaddress() const{return address;};
}

istream &read(istream&is, Person&object) {
  is >> object.name >> object.address;
  return is;
}
ostream &print(ostream &os, const Person &object) {
  os << object.readname() << " " << object.readaddress();
  return os;
}

Person add(Person object1, Person object2) {
  Person combineInfo;
  if (object1.name == object2.name && object1.address == object2.address)
      combineInfo.population = object1.population + object2.population;
  return combineInfo;
}

#endif //PERSON_HPP
