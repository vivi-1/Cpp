//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
using namespace std;

class screen {
public:
  typedef string::size_type pos;
  //constructors
  screen() = default;
  screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' '){}
  screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}
  //class member functions
  char get() const {return contents[cursor];}
  inline char get(pos ht, pos wd) const;
  screen &move(pos r, pos c);
  void some_member() const {++access_ctr;}
private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;
  mutable size_t access_ctr;
};

inline
screen & screen::move(pos r, pos c){
  pos row = r*width;
  cursor = row + c;
  return *this;
}

char screen::get(pos r, pos c) const{
  pos row = r*width;
  return contents[row+c];
}

#endif //SCREEN_HPP
