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

#ifndef PHQ_SCALAR_ANGULAR_ACCELERATION_HPP
#define PHQ_SCALAR_ANGULAR_ACCELERATION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "AngularSpeed.hpp"
#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/AngularAcceleration.hpp"

namespace PhQ {

/// @brief Scalar angular acceleration. Represents the time rate of change of an angular speed; see
/// also PhQ::AngularSpeed, PhQ::Time, and PhQ::Frequency. Can also represent a component or the
/// magnitude of an angular acceleration pseudovector.
template <typename NumericType = double>
class ScalarAngularAcceleration : public DimensionalScalar<Unit::AngularAcceleration, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar angular acceleration with an uninitialized
  /// value.
  ScalarAngularAcceleration() = default;

  /// \brief Constructor. Constructs a scalar angular acceleration with a given value expressed in a
  /// given angular acceleration unit.
  ScalarAngularAcceleration(const NumericType value, const Unit::AngularAcceleration unit)
    : DimensionalScalar<Unit::AngularAcceleration, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar angular acceleration from a given angular speed and
  /// time using the definition of angular acceleration.
  constexpr ScalarAngularAcceleration(
      const AngularSpeed<NumericType>& angular_speed, const Time<NumericType>& time)
    : ScalarAngularAcceleration<NumericType>(angular_speed.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a scalar angular acceleration from a given angular speed and
  /// frequency using the definition of angular acceleration.
  constexpr ScalarAngularAcceleration(
      const AngularSpeed<NumericType>& angular_speed, const Frequency<NumericType>& frequency)
    : ScalarAngularAcceleration<NumericType>(angular_speed.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this scalar angular acceleration.
  ~ScalarAngularAcceleration() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar angular acceleration by copying another one.
  constexpr ScalarAngularAcceleration(
      const ScalarAngularAcceleration<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar angular acceleration by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarAngularAcceleration(
      const ScalarAngularAcceleration<OtherNumericType>& other)
    : ScalarAngularAcceleration(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar angular acceleration by moving another one.
  constexpr ScalarAngularAcceleration(
      ScalarAngularAcceleration<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar angular acceleration by copying another
  /// one.
  constexpr ScalarAngularAcceleration<NumericType>& operator=(
      const ScalarAngularAcceleration<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar angular acceleration by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr ScalarAngularAcceleration<NumericType>& operator=(
      const ScalarAngularAcceleration<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar angular acceleration by moving another
  /// one.
  constexpr ScalarAngularAcceleration<NumericType>& operator=(
      ScalarAngularAcceleration<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar angular acceleration of zero.
  [[nodiscard]] static constexpr ScalarAngularAcceleration<NumericType> Zero() {
    return ScalarAngularAcceleration<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar angular acceleration with a given value expressed in a
  /// given angular acceleration unit.
  template <Unit::AngularAcceleration Unit>
  [[nodiscard]] static constexpr ScalarAngularAcceleration<NumericType> Create(
      const NumericType value) {
    return ScalarAngularAcceleration<NumericType>{
      ConvertStatically<Unit::AngularAcceleration, Unit, Standard<Unit::AngularAcceleration>>(
          value)};
  }

  constexpr ScalarAngularAcceleration<NumericType> operator+(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration<NumericType>{this->value + scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration<NumericType> operator-(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration<NumericType>{this->value - scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration<NumericType> operator*(const NumericType number) const {
    return ScalarAngularAcceleration<NumericType>{this->value * number};
  }

  constexpr AngularSpeed<NumericType> operator*(const Time<NumericType>& time) const {
    return AngularSpeed<NumericType>{*this, time};
  }

  constexpr ScalarAngularAcceleration<NumericType> operator/(const NumericType number) const {
    return ScalarAngularAcceleration<NumericType>{this->value / number};
  }

  constexpr AngularSpeed<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return AngularSpeed<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const AngularSpeed<NumericType>& angular_speed) const {
    return Frequency<NumericType>{*this, angular_speed};
  }

  constexpr NumericType operator/(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const noexcept {
    return this->value / scalar_angular_acceleration.value;
  }

  constexpr void operator+=(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) noexcept {
    this->value += scalar_angular_acceleration.value;
  }

  constexpr void operator-=(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) noexcept {
    this->value -= scalar_angular_acceleration.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar angular acceleration with a given value expressed in
  /// the standard angular acceleration unit.
  explicit constexpr ScalarAngularAcceleration(const NumericType value)
    : DimensionalScalar<Unit::AngularAcceleration, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarAngularAcceleration<NumericType>& left,
                                 const ScalarAngularAcceleration<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarAngularAcceleration<NumericType>& left,
                                 const ScalarAngularAcceleration<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarAngularAcceleration<NumericType>& left,
                                const ScalarAngularAcceleration<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarAngularAcceleration<NumericType>& left,
                                const ScalarAngularAcceleration<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarAngularAcceleration<NumericType>& left,
                                 const ScalarAngularAcceleration<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarAngularAcceleration<NumericType>& left,
                                 const ScalarAngularAcceleration<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) {
  stream << scalar_angular_acceleration.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarAngularAcceleration<NumericType> operator*(
    const NumericType number,
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) {
  return scalar_angular_acceleration * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const AngularSpeed<NumericType>& angular_speed,
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration)
  : Time<NumericType>(angular_speed.Value() / scalar_angular_acceleration.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration,
    const AngularSpeed<NumericType>& angular_speed)
  : Frequency<NumericType>(scalar_angular_acceleration.Value() / angular_speed.Value()) {}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType>::AngularSpeed(
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration,
    const Time<NumericType>& time)
  : AngularSpeed<NumericType>(scalar_angular_acceleration.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType>::AngularSpeed(
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration,
    const Frequency<NumericType>& frequency)
  : AngularSpeed<NumericType>(scalar_angular_acceleration.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType> Time<NumericType>::operator*(
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const {
  return AngularSpeed<NumericType>(scalar_angular_acceleration, *this);
}

template <typename NumericType>
inline constexpr ScalarAngularAcceleration<NumericType> Frequency<NumericType>::operator*(
    const AngularSpeed<NumericType>& angular_speed) const {
  return ScalarAngularAcceleration<NumericType>{angular_speed, *this};
}

template <typename NumericType>
inline constexpr ScalarAngularAcceleration<NumericType> AngularSpeed<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return ScalarAngularAcceleration<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr ScalarAngularAcceleration<NumericType> AngularSpeed<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return ScalarAngularAcceleration<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> AngularSpeed<NumericType>::operator/(
    const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const {
  return Time<NumericType>{*this, scalar_angular_acceleration};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarAngularAcceleration<NumericType>> {
  inline size_t operator()(
      const PhQ::ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const {
    return hash<NumericType>()(scalar_angular_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_ANGULAR_ACCELERATION_HPP
