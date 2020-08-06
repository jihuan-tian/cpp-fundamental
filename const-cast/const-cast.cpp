#include <iostream>
using namespace std;

int main()
{
  const int a = 10;

  //! Try to use a traditional way to modify a constant via casting const pointer to a nonconst pointer.
  //! However, this operation as below does not work, even if a_var_pt and a_pt point to a same address.
  const int * a_pt = &a;
  int * a_var_pt = (int *) a_pt;
  *a_var_pt = 12;

  cout << "a_pt: \t" << a_pt << endl;
  cout << "a_var_pt: \t" << a_var_pt << endl;
  cout << "Modified(failed) a=" << a << endl;

  //! Try to use const_cast to remove the const constraint. However, this operation still fails, because
  //! the value pointed by the pointer is itself a constant, which can never be changed.
  int * a_const_cast_pt = const_cast<int *>(a_pt);
  *a_const_cast_pt = 14;
  cout << "Modified(failed) a=" << a << endl;

  //! If the original value is not a const, both the above methods work.
  int b = 10;
  const int * b_pt = (const int *) &b;
  int * b_var_pt = (int *) b_pt;
  *b_var_pt = 12;

  cout << "b_pt: \t" << b_pt << endl;
  cout << "b_var_pt: \t" << b_var_pt << endl;
  cout << "Modified b=" << b << endl;

  int * b_const_cast_pt = const_cast<int *>(b_pt);
  *b_const_cast_pt = 14;
  cout << "Modified b=" << b << endl;
}
