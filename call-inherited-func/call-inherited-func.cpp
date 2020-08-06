//! This code demonstrates the correct calling of inherited member function.
//!
//! Author: Jihuan Tian
//! Date: 2017-10-06

#include <iostream>

using namespace std;

class A {
public:
  A(int i = 0) : _i(i) {}

  void print() { cout << "Class A" << endl; }

  int _i;
};

class B : public A {
public:
  B() {}

  //! Call the self print().
  void print() { cout << "Class B" << endl; }

  //! Call the print() of the parent class.
  void call_parent_print() { A::print(); }
};

//! Template class A.
template <class T> class AT {
public:
  AT(T i = 0) : _i(i) {}

  void print();

  T _i;
};

// N.B. Although the definition of print() function is written in the form of a template function,
// print() itself actually does not depend on the template parameter T.
template <class T> void AT<T>::print() {
  cout << "Class AT: " << _i << endl;
}

template <class T> class BT : public AT<T> {
public:
  BT() {}

  //! Call the print() of the parent class.
  //! The following is wrong with the error:
  //! call-inherited-func.cpp: In member function ‘void BT<T>::call_parent_print()’:
  //! call-inherited-func.cpp:49:36: error: there are no arguments to ‘print’ that depend on a template parameter, so a declaration of ‘print’ must be available [-fpermissive]
  //!    void call_parent_print() { print(); }
  //!                                     ^
  //! call-inherited-func.cpp:49:36: note: (if you use ‘-fpermissive’, G++ will accept your code, but allowing the use of an undeclared name is deprecated)
  //! void call_parent_print() { print(); }

  //! Call the print() of the parent class.
  //! This is wrong.
  //! void call_parent_print_with_template_arg() { print<T>(); }

  //! Call the print() of the parent class.
  //! This is correct.
  void call_parent_print_with_this_ptr() { this->print(); }

  //! Call the print() of the parent class.
  //! This is correct.
  void call_parent_print_with_parent_prefix() { AT<T>::print(); }
};

int main() {
  B b;

  b.print();
  b.call_parent_print();

  BT<int> c;

  c.call_parent_print_with_this_ptr();
  c.call_parent_print_with_parent_prefix();
}
