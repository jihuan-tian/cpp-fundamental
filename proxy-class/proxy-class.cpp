#include "proxy-class.h"

//! \brief Definition of the RealClass which is wrapped by the class Proxy.
//! Because RealClass is declared as an embedded class in class Proxy, here it
//! should be declared as *class Proxy::RealClass*.
class Proxy::RealClass {
public:
  RealClass(int vi = 0) { i = vi; }
  int get() { return i; }
  void set(int vi) { i = vi; }
private:
  int i;
};

void Proxy::initialize() {
  obj = new RealClass();
}

void Proxy::destroy() {
  delete obj;
}

int Proxy::get() {
  return obj->get();
}

void Proxy::set(int vi) {
  obj->set(vi);
}
