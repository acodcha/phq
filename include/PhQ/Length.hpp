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

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declarations for class Length.
class Area;
class Direction;
class Displacement;
class Time;
class DynamicViscosity;
class Frequency;
class KinematicViscosity;
class MassDensity;
class Position;
class ReynoldsNumber;
class Speed;
class Volume;

class Length : public DimensionalScalarQuantity<Unit::Length> {
public:
  constexpr Length() noexcept : DimensionalScalarQuantity<Unit::Length>() {}

  Length(const double value, const Unit::Length unit) noexcept
      : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

  Length(const Displacement& displacement) noexcept;

  Length(const Position& position) noexcept;

  constexpr Length(const Speed& speed, const Time& time) noexcept;

  constexpr Length(const Speed& speed, const Frequency& frequency) noexcept;

  constexpr Length(const ReynoldsNumber& reynolds_number,
                   const DynamicViscosity& dynamic_viscosity,
                   const MassDensity& mass_density,
                   const Speed& speed) noexcept;

  constexpr Length(const ReynoldsNumber& reynolds_number,
                   const KinematicViscosity& kinematic_viscosity,
                   const Speed& speed) noexcept;

  inline Length operator+(const Length& length) const noexcept {
    return Length{value_ + length.value_};
  }

  inline Length operator-(const Length& length) const noexcept {
    return Length{value_ - length.value_};
  }

  inline Length operator*(const double number) const noexcept {
    return Length{value_ * number};
  }

  inline Area operator*(const Length& length) const noexcept;

  inline Volume operator*(const Area& area) const noexcept;

  inline Speed operator*(const Frequency& frequency) const noexcept;

  inline Displacement operator*(const Direction& direction) const noexcept;

  inline Length operator/(const double number) const noexcept {
    return Length{value_ / number};
  }

  inline Speed operator/(const Time& time) const noexcept;

  inline Time operator/(const Speed& speed) const noexcept;

  inline constexpr void operator+=(const Length& length) noexcept {
    value_ += length.value_;
  }

  inline constexpr void operator-=(const Length& length) noexcept {
    value_ -= length.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Length(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Length>(value) {}

  friend class Area;
  friend class Volume;
};

inline constexpr bool operator==(const Length& left,
                                 const Length& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Length& left,
                                 const Length& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Length& left,
                                const Length& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Length& left,
                                const Length& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Length& left,
                                 const Length& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Length& left,
                                 const Length& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Length& length) noexcept {
  stream << length.Print();
  return stream;
}

inline Length operator*(const double number, const Length& length) noexcept {
  return length * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Length> {
  size_t operator()(const PhQ::Length& length) const {
    return hash<double>()(length.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_LENGTH_HPP
