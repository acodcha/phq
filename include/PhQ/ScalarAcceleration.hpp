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

#ifndef PHQ_SCALAR_ACCELERATION_HPP
#define PHQ_SCALAR_ACCELERATION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Speed.hpp"
#include "Time.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarAcceleration.
template <typename NumericType>
class Acceleration;

// Forward declaration for class PhQ::ScalarAcceleration.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::ScalarAcceleration.
template <typename NumericType>
class PlanarAcceleration;

// Forward declaration for class PhQ::ScalarAcceleration.
template <typename NumericType>
class PlanarDirection;

/// \brief Scalar acceleration component or magnitude of an acceleration vector. For a
/// three-dimensional Euclidean acceleration vector, see PhQ::Acceleration. For a two-dimensional
/// Euclidean acceleration vector in the XY plane, see PhQ::PlanarAcceleration.
template <typename NumericType = double>
class ScalarAcceleration : public DimensionalScalar<Unit::Acceleration, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar acceleration with an uninitialized value.
  ScalarAcceleration() = default;

  /// \brief Constructor. Constructs a scalar acceleration with a given value expressed in a given
  /// acceleration unit.
  ScalarAcceleration(const NumericType value, const Unit::Acceleration unit)
    : DimensionalScalar<Unit::Acceleration, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar acceleration from a given speed and time using the
  /// definition of acceleration.
  constexpr ScalarAcceleration(const Speed<NumericType>& speed, const Time<NumericType>& time)
    : ScalarAcceleration<NumericType>(speed.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a scalar acceleration from a given speed and frequency using
  /// the definition of acceleration.
  constexpr ScalarAcceleration(
      const Speed<NumericType>& speed, const Frequency<NumericType>& frequency)
    : ScalarAcceleration<NumericType>(speed.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this acceleration scalar.
  ~ScalarAcceleration() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar acceleration by copying another one.
  constexpr ScalarAcceleration(const ScalarAcceleration<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar acceleration by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarAcceleration(const ScalarAcceleration<OtherNumericType>& other)
    : ScalarAcceleration(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar acceleration by moving another one.
  constexpr ScalarAcceleration(ScalarAcceleration<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar acceleration by copying another one.
  constexpr ScalarAcceleration<NumericType>& operator=(
      const ScalarAcceleration<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar acceleration by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarAcceleration<NumericType>& operator=(
      const ScalarAcceleration<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar acceleration by moving another one.
  constexpr ScalarAcceleration<NumericType>& operator=(
      ScalarAcceleration<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar acceleration of zero.
  static constexpr ScalarAcceleration<NumericType> Zero() {
    return ScalarAcceleration<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar acceleration with a given value expressed in a given
  /// acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr ScalarAcceleration<NumericType> Create(const NumericType value) {
    return ScalarAcceleration<NumericType>{
        ConvertStatically<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  constexpr ScalarAcceleration<NumericType> operator+(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const {
    return ScalarAcceleration<NumericType>{this->value + scalar_acceleration.value};
  }

  constexpr ScalarAcceleration<NumericType> operator-(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const {
    return ScalarAcceleration<NumericType>{this->value - scalar_acceleration.value};
  }

  constexpr ScalarAcceleration<NumericType> operator*(const NumericType number) const {
    return ScalarAcceleration<NumericType>{this->value * number};
  }

  constexpr Speed<NumericType> operator*(const Time<NumericType>& time) const {
    return Speed<NumericType>{*this, time};
  }

  constexpr PlanarAcceleration<NumericType> operator*(
      const PlanarDirection<NumericType>& planar_direction) const;

  constexpr Acceleration<NumericType> operator*(const Direction<NumericType>& direction) const;

  constexpr ScalarAcceleration<NumericType> operator/(const NumericType number) const {
    return ScalarAcceleration<NumericType>{this->value / number};
  }

  constexpr Speed<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Speed<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const Speed<NumericType>& speed) const {
    return Frequency<NumericType>{*this, speed};
  }

  constexpr NumericType operator/(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const noexcept {
    return this->value / scalar_acceleration.value;
  }

  constexpr void operator+=(const ScalarAcceleration<NumericType>& scalar_acceleration) noexcept {
    this->value += scalar_acceleration.value;
  }

  constexpr void operator-=(const ScalarAcceleration<NumericType>& scalar_acceleration) noexcept {
    this->value -= scalar_acceleration.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar acceleration with a given value expressed in the
  /// standard acceleration unit.
  explicit constexpr ScalarAcceleration(const NumericType value)
    : DimensionalScalar<Unit::Acceleration, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class PlanarAcceleration;

  template <typename OtherNumericType>
  friend class Acceleration;
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarAcceleration<NumericType>& left,
                                 const ScalarAcceleration<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarAcceleration<NumericType>& left,
                                 const ScalarAcceleration<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarAcceleration<NumericType>& left,
                                const ScalarAcceleration<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarAcceleration<NumericType>& left,
                                const ScalarAcceleration<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarAcceleration<NumericType>& left,
                                 const ScalarAcceleration<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarAcceleration<NumericType>& left,
                                 const ScalarAcceleration<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarAcceleration<NumericType>& scalar_acceleration) {
  stream << scalar_acceleration.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarAcceleration<NumericType> operator*(
    const NumericType number, const ScalarAcceleration<NumericType>& scalar_acceleration) {
  return scalar_acceleration * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Speed<NumericType>& speed, const ScalarAcceleration<NumericType>& scalar_acceleration)
  : Time<NumericType>(speed.Value() / scalar_acceleration.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const ScalarAcceleration<NumericType>& scalar_acceleration, const Speed<NumericType>& speed)
  : Frequency<NumericType>(scalar_acceleration.Value() / speed.Value()) {}

template <typename NumericType>
inline constexpr Speed<NumericType>::Speed(
    const ScalarAcceleration<NumericType>& scalar_acceleration, const Time<NumericType>& time)
  : Speed<NumericType>(scalar_acceleration.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Speed<NumericType>::Speed(
    const ScalarAcceleration<NumericType>& scalar_acceleration,
    const Frequency<NumericType>& frequency)
  : Speed<NumericType>(scalar_acceleration.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr ScalarAcceleration<NumericType> Frequency<NumericType>::operator*(
    const Speed<NumericType>& speed) const {
  return ScalarAcceleration<NumericType>{speed, *this};
}

template <typename NumericType>
inline constexpr Speed<NumericType> Time<NumericType>::operator*(
    const ScalarAcceleration<NumericType>& scalar_acceleration) const {
  return Speed<NumericType>{scalar_acceleration, *this};
}

template <typename NumericType>
inline constexpr ScalarAcceleration<NumericType> Speed<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return ScalarAcceleration<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr ScalarAcceleration<NumericType> Speed<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return ScalarAcceleration<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> Speed<NumericType>::operator/(
    const ScalarAcceleration<NumericType>& scalar_acceleration) const {
  return Time<NumericType>{*this, scalar_acceleration};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarAcceleration<NumericType>> {
  inline size_t operator()(const PhQ::ScalarAcceleration<NumericType>& scalar_acceleration) const {
    return hash<NumericType>()(scalar_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_ACCELERATION_HPP
