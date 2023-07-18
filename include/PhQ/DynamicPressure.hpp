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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_PRESSURE_HPP

#include "Base/SquareRoot.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declaration for class DynamicPressure.
class DynamicKinematicPressure;

class DynamicPressure : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr DynamicPressure() noexcept
    : DimensionalScalarQuantity<Unit::Pressure>() {}

  DynamicPressure(const double value, const Unit::Pressure unit) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr DynamicPressure(
      const MassDensity& mass_density, const Speed& speed) noexcept
    : DynamicPressure(0.5 * mass_density.Value() * std::pow(speed.Value(), 2)) {
  }

  constexpr DynamicPressure(const TotalPressure& total_pressure,
                            const StaticPressure& static_pressure) noexcept;

  constexpr DynamicPressure(
      const DynamicKinematicPressure& dynamic_kinematic_pressure,
      const MassDensity& mass_density) noexcept;

  template<Unit::Pressure Unit>
  static constexpr DynamicPressure Create(const double value) noexcept {
    return DynamicPressure{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr DynamicPressure operator+(
      const DynamicPressure& dynamic_pressure) const noexcept {
    return DynamicPressure{value_ + dynamic_pressure.value_};
  }

  inline constexpr TotalPressure operator+(
      const StaticPressure& static_pressure) const noexcept;

  inline constexpr DynamicPressure operator-(
      const DynamicPressure& dynamic_pressure) const noexcept {
    return DynamicPressure{value_ - dynamic_pressure.value_};
  }

  inline constexpr DynamicPressure operator*(
      const double number) const noexcept {
    return DynamicPressure{value_ * number};
  }

  inline constexpr DynamicPressure operator/(
      const double number) const noexcept {
    return DynamicPressure{value_ / number};
  }

  inline constexpr void operator+=(
      const DynamicPressure& dynamic_pressure) noexcept {
    value_ += dynamic_pressure.value_;
  }

  inline constexpr void operator-=(
      const DynamicPressure& dynamic_pressure) noexcept {
    value_ -= dynamic_pressure.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr DynamicPressure(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const DynamicPressure& dynamic_pressure) noexcept {
  stream << dynamic_pressure.Print();
  return stream;
}

inline constexpr DynamicPressure operator*(
    const double number, const DynamicPressure& dynamic_pressure) noexcept {
  return dynamic_pressure * number;
}

inline constexpr MassDensity::MassDensity(
    const DynamicPressure& dynamic_pressure, const Speed& speed) noexcept
  : MassDensity(
      2.0 * dynamic_pressure.Value() / (speed.Value() * speed.Value())) {}

inline constexpr Speed::Speed(const DynamicPressure& dynamic_pressure,
                              const MassDensity& mass_density) noexcept
  : Speed(SquareRoot(2.0 * dynamic_pressure.Value() / mass_density.Value())) {}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::DynamicPressure> {
  size_t operator()(const PhQ::DynamicPressure& dynamic_pressure) const {
    return hash<double>()(dynamic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_PRESSURE_HPP
