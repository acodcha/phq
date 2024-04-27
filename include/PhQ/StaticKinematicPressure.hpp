// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_STATIC_KINEMATIC_PRESSURE_HPP
#define PHQ_STATIC_KINEMATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "StaticPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declarations for class StaticKinematicPressure.
class DynamicKinematicPressure;
class TotalKinematicPressure;

// Static kinematic pressure, which is static pressure divided by mass density.
class StaticKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy> {
public:
  // Default constructor. Constructs a static kinematic pressure with an uninitialized value.
  StaticKinematicPressure() = default;

  // Constructor. Constructs a static kinematic pressure with a given value expressed in a given
  // specific energy unit.
  StaticKinematicPressure(const double value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy>(value, unit) {}

  // Constructor. Constructs a static kinematic pressure from a given total kinematic pressure and
  // dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr StaticKinematicPressure(const TotalKinematicPressure& total_kinematic_pressure,
                                    const DynamicKinematicPressure& dynamic_kinematic_pressure);

  // Constructor. Constructs a static kinematic pressure from a given static pressure and mass
  // density using the definition of static kinematic pressure.
  constexpr StaticKinematicPressure(
      const StaticPressure& static_pressure, const MassDensity& mass_density)
    : StaticKinematicPressure(static_pressure.Value() / mass_density.Value()) {}

  // Destructor. Destroys this static kinematic pressure.
  ~StaticKinematicPressure() noexcept = default;

  // Copy constructor. Constructs a static kinematic pressure by copying another one.
  constexpr StaticKinematicPressure(const StaticKinematicPressure& other) = default;

  // Move constructor. Constructs a static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure(StaticKinematicPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this static kinematic pressure by copying another one.
  constexpr StaticKinematicPressure& operator=(const StaticKinematicPressure& other) = default;

  // Move assignment operator. Assigns this static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure& operator=(StaticKinematicPressure&& other) noexcept = default;

  // Statically creates a static kinematic pressure of zero.
  static constexpr StaticKinematicPressure Zero() {
    return StaticKinematicPressure{0.0};
  }

  // Statically creates a static kinematic pressure with a given value expressed in a given specific
  // energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr StaticKinematicPressure Create(const double value) {
    return StaticKinematicPressure{
        StaticConvertCopy<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr StaticKinematicPressure operator+(const StaticKinematicPressure& other) const {
    return StaticKinematicPressure{value + other.value};
  }

  constexpr TotalKinematicPressure operator+(
      const DynamicKinematicPressure& dynamic_kinematic_pressure) const;

  constexpr StaticKinematicPressure operator-(const StaticKinematicPressure& other) const {
    return StaticKinematicPressure{value - other.value};
  }

  constexpr StaticKinematicPressure operator*(const double number) const {
    return StaticKinematicPressure{value * number};
  }

  constexpr StaticPressure operator*(const MassDensity& mass_density) const {
    return {mass_density, *this};
  }

  constexpr StaticKinematicPressure operator/(const double number) const {
    return StaticKinematicPressure{value / number};
  }

  constexpr double operator/(const StaticKinematicPressure& other) const noexcept {
    return value / other.value;
  }

  constexpr void operator+=(const StaticKinematicPressure& other) noexcept {
    value += other.value;
  }

  constexpr void operator-=(const StaticKinematicPressure& other) noexcept {
    value -= other.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a static kinematic pressure with a given value expressed in the
  // standard specific energy unit.
  explicit constexpr StaticKinematicPressure(const double value)
    : DimensionalScalar<Unit::SpecificEnergy>(value) {}
};

inline constexpr bool operator==(
    const StaticKinematicPressure& left, const StaticKinematicPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StaticKinematicPressure& left, const StaticKinematicPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const StaticKinematicPressure& left, const StaticKinematicPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const StaticKinematicPressure& left, const StaticKinematicPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StaticKinematicPressure& left, const StaticKinematicPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StaticKinematicPressure& left, const StaticKinematicPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const StaticKinematicPressure& static_kinematic_pressure) {
  stream << static_kinematic_pressure.Print();
  return stream;
}

inline constexpr StaticKinematicPressure operator*(
    const double number, const StaticKinematicPressure& static_kinematic_pressure) {
  return static_kinematic_pressure * number;
}

inline constexpr StaticPressure::StaticPressure(
    const MassDensity& mass_density, const StaticKinematicPressure& static_kinematic_pressure)
  : StaticPressure(mass_density.Value() * static_kinematic_pressure.Value()) {}

inline constexpr StaticKinematicPressure StaticPressure::operator/(
    const MassDensity& mass_density) const {
  return {*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StaticKinematicPressure> {
  inline size_t operator()(const PhQ::StaticKinematicPressure& static_kinematic_pressure) const {
    return hash<double>()(static_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_STATIC_KINEMATIC_PRESSURE_HPP
