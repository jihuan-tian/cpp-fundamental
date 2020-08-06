//! This code demonstrates the conversion between different types, such as
//! signed and unsigned, long and short bytes, etc.
//!
//! Author: Jihuan Tian
//! Date: 2017-10-19

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char * argv[]) {
  //! Print the length of typical data types.
  cout << "Data type length:\n";
  cout << "char\t\t\t\t" << sizeof(char) << "\n";
  cout << "signed char\t\t\t" << sizeof(signed char) << "\n";
  cout << "unsigned char\t\t\t" << sizeof(unsigned char) << "\n";

  cout << "short int\t\t\t" << sizeof(short int) << "\n";
  cout << "short unsigned int\t\t" << sizeof(short unsigned int) << "\n";
  cout << "int\t\t\t\t" << sizeof(int) << "\n";
  cout << "unsigned int\t\t\t" << sizeof(unsigned int) << "\n";
  cout << "long int\t\t\t" << sizeof(long int) << "\n";
  cout << "long long int\t\t\t" << sizeof(long long int) << "\n";
  cout << "float\t\t\t\t" << sizeof(float) << "\n";
  cout << "double\t\t\t\t" << sizeof(double) << "\n";

  //! Convert unsigned char to signed and unsigned int.
  cout << "\nConvert unsigned char to signed and unsigned int." << endl;
  unsigned char a = 233;

  short int a_short_int = a;
  short unsigned int a_short_uint = a;
  cout << "a_short_int=" << a_short_int << ", a_short_uint=" << a_short_uint << endl;

  int a_int = a;
  unsigned int a_uint = a;
  cout << "a_int=" << a_int << ", a_uint=" << a_uint << endl;

  long int a_long_int = a;
  long unsigned int a_long_uint = (long unsigned int) a;
  cout << "a_long_int=" << a_long_int << ", a_long_uint=" << a_long_uint << endl;

  //! Convert signed char to signed int and unsigned int.
  cout << "\nConvert signed char to signed and unsigned int." << endl;
  signed char b = 233;

  short int b_sint = b;
  short unsigned int b_suint = b;
  cout << "b_sint=" << b_sint << ", b_suint=" << b_suint << endl;

  int b_int = b;
  unsigned int b_uint = b;
  cout << "b_int=" << b_int << ", b_uint=" << b_uint << endl;

  long int b_lint = b;
  long unsigned int b_luint = b;
  cout << "b_lint=" << b_lint << ", b_luint=" << b_luint << endl;

  //! Convert between int and unsigned int.
  short int c_sint = 65533;
  short unsigned int c_suint = c_sint;
  cout << "c_sint=" << c_sint << ", c_suint=" << c_suint << endl;

  //! Convert from int to short int.
  int d_int = 0xfeeef010;
  short int d_sint = d_int;
  short unsigned int d_suint = d_int;
  cout << "d_sint=" << d_sint << ", d_suint=" << d_suint << endl;
}
