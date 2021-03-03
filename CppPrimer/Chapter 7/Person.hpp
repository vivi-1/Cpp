//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
using namespace std;

class Person {
  public://constructors:
    Person() = default;
    Person(const string &n, const string &a, const unsigned int &p) : name(n), address(a), population(p){}
    Person(istream&);

  private://Class data members
    string name;
    string address;
    unsigned int population = 1;

  public://class function members
    string readname () const {return name;};
    string readaddress() const{return address;};
    istream& read(istream&is, Person&object);

  friend istream& read(istream&is, Person&object);
  friend ostream &print(ostream &os, const Person &object);
  friend Person add(Person object1, Person object2);
};


istream& read(istream&is, Person&object) {
  is >> object.name >> object.address;
  return is;
}

Person::Person(istream& is) {
  read(is, *this);
}

ostream &print(ostream &os, const Person &object) {
  os << object.readname() << " " << object.readaddress();
  return os;
}

Person add(Person object1, Person object2) {
  Person combineInfo;
  if (object1.readname() == object2.readname() && object1.readaddress() == object2.readaddress())
      combineInfo.population = object1.population + object2.population;
  return combineInfo;
}

#endif //PERSON_HPP
