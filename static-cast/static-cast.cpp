#include <iostream>
using namespace std;

class Parent
{
public:
  //! N.B. The destructor of a virtual class should also be declared as virtual.
  virtual ~Parent();
  virtual void print();
};

Parent::~Parent()
{
  cout << "Parent object is destroyed!" << endl;
}

void Parent::print()
{
  cout << "This is parent object." << endl;
}

class Child : public Parent
{
public:
  ~Child();
  void print();
};

Child::~Child()
{
  cout << "Child object is destroyed!" << endl;
}

void Child::print()
{
  cout << "This is child object." << endl;
}

int main()
{
  //! Type casting between C++ basic types.
  int a = 10;
  cout << "Floating point calculation: a/3=" << static_cast<double>(a)/3 << endl;

  double b = 10.0;
  cout << "Integer calculation: b/3=" << static_cast<int>(b)/3 << endl;

  //! Type casting between parent and child objects.
  Child * child_pt = new Child();
  //! Casting from child to parent class is safe.
  Parent * parent_pt = static_cast<Parent *>(child_pt);
  //! Since the parent class is declared as virtual, the inheritance has polymorphism and
  //! the following print() actually executes the Child class version.
  parent_pt->print();
  //! Explicitly call the print() of the Parent class version by adding a prefix Parent::.
  parent_pt->Parent::print();
  //! Convert back the pointer from parent to child. Unless you can make sure the actual object
  //! pointed by the parent class pointer is the child object itself, such casting from top to
  //! bottom is unsafe.
  Child * child_pt_back = static_cast<Child *>(parent_pt);
  child_pt_back->print();

  delete child_pt;

  return 0;
}
