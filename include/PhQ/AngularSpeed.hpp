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

#ifndef PHQ_ANGULAR_SPEED_HPP
#define PHQ_ANGULAR_SPEED_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration for class PhQ::AngularSpeed.
template <typename NumericType>
class ScalarAngularAcceleration;

/// @brief Angular speed, also known as angular rate or angular frequency. Represents the time rate
/// of change of an angle; see also PhQ::Angle, PhQ::ScalarAngularAcceleration, PhQ::Time, and
/// PhQ::Frequency. Can also represent a component or the magnitude of an angular velocity
/// pseudovector.
template <typename NumericType = double>
class AngularSpeed : public DimensionalScalar<Unit::AngularSpeed, NumericType> {
public:
  /// \brief Default constructor. Constructs an angular speed with an uninitialized value.
  AngularSpeed() = default;

  /// \brief Constructor. Constructs an angular speed with a given value expressed in a given
  /// angular speed unit.
  AngularSpeed(const NumericType value, const Unit::AngularSpeed unit)
    : DimensionalScalar<Unit::AngularSpeed, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an angular speed from a given angle and time using the
  /// definition of angular speed.
  constexpr AngularSpeed(const Angle<NumericType>& angle, const Time<NumericType>& time)
    : AngularSpeed<NumericType>(angle.Value() / time.Value()) {}

  /// \brief Constructor. Constructs an angular speed from a given angle and frequency using the
  /// definition of angular speed.
  constexpr AngularSpeed(const Angle<NumericType>& angle, const Frequency<NumericType>& frequency)
    : AngularSpeed<NumericType>(angle.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs an angular speed from a given scalar angular acceleration and
  /// time using the definition of angular acceleration.
  constexpr AngularSpeed(const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration,
                         const Time<NumericType>& time);

  /// \brief Constructor. Constructs an angular speed from a given scalar angular acceleration and
  /// frequency using the definition of angular acceleration.
  constexpr AngularSpeed(const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration,
                         const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this angular speed.
  ~AngularSpeed() noexcept = default;

  /// \brief Copy constructor. Constructs an angular speed by copying another one.
  constexpr AngularSpeed(const AngularSpeed<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an angular speed by copying another one.
  template <typename OtherNumericType>
  explicit constexpr AngularSpeed(const AngularSpeed<OtherNumericType>& other)
    : AngularSpeed(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an angular speed by moving another one.
  constexpr AngularSpeed(AngularSpeed<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this angular speed by copying another one.
  constexpr AngularSpeed<NumericType>& operator=(const AngularSpeed<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this angular speed by copying another one.
  template <typename OtherNumericType>
  constexpr AngularSpeed<NumericType>& operator=(const AngularSpeed<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this angular speed by moving another one.
  constexpr AngularSpeed<NumericType>& operator=(
      AngularSpeed<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an angular speed of zero.
  [[nodiscard]] static constexpr AngularSpeed<NumericType> Zero() {
    return AngularSpeed<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an angular speed with a given value expressed in a given angular
  /// speed unit.
  template <Unit::AngularSpeed Unit>
  [[nodiscard]] static constexpr AngularSpeed<NumericType> Create(const NumericType value) {
    return AngularSpeed<NumericType>{
        ConvertStatically<Unit::AngularSpeed, Unit, Standard<Unit::AngularSpeed>>(value)};
  }

  constexpr AngularSpeed<NumericType> operator+(
      const AngularSpeed<NumericType>& angular_speed) const {
    return AngularSpeed<NumericType>{this->value + angular_speed.value};
  }

  constexpr AngularSpeed<NumericType> operator-(
      const AngularSpeed<NumericType>& angular_speed) const {
    return AngularSpeed<NumericType>{this->value - angular_speed.value};
  }

  constexpr AngularSpeed<NumericType> operator*(const NumericType number) const {
    return AngularSpeed<NumericType>{this->value * number};
  }

  constexpr Angle<NumericType> operator*(const Time<NumericType>& time) const {
    return Angle<NumericType>{*this, time};
  }

  constexpr ScalarAngularAcceleration<NumericType> operator*(
      const Frequency<NumericType>& frequency) const;

  constexpr AngularSpeed<NumericType> operator/(const NumericType number) const {
    return AngularSpeed<NumericType>{this->value / number};
  }

  constexpr Angle<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Angle<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const Angle<NumericType>& angle) const {
    return Frequency<NumericType>{*this, angle};
  }

  constexpr ScalarAngularAcceleration<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const;

  constexpr NumericType operator/(const AngularSpeed<NumericType>& angular_speed) const noexcept {
    return this->value / angular_speed.value;
  }

  constexpr void operator+=(const AngularSpeed<NumericType>& angular_speed) noexcept {
    this->value += angular_speed.value;
  }

  constexpr void operator-=(const AngularSpeed<NumericType>& angular_speed) noexcept {
    this->value -= angular_speed.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an angular speed with a given value expressed in the standard
  /// angular speed unit.
  explicit constexpr AngularSpeed(const NumericType value)
    : DimensionalScalar<Unit::AngularSpeed, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const AngularSpeed<NumericType>& left, const AngularSpeed<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const AngularSpeed<NumericType>& left, const AngularSpeed<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const AngularSpeed<NumericType>& left, const AngularSpeed<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const AngularSpeed<NumericType>& left, const AngularSpeed<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const AngularSpeed<NumericType>& left, const AngularSpeed<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const AngularSpeed<NumericType>& left, const AngularSpeed<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const AngularSpeed<NumericType>& angular_speed) {
  stream << angular_speed.Print();
  return stream;
}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType> operator*(
    const NumericType number, const AngularSpeed<NumericType>& angular_speed) {
  return angular_speed * number;
}

template <typename NumericType>
inline constexpr Angle<NumericType>::Angle(
    const AngularSpeed<NumericType>& angular_speed, const Time<NumericType>& time)
  : Angle<NumericType>(angular_speed.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Angle<NumericType>::Angle(
    const AngularSpeed<NumericType>& angular_speed, const Frequency<NumericType>& frequency)
  : Angle<NumericType>(angular_speed.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Angle<NumericType>& angle, const AngularSpeed<NumericType>& angular_speed)
  : Time<NumericType>(angle.Value() / angular_speed.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const AngularSpeed<NumericType>& angular_speed, const Angle<NumericType>& angle)
  : Frequency<NumericType>(angular_speed.Value() / angle.Value()) {}

template <typename NumericType>
inline constexpr Angle<NumericType> Time<NumericType>::operator*(
    const AngularSpeed<NumericType>& angular_speed) const {
  return Angle<NumericType>(angular_speed, *this);
}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType> Angle<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return AngularSpeed<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType> Frequency<NumericType>::operator*(
    const Angle<NumericType>& angle) const {
  return AngularSpeed<NumericType>{angle, *this};
}

template <typename NumericType>
inline constexpr AngularSpeed<NumericType> Angle<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return AngularSpeed<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> Angle<NumericType>::operator/(
    const AngularSpeed<NumericType>& angular_speed) const {
  return Time<NumericType>{*this, angular_speed};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::AngularSpeed<NumericType>> {
  inline size_t operator()(const PhQ::AngularSpeed<NumericType>& angular_speed) const {
    return hash<NumericType>()(angular_speed.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGULAR_SPEED_HPP
