#include <iostream>
using namespace std;

struct A
{
  //! 4-byte int.
  int a;
  //! 2-byte int.
  short int b;
  //! 2-byte int.
  short int c;

  void print()
  {
    cout << "A: a=" << a << ", b=" << b << ", c=" << c << endl;
  }
};

struct B
{
  //! 2-byte int.
  short int a;
  //! 2-byte int.
  short int b;
  //! 4-byte int.
  int c;

  void print()
  {
    cout << "B: a=" << a << ", b=" << b << ", c=" << c << endl;
  }
};

int main()
{
  A * a = new A();
  a->a = 2147483647;
  a->b = 10;
  a->print();

  cout << "sizeof(A): " << sizeof(A) << endl;

  B * b = reinterpret_cast<B *>(a);
  b->print();

  cout << "sizeof(B): " << sizeof(B) << endl;

  delete a;

  return 0;
}
