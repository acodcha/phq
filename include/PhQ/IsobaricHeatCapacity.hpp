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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOBARIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOBARIC_HEAT_CAPACITY_HPP

#include "IsochoricHeatCapacity.hpp"

namespace PhQ {

class IsobaricHeatCapacity
    : public DimensionalScalarQuantity<Unit::HeatCapacity> {
public:
  constexpr IsobaricHeatCapacity() noexcept
      : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  IsobaricHeatCapacity(const double value,
                       const Unit::HeatCapacity unit) noexcept
      : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr IsobaricHeatCapacity(
      const GasConstant& gas_constant,
      const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  constexpr IsobaricHeatCapacity(
      const GasConstant& gas_constant,
      const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr IsobaricHeatCapacity(
      const IsochoricHeatCapacity& isochoric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept
      : IsobaricHeatCapacity(isochoric_heat_capacity.Value() *
                             specific_heat_ratio.Value()) {}

  constexpr IsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const Mass& mass) noexcept;

  inline IsobaricHeatCapacity operator+(
      const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return IsobaricHeatCapacity{value_ + isobaric_heat_capacity.value_};
  }

  inline IsobaricHeatCapacity operator-(
      const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return IsobaricHeatCapacity{value_ - isobaric_heat_capacity.value_};
  }

  inline GasConstant operator-(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept;

  inline IsochoricHeatCapacity operator-(
      const GasConstant& gas_constant) const noexcept;

  inline IsobaricHeatCapacity operator*(const double number) const noexcept {
    return IsobaricHeatCapacity{value_ * number};
  }

  inline IsobaricHeatCapacity operator/(const double number) const noexcept {
    return IsobaricHeatCapacity{value_ / number};
  }

  inline SpecificIsobaricHeatCapacity operator/(
      const Mass& mass) const noexcept;

  inline Mass operator/(const SpecificIsobaricHeatCapacity&
                            specific_isobaric_heat_capacity) const noexcept;

  inline SpecificHeatRatio operator/(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return {*this, isochoric_heat_capacity};
  }

  inline IsochoricHeatCapacity operator/(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return {*this, specific_heat_ratio};
  }

  inline constexpr void operator+=(
      const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value_ += isobaric_heat_capacity.value_;
  }

  inline constexpr void operator-=(
      const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value_ -= isobaric_heat_capacity.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr IsobaricHeatCapacity(const double value) noexcept
      : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}
};

inline constexpr bool operator==(const IsobaricHeatCapacity& left,
                                 const IsobaricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const IsobaricHeatCapacity& left,
                                 const IsobaricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const IsobaricHeatCapacity& left,
                                const IsobaricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const IsobaricHeatCapacity& left,
                                const IsobaricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const IsobaricHeatCapacity& left,
                                 const IsobaricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const IsobaricHeatCapacity& left,
                                 const IsobaricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
  stream << isobaric_heat_capacity.Print();
  return stream;
}

inline IsobaricHeatCapacity operator*(
    const double number,
    const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
  return isobaric_heat_capacity * number;
}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const IsobaricHeatCapacity& isobaric_heat_capacity,
    const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept
    : SpecificHeatRatio(isobaric_heat_capacity.Value() /
                        isochoric_heat_capacity.Value()) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const IsobaricHeatCapacity& isobaric_heat_capacity,
    const SpecificHeatRatio& specific_heat_ratio) noexcept
    : IsochoricHeatCapacity(isobaric_heat_capacity.Value() /
                            specific_heat_ratio.Value()) {}

inline IsobaricHeatCapacity SpecificHeatRatio::operator*(
    const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
  return {isochoric_heat_capacity, *this};
}

inline IsobaricHeatCapacity IsochoricHeatCapacity::operator*(
    const SpecificHeatRatio& specific_heat_ratio) const noexcept {
  return {*this, specific_heat_ratio};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::IsobaricHeatCapacity> {
  size_t operator()(
      const PhQ::IsobaricHeatCapacity& isobaric_heat_capacity) const {
    return hash<double>()(isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOBARIC_HEAT_CAPACITY_HPP
