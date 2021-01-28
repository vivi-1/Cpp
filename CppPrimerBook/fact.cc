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
