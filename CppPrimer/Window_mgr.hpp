//This file was written by Wei Wang, github: https://github.com/vivi-1
#ifndef WINDOW_MGR_HPP
#define WINDOW_MGR_HPP

#include <iostream>
#include"screen.hpp"
#include <vector>
using namespace std;

class Window_mgr {
public:
  using screenIndex = vector<screen>::size_type;
  void clear(screenIndex);
private:
  vector<screen> screens{screen{24, 80,' '}};
};

void Window_mgr::clear(screenIndex i){
  screen &s = screens[i];
  s.contents = string(s.height*s.width,' ');
}
#endif //WINDOW_MGR_HPP
