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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_REYNOLDS_NUMBER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_REYNOLDS_NUMBER_HPP

#include "DimensionlessScalarQuantity.hpp"
#include "DynamicViscosity.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"

namespace PhQ {

// Reynolds number of a fluid flow.
class ReynoldsNumber : public DimensionlessScalarQuantity {
public:
  constexpr ReynoldsNumber() : DimensionlessScalarQuantity() {}

  explicit constexpr ReynoldsNumber(const double value)
    : DimensionlessScalarQuantity(value) {}

  constexpr ReynoldsNumber(
      const DynamicViscosity& dynamic_viscosity,
      const MassDensity& mass_density, const Speed& speed, const Length& length)
    : ReynoldsNumber(mass_density.Value() * speed.Value() * length.Value()
                     / dynamic_viscosity.Value()) {}

  constexpr ReynoldsNumber(const KinematicViscosity& kinematic_viscosity,
                           const Speed& speed, const Length& length)
    : ReynoldsNumber(
        speed.Value() * length.Value() / kinematic_viscosity.Value()) {}

  static constexpr ReynoldsNumber Zero() {
    return ReynoldsNumber{0.0};
  }

  constexpr PhQ::DynamicViscosity DynamicViscosity(
      const PhQ::MassDensity& mass_density, const PhQ::Speed& speed,
      const PhQ::Length& length) const {
    return {*this, mass_density, speed, length};
  }

  constexpr PhQ::KinematicViscosity KinematicViscosity(
      const PhQ::Speed& speed, const PhQ::Length& length) const {
    return {*this, speed, length};
  }

  constexpr PhQ::MassDensity MassDensity(
      const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::Speed& speed,
      const PhQ::Length& length) const {
    return {*this, dynamic_viscosity, speed, length};
  }

  constexpr PhQ::Speed Speed(
      const PhQ::DynamicViscosity& dynamic_viscosity,
      const PhQ::MassDensity& mass_density, const PhQ::Length& length) const {
    return {*this, dynamic_viscosity, mass_density, length};
  }

  constexpr PhQ::Speed Speed(const PhQ::KinematicViscosity& kinematic_viscosity,
                             const PhQ::Length& length) const {
    return {*this, kinematic_viscosity, length};
  }

  constexpr PhQ::Length Length(
      const PhQ::DynamicViscosity& dynamic_viscosity,
      const PhQ::MassDensity& mass_density, const PhQ::Speed& speed) const {
    return {*this, dynamic_viscosity, mass_density, speed};
  }

  constexpr PhQ::Length Length(
      const PhQ::KinematicViscosity& kinematic_viscosity,
      const PhQ::Speed& speed) const {
    return {*this, kinematic_viscosity, speed};
  }

  constexpr ReynoldsNumber operator+(
      const ReynoldsNumber& reynolds_number) const {
    return ReynoldsNumber{value_ + reynolds_number.value_};
  }

  constexpr ReynoldsNumber operator-(
      const ReynoldsNumber& reynolds_number) const {
    return ReynoldsNumber{value_ - reynolds_number.value_};
  }

  constexpr ReynoldsNumber operator*(const double number) const {
    return ReynoldsNumber{value_ * number};
  }

  constexpr ReynoldsNumber operator/(const double number) const {
    return ReynoldsNumber{value_ / number};
  }

  constexpr double operator/(
      const ReynoldsNumber& reynolds_number) const noexcept {
    return value_ / reynolds_number.value_;
  }

  constexpr void operator+=(const ReynoldsNumber& reynolds_number) noexcept {
    value_ += reynolds_number.value_;
  }

  constexpr void operator-=(const ReynoldsNumber& reynolds_number) noexcept {
    value_ -= reynolds_number.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ReynoldsNumber& left, const ReynoldsNumber& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ReynoldsNumber& reynolds_number) {
  stream << reynolds_number.Print();
  return stream;
}

inline constexpr ReynoldsNumber operator+(
    const double number, const ReynoldsNumber& reynolds_number) {
  return ReynoldsNumber{number + reynolds_number.Value()};
}

inline constexpr ReynoldsNumber operator-(
    const double number, const ReynoldsNumber& reynolds_number) {
  return ReynoldsNumber{number - reynolds_number.Value()};
}

inline constexpr ReynoldsNumber operator*(
    const double number, const ReynoldsNumber& reynolds_number) {
  return ReynoldsNumber{number * reynolds_number.Value()};
}

inline constexpr double operator/(
    const double number, const ReynoldsNumber& reynolds_number) noexcept {
  return number / reynolds_number.Value();
}

inline constexpr Length::Length(
    const ReynoldsNumber& reynolds_number,
    const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density,
    const Speed& speed)
  : Length(reynolds_number.Value() * dynamic_viscosity.Value()
           / (mass_density.Value() * speed.Value())) {}

inline constexpr Length::Length(
    const ReynoldsNumber& reynolds_number,
    const KinematicViscosity& kinematic_viscosity, const Speed& speed)
  : Length(
      reynolds_number.Value() * kinematic_viscosity.Value() / speed.Value()) {}

inline constexpr Speed::Speed(
    const ReynoldsNumber& reynolds_number,
    const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density,
    const Length& length)
  : Speed(reynolds_number.Value() * dynamic_viscosity.Value()
          / (mass_density.Value() * length.Value())) {}

inline constexpr Speed::Speed(
    const ReynoldsNumber& reynolds_number,
    const KinematicViscosity& kinematic_viscosity, const Length& length)
  : Speed(
      reynolds_number.Value() * kinematic_viscosity.Value() / length.Value()) {}

inline constexpr MassDensity::MassDensity(
    const ReynoldsNumber& reynolds_number,
    const DynamicViscosity& dynamic_viscosity, const Speed& speed,
    const Length& length)
  : MassDensity(reynolds_number.Value() * dynamic_viscosity.Value()
                / (speed.Value() * length.Value())) {}

inline constexpr KinematicViscosity::KinematicViscosity(
    const ReynoldsNumber& reynolds_number, const Speed& speed,
    const Length& length)
  : KinematicViscosity(
      speed.Value() * length.Value() / reynolds_number.Value()) {}

inline constexpr DynamicViscosity::DynamicViscosity(
    const ReynoldsNumber& reynolds_number, const MassDensity& mass_density,
    const Speed& speed, const Length& length)
  : DynamicViscosity(mass_density.Value() * speed.Value() * length.Value()
                     / reynolds_number.Value()) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ReynoldsNumber> {
  inline size_t operator()(const PhQ::ReynoldsNumber& reynolds_number) const {
    return hash<double>()(reynolds_number.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_REYNOLDS_NUMBER_HPP
