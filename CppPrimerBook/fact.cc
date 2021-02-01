#include<iostream>
#include "Chapter6.h"
using namespace std;



//E6.3 6.4
int fact(int input) {
  int temp = 1;
  while (input > 1) {
    temp *= input;
    --input;
  }
  return temp;
}



//E6.5
unsigned int abv(signed int input1) {
  if (input1 < 0) input1 *= (-1);
  return input1;
}

//E6.10  Write and test your own version of reset that takes a reference.
void swap(int *num1, int *num2) {
  const int temp2 = *num2;
  const int temp1 = *num1;
  *num1 = temp2;
  *num2 = temp1;
}

//E6.11  Write and test your own version of reset that takes a reference.
void reset(char &chr) {
  chr = 'q';
}

//E6.12
void swap2(int &num3, int &num4) {
  const int temp3 = num3;
  const int temp4 = num4;
  num3 = temp4;
  num4 = temp3;
}

//E6.17 Write a function to determine whether a string contains any capital
//letters. Write a function to change a string to all lowercase. Do the parameters
//you used in these functions have the same type? If so, why? If not, why not?
bool is_upper(const string &input) {
  unsigned int temp = 0;
  bool result = false;
  for (auto c : input) {
    if (c.isupper()) temp += 1;
  }
  if (temp != 0) result = true;
  return result;
}

void to_lowercase(string &input) {
  for (auto c : input) c = tolower(c);
}


//E6.21 Write a function that takes an int and a pointer to an int and returns
//the larger of the int value or the value to which the pointer points. What
//type should you use for the pointer?
int compareLarger (const int input1, const int *const input2) {
  return (input1 > *input2) ? input1 : (*input2);
}


//E6.22 Write a function to swap two int pointers.
void swap_ptr(int*& p1, int*& p2) {
  int* const temp = p1;
  p1 = p2;
  p2 =  temp;
}

//E6.23
void print(const int* ptr) {
  for ( ; ptr != nullptr && (*ptr) != Null; ++ptr) cout << *ptr << endl;
}
