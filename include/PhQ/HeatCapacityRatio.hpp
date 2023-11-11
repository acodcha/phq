// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_CAPACITY_RATIO_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_CAPACITY_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations for class HeatCapacityRatio.
class GasConstant;
class IsobaricHeatCapacity;
class IsochoricHeatCapacity;
class Mass;
class SpecificGasConstant;
class SpecificIsobaricHeatCapacity;
class SpecificIsochoricHeatCapacity;

// Heat capacity ratio, also known as ratio of specific heats, adiabatic index, or Laplace's
// coefficient. The heat capacity ratio is the ratio of the isobaric heat capacity of a material to
// its isochoric heat capacity.
class HeatCapacityRatio : public DimensionlessScalar {
public:
  // Default constructor. Constructs a heat capacity ratio ratio with an uninitialized value.
  HeatCapacityRatio() = default;

  // Constructor. Constructs a heat capacity ratio with a given value.
  explicit constexpr HeatCapacityRatio(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a heat capacity ratio from a given specific gas constant and specific
  // isobaric heat capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
                              const SpecificGasConstant& specific_gas_constant);

  // Constructor. Constructs a heat capacity ratio from a given specific gas constant and specific
  // isochoric heat capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity);

  // Constructor. Constructs a heat capacity ratio from a given specific isobaric heat capacity and
  // specific isochoric heat capacity using the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity);

  // Constructor. Constructs a heat capacity ratio from a given gas constant and isobaric heat
  // capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const IsobaricHeatCapacity& isobaric_heat_capacity, const GasConstant& gas_constant);

  // Constructor. Constructs a heat capacity ratio from a given gas constant and isochoric heat
  // capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const GasConstant& gas_constant, const IsochoricHeatCapacity& isochoric_heat_capacity);

  // Constructor. Constructs a heat capacity ratio from a given isobaric heat capacity and isochoric
  // heat capacity using the definition of the specific heat ratio.
  constexpr HeatCapacityRatio(const IsobaricHeatCapacity& isobaric_heat_capacity,
                              const IsochoricHeatCapacity& isochoric_heat_capacity);

  // Destructor. Destroys this heat capacity ratio.
  ~HeatCapacityRatio() noexcept = default;

  // Copy constructor. Constructs a heat capacity ratio by copying another one.
  constexpr HeatCapacityRatio(const HeatCapacityRatio& other) = default;

  // Move constructor. Constructs a heat capacity ratio by moving another one.
  constexpr HeatCapacityRatio(HeatCapacityRatio&& other) noexcept = default;

  // Copy assignment operator. Assigns this heat capacity ratio by copying another one.
  constexpr HeatCapacityRatio& operator=(const HeatCapacityRatio& other) = default;

  // Move assignment operator. Assigns this heat capacity ratio by moving another one.
  constexpr HeatCapacityRatio& operator=(HeatCapacityRatio&& other) noexcept = default;

  // Statically creates a heat capacity ratio of zero.
  static constexpr HeatCapacityRatio Zero() {
    return HeatCapacityRatio{0.0};
  }

  constexpr HeatCapacityRatio operator+(const HeatCapacityRatio& heat_capacity_ratio) const {
    return HeatCapacityRatio{value_ + heat_capacity_ratio.value_};
  }

  constexpr HeatCapacityRatio operator-(const HeatCapacityRatio& heat_capacity_ratio) const {
    return HeatCapacityRatio{value_ - heat_capacity_ratio.value_};
  }

  constexpr HeatCapacityRatio operator*(const double number) const {
    return HeatCapacityRatio{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const;

  constexpr SpecificIsobaricHeatCapacity operator*(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const;

  constexpr HeatCapacityRatio operator/(const double number) const {
    return HeatCapacityRatio{value_ / number};
  }

  constexpr double operator/(const HeatCapacityRatio& heat_capacity_ratio) const noexcept {
    return value_ / heat_capacity_ratio.value_;
  }

  constexpr void operator+=(const HeatCapacityRatio& heat_capacity_ratio) noexcept {
    value_ += heat_capacity_ratio.value_;
  }

  constexpr void operator-=(const HeatCapacityRatio& heat_capacity_ratio) noexcept {
    value_ -= heat_capacity_ratio.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const HeatCapacityRatio& left, const HeatCapacityRatio& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const HeatCapacityRatio& left, const HeatCapacityRatio& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const HeatCapacityRatio& left, const HeatCapacityRatio& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const HeatCapacityRatio& left, const HeatCapacityRatio& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const HeatCapacityRatio& left, const HeatCapacityRatio& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const HeatCapacityRatio& left, const HeatCapacityRatio& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const HeatCapacityRatio& heat_capacity_ratio) {
  stream << heat_capacity_ratio.Print();
  return stream;
}

inline constexpr HeatCapacityRatio operator*(
    const double number, const HeatCapacityRatio& heat_capacity_ratio) {
  return HeatCapacityRatio{number * heat_capacity_ratio.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::HeatCapacityRatio> {
  inline size_t operator()(const PhQ::HeatCapacityRatio& heat_capacity_ratio) const {
    return hash<double>()(heat_capacity_ratio.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_CAPACITY_RATIO_HPP
