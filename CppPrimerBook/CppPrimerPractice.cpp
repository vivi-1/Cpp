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

/*
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
*/

/*E3.2
string line;
while (getline (cin, line))
   cout << line << endl;


string word;
while (cin >> word)
   cout << word << endl;


string s1,s2;
cin >> s1;
cin >> s2;
if (s1=s2) {
   cout << "two strings are equal" << endl;
}
else {

}

string s3,s4;
cin >> s3;
cin >> s4;
if (s3 > s4) {
   cout << s3 << endl;
}

if (s3 < s4) {
   cout << s4 << endl;
}
if (s3=s4) {
   cout << "two strings are equal" << endl;
}


//E3.6
std::string str5= "Kevin";
for (auto &c : str5) cout << "now our str is " << str5 << " please enter your new characters one by one" << endl && cin >> c;
cout << "now our string is " << str5 << endl;

//E3.7
std::string str5= "Kevin";
for (char &c : str5) cout << "now our str is " << str5 << " please enter your new character one by one" << endl && cin >> c;
cout << "now our string is " << str5 << endl;

string word;
cin >> word;
for (char &c : word){
	c = 'X';
}
cout << word << endl;

//E3.8
//while loop
string word, temp;
cin >> word;
temp = word;
int n=0;
while (n < word.size()) {
	word[n] = 'X';
	n++;
	cout << n <<endl;
}
cout << "while: " << word << endl;

//tranditional for loop
word = temp;
for (int i = 0; i < word.size(); i++) {
	word[i] = 'X';
	cout << i << endl;

}
cout << "tranditional for: " << word << endl;


string s;
cout << s[0] << "s is:" << s << ";haha"<< endl; //doesn't give error but s will not cout anything
cout << s[1] << "s1 is:" << s << ";haha"<< endl; //


//E3.9 It is invalid because of undefined behavior but it won't give an error if you run it . s is not initiated.

//E3.10
string phrase, newPhrase;
int i=0;
getline(cin, phrase);
for (int n=0; n < phrase.size(); n++){
	//if (!ispunct(phrase[n])) newPhrase += phrase[n]; //Method 1
	if (ispunct(phrase[n])) {
		phrase.erase(phrase.begin()+n);
		n--;
	} //Method 2
	cout << n << endl;
}
	cout << phrase << ":is phrase" << endl << newPhrase << ": is newphrase" <<endl;

//E3.11
The range for loop is legal (note that the statement in {} is commented. If it was not commented we need to think of cases that c value was changed in the statement.)
c is a reference to a constant character


//E2.12
// (a) legal (b) ilegal, type doesnt match (c)legal

//E3.13
   (a) vector <int> v1; no element, no value;
   (b) vector <int> v2(10);10 elements, their values are all 0;
   (c) vector<int> v3(10, 42); 10 elements, their values are all 42s;
   (d) vector<int> v4{10}; 1 element, value is 10;
   (e) vector<int> v5{10, 42}; 2 elements, values are 10 and 42;
   (f) vector<string> v6{10}; 10 elements, values are empty strings;
   (g) vector<string> v7{10, "hi"}; 10 elemtns, values are all "hi";

//E3.14
vector <int> ivec;
int num;
vector <string> svec;
while (cin >> num) {
   if (num == -1) {
      break;
   }
   ivec.push_back(num);
}
for (auto i : ivec) {
	cout << i << endl;
}


vector <string> svec2;
//while (cin >> istring) {
 //  svec.push_back(istring);
//}
for (string istring; cin>>istring; svec2.push_back(istring)){
   if (istring == "stop") {
      break;
   }
}

for (auto j : svec2) {
   cout << j << endl;
}


// E3.16
vector<int> v1;
vector<int> v2 (10);
vector<int> v3 (10, 42);
//vector<int> v4 {10};
vector<int> v4 (1,10);
vector<int> v5{10, 42};
vector<string> v6 {10};
vector<string> v7 {10, "hi"};

vector<vector <int> > vi_total{v1,v2,v3,v4,v5};
vector<vector <string> > vs_total{v6,v7};
vector<int> vs;
vector<int> :: size_type sz_i;
vector<string> :: size_type sz_s;
cout << vi_total.size() << endl;


for (auto i : vi_total) {
   sz_i = i.size();
   vs.push_back(sz_i);
   for (auto j : i) {
      cout << j << "is in this vector" << endl;
   }
}

for (auto i : vs) {
   cout << i <<endl;
}

//E3.17
vector<string> word;
string values;
while (cin >> values && values != "end" ) {
  word.push_back(values);
}

for (auto &i : word) {
  for (auto &j : i) {
    j=toupper(j);
  }
}

for (auto n : word) {
  cout << n << " ";
}

cout << endl;

//E3.18
vector<int> ivec(10);
ivec[0] =42;
for (auto i : ivec) {
  cout << i << endl;
}

//E3.19
//Method1
vector <int> ivec1(10, 42);
//Method2
vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
//Methods3
vector<int> ivec3(10);
for (auto &i : ivec3) {
  i = 42;
}



//3.20
//Read a set of int into vector, print sum of adjecent elements
//print the sum of 1 and last elements followed by second and second to last
//and so on.

vector<int> ivec3;
int values;
while (cin >> values) {
  ivec3.push_back(values);
}

for (auto i : ivec3) {
  cout << i << " ";
}
cout << endl;


//print sum of adjecent elements
for (int s=0; s< ivec3.size()-1;s++) {
  cout << ivec3[s]+ivec3[s+1] << endl;
}
int n=ivec3.size();
for (int s=0; s< n/2;s++) {
  cout << s << " " << n << " " << n-s-1  << " " << ivec3[s] + ivec3[n-1-s] << endl;
}

if (n%2 !=0) {
  cout << ivec3[n/2] << endl;
}

//E3.21 size and contents
vector<int> v1;
vector<int> v2 (10);
vector<int> v3 (10, 42);
//vector<int> v4 {10};
vector<int> v4 (1,10);
vector<int> v5{10, 42};
vector<string> v6 {10};
vector<string> v7 {10, "hi"};

vector<vector <int> > vi_total{v1,v2,v3,v4,v5};
vector<vector <string> > vs_total{v6,v7};
vector<int> vs;
int vs_i;

// check the size in vi_total;
for (auto i = vi_total.begin(); i!=vi_total.end(); ++i) {
  vs_i = (*i).size();
  vs.push_back(vs_i);
  for (auto x = (*i).begin(); x!=(*i).end(); ++x) {
    cout << *x << " ";
  }
  cout << endl;
}
cout << endl;

for (auto j = vs.cbegin(); j!=vs.cend(); ++j) {
  cout << *j << " ";
}
cout << endl << endl;

//E3.22
string input;
vector<string> paragraph;
int j=0;
while (getline (cin, input) && input!="end") {
  paragraph.push_back(input);
  j++;
  cout << "original input of the " << j << " line is: " << input << endl;
}
for (auto vi = paragraph.begin(); vi!=paragraph.end() && !(*vi).empty(); ++vi) {
 for (auto i: *vi) {
    i=toupper(i);
    cout << i;
  }
}


//E3.23
vector<int> vi(10);
int input;
cout << vi.size() << endl;
int i=0;
while (cin >>input) {
  vi.push_back(input);
  i++;
  cout << i << " elements have been added" << endl;
  if (i == 10) {
    break;
    cout << "vector's full now" << endl;
  }
}

for (auto j=vi.begin(); j!=vi.end(); ++j) {
  cout << "original number is " << endl;
  cout << *j << " ";
  cout << endl;
  (*j)*=2;
  cout << "after changing: " << *j << " ";
  cout << endl;
}

//E2.24
vector<int> ivec3;
int values;
while (cin >> values) {
  ivec3.push_back(values);
}
cout << "the sum of the adjecent elements are " << endl;

//print sum of adjecent elements
auto i = ivec3.begin();
while (i!= ivec3.end()-1) {
  cout << *i + *(i+1) << " ";
  cout << endl;
  i+=1;
}

//print the sum of first and last elements followed by second and second to last
//and so on.
auto i2 = ivec3.begin(), j = ivec3.end()-1, mid = ivec3.begin()+(j-i2+1)/2;
auto mid2 = ivec3.begin() + (ivec3.end()- ivec3.begin())/2;
cout << *mid << " is the mid point while mid2 point is " << *mid2 << endl;
cout << "the sum of two ends elements are: " << endl;

while (i2 < mid && j>mid) {
  cout << *i2 + *j << " ";
  i2 += 1;
  j-=1;
}

if (ivec3.size() %2 != 0) cout << endl << "vec has odd number of elements, mid point is " << *mid << endl;
else cout << *mid + *(mid-1) << endl;

*/

//E2.25
vector<unsigned> scores(11,0);
unsigned grade;
while (cin >> grade) {
  if (grade <= 100) ++scores[grade/10];
}

return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.

}
