/*
This is CppPrimerPractice for the C++ primer 5th edition
By Wei Wang, link: https://github.com/vivi-1/Cpp.git
*/
#include<iostream>
#include<vector>
using namespace std;

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


  
  */




  return 0; //return EXIT_SUCCESS
  //return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.
  }
