// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "IsochoricHeatCapacity.hpp"

namespace PhQ {

class IsobaricHeatCapacity : public DimensionalScalarQuantity<Unit::HeatCapacity> {

public:

  constexpr IsobaricHeatCapacity() noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  constexpr IsobaricHeatCapacity(double value, Unit::HeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr IsobaricHeatCapacity(const GasConstant& gas_constant, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  constexpr IsobaricHeatCapacity(const GasConstant& gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr IsobaricHeatCapacity(const IsochoricHeatCapacity& isochoric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : IsobaricHeatCapacity(isochoric_heat_capacity.value() * specific_heat_ratio.value()) {}

  constexpr IsobaricHeatCapacity(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const Mass& mass) noexcept;

  constexpr bool operator==(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ == isobaric_heat_capacity.value_;
  }

  constexpr bool operator!=(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ != isobaric_heat_capacity.value_;
  }

  constexpr bool operator<(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ < isobaric_heat_capacity.value_;
  }

  constexpr bool operator<=(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ <= isobaric_heat_capacity.value_;
  }

  constexpr bool operator>(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ > isobaric_heat_capacity.value_;
  }

  constexpr bool operator>=(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ >= isobaric_heat_capacity.value_;
  }

  constexpr IsobaricHeatCapacity operator+(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return {value_ + isobaric_heat_capacity.value_};
  }

  constexpr void operator+=(const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value_ += isobaric_heat_capacity.value_;
  }

  constexpr IsobaricHeatCapacity operator-(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return {value_ - isobaric_heat_capacity.value_};
  }

  constexpr GasConstant operator-(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept;

  constexpr IsochoricHeatCapacity operator-(const GasConstant& gas_constant) const noexcept;

  constexpr void operator-=(const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value_ -= isobaric_heat_capacity.value_;
  }

  constexpr SpecificIsobaricHeatCapacity operator/(const Mass& mass) const noexcept;

  constexpr Mass operator/(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept;

  constexpr SpecificHeatRatio operator/(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return {*this, isochoric_heat_capacity};
  }

  constexpr IsochoricHeatCapacity operator/(const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return {*this, specific_heat_ratio};
  }

protected:

  constexpr IsobaricHeatCapacity(double value) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}

};

template <> constexpr bool sort(const IsobaricHeatCapacity& isobaric_heat_capacity_1, const IsobaricHeatCapacity& isobaric_heat_capacity_2) noexcept {
  return sort(isobaric_heat_capacity_1.value(), isobaric_heat_capacity_2.value());
}

constexpr SpecificHeatRatio::SpecificHeatRatio(const IsobaricHeatCapacity& isobaric_heat_capacity, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept : SpecificHeatRatio(isobaric_heat_capacity.value() / isochoric_heat_capacity.value()) {}

constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(const IsobaricHeatCapacity& isobaric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : IsochoricHeatCapacity(isobaric_heat_capacity.value() / specific_heat_ratio.value()) {}

constexpr IsobaricHeatCapacity SpecificHeatRatio::operator*(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
  return {isochoric_heat_capacity, *this};
}

constexpr IsobaricHeatCapacity IsochoricHeatCapacity::operator*(const SpecificHeatRatio& specific_heat_ratio) const noexcept {
  return {*this, specific_heat_ratio};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::IsobaricHeatCapacity> {
  size_t operator()(const PhQ::IsobaricHeatCapacity& isobaric_heat_capacity) const {
    return hash<double>()(isobaric_heat_capacity.value());
  }
};

} // namespace std
