#include <iostream>

#include "proxy-class.h"

int main() {
  Proxy a;
  a.initialize();

  a.set(5);
  std::cout << a.get() << std::endl;

  a.destroy();

  return 0;
}
