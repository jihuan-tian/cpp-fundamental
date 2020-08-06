#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

class A {
public:
  friend ostream & operator<<(const ostream & os, const A & a);

  A();

  static const int size = 10;
  // The following is wrong!
  // vector<int> array(size);
  vector<int> array;
};

ostream & operator<<(ostream & os, const A & a) {
  for (int i=0; i<A::size; i++) {
	  os << a.array[i] << " ";
  }

  return os;
}

A::A() {
  array.reserve(size);

  for (int i=0; i<size; i++) {
    array.push_back(i);
  }
}

int main() {
  A a;

  cout << "Dimension: " << a.array.size() << endl;
  cout << a << endl;

  return 0;
}
