// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_ACCELERATION_HPP
#define PHQ_ACCELERATION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Frequency.hpp"
#include "PlanarAcceleration.hpp"
#include "ScalarAcceleration.hpp"
#include "Time.hpp"
#include "Unit/Acceleration.hpp"
#include "Vector.hpp"
#include "Velocity.hpp"

namespace PhQ {

/// \brief Three-dimensional Euclidean acceleration vector. Contains three components in Cartesian
/// coordinates: x, y, and z. For a two-dimensional Euclidean acceleration vector in the XY plane,
/// see PhQ::PlanarAcceleration. For scalar acceleration components or for the magnitude of an
/// acceleration vector, see PhQ::ScalarAcceleration.
template <typename NumericType = double>
class Acceleration : public DimensionalVector<Unit::Acceleration, NumericType> {
public:
  /// \brief Default constructor. Constructs an acceleration vector with an uninitialized value.
  Acceleration() = default;

  /// \brief Constructor. Constructs an acceleration vector with a given value expressed in a given
  /// acceleration unit.
  Acceleration(const Vector<NumericType>& value, const Unit::Acceleration unit)
    : DimensionalVector<Unit::Acceleration, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an acceleration vector from a given set of scalar acceleration
  /// components.
  Acceleration(const ScalarAcceleration<NumericType>& x, const ScalarAcceleration<NumericType>& y,
               const ScalarAcceleration<NumericType>& z)
    : Acceleration<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs an acceleration vector from a given scalar acceleration
  /// magnitude and direction.
  constexpr Acceleration(const ScalarAcceleration<NumericType>& scalar_acceleration,
                         const Direction<NumericType>& direction)
    : Acceleration<NumericType>(scalar_acceleration.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs an acceleration vector from a given planar acceleration vector
  /// in the XY plane. This acceleration vector's z-component is initialized to zero.
  explicit constexpr Acceleration(const PlanarAcceleration<NumericType>& planar_acceleration)
    : Acceleration<NumericType>(Vector<NumericType>{planar_acceleration.Value()}) {}

  /// \brief Constructor. Constructs an acceleration vector from a given velocity and time using the
  /// definition of acceleration.
  constexpr Acceleration(const Velocity<NumericType>& velocity, const Time<NumericType>& time)
    : Acceleration<NumericType>(velocity.Value() / time.Value()) {}

  /// \brief Constructor. Constructs an acceleration vector from a given velocity and frequency
  /// using the definition of acceleration.
  constexpr Acceleration(
      const Velocity<NumericType>& velocity, const Frequency<NumericType>& frequency)
    : Acceleration<NumericType>(velocity.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this acceleration vector.
  ~Acceleration() noexcept = default;

  /// \brief Copy constructor. Constructs an acceleration vector by copying another one.
  constexpr Acceleration(const Acceleration<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an acceleration vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Acceleration(const Acceleration<OtherNumericType>& other)
    : Acceleration(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs an acceleration vector by moving another one.
  constexpr Acceleration(Acceleration<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this acceleration vector by copying another one.
  constexpr Acceleration<NumericType>& operator=(const Acceleration<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this acceleration vector by copying another one.
  template <typename OtherNumericType>
  constexpr Acceleration<NumericType>& operator=(const Acceleration<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this acceleration vector by moving another one.
  constexpr Acceleration<NumericType>& operator=(
      Acceleration<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an acceleration vector of zero.
  static constexpr Acceleration<NumericType> Zero() {
    return Acceleration<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates an acceleration vector from the given x, y, and z Cartesian
  /// components expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return Acceleration<NumericType>{
        ConvertStatically<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates an acceleration vector from the given x, y, and z Cartesian
  /// components expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return Acceleration<NumericType>{
        ConvertStatically<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates an acceleration vector with a given value expressed in a given
  /// acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration<NumericType> Create(const Vector<NumericType>& value) {
    return Acceleration<NumericType>{
        ConvertStatically<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  /// \brief Returns the x Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<NumericType> x() const noexcept {
    return ScalarAcceleration<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<NumericType> y() const noexcept {
    return ScalarAcceleration<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<NumericType> z() const noexcept {
    return ScalarAcceleration<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this acceleration vector.
  [[nodiscard]] ScalarAcceleration<NumericType> Magnitude() const {
    return ScalarAcceleration<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this acceleration vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this acceleration vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Acceleration<NumericType>& other) const {
    return PhQ::Angle<NumericType>{*this, other};
  }

  constexpr Acceleration<NumericType> operator+(const Acceleration<NumericType>& other) const {
    return Acceleration<NumericType>{this->value + other.value};
  }

  constexpr Acceleration<NumericType> operator-(const Acceleration<NumericType>& other) const {
    return Acceleration<NumericType>{this->value - other.value};
  }

  constexpr Acceleration<NumericType> operator*(const NumericType number) const {
    return Acceleration<NumericType>{this->value * number};
  }

  constexpr Velocity<NumericType> operator*(const Time<NumericType>& time) const {
    return Velocity<NumericType>{*this, time};
  }

  constexpr Acceleration<NumericType> operator/(const NumericType number) const {
    return Acceleration<NumericType>{this->value / number};
  }

  constexpr Velocity<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Velocity<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const Acceleration<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const Acceleration<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an acceleration vector with a given value expressed in the
  /// standard acceleration unit.
  explicit constexpr Acceleration(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Acceleration, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Acceleration<NumericType>& left, const Acceleration<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Acceleration<NumericType>& left, const Acceleration<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Acceleration<NumericType>& left, const Acceleration<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Acceleration<NumericType>& left, const Acceleration<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Acceleration<NumericType>& left, const Acceleration<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Acceleration<NumericType>& left, const Acceleration<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const Acceleration<NumericType>& acceleration) {
  stream << acceleration.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Acceleration<NumericType> operator*(
    const NumericType number, const Acceleration<NumericType>& acceleration) {
  return acceleration * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const Acceleration<NumericType>& acceleration)
  : Direction<NumericType>(acceleration.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const Acceleration<NumericType>& acceleration_1,
                                 const Acceleration<NumericType>& acceleration_2)
  : Angle<NumericType>(acceleration_1.Value(), acceleration_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType>::PlanarAcceleration(
    const Acceleration<NumericType>& acceleration)
  : PlanarAcceleration(PlanarVector<NumericType>{acceleration.Value()}) {}

template <typename NumericType>
inline constexpr Velocity<NumericType>::Velocity(
    const Acceleration<NumericType>& acceleration, const Time<NumericType>& time)
  : Velocity<NumericType>(acceleration.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Velocity<NumericType>::Velocity(
    const Acceleration<NumericType>& acceleration, const Frequency<NumericType>& frequency)
  : Velocity<NumericType>(acceleration.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Acceleration<NumericType> Direction<NumericType>::operator*(
    const ScalarAcceleration<NumericType>& scalar_acceleration) const {
  return Acceleration<NumericType>{scalar_acceleration, *this};
}

template <typename NumericType>
inline constexpr Velocity<NumericType> Time<NumericType>::operator*(
    const Acceleration<NumericType>& acceleration) const {
  return Velocity<NumericType>{acceleration, *this};
}

template <typename NumericType>
inline constexpr Acceleration<NumericType> ScalarAcceleration<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return Acceleration<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr Acceleration<NumericType> Velocity<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return Acceleration<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr Acceleration<NumericType> Frequency<NumericType>::operator*(
    const Velocity<NumericType>& velocity) const {
  return Acceleration<NumericType>{velocity, *this};
}

template <typename NumericType>
inline constexpr Acceleration<NumericType> Velocity<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return Acceleration<NumericType>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Acceleration<NumericType>> {
  inline size_t operator()(const PhQ::Acceleration<NumericType>& acceleration) const {
    return hash<PhQ::Vector<NumericType>>()(acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_ACCELERATION_HPP
