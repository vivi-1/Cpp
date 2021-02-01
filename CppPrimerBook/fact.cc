#include<iostream>
#include "Chapter6.h"
using namespace std;
using namespace ft;

//E6.3 6.4
int chapter6::fact(int input) {
  int temp = 1;
  while (input > 1) {
    temp *= input;
    --input;
  }
  return temp;
}



//E6.5
unsigned int chapter6::abv(signed int input1) {
  if (input1 < 0) input1 *= (-1);
  return input1;
}

//E6.10  Write and test your own version of reset that takes a reference.
void chapter6::swap(int *num1, int *num2) {
  cout << "num1 and num2 before swap are " << num1 << " " << num2 << endl;
  const int temp2 = *num2;
  const int temp1 = *num1;
  *num1 = temp2;
  *num2 = temp1;
  cout << "num1 and num2 after swap are " << num1 << " " << num2 << endl;
}

//E6.11  Write and test your own version of reset that takes a reference.
void chapter6::reset(char &chr) {
  chr = 'q';
}


//E6.12
void chapter6::swap2(int& num3, int& num4) {
  const int temp3 = num3;
  const int temp4 = num4;
  num3 = temp4;
  num4 = temp3;
}

//E6.17 Write a function to determine whether a string contains any capital
//letters. Write a function to change a string to all lowercase. Do the parameters
//you used in these functions have the same type? If so, why? If not, why not?
bool chapter6::is_upper(const string& input) {
  unsigned int temp = 0;
  bool result = false;
  for (auto &c : input) {
    if (isupper(c)) temp += 1;
  }
  if (temp != 0) result = true;
  return result;
}

string chapter6::to_lcase(string &input) {
  for (char &c : input) c = tolower(c);
  return input;
}


//E6.21
int chapter6::compareLarger (const int input1, const int *const input2) {
  return (input1 > *input2) ? input1 : (*input2);
}

//E6.22 Write a function to swap two int pointers.
void chapter6::swap_ptr(int*& p1, int*& p2) {
  int* const temp = p1;
  p1 = p2;
  p2 =  temp;
}


//E6.23
void chapter6::print(const int* ptr) {
  if (ptr != nullptr && (*ptr) != '\0') cout << *ptr << endl;
}

void chapter6::print (const int (&arr)[2]) {
  for(auto i : arr) {
    cout << i << endl;
  }
}
