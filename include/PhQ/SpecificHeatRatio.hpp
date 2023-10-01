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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_HEAT_RATIO_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_HEAT_RATIO_HPP

#include "DimensionlessScalarQuantity.hpp"

namespace PhQ {

// Forward declarations for class SpecificHeatRatio.
class GasConstant;
class IsobaricHeatCapacity;
class IsochoricHeatCapacity;
class Mass;
class SpecificGasConstant;
class SpecificIsobaricHeatCapacity;
class SpecificIsochoricHeatCapacity;

// Ratio of the isobaric and isochoric specific heats of a material.
class SpecificHeatRatio : public DimensionlessScalarQuantity {
public:
  // Default constructor. Constructs a specific heat ratio ratio with an
  // uninitialized value.
  SpecificHeatRatio() = default;

  // Constructor. Constructs a specific heat ratio with a given value.
  explicit constexpr SpecificHeatRatio(const double value)
    : DimensionlessScalarQuantity(value) {}

  // Constructor. Constructs a specific heat ratio from a given specific gas
  // constant and specific isobaric heat capacity using Mayer's relation and the
  // definition of the specific heat ratio.
  constexpr SpecificHeatRatio(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity);

  // Constructor. Constructs a specific heat ratio from a given specific gas
  // constant and specific isochoric heat capacity using Mayer's relation and
  // the definition of the specific heat ratio.
  constexpr SpecificHeatRatio(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity);

  // Constructor. Constructs a specific heat ratio from a given specific
  // isobaric heat capacity and specific isochoric heat capacity using the
  // definition of the specific heat ratio.
  constexpr SpecificHeatRatio(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity);

  // Constructor. Constructs a specific heat ratio from a given gas constant and
  // isobaric heat capacity using Mayer's relation and the definition of the
  // specific heat ratio.
  constexpr SpecificHeatRatio(
      const GasConstant& gas_constant,
      const IsobaricHeatCapacity& isobaric_heat_capacity);

  // Constructor. Constructs a specific heat ratio from a given gas constant and
  // isochoric heat capacity using Mayer's relation and the definition of the
  // specific heat ratio.
  constexpr SpecificHeatRatio(
      const GasConstant& gas_constant,
      const IsochoricHeatCapacity& isochoric_heat_capacity);

  // Constructor. Constructs a specific heat ratio from a given isobaric heat
  // capacity and isochoric heat capacity using the definition of the specific
  // heat ratio.
  constexpr SpecificHeatRatio(
      const IsobaricHeatCapacity& isobaric_heat_capacity,
      const IsochoricHeatCapacity& isochoric_heat_capacity);

  // Destructor. Destroys this specific heat ratio.
  ~SpecificHeatRatio() noexcept = default;

  // Copy constructor. Constructs a specific heat ratio by copying another one.
  constexpr SpecificHeatRatio(const SpecificHeatRatio& other) = default;

  // Move constructor. Constructs a specific heat ratio by moving another one.
  constexpr SpecificHeatRatio(SpecificHeatRatio&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific heat ratio by copying
  // another one.
  constexpr SpecificHeatRatio& operator=(
      const SpecificHeatRatio& other) = default;

  // Move assignment operator. Assigns this specific heat ratio by moving
  // another one.
  constexpr SpecificHeatRatio& operator=(
      SpecificHeatRatio&& other) noexcept = default;

  // Statically creates a specific heat ratio of zero.
  static constexpr SpecificHeatRatio Zero() {
    return SpecificHeatRatio{0.0};
  }

  constexpr SpecificHeatRatio operator+(
      const SpecificHeatRatio& specific_heat_ratio) const {
    return SpecificHeatRatio{value_ + specific_heat_ratio.value_};
  }

  constexpr SpecificHeatRatio operator-(
      const SpecificHeatRatio& specific_heat_ratio) const {
    return SpecificHeatRatio{value_ - specific_heat_ratio.value_};
  }

  constexpr SpecificHeatRatio operator*(const double number) const {
    return SpecificHeatRatio{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const;

  constexpr SpecificIsobaricHeatCapacity operator*(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const;

  constexpr SpecificHeatRatio operator/(const double number) const {
    return SpecificHeatRatio{value_ / number};
  }

  constexpr double operator/(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return value_ / specific_heat_ratio.value_;
  }

  constexpr void operator+=(
      const SpecificHeatRatio& specific_heat_ratio) noexcept {
    value_ += specific_heat_ratio.value_;
  }

  constexpr void operator-=(
      const SpecificHeatRatio& specific_heat_ratio) noexcept {
    value_ -= specific_heat_ratio.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const SpecificHeatRatio& left, const SpecificHeatRatio& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificHeatRatio& left, const SpecificHeatRatio& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificHeatRatio& left, const SpecificHeatRatio& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificHeatRatio& left, const SpecificHeatRatio& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificHeatRatio& left, const SpecificHeatRatio& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificHeatRatio& left, const SpecificHeatRatio& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const SpecificHeatRatio& specific_heat_ratio) {
  stream << specific_heat_ratio.Print();
  return stream;
}

inline constexpr SpecificHeatRatio operator+(
    const double number, const SpecificHeatRatio& specific_heat_ratio) {
  return SpecificHeatRatio{number + specific_heat_ratio.Value()};
}

inline constexpr SpecificHeatRatio operator-(
    const double number, const SpecificHeatRatio& specific_heat_ratio) {
  return SpecificHeatRatio{number - specific_heat_ratio.Value()};
}

inline constexpr SpecificHeatRatio operator*(
    const double number, const SpecificHeatRatio& specific_heat_ratio) {
  return SpecificHeatRatio{number * specific_heat_ratio.Value()};
}

inline constexpr double operator/(
    const double number,
    const SpecificHeatRatio& specific_heat_ratio) noexcept {
  return number / specific_heat_ratio.Value();
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificHeatRatio> {
  inline size_t operator()(
      const PhQ::SpecificHeatRatio& specific_heat_ratio) const {
    return hash<double>()(specific_heat_ratio.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_HEAT_RATIO_HPP
