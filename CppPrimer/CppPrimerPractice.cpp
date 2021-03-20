/*
This is CppPrimerPractice for the C++ primer 5th edition
By Wei Wang, link: https://github.com/vivi-1/Cpp.git
*/
#include<iostream>
#include<fstream>
#include <sstream>
using std::istream;
using std::ostream;
using std::istringstream;
using std::ostringstream;

#include "Sales_item.h"
#include "Sales_data.hpp"
#include "screen.hpp"
#include "Delegating_SalesData.hpp"
#include "Chapter7_Debug.hpp"
#include "PersonInfo.hpp"
#include<vector>

using namespace std;



//E2.40 Write your own version of the Sales_data class.
struct Sales_data1 {
  string name;
  unsigned unit = 0;
  double price = 0.0;
  double revenue = 0.0;
};

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
bool is_upper(const string& input) {
  unsigned int temp = 0;
  bool result = false;
  for (auto &c : input) {
    if (isupper(c)) temp += 1;
  }
  if (temp != 0) result = true;
  return result;
}

string to_lcase(string &input) {
  for (char &c : input) c = tolower(c);
  return input;
}


//E6.21
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
  if (ptr != nullptr && (*ptr) != '\0') cout << *ptr << endl;
}

void print (const int (&arr)[2]) {
  for(auto i : arr) {
    cout << i << endl;
  }
}

//E6.27 Write a function that takes an initializer_list<int> and produces the
//sum of the elements in the list.
double sum_list(initializer_list<double> lst) {
  double result;
  for (auto beg = lst.begin(); beg != lst.end(); ++beg) result += (*beg);
  return result;
}

//E6.33 Write a recursive function to print the contents of a vector.
void print_vec(vector<string> v, vector<string>::size_type i) {
  if (i > 0) {
    cout << v[i-1] << endl;
    print_vec(v, i-1);
  }
}

//E6.42
string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;}

//E6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size(); }

//E6.46: Would it be possible to define isShorter as a constexpr? If so, do so.
//If not, explain why not.
constexpr bool isShorter2(const string &s1, const string &s2) {
    return s1.size() < s2.size(); }

//E6.47: Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that
//used recursion to print the contents of a vector to conditionally print
//information about its execution. For example, you might print the size of the
//vector on each call. Compile and run the program with debugging turned on and
//again with it turned off.

void print_vec(vector<string>::iterator beg, vector<string>::iterator end) {
    #ifndef NDEBUG
    assert(cout << ": vector size is " << end-beg << endl);
    #endif
    if(beg != end) {
      cout << *beg << endl;
      print_vec(beg+1, end);
    }
}

//E6.51
void f(int i) {
  cout << "int" << i << endl;
}

void f(double i) {
  cout << "double" << i << endl;
}

void f(int i, int j) {
  cout << "int int" << i << " " << j << endl;
}

void f(double i, double j = 3.14) {
  cout << "double double" << i << " " << j << endl;
}

//E6.55
int ad(int i, int j) { return (i+j);}
int st(int i, int j) { return (i-j);}
int mp(int i, int j) { return (i*j);}
int dv(int i, int j) { return (i/j);}

//E8.1: Write a function that takes and returns an istream&. The function should
//read the stream until it hits end-of-file. The function should print what it
//reads to the standard output. Reset the stream so that it is valid before
//returning the stream.
istream& read_until_eof(istream& is) {
  string result;
  while(!is.eof() && is >> result) {
    cout << result << " ";
  }
  cout << endl;
  is.clear();
  return is;
}

istream& read_until_eof_line(istream& is) {
  string result;
  while (getline(is, result)) cout << result << " ";
  cout << endl;
  is.clear();
  return is;
}

//E8.4
vector<string> read_line_into_vector(const string filename) {
  ifstream in(filename, ios::in);
  vector<string> result;
  if (in) {
    string temp;
    while (getline(in,temp)) result.push_back(temp);
  }
  else{
  cerr << "error in opening file: " << filename << endl;
  exit(EXIT_FAILURE);
  }
  return result;
}

//E8.5
vector<string> read_word_into_vector(const string filename) {
  ifstream in(filename, ios::in);
  vector<string> result;
  if (in) {
    string temp;
    while (in >> temp) result.push_back(temp);
  }
  else{
  cerr << "error in opening file: " << filename << endl;
  exit(EXIT_FAILURE);
  }
  return result;
}

//E8.10: Write a program to store each line from a file in a vector<string>.
//Now use an istringstream to read each element from the vector a word at a time.
vector<string> read_sstream_into_vector(ifstream& filename) {
  vector<string> result;
  if(filename) {
    string line, word;
    while (getline(filename, line)) {
      istringstream str(line);
      while (str >> word) {
        result.push_back(word);
        cout << word << " ";
     }
     cout << endl;
    }
      cout << "eof\n";
  }
  return result;
}


