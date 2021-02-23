//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
using namespace std;

struct Person {
  private:
  string name;
  string address;
  public:
  string readname () const {return name;};
  string readaddress() const{return address;};
}
ostream &print(ostream&, const Person&);
istream &read(istream&, Person&);

#endif //PERSON_HPP
