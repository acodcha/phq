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

#ifndef PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
#define PHQ_TOTAL_KINEMATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "DynamicKinematicPressure.hpp"
#include "MassDensity.hpp"
#include "StaticKinematicPressure.hpp"
#include "TotalPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Total kinematic pressure, which is the sum of static kinematic pressure and dynamic kinematic
// pressure.
class TotalKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, double> {
public:
  // Default constructor. Constructs a total kinematic pressure with an uninitialized value.
  TotalKinematicPressure() = default;

  // Constructor. Constructs a total kinematic pressure with a given value expressed in a given
  // specific energy unit.
  TotalKinematicPressure(const double value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy>(value, unit) {}

  // Constructor. Constructs a total kinematic pressure from a given static kinematic pressure and
  // dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr TotalKinematicPressure(const StaticKinematicPressure& static_kinematic_pressure,
                                   const DynamicKinematicPressure& dynamic_kinematic_pressure)
    : TotalKinematicPressure(
        static_kinematic_pressure.Value() + dynamic_kinematic_pressure.Value()) {}

  // Constructor. Constructs a total kinematic pressure from a given total pressure and mass density
  // using the definition of total kinematic pressure.
  constexpr TotalKinematicPressure(
      const TotalPressure& total_pressure, const MassDensity& mass_density)
    : TotalKinematicPressure(total_pressure.Value() / mass_density.Value()) {}

  // Destructor. Destroys this total kinematic pressure.
  ~TotalKinematicPressure() noexcept = default;

  // Copy constructor. Constructs a total kinematic pressure by copying another one.
  constexpr TotalKinematicPressure(const TotalKinematicPressure& other) = default;

  // Move constructor. Constructs a total kinematic pressure by moving another one.
  constexpr TotalKinematicPressure(TotalKinematicPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this total kinematic pressure by copying another one.
  constexpr TotalKinematicPressure& operator=(const TotalKinematicPressure& other) = default;

  // Move assignment operator. Assigns this total kinematic pressure by moving another one.
  constexpr TotalKinematicPressure& operator=(TotalKinematicPressure&& other) noexcept = default;

  // Statically creates a total kinematic pressure of zero.
  static constexpr TotalKinematicPressure Zero() {
    return TotalKinematicPressure{0.0};
  }

  // Statically creates a total kinematic pressure with a given value expressed in a given specific
  // energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr TotalKinematicPressure Create(const double value) {
    return TotalKinematicPressure{
        StaticConvertCopy<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr TotalKinematicPressure operator+(
      const TotalKinematicPressure& total_kinematic_pressure) const {
    return TotalKinematicPressure{value + total_kinematic_pressure.value};
  }

  constexpr TotalKinematicPressure operator-(
      const TotalKinematicPressure& total_kinematic_pressure) const {
    return TotalKinematicPressure{value - total_kinematic_pressure.value};
  }

  constexpr DynamicKinematicPressure operator-(
      const StaticKinematicPressure& static_kinematic_pressure) const {
    return {*this, static_kinematic_pressure};
  }

  constexpr StaticKinematicPressure operator-(
      const DynamicKinematicPressure& dynamic_kinematic_pressure) const {
    return {*this, dynamic_kinematic_pressure};
  }

  constexpr TotalKinematicPressure operator*(const double number) const {
    return TotalKinematicPressure{value * number};
  }

  constexpr TotalKinematicPressure operator/(const double number) const {
    return TotalKinematicPressure{value / number};
  }

  constexpr double operator/(
      const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value / total_kinematic_pressure.value;
  }

  constexpr void operator+=(const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value += total_kinematic_pressure.value;
  }

  constexpr void operator-=(const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value -= total_kinematic_pressure.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a total kinematic pressure with a given value expressed in the standard
  // specific energy unit.
  explicit constexpr TotalKinematicPressure(const double value)
    : DimensionalScalar<Unit::SpecificEnergy>(value) {}
};

inline constexpr bool operator==(
    const TotalKinematicPressure& left, const TotalKinematicPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TotalKinematicPressure& left, const TotalKinematicPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TotalKinematicPressure& left, const TotalKinematicPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TotalKinematicPressure& left, const TotalKinematicPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TotalKinematicPressure& left, const TotalKinematicPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TotalKinematicPressure& left, const TotalKinematicPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TotalKinematicPressure& total_kinematic_pressure) {
  stream << total_kinematic_pressure.Print();
  return stream;
}

inline constexpr TotalKinematicPressure operator*(
    const double number, const TotalKinematicPressure& total_kinematic_pressure) {
  return total_kinematic_pressure * number;
}

inline constexpr TotalPressure::TotalPressure(
    const MassDensity& mass_density, const TotalKinematicPressure& total_kinematic_pressure)
  : TotalPressure(mass_density.Value() * total_kinematic_pressure.Value()) {}

inline constexpr StaticKinematicPressure::StaticKinematicPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const DynamicKinematicPressure& dynamic_kinematic_pressure)
  : StaticKinematicPressure(total_kinematic_pressure.Value() - dynamic_kinematic_pressure.Value()) {
}

inline constexpr DynamicKinematicPressure::DynamicKinematicPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const StaticKinematicPressure& static_kinematic_pressure)
  : DynamicKinematicPressure(total_kinematic_pressure.Value() - static_kinematic_pressure.Value()) {
}

inline constexpr TotalKinematicPressure StaticKinematicPressure::operator+(
    const DynamicKinematicPressure& dynamic_kinematic_pressure) const {
  return {*this, dynamic_kinematic_pressure};
}

inline constexpr TotalKinematicPressure DynamicKinematicPressure::operator+(
    const StaticKinematicPressure& static_kinematic_pressure) const {
  return {static_kinematic_pressure, *this};
}

inline constexpr TotalKinematicPressure TotalPressure::operator/(
    const MassDensity& mass_density) const {
  return {*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TotalKinematicPressure> {
  inline size_t operator()(const PhQ::TotalKinematicPressure& total_kinematic_pressure) const {
    return hash<double>()(total_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
