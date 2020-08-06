#include "ModuleA.h"
#include "ModuleB.h"

int global_variable = 10;

int main()
{
  //! Access the module local variable by calling the module's function.
  print();

  //! Directly access the module local variable from the main module.
  //! This can't be successfully compiled, because the static variable is hidden from the main module.
  //! std::cout << "Directly access the module local variable: " << local_static_var << std::endl;

  //! Access the global variable from ModuleA, which is visible by multiple modules.
  print_global_variable();

  //! Access the global variable from ModuleB, which is visible by multiple modules.
  print_global_variable_from_moduleb();
}
