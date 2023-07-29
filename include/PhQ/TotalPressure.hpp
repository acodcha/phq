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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_PRESSURE_HPP

#include "DynamicPressure.hpp"

namespace PhQ {

// Total pressure.
class TotalPressure : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr TotalPressure() noexcept
    : DimensionalScalarQuantity<Unit::Pressure>() {}

  TotalPressure(const double value, const Unit::Pressure unit) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr TotalPressure(const DynamicPressure& dynamic_pressure,
                          const StaticPressure& static_pressure) noexcept
    : TotalPressure(dynamic_pressure.Value() + static_pressure.Value()) {}

  constexpr TotalPressure(
      const TotalKinematicPressure& total_kinematic_pressure,
      const MassDensity& mass_density) noexcept;

  static constexpr TotalPressure Zero() noexcept { return TotalPressure{0.0}; }

  template<Unit::Pressure Unit>
  static constexpr TotalPressure Create(const double value) noexcept {
    return TotalPressure{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr TotalPressure operator+(
      const TotalPressure& total_pressure) const noexcept {
    return TotalPressure{value_ + total_pressure.value_};
  }

  inline constexpr TotalPressure operator-(
      const TotalPressure& total_pressure) const noexcept {
    return TotalPressure{value_ - total_pressure.value_};
  }

  inline constexpr DynamicPressure operator-(
      const StaticPressure& static_pressure) const noexcept {
    return {*this, static_pressure};
  }

  inline constexpr StaticPressure operator-(
      const DynamicPressure& dynamic_pressure) const noexcept {
    return {*this, dynamic_pressure};
  }

  inline constexpr TotalPressure operator*(const double number) const noexcept {
    return TotalPressure{value_ * number};
  }

  inline constexpr TotalPressure operator/(const double number) const noexcept {
    return TotalPressure{value_ / number};
  }

  inline constexpr void operator+=(
      const TotalPressure& total_pressure) noexcept {
    value_ += total_pressure.value_;
  }

  inline constexpr void operator-=(
      const TotalPressure& total_pressure) noexcept {
    value_ -= total_pressure.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TotalPressure(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TotalPressure& total_pressure) noexcept {
  stream << total_pressure.Print();
  return stream;
}

inline constexpr TotalPressure operator*(
    const double number, const TotalPressure& total_pressure) noexcept {
  return total_pressure * number;
}

inline constexpr StaticPressure::StaticPressure(
    const TotalPressure& total_pressure,
    const DynamicPressure& dynamic_pressure) noexcept
  : StaticPressure(total_pressure.Value() - dynamic_pressure.Value()) {}

inline constexpr DynamicPressure::DynamicPressure(
    const TotalPressure& total_pressure,
    const StaticPressure& static_pressure) noexcept
  : DynamicPressure(total_pressure.Value() - static_pressure.Value()) {}

inline constexpr TotalPressure StaticPressure::operator+(
    const DynamicPressure& dynamic_pressure) const noexcept {
  return {dynamic_pressure, *this};
}

inline constexpr TotalPressure DynamicPressure::operator+(
    const StaticPressure& static_pressure) const noexcept {
  return {*this, static_pressure};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::TotalPressure> {
  size_t operator()(const PhQ::TotalPressure& total_pressure) const {
    return hash<double>()(total_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_PRESSURE_HPP
