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

*/





return 0; //return EXIT_SUCCESS
//return(0) is basically used to tell the machine that program executed successfully.And any other number other than 0(like -1,1,2 etc..) indicate that program doesnt executed successfully.

}
