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

#include "Quantity/DimensionlessScalar.hpp"

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
  constexpr SpecificHeatRatio() noexcept : DimensionlessScalarQuantity() {}

  explicit constexpr SpecificHeatRatio(const double value) noexcept
    : DimensionlessScalarQuantity(value) {}

  constexpr SpecificHeatRatio(const SpecificGasConstant& specific_gas_constant,
                              const SpecificIsobaricHeatCapacity&
                                  specific_isobaric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(const SpecificGasConstant& specific_gas_constant,
                              const SpecificIsochoricHeatCapacity&
                                  specific_isochoric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity&
          specific_isochoric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(
      const GasConstant& gas_constant,
      const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(
      const GasConstant& gas_constant,
      const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(
      const IsobaricHeatCapacity& isobaric_heat_capacity,
      const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  static constexpr SpecificHeatRatio Zero() noexcept {
    return SpecificHeatRatio{0.0};
  }

  constexpr SpecificHeatRatio operator+(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return SpecificHeatRatio{value_ + specific_heat_ratio.value_};
  }

  constexpr SpecificHeatRatio operator-(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return SpecificHeatRatio{value_ - specific_heat_ratio.value_};
  }

  constexpr SpecificHeatRatio operator*(const double number) const noexcept {
    return SpecificHeatRatio{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept;

  constexpr SpecificIsobaricHeatCapacity operator*(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept;

  constexpr SpecificHeatRatio operator/(const double number) const noexcept {
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

  constexpr void operator*=(const double number) noexcept { value_ *= number; }

  constexpr void operator/=(const double number) noexcept { value_ /= number; }
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
    std::ostream& stream,
    const SpecificHeatRatio& specific_heat_ratio) noexcept {
  stream << specific_heat_ratio.Print();
  return stream;
}

inline constexpr SpecificHeatRatio operator+(
    const double number,
    const SpecificHeatRatio& specific_heat_ratio) noexcept {
  return SpecificHeatRatio{number + specific_heat_ratio.Value()};
}

inline constexpr SpecificHeatRatio operator-(
    const double number,
    const SpecificHeatRatio& specific_heat_ratio) noexcept {
  return SpecificHeatRatio{number - specific_heat_ratio.Value()};
}

inline constexpr SpecificHeatRatio operator*(
    const double number,
    const SpecificHeatRatio& specific_heat_ratio) noexcept {
  return SpecificHeatRatio{number * specific_heat_ratio.Value()};
}

inline constexpr double operator/(
    const double number,
    const SpecificHeatRatio& specific_heat_ratio) noexcept {
  return number / specific_heat_ratio.Value();
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::SpecificHeatRatio> {
  inline size_t operator()(
      const PhQ::SpecificHeatRatio& specific_heat_ratio) const {
    return hash<double>()(specific_heat_ratio.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_HEAT_RATIO_HPP
