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

#ifndef PHQ_REYNOLDS_NUMBER_HPP
#define PHQ_REYNOLDS_NUMBER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"
#include "DynamicViscosity.hpp"
#include "KinematicViscosity.hpp"
#include "Length.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"

namespace PhQ {

// Reynolds number of a fluid flow.
class ReynoldsNumber : public DimensionlessScalar {
public:
  // Default constructor. Constructs a Reynolds number with an uninitialized value.
  ReynoldsNumber() = default;

  // Constructor. Constructs a Reynolds number with a given value.
  explicit constexpr ReynoldsNumber(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a Reynolds number from a given mass density, speed, length, and dynamic
  // viscosity using the definition of the Reynolds number.
  constexpr ReynoldsNumber(const MassDensity& mass_density, const Speed& speed,
                           const Length& length, const DynamicViscosity& dynamic_viscosity)
    : ReynoldsNumber(
        mass_density.Value() * speed.Value() * length.Value() / dynamic_viscosity.Value()) {}

  // Constructor. Constructs a Reynolds number from a given speed, length, and kinematic viscosity
  // using the definition of the Reynolds number.
  constexpr ReynoldsNumber(
      const Speed& speed, const Length& length, const KinematicViscosity& kinematic_viscosity)
    : ReynoldsNumber(speed.Value() * length.Value() / kinematic_viscosity.Value()) {}

  // Destructor. Destroys this Reynolds number.
  ~ReynoldsNumber() noexcept = default;

  // Copy constructor. Constructs a Reynolds number by copying another one.
  constexpr ReynoldsNumber(const ReynoldsNumber& other) = default;

  // Move constructor. Constructs a Reynolds number by moving another one.
  constexpr ReynoldsNumber(ReynoldsNumber&& other) noexcept = default;

  // Copy assignment operator. Assigns this Reynolds number by copying another one.
  constexpr ReynoldsNumber& operator=(const ReynoldsNumber& other) = default;

  // Move assignment operator. Assigns this Reynolds number by moving another one.
  constexpr ReynoldsNumber& operator=(ReynoldsNumber&& other) noexcept = default;

  // Statically creates a Reynolds number of zero.
  static constexpr ReynoldsNumber Zero() {
    return ReynoldsNumber{0.0};
  }

  [[nodiscard]] constexpr PhQ::DynamicViscosity DynamicViscosity(
      const PhQ::MassDensity& mass_density, const PhQ::Speed& speed,
      const PhQ::Length& length) const {
    return {mass_density, speed, length, *this};
  }

  [[nodiscard]] constexpr PhQ::KinematicViscosity KinematicViscosity(
      const PhQ::Speed& speed, const PhQ::Length& length) const {
    return {speed, length, *this};
  }

  [[nodiscard]] constexpr PhQ::Length Length(
      const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::MassDensity& mass_density,
      const PhQ::Speed& speed) const {
    return {*this, dynamic_viscosity, mass_density, speed};
  }

  [[nodiscard]] constexpr PhQ::Length Length(
      const PhQ::KinematicViscosity& kinematic_viscosity, const PhQ::Speed& speed) const {
    return {*this, kinematic_viscosity, speed};
  }

  [[nodiscard]] constexpr PhQ::MassDensity MassDensity(
      const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::Speed& speed,
      const PhQ::Length& length) const {
    return {*this, dynamic_viscosity, speed, length};
  }

  [[nodiscard]] constexpr PhQ::Speed Speed(
      const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::MassDensity& mass_density,
      const PhQ::Length& length) const {
    return {*this, dynamic_viscosity, mass_density, length};
  }

  [[nodiscard]] constexpr PhQ::Speed Speed(
      const PhQ::KinematicViscosity& kinematic_viscosity, const PhQ::Length& length) const {
    return {*this, kinematic_viscosity, length};
  }

  constexpr ReynoldsNumber operator+(const ReynoldsNumber& reynolds_number) const {
    return ReynoldsNumber{value + reynolds_number.value};
  }

  constexpr ReynoldsNumber operator-(const ReynoldsNumber& reynolds_number) const {
    return ReynoldsNumber{value - reynolds_number.value};
  }

  constexpr ReynoldsNumber operator*(const double number) const {
    return ReynoldsNumber{value * number};
  }

  constexpr ReynoldsNumber operator/(const double number) const {
    return ReynoldsNumber{value / number};
  }

  constexpr double operator/(const ReynoldsNumber& reynolds_number) const noexcept {
    return value / reynolds_number.value;
  }

  constexpr void operator+=(const ReynoldsNumber& reynolds_number) noexcept {
    value += reynolds_number.value;
  }

  constexpr void operator-=(const ReynoldsNumber& reynolds_number) noexcept {
    value -= reynolds_number.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }
};

inline constexpr bool operator==(const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ReynoldsNumber& reynolds_number) {
  stream << reynolds_number.Print();
  return stream;
}

inline constexpr ReynoldsNumber operator*(
    const double number, const ReynoldsNumber& reynolds_number) {
  return ReynoldsNumber{number * reynolds_number.Value()};
}

inline constexpr Length::Length(
    const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity,
    const MassDensity& mass_density, const Speed& speed)
  : Length(reynolds_number.Value() * dynamic_viscosity.Value()
           / (mass_density.Value() * speed.Value())) {}

inline constexpr Length::Length(const ReynoldsNumber& reynolds_number,
                                const KinematicViscosity& kinematic_viscosity, const Speed& speed)
  : Length(reynolds_number.Value() * kinematic_viscosity.Value() / speed.Value()) {}

inline constexpr Speed::Speed(
    const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity,
    const MassDensity& mass_density, const Length& length)
  : Speed(reynolds_number.Value() * dynamic_viscosity.Value()
          / (mass_density.Value() * length.Value())) {}

inline constexpr Speed::Speed(const ReynoldsNumber& reynolds_number,
                              const KinematicViscosity& kinematic_viscosity, const Length& length)
  : Speed(reynolds_number.Value() * kinematic_viscosity.Value() / length.Value()) {}

inline constexpr MassDensity::MassDensity(
    const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity,
    const Speed& speed, const Length& length)
  : MassDensity(
      reynolds_number.Value() * dynamic_viscosity.Value() / (speed.Value() * length.Value())) {}

inline constexpr KinematicViscosity::KinematicViscosity(
    const Speed& speed, const Length& length, const ReynoldsNumber& reynolds_number)
  : KinematicViscosity(speed.Value() * length.Value() / reynolds_number.Value()) {}

inline constexpr DynamicViscosity::DynamicViscosity(
    const MassDensity& mass_density, const Speed& speed, const Length& length,
    const ReynoldsNumber& reynolds_number)
  : DynamicViscosity(
      mass_density.Value() * speed.Value() * length.Value() / reynolds_number.Value()) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ReynoldsNumber> {
  inline size_t operator()(const PhQ::ReynoldsNumber& reynolds_number) const {
    return hash<double>()(reynolds_number.Value());
  }
};

}  // namespace std

#endif  // PHQ_REYNOLDS_NUMBER_HPP
