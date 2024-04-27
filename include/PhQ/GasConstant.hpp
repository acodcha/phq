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

#ifndef PHQ_GAS_CONSTANT_HPP
#define PHQ_GAS_CONSTANT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsobaricHeatCapacity.hpp"
#include "IsochoricHeatCapacity.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Forward declaration for class GasConstant.
class SpecificGasConstant;

// Gas constant of a gas. Not to be confused with the molar gas constant or the specific gas
// constant.
class GasConstant : public DimensionalScalar<Unit::HeatCapacity> {
public:
  // Default constructor. Constructs a gas constant with an uninitialized value.
  GasConstant() = default;

  // Constructor. Constructs a gas constant with a given value expressed in a given heat capacity
  // unit.
  GasConstant(const double value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity>(value, unit) {}

  // Constructor. Constructs a gas constant from a given isobaric heat capacity and isochoric heat
  // capacity using Mayer's relation.
  constexpr GasConstant(const IsobaricHeatCapacity& isobaric_heat_capacity,
                        const IsochoricHeatCapacity& isochoric_heat_capacity)
    : GasConstant(isobaric_heat_capacity.Value() - isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a gas constant from a given isobaric heat capacity and heat capacity
  // ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio& heat_capacity_ratio,
                        const IsobaricHeatCapacity& isobaric_heat_capacity)
    : GasConstant((1.0 - 1.0 / heat_capacity_ratio.Value()) * isobaric_heat_capacity.Value()) {}

  // Constructor. Constructs a gas constant from a given isochoric heat capacity and heat capacity
  // ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio& heat_capacity_ratio,
                        const IsochoricHeatCapacity& isochoric_heat_capacity)
    : GasConstant((heat_capacity_ratio.Value() - 1.0) * isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a gas constant from a given specific gas constant and mass using the
  // definition of the specific gas constant.
  constexpr GasConstant(const SpecificGasConstant& specific_gas_constant, const Mass& mass);

  // Destructor. Destroys this gas constant.
  ~GasConstant() noexcept = default;

  // Copy constructor. Constructs a gas constant by copying another one.
  constexpr GasConstant(const GasConstant& other) = default;

  // Move constructor. Constructs a gas constant by moving another one.
  constexpr GasConstant(GasConstant&& other) noexcept = default;

  // Copy assignment operator. Assigns this gas constant by copying another one.
  constexpr GasConstant& operator=(const GasConstant& other) = default;

  // Move assignment operator. Assigns this gas constant by moving another one.
  constexpr GasConstant& operator=(GasConstant&& other) noexcept = default;

  // Statically creates a gas constant of zero.
  static constexpr GasConstant Zero() {
    return GasConstant{0.0};
  }

  // Statically creates a gas constant with a given value expressed in a given heat capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr GasConstant Create(const double value) {
    return GasConstant{
        StaticConvertCopy<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr GasConstant operator+(const GasConstant& gas_constant) const {
    return GasConstant{value_ + gas_constant.value_};
  }

  constexpr IsobaricHeatCapacity operator+(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const {
    return {isochoric_heat_capacity, *this};
  }

  constexpr GasConstant operator-(const GasConstant& gas_constant) const {
    return GasConstant{value_ - gas_constant.value_};
  }

  constexpr GasConstant operator*(const double number) const {
    return GasConstant{value_ * number};
  }

  constexpr GasConstant operator/(const double number) const {
    return GasConstant{value_ / number};
  }

  constexpr SpecificGasConstant operator/(const Mass& mass) const;

  constexpr Mass operator/(const SpecificGasConstant& specific_gas_constant) const;

  constexpr double operator/(const GasConstant& gas_constant) const noexcept {
    return value_ / gas_constant.value_;
  }

  constexpr void operator+=(const GasConstant& gas_constant) noexcept {
    value_ += gas_constant.value_;
  }

  constexpr void operator-=(const GasConstant& gas_constant) noexcept {
    value_ -= gas_constant.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a gas constant with a given value expressed in the standard heat
  // capacity unit.
  explicit constexpr GasConstant(const double value)
    : DimensionalScalar<Unit::HeatCapacity>(value) {}
};

inline constexpr bool operator==(const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const GasConstant& gas_constant) {
  stream << gas_constant.Print();
  return stream;
}

inline constexpr GasConstant operator*(const double number, const GasConstant& gas_constant) {
  return gas_constant * number;
}

inline constexpr HeatCapacityRatio::HeatCapacityRatio(
    const IsobaricHeatCapacity& isobaric_heat_capacity, const GasConstant& gas_constant)
  : HeatCapacityRatio(
      isobaric_heat_capacity.Value() / (isobaric_heat_capacity.Value() - gas_constant.Value())) {}

inline constexpr HeatCapacityRatio::HeatCapacityRatio(
    const GasConstant& gas_constant, const IsochoricHeatCapacity& isochoric_heat_capacity)
  : HeatCapacityRatio(gas_constant.Value() / isochoric_heat_capacity.Value() + 1.0) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const IsobaricHeatCapacity& isobaric_heat_capacity, const GasConstant& gas_constant)
  : IsochoricHeatCapacity(isobaric_heat_capacity.Value() - gas_constant.Value()) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const GasConstant& gas_constant, const HeatCapacityRatio& heat_capacity_ratio)
  : IsochoricHeatCapacity(gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const IsochoricHeatCapacity& isochoric_heat_capacity, const GasConstant& gas_constant)
  : IsobaricHeatCapacity(isochoric_heat_capacity.Value() + gas_constant.Value()) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const HeatCapacityRatio& heat_capacity_ratio, const GasConstant& gas_constant)
  : IsobaricHeatCapacity(
      heat_capacity_ratio.Value() * gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

inline constexpr IsobaricHeatCapacity IsochoricHeatCapacity::operator+(
    const GasConstant& gas_constant) const {
  return {*this, gas_constant};
}

inline constexpr GasConstant IsobaricHeatCapacity::operator-(
    const IsochoricHeatCapacity& isochoric_heat_capacity) const {
  return {*this, isochoric_heat_capacity};
}

inline constexpr IsochoricHeatCapacity IsobaricHeatCapacity::operator-(
    const GasConstant& gas_constant) const {
  return {*this, gas_constant};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::GasConstant> {
  inline size_t operator()(const PhQ::GasConstant& gas_constant) const {
    return hash<double>()(gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHQ_GAS_CONSTANT_HPP
