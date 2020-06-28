// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/ConstitutiveModel/CompressibleNewtonianFluid.hpp"
#include "../include/PhQ/ConstitutiveModel/ElasticIsotropicSolid.hpp"
#include "../include/PhQ/ConstitutiveModel/IncompressibleNewtonianFluid.hpp"

int main(int argc, char *argv[]) {

  PhQ::YoungModulus aluminum_young_modulus{68.9, PhQ::Unit::Pressure::Gigapascal};
  PhQ::PoissonRatio aluminum_poisson_ratio{0.33};
  PhQ::ConstitutiveModel::ElasticIsotropicSolid aluminum{aluminum_young_modulus, aluminum_poisson_ratio};
  std::cout << "Aluminum: " << aluminum << std::endl;
  std::cout << "- E = " << aluminum.young_modulus() << std::endl;
  std::cout << "- K = " << aluminum.isentropic_bulk_modulus() << std::endl;
  std::cout << "- M = " << aluminum.p_wave_modulus() << std::endl;
  std::cout << "- ν = " << aluminum.poisson_ratio() << std::endl;
  PhQ::Strain strain{{0.010, -0.002, -0.003, 0.008, -0.004, -0.006}};
  std::cout << "- Strain: " << strain << std::endl;
  std::cout << "- Stress: " << aluminum.stress(strain) << std::endl;
  std::cout << "- Strain: " << aluminum.strain(aluminum.stress(strain)) << std::endl;

  PhQ::DynamicViscosity air_dynamic_viscosity{1.8e-5, PhQ::Unit::DynamicViscosity::PascalSecond};
  PhQ::StrainRate strain_rate{{0.010, -0.002, -0.003, 0.008, -0.004, -0.006}, PhQ::Unit::Frequency::Hertz};

  PhQ::ConstitutiveModel::IncompressibleNewtonianFluid air_incompressible{air_dynamic_viscosity};
  std::cout << "Air (Incompressible): " << air_incompressible << std::endl;
  std::cout << "- Strain Rate: " << strain_rate << std::endl;
  std::cout << "- Stress: " << air_incompressible.stress(strain_rate) << std::endl;

  PhQ::ConstitutiveModel::CompressibleNewtonianFluid air_compressible{air_dynamic_viscosity};
  std::cout << "Air (Compressible): " << air_compressible << std::endl;
  std::cout << "- Strain Rate: " << strain_rate << std::endl;
  std::cout << "- Stress: " << air_compressible.stress(strain_rate) << std::endl;

  return EXIT_SUCCESS;
}
