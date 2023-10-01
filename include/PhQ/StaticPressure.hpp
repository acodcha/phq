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
  // Default constructor. Constructs a static pressure with an uninitialized
  // value.
  StaticPressure() = default;

  // Constructor. Constructs a static pressure with a given value expressed in a
  // given pressure unit.
  StaticPressure(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a static pressure from a given force magnitude and
  // area using the definition of pressure.
  constexpr StaticPressure(
      const ForceMagnitude& force_magnitude, const Area& area)
    : StaticPressure(force_magnitude.Value() / area.Value()) {}

  // Constructor. Constructs a static pressure from a given traction vector.
  StaticPressure(const Traction& traction);

  // Constructor. Constructs a static pressure from a given total pressure and
  // dynamic pressure using the definition of total pressure.
  constexpr StaticPressure(const TotalPressure& total_pressure,
                           const DynamicPressure& dynamic_pressure);

  // Constructor. Constructs a static pressure from a given static kinematic
  // pressure and mass density using the definition of static kinematic
  // pressure.
  constexpr StaticPressure(
      const StaticKinematicPressure& static_kinematic_pressure,
      const MassDensity& mass_density);

  // Destructor. Destroys this static pressure.
  ~StaticPressure() noexcept = default;

  // Copy constructor. Constructs a static pressure by copying another one.
  constexpr StaticPressure(const StaticPressure& other) = default;

  // Move constructor. Constructs a static pressure by moving another one.
  constexpr StaticPressure(StaticPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this static pressure by copying another
  // one.
  constexpr StaticPressure& operator=(const StaticPressure& other) = default;

  // Move assignment operator. Assigns this static pressure by moving another
  // one.
  constexpr StaticPressure& operator=(
      StaticPressure&& other) noexcept = default;

  // Statically creates a static pressure of zero.
  static constexpr StaticPressure Zero() {
    return StaticPressure{0.0};
  }

  // Statically creates a static pressure with a given value expressed in a
  // given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr StaticPressure Create(const double value) {
    return StaticPressure{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr PhQ::Stress Stress() const;

  constexpr StaticPressure operator+(
      const StaticPressure& static_pressure) const {
    return StaticPressure{value_ + static_pressure.value_};
  }

  constexpr StaticPressure operator+(
      const PressureDifference& pressure_difference) const {
    return StaticPressure{value_ + pressure_difference.Value()};
  }

  constexpr TotalPressure operator+(
      const DynamicPressure& dynamic_pressure) const;

  constexpr PressureDifference operator-(
      const StaticPressure& static_pressure) const {
    return PressureDifference{value_ - static_pressure.value_};
  }

  constexpr StaticPressure operator-(
      const PressureDifference& pressure_difference) const {
    return StaticPressure{value_ - pressure_difference.Value()};
  }

  constexpr StaticPressure operator*(const double number) const {
    return StaticPressure{value_ * number};
  }

  constexpr ForceMagnitude operator*(const Area& area) const {
    return {*this, area};
  }

  constexpr Traction operator*(const Direction& direction) const;

  constexpr StaticPressure operator/(const double number) const {
    return StaticPressure{value_ / number};
  }

  constexpr StaticKinematicPressure operator/(
      const MassDensity& mass_density) const;

  constexpr double operator/(
      const StaticPressure& static_pressure) const noexcept {
    return value_ / static_pressure.value_;
  }

  constexpr void operator+=(const StaticPressure& static_pressure) noexcept {
    value_ += static_pressure.value_;
  }

  constexpr void operator+=(
      const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.Value();
  }

  constexpr void operator-=(const StaticPressure& static_pressure) noexcept {
    value_ -= static_pressure.value_;
  }

  constexpr void operator-=(
      const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.Value();
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a static pressure with a given value expressed in
  // the standard pressure unit.
  explicit constexpr StaticPressure(const double value)
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
    std::ostream& stream, const StaticPressure& static_pressure) {
  stream << static_pressure.Print();
  return stream;
}

inline constexpr StaticPressure operator*(
    const double number, const StaticPressure& static_pressure) {
  return static_pressure * number;
}

inline constexpr Area::Area(const StaticPressure& static_pressure,
                            const ForceMagnitude& force_magnitude)
  : Area(force_magnitude.Value() / static_pressure.Value()) {}

inline constexpr ForceMagnitude::ForceMagnitude(
    const StaticPressure& static_pressure, const Area& area)
  : ForceMagnitude(static_pressure.Value() * area.Value()) {}

inline constexpr ForceMagnitude Area::operator*(
    const StaticPressure& static_pressure) const {
  return {static_pressure, *this};
}

inline constexpr StaticPressure ForceMagnitude::operator/(
    const Area& area) const {
  return {*this, area};
}

inline constexpr StaticPressure PressureDifference::operator+(
    const StaticPressure& static_pressure) const {
  return StaticPressure{value_ + static_pressure.Value()};
}

inline constexpr StaticPressure PressureDifference::operator-(
    const StaticPressure& static_pressure) const {
  return StaticPressure{value_ - static_pressure.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StaticPressure> {
  inline size_t operator()(const PhQ::StaticPressure& static_pressure) const {
    return hash<double>()(static_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_PRESSURE_HPP