int main() {/*
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

//E2.11d definition, definition, declaration,

// int double = 3.14; invalid
//int _; //valid
// int catch-22; invalid
// int 1_or_2 = 1;  invalid, can only start with an underscore or a letter not a number
//double Double = 3.14;  // Capitalized sensitive

//E2.13 j=100
//E2.14 i=100 sum=45

int val;
int *p = &val;
cin >> *p;
cout << *p <<endl;
cin >> val;
cout << val << " " << *p <<endl; //E2.18

//pointer vs references:
//(1)pointer doesn't need to be initialized when its defined;
//(2) pointer is an boject while reference is just an address;
//(3) pointer are not limited to one object while reference has to be limited to one;

int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
cout << *p1 << endl;
cout << i << endl;

//if (p) means if the pointer p is not null.
//if (*p) means if the object pointed by the pointer is not false (which means
//the object is not null or zero etc.).

// the value of a pointer, the value of the object the pointer points


int i =10;
int *j = &i;
int k = 3;
*j = 20;
cout << i <<" " << *j << endl;

*j = k;
cout << *j << endl; //E2.18 Kevin answer


//E2.25
//(a) ip: a pointer to an int
//     i: an int
//     r: a ref to i
//(b) i: int;  ip is a valid null pointer;
//(c) ip: pointer points to an int, ip2 is an int;

//E2.26
//(a) illegal: needs to be initialized
//(b) legal
//(c) legal
//(d) ++cnt is legal, ++sz is illgegal cuz constant can't be changed

//int i = 42;
//int &r1 = i;
//const int &r2 = i;
//r1 = 0;
//cout << r1 << " " << r2 << endl;

//E2.27
//(a) int i=-1 is legal, &r=0 is illegal cuz it has to refer to an object;
//(b) it is legal
//(c) 1st is legal
//(d) if i2 is constant its legal
//(e) if i2 is constant its legal
//(f) illegal, cuz reference doesn'e have this grammer
//(g) if i is constant too,its legal

//E2.28
//(a) illegal: *const cp must be initialized
//(b) illegal: *const p2 must be initialized
//(c) ic must be initialized
//(d) must be initialized
//(e) ok

//E2.29
//(a) legal int equals to a constent int
//(b) illegal if p3 is initialized, assign a const pointer to int p1
//(c) p1=&ic illegal, p1 is int while ic is const int.
//(d) illegal: can't re-initialize
//(e) can't re-initialize const pointer
//(f) legal if its inside of the declaration, ilegal if its outside of initialization

//E2.30
v2 top-level const   v1 has no const
p1, v1, r1 no const
p2 low level, p3 both low and top, r2 is a reference only low

//E2.31
legal, when copied into r1 which is a int, the v2 doesn't change
   illegal, low level const doesn't match
legal, can convert int to const int
    illegal:  p3 has a low-level const but p1 doesn't.
legal




//E2.39 Compile the following program to see what happens when you forget the
//semicolon after a class definition. Remember the message for future reference.
//error: expected ';' after struct

//E2.40 Write your own version of the Sales_data class.
// struct Sales_data1 {
//   string name;
//   unsigned unit = 0;
//   double price = 0.0;
//   double revenue = 0.0;
// };

//E2.41 Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22),
//§ 1.5.2 (p. 24), Eand § 1.6 (p. 25) (which are E1.20-25). For now, you should
//define your Sales_data class in the same file as your main function.
//replacing E1.20:
Sales_data1 itemx;
while (cin >> itemx.name >> itemx.unit >> itemx.price) {
  itemx.revenue = itemx.price * itemx.unit;
  cout << itemx.name << " " << itemx.unit << " " << itemx.revenue << endl;
}
//replacing E1.21:
Sales_data1 item1, item2;
cin >> item1.name >> item1.unit >> item1.price >> item2.name >> item2.unit >> item2.price;
if (item1.name == item2.name) {
  item1.revenue = item1.price * item1.unit;
  item2.revenue = item2.price * item2.unit;
  cout << item1.name << " " << item1.unit + item2.unit << " "
    << item1.revenue + item2.revenue << endl;
}
else cout << "two input names have to be the same" << endl;
//replacing E1.22:
Sales_data1 sum7, temp6;
cin >>  sum7.name >> sum7.unit >> sum7.price;
while (cin >> temp6.name >> temp6.unit >> temp6.price) {
  if (temp6.name == sum7.name){
    temp6.revenue = temp6.price * temp6.unit;
    sum7.revenue = sum7.price * sum7.unit;
    sum7.unit += temp6.unit;
    sum7.revenue += temp6.revenue;
    cout << sum7.name << " " << sum7.unit << " " << sum7.revenue << endl;}
  else {
    cerr << "inputs have to have the same ISBN\n";
    return -1;}
}
//replacing E1.23:
Sales_data1 Current1, item3;
if (cin >> Current1.name >> Current1.unit >> Current1.price) {
   int cnt = 1;
   while (cin >> item3.name >> item3.unit >> item3.price) {
      if (item3.name == Current.name) {
         ++cnt;
      }
      else {
         cout << Current << "occurs" << cnt << "times" << endl;
         Current.name = item3.name;
         cnt = 1;
      }
   }
}

//E2.42 Write your own version of the Sales_data.h header and use it to rewrite
//the exercise from § 2.6.2 (p. 76) which is E2.41
//Please also see Sales_data.h file
//replacing E1.20:
Sales_data item4;
while (cin >> item4) {
  item4.print_s();
}

//replacing E1.21 & E1.22:
Sales_data item5, item6;
while (cin >> item5 >> item6) {
  item5.sameaddTwo(item6).print_s();
}

//replacing E1.23:
Sales_data Current2, item7;
if (cin >> Current2) {
   int cnt = 1;
   while (cin >> item7) {
      if (item7.bookNo == Current2.bookNo) {
         ++cnt;
         cout << Current2.bookNo << "occurs" << cnt << "times" << endl;
      }
      else {
         Current2 = item7;
         cnt = 1;
         cout << Current2.bookNo << "occurs" << cnt << "times" << endl;
      }
   }
}
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



//E5.9 Use if statement to count vowels numbers from input
string input;
int cnt_a = 0, cnt_e = 0, cnt_i = 0, cnt_o=0, cnt_u = 0, cnt_other = 0;
while (getline(cin, input)) {
  for (auto &i : input) {
    if (i == 'a') cnt_a += 1;
    else if (i == 'e') cnt_e += 1;
    else if (i == 'i') cnt_i += 1;
    else if (i == 'o') cnt_o += 1;
    else if (i == 'u') cnt_u += 1;
    else cnt_other += 1;
  }
  cout << cnt_a <<"of a, " << cnt_e << "of e, "<< cnt_i  << "of i, " << cnt_o << "of o, " << cnt_u << "of u, \n";
}

//E5.10
string input;
int cnt_a = 0, cnt_e = 0, cnt_i = 0, cnt_o=0, cnt_u = 0, cnt_other = 0;
while (getline(cin, input) && input != "end") {
  for (auto &i : input) {
    switch (i) {
      case 'a' : case 'A' : ++cnt_a; break;
      case 'e' : case 'E' : ++cnt_e; break;
      case 'i' : case 'I' : ++cnt_i; break;
      case 'o' : case 'O' : ++cnt_o; break;
      case 'u' : case 'U' : ++cnt_u; break;
      default: ++cnt_other; break;
    }
  }
  cout << cnt_a <<"of a, " << cnt_e << "of e, "<< cnt_i  << "of i, " << cnt_o << "of o, " << cnt_u << "of u, " << cnt_other << "of other \n";
}



//E5.11
string input;
int cnt_a = 0, cnt_e = 0, cnt_i = 0, cnt_o=0, cnt_u = 0, cnt_other = 0,
    cnt_blank = 0, cnt_newline = 0, cnt_tab = 0;
while (getline(cin, input) && input != "end") {
  for (auto &i : input) {
    switch (i) {
      case 'a' : case 'A' : ++cnt_a; break;
      case 'e' : case 'E' : ++cnt_e; break;
      case 'i' : case 'I' : ++cnt_i; break;
      case 'o' : case 'O' : ++cnt_o; break;
      case 'u' : case 'U' : ++cnt_u; break;
      case ' ' : ++cnt_blank; break;
      case '\t' : ++cnt_tab; break;
      case '\n' : ++cnt_newline; break;
      default: ++cnt_other; break;
    }
  }
}
cout << cnt_a <<" of a, " << cnt_e << " of e, "<< cnt_i  << " of i, " << cnt_o
      << " of o, " << cnt_u << " of u, " << cnt_other << " of other, " << cnt_blank
      << " of blank spaces, " << cnt_tab << " of tab, " << cnt_newline << " of new lines\n";


//E5.12  counts the number of occurrences of the following two-character sequences: ff, fl, and fi.
//Method1
string input;
int cnt_f = 0;
while (getline(cin, input) && input != "end") {
  for (int i = 0; i < input.size(); ++i) {
    switch (input[i]) {
      case 'f' : {
        switch (input[i+1]) {
          case 'f' :case 'i' : case 'l' : ++cnt_f; break;
          default : break;}
      break;}
      default : break;}
  }
}
cout << cnt_f <<" of ff, fl and fi \n";



//E5.13 Each of the programs in the highlighted text on page 184 contains a
// common programming error. Identify and correct each error.
//(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
//char ch = next_text();
//switch (ch) {
//    case 'a': aCnt++;
//    case 'e': eCnt++;
//    default: iouCnt++;
//}
// error: no break after each case end
//Correction:
// unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
//char ch = next_text();
//switch (ch) {
//    case 'a': aCnt++; break;
//    case 'e': eCnt++; break;
//    default: iouCnt++; break;
//}


//(b) unsigned index = some_value();
//switch (index) {
//    case 1:
//        int ix = get_value();
//        ivec[ ix ] = index;
//        break;
//    default:
//        ix = ivec.size()-1;
//        ivec[ ix ] = index;
//}
// error: ix is defined in case 1 scope but is used out of the scope in default
//correction:
//unsigned index = some_value();
//switch (index) {
//    int ix;
//    case 1:
//        ix = get_value();
//        ivec[ ix ] = index;
//        break;
//    default:
//        ix = ivec.size()-1;
//        ivec[ ix ] = index;
//        break;
//}


//(c) unsigned evenCnt = 0, oddCnt = 0;
//int digit = get_num() % 10;
//switch (digit) {
//    case 1, 3, 5, 7, 9:
//        oddcnt++;
//        break;
//    case 2, 4, 6, 8, 10:
//        evencnt++;
//        break;
//}
//error: lack of keyword "case" before each case and should use' : ' to connect each case
//correction:
//unsigned evenCnt = 0, oddCnt = 0;
//int digit = get_num() % 10;
//switch (digit) {
//    case 1 : case 3 : case 5 : case 7 : case 9:
//        oddcnt++;
//        break;
//    case 2 : case 4 : case 6 : case 8 : case 10:
//        evencnt++;
//        break; }



//(d) unsigned ival=512, jval=1024, kval=4096;
//unsigned bufsize;
//unsigned swt = get_bufCnt();
//switch(swt) {
//    case ival:
//        bufsize = ival * sizeof(int);
//        break;
//    case jval:
//        bufsize = jval * sizeof(int);
//        break;
//    case kval:
//        bufsize = kval * sizeof(int);
//        break;
//}
//error:  ival,jval and kval should be constant expressions to be case lables
//correction:
//constexpr unsigned ival=512, jval=1024, kval=4096;
//unsigned bufsize;
//unsigned swt = get_bufCnt();
//switch(swt) {
//    case ival:
//        bufsize = ival * sizeof(int);
//        break;
//    case jval:
//        bufsize = jval * sizeof(int);
//        break;
//    case kval:
//        bufsize = kval * sizeof(int);
//        break;
//}


//E5.14
vector<string> words;
string input;
while (cin >> input) {
  words.push_back(input);
  sort(words.begin(), words.end());
  int cnt = 1;
  auto p = words.begin();
  cout << "added one word" <<endl;
  while (p!= words.end()) {
    if (*p == *(p+1)) {
      ++cnt;
      }
    else {
      cout << cnt << " of " << *p << '\n';
      cnt = 1;
    }
    ++p;
    cout << "\n";
  }
}

//E5.15 Explain each of the following loops. Correct any problems you detect.
//(a) for (int ix = 0; ix != sz; ++ix)  { ... }
//if (ix != sz)
     // . . .
//Explaination: ix was defined in for loop and initialized as 0, ix will increment
//until it is equal to sz. During the for loop, do something while ix increment.
//Later the code checks if ix doesn't reach sz.
//error: ix was used out of the scope which should only be used in the for loop
//Correction:
//int ix;
//for (ix = 0; ix != sz; ++ix)  {... }
//if (ix != sz)

//(b) int ix;
//for (ix != sz; ++ix) { ... }
//Explaination: ix was declared and was default initialized to 0 in the begining.
//Then in the for loop, do something while ix increments until ix reached sz.
//error: for loop doesn't fit the syntax, it lacks of the initialization statement
//Correction:
//int ix;
//for ( ; ix != sz; ++ix) { ... }

//(c) for (int ix = 0; ix != sz; ++ix, ++ sz)  { ...}
//Explaination: ix was initialized as 0 and will increment until its equal to
//sz, which also increments in every for loop.
//error:sz was not defined or initilized and the for loop never ends since ix
//will never reach sz
//Correction:
//for (int ix = 0, sz = getsize(); ix != sz; ++ix, -- sz)  {...}




//E5.16
//for loop && while loop
vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
for (int j = 0; j<10; ++j) cout << ivec[j] << " " << j << endl;
cout << "\n\n";
int i = 0;
while (i < 10 && i >=0 ) {cout << ivec[i] << " " << i << endl; ++i;}


//while loop and for loop
string line;
while(getline(cin,line) && line != "end") {
  cout << line << endl;
}


for (string line2; line2 != "end"; ) {
  getline(cin, line2);
  cout << line2 <<endl;
}



//E5.17  Given two vectors of ints, write a program to determine whether one
//vector is a prefix of the other. For vectors of unequal length, compare the
//number of elements of the smaller vector. For example, given the vectors
//containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program
//should return true.
vector <int> v1, v2;
int int1, int2;
cout << "please input for v1: \n";
while (cin) {
  cin >> int1;
  v1.push_back(int1);
  if (cin.good()) continue;
  else {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    v1.pop_back();
    cout << "please input for v2: \n";
    while (cin >> int2){
      v2.push_back(int2);
      if (cin.good()) continue;
      else break;
    }
  }
}

for (auto s1 : v1) {
  cout << s1 << " ";
}

for (auto s2 : v2) {
  cout << s2 << " ";
}
cout <<endl;

if (v1.size() < v2.size()) {
  auto i = v1.begin(), j = v2.begin();
  for (; i != v1.end() && j!= v2.end(); ++i, ++j) {
    cout << *i <<" i  ";
    cout << *j << " j ";
    if ((*i) != (*j)) break;
    else continue;
  }
  cout << *i << endl;
  if (i == v1.end()) cout << " v1 is prefix for v2\n\n";
  else cout << " v1 has smaller size than v2 and its not prefix for v2\n\n";
}

else if (v1.size() > v2.size()) {
  auto i = v1.begin(), j = v2.begin();
  for (; i != v1.end() && j!= v2.end(); ++i, ++j) {
    if ((*j) != (*i)) break;
    else continue;
  }
  if (j == v2.end()) cout << " v2 is prefix for v1\n\n";
  else cout << " v2 has smaller size than v1 and its not prefix for v1\n\n";
}

else cout << " two vectors have the same size, so one is not a prefix of the other\n\n";



//E5.18: Explain each of the following loops. Correct any problems you detect.

//(a) do
//    int v1, v2;
//    cout << "Please enter two numbers to sum:" ;
//    if (cin >> v1 >> v2)
//        cout << "Sum is: " << v1 + v2 << endl;
//while (cin);

//Explaination: calculate and print v1+v2 if v1 and v2 are input as integers
//Error: missing curly braces
//correction:
//do {
//    int v1, v2;
//    cout << "Please enter two numbers to sum:" ;
//    if (cin >> v1 >> v2)
//        cout << "Sum is: " << v1 + v2 << endl;}
//while (cin);

//(b) do {
//    // . . .
//} while (int ival = get_response());

//Explaination: do something while ival is the result from function get_response
//Error: you can't define ival in the condition in a do, while loop;
//correction:
//int ival;
//do {
//    // . . .
//} while (ival = get_response());


//(c) do {
//    int ival = get_response();
// } while (ival);

//Explaination: assign whats returned from get_response to ival;
//Error: ival was defined in do loop which made it a in scope object;
//correction:
//int ival;
//do {
//    ival = get_response();
// } while (ival);

//E5.19: Write a program that uses a do while loop to repetitively request
//two strings from the user and report which string is less than the other.
string s1, s2;
do {
  cout << "please input two strings to compare" << endl;
  cin >> s1 >> s2;
  if (s1 > s2) cout << s2 << " is the smaller string " << endl;
  else if (s2 > s1) cout << s1 << " is the smaller string" << endl;
} while (cin);


//E5.20: Write a program to read a sequence of strings from the standard
//input until either the same word occurs twice in succession or all the words
//have been read. Use a while loop to read the text one word at a time. Use the
//break statement to terminate the loop if a word occurs twice in succession.
//Print the word if it occurs twice in succession, or else print a message saying
//that no word was repeated.
vector<string> ivec;
string input;
int i = 0;
while (cin >> input && input != "endofinput") {
  ivec.push_back(input);
  ++i;
  if (ivec[i-1] == ivec[i-2]) break;
  else continue;
}


//E5.21 Revise the program from the exercise in § 5.5.1 (p. 191)
//so that it looks only for duplicated words that start with an uppercase letter.

vector<string> ivec;
string input;
int i = 0;
while (cin >> input && input != "endofinput") {
  ivec.push_back(input);
  ++i;
  if (ivec[i-1] == ivec[i-2] && isupper(ivec[i-1].at(0))) {
    break;
  }
  else continue;
}


//E5.22 The last example in this section that jumped back to begin could be better
//written using a loop. Rewrite the code to eliminate the goto.
//orinial code:
  begin:
    int sz = get_size();
    if (sz <= 0) {
          goto begin;
    }

//Method1
int sz;
while (sz <= 0) sz = get_size();

//Method2
int sz;
do {
  sz = get_size()
} while(sz <= 0);

//Methods3
int sz;
while ((sz = get_size()) <= 0) ; // Null statement


//E5.23: Write a program that reads two integers from the standard input and
//prints the result of dividing the first number by the second.
int input1, input2;
while (cin >> input1 >> input2) cout << "the result is " << input1/input2 << " while the remainder is " << input1%input2 << endl;

//E5.24: Revise your program to throw an exception if the second number is zero.
//Test your program with a zero input to see what happens on your system if
//you don’t catch an exception.

//if there's no exception, it gives error as "zsh: floating point exception"
int input1, input2;
  while (cin >> input1 >> input2) {
    if (input2 == 0) throw runtime_error("second number can't be 0");
    else cout << "the result is " << input1/input2 << endl;
  }



//E5.25: Revise your program from the previous exercise to use a try block to
//catch the exception. The catch clause should print a message to the user and
//ask them to supply a new number and repeat the code inside the try.
int input1, input2;
  while (cin >> input1 >> input2) {
    try {
      if (input2 == 0) throw runtime_error("second input can't be 0");
      else cout << input1/input2 << endl;
    } catch (runtime_error err) {
      cout << err.what() << "\ntry to input again? Yes or No" << endl;
      string input3;
      cin >> input3;
      if ( !cin || input3 == "No" || input3 == "NO" || input3 == "no" ) break;
      else if ( input3 == "yes" || input3 == "YES" || input3 == "Yes" ) continue;
    }
  }


//E6.1 What is the difference between a parameter and an argument?
//Parameter: variable defined in function declaration, seen in the parenthesis
//behind the function name
//Arguments:the actual value of the variable you want to pass to the function, it
//is seen when you call a function

//E6.2  Indicate which of the following functions are in error and why.
//Suggest how you might correct the problems.
//(a) int f() {
//     string s;
//     // ...
//     return s;
// }

// Wrong, return types don't match

//(b) f2(int i) {...}
//Wrong, doesnt have a return type before the function

//(c) int calc(int v1, int v1) ... }
//Wrong, two paramenters can't have the same name, curly braces are not complete

//(d) double square(double x) return x * x;
//Wrong, the function body should be in a block with curly braces


//E6.3 Write and test your own version of fact.

int s = fact(5)



//E6.4: Write a function that interacts with the user, asking for a number and
//generating the factorial of that number. Call this function from main.
int j;
while (cin >> j) {
  int s = fact(j);
  cout << s <<endl;
}


//E6.5: Write a function to return the absolute value of its argument.

int j;
while (cin >> j) {
  int s = abv(j);
  cout << s <<endl;
}




//E6.6 Explain the differences between a parameter, a local variable, and a
//local static variable. Give an example of a function in which each might
//be useful.

//Local variable: Parameters and variables defined inside a function body are referred to as
//local variables. They are “local” to that function and hide declarations of
//the same name made in an outer scope.

//Parameter is a local variable. The scope of a parameter is the same as local variable, which is the
// function body.The lifetime of the parameter starts when the function begins,
//and ends when the function terminates. It is initialized by the arguments
//passed to the function.

//A local static variable is a local variable that defined with static keyword.
//It has a lifetime much longer than usual local variable.The scope of a local
//static variable is the same as local variable, which is the function body.
//The lifetime of the local static varible starts when the first time control passes
// through the variable's definition, and ends when the program terminates.
//It is initialized if its definition contains an initializer, otherwise, it is
//value initialized

int count (int i) {
  static int cnt;
  ++cnt;
  int j = 0;
  if (i == j) return cnt;
  else return j;
}



//E6.7 Write a function that returns 0 when it is first called and then
//generates numbers in sequence each time it is called again.
int count (int i) {
  static int cnt == 0;
  if (cnt == 0) return 0;
  else return cnt;
  ++cnt;
}



//E6.8 Write a header file named Chapter6.h that contains declarations for the
//functions you wrote for the exercises in § 6.1 (p. 205).




//E6.9 Write your own versions of the fact.cc and factMain.cc files. These files
//should include your Chapter6.h from the exercises in the previous section.
//Use these files to understand how your compiler supports separate compilation.

// fact.cc
//FactMain.cc


//E6.10 Using pointers, write a function to swap the values of two ints. Test
//the function by calling it and printing the swapped values.
int input1, input2;
while (cin >> input1 >> input2) {
  cout << "original numbers are: " << input1 << " " << input2 << endl;
  swap(&input1, &input2);
  cout << "after swap, they are " << input1 << " " << input2 << endl;
}



//E6.11  Write and test your own version of reset that takes a reference.
string input;
while (cin >> input) {
  reset(input[0]);
  cout << input[0] << " is the first letter" << endl;
  cout << input << " is now the string" << endl;
}


//E6.12 Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use
//references instead of pointers to swap the value of two ints. Which version
//do you think would be easier to use and why?

int input5, input6;
while (cin >> input5 >> input6) {
  cout << " original is " << input5 << " " << input6 << endl;
  swap2(input5, input6);
  cout << "after swap it is " << input5 << " " << input6 << endl;
}



//E6.13 Assuming T is the name of a type, explain the difference between a
//function declared as void f(T) and void f(T&).
//void f(T) is passing arguments by value or the function called by value. The value
//of initializer is copied into the type-T parameter. Changes to the parameter in
//function body will not change the argument value.
//void f(T&) the corresponding argument is passed by reference or the function
//called by reference. The initializer is a reference or alias for the type-T parameter.


//E6.14 Give an example of when a parameter should be a reference type.
//Give an example of when a parameter should not be a reference.

//a parameter should be a reference type:
//Using References to Avoid Copies: It can be inefficient to copy objects of
//large class types or large containers. Moreover, some class types (including
//the IO types) cannot be copied. Functions must use reference parameters to
//operate on objects of a type that cannot be copied.

//Using Reference Parameters to Return Additional Information: A function can
//return only a single value. However, sometimes a function has more than one
//value to return. Reference parameters let us effectively return multiple results.

//a parameter should not be a reference: Changes made to the variable have no effect on the initializer


//E6.15 Explain the rationale for the type of each of find_char’s parameters
//In particular, why is s a reference to const but occurs is a plain reference?
//Why are these parameters references, but the char parameter c is not?
//What would happen if we made s a plain reference? What if we made occurs a
//reference to const?

//string s should be constant because we don't want to change s later, we find character c
// in a constant string. occurs is dynamicly changed in the for loop, when counting
// how many character c is showed up.

//For string &s, it is a reference because string is a large container, we want to use reference
// to get rid of copying large object.

//For occurs, we want to change the initializer in the argument it passed to the
//function. So ++occurs in the function statement means the argument will change
//accordingly. And we want the final value returned by ++occurs

//It's fine make s a plain reference in this case, but its dangerous because
//there's possibility changing s by accident

//if occurs is a const, then it always is the value when it was initialized at first


//E6.16 The following function, although legal, is less useful than it might be.
//Identify and correct the limitation on this function:

//bool is_empty(string& s) { return s.empty(); }
//correction: bool is_empty(const string& s) { return s.empty(); }



//E6.17 Write a function to determine whether a string contains any capital
//letters. Write a function to change a string to all lowercase. Do the parameters
//you used in these functions have the same type? If so, why? If not, why not?

string input;
while (cin >> input) cout << input << is_upper(input) << endl;


string input2;
while (cin >> input2) {
  cout << to_lcase (input2) << endl;
}



//E6.18 Write declarations for each of the following functions. When you write
//these declarations, use the name of the function to indicate what the function does.

//(a) A function named compare that returns a bool and has two parameters that
//are references to a class named matrix.

//bool compare (matrix& p1, matrix& p2){...}

//(b) A function named change_val that returns a vector<int> iterator and takes
//two parameters: One is an int and the other is an iterator for a vector<int>.

//vector<int>::interator change_val(int input1, vector<int> :: interator iter1)

//E6.19 Given the following declarations, determine which calls are legal and
//which are illegal. For those that are illegal, explain why.

//double calc(double);
//int count(const string &, char);
//int sum(vector<int>::iterator, vector<int>::iterator, int);
//vector<int> vec(10);

//(a) calc(23.4, 55.1); ilegal, the amount of arguments doesn't match with the parameter numbers;
//(b) count("abcda", 'a'); legal
//(c) calc(66); legal, 66 will be converted to double
//(d) sum(vec.begin(), vec.end(), 3.8); legal, 3.8 will be truncated into integer.


//E6.20 When should reference parameters be references to const? What happens if
//we make a parameter a plain reference when it could be a reference to const?
//when you dont want to cahnge the original argument value, just want to calculate
// the numbers of elelments in the arguments;
// could accidentally change the original argument by accident when you just want to
// know the features of the arguments;


//E6.21 Write a function that takes an int and a pointer to an int and returns
//the larger of the int value or the value to which the pointer points. What
//type should you use for the pointer?
int i = 5;
cout << compareLarger(i=7, &i);


//E6.22 Write a function to swap two int pointers.
int i = 9, j = 6;
int* ptr1 = &i; int* ptr2 = &j;
swap_ptr(ptr1, ptr2);
cout << *ptr1 << " " << *ptr2 <<endl;



//E6.23 Write your own versions of each of the print functions presented in this
//section. Call each of these functions to print i and j defined as follows:
int i = 0, j[2] = {0, 1};
print(&i);
cout << "\n\n\n";
print(j);


//E6.24 Explain the behavior of the following function. If there are problems in
//the code, explain what they are and how you might fix them.

//void print(const int ia[10])
//{
//    for (size_t i = 0; i != 10; ++i)
//        cout << ia[i] << endl;
//}
//correction: void print(const int (&ia)[10])


//E6.25 Write a main function that takes two arguments. Concatenate the supplied
// arguments and print the resulting string.
//E6.26 Write a program that accepts the options presented in this section.
//Print the values of the arguments passed to main.

//int main(int argc, char *argv[]) {
//  string s;
//  for (auto i = 0; i < argc; ++i)
//  s += argv[i];
//  cout << s << endl;
//}


//E6.27 Write a function that takes an initializer_list<int> and produces the
//sum of the elements in the list.

double test = sum_list({3.14, 15925, 53, 123.2});
cout << test << endl;

//E6.28 In the second version of error_msg that has an ErrCode parameter, what
//is the type of elem in the for loop?
//constant reference to strings


//E6.29 When you use an initializer_list in a range for would you ever use a
//reference as the loop control variable? If so, why? If not, why not?
//Depends what scenerio you are in. The initilizer_list only contains constant
//values, so you can't change the initilizers. If you want to change the object
//or the object can't be copied to pass to the argument, then you should use reference.



//E6.30 Compile the version of str_subrange as presented on page 223 to see what
// your compiler does with the indicated errors.
//bool str_subrange(const std::string &str1, const std::string &str2)
//{
//	if (str1.size() == str2.size())
//		return str1 == str2;
//	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
//	for (decltype(size) i = 0; i != size; ++i)
//		if (str1[i] != str2[i])
//			return;
//}
//error: non-void function 'str_subrange' should return a value


//E6.31 When is it valid to return a reference? A reference to const?
//When the object that the  reference refers to  is not local in the function
//because it will be erased after the function call ends.
// when the returned object was not meant to be lvalue which means that
// we want to change the object afterwards;



//E6.32 Indicate whether the following function is legal. If so, explain what
//it does; if not, correct any errors and then explain it.

//int &get(int *arry, int index) { return arry[index]; }
//int main() {
//    int ia[10];
//    for (int i = 0; i != 10; ++i)
//        get(ia, i) = i;
//}

//legal, get returns a int& to the element on position index in arry. When the function
//was called in main, "get" returns refereces to the range from ia[0] to ia[9].
//


//E6.33 Write a recursive function to print the contents of a vector.

vector<string> v = {"kevin", "loves", "Wei"};
vector<string>::size_type i = v.size();
print_vec(v, i);



//E6.34 What would happen if the stopping condition in factorial were

//if (val != 0)
// it will multiply 0 in the end which makes the result 0

//E6.35 In the call to factorial, why did we pass val - 1 rather than val--?
// for each val, it will print factorial numbers of val, val-1, val-2....3,2,1.


//E6.36: Write the declaration for a function that returns a reference to an
//array of ten strings, without using either a trailing return, decltype, or a
//type alias.

// string (& arr_s10(string arr[10])) [10]
// string(&arr_s10(string (&arr)[10])) [10]

//E6.37: Write three additional declarations for the function in the previous exercise.
//One should use a type alias, one should use a trailing return, and the third
//should use decltype. Which form do you prefer and why?

//type alias
//typedef string arrT[10];
//or (using arrT = string[10];)
//arrT& func(arrT & arr);
//trailing return: auto func(arrT& arr) -> string(&)[10];
//decltype: string arr1[10]; decltype(arr1) & func(arrT arr);

//E6.38: Revise the arrPtr function on to return a reference to the array.
//int odd[] = {1,3,5,7,9};
//int even[] = {0,2,4,6,8};

//decltype(odd) &arrPtr(int i)
//{
//    return (i % 2) ? odd : even;
//}


//E6.39: Explain the effect of the second declaration in each one of the following
// sets of declarations. Indicate which, if any, are illegal.

//(a) int calc(int, int);
//int calc(const int, const int);
//illegal

//(b) int get();
//double get();
//illegal


//(c) int *reset(int *);
//double *reset(double *);
//legal

//E6.40: Which, if either, of the following declarations are errors? Why?

//(a) int ff(int a, int b = 0, int c = 0);
//Right

//(b) char *init(int ht = 24, int wd, char bckgrnd);
//Errors: First parameter was default initialized but the following parameters
//should be initialized but they were not.

//E6.41: Which, if any, of the following calls are illegal? Why? Which, if any,
//are legal but unlikely to match the programmer’s intent? Why?

//char *init(int ht, int wd = 80, char bckgrnd = ' ');

//(a) init();
//illegal, the1st parameter ht should be assigned a value

//(b) init(24,10);
//legal, ht = 24, wd = 10

//(c) init(14, '*');
//legal, but it's unlikely to match the programmer's intent. So the 2nd argument
//'*' would be assigned to wd, but since it's a character, it is meant to be assigned
// to the 3rd parameter bckgrnd.

//E6.42: Give the second parameter of make_plural (§ 6.3.2, p. 224) a default
//argument of 's'. Test your program by printing singular and plural versions of
// the words success and failure.
//string make_plural(size_t ctr, const string &word, const string &ending) {
//    return (ctr > 1) ? word + ending : word;}

//if the second parameter which is "word" was given 's' as a default argument:
//error: reference to type 'const std::__1::string' (aka 'const basic_string<char,
//char_traits, allocator >') could not bind to an rvalue of type 'char'
//string make_plural(size_t ctr, const string &word = 's', const string &ending) {

//However, if it's a typo and the 3rd parameter instead of the 2nd one was given 's':

string word;
while(cin >> word) {
  size_t sz = word.length();
  cout << make_plural(sz, word) <<endl;
}

//E6.43: Which one of the following declarations and definitions would you put
//in a header? In a source file? Explain why.

//(a) inline bool eq(const BigInt&, const BigInt&) {...}
//In header file: inline and constexpr functions normally are defined in header

//(b) void putValues(int *arr, int size);
//the function declaration should be in a header file


//E6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.
//bool isShorter(const string &s1, const string &s2) {
//    return s1.size() < s2.size(); }
string s1, s2;
while (cin >> s1 >> s2) {
  cout << isShorter(s1, s2) << endl;
}

//E6.45: Review the programs you’ve written for the earlier exercises and decide
// whether they should be defined as inline. If so, do so. If not, explain why
//they should not be inline.
//Those functions with small, simple, one line of return and called multi-times
//can be modified into inline function. Thus, the run-time overhead of making
//those functions is removed.


//E6.46: Would it be possible to define isShorter as a constexpr? If so, do so.
//If not, explain why not.
//It is possible to define isShorter as a constexpr.
cout << isShorter2("Wang", "Wei") << endl;



//E6.47: Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that
//used recursion to print the contents of a vector to conditionally print
//information about its execution. For example, you might print the size of the
//vector on each call. Compile and run the program with debugging turned on and
//again with it turned off.


vector<string> v = {"Wei", "Wang", "Kevin", "Yu"};
vector<string>:: iterator b= v.begin();
vector<string>:: iterator e= v.end();
print_vec (b,e);


//E6.48: Explain what this loop does and whether it is a good use of assert:
//string s;
//while (cin >> s && s != sought) { }  // empty body
//assert(cin);

//It is not a good use of assert because cin is always valid; it's better to change
//the statement as follows:
//while (cin >> s && assert(s != sought)) { }  // empty body



//E6.49: What is a candidate function? What is a viable function?
//Candidate function is a list of functions that have the same name as the called
//function and for which a declaration is visible at the point of the call.
//To be viable, a function must have the same number of parameters as there are
//arguments in the call, and the type of each argument must match—or be
//convertible to—the type of its corresponding parameter.

//E6.50: Given the declarations for f from page 242, list the viable functions,
//if any for each of the following calls. Indicate which function is the best
//match, or if the call is illegal whether there is no match or why the call is
//ambiguous.

//(a) f(2.56, 42)
//it is ambiguous because both void f(double, double = 3.14) and void f(int, int)
//are viable but both of them need a convert to be best matches

//(b) f(42)
//void f(int) is the best match

//(c) f(42, 0)
//void f(int, int) is the best match

//(d) f(2.56, 3.14)
//void f(double, double = 3.14) is the best match

//E6.51: Write all four versions of f. Each function should print a
//distinguishing message. Check your answers for the previous exercise. If your
// answers were incorrect, study this section until you understand why your
//answers were wrong.

//f(2.56, 42); //ambigous

f(42);

f(42, 0);

f(2.56, 3.14);



//E6.52: Given the following declarations,
//void manip(int, int);
//double dobj;
//what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?

//(a) manip('a', 'z');
//Promotion from char to int, and then an exact match

//(b) manip(55.4, dobj);
//Arithmetic convertion from double to int

//E6.53: Explain the effect of the second declaration in each one of the
//following sets of declarations. Indicate which, if any, are illegal.

//(a) int calc(int&, int&);
//int calc(const int&, const int&);
//legal

//(b) int calc(char*, char*);
//int calc(const char*, const char*);
//legal

//(c) int calc(char*, char*);
//int calc(char* const, char* const);
//illegal; ambiguous call, because top-leval constness will be discarded

//E6.54: Write a declaration for a function that takes two int parameters and
//returns an int, and declare a vector whose elements have this function pointer
//type.
// int f(int i, int j)
//decltype(f) *pf(); vector<pf> v1;
//Or: typedef int(*pf) (int i, int j); vector<pf> v1;
//Or: typedef decltype(f) *pf; vector<pf> v1;
//Or: Using pf = int(*)(int, int); vector<pf> v1;
//Or: Using f = int(int, int);  vector<*f> v1;


///E6.55: Write four functions that add, subtract, multiply, and divide two int
//values. Store pointers to these functions in your vector from the previous
//exercise.
using pf = int(*)(int, int);
vector<pf> funcpt1 {ad, st, mp, dv};
vector<pf> funcpt2 {&ad, &st, &mp, &dv};

///E6.56: Call each element in the vector and print their result.
for  (auto f : funcpt1) cout << f(8, 5) << " ";
cout <<"\n\n";
for  (auto f : funcpt2) cout << f(10, 4) << " ";
cout << "\n\n";


//E7.1: Write a version of the transaction-processing program from § 1.6 (p. 24)
//using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).
Sales_data total;
if (cin >> total) {
  Sales_data trans;
  while (cin >> trans) {
    if (total.isbn()== trans.isbn()) total = total.sameaddTwo(trans);
    else total = trans;
    total.print_s();
   }
 }
else {
 cerr << "No data?!" << endl;
 return -1;  // indicate failure
}


//E7.2 Add the combine and isbn members to the Sales_data class you wrote for
//the exercises in § 2.6.2 (p. 76).
//Answer:Please see Sales_data.hpp

//E7.3 Revise your transaction-processing program from § 7.1.1 (p. 256) to
//use these members.
//Answer: Please see the answer from E7.1

//E7.4 Write a class named Person that represents the name and address of a
//person. Use a string to hold each of these elements. Subsequent exercises
//will incrementally add features to this class.
//Please see Person.hpp

//E7.5 Provide operations in your Person class to return the name and address.
//Should these functions be const? Explain your choice.
//They should be const so that they don't modify the data members that are returned

//E7.6 Define your own versions of the add, read, and print functions.
// istream &read(istream&is, Sales_data&object) {
//   is >> object.bookNo >> object.units_sold >> object.price;
//   return is;
// }
// ostream &print(ostream &os, const Sales_data &item) {
//   os << item.isbn() << " " << item.units_sold << " "<< item.revenue << " "
//       << item.avgprice;
//   return os;
// }
// Sales_data add(Sales_data item1, Sales_data item2) {
//   Sales_data total = item2;
//   if (item1.isbn() == item2.isbn()){
//     total = item2.sameaddTwo(item1);
//   }
//   return total;
// }

//E7.7: Rewrite the transaction-processing program you wrote for the exercises
//in § 7.1.2 (p. 260) to use these new functions.
Sales_data item8;
if (read(cin, item8)) {
  Sales_data item9;
  while (read(cin, item9)) {
    if (item8.isbn() == item9.isbn()) item8 = add(item8, item9);
    else item8 = item9;
    print(cout, item8);
  }
}
else cerr << "No data input\n";


//E7.8: Why does read define its Sales_data parameter as a plain reference and
//print define its parameter as a reference to const?
//When reading: Sales_data item parameter is modified whenever an input is read.
//When printing:Sales_data item should not be modified, we just want to access the member values

//E7.9: Add operations to read and print Person objects to the code you wrote
//for the exercises in § 7.1.2 (p. 260).
//Please see the functions add, read and print in Person.hpp

//E7.10: What does the condition in the following if statement do?
//if (read(read(cin, data1), data2))
//read takes a reference to their respective IO class types.
//The IO classes are types that cannot be copied, so we may only pass them by
//reference.
//std::istream &firstStep = read(cin, data1);
//sdt::istream &secondStep = read(firstStep, data2);
//if (secondStep == True) meaning that if istream takes two data: data1 and data2

//E7.11 Add constructors to your Sales_data class and write a program to use
//each of the constructors.
Sales_data item10;
Sales_data item11("kiwi", 4, 5);
Sales_data item12(cin);
print(cout,item10);
print(cout,item11);
print(cout,item12);


//E7.12: Move the definition of the Sales_data constructor that takes an istream
// into the body of the Sales_data class.
//Please see Sales_data.hpp

//E7.13: Rewrite the program from page 255 (E7.1)to use the istream constructor.
Sales_data total(cin);
if (cin) {
  Sales_data trans;
  while (read(cin, trans)) {
    if (total.isbn()== trans.isbn()) total = total.sameaddTwo(trans);
    else total = trans;
    total.print_s();
   }
 }
else {
 cerr << "No data?!" << endl;
 return -1;  // indicate failure
}

//E7.14: Write a version of the default constructor that explicitly initializes
//the members to the values we have provided as in-class initializers.
//Please see Sales_data.hpp

//E7.15: Add appropriate constructors to your Person class.
//Please see Person.hpp


//E7.16 What, if any, are the constraints on where and how often an access
//specifier may appear inside a class definition? What kinds of members should
//be defined after a public specifier? What kinds should be private?
//Access specifiers are used to enforce encapsulation: members under public specifier
//are accessible to all parts of the programs and they define the interface to the class.
//Members under private specifier are accessible to the member functions of the class
//but are not accessible to code that uses the class. The private section hide the
//implementation
//A class can have zero or multiple access specifiers, no restriction of how often
//access specifiers appear.

//E7.17 What, if any, are the differences between using class or struct?
//Default access levals of class and struct are different. Class has private
//default access while struct has public acess.

//E7.18 What is encapsulation? Why is it useful?
//encapsulation is to hide the implementations or the private members and make
//those members only accessible to the member functions of the class.
//The users won't be able to access to the implementation, or don't need to know how
//the class works. And users won't be able to accidentally change the values of
//class members.

//E7.19  Indicate which members of your Person class you would declare as public
//and which you would declare as private. Explain your choice.
//I would make those class data members private: name, address and population
//I would make those member functions and constructors public: readname (), readaddress()
//Person() = default;
//Person(const string &n, const string &a, const unsigned int &p) : name(n), address(a), population(p){}
//Person(istream&);

//E7.20 When are friends useful? Discuss the pros and cons of using friends.
//It is useful when a function or class is in the interface of a class but not a class member,
//and the function or class needs to access the class members.
//Pro: Non-class function members can access to class members
//Cons: If the implementation changes, the friends may need to change too.

//E7.21 Update your Sales_data class to hide its implementation. The programs
//you’ve written to use Sales_data operations should still continue to work.
// Recompile those programs with your new class definition to verify that they
//still work.
//Please see Sales_data.hpp

//E7.22 Update your Person class to hide its implementation.
//Please check Person.hpp

//E7.23 Write your own version of the Screen class.
//Please see screen.hpp

//E7.24 Give your Screen class three constructors: a default constructor; a
//constructor that takes values for height and width and initializes the contents
//to hold the given number of blanks; and a constructor that takes values for
//height, width, and a character to use as the contents of the screen.
//Please see screen.hpp

//E7.25 Can Screen safely rely on the default versions of copy and assignment?
//If so, why? If not, why not?
//We can, because there are only some cases that we can't rely on synthesizd default constructor:
//(1)objects of built-in or compound type (such as arrays and pointers) that are
//defined inside a block have undefined value when they are default initialized
//(2) For example, if a class has a member that has a class type, and that class
// doesn’t have a default constructor, then the compiler can’t initialize that
//member.
//screen only uses std::string, so it doesn't belong to the two scenerio above.

//E7.26 Define Sales_data::avg_price as an inline function.
//Please see screen.hpp

//E7.27 Add the move, set, and display operations to your version of Screen.
//Test your class by executing the following code:
//Please see screen.hpp
screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";

//E7.28 What would happen in the previous exercise if the return type of move,
//set, and display was Screen rather than Screen&?
//myScreen.move(4,0).set('#').display(cout);
//Move function will return a temporary copy of *this instead of passing a reference to
//the object to set. So set # will only be added to the temporary copy instead of
//the originial myScreen object. So when myScreen.display was called, it doesn't have
//the expected "#" in the output.


//E7.29 Revise your Screen class so that move, set, and display functions return
// Screen and check your prediction from the previous exercise.
// screen myScreen(5, 5, 'X');
// myScreen.move(4,0).set('#').display(cout);
// cout << "\n";
// myScreen.display(cout);
// cout << "\n";
// XXXXXXXXXXXXXXXXXXXX#XXXX
// XXXXXXXXXXXXXXXXXXXXXXXXX

//E7.30 It is legal but redundant to refer to members through the this pointer.
//Discuss the pros and cons of explicitly using the this pointer to access members.
//Pros: an explicit "this" can reminds the class user that class members are
//being accessed and changed through a pointer. So if there's additional use of
//the changed return value, the return value has to be a reference

//E7.31 Define a pair of classes X and Y, in which X has a pointer to Y, and Y
//has an object of type X.
//Please see XY.hpp

//E7.32 Define your own versions of Screen and Window_mgr in which clear is a
//member of Window_mgr and a friend of Screen.
//Please check Window_mgr.hpp

//E7.33 What would happen if we gave Screen a size member defined as follows?
//Fix any problems you identify.

//pos Screen::size() const {return height * width;}
//Problem: return type is seen before class name, even when it is inside of the
//class scope, it appears outside of the class scope.So the reuturn type "pos"
//needs to have class name in front of it. Correction:
//Screen::pos Screen::size() const {return height * width;}

//E7.34 What would happen if we put the typedef of pos in the Screen class on
//page 285 as the last line in the class?
//it would throw an error "unknown type name pos" when its using pos as parameter types

//E7.35 Exercise 7.35: Explain the following code, indicating which definition
//of Type or initVal is used for each use of those names. Say how you would fix
//any errors.
//With errors:
// typedef string Type;
// Type initVal();
// class Exercise {
// public:
//     typedef double Type;  //Error:can't re-define typename Type
//     Type setVal(Type);//string Type for both return type and parametr type
//     Type initVal(); //string Type
// private:
//     int val;
// };
// Type //string Type Exercise::setVal(Type parm)//double Type {
//     val = parm + initVal(); //Excercise::initval
//     return val;
// }

//Correction:
// typedef string Type_s;
// Type initVal();
// class Exercise {
// public:
//     typedef double Type_d;
//     Type_d setVal(Type_d);
//     Type_d initVal();
// private:
//     int val;
// };
// Excercise::Type_d Exercise::setVal(Type_d parm) {
//     val = parm + initVal();
//     return val;
// }

//E7.36 The following initializer is in error. Identify and fix the problem.
// struct X {
//     X (int i, int j): base(i), rem(base % j) { }
//     int rem, base;
// };
//rem was declared (and default initialized) before base, however, base is
//needed when "initializing" rem in the initiliazation list. Correction:
// struct X {
//     X (int i, int j): base(i), rem(i % j) { }
//     int base, rem;
// };


//E7.37 Using the version of Sales_data from this section, determine which
//constructor is used to initialize each of the following variables and list the
// values of the data members in each object:
// Sales_data first_item(cin);
////Constructor used:Sales_data(istream &is) {read(is, *this);} whatever cin takes
// int main() {
//     Sales_data next;
////Constructor used: Sales_data () = default; all members are in class initialized
//     Sales_data last("9-999-99999-9");
////Constructor used: Sales_data (const string &s) : bookNo(s){};
////bookNo is "9-999-99999-9" while other members are in class initialized
// }

//E7.38 We might want to supply cin as a default argument to the constructor
//that takes an istream&. Write the constructor declaration that uses cin as a
//default argument.
//Sales_data(istream &is = cin) {read(is, *this);}

//E7.39 Would it be legal for both the constructor that takes a string and the
//one that takes an istream& to have default arguments? If not, why not?
//No, it will cause ambigous behaviors

//E7.40 Choose one of the following abstractions (or an abstraction of your own
//choosing). Determine what data are needed in the class. Provide an appropriate
// set of constructors. Explain your decisions.
//(c) Employee
//Emplyment() = default;
//Employee(string n = " "):name(n) { }
//Employee(string n, unsigned int p, string a):name(n),phoneNo(p), address(a){}
//Employee(istream &is) {read(is, *this);}

//E7.41 Rewrite your own version of the Sales_data class to use delegating
//constructors. Add a statement to the body of each of the constructors that
//prints a message whenever it is executed. Write declarations to construct a
//Sales_data object in every way possible. Study the output until you are certain
//you understand the order of execution among delegating constructors.
//Please check my Delegating_SalesData.hpp to check the delegating constructors
//Below is the code for checking the outputs:
Delegating_SalesData item15("kiwi", 5, 10.0);
cout << "next\n";
Delegating_SalesData item13;
cout << "next\n";
Delegating_SalesData item14("kiwi");
cout << "next\n";
Delegating_SalesData item16(cin);
cout << "next\n";
//delegated constructor function body first and then delegating constructor
//function body second

//E7.42 For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide
//whether any of the constructors might use delegation. If so, write the delegating
// constructor(s) for your class. If not, look at the list of abstractions and
//choose one that you think would use a delegating constructor. Write the class
//definition for that abstraction.
// Delegating version:
//(c) Employee
//Employee(string n, unsigned int p, string a):name(n),phoneNo(p), address(a){}
//Employee(string n = " "):Employee(n, 0, " ") {}
//Employee():Employee(" ", 0, " ") {}
//Employee(istream &is):Employee(){read(is, *this);}

//E7.43 Assume we have a class named NoDefault that has a constructor that takes
// an int, but has no default constructor. Define a class C that has a member of
// type NoDefault. Define the default constructor for C.
//class NoDefault {
// public:
//  NoDefault (int i) : member1(i){}
// private:
//  int member1;
// };
//
//class C {
// public:
//  C(NoDefault j) : member2(j){}
//  C() : C(0) {}
// private:
//  NoDefault member2;
// };

//E7.44 Is the following declaration legal? If not, why not?
//vector<NoDefault> vec(10);
//illegal.Because the elements in vec can't be default initialized;

//E7.45 What if we defined the vector in the previous execercise to hold objects
// of type C?
//It will become legal and 10 vec elements will be default initialized into 0
//using the constructor: C() : C(0) {} delegating C(NoDefault j) : member2(j){}


//E7.46 Which, if any, of the following statements are untrue? Why?
//(a) A class must provide at least one constructor.
//False: compiler will generate a synthesizd default constructor
//(b) A default constructor is a constructor with an empty parameter list.
//True
//(c) If there are no meaningful default values for a class, the class should not
//provide a default constructor.
//False: meaningfulness is not a neccessity for default values for a class.
//(d) If a class does not define a default constructor, the compiler generates one
//that initializes each data member to the default value of its associated type.
//True

//E7.47: Explain whether the Sales_data constructor that takes a string should
//be explicit. What are the benefits of making the constructor explicit? What
//are the drawbacks?

//E7.48: Assuming the Sales_data constructors are not explicit, what operations
//happen during the following definitions
// string null_isbn("9-999-99999-9");
// Sales_data item1(null_isbn);
// Sales_data item2("9-999-99999-9");
//What happens if the Sales_data constructors are explicit?
//When Sales_data constructors are not explicit:
//string literal "9-999-99999-9" will be converted to library string.
//item1 will be initiliazed by the constructor:
//Sales_item(const std::string &book): bookNo(book) { }
//item2 argument "9-999-99999-9" will be converted to a string and will be stored
// in a temperory string object which will be passed to the constructor:
//Sales_item(const std::string &book): bookNo(book) { }
//When Sales_data constructors are explicit:
//For item2, the string literal will be implicitly transformed into library string
//However,Item1 or item2 can't do copy initilization such as:Sales_data item2 = "9-999-99999-9";

//E7.49: For each of the three following declarations of combine, explain what
//happens if we call i.combine(s), where i is a Sales_data and s is a string:
// (a) Sales_data &combine(Sales_data);
//s will be implicitly converted into Sales_data through string constructor
//and saved in temp which will pass to combine
// (b) Sales_data &combine(Sales_data&);
//s will be implicitly converted into Sales_data through string constructor
//and saved in a reference to it which will pass to combine
// (c) Sales_data &combine(const Sales_data&) const;
//const function can't modify the object passed to it. So i can't be converted
//into Sales_data so it will give an error

//E7.50: Determine whether any of your Person class constructors should be
//explicit.
//Person(istream&); should be explicit so that we don't use copy initilization

//E7.51: Why do you think vector defines its single-argument constructor as
//explicit, but string does not?
//Explicit  constructor can't allow copy initilization. Imagine an initilization scenario.
//vector<int> vec = 10.(if it's implicit) then the 10 could be the size of the vec or
//it could be the element in the vector.
//For a string: string s("abcd") or string s = "abcd" don't make any confusion.

//E7.52: Using our first version of Sales_data from § 2.6.1 (p. 72), explain the
// following initialization. Identify and fix any problems.
//Sales_data item = {"978-0590353403", 25, 15.99};
//It list initialized a temp Sales_data with bookNo "978-0590353403", units_sold 25
//price 15.99 into revenue and then it is copied into Sales_data item.
//Revenue should be price*units_sold, so the last initializer should be 25*15.99.

//E7.53: Define your own version of Debug.
constexpr Debug io_sub(false, true, false);
io_sub.print_error();

//E7.54: Should the members of Debug that begin with set_ be declared as
//constexpr? If not, why not?
//It shouldn't; In C++11, if its constexpr, it is implicitly const which means that
//the funciton can't change data members inside the class.

//E7.55 Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why
//not? If so, explain why it is literal.
//It's not literal class. It is an aggregate class but its data members are not
//literal types.

//E7.56: What is a static class member? What are the advantages of static
// members? How do they differ from ordinary members?
//Static class member is associated with the class not with any object in the class.
//it is part of the class and all the class objects share the same static class member.
//Differences:
//1.it can't have in-class initilization except for cibst of literal type
//or a constexpr of literal type.
//2. It has to be defined outside of the class.
//3. It can be used as a default argument for a member function.

//E7.57: Write your own version of the Account class.
//Please see my CHAPTER7_ACCOUNT_HPP

//E7.58: Which, if any, of the following static data member declarations and
//definitions are errors? Explain why.

// // example.h
// class Example {
// public:
//     static double rate = 6.5;
//     //error:non-const static data member must be initialized out of line
//     static const int vecSize = 20;
//     static vector<double> vec(vecSize);
//     //error:non-const static data member must be initialized out of the class
// };
// // example.C
// #include "example.h"
// double Example::rate;
// vector<double> Example::vec;
//Correction:
// // example.h
// class Example {
// public:
//     static double rate;
//     static const int vecSize = 20;
//     static vector<double> vec;
// };
// // example.C
// #include "example.h"
// double Example::rate = 6.5;
// vector<double> Example::vec(Example::vecSize);

//E8.1: Write a function that takes and returns an istream&. The function should
//read the stream until it hits end-of-file. The function should print what it
//reads to the standard output. Reset the stream so that it is valid before
//returning the stream.
// istream& read_until_eof(istream& is) {
//  string result;
//   while(!item.eof() && is >> result) {
//     cout << item;
//   }
//   is.clear();
//   return is;
// }

//E8.2: Test your function by calling it, passing cin as an argument.
istream& is = read_until_eof(cin);
cout << is.rdstate() << endl;

//E8.3: What causes the following while to terminate?
// while (cin >> i)

//eofbit: reaching end of file, in this case, reaching the end of whats passed into cin;
//failbit: a recoverable error such as read a character when numeric data was expected;
// in this case, input was different type with i;
//badbit:system-level failure, such as an unrecoverable read or write error

string k;
while (cin >> k) cout << k << endl;

//E8.4: Write a function to open a file for input and read its contents into a
//vector of strings, storing each line as a separate element in the vector.
// vector<string> read_line_into_vector(const string filename) {
//   ifstream in(filename);
//   vector<string> result;
//   if (in) {
//     string temp;
//     while (getline(in,temp)) result.push_back(temp);
//   }
//   else{
//   cerr << "error in opening file: " << filename << endl;
//   exit(EXIT_FAILURE);
//   }
//   return result;
// }

vector<string> test = read_line_into_vector("test.txt");
for (auto i : test) cout << i << "\n";


//E8.5: Rewrite the previous program to store each word in a separate element.
// vector<string> read_word_into_vector(const string filename) {
//   ifstream in(filename);
//   vector<string> result;
//   if (in) {
//     string temp;
//     while (in >> temp) result.push_back(temp);
//   }
//   else{
//   cerr << "error in opening file" << filename << endl;
//   exit(EXIT_FAILURE);
//   }
//   return result;
// }

//E8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its
//transactions from a file. Pass the name of the file as an argument to
//main (§ 6.2.5, p. 218).
//Please see my E8_6.cpp

//E8.7: Revise the bookstore program from the previous section to write its
//output to a file. Pass the name of that file as a second argument to main.
//please check my E8_7.cpp

//E8.8: Revise the program from the previous exercise to append its output to
//its given file. Run the program on the same output file at least twice to
//ensure that the data are preserved.
//please check my E8_8.cpp

//E8.9: Use the function you wrote for the first exercise in § 8.1.2 (E8.1)
//(p. 314) to print the contents of an istringstream object.
// istream& read_until_eof(istream& is) {
//   string result;
//   while(!is.eof() && is >> result) {
//     cout << result << " ";
//   }
//   is.clear();
//   return is;
// }
istringstream iss("isstring print");
read_until_eof(iss);

//E8.10: Write a program to store each line from a file in a vector<string>.
//Now use an istringstream to read each element from the vector a word at a time.
// vector<string> read_sstream_into_vector(ifstream& filename) {
//   vector<string> result;
//   if(filename) {
//     string line, word;
//     while (getline(filename, line)) {
//       istringstream str(line);
//       while (str >> word) {
//         result.push_back(word);
//         cout << word << " ";
//      }
//      cout << endl;
//     }
//       cout << "eof\n";
//   }
//   return result;
// }

fstream createFile("test.txt");
createFile << "Wei 2 5.0\nWei 7 8.0\nKevin 1 2.0\nhahahaha 2 1.0" << endl;
createFile.close();
ifstream input("test.txt");
read_sstream_into_vector(input);

//E8.11: The program in this section defined its istringstream object inside the
//outer while loop. What changes would you need to make if record were defined
//outside that loop? Rewrite the program, moving the definition of record outside
// the while, and see whether you thought of all the changes that are needed.
//Orginal:
// string line, word;
// vector<PersonInfo> people;
// while (getline(cin, line)) {
//     PersonInfo info;
//     istringstream record(line);
//     record >> info.name;
//     while (record >> word)
//         info.phones.push_back(word);
//     people.push_back(info);
// }
//My edit:
// string line, word;
// vector<PersonInfo> people;
// istringstream record;
// while (getline(cin, line)) {
//     record.str(line);
//     PersonInfo info;
//     record >> info.name;
//     while (record >> word)
//         info.phones.push_back(word);
//     people.push_back(info);
// }

//E8.12: Why didn’t we use in-class initializers in PersonInfo?
//It is an aggregate class:"An aggregate is a simple collection of
//data that does not have any invariants the class would have to guarantee.
//Since there is no invariant and thus all combinations of possible values of
//the member make sense, there is no point in making them private since there
//is nothing to protect."
//All of its data members are public
//It does not define any constructors
//It has no in-class initializers (§ 2.6.1, p. 73)
//It has no base classes or virtual functions,

//E8.13 Rewrite the phone number program from this section to read from a named
// file rather than from cin.
vector<PersonInfo> people;
ifstream input("test.txt");
string line, word;
while (getline(input, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word)
        info.phones.push_back(word);
    people.push_back(info);
}
for (const auto &entry : people) {
    ostringstream formatted, badNums;
    for (const auto &nums : entry.phones) {
        if (!valid(nums)) {
            badNums << " " << nums;
        } else
            formatted << " " << format(nums);
    }
    if (badNums.str().empty())
        cout << entry.name << " "
           << formatted.str() << endl;
    else
        cerr << "input error: " << entry.name
             << " invalid number(s) " << badNums.str() << endl;
}

//E8.14: Why did we declare entry and nums as const auto &?
//We don't want to risk changing the original data in People, so we make it const;
*/



return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed
//successfully.And any other number other than 0(like -1,1,2 etc..) indicate
//that program doesnt executed successfully.
}
