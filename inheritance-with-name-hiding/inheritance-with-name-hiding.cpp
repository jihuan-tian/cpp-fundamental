// This code demonstrates the name hiding effect by defining member function in
// the child class with the same name as that of the parent class.
//
// Author: Jihuan Tian
// Date: 2017-09-30

#include <iostream>

using namespace std;

class A {
public:
  A(int vi = 1) : i(vi) {}
  void print() { cout << "Class A's member: " << i << endl; }

private:
  int i;
};

class B : public A {
public:
  //! N.B. The constructor's initializer calls the constructor of the parent class.
  B(double vi = 5.2) : A(vi), i(vi) {}
  void print() { cout << "Class B's member: " << i << endl; }
  void print_parent() { A::print(); }
private:
  double i;
};

int main() {
  A a;
  B b;

  a.print();
  b.print();
  b.print_parent();

  return 0;
}
