// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalarQuantity.hpp"
#include "ForceMagnitude.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declarations for class StaticPressure.
class Direction;
class DynamicPressure;
class MassDensity;
class StaticKinematicPressure;
class Stress;
class TotalPressure;
class Traction;

// Static pressure. Pressure of a fluid at rest. Not to be confused with dynamic pressure, which is
// the additional pressure resulting from the kinetic energy of a flowing fluid, or total pressure,
// which is the sum of static pressure and dynamic pressure. Can represent either an absolute static
// pressure or a static pressure difference relative to another static pressure.
class StaticPressure : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  // Default constructor. Constructs a static pressure with an uninitialized value.
  StaticPressure() = default;

  // Constructor. Constructs a static pressure with a given value expressed in a given pressure
  // unit.
  StaticPressure(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a static pressure from a given force magnitude and area using the
  // definition of pressure.
  constexpr StaticPressure(const ForceMagnitude& force_magnitude, const Area& area)
    : StaticPressure(force_magnitude.Value() / area.Value()) {}

  // Constructor. Constructs a static pressure from a given traction vector. Since pressure is
  // compressive, the static pressure that corresponds to the magnitude of a traction is negative.
  explicit StaticPressure(const Traction& traction);

  // Constructor. Constructs a static pressure from a given total pressure and dynamic pressure
  // using the definition of total pressure.
  constexpr StaticPressure(
      const TotalPressure& total_pressure, const DynamicPressure& dynamic_pressure);

  // Constructor. Constructs a static pressure from a given mass density and static kinematic
  // pressure using the definition of static kinematic pressure.
  constexpr StaticPressure(
      const MassDensity& mass_density, const StaticKinematicPressure& static_kinematic_pressure);

  // Destructor. Destroys this static pressure.
  ~StaticPressure() noexcept = default;

  // Copy constructor. Constructs a static pressure by copying another one.
  constexpr StaticPressure(const StaticPressure& other) = default;

  // Move constructor. Constructs a static pressure by moving another one.
  constexpr StaticPressure(StaticPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this static pressure by copying another one.
  constexpr StaticPressure& operator=(const StaticPressure& other) = default;

  // Move assignment operator. Assigns this static pressure by moving another one.
  constexpr StaticPressure& operator=(StaticPressure&& other) noexcept = default;

  // Statically creates a static pressure of zero.
  static constexpr StaticPressure Zero() {
    return StaticPressure{0.0};
  }

  // Statically creates a static pressure with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr StaticPressure Create(const double value) {
    return StaticPressure{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  [[nodiscard]] constexpr PhQ::Stress Stress() const;

  constexpr StaticPressure operator+(const StaticPressure& other) const {
    return StaticPressure{value_ + other.value_};
  }

  constexpr TotalPressure operator+(const DynamicPressure& dynamic_pressure) const;

  constexpr StaticPressure operator-(const StaticPressure& other) const {
    return StaticPressure{value_ - other.value_};
  }

  constexpr StaticPressure operator*(const double number) const {
    return StaticPressure{value_ * number};
  }

  constexpr ForceMagnitude operator*(const Area& area) const {
    return {*this, area};
  }

  // Since pressure is compressive, the negative of this static pressure contributes to the
  // traction.
  constexpr Traction operator*(const Direction& direction) const;

  constexpr StaticPressure operator/(const double number) const {
    return StaticPressure{value_ / number};
  }

  constexpr StaticKinematicPressure operator/(const MassDensity& mass_density) const;

  constexpr double operator/(const StaticPressure& other) const noexcept {
    return value_ / other.value_;
  }

  constexpr void operator+=(const StaticPressure& other) noexcept {
    value_ += other.value_;
  }

  constexpr void operator-=(const StaticPressure& other) noexcept {
    value_ -= other.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a static pressure with a given value expressed in the standard pressure
  // unit.
  explicit constexpr StaticPressure(const double value)
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const StaticPressure& left, const StaticPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const StaticPressure& static_pressure) {
  stream << static_pressure.Print();
  return stream;
}

inline constexpr StaticPressure operator*(
    const double number, const StaticPressure& static_pressure) {
  return static_pressure * number;
}

inline constexpr Area::Area(
    const ForceMagnitude& force_magnitude, const StaticPressure& static_pressure)
  : Area(force_magnitude.Value() / static_pressure.Value()) {}

inline constexpr ForceMagnitude::ForceMagnitude(
    const StaticPressure& static_pressure, const Area& area)
  : ForceMagnitude(static_pressure.Value() * area.Value()) {}

inline constexpr ForceMagnitude Area::operator*(const StaticPressure& static_pressure) const {
  return {static_pressure, *this};
}

inline constexpr StaticPressure ForceMagnitude::operator/(const Area& area) const {
  return {*this, area};
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
