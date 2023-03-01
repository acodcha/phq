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

#include "../include/PhQ/ThermodynamicStateModel/IdealGas.hpp"
#include "../include/PhQ/ThermodynamicStateModel/IncompressibleFluid.hpp"

namespace PhQ {

namespace {

TEST(OldThermodynamicStateModels, Simple) {
  PhQ::MassDensity mass_density_1{
      999.0, PhQ::Unit::MassDensity::KilogramPerCubicMetre};
  PhQ::SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_1{
      4190.0, PhQ::Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  PhQ::ThermodynamicStateModel::IncompressibleFluid model_1{
      mass_density_1, specific_isobaric_heat_capacity_1};
  std::cout << "Thermodynamic State Model 1:" << std::endl;
  std::cout << "- Print: " << model_1.Print() << std::endl;
  std::cout << "- JSON: " << model_1.Json() << std::endl;
  std::cout << "- XML: " << model_1.Xml() << std::endl;

  PhQ::SpecificGasConstant specific_gas_constant_2{
      287.0, PhQ::Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  PhQ::SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_2{
      1006.0, PhQ::Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  PhQ::ThermodynamicStateModel::IdealGas model_2{
      specific_gas_constant_2, specific_isobaric_heat_capacity_2};
  std::cout << "Thermodynamic State Model 2:" << std::endl;
  std::cout << "- Print: " << model_2.Print() << std::endl;
  std::cout << "- JSON: " << model_2.Json() << std::endl;
  std::cout << "- XML: " << model_2.Xml() << std::endl;
}

}  // namespace

}  // namespace PhQ
