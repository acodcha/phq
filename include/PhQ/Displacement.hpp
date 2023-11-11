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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Length.hpp"
#include "Unit/Length.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declarations for class Displacement.
class Frequency;
class Position;
class Time;
class Velocity;

// Displacement vector. Not to be confused with position vector.
class Displacement : public DimensionalVector<Unit::Length> {
public:
  // Default constructor. Constructs a displacement with an uninitialized value.
  Displacement() = default;

  // Constructor. Constructs a displacement with a given value expressed in a given length unit.
  Displacement(const Vector& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length>(value, unit) {}

  // Constructor. Constructs a displacement from a given length and direction.
  constexpr Displacement(const Length& length, const Direction& direction)
    : Displacement(length.Value() * direction.Value()) {}

  // Constructor. Constructs a displacement from a given velocity and time using the definition of
  // velocity.
  constexpr Displacement(const Velocity& velocity, const Time& time);

  // Constructor. Constructs a displacement from a given velocity and frequency using the definition
  // of velocity.
  constexpr Displacement(const Velocity& velocity, const Frequency& frequency);

  // Constructor. Constructs a displacement between a given position and the origin.
  explicit constexpr Displacement(const Position& position);

  // Destructor. Destroys this displacement.
  ~Displacement() noexcept = default;

  // Copy constructor. Constructs a displacement by copying another one.
  constexpr Displacement(const Displacement& other) = default;

  // Move constructor. Constructs a displacement by moving another one.
  constexpr Displacement(Displacement&& other) noexcept = default;

  // Copy assignment operator. Assigns this displacement by copying another one.
  constexpr Displacement& operator=(const Displacement& other) = default;

  // Move assignment operator. Assigns this displacement by moving another one.
  constexpr Displacement& operator=(Displacement&& other) noexcept = default;

  // Statically creates a displacement of zero.
  static constexpr Displacement Zero() {
    return Displacement{Vector::Zero()};
  }

  // Statically creates a displacement from the given x, y, and z Cartesian components expressed in
  // a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement Create(const double x, const double y, const double z) {
    return Displacement{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector{x, y, z})};
  }

  // Statically creates a displacement from the given x, y, and z Cartesian components expressed in
  // a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement Create(const std::array<double, 3>& x_y_z) {
    return Displacement{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector{x_y_z})};
  }

  // Statically creates a displacement with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement Create(const Vector& value) {
    return Displacement{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  // Returns the magnitude of this displacement.
  [[nodiscard]] Length Magnitude() const {
    return Length{value_.Magnitude()};
  }

  // Returns the angle between this displacement and another one.
  [[nodiscard]] PhQ::Angle Angle(const Displacement& displacement) const {
    return {*this, displacement};
  }

  constexpr Position operator+(const Position& position) const;

  constexpr Displacement operator+(const Displacement& displacement) const {
    return Displacement{value_ + displacement.value_};
  }

  constexpr Position operator-(const Position& position) const;

  constexpr Displacement operator-(const Displacement& displacement) const {
    return Displacement{value_ - displacement.value_};
  }

  constexpr Displacement operator*(const double number) const {
    return Displacement{value_ * number};
  }

  constexpr Velocity operator*(const Frequency& frequency) const;

  constexpr Displacement operator/(const double number) const {
    return Displacement{value_ / number};
  }

  constexpr Velocity operator/(const Time& time) const;

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a displacement with a given value expressed in the standard length
  // unit.
  explicit constexpr Displacement(const Vector& value) : DimensionalVector<Unit::Length>(value) {}

  friend class Position;
};

inline constexpr bool operator==(const Displacement& left, const Displacement& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Displacement& left, const Displacement& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Displacement& left, const Displacement& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Displacement& left, const Displacement& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Displacement& left, const Displacement& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Displacement& left, const Displacement& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Displacement& displacement) {
  stream << displacement.Print();
  return stream;
}

inline constexpr Displacement operator*(const double number, const Displacement& displacement) {
  return displacement * number;
}

inline Direction::Direction(const Displacement& displacement) : Direction(displacement.Value()) {}

inline Angle::Angle(const Displacement& displacement1, const Displacement& displacement2)
  : Angle(displacement1.Value(), displacement2.Value()) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Displacement> {
  inline size_t operator()(const PhQ::Displacement& displacement) const {
    return hash<PhQ::Vector>()(displacement.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP
