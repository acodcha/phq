// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include <gtest/gtest.h>

#include "../include/PhQ/ConstitutiveModel/CompressibleNewtonianFluid.hpp"
#include "../include/PhQ/ConstitutiveModel/ElasticIsotropicSolid.hpp"
#include "../include/PhQ/ConstitutiveModel/IncompressibleNewtonianFluid.hpp"

namespace PhQ {

namespace {

TEST(OldConstitutiveModels, Simple) {
  YoungModulus aluminum_young_modulus{68.9, Unit::Pressure::Gigapascal};
  PoissonRatio aluminum_poisson_ratio{0.33};
  ElasticIsotropicSolid aluminum{aluminum_young_modulus,
                                 aluminum_poisson_ratio};
  std::cout << "Aluminum: " << aluminum.Print() << std::endl;
  std::cout << "- E = " << aluminum.YoungModulus() << std::endl;
  std::cout << "- K = " << aluminum.IsentropicBulkModulus() << std::endl;
  std::cout << "- M = " << aluminum.PWaveModulus() << std::endl;
  std::cout << "- ν = " << aluminum.PoissonRatio() << std::endl;
  const Strain strain{{0.010, -0.002, -0.003, 0.008, -0.004, -0.006}};
  std::cout << "- Strain: " << strain << std::endl;
  std::cout << "- Stress: " << aluminum.Stress(strain, {}) << std::endl;
  std::cout << "- Strain: " << aluminum.Strain(aluminum.Stress(strain, {}))
            << std::endl;

  DynamicViscosity air_dynamic_viscosity{1.8e-5,
                                         Unit::DynamicViscosity::PascalSecond};
  StrainRate strain_rate{{0.010, -0.002, -0.003, 0.008, -0.004, -0.006},
                         Unit::Frequency::Hertz};

  const std::unique_ptr<ConstitutiveModel> model0 =
      std::make_unique<ElasticIsotropicSolid>(ElasticIsotropicSolid{
          aluminum_young_modulus, aluminum_poisson_ratio});
  std::cout << model0->Print();
  std::cout << "- Stress: " << model0->Stress(strain, {}) << std::endl;

  IncompressibleNewtonianFluid air_incompressible{air_dynamic_viscosity};
  std::cout << "Air (Incompressible): " << air_incompressible.Print()
            << std::endl;
  std::cout << "- Strain Rate: " << strain_rate << std::endl;
  std::cout << "- Stress: " << air_incompressible.Stress({}, strain_rate)
            << std::endl;

  CompressibleNewtonianFluid air_compressible{air_dynamic_viscosity};
  std::cout << "Air (Compressible): " << air_compressible.Print() << std::endl;
  std::cout << "- Strain Rate: " << strain_rate << std::endl;
  std::cout << "- Stress: " << air_compressible.Stress({}, strain_rate)
            << std::endl;
}

}  // namespace

}  // namespace PhQ
