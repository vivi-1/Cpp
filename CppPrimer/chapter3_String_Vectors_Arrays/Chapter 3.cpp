/*
This is CppPrimerPractice for the C++ primer 5th edition
git config --global user.email wwei6@vt.edu
*/
#include<iostream>
using namespace std;
#include <vector>


int main()
{/*E3.2
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
 (a) no element, no value;
   (b) 10 elements, their values are all 0;
   (c) 10 elements, their values are all 42s;
   (d) 1 element, value is 10;
   (e) 2 elements, values are 10 and 42;
   (f) 10 elements, values are empty strings;
   (g) 10 elemtns, values are all "hi";

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

   //E 3.30: Identify the indexing errors in the following code:

   	//constexpr size_t array_size = 10;
   	//int ia[array_size];
   	//for (size_t ix = 1; ix <= array_size; ++ix) // will trigger buffer overflow; shoudl be: for (size_t ix = 0; ix < array_size; ++ix)
   	//ia[ix] = ix;


    //E3.30: Identify the indexing errors in the following code:

    	//constexpr size_t array_size = 10;
    	//int ia[array_size];
    	//for (size_t ix = 1; ix <= array_size; ++ix)
      // will trigger buffer overflow; shoudl be: for (size_t ix = 0; ix < array_size; ++ix)
    	//ia[ix] = ix;

    //E3.31 Write a program to define an array of ten ints. Give each element the
    //same value as its position in the array.


    //E3.32: Copy the array you defined in the previous exercise into another array.
    //Rewrite your program to use vectors.


    //Exercise 3.33: What would happen if we did not initialize the scores array in
    //the program on page 116?

    // E3.34: Given that p1 and p2 point to elements in the same array, what does the
    // following code do? Are there values of p1 or p2 that make this code illegal?
    // p1 += p2-p1;
    // the meaning of the equations is: find the distance between p2 and p1 and add it
    // to p1, which moves p1 to position p2. It is always legal.

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
      while (auto i = 0 && i != n1) {
        if arr1[i] = arr2[i] cout << "same element at position  " << i << endl;
        ++i;
        else {
          break;
          cout << "elements at " << i << " are different" << endl;
        }
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
*/


return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.

}
