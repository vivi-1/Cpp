/*
This is CppPrimerPractice for the C++ primer 5th edition
http://mirrors.concertpass.com/gcc/releases/ to check release of new C++ versions;
..It opens slow..
*/
#include<iostream>
#include "Sales_item.h"
#include<vector>
using namespace std;

int main()
{ /*
  //E4.1   multiply and division have higher precedence than addition, so the answer is 105

  //E4.2
  // * vec.begin()   =  * (vec.(begin()))
  //"*" as dereference are lower, "." as member selector are the same level with
  //"()" as function call. Due to associativity, the code should be read left to right

  // * vec.begin() +1 =  (* (vec.begin())) +1
  //  "+"as adding rvalues, has the lowest precedence. So "+1" is added after dereference.


  //E4.3
  //It is an acceptable trade-off for professional programmers, who want the code
  // to be more effecient, will think thouroughly before output things and save time for big program.
  // As beginners, it can be hard to pick up because of lack of thinking, but every coder should develop a
  // great habit for coding just to prevent any unexcepted errors.




  //E4.4 ((12/3) *4) + (5*15) + ((24 % 4)/2) =91

  //E4.5
  // (a) -30 * 3 + 21 / 5 = -86;
  // (b) -30 + 3 * 21 / 5 = -18;
  // (c) ((30 / 3) * 21) % 5 = 0;
  // (d) -30 / 3 * 21 % 4 = -2;


  //E4.6
  int number;
  cout << "please enter a number here: " << endl;
  cin >> number;
  if (number%2 == 0) {
    cout << "even" << endl;
  }
  else cout << "odd" << endl;



  //E4.7 Overflow happens when a value is computed that is outside the range of values the type can represent
  short short_value = 32767; // max value if shorts are 16 bits
  short_value += 1; // this calculation overflows
  cout << "short_value: " << short_value << endl;  //short_value: -32768


  short short_value2 = -32768;
  short_value2 -= 1;
  cout << "short_value2: " << short_value2 << endl; // short_value2: 32767

  int int_value    = -2147483648;
  cout << "int_value: " << int_value - 1 << endl; // int_value: 2147483647

  //E4.8 The logical && and || operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as short-circuit evaluation.

  // logical && : the second operand is evaluated if and only if the left side is true.
  // logical || : the second operand is evaluated if and only if the left side is false
  // equality operators == : undefined.


  //E4.9
  // if (cp && *cp): if cp is not a null pointer, which means if cp containing a valid address is true, as well as what cp is pointing to is not null character '\0'.

  //E4.10
  int input;
  while (cin >> input && input != 42) {
    cout << "input is not 42" << '\n';
  }

  // E4.11
  // Method1
  int a, b, c, d, temp1,temp2,temp3;
  cout << "please input a: ";
  cin >> a;
  cout << "a is " << a << ", please input b: ";
  while (cin >> temp1) {
    if (!(a > temp1)) {
      cout << "a is " << a << " please input b smaller than a please: ";
    }
    else {
      b=temp1;
      cout << "b is " << b << " please input c: " ;
      while (cin >> temp2) {
        if (!(b > temp2)) {
          cout << "b is " << b << " please input c smaller than b please: ";
        }
        else {
          c=temp2;
          cout << "c is " << c << " please input d: ";
          while (cin >> temp3) {
            if (!(c > temp3)) {
              cout << "c is " << c << " please input d smaller than c please: ";
            }
            else {
              d=temp3;
              cout << a <<" " << b << " " << c << " " << d << " " <<endl;
            }
          }
        }
      }
    }
  }


  // Method2
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a >b && b >c && c>d) {
    cout << a <<" " << b << " " << c << " " << d << " " <<endl;
  }
  else cout << "please make sure that a>b>c>d";


  // E4.12  i != j<k  means i != (j<k)
  // (a) if j<k is true, then it will return a bool, true, and converts into 1 to compare with i, so
  // in this case, it means i!=1; (b) if j<k is not true, then it will return a bool, true, and transformed into 0 to compare with i, so finally it  means i != 0;


  //E4.13
  //(a) d is 3.0, i is 3
  //(b) d is 3.5 and i is 3


  //E4.14
  //if (42 = i) gives an error because left-hand operand is rvalue. it is not assignable
  //if (i = 42)  // i is assigned the value of 42. This  statement is always true.
  // if you want to say if i is 42, then it should be written as if (i==42).

  //E4.15
  // Because the types of dval, ival and pi are not convertible
  //could be: dval = ival = *pi = 0;
  //or: dval = ival = 0; pi = 0;
  //or: dval=0; ival = 0; pi = 0;

  //E4.16
  // (a) if (p = getPtr() != 0)  equals to   if (p = (getPtr() != 0)), the != has higher precedence than =
  // could be if ((p = getPtr()) != 0) meaning if p returned from getPtr is not 0;
  //(b) if (i = 1024) meaning if i=1024 statement is true. if you want to compare
  //i with 1024, it should be if(i == 1024)

  //E4.17 prefix ++i returns a changed value (i+1) as a result, postfix i++ returns
  // a copy of the unchanged value(i) as a result, then plus 1 to it.Both require an lvalue operands. The prefix returns an lvalue and the postfix returns rvalue.

  //E4.18 it will skips the first positive value and it will not stop at the last >= 0 value, which means the 1st negative value after the last postive element or the one past the end will be printed in the end.

  //E4.19 Given that ptr points to an int, that vec is a vector<int>, and that
  // ival is an int, explain the behavior of each of these expressions. Which,
  // if any, are likely to be incorrect? Why? How might each be corrected?

  // (a) ptr != 0 && *ptr++
  //during evaluation, its true that pointer is not null and points to a not empty character, returns the value the ptr points to, and increment ptr

  // (b) ival++ && ival meaning return current ival and then increment ival by 1 && ival is still the original value
  // if ival++ is true which means ival is not 0, then evaluate the ival which should also be true. If false, both are false.

  // (c) vec[ival++] <= vec[ival]
  // ival++ returns ival, but increment 1 after being evaluated. it will gives an undefined result because ival can't present on both sides of the operand.
  // correction: vec[ival] <= vec[ival+1]; ++ival;

  //E4.21
  vector<int> vi;
  int input;
  cout << vi.size() << endl;
  int i=0;
  while (cin >>input) {
    vi.push_back(input);
    i++;
    cout << i << " elements have been added" << endl;
    if (i == 10) {
      break;
    }
  }
  cout << "vector's full now" << endl;

  for (auto &i:vi) {
    cout << i << " ";
    (! (i%2)) ? (i*=2) : (i*=1);
    cout << i << endl;
  }


  //E4.22
  //Use conditional operators
  int grade21;
  string finalgrade1;
  while (cin >> grade1) {
    finalgrade1 = (grade1 > 90) ? "high pass"
                            : (grade1 >60 && grade1 < 70) ? "low pass"
                            : (grade1 < 60) ? "fail" : "pass";
    cout << finalgrade1 << endl;
  }

  //Use if statements
  int grade2;
  string finalgrade2;
  while (cin >> grade2) {
    if (grade2 > 90) finalgrade2 = "high pass" ;
    else if (grade2 > 60 && grade2 <70) finalgrade2 = "low pass" ;
    else if (grade2 < 60) finalgrade2 = "fail" ;
    else finalgrade2 = "pass" ;
    cout << finalgrade2 << endl;
  }

  //E4.23
  string s = "word";
  string p1 = s + ((s[s.size()-1] == 's') ? " " : "s");
  cout << s << " " << p1 << endl;

  //E4.24
  //


  //E4.25
  //'q' has the bit pattern 01110001 (8 bit char) ~'q' << 6 32 bit int

  // ~q = 111111111111111111  10001110 000000

  //E4.26
  // On 16 bit machine, int minimun size is 2 bytes which is 16bits. On 32 bit machine it can be 2 or 4 bytes which is 16 or 32 bits. So the code behavior will be undefined.


  //E4.27
  // ul1 = 0000000000000000000000000000111
  // ul2 = 0000000000000000000000001111111
  //(a) ul1 & ul2 = 0000000000000000000000000000111 or 3
  //(b) ul1 | ul2 = 0000000000000000000000001111111 or 7
  //(c) ul1 && ul2  true or 1
  //(d) ul1 || ul2  true or 1

  //E4.28
  cout << "bool\t" << sizeof(bool) << endl;
  cout << "char\t" << sizeof(char) << '\n';
  cout << "unsigned char\t" << sizeof(unsigned char) << endl;
  cout << "int\t" << sizeof(int) << '\n';
  cout << "unsigned int\t" << sizeof(unsigned) << endl;
  cout << "double\t"  << sizeof(double) << '\n';
  cout << "nullptr\t" << sizeof(nullptr) << endl;


  //E4.29
  int x[10];   int *p = x;
  cout << sizeof(x)/sizeof(*x) << endl; // 10ints (40bytes)/element size (4bytes) = numbers of elements which is 10;
  cout << sizeof(p)/sizeof(*p) << endl; // size needed to hold a pointer (8bytes)/size needed to hold an int (4bytes);
  */


return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.

}
