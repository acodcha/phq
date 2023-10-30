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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRACTION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRACTION_HPP

#include "Force.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Traction vector.
class Traction : public DimensionalVectorQuantity<Unit::Pressure> {
public:
  // Default constructor. Constructs a traction with an uninitialized value.
  Traction() = default;

  // Constructor. Constructs a traction with a given value expressed in a given
  // pressure unit.
  Traction(const Value::Vector& value, const Unit::Pressure unit)
    : DimensionalVectorQuantity<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a traction from a given static pressure and
  // direction. Since pressure is compressive, the negative of the static
  // pressure contributes to the traction.
  constexpr Traction(
      const StaticPressure& static_pressure, const Direction& direction)
    : Traction(-static_pressure.Value() * direction.Value()) {}

  // Constructor. Constructs a traction from a given force and area using the
  // definition of traction.
  constexpr Traction(const Force& force, const Area& area)
    : Traction(force.Value() / area.Value()) {}

  // Constructor. Constructs a traction from a given stress and direction using
  // the definition of traction.
  constexpr Traction(const Stress& stress, const Direction& direction);

  // Destructor. Destroys this traction.
  ~Traction() noexcept = default;

  // Copy constructor. Constructs a traction by copying another one.
  constexpr Traction(const Traction& other) = default;

  // Move constructor. Constructs a traction by moving another one.
  constexpr Traction(Traction&& other) noexcept = default;

  // Copy assignment operator. Assigns this traction by copying another one.
  constexpr Traction& operator=(const Traction& other) = default;

  // Move assignment operator. Assigns this traction by moving another one.
  constexpr Traction& operator=(Traction&& other) noexcept = default;

  // Statically creates a traction of zero.
  static constexpr Traction Zero() {
    return Traction{Value::Vector::Zero()};
  }

  // Statically creates a traction from the given x, y, and z Cartesian
  // components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction
  Create(const double x, const double y, const double z) {
    return Traction{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            Value::Vector{x, y, z})};
  }

  // Statically creates a traction from the given x, y, and z Cartesian
  // components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction Create(const std::array<double, 3>& x_y_z) {
    return Traction{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            Value::Vector{x_y_z})};
  }

  // Statically creates a traction with a given value expressed in a given
  // pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction Create(const Value::Vector& value) {
    return Traction{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  // Returns the magnitude of this traction. Since pressure is compressive, the
  // static pressure that corresponds to the magnitude of this traction is
  // negative.
  StaticPressure Magnitude() const {
    return {*this};
  }

  // Returns the angle between this traction and another one.
  PhQ::Angle Angle(const Traction& traction) const {
    return {*this, traction};
  }

  constexpr Traction operator+(const Traction& traction) const {
    return Traction{value_ + traction.value_};
  }

  constexpr Traction operator-(const Traction& traction) const {
    return Traction{value_ - traction.value_};
  }

  constexpr Traction operator*(const double number) const {
    return Traction{value_ * number};
  }

  constexpr Force operator*(const Area& area) const {
    return {*this, area};
  }

  constexpr Traction operator/(const double number) const {
    return Traction{value_ / number};
  }

  constexpr void operator+=(const Traction& traction) noexcept {
    value_ += traction.value_;
  }

  constexpr void operator-=(const Traction& traction) noexcept {
    value_ -= traction.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a traction with a given value expressed in the
  // standard pressure unit.
  explicit constexpr Traction(const Value::Vector& value)
    : DimensionalVectorQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const Traction& left, const Traction& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Traction& left, const Traction& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Traction& left, const Traction& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Traction& left, const Traction& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Traction& left, const Traction& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Traction& left, const Traction& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Traction& traction) {
  stream << traction.Print();
  return stream;
}

inline constexpr Traction operator*(
    const double number, const Traction& traction) {
  return traction * number;
}

inline Direction::Direction(const Traction& traction)
  : Direction(traction.Value()) {}

inline Angle::Angle(const Traction& traction_1, const Traction& traction_2)
  : Angle(traction_1.Value(), traction_2.Value()) {}

inline StaticPressure::StaticPressure(const Traction& traction)
  : StaticPressure(-traction.Value().Magnitude()) {}

inline constexpr Force::Force(const Traction& traction, const Area& area)
  : Force(traction.Value() * area.Value()) {}

inline constexpr Traction Direction::operator*(
    const StaticPressure& static_pressure) const {
  return {static_pressure, *this};
}

inline constexpr Traction StaticPressure::operator*(
    const Direction& direction) const {
  return {*this, direction};
}

inline constexpr Traction Force::operator/(const Area& area) const {
  return {*this, area};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Traction> {
  inline size_t operator()(const PhQ::Traction& traction) const {
    return hash<PhQ::Value::Vector>()(traction.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRACTION_HPP
