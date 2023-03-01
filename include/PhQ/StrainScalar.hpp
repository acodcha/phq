// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

StrainScalar operator+(double real, const StrainScalar& strain_scalar) noexcept {
  return {real + strain_scalar.Value()};
}

StrainScalar operator-(double real, const StrainScalar& strain_scalar) noexcept {
  return {real - strain_scalar.Value()};
}

StrainScalar operator*(double real, const StrainScalar& strain_scalar) noexcept {
  return {real * strain_scalar.Value()};
}

constexpr double operator/(double real, const StrainScalar& strain_scalar) noexcept {
  return real / strain_scalar.Value();
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::StrainScalar> {
  size_t operator()(const PhQ::StrainScalar& strain_scalar) const {
    return hash<double>()(strain_scalar.Value());
  }
};

} // namespace std
