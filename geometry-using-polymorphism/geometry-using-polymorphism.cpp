//! This code demonstrates using polymorphism to calculate the area of typical geoemtric entities.
//! Only pointer class type supports polymorphism.
//!
//! Author: Jihuan Tian
//! Date: 2017-10-04

#include <iostream>
#include <vector>

using namespace std;

//! The root class, within which common functions for geometric computation are
//! defined. The classes for actual geometric entities will be derived from this
//! class.
class Shape {
public:
  Shape() {}

  //! Base virtual area function without argument.
  virtual double area() = 0;
  //! Base virtual area function with argument.
  virtual double area(int i);
};

double Shape::area(int i) {
  cout << "Base class method area(int i) is called!" << endl;

  return -i;
}

class Triangle : public Shape {
public:
  Triangle(double h = 0, double a = 0) : _h(h), _a(a) {}
  virtual double area() { return 0.5 * _h * _a; }

  double _h;
  double _a;
};

class Rectangle : public Shape {
public:
  Rectangle(double a = 0, double b = 0) : _a(a), _b(b) {}
  virtual double area() { return _a * _b; }

  double _a;
  double _b;
};

class Polygon : public Shape {
public:
  //! Try to overload the base class' area function by changing the return type: wrong!
  //! int area() { return 1; }

  //! Overloading of the base class' area function should have the same function
  //! signature.
  double area() { return 1; }

  //! Child class' own area function which is not virtual.
  double area(int i) { return 0; }
};

int main() {
  Triangle t(3, 4);
  Rectangle r(5, 7);
  Polygon p;

  vector<Shape*> shape_pointers;
  shape_pointers.push_back(&t);
  shape_pointers.push_back(&r);
  shape_pointers.push_back(&p);

  for (unsigned int i = 0; i < shape_pointers.size(); i++) {
    cout << "Area of shape #" << i << ": " << shape_pointers[i]->area() << endl;
  }

  cout << "Area of the polygon: " << p.area(7) << endl;

  return 0;
}
