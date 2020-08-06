//! This code demonstrates the size of the parent class and the child class,
//! which shows that the inhertance is actually making a copy of the parent
//! class.
//!
//! Author: Jihuan Tian
//! Date: 2017-10-04

#include <iostream>

using namespace std;

//! The parent class with a single member variable.
class A {
public:
  int i;
};

//! The child class with its own member variable, which shold has the double
//! size of its parent class A.
class B : public A {
public:
  int i;
};

int main() {
  cout << "Size of the parent class A: " << sizeof(A) << endl;
  cout << "Size of the child class B: " << sizeof(B) << endl;

  return 0;
}
