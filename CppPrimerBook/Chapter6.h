#include<iostream>
#include "Sales_item.h"
#include<vector>
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


int main()
{
