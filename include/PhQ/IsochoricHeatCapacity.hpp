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

#include "Quantity/DimensionalScalar.hpp"
#include "SpecificHeatRatio.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Isochoric heat capacity, also known as heat capacity at constant volume.
class IsochoricHeatCapacity
  : public DimensionalScalarQuantity<Unit::HeatCapacity> {
public:
  constexpr IsochoricHeatCapacity() noexcept
    : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  IsochoricHeatCapacity(
      const double value, const Unit::HeatCapacity unit) noexcept
    : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr IsochoricHeatCapacity(
      const GasConstant& gas_constant,
      const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept;

  constexpr IsochoricHeatCapacity(
      const GasConstant& gas_constant,
      const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr IsochoricHeatCapacity(
      const IsobaricHeatCapacity& isobaric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr IsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const Mass& mass) noexcept;

  static constexpr IsochoricHeatCapacity Zero() noexcept {
    return IsochoricHeatCapacity{0.0};
  }

  template<Unit::HeatCapacity Unit>
  static constexpr IsochoricHeatCapacity Create(const double value) noexcept {
    return IsochoricHeatCapacity{
        StaticConvertCopy<Unit::HeatCapacity, Unit,
                          Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsochoricHeatCapacity operator+(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return IsochoricHeatCapacity{value_ + isochoric_heat_capacity.value_};
  }

  constexpr IsobaricHeatCapacity operator+(
      const GasConstant& gas_constant) const noexcept;

  constexpr IsochoricHeatCapacity operator-(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return IsochoricHeatCapacity{value_ - isochoric_heat_capacity.value_};
  }

  constexpr IsochoricHeatCapacity operator*(
      const double number) const noexcept {
    return IsochoricHeatCapacity{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept;

  constexpr IsochoricHeatCapacity operator/(
      const double number) const noexcept {
    return IsochoricHeatCapacity{value_ / number};
  }

  constexpr SpecificIsochoricHeatCapacity operator/(
      const Mass& mass) const noexcept;

  constexpr Mass operator/(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept;

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

  constexpr void operator*=(const double number) noexcept { value_ *= number; }

  constexpr void operator/=(const double number) noexcept { value_ /= number; }

private:
  explicit constexpr IsochoricHeatCapacity(const double value) noexcept
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
    const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept {
  stream << isochoric_heat_capacity.Print();
  return stream;
}

inline constexpr IsochoricHeatCapacity operator*(
    const double number,
    const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept {
  return isochoric_heat_capacity * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::IsochoricHeatCapacity> {
  inline size_t operator()(
      const PhQ::IsochoricHeatCapacity& isochoric_heat_capacity) const {
    return hash<double>()(isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
