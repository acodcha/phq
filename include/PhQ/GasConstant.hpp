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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_GAS_CONSTANT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_GAS_CONSTANT_HPP

#include "IsobaricHeatCapacity.hpp"

namespace PhQ {

// Forward declaration for class GasConstant.
class SpecificGasConstant;

// Gas constant of a gas.
class GasConstant : public DimensionalScalarQuantity<Unit::HeatCapacity> {
public:
  constexpr GasConstant() noexcept
    : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  GasConstant(const double value, const Unit::HeatCapacity unit) noexcept
    : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr GasConstant(
      const IsobaricHeatCapacity& isobaric_heat_capacity,
      const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept
    : GasConstant(
        isobaric_heat_capacity.Value() - isochoric_heat_capacity.Value()) {}

  constexpr GasConstant(const IsobaricHeatCapacity& isobaric_heat_capacity,
                        const SpecificHeatRatio& specific_heat_ratio) noexcept
    : GasConstant(isobaric_heat_capacity.Value()
                  * (1.0 - 1.0 / specific_heat_ratio.Value())) {}

  constexpr GasConstant(const IsochoricHeatCapacity& isochoric_heat_capacity,
                        const SpecificHeatRatio& specific_heat_ratio) noexcept
    : GasConstant(
        isochoric_heat_capacity.Value() * (specific_heat_ratio.Value() - 1.0)) {
  }

  constexpr GasConstant(const SpecificGasConstant& specific_gas_constant,
                        const Mass& mass) noexcept;

  static constexpr GasConstant Zero() noexcept {
    return GasConstant{0.0};
  }

  template <Unit::HeatCapacity Unit>
  static constexpr GasConstant Create(const double value) noexcept {
    return GasConstant{StaticConvertCopy<Unit::HeatCapacity, Unit,
                                         Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr GasConstant operator+(
      const GasConstant& gas_constant) const noexcept {
    return GasConstant{value_ + gas_constant.value_};
  }

  constexpr IsobaricHeatCapacity operator+(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return {*this, isochoric_heat_capacity};
  }

  constexpr GasConstant operator-(
      const GasConstant& gas_constant) const noexcept {
    return GasConstant{value_ - gas_constant.value_};
  }

  constexpr GasConstant operator*(const double number) const noexcept {
    return GasConstant{value_ * number};
  }

  constexpr GasConstant operator/(const double number) const noexcept {
    return GasConstant{value_ / number};
  }

  constexpr SpecificGasConstant operator/(const Mass& mass) const noexcept;

  constexpr Mass operator/(
      const SpecificGasConstant& specific_gas_constant) const noexcept;

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
  explicit constexpr GasConstant(const double value) noexcept
    : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const GasConstant& left, const GasConstant& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const GasConstant& gas_constant) noexcept {
  stream << gas_constant.Print();
  return stream;
}

inline constexpr GasConstant operator*(
    const double number, const GasConstant& gas_constant) noexcept {
  return gas_constant * number;
}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const GasConstant& gas_constant,
    const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept
  : SpecificHeatRatio(
      isobaric_heat_capacity.Value()
      / (isobaric_heat_capacity.Value() - gas_constant.Value())) {}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const GasConstant& gas_constant,
    const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept
  : SpecificHeatRatio(
      gas_constant.Value() / isochoric_heat_capacity.Value() + 1.0) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const GasConstant& gas_constant,
    const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept
  : IsochoricHeatCapacity(
      isobaric_heat_capacity.Value() - gas_constant.Value()) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const GasConstant& gas_constant,
    const SpecificHeatRatio& specific_heat_ratio) noexcept
  : IsochoricHeatCapacity(
      gas_constant.Value() / (specific_heat_ratio.Value() - 1.0)) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const GasConstant& gas_constant,
    const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept
  : IsobaricHeatCapacity(
      gas_constant.Value() + isochoric_heat_capacity.Value()) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const GasConstant& gas_constant,
    const SpecificHeatRatio& specific_heat_ratio) noexcept
  : IsobaricHeatCapacity(gas_constant.Value() * specific_heat_ratio.Value()
                         / (specific_heat_ratio.Value() - 1.0)) {}

inline constexpr IsobaricHeatCapacity IsochoricHeatCapacity::operator+(
    const GasConstant& gas_constant) const noexcept {
  return {gas_constant, *this};
}

inline constexpr GasConstant IsobaricHeatCapacity::operator-(
    const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
  return {*this, isochoric_heat_capacity};
}

inline constexpr IsochoricHeatCapacity IsobaricHeatCapacity::operator-(
    const GasConstant& gas_constant) const noexcept {
  return {gas_constant, *this};
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_GAS_CONSTANT_HPP
