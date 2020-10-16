/*
This is CppPrimerPractice for the C++ primer 5th edition
*/
#include<iostream>
#include "Sales_item.h"

using namespace std;

int main() 
{

/*
   cout << "enter two numbers:" << endl << "First number: ";
   int v1, v2;
   cin>>v1;
   cout << "Second number: ";
   cin>>v2;
   cout << "the multiplication of " << v1 << " and " << v2 << " is " << v1*v2 << endl; //E1.4
   cout << "Hello, World" << endl;  //E1.3
   cout << "the multiplication of ";
   cout << v1;
   cout << " and ";
   cout << v2;
   cout << " is ";
   cout << v1*v2 << endl; //E1.5
*/
// /*incorrect comments // /* */ E1.7

   cout << "/*" << endl;  //E1.8
   cout << /* "*/" */ "/*" */ << endl; //E1.8   
 /*
   int sum=0, val=1, x; //if you don't define x, x is random number
   cout << "initial sum is " << sum << ", while val is " << val << endl;
   while (val <= 10) {   
      cout << "now sum is " << sum << endl;
      sum += val;
      cout << "result sum is " << sum << " when val is " << val << endl;
      ++val;
      cout << "now val changes to " << val << endl;
   }
   cout << "result is " << sum << endl;
   cout << x << endl;  // x is random integer

   int sum2 = 0, val2 = 50;
   while (val2 <= 100) {
      sum2 +=val2;
      ++val2;
   }
   cout << "sum from 50 to 100 is " << sum2 << endl;
   cout << "The correct answer is " << 150*51*0.5 << "please check it out" << endl;  // E1.9



   int val3=10;
   while (val3 >= 0) {
      cout << "now it's at position " << val3 << endl;
      --val3;
   } // E1.10
   
   int val4=5, val5=1;
   cout << "original val4 is " << val4 << "val5 is " << val5 << endl;
   if (val5 >= val4) {
      int result = val4;
      cout << "starting point is " << result << endl;
      while (result < val5) {
         ++result;
         cout << "now its " << result << endl;
      }
   }
   else {
      int result = val5;
      while (result <= val4) {
         ++result;
         cout << "now its " << result << endl;
      }
   }  // E1.11

   int sum3 = 0;
   for (int val6 = -100; val6 <=100; ++val6)
      sum3 += val6;
   cout << sum3 << endl;  //E1.12

   int sum4 = 0;
   for (int val7 = 50; val7 <= 100; ++val7)
      sum4 += val7;
   cout << sum4 << endl; //E1.13

   for (int val8 = 10; val8 >= 0; --val8)
      cout << "now it's at position " << val8 << endl; //E1.13
   
   int sum5 = 0, value = 4;
   while (cin >> value)
      sum5 += value;
      cout << sum5 << endl;

   int sum6 = 0, value1=2;
   while (cin>>value1)
      sum6 += value1;
      cout << sum6 << endl;  //E1.16

   int currVal = 0, val9 = 0;
   if (cin >> currVal) {
      int cnt = 1;
      while (cin >> val9) {
         if (val9 == currVal)
            ++cnt;
         else {cout << currVal << "occurs" << cnt << " times" << endl;
         currVal = val9;
         cnt = 1;
         }
      }
      cout << currVal << " occurs " << cnt << " times" << endl;
      
   }

   Sales_item book;
   cin >> book;
   cout << book << endl; //E1.20

   Sales_item item1, item2;
   cin >> item1 >> item2;
   cout << item1 +item2 << endl; //E1.21

   Sales_item item1, item2, item3, item4;
   cin >> item1 >> item2 >> item3 >> item4;
   cout << item1 + item2 + item3 +item4 << endl; // E1.22


   Sales_item item1, item2;
   cin >> item1 >> item2;
   if (item1.isbn() == item2.isbn()) {
      cout << item1 + item2 << endl;
      cout << item1.isbn() << endl;
      return 0;}
   else{
      cout << "data must refer to same ISBN" << endl;
      cout << item1.isbn() << endl;
      return -1;
   }
   }

   Sales_item item1, item2, item3;
   cin >> item1 >> item2 >> item3;
   cout << item1.isbn() << item1.bookNo() << endl;

   Sales_item Current, input;
   if (cin >> Current) {
      int cnt = 1;
      while (cin >> input) {
         if (input.isbn() == Current.isbn()) {
            ++cnt;
         }
         else {
            cout << Current << "occurs" << cnt << "times" << endl;
            Current = input;
            cnt = 1;
         } 
      }
   } //E1.23 E1.24

   Sales_item total;
   if (cin >> total) {
      Sales_item trans;
      while (cin >> trans) {
         if (total.isbn() == trans.isbn())
         total += trans;
         else{
            cout << total << endl;
            total = trans;
         }
      }
      cout << total << endl;
   }
   else {
      cerr << "no data?!" << endl;
      return -1;
   }  //E1.25


// E2.1 short <= int <= long <= long long; unsigned >=0  signed can be negative or positive; float is shown in one word (32bits, 4 bytes), double in two words (64bits, 8bytes)
// E2.2 double or long double, which has more precision instead of float

unsigned u = 10;
int i = -42;
cout << i+i << endl;
cout << u+i << endl;  // u is unsigned, i is signed, i will be converted into unsigned.

 unsigned u = 11;
 while (u > 0) {
    --u;
    cout << u << endl;
 }


unsigned i=-32;
cout << i << endl;
//32; 4294967264, 32, -32, 0,0 E2.3

unsigned u, u2;
while (cin >> u >> u2) {
   if (u2-u == 32) {
      cout << "correct" << endl;
   } else {
      cout << "wrong" << endl;
   } 
} //E2.4


 cout << "hi"
 "there" << endl;

cout << "hi""there" << endl;
cout << "hi" "there" << endl;
cout << "hi"   "there" << endl;  //concatenate into a single literal

cout << '\n' << endl;
cout << "\" double quote \" \n" "\a" "\' single quote\'\n"  "\a \? \t \v" << endl; //escape sequences
cout << "\7 \n" "\115 \12"  "\x4d \n" << endl;
cout << "Who goes with F\145rgus?\012"  "3.14e1L "  "1024f" " 3.14L" << endl;
cout << "2M \n" "2 \12 \115 2 \t \x4d" << endl;
cout << "\062" << endl;
*/


return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully. 
   
}

