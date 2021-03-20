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
    
  */





return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.
}
