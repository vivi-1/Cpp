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


*/




return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.
}
