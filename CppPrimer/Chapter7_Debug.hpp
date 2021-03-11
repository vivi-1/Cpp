#ifndef CHAPTER7_DEBUG_HPP
#define CHAPTER7_DEBUG_HPP

#include <iostream>
using namespace std;
class Debug {
public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
  constexpr Debug(bool h, bool i, bool o):hw(h), io(i), other(o){ }
  constexpr bool any() const {return hw||io||other;}
  void set_io(bool b) {io = b;}
  void set_hw(bool b) {hw = b;}
  void set_other(bool b) {other = b;}
  constexpr char* debug_type() const {
    char* result;
    if(hw) result = "hw";
    if(io) result = "io";
    if(other) result = "other";
    return result;
  }
  void print_error() const {if(any()) cerr << debug_type() << " debugging\n\n";}
private:
  bool hw;
  bool io;
  bool other;
};


#endif //CHAPTER7_DEBUG_HPP
