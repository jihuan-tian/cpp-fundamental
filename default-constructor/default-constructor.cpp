#include <iostream>

using namespace std;

class A {
public:
  //! Default constructor

  //! This is duplicate with the constructor with default argument. The compiler
  //! will complain with the following message:
  //! ```
  //! call of overloaded ‘A()’ is ambiguous
  //! ```
  //! A () : x(0) { cout << "Default constructor." << endl; }

  //! Constructor with default argument.
  A (int i = 0) : x(i) { cout << "Constructor with default argument." << endl; }

private:
  int x;
};

int main() {
  A a;
  A b(2);

  return 0;
}
