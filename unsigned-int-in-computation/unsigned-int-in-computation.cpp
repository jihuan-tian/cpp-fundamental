#include <iostream>

using namespace std;

int main() {
  //! 2-byte integer.
  unsigned short a = 5;
  //! The following will output -5, which means -a is treated as a signed int.
  cout << "-a=" << -a << endl;
  //! a will be treated as an unsigned int and by assigning -5 to a, it will wrap around
  //! to the highest bit of a. Therefore, it will output 2^16-5=65531.
  a = -5;
  cout << "a=-5, then a=" << a << endl;

  //! 4-byte integer.
  unsigned int b = 5;
  //! The following will not output -5, which means -b is treated as an unsigned int.
  //! Because there is wrap-around to the highest bit of b, it will output 2^32-5=4294967291.
  cout << "-b=" << -b << endl;
  b = -5;
  cout << "b=-5, then b=" << b << endl;

  //! Therefore, according to this example, we must be very careful about the computation
  //! involving unsigned int. We had better not use unsigned int in the computation, whose
  //! behavior is abnormal.

  return 0;
}
