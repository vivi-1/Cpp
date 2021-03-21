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



  return 0;
}
