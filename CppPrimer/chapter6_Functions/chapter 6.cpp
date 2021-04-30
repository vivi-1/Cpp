/*
This is CppPrimerPractice for the C++ primer 5th edition
By Wei Wang, link: https://github.com/vivi-1/Cpp.git
*/

#include<iostream>
#include<vector>
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
bool chapter6::is_upper(const string& input) {
  unsigned int temp = 0;
  bool result = false;
  for (auto &c : input) {
    if (isupper(c)) temp += 1;
  }
  if (temp != 0) result = true;
  return result;
}

string chapter6::to_lcase(string &input) {
  for (char &c : input) c = tolower(c);
  return input;
}


//E6.21
int chapter6::compareLarger (const int input1, const int *const input2) {
  return (input1 > *input2) ? input1 : (*input2);
}

//E6.22 Write a function to swap two int pointers.
void chapter6::swap_ptr(int*& p1, int*& p2) {
  int* const temp = p1;
  p1 = p2;
  p2 =  temp;
}


//E6.23
void chapter6::print(const int* ptr) {
  if (ptr != nullptr && (*ptr) != '\0') cout << *ptr << endl;
}

void chapter6::print (const int (&arr)[2]) {
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


int main()
{/*
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

  */




  return 0; //return EXIT_SUCCESS
  //return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.
  }
