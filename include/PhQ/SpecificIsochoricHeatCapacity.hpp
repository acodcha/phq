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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP

#include "IsochoricHeatCapacity.hpp"
#include "Mass.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

class SpecificIsochoricHeatCapacity
    : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {
public:
  constexpr SpecificIsochoricHeatCapacity() noexcept
      : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  SpecificIsochoricHeatCapacity(const double value,
                                const Unit::SpecificHeatCapacity unit) noexcept
      : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr SpecificIsochoricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificIsobaricHeatCapacity&
          specific_isobaric_heat_capacity) noexcept;

  constexpr SpecificIsochoricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr SpecificIsochoricHeatCapacity(
      const IsochoricHeatCapacity& isochoric_heat_capacity,
      const Mass& mass) noexcept
      : SpecificIsochoricHeatCapacity(isochoric_heat_capacity.Value() /
                                      mass.Value()) {}

  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsochoricHeatCapacity Create(
      const double value) noexcept {
    return SpecificIsochoricHeatCapacity{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit,
                          StandardUnit<Unit::SpecificHeatCapacity>>(value)};
  }

  inline SpecificIsochoricHeatCapacity operator+(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept {
    return SpecificIsochoricHeatCapacity{
        value_ + specific_isochoric_heat_capacity.value_};
  }

  inline SpecificIsobaricHeatCapacity operator+(
      const SpecificGasConstant& specific_gas_constant) const noexcept;

  inline SpecificIsochoricHeatCapacity operator-(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept {
    return SpecificIsochoricHeatCapacity{
        value_ - specific_isochoric_heat_capacity.value_};
  }

  inline SpecificIsochoricHeatCapacity operator*(
      const double number) const noexcept {
    return SpecificIsochoricHeatCapacity{value_ * number};
  }

  inline IsochoricHeatCapacity operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  inline SpecificIsobaricHeatCapacity operator*(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept;

  inline SpecificIsochoricHeatCapacity operator/(
      const double number) const noexcept {
    return SpecificIsochoricHeatCapacity{value_ / number};
  }

  inline constexpr void operator+=(
      const SpecificIsochoricHeatCapacity&
          specific_isochoric_heat_capacity) noexcept {
    value_ += specific_isochoric_heat_capacity.value_;
  }

  inline constexpr void operator-=(
      const SpecificIsochoricHeatCapacity&
          specific_isochoric_heat_capacity) noexcept {
    value_ -= specific_isochoric_heat_capacity.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificIsochoricHeatCapacity(const double value) noexcept
      : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const SpecificIsochoricHeatCapacity&
                                    specific_isochoric_heat_capacity) noexcept {
  stream << specific_isochoric_heat_capacity.Print();
  return stream;
}

inline SpecificIsochoricHeatCapacity operator*(
    const double number, const SpecificIsochoricHeatCapacity&
                             specific_isochoric_heat_capacity) noexcept {
  return specific_isochoric_heat_capacity * number;
}

inline constexpr Mass::Mass(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
    const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept
    : Mass(isochoric_heat_capacity.Value() /
           specific_isochoric_heat_capacity.Value()) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
    const Mass& mass) noexcept
    : IsochoricHeatCapacity(specific_isochoric_heat_capacity.Value() *
                            mass.Value()) {}

inline IsochoricHeatCapacity Mass::operator*(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const noexcept {
  return {specific_isochoric_heat_capacity, *this};
}

inline SpecificIsochoricHeatCapacity IsochoricHeatCapacity::operator/(
    const Mass& mass) const noexcept {
  return {*this, mass};
}

inline Mass IsochoricHeatCapacity::operator/(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const noexcept {
  return {specific_isochoric_heat_capacity, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificIsochoricHeatCapacity> {
  size_t operator()(const PhQ::SpecificIsochoricHeatCapacity&
                        specific_isochoric_heat_capacity) const {
    return hash<double>()(specific_isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
