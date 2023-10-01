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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOCHORIC_HEAT_CAPACITY_HPP

#include "DimensionalScalarQuantity.hpp"
#include "HeatCapacityRatio.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Isochoric heat capacity, also known as heat capacity at constant volume.
class IsochoricHeatCapacity
  : public DimensionalScalarQuantity<Unit::HeatCapacity> {
public:
  // Default constructor. Constructs an isochoric heat capacity with an
  // uninitialized value.
  IsochoricHeatCapacity() = default;

  // Constructor. Constructs an isochoric heat capacity with a given value
  // expressed in a given heat capacity unit.
  IsochoricHeatCapacity(const double value, const Unit::HeatCapacity unit)
    : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  // Constructor. Constructs an isochoric heat capacity from a given gas
  // constant and isobaric heat capacity using Mayer's relation.
  constexpr IsochoricHeatCapacity(
      const GasConstant& gas_constant,
      const IsobaricHeatCapacity& isobaric_heat_capacity);

  // Constructor. Constructs an isochoric heat capacity from a given gas
  // constant and heat capacity ratio using the definition of the specific heat
  // ratio and Mayer's relation.
  constexpr IsochoricHeatCapacity(const GasConstant& gas_constant,
                                  const HeatCapacityRatio& heat_capacity_ratio);

  // Constructor. Constructs an isochoric heat capacity from a given isobaric
  // heat capacity and heat capacity ratio using the definition of the specific
  // heat ratio.
  constexpr IsochoricHeatCapacity(
      const IsobaricHeatCapacity& isobaric_heat_capacity,
      const HeatCapacityRatio& heat_capacity_ratio);

  // Constructor. Constructs an isochoric heat capacity from a given specific
  // isochoric heat capacity and mass using the definition of the specific
  // isochoric heat capacity.
  constexpr IsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const Mass& mass);

  // Destructor. Destroys this isochoric heat capacity.
  ~IsochoricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs an isochoric heat capacity by copying another
  // one.
  constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity& other) = default;

  // Move constructor. Constructs an isochoric heat capacity by moving another
  // one.
  constexpr IsochoricHeatCapacity(
      IsochoricHeatCapacity&& other) noexcept = default;

  // Copy assignment operator. Assigns this isochoric heat capacity by copying
  // another one.
  constexpr IsochoricHeatCapacity& operator=(
      const IsochoricHeatCapacity& other) = default;

  // Move assignment operator. Assigns this isochoric heat capacity by moving
  // another one.
  constexpr IsochoricHeatCapacity& operator=(
      IsochoricHeatCapacity&& other) noexcept = default;

  // Statically creates an isochoric heat capacity of zero.
  static constexpr IsochoricHeatCapacity Zero() {
    return IsochoricHeatCapacity{0.0};
  }

  // Statically creates an isochoric heat capacity with a given value expressed
  // in a given heat capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr IsochoricHeatCapacity Create(const double value) {
    return IsochoricHeatCapacity{
        StaticConvertCopy<Unit::HeatCapacity, Unit,
                          Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsochoricHeatCapacity operator+(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const {
    return IsochoricHeatCapacity{value_ + isochoric_heat_capacity.value_};
  }

  constexpr IsobaricHeatCapacity operator+(
      const GasConstant& gas_constant) const;

  constexpr IsochoricHeatCapacity operator-(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const {
    return IsochoricHeatCapacity{value_ - isochoric_heat_capacity.value_};
  }

  constexpr IsochoricHeatCapacity operator*(const double number) const {
    return IsochoricHeatCapacity{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(
      const HeatCapacityRatio& heat_capacity_ratio) const;

  constexpr IsochoricHeatCapacity operator/(const double number) const {
    return IsochoricHeatCapacity{value_ / number};
  }

  constexpr SpecificIsochoricHeatCapacity operator/(const Mass& mass) const;

  constexpr Mass operator/(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const;

  constexpr double operator/(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ / isochoric_heat_capacity.value_;
  }

  constexpr void operator+=(
      const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept {
    value_ += isochoric_heat_capacity.value_;
  }

  constexpr void operator-=(
      const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept {
    value_ -= isochoric_heat_capacity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs an isochoric heat capacity with a given value
  // expressed in the standard heat capacity unit.
  explicit constexpr IsochoricHeatCapacity(const double value)
    : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}
};

inline constexpr bool operator==(const IsochoricHeatCapacity& left,
                                 const IsochoricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const IsochoricHeatCapacity& left,
                                 const IsochoricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const IsochoricHeatCapacity& left,
                                const IsochoricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const IsochoricHeatCapacity& left,
                                const IsochoricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const IsochoricHeatCapacity& left,
                                 const IsochoricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const IsochoricHeatCapacity& left,
                                 const IsochoricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const IsochoricHeatCapacity& isochoric_heat_capacity) {
  stream << isochoric_heat_capacity.Print();
  return stream;
}

inline constexpr IsochoricHeatCapacity operator*(
    const double number, const IsochoricHeatCapacity& isochoric_heat_capacity) {
  return isochoric_heat_capacity * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::IsochoricHeatCapacity> {
  inline size_t operator()(
      const PhQ::IsochoricHeatCapacity& isochoric_heat_capacity) const {
    return hash<double>()(isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
