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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_LENGTH_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_LENGTH_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declarations for class Length.
class Area;
class Direction;
class Displacement;
class DynamicViscosity;
class Energy;
class Frequency;
class KinematicViscosity;
class MassDensity;
class Position;
class ReynoldsNumber;
class Speed;
class Time;
class TransportEnergyConsumption;
class Volume;

// Scalar length. Can also represent the magnitude of a position vector or
// displacement vector.
class Length : public DimensionalScalarQuantity<Unit::Length> {
public:
  constexpr Length() : DimensionalScalarQuantity<Unit::Length>() {}

  Length(const double value, const Unit::Length unit)
    : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

  Length(const Displacement& displacement);

  Length(const Position& position);

  constexpr Length(const Speed& speed, const Time& time);

  constexpr Length(const Speed& speed, const Frequency& frequency);

  constexpr Length(const ReynoldsNumber& reynolds_number,
                   const DynamicViscosity& dynamic_viscosity,
                   const MassDensity& mass_density, const Speed& speed);

  constexpr Length(
      const ReynoldsNumber& reynolds_number,
      const KinematicViscosity& kinematic_viscosity, const Speed& speed);

  constexpr Length(
      const Energy& energy,
      const TransportEnergyConsumption& transport_energy_consumption);

  static constexpr Length Zero() {
    return Length{0.0};
  }

  template <Unit::Length Unit>
  static constexpr Length Create(const double value) {
    return Length{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  constexpr Length operator+(const Length& length) const {
    return Length{value_ + length.value_};
  }

  constexpr Length operator-(const Length& length) const {
    return Length{value_ - length.value_};
  }

  constexpr Length operator*(const double number) const {
    return Length{value_ * number};
  }

  constexpr Area operator*(const Length& length) const;

  constexpr Volume operator*(const Area& area) const;

  constexpr Speed operator*(const Frequency& frequency) const;

  constexpr Position operator*(const Direction& direction) const;

  constexpr Energy operator*(
      const TransportEnergyConsumption& transport_energy_consumption) const;

  constexpr Length operator/(const double number) const {
    return Length{value_ / number};
  }

  constexpr Speed operator/(const Time& time) const;

  constexpr Time operator/(const Speed& speed) const;

  constexpr double operator/(const Length& length) const noexcept {
    return value_ / length.value_;
  }

  constexpr void operator+=(const Length& length) noexcept {
    value_ += length.value_;
  }

  constexpr void operator-=(const Length& length) noexcept {
    value_ -= length.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Length(const double value)
    : DimensionalScalarQuantity<Unit::Length>(value) {}

  friend class Area;
  friend class Volume;
};

inline constexpr bool operator==(
    const Length& left, const Length& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Length& left, const Length& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Length& left, const Length& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Length& left, const Length& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Length& left, const Length& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Length& left, const Length& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Length& length) {
  stream << length.Print();
  return stream;
}

inline constexpr Length operator*(const double number, const Length& length) {
  return length * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Length> {
  inline size_t operator()(const PhQ::Length& length) const {
    return hash<double>()(length.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_LENGTH_HPP
