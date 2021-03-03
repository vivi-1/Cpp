//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef SCREENMUTABLE_HPP
#define SCREENMUTABLE_HPP

#include <iostream>
using namespace std;

class screenMutable {
public:
  void some_member() const;
private:
  mutable size_t access_ctr;
};

void screenMutable::some_member() const{++access_ctr;}

#endif //SCREENMUTABLE_HPP
