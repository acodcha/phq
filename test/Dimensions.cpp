// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#include "../lib/Dimension/Set.hpp"

int main(int argc, char *argv[]) {

  PhQ::Dimension::Set dimension_set_1;
  std::cout << "Dimension Set 1:" << std::endl;
  std::cout << "- Print: " << dimension_set_1 << std::endl;
  std::cout << "- JSON: " << dimension_set_1.json() << std::endl;
  std::cout << "- XML: " << dimension_set_1.xml() << std::endl;

  PhQ::Dimension::Set dimension_set_2{{-3}, {2}, {-1}};
  std::cout << "Dimension Set 2:" << std::endl;
  std::cout << "- Print: " << dimension_set_2 << std::endl;
  std::cout << "- JSON: " << dimension_set_2.json() << std::endl;
  std::cout << "- XML: " << dimension_set_2.xml() << std::endl;

  PhQ::Dimension::Set dimension_set_3{{7}, {-6}, {5}, {-4}, {3}, {-2}, {1}};
  std::cout << "Dimension Set 3:" << std::endl;
  std::cout << "- Print: " << dimension_set_3 << std::endl;
  std::cout << "- JSON: " << dimension_set_3.json() << std::endl;
  std::cout << "- XML: " << dimension_set_3.xml() << std::endl;

  return EXIT_SUCCESS;
}
