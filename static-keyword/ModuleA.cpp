/*
 * ModuleA.cpp
 *
 *  Created on: 2020年7月30日
 *      Author: jihuan
 */

#include <iostream>
#include "ModuleA.h"

static int local_static_var = 5;

void print()
{
  std::cout << "Module local static variable: " << local_static_var << std::endl;
}

void print_global_variable()
{
  //! The global variable is actually defined in the main module.
  std::cout << "Global variable printed from ModuleA: " << global_variable << std::endl;
}
