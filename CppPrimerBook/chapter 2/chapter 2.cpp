/*
This is CppPrimerPractice for the C++ primer 5th edition
*/
#include<iostream>
using namespace std;

int main() 
{// E2.1 short <= int <= long <= long long; unsigned >=0  signed can be negative or positive; float is shown in one word (32bits, 4 bytes), double in two words (64bits, 8bytes)
// E2.2 double or long double, which has more precision instead of float

/*
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

E2.11d definition, definition, declaration,

// int double = 3.14; invalid
int _; //valid
// int catch-22; invalid
// int 1_or_2 = 1;  invalid, can only start with an underscore or a letter not a number
double Double = 3.14;  // Capitalized sensitive

E2.13 j=100
E2.14 i=100 sum=45

int val;
int *p = &val;
cin >> *p;
cout << *p <<endl;
cin >> val;
cout << val << " " << *p <<endl; //E2.18

pointer vs references: 
(1)pointer doesn't need to be initialized when its defined;
(2) pointer is an boject while reference is just an address;
(3) pointer are not limited to one object while reference has to be limited to one;

int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
cout << *p1 << endl;
cout << i << endl;


if (p) means if the pointer p is not null.
if (*p) means if the object pointed by the pointer is not false (which means the object is not null or zero etc.).

// the value of a pointer, the value of the object the pointer points



int i =10;
int *j = &i;
int k = 3;
*j = 20;
cout << i <<" " << *j << endl;

*j = k;
cout << *j << endl; //E2.18 Kevin answer


E2.25
(a) ip: a pointer to an int
     i: an int
     r: a ref to i
(b) i: int;  ip is a valid null pointer;
(c) ip: pointer points to an int, ip2 is an int;

E2.26
(a) illegal: needs to be initialized
(b) legal
(c) legal
(d) ++cnt is legal, ++sz is illgegal cuz constant can't be changed

int i = 42;
int &r1 = i;
const int &r2 = i;
r1 = 0;
cout << r1 << " " << r2 << endl;

E2.27
(a) int i=-1 is legal, &r=0 is illegal cuz it has to refer to an object;
(b) it is legal
(c) 1st is legal
(d) if i2 is constant its legal
(e) if i2 is constant its legal
(f) illegal, cuz reference doesn'e have this grammer
(g) if i is constant too,its legal

E2.28
(a) illegal: *const cp must be initialized
(b) illegal: *const p2 must be initialized
(c) ic must be initialized
(d) must be initialized
(e) ok

E2.29
(a) legal int equals to a constent int
(b) illegal if p3 is initialized, assign a const pointer to int p1
(c) p1=&ic illegal, p1 is int while ic is const int. 
(d) illegal: can't re-initialize 
(e) can't re-initialize const pointer
(f) legal if its inside of the declaration, ilegal if its outside of initialization

E2.30
v2 top-level const   v1 has no const
p1, v1, r1 no const
p2 low level, p3 both low and top, r2 is a reference only low


E2.31
legal, when copied into r1 which is a int, the v2 doesn't change
   illegal, low level const doesn't match
legal, can convert int to const int
    illegal:  p3 has a low-level const but p1 doesn't.
legal
*/

int val=10, val1=30;

int *pi = &val;
int **ppi = &pi;
cout << ppi <<"   " << **ppi <<"   " << pi <<"   " << *pi <<"   " << val << endl;
int &r = *pi;
int *&r2 = pi;
val = 20;
r=5;
pi = &val1;
cout << r <<"   " <<"   " << r2 <<"   " << *r2 << "   " << val << endl;

return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully. 
   
}