// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations.
class LinearThermalExpansionCoefficient;
class TemperatureDifference;

class StrainScalar : public DimensionlessScalarQuantity {

public:

  constexpr StrainScalar() noexcept : DimensionlessScalarQuantity() {}

  constexpr StrainScalar(double value) noexcept : DimensionlessScalarQuantity(value) {}

  constexpr StrainScalar(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient, const TemperatureDifference& temperature_difference) noexcept;

};

} // namespace PhQ

constexpr PhQ::StrainScalar operator+(double real, const PhQ::StrainScalar& strain_scalar) noexcept {
  return {real + strain_scalar.value()};
}

constexpr PhQ::StrainScalar operator-(double real, const PhQ::StrainScalar& strain_scalar) noexcept {
  return {real - strain_scalar.value()};
}

constexpr PhQ::StrainScalar operator*(double real, const PhQ::StrainScalar& strain_scalar) noexcept {
  return {real * strain_scalar.value()};
}

constexpr double operator/(double real, const PhQ::StrainScalar& strain_scalar) noexcept {
  return real / strain_scalar.value();
}
