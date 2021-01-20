/*
This is CppPrimerPractice for the C++ primer 5th edition
By Wei Wang, link: https://github.com/vivi-1/Cpp.git
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{/*
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
