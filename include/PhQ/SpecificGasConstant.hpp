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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_GAS_CONSTANT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_GAS_CONSTANT_HPP

#include "GasConstant.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"

namespace PhQ {

// Specific gas constant of a gas. Gas constant per unit mass.
class SpecificGasConstant
  : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {
public:
  constexpr SpecificGasConstant() noexcept
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  SpecificGasConstant(
      const double value, const Unit::SpecificHeatCapacity unit) noexcept
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr SpecificGasConstant(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity&
          specific_isochoric_heat_capacity) noexcept
    : SpecificGasConstant(specific_isobaric_heat_capacity.Value()
                          - specific_isochoric_heat_capacity.Value()) {}

  constexpr SpecificGasConstant(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept
    : SpecificGasConstant(specific_isobaric_heat_capacity.Value()
                          * (1.0 - 1.0 / specific_heat_ratio.Value())) {}

  constexpr SpecificGasConstant(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept
    : SpecificGasConstant(specific_isochoric_heat_capacity.Value()
                          * (specific_heat_ratio.Value() - 1.0)) {}

  constexpr SpecificGasConstant(
      const GasConstant& gas_constant, const Mass& mass) noexcept
    : SpecificGasConstant(gas_constant.Value() / mass.Value()) {}

  static constexpr SpecificGasConstant Zero() noexcept {
    return SpecificGasConstant{0.0};
  }

  template<Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificGasConstant Create(const double value) noexcept {
    return SpecificGasConstant{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit,
                          StandardUnit<Unit::SpecificHeatCapacity>>(value)};
  }

  inline constexpr SpecificGasConstant operator+(
      const SpecificGasConstant& specific_gas_constant) const noexcept {
    return SpecificGasConstant{value_ + specific_gas_constant.value_};
  }

  inline constexpr SpecificIsobaricHeatCapacity operator+(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept {
    return {*this, specific_isochoric_heat_capacity};
  }

  inline constexpr SpecificGasConstant operator-(
      const SpecificGasConstant& specific_gas_constant) const noexcept {
    return SpecificGasConstant{value_ - specific_gas_constant.value_};
  }

  inline constexpr SpecificGasConstant operator*(
      const double number) const noexcept {
    return SpecificGasConstant{value_ * number};
  }

  inline constexpr GasConstant operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  inline constexpr SpecificGasConstant operator/(
      const double number) const noexcept {
    return SpecificGasConstant{value_ / number};
  }

  inline constexpr double operator/(
      const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ / specific_gas_constant.value_;
  }

  inline constexpr void operator+=(
      const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ += specific_gas_constant.value_;
  }

  inline constexpr void operator-=(
      const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ -= specific_gas_constant.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificGasConstant(const double value) noexcept
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}
};

inline constexpr bool operator==(const SpecificGasConstant& left,
                                 const SpecificGasConstant& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const SpecificGasConstant& left,
                                 const SpecificGasConstant& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const SpecificGasConstant& left,
                                const SpecificGasConstant& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const SpecificGasConstant& left,
                                const SpecificGasConstant& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const SpecificGasConstant& left,
                                 const SpecificGasConstant& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const SpecificGasConstant& left,
                                 const SpecificGasConstant& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificGasConstant& specific_gas_constant) noexcept {
  stream << specific_gas_constant.Print();
  return stream;
}

inline constexpr SpecificGasConstant operator*(
    const double number,
    const SpecificGasConstant& specific_gas_constant) noexcept {
  return specific_gas_constant * number;
}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept
  : SpecificHeatRatio(specific_isobaric_heat_capacity.Value()
                      / (specific_isobaric_heat_capacity.Value()
                         - specific_gas_constant.Value())) {}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificIsochoricHeatCapacity&
        specific_isochoric_heat_capacity) noexcept
  : SpecificHeatRatio(
      specific_gas_constant.Value() / specific_isochoric_heat_capacity.Value()
      + 1.0) {}

inline constexpr Mass::Mass(const SpecificGasConstant& specific_gas_constant,
                            const GasConstant& gas_constant) noexcept
  : Mass(gas_constant.Value() / specific_gas_constant.Value()) {}

inline constexpr GasConstant::GasConstant(
    const SpecificGasConstant& specific_gas_constant, const Mass& mass) noexcept
  : GasConstant(specific_gas_constant.Value() * mass.Value()) {}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept
  : SpecificIsochoricHeatCapacity(
      specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value()) {
}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificHeatRatio& specific_heat_ratio) noexcept
  : SpecificIsochoricHeatCapacity(
      specific_gas_constant.Value() / (specific_heat_ratio.Value() - 1.0)) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificIsochoricHeatCapacity&
        specific_isochoric_heat_capacity) noexcept
  : SpecificIsobaricHeatCapacity(specific_gas_constant.Value()
                                 + specific_isochoric_heat_capacity.Value()) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificHeatRatio& specific_heat_ratio) noexcept
  : SpecificIsobaricHeatCapacity(
      specific_gas_constant.Value() * specific_heat_ratio.Value()
      / (specific_heat_ratio.Value() - 1.0)) {}

inline constexpr GasConstant Mass::operator*(
    const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

inline constexpr SpecificGasConstant GasConstant::operator/(
    const Mass& mass) const noexcept {
  return {*this, mass};
}

inline constexpr Mass GasConstant::operator/(
    const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

inline constexpr SpecificIsobaricHeatCapacity
SpecificIsochoricHeatCapacity::operator+(
    const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

inline constexpr SpecificGasConstant SpecificIsobaricHeatCapacity::operator-(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const noexcept {
  return {*this, specific_isochoric_heat_capacity};
}

inline constexpr SpecificIsochoricHeatCapacity
SpecificIsobaricHeatCapacity::operator-(
    const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::SpecificGasConstant> {
  size_t operator()(
      const PhQ::SpecificGasConstant& specific_gas_constant) const {
    return hash<double>()(specific_gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_GAS_CONSTANT_HPP
