// This code demonstrates when the copy constructor is called and when the overloaded assignment
// operator '=' is called.
// Author: Jihuan Tian
// Date: 2017-07-10

#include <iostream>

using namespace std;

class A {
public:
  // Constructor and default constructor.
  A(int v = 0) : i(v) { cout << "A()" << endl; }
  // Copy constructor.
  A(const A& v) : i(v.i) { cout << "A(const A& v)" << endl; }

  // Assignment
  // Note: the returned value from the opeartor = should be a mutable reference which should be used as
  // an lvalue.
  A& operator=(const A& v) {
    i = v.i;
    cout << "operator=" << endl;

    return *this;
  }

private:
  int i;
};

int main(){
  // Constructor is called.
  A a(5);
  // Copy constructor should be called.
  A b(a);
  // Copy constructor should be called. Therefore, the following are equivalent:
  // A b(a);
  // A c = a;
  A c = a;
  // Assignment operator should be called.
  c = a;

  return 0;
}
