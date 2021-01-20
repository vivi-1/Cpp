/*
This is CppPrimerPractice for the C++ primer 5th edition
By Wei Wang, link: https://github.com/vivi-1/Cpp.git
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



//E2.25
  vector<unsigned> scores(11,0);
  unsigned grade;

//subscription method
  while (cin >> grade) {
    if (grade <= 100) ++scores[grade/10];
  }


vector<unsigned> scores(11,0);
unsigned grade;
// iterator method
  while (cin >> grade) {
    cout << "grade/10 is: " << grade/10<<endl;
    if (grade <=100) {
      auto i = scores.begin() + grade/10;
      (*i) += 1;
      cout << "the position number is: " << *i << endl;
    }

  }


//E3.26 In the binary search program on page 112, why did we write mid=beg+(end-beg)/2; instead of mid=(beg+end) /2;?

// We can only apply the subtraction between the two iterators not additions.
// beg + end is illegal.
//And (end-beg)/2 makes it a difference_type instead of an iterator.

//E3.27 Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.

//unsigned buf_size = 1024;
//int ia[buf_size];   // illegal, The dimension value must be a constant expression.
//int ia[4 * 7 - 14]; // legal, 4*7-14 is a literal
//int ia[txt_size()]; // illegal, txt_size() is not a constant expression, it returns a int instead of constant int;
//char st[11] = "fundamental";  // illegal, the string's size is 12 and the character array has to have a null position at the end so the dimension of st has to be at least 12.

//E3.28 What are the values in the following arrays?
//string sa[10];
//int ia[10];

//int main() {
  //string sa2[10];
  //int ia2[10];
//}

//std::string isn't a build-in type. The initializer will set it empty, so sa and sa2 has 10 empty strings.
// int is a build-in  type. ia is not in function body, will be initialized to 0. ia2 is in the function body so its undefined.


//E3.29 Drawbacks of arrays compared to vectors:
// Array is less flexible, can't add elements or substract elements;
//You have to know the dimensions of array you are defining. It has to define from constant expression or constant values
//It's complicated to define or understand pointers or references of arrays;
//arrays can't be copied or re-assigned;
// When defining a character array from a string, need to leave space for null at the end;
// array runs at compile time while vector at runs time so arrays runs faster than vectors;
//



//E3.30: Identify the indexing errors in the following code:

	//constexpr size_t array_size = 10;
	//int ia[array_size];
	//for (size_t ix = 1; ix <= array_size; ++ix)
  // will trigger buffer overflow; shoudl be: for (size_t ix = 0; ix < array_size; ++ix)
	//ia[ix] = ix;



//E3.31 Write a program to define an array of ten ints. Give each element the
//same value as its position in the array.

//Method 1
int arr[10] = {0,1,2,3,4,5,6,7,8,9};
for (auto i :arr) cout << i << " ";
cout << endl;

int arr2[10];
for (size_t ix = 0; ix < 10; ++ix) {
  arr2[ix] = ix;
  cout << "arr2 array is " << ix << " " << arr2[ix] << endl;
}

//E3.32: Copy the array you defined in the previous exercise into another array.
//Rewrite your program to use vectors.
int arr3[10];
  for (size_t ix3 = 0; ix3 < 10; ++ix3) {
    arr3[ix3] = arr2[ix3];
    cout << "arr3 array is "<< ix3 << " " << arr3[ix3] << endl;
  }

//Create a vector that has 10 elemetns and each element is their position
vector <int> vec1{0,1,2,3,4,5,6,7,8,9};
vector <int> vec2(10);

int j = 0;
for (auto i = vec2.begin(); i!=vec2.end(); ++i) {
  *i = j;
  cout << j << " " << *i << endl;
  ++j;
}

//Copy the vetor vec2 into vec3.
vector<int> vec3 = vec2;
for (auto i = vec3.begin(); i!=vec3.end(); ++i) {
  cout << *i << " ";
  cout << endl;
}



// E3.33: What would happen if we did not initialize the scores array in
//the program on page 116?
// It still will work; it will defualt initialize to 0 if score is a global
//object (outside of any function); it will be undefined if score is a local
//object (inside of any function);


// E3.34: Given that p1 and p2 point to elements in the same array, what does the
// following code do? Are there values of p1 or p2 that make this code illegal?
// p1 += p2-p1;
// the meaning of the equations is: find the distance between p2 and p1 and add it
// to p1, which moves p1 to position p2. It is always legal;

// E3.35  Using pointers, write a program to set the elements in an
// array to zero.
int arr[10] = {0,1,2,3,4,5,6,7,8,9};

//Method 1
int *p = arr, *e = arr + 10, i = 0; //equals to int *p= &arr[0];
while (p < e) {
  *p = 0;
  cout << i << " " << *p << endl;
  ++p;
  ++i;
}

//Method 2
int *beg = begin(arr), *last = end(arr), j=0;
while (beg != last && *beg>=0) {
  *beg = 0;
  ++beg;
  ++j;
  cout <<j << " "  << beg << " " << *beg << endl;
}

//Exercise 3.36: Write a program to compare two arrays for equality. Write a
//similar program to compare two vectors.
// compare the size of two arrays and if they are the same do element comparison
auto n1 = end(arr1) -begin(arr1), n2 = end(arr2) -begin(arr2);
if (n1 = n2) {
  size_t i = 0;
  while (i != n1) {
    if (arr1[i] == arr2[i]) cout << "same element at position  " << i << endl;
    else {
      cout << "elements at " << i << " are different" << endl;
      break;
    }
    ++i;
  }
}

else cout << "they have different size" << endl;

// compare two vectors
if vec1 == vac2 cout << "vec1 and vec2 are equal to each other" << endl;
else cout << "vec1 and vec2 are equal to each other" << endl;

//E3.37 There's not null in the end, so the program will print what cp is pointing
 to, one by one (which are "hello") until it finds the null character.


//E3.38 In this section, we noted that it was not only illegal but meaningless
//to try to add two pointers. Why would adding two pointers be meaningless?
//Because pointers hold the values of the objects that they are pointing to. if
// they are pointing to two objects, that means they are holding addresses of two
// objects separately. Adding those addresses doesn't make sense.


//E3.39
string s1, s2;
getline(cin,s1);
  cout << "s1 is " << s1 << endl;

getline(cin,s2);
  cout << "s2 is " << s2 << endl;

if (s1 == s2) {
  cout << "same" << endl;
}
else cout << "different" << endl;

////
char cts1[] = "hello my name is kevin", cts2[] = "hello my name is wei";

if (strcmp(cts1, cts2) == 0) {
  cout << "they are the same" << endl;
}
else {
  if (strcmp(cts1, cts2) < 0) {
  cout << "2nd string is bigger than the 1st one" << endl;
  }
  else cout << "2nd string is smaller than the 1st one" << endl;
}

// E3.40
char cts3[22], cts4[46];

strcpy(cts3, cts2);
strcat(cts3, cts1);
for (auto i : cts3) cout << i << " ";
cout << endl;

strcpy(cts4, cts1);
strcpy(cts4, cts2);



// E3.41 E3.42
int arr_int[10] = {1,2,3,4,5,6,7,8,9,10};
vector <int> vec_int(begin(arr_int), end(arr_int));
for (auto i : vec_int) cout << i << endl;
int size_vec = vec_int.size();

int arr_cp[size_vec];
int i=0;
while (i != 10) {
  arr_cp[i] = vec_int [i];
  cout << arr_cp[i] << " ";
  i++;
}


//E3.43 & E3.45
constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt];
for (size_t i = 0; i != rowCnt; ++i) {
  for (size_t j = 0; j != colCnt; ++j) {
    ia[i][j] = i*colCnt + j;
  }
}

//range for loop
for (const auto &row : ia) {
  for (const auto &col: row) {
    cout << col <<" ";
  }
  cout << endl;
}
cout << endl << endl;

//ordinary for loop - subscription
for (size_t i = 0; i != rowCnt; ++i) {
  for (size_t j = 0; j != colCnt; ++j) {
    cout << ia[i][j] << " ";
  }
  cout << endl;
}
cout << endl << endl;

//ordinary for loop - pointers

for (auto p = ia; p != ia+rowCnt; ++p) {
  for (auto q = *p; q != *p + colCnt; ++q) {
    cout << *q << " ";
  }
  cout << endl;
}
cout << endl << endl;


//E3.44
//ordinary for loop - type alias pointers
using int_array = int[4];
typedef int int_array[4];
for (int_array *p = ia; p != ia+rowCnt; ++p) {
  for (int *pp = *p; pp != *p+colCnt; ++pp) {
    cout << *pp << " ";
  }
  cout << endl;
}
cout << endl << endl;



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
  (! (i%2)) ? (i*=1) : (i*=2);
  cout << i << endl;
}


//E4.22
//Use conditional operators
int grade21;
string finalgrade1;
while (cin >> grade1) {
  finalgrade1 = (grade1 > 90) ? "high pass"
                          : (grade1 >60 && grade1 < 75) ? "low pass"
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
//finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";


//E4.25
//'q' has the bit pattern 01110001 (8 bit char) ~'q' << 6 32 bit int

// ~q = 1111111111111111 1110 0011 1000 0000

//E4.26
// On 16 bit machine, int minimun size is 2 bytes which is 16bits. On 32 bit
// machine it can be 2 or 4 bytes which is 16 or 32 bits. So the code behavior
// will be undefined.


//E4.27
// ul1 = 0000000000000000000000000000011
// ul2 = 0000000000000000000000000000111
//(a) ul1 & ul2 = 0000000000000000000000000000011 or 3
//(b) ul1 | ul2 = 0000000000000000000000000000111 or 7
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
cout << sizeof(p)/sizeof(*p) << endl; // size needed to hold a pointer (can be 8bytes or 4bytes)/size needed to hold an int (4bytes);


//E4.30
// (a) sizeof (x) + y // precedence rank: "sizeof" > "binary +"

// (b) sizeof (p->mem[i]) // precedence rank: "->" = "[]subscript" > "sizeof"

// (c) sizeof (a) < b // precedence rank: "sizeof" > "less than <"

// (d) sizeof (f()) // precedence rank: "function() " > "sizeof";

int a = 10, b = 20; cout << sizeof (a<b) << endl; cout << sizeof (a+b) << endl;


//E4.31 prefix ++ix, --cnt return (ix+1) and (cnt+1) after each of loop is run, while the ix++ and cnt-- return ix and cnt and then increment or decrement;

//E4.32
constexpr int size = 5; // define the size of an array
int ia[size] = {1,2,3,4,5}; // define a 5-element array containing 1-5
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) {
  cout << ix << " " << *ptr << " " << ptr << endl;
  //ptr is pointer to ia, ix is from 0-4, ptr points to position 0-4 in ia, after each loop, +ix,+ptr within the conditioned range;
}



//E4.33 someValue ? ++x, ++y : --x, --y
//precedence rank: "prefix ++" = "prefix --" > "?: conditional" > ", comma expr"
//the expression is equal to (someValue ? (++x), (++y) : (--x)), (--y)
// if someValue is true, ++x and ++y and after increment, --y, so y will not increment at all;
// if someValue is false, --x, no matter if somevalue is true or false --y all the time

//E4.34
bool flag; char cval; short sval; unsigned short usval;
int ival; unsigned int uival; long lval; unsigned long ulval;
float fval; double dval;
// (a) if (fval) //fval transform into bool
// (b) dval = fval + ival; //ival transform into float and the sum of (fval + ival) will transform into double and add to dval
// (c) dval + ival * cval; // cval into int, and (ival * cval) will transform into double and add to dval


//E4.35
bool flag; char cval; short sval; unsigned short usval;
int ival; unsigned int ui; long lval; unsigned long ulval;
float fval; double dval;
// (a) cval = 'a' + 3; // 'a' is converted into int and add to 3, then the result is converted to char
// (b) fval = ui - ival * 1.0; //ival into double and times 1.0, later it depends on ui and double size: for example: if unsigned int is bigger than double, the result converted into unsigned int and be substracted by ui. Then the result is converted into float
// (c) dval = ui * fval; // Conversion depends on the size of unsigned int and float, in the end the result will be converted into double;
// (d) cval = ival + fval + dval; // ival convert into float, addition to fval and convert into double, added to dval, and then convert into int, and convert into char.


//E4.36 Assuming i is an int and d is a double write the expression i *= d so
// that it does integral, rather than floating-point, multiplication.
int i = 314;
double d = 3.1415926;
cout << i << " " << d << " " << i*d <<" " << i*static_cast<int>(d) << endl;

//E4.37 int i;  double d;  const string *ps;  char *pc;  void *pv;
// (a) pv = (void*)ps; pv = const_cast<string*>(ps)

// (b) i = int(*pc); i = static_cast<int>(*pc)

// (c) pv = &d; // no need to cast or     pv = static_cast<void*>(&d);

// (d) pc = (char*) pv; pc = reinterpret_cast<char*> pv;


// E4.38: Explain the following expression: double slope = static_cast<double>(j/i);
//if i and j are both int, then j/i will be int, and then converted into double and copied into slope


// E5.1 null statement is an empty statement which is a single semicolon; we can
// use it where the language requires a statement but the program's logic does not
// such as when a loop's work can be done within its condition. for example:
// "while (cin >> s && s != sought) ; "


// E5.2 A block contains compound statements which are a sequence of statements
// (possibly empty) and declarations surounded by a pair of curly braces.
// A block is a scope.

// E5.3
//original while loop
int ival = 0, sum = 0;
while (ival <= 10) {
  sum += ival;
  ++ival;
}
std::cout << sum << " " << ival << '\n';

//Modified while loop
ival = 0, sum = 0;
while (ival <= 10) sum += ival++;
std::cout << sum << " " << ival << '\n';

//Using comma operand

for (ival = 0, sum = 0; ival <= 10; sum += ival, ++ival);
std::cout << sum << " " << ival << '\n';


// E5.4
// (a) while (string::iterator iter != s.end()) { .... }
//    The intention of the original code is defining the iterator to read
//    the strings, and while the iterator is not hitting the end of the string,
//    do the statements in the curly braces. However, iter should be initialized
//    before being used in the condition. Correction:
//      string::iterator iter = s.begin();
//      while (iter != s.end()) { .... }

// (b) while (bool status = find(word)) { .... }
//     if (!status) { .... }

// Since status is initialized in the while loop, it is a in-scope-variable that
// can't be used outside of the while loop and can't be re-assigned in the if loop
// later. Correction:
// bool status = find(word);
// while (status = find(word)) { .... }
// if (!status) { .... }


// E5.5: Using an if–else statement, write your own version of the program
// to generate the letter grade from a numeric grade.

const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
int grade;
string lettergrade;
while (cin >> grade) {
  if (grade == 100) cout << scores[5] << endl;
  else {
    if (grade < 60) cout << scores[0] << endl;
    else {
      if (grade %10 < 3 ) cout << scores[grade/10-5] << "-" << endl;
      else if (grade %10 > 7 ) cout << scores[grade/10-5] << "+" << endl;
      else cout << scores[grade/10-5] <<endl;
    }
  }
}



//E5.6: Rewrite your grading program to use the conditional operator
//(§ 4.7, p. 151) in place of the if–else statement.
const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
int grade;
string lettergrade;
while (cin >> grade) {
  (grade == 100) ? cout << scores[5] << endl
              : (grade < 60) ? cout << scores[0] << endl
                : (grade %10 < 3) ? cout << scores[grade/10-5] << "-" << endl
                  : (grade %10 > 7) ? cout << scores[grade/10-5] << "+" << endl
                    : cout << scores[grade/10-5] <<endl;
}



//E5.7 Correct the errors in each of the following code fragments:
//(a) if (ival1 != ival2)
//    ival1 = ival2
//else ival1 = ival2 = 0;

//should change the indentation and add semicolon
//if (ival1 != ival2)
//    ival1 = ival2;
//else ival1 = ival2 = 0;

//(b) if (ival < minval)
//    minval = ival;
//    occurs = 1;
// should use a block or curly braces to hold more than 1 statements:
//if (ival < minval) {
//    minval = ival;
//    occurs = 1;}

//(c) if (int ival = get_value())
//    cout << "ival = " << ival << endl;
// if (!ival)
//    cout << "ival = 0\n";
// should change the indentation of the second if statement to match the first if statement
// should use a else if instead of if to use ival in the scope:
//if (int ival = get_value())
//    cout << "ival = " << ival << endl;
//else if (!ival)
//    cout << "ival = 0\n";


//(d) if (ival = 0)
//    ival = get_value();
// the condition for the if statement is always true since its always assigning
// 0 to ival. should change into "if (ival == 0) ival = get_value()" or
// "if (!ival) ival = get_value()"


//E5.8 What is a “dangling else”? How are else clauses resolved in C++?
// When there are too many if for the else, then the program wouldn't know to Which\
// if a given else belongs. This problem is called dangling else. In C++ the
//ambiguity is resolved by specifying that each else is matched with the
// closest preceding unmatched if. We can control the execution path with curly braces
*/




return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.

}
