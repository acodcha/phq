// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
#include "PlanarDisplacement.hpp"
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

/// \brief Displacement vector. Not to be confused with the position vector. See also PhQ::Position.
template <typename Number = double>
class Displacement : public DimensionalVector<Unit::Length, Number> {
public:
  /// \brief Default constructor. Constructs a displacement vector with an uninitialized value.
  Displacement() = default;

  /// \brief Constructor. Constructs a displacement vector with a given value expressed in a given
  /// length unit.
  Displacement(const Vector<Number>& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length, Number>(value, unit) {}

  /// \brief Constructor. Constructs a displacement vector from a given length and direction.
  constexpr Displacement(const Length<Number>& length, const Direction<Number>& direction)
    : Displacement<Number>(length.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs an displacement vector from a given planar displacement vector
  /// in the XY plane. This displacement vector's z-component is initialized to zero.
  explicit constexpr Displacement(const PlanarDisplacement<Number>& planar_displacement)
    : Displacement<Number>(Vector<Number>{planar_displacement.Value()}) {}

  /// \brief Constructor. Constructs a displacement vector from a given velocity vector and time
  /// using the definition of velocity.
  constexpr Displacement(const Velocity<Number>& velocity, const Time<Number>& time);

  /// \brief Constructor. Constructs a displacement vector from a given velocity vector and
  /// frequency using the definition of velocity.
  constexpr Displacement(const Velocity<Number>& velocity, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs a displacement vector between a given position vector and the
  /// origin.
  explicit constexpr Displacement(const Position<Number>& position);

  /// \brief Destructor. Destroys this displacement vector.
  ~Displacement() noexcept = default;

  /// \brief Copy constructor. Constructs a displacement vector by copying another one.
  constexpr Displacement(const Displacement<Number>& other) = default;

  /// \brief Copy constructor. Constructs a displacement by copying another one.
  template <typename OtherNumber>
  explicit constexpr Displacement(const Displacement<OtherNumber>& other)
    : Displacement(static_cast<Vector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a displacement vector by moving another one.
  constexpr Displacement(Displacement<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this displacement vector by copying another one.
  constexpr Displacement<Number>& operator=(const Displacement<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this displacement by copying another one.
  template <typename OtherNumber>
  constexpr Displacement<Number>& operator=(const Displacement<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this displacement vector by moving another one.
  constexpr Displacement<Number>& operator=(Displacement<Number>&& other) noexcept = default;

  /// \brief Statically creates a displacement vector of zero.
  static constexpr Displacement<Number> Zero() {
    return Displacement<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a displacement vector from the given x, y, and z Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<Number> Create(const Number x, const Number y, const Number z) {
    return Displacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a displacement vector from the given x, y, and z Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Displacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a displacement vector with a given value expressed in a given length
  /// unit.
  template <Unit::Length Unit>
  static constexpr Displacement<Number> Create(const Vector<Number>& value) {
    return Displacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<Number> x() const noexcept {
    return Length<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<Number> y() const noexcept {
    return Length<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<Number> z() const noexcept {
    return Length<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this displacement vector.
  [[nodiscard]] Length<Number> Magnitude() const {
    return Length<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this displacement vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this displacement vector and another one.
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
  /// \brief Constructor. Constructs a displacement vector with a given value expressed in the
  /// standard length unit.
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

template <typename Number>
inline constexpr PlanarDisplacement<Number>::PlanarDisplacement(
    const Displacement<Number>& displacement)
  : PlanarDisplacement(PlanarVector<Number>{displacement.Value()}) {}

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
