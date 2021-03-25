/*
This is CppPrimerPractice for the C++ primer 5th edition
By Wei Wang, link: https://github.com/vivi-1/Cpp.git
*/
#include<iostream>
#include<list>
#include<deque>
#include<vector>
using namespace std;

//E9.4 Write a function that takes a pair of iterators to a vector<int> and an
//int value. Look for that value in the range and return a bool indicating whether
//it was found.
bool is_in(vector<int> vec, int object) {
  for (auto i = vec.begin(); i != vec.end(); ++i) {
    if ((*i)==object) return true;
  }
  return false;
}

//E9.5 Rewrite the previous program to return an iterator to the requested element.
// Note that the program must handle the case where the element is not found.
vector<int>::iterator itr(vector<int> vec, int object) {
  auto i = vec.begin();
  for (; i != vec.end(); ++i) {
    if ((*i)==object) {
      return i;
    }
  }
  cerr << "not found\n";
  exit(EXIT_FAILURE);
}

//E9.14 Write a program to assign the elements from a list of char* pointers to
//C-style character strings to a vector of strings.
vector<string> c_to_str_vec(list<char const*> cstring){
  vector<string> result;
  result.assign(cstring.cbegin(), cstring.cend());
  return result;
}

//E9.15 Write a program to determine whether two vector<int>s are equal.
bool if_equal(vector<int> v1, vector<int> v2){
  return v1==v2;
}

//E9.16 Repeat the previous program, but compare elements in a list<int> to a
//vector<int>.
bool if_equal(vector<int> v1, list<int> l1){
  if (v1.size()!= l1.size()) return false;
  else {
    for (pair<vector<int>::iterator, list<int>::iterator> i(v1.begin(),l1.begin()); i.first != v1.end() &&i.second != l1.end(); ++i.first, ++i.second) {
      if ((*i.first)!= (*i.second)) return false;
    }
  }
  return true;
}

int main(){
//E9.1 Which is the most appropriate—a vector, a deque, or a list—for the
//following program tasks? Explain the rationale for your choice. If there is
//no reason to prefer one or another container, explain why not.
//(a) Read a fixed number of words, inserting them in the container alphabetically
//as they are entered. We’ll see in the next chapter that associative containers
// are better suited to this problem.
//Singlylinked list (forward_list)
//(b) Read an unknown number of words. Always insert new words at the back.
//Remove the next value from the front.
//Dequeue
//(c) Read an unknown number of integers from a file. Sort the numbers and then
//print them to standard output.
//vector

//E9.2 Define a list that holds elements that are deques that hold ints.
list <deque<int>> list1;
//E9.3 What are the constraints on the iterators that form iterator ranges?
//(1) begin and end should refer to the elements of or one past the end of the same container;
//(2) its possible to reach to end by repeatedly increment begin. End must not precede begin;

//E9.4 Write a function that takes a pair of iterators to a vector<int> and an
//int value. Look for that value in the range and return a bool indicating whether
//it was found.
vector<int> vec = {1,2,3,4,5,6,7,8,9,12};
if (is_in(vec, 12)) cout << "yes\n";

//E9.5 Rewrite the previous program to return an iterator to the requested element.
// Note that the program must handle the case where the element is not found.
vector<int> vec1 = {1,2,3,4,5,6,7,8,9,12};
cout << *itr(vec1, 1) << endl;

//E9.6 What is wrong with the following program? How might you correct it?
// list<int> lst1;
// list<int>::iterator iter1 = lst1.begin(),
//                     iter2 = lst1.end();
// while (iter1 < iter2)
//<operator is not implemented in lists or forward_list, the iterator are not continuous;
// Correction:
// list<int> lst1;
// list<int>::iterator iter1 = lst1.begin(),
//                     iter2 = lst1.end();
// while (iter1 != iter2)

//E9.7 What type should be used as the index into a vector of ints?
//vector<int>::size_type

//E9.8 What type should be used to read elements in a list of strings? To write them?
//list<string>::const_iterator
//llist<string>::iterator

//E9.9 What is the difference between the begin and cbegin functions?
//begin returns an iterator type while cbegin returns a const_iteractor type
//Use cbegin when write access is not needed.

//E9.10 What are the types of the following four objects?
// vector<int> v1;
//vector<int>
// const vector<int> v2;
//const vector<int>
// auto it1 = v1.begin(), it2 = v2.begin();
//vector<int>::iterator
// auto it3 = v1.cbegin(), it4 = v2.cbegin();
//vector<int>::const_iterator

//E9.11 Show an example of each of the six ways to create and initialize a
//vector. Explain what values each vector contains.
//vector<int> v = {1,2,3,4,5}
//vector<int> v1(v)
//vector<int> v2(v.begin(), v.end())
//vector<int> v3 (v.cbegin()+2, v.cend()-1)
//vector<int> v3(10, 1)
//vector<int> v4(10)

//E9.12 Explain the differences between the constructor that takes a container
//to copy and the constructor that takes two iterators.
//When using a copy constructor to initialize an object, the object type must
//match the original container. When taking two iterators as parameters, the types
//don't need to match

//E9.13: How would you initialize a vector<double> from a list<int>? From a
//vector<int>? Write code to check your answers.
list<int> li={1,2,3,4,5};
vector<int> vi={2,4,6,8};
vector<double> vd(li.begin(), li.end());
vector<double> vd1(vi.cbegin(), vi.cend());
for (auto i : vd) cout << i << " ";
cout << endl;
for (auto i : vd1) cout << i << " ";
cout << endl;

//E9.14 Write a program to assign the elements from a list of char* pointers to
//C-style character strings to a vector of strings.
list<char const*> li1 = {"wei", "kevin", "Yu"};
vector<string> vi1 = c_to_str_vec(li1);
for (auto i : vi1) cout << i << endl;

//E9.15 Write a program to determine whether two vector<int>s are equal.
//Please check E9.15 outside of the scope
vector <int> v5 = {1,2,3,4,5};
vector <int> v6 = {1,2,3,4,5};
vector <int> v7 = {1,2,3,5};
if(if_equal(v5,v6)) cout << "true\n";
if(!if_equal(v7,v6)) cout << "true\n";

//E9.16 Repeat the previous program, but compare elements in a list<int> to a
//vector<int>.
//Please check E9.16 outside of the scope
list<int> li2= {1,2,3,7};
list<int> li3= {1,2,3,4,5};
if (!if_equal(v5,li2)) cout << "true\n";
if (if_equal(v5,li3)) cout << "true\n";

//E9.17 Assuming c1 and c2 are containers, what (if any) constraints does the
//following usage place on the types of c1 and c2?
//if (c1 < c2)
//operand "<" can not be used on unordered associative containers;
//operand "<" can not be used on class members that didn't define "<"
// c1 and c2 have to be the same container holding the same type elements

//E9.18 Write a program to read a sequence of strings from the standard input
//into a deque. Use iterators to write a loop to print the elements in the deque.


//E9.19 Rewrite the program from the previous exercise to use a list. List the
//changes you needed to make.

//E9.20 Write a program to copy elements from a list<int> into two deques. The
//even-valued elements should go into one deque and the odd ones into the other.

//E9.21 Explain how the loop from page 345 that used the return from insert to
//add elements to a list would work if we inserted into a vector instead.

//E9.22 Assuming iv is a vector of ints, what is wrong with the following
//program? How might you correct the problem(s)?

// vector<int>::iterator iter = iv.begin(),
//                       mid= iv.begin() + iv.size()/2;
// while (iter != mid)
//     if (*iter == some_val)
//         iv.insert(iter, 2 * some_val);

  return 0;
}
