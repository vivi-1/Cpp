#include<iostream>
#include "Sales_item.h"
using namespace std;

int main(){
/*
//E1.5
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
   cout << v1*v2 << endl;
*/
// /*incorrect comments // /* */ E1.7

//E1.8
   cout << "/*" << endl;
   cout << /* "*/" */ "/*" */ << endl;
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

// E1.9
   int sum2 = 0, val2 = 50;
   while (val2 <= 100) {
      sum2 +=val2;
      ++val2;
   }
   cout << "sum from 50 to 100 is " << sum2 << endl;
   cout << "The correct answer is " << 150*51*0.5 << "please check it out"
   << endl;


// E1.10
   int val3=10;
   while (val3 >= 0) {
      cout << "now it's at position " << val3 << endl;
      --val3;
   }

// E1.11
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
   }

//E1.12
   int sum3 = 0;
   for (int val6 = -100; val6 <=100; ++val6)
      sum3 += val6;
   cout << sum3 << endl;

//E1.13
   int sum4 = 0;
   for (int val7 = 50; val7 <= 100; ++val7)
      sum4 += val7;
   cout << sum4 << endl;
//E1.14
   for (int val8 = 10; val8 >= 0; --val8)
      cout << "now it's at position " << val8 << endl;

   int sum5 = 0, value = 4;
   while (cin >> value)
      sum5 += value;
      cout << sum5 << endl;
//E1.16
   int sum6 = 0, value1=2;
   while (cin>>value1)
      sum6 += value1;
      cout << sum6 << endl;

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

//E1.20
   Sales_item book;
   cin >> book;
   cout << book << endl;
//E1.21 Write a program that reads two Sales_item objects that have the same
//ISBN and produces their sum.
   Sales_item ob1, ob2;
   cin >> ob1 >> ob2;
   if (ob1.isbn() == ob2.isbn()) cout << ob1 + ob2 << endl;
   else {
     cerr << "inputs have to have the same ISBN\n";
     return -1;}

//E1.22 Write a program that reads several transactions for the same ISBN.
//Write the sum of all the transactions that were read.
   Sales_item sum, temp5;
   cin >> sum;
   while (cin >> temp5) {
     if (temp5.isbn() == sum.isbn()){
       sum += temp5;
       cout << sum << endl;}
     else {
       cerr << "inputs have to have the same ISBN\n";
       return -1;}
   }

//E1.23 Write a program that reads several transactions and counts how many
//transactions occur for each ISBN.
//E1.24 Test the previous program by giving multiple transactions representing
//multiple ISBNs. The records for each ISBN should be grouped together.
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
   }

//E1.25 Using the Sales_item.h header from the Web site, compile and execute
//the bookstore program presented in this section.
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
   }
*/

return 0;
}
