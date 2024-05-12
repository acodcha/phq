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

#ifndef PHQ_DISPLACEMENT_HPP
#define PHQ_DISPLACEMENT_HPP

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

// Forward declaration for class PhQ::Displacement.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Displacement.
template <typename Number>
class Position;

// Forward declaration for class PhQ::Displacement.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Displacement.
template <typename Number>
class Velocity;

// Displacement vector. Not to be confused with position vector.
template <typename Number = double>
class Displacement : public DimensionalVector<Unit::Length, Number> {
public:
  // Default constructor. Constructs a displacement vector with an uninitialized value.
  Displacement() = default;

  // Constructor. Constructs a displacement vector with a given value expressed in a given length
  // unit.
  Displacement(const Vector<Number>& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length, Number>(value, unit) {}

  // Constructor. Constructs a displacement vector from a given length and direction.
  constexpr Displacement(const Length<Number>& length, const Direction<Number>& direction)
    : Displacement<Number>(length.Value() * direction.Value()) {}

  // Constructor. Constructs a displacement vector from a given velocity vector and time using the
  // definition of velocity.
  constexpr Displacement(const Velocity<Number>& velocity, const Time<Number>& time);

  // Constructor. Constructs a displacement vector from a given velocity vector and frequency using
  // the definition of velocity.
  constexpr Displacement(const Velocity<Number>& velocity, const Frequency<Number>& frequency);

  // Constructor. Constructs a displacement vector between a given position vector and the origin.
  explicit constexpr Displacement(const Position<Number>& position);

  // Destructor. Destroys this displacement vector.
  ~Displacement() noexcept = default;

  // Copy constructor. Constructs a displacement vector by copying another one.
  constexpr Displacement(const Displacement<Number>& other) = default;

  // Copy constructor. Constructs a displacement by copying another one.
  template <typename OtherNumber>
  explicit constexpr Displacement(const Displacement<OtherNumber>& other)
    : Displacement(static_cast<Vector<Number>>(other.Value())) {}

  // Move constructor. Constructs a displacement vector by moving another one.
  constexpr Displacement(Displacement<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this displacement vector by copying another one.
  constexpr Displacement<Number>& operator=(const Displacement<Number>& other) = default;

  // Copy assignment operator. Assigns this displacement by copying another one.
  template <typename OtherNumber>
  constexpr Displacement<Number>& operator=(const Displacement<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this displacement vector by moving another one.
  constexpr Displacement<Number>& operator=(Displacement<Number>&& other) noexcept = default;

  // Statically creates a displacement vector of zero.
  static constexpr Displacement<Number> Zero() {
    return Displacement<Number>{Vector<Number>::Zero()};
  }

  // Statically creates a displacement vector from the given x, y, and z Cartesian components
  // expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<Number> Create(const Number x, const Number y, const Number z) {
    return Displacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x, y, z})};
  }

  // Statically creates a displacement vector from the given x, y, and z Cartesian components
  // expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Displacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x_y_z})};
  }

  // Statically creates a displacement vector with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<Number> Create(const Vector<Number>& value) {
    return Displacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  // Returns the x Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<Number> x() const noexcept {
    return Length<Number>{this->value.x()};
  }

  // Returns the y Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<Number> y() const noexcept {
    return Length<Number>{this->value.y()};
  }

  // Returns the z Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<Number> z() const noexcept {
    return Length<Number>{this->value.z()};
  }

  // Returns the magnitude of this displacement vector.
  [[nodiscard]] Length<Number> Magnitude() const {
    return Length<Number>{this->value.Magnitude()};
  }

  // Returns the direction of this displacement vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  // Returns the angle between this displacement vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Displacement<Number>& displacement) const {
    return PhQ::Angle<Number>{*this, displacement};
  }

  constexpr Position<Number> operator+(const Position<Number>& position) const;

  constexpr Displacement<Number> operator+(const Displacement<Number>& displacement) const {
    return Displacement<Number>{this->value + displacement.value};
  }

  constexpr Position<Number> operator-(const Position<Number>& position) const;

  constexpr Displacement<Number> operator-(const Displacement<Number>& displacement) const {
    return Displacement<Number>{this->value - displacement.value};
  }

  constexpr Displacement<Number> operator*(const Number number) const {
    return Displacement<Number>{this->value * number};
  }

  constexpr Velocity<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Displacement<Number> operator/(const Number number) const {
    return Displacement<Number>{this->value / number};
  }

  constexpr Velocity<Number> operator/(const Time<Number>& time) const;

  constexpr void operator+=(const Displacement<Number>& displacement) noexcept {
    this->value += displacement.value;
  }

  constexpr void operator-=(const Displacement<Number>& displacement) noexcept {
    this->value -= displacement.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a displacement vector with a given value expressed in the standard
  // length unit.
  explicit constexpr Displacement(const Vector<Number>& value)
    : DimensionalVector<Unit::Length, Number>(value) {}

  template <typename OtherNumber>
  friend class Position;
};

template <typename Number>
inline constexpr bool operator==(
    const Displacement<Number>& left, const Displacement<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Displacement<Number>& left, const Displacement<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Displacement<Number>& left, const Displacement<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Displacement<Number>& left, const Displacement<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Displacement<Number>& left, const Displacement<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Displacement<Number>& left, const Displacement<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Displacement<Number>& displacement) {
  stream << displacement.Print();
  return stream;
}

template <typename Number>
inline constexpr Displacement<Number> operator*(
    const Number number, const Displacement<Number>& displacement) {
  return displacement * number;
}

template <typename Number>
inline Direction<Number>::Direction(const Displacement<Number>& displacement)
  : Direction<Number>(displacement.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const Displacement<Number>& displacement1, const Displacement<Number>& displacement2)
  : Angle<Number>(displacement1.Value(), displacement2.Value()) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Displacement<Number>> {
  inline size_t operator()(const PhQ::Displacement<Number>& displacement) const {
    return hash<PhQ::Vector<Number>>()(displacement.Value());
  }
};

}  // namespace std

#endif  // PHQ_DISPLACEMENT_HPP
