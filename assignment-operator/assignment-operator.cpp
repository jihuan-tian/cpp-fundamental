//! \file This code demonstrates the definition of overloaded assignment
//! operator and show the incorrect use of multiple assignment.

#include <iostream>

using namespace std;

class A_assignment_return_by_val {
public:
  friend ostream& operator<<(ostream& out, const A_assignment_return_by_val & a);
  friend void SetX(A_assignment_return_by_val & a, int v);

  //! Default constructor
  A_assignment_return_by_val(int u = 0, int v = 0) : x(u), y(v) {}
  //! Copy constructor
  A_assignment_return_by_val(const A_assignment_return_by_val & b) : x(b.x), y(b.y) {}

  //! Assignment returns a copy of the object.
  A_assignment_return_by_val operator=(const A_assignment_return_by_val & v) { x = v.x; y = v.y; return *this; }

private:
  int x;
  int y;
};

class A_assignment_return_by_ref {
public:
  friend ostream& operator<<(ostream& out, const A_assignment_return_by_ref & a);
  friend void SetX(A_assignment_return_by_ref & a, int v);

  //! Default constructor
  A_assignment_return_by_ref(int u = 0, int v = 0) : x(u), y(v) {}
  //! Copy constructor
  A_assignment_return_by_ref(const A_assignment_return_by_ref & b) : x(b.x), y(b.y) {}

  //! Assignment returns a reference to the object.
  A_assignment_return_by_ref& operator=(const A_assignment_return_by_ref & v) { x = v.x; y = v.y; return *this; }

private:
  int x;
  int y;
};

ostream& operator<<(ostream& out, const A_assignment_return_by_val & a) {
  out << a.x << ", " << a.y << endl;
  return out;
}

ostream& operator<<(ostream& out, const A_assignment_return_by_ref & a) {
  out << a.x << ", " << a.y << endl;
  return out;
}

void SetX(A_assignment_return_by_ref & a, int v) { a.x = v; }
void SetX(A_assignment_return_by_val & a, int v) { a.x = v; }

int main() {
  A_assignment_return_by_val a(1,3);
  A_assignment_return_by_val b(2,4);
  A_assignment_return_by_val c(3,5);

  cout << "Assignment returns value\n";
  cout << "a = b: " << (a = b);
  cout << "a: " << a;
  cout << "(a = b) = c: " << ((a = b) = c);
  cout << "a: " << a;

  A_assignment_return_by_ref d(1,3);
  A_assignment_return_by_ref e(2,4);
  A_assignment_return_by_ref f(3,5);

  cout << "Assignment returns reference\n";
  cout << "d = e: " << (d = e);
  cout << "d: " << d;
  cout << "(d = e) = f: " << ((d = e) = f);
  cout << "d: " << d;

  // Temporary object as an lvalue is mutable.
  cout << "Assign value to temporary object as lvalue\n";
  cout << (A_assignment_return_by_val(1,1) = c);
  cout << (A_assignment_return_by_ref(1,1) = f);

  cout << "Modify temporary object's value\n";
  // This is wrong! Because temporary object as an rvalue is treated as const.
  // SetX(A_assignment_return_by_ref(1,1), 5);
  //! This is correct.
  SetX(d, 5);
  cout << "d: " << d;

  return 0;
}
