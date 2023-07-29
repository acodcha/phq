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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_PRESSURE_HPP

#include "ForceMagnitude.hpp"
#include "PressureDifference.hpp"

namespace PhQ {

// Forward declarations for class StaticPressure.
class Direction;
class DynamicPressure;
class StaticKinematicPressure;
class Stress;
class TotalPressure;
class Traction;

// Static pressure.
class StaticPressure : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr StaticPressure() noexcept
    : DimensionalScalarQuantity<Unit::Pressure>() {}

  StaticPressure(const double value, const Unit::Pressure unit) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr StaticPressure(
      const ForceMagnitude& force_magnitude, const Area& area) noexcept
    : StaticPressure(force_magnitude.Value() / area.Value()) {}

  constexpr StaticPressure(const Traction& traction) noexcept;

  constexpr StaticPressure(const TotalPressure& total_pressure,
                           const DynamicPressure& dynamic_pressure) noexcept;

  constexpr StaticPressure(
      const StaticKinematicPressure& static_kinematic_pressure,
      const MassDensity& mass_density) noexcept;

  static constexpr StaticPressure Zero() noexcept {
    return StaticPressure{0.0};
  }

  template<Unit::Pressure Unit>
  static constexpr StaticPressure Create(const double value) noexcept {
    return StaticPressure{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr PhQ::Stress Stress() const noexcept;

  inline constexpr StaticPressure operator+(
      const StaticPressure& static_pressure) const noexcept {
    return StaticPressure{value_ + static_pressure.value_};
  }

  inline constexpr StaticPressure operator+(
      const PressureDifference& pressure_difference) const noexcept {
    return StaticPressure{value_ + pressure_difference.Value()};
  }

  inline constexpr TotalPressure operator+(
      const DynamicPressure& dynamic_pressure) const noexcept;

  inline constexpr PressureDifference operator-(
      const StaticPressure& static_pressure) const noexcept {
    return PressureDifference{value_ - static_pressure.value_};
  }

  inline constexpr StaticPressure operator-(
      const PressureDifference& pressure_difference) const noexcept {
    return StaticPressure{value_ - pressure_difference.Value()};
  }

  inline constexpr StaticPressure operator*(
      const double number) const noexcept {
    return StaticPressure{value_ * number};
  }

  inline constexpr ForceMagnitude operator*(const Area& area) const noexcept {
    return {*this, area};
  }

  inline constexpr Traction operator*(
      const Direction& direction) const noexcept;

  inline constexpr StaticPressure operator/(
      const double number) const noexcept {
    return StaticPressure{value_ / number};
  }

  inline constexpr StaticKinematicPressure operator/(
      const MassDensity& mass_density) const noexcept;

  inline constexpr void operator+=(
      const StaticPressure& static_pressure) noexcept {
    value_ += static_pressure.value_;
  }

  inline constexpr void operator+=(
      const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.Value();
  }

  inline constexpr void operator-=(
      const StaticPressure& static_pressure) noexcept {
    value_ -= static_pressure.value_;
  }

  inline constexpr void operator-=(
      const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.Value();
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr StaticPressure(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class PressureDifference;
};

inline constexpr bool operator==(
    const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const StaticPressure& static_pressure) noexcept {
  stream << static_pressure.Print();
  return stream;
}

inline constexpr StaticPressure operator*(
    const double number, const StaticPressure& static_pressure) noexcept {
  return static_pressure * number;
}

inline constexpr Area::Area(const StaticPressure& static_pressure,
                            const ForceMagnitude& force_magnitude) noexcept
  : Area(force_magnitude.Value() / static_pressure.Value()) {}

inline constexpr ForceMagnitude::ForceMagnitude(
    const StaticPressure& static_pressure, const Area& area) noexcept
  : ForceMagnitude(static_pressure.Value() * area.Value()) {}

inline constexpr ForceMagnitude Area::operator*(
    const StaticPressure& static_pressure) const noexcept {
  return {static_pressure, *this};
}

inline constexpr StaticPressure ForceMagnitude::operator/(
    const Area& area) const noexcept {
  return {*this, area};
}

inline constexpr StaticPressure PressureDifference::operator+(
    const StaticPressure& static_pressure) const noexcept {
  return StaticPressure{value_ + static_pressure.Value()};
}

inline constexpr StaticPressure PressureDifference::operator-(
    const StaticPressure& static_pressure) const noexcept {
  return StaticPressure{value_ - static_pressure.Value()};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::StaticPressure> {
  size_t operator()(const PhQ::StaticPressure& static_pressure) const {
    return hash<double>()(static_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_PRESSURE_HPP
