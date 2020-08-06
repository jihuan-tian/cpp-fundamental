/*
 * ModuleB.cpp
 *
 *  Created on: 2020年7月30日
 *      Author: jihuan
 */

#include <iostream>

#include "ModuleA.h"
#include "ModuleB.h"

void print_global_variable_from_moduleb()
{
  //! The global variable is actually defined in the main module.
  std::cout << "Global variable printed from ModuleB: " << global_variable << std::endl;
}
