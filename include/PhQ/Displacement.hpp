// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Displacement.
template <typename NumericType>
class Position;

// Forward declaration for class PhQ::Displacement.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Displacement.
template <typename NumericType>
class Velocity;

/// \brief Three-dimensional Euclidean displacement vector. Contains three components in Cartesian
/// coordinates: x, y, and z. Displacement is not to be confused with position; for a
/// three-dimensional Euclidean position vector, see PhQ::Position. For a two-dimensional Euclidean
/// displacement vector in the XY plane, see PhQ::PlanarDisplacement. For scalar displacement
/// components or for the magnitude of a displacement vector, see PhQ::Length.
template <typename NumericType = double>
class Displacement : public DimensionalVector<Unit::Length, NumericType> {
public:
  /// \brief Default constructor. Constructs a displacement vector with an uninitialized value.
  Displacement() = default;

  /// \brief Constructor. Constructs a displacement vector with a given value expressed in a given
  /// length unit.
  Displacement(const Vector<NumericType>& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a displacement vector from a given set of length components.
  Displacement(
      const Length<NumericType>& x, const Length<NumericType>& y, const Length<NumericType>& z)
    : Displacement<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a displacement vector from a given length and direction.
  constexpr Displacement(const Length<NumericType>& length, const Direction<NumericType>& direction)
    : Displacement<NumericType>(length.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs an displacement vector from a given planar displacement vector
  /// in the XY plane. This displacement vector's z-component is initialized to zero.
  explicit constexpr Displacement(const PlanarDisplacement<NumericType>& planar_displacement)
    : Displacement<NumericType>(Vector<NumericType>{planar_displacement.Value()}) {}

  /// \brief Constructor. Constructs a displacement vector from a given velocity vector and time
  /// using the definition of velocity.
  constexpr Displacement(const Velocity<NumericType>& velocity, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a displacement vector from a given velocity vector and
  /// frequency using the definition of velocity.
  constexpr Displacement(
      const Velocity<NumericType>& velocity, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a displacement vector between a given position vector and the
  /// origin.
  explicit constexpr Displacement(const Position<NumericType>& position);

  /// \brief Destructor. Destroys this displacement vector.
  ~Displacement() noexcept = default;

  /// \brief Copy constructor. Constructs a displacement vector by copying another one.
  constexpr Displacement(const Displacement<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a displacement by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Displacement(const Displacement<OtherNumericType>& other)
    : Displacement(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a displacement vector by moving another one.
  constexpr Displacement(Displacement<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this displacement vector by copying another one.
  constexpr Displacement<NumericType>& operator=(const Displacement<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this displacement by copying another one.
  template <typename OtherNumericType>
  constexpr Displacement<NumericType>& operator=(const Displacement<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this displacement vector by moving another one.
  constexpr Displacement<NumericType>& operator=(
      Displacement<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a displacement vector of zero.
  static constexpr Displacement<NumericType> Zero() {
    return Displacement<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a displacement vector from the given x, y, and z Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return Displacement<NumericType>{ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(
        Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a displacement vector from the given x, y, and z Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Displacement<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return Displacement<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a displacement vector with a given value expressed in a given length
  /// unit.
  template <Unit::Length Unit>
  static constexpr Displacement<NumericType> Create(const Vector<NumericType>& value) {
    return Displacement<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<NumericType> x() const noexcept {
    return Length<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<NumericType> y() const noexcept {
    return Length<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this displacement vector.
  [[nodiscard]] constexpr Length<NumericType> z() const noexcept {
    return Length<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this displacement vector.
  [[nodiscard]] Length<NumericType> Magnitude() const {
    return Length<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this displacement vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this displacement vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Displacement<NumericType>& displacement) const {
    return PhQ::Angle<NumericType>{*this, displacement};
  }

  constexpr Position<NumericType> operator+(const Position<NumericType>& position) const;

  constexpr Displacement<NumericType> operator+(
      const Displacement<NumericType>& displacement) const {
    return Displacement<NumericType>{this->value + displacement.value};
  }

  constexpr Position<NumericType> operator-(const Position<NumericType>& position) const;

  constexpr Displacement<NumericType> operator-(
      const Displacement<NumericType>& displacement) const {
    return Displacement<NumericType>{this->value - displacement.value};
  }

  constexpr Displacement<NumericType> operator*(const NumericType number) const {
    return Displacement<NumericType>{this->value * number};
  }

  constexpr Velocity<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Displacement<NumericType> operator/(const NumericType number) const {
    return Displacement<NumericType>{this->value / number};
  }

  constexpr Velocity<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr void operator+=(const Displacement<NumericType>& displacement) noexcept {
    this->value += displacement.value;
  }

  constexpr void operator-=(const Displacement<NumericType>& displacement) noexcept {
    this->value -= displacement.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a displacement vector with a given value expressed in the
  /// standard length unit.
  explicit constexpr Displacement(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Length, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class Position;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Displacement<NumericType>& left, const Displacement<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Displacement<NumericType>& left, const Displacement<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Displacement<NumericType>& left, const Displacement<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Displacement<NumericType>& left, const Displacement<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Displacement<NumericType>& left, const Displacement<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Displacement<NumericType>& left, const Displacement<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const Displacement<NumericType>& displacement) {
  stream << displacement.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Displacement<NumericType> operator*(
    const NumericType number, const Displacement<NumericType>& displacement) {
  return displacement * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const Displacement<NumericType>& displacement)
  : Direction<NumericType>(displacement.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Displacement<NumericType>& displacement1, const Displacement<NumericType>& displacement2)
  : Angle<NumericType>(displacement1.Value(), displacement2.Value()) {}

template <typename NumericType>
inline constexpr PlanarDisplacement<NumericType>::PlanarDisplacement(
    const Displacement<NumericType>& displacement)
  : PlanarDisplacement(PlanarVector<NumericType>{displacement.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Displacement<NumericType>> {
  inline size_t operator()(const PhQ::Displacement<NumericType>& displacement) const {
    return hash<PhQ::Vector<NumericType>>()(displacement.Value());
  }
};

}  // namespace std

#endif  // PHQ_DISPLACEMENT_HPP
