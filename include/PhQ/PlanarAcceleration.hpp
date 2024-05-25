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

#ifndef PHQ_PLANAR_ACCELERATION_HPP
#define PHQ_PLANAR_ACCELERATION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "Frequency.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "PlanarVelocity.hpp"
#include "ScalarAcceleration.hpp"
#include "Time.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

/// \brief Planar acceleration vector in the XY plane. See also PhQ::Acceleration and
/// PhQ::ScalarAcceleration.
template <typename Number = double>
class PlanarAcceleration : public DimensionalPlanarVector<Unit::Acceleration, Number> {
public:
  /// \brief Default constructor. Constructs a planar acceleration vector with an uninitialized
  /// value.
  PlanarAcceleration() = default;

  /// \brief Constructor. Constructs a planar acceleration vector with a given value expressed in a
  /// given acceleration unit.
  PlanarAcceleration(const PlanarVector<Number>& value, const Unit::Acceleration unit)
    : DimensionalPlanarVector<Unit::Acceleration, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given scalar acceleration
  /// magnitude and planar direction.
  constexpr PlanarAcceleration(const ScalarAcceleration<Number>& scalar_acceleration,
                               const PlanarDirection<Number>& planar_direction)
    : PlanarAcceleration<Number>(scalar_acceleration.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given acceleration vector
  /// by projecting the acceleration vector onto the XY plane.
  explicit constexpr PlanarAcceleration(const Acceleration<Number>& acceleration);

  /// \brief Constructor. Constructs a planar acceleration vector from a given planar velocity and
  /// time using the definition of acceleration.
  constexpr PlanarAcceleration(
      const PlanarVelocity<Number>& planar_velocity, const Time<Number>& time)
    : PlanarAcceleration<Number>(planar_velocity.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given planar velocity and
  /// frequency using the definition of acceleration.
  constexpr PlanarAcceleration(
      const PlanarVelocity<Number>& planar_velocity, const Frequency<Number>& frequency)
    : PlanarAcceleration<Number>(planar_velocity.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this acceleration vector.
  ~PlanarAcceleration() noexcept = default;

  /// \brief Copy constructor. Constructs a planar acceleration vector by copying another one.
  constexpr PlanarAcceleration(const PlanarAcceleration<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar acceleration vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarAcceleration(const PlanarAcceleration<OtherNumber>& other)
    : PlanarAcceleration(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar acceleration vector by moving another one.
  constexpr PlanarAcceleration(PlanarAcceleration<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this acceleration vector by copying another one.
  constexpr PlanarAcceleration<Number>& operator=(
      const PlanarAcceleration<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this acceleration vector by copying another one.
  template <typename OtherNumber>
  constexpr PlanarAcceleration<Number>& operator=(const PlanarAcceleration<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this acceleration vector by moving another one.
  constexpr PlanarAcceleration<Number>& operator=(
      PlanarAcceleration<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar acceleration vector of zero.
  static constexpr PlanarAcceleration<Number> Zero() {
    return PlanarAcceleration<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar acceleration vector from the given x and y Cartesian
  /// components expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr PlanarAcceleration<Number> Create(const Number x, const Number y) {
    return PlanarAcceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar acceleration vector from the given x and y Cartesian
  /// components expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr PlanarAcceleration<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarAcceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar acceleration vector with a given value expressed in a given
  /// acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr PlanarAcceleration<Number> Create(const PlanarVector<Number>& value) {
    return PlanarAcceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  /// \brief Returns the x Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<Number> x() const noexcept {
    return ScalarAcceleration<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<Number> y() const noexcept {
    return ScalarAcceleration<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this acceleration vector.
  [[nodiscard]] ScalarAcceleration<Number> Magnitude() const {
    return ScalarAcceleration<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this acceleration vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this acceleration vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarAcceleration<Number>& other) const {
    return PhQ::Angle<Number>{*this, other};
  }

  constexpr PlanarAcceleration<Number> operator+(const PlanarAcceleration<Number>& other) const {
    return PlanarAcceleration<Number>{this->value + other.value};
  }

  constexpr PlanarAcceleration<Number> operator-(const PlanarAcceleration<Number>& other) const {
    return PlanarAcceleration<Number>{this->value - other.value};
  }

  constexpr PlanarAcceleration<Number> operator*(const Number number) const {
    return PlanarAcceleration<Number>{this->value * number};
  }

  constexpr PlanarVelocity<Number> operator*(const Time<Number>& time) const {
    return PlanarVelocity<Number>{*this, time};
  }

  constexpr PlanarAcceleration<Number> operator/(const Number number) const {
    return PlanarAcceleration<Number>{this->value / number};
  }

  constexpr PlanarVelocity<Number> operator/(const Frequency<Number>& frequency) const {
    return PlanarVelocity<Number>{*this, frequency};
  }

  constexpr void operator+=(const PlanarAcceleration<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const PlanarAcceleration<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar acceleration vector with a given value expressed in
  /// the standard acceleration unit.
  explicit constexpr PlanarAcceleration(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Acceleration, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarAcceleration<Number>& left, const PlanarAcceleration<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarAcceleration<Number>& left, const PlanarAcceleration<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarAcceleration<Number>& left, const PlanarAcceleration<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarAcceleration<Number>& left, const PlanarAcceleration<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarAcceleration<Number>& left, const PlanarAcceleration<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarAcceleration<Number>& left, const PlanarAcceleration<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarAcceleration<Number>& planar_acceleration) {
  stream << planar_acceleration.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarAcceleration<Number> operator*(
    const Number number, const PlanarAcceleration<Number>& planar_acceleration) {
  return planar_acceleration * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(
    const PlanarAcceleration<Number>& planar_acceleration)
  : PlanarDirection<Number>(planar_acceleration.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarAcceleration<Number>& planar_acceleration_1,
                            const PlanarAcceleration<Number>& planar_acceleration_2)
  : Angle<Number>(planar_acceleration_1.Value(), planar_acceleration_2.Value()) {}

template <typename Number>
inline constexpr PlanarVelocity<Number>::PlanarVelocity(
    const PlanarAcceleration<Number>& planar_acceleration, const Time<Number>& time)
  : PlanarVelocity<Number>(planar_acceleration.Value() * time.Value()) {}

template <typename Number>
inline constexpr PlanarVelocity<Number>::PlanarVelocity(
    const PlanarAcceleration<Number>& planar_acceleration, const Frequency<Number>& frequency)
  : PlanarVelocity<Number>(planar_acceleration.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr PlanarAcceleration<Number> PlanarDirection<Number>::operator*(
    const ScalarAcceleration<Number>& scalar_acceleration) const {
  return PlanarAcceleration<Number>{scalar_acceleration, *this};
}

template <typename Number>
inline constexpr PlanarVelocity<Number> Time<Number>::operator*(
    const PlanarAcceleration<Number>& planar_acceleration) const {
  return PlanarVelocity<Number>{planar_acceleration, *this};
}

template <typename Number>
inline constexpr PlanarAcceleration<Number> ScalarAcceleration<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarAcceleration<Number>{*this, planar_direction};
}

template <typename Number>
inline constexpr PlanarAcceleration<Number> PlanarVelocity<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return PlanarAcceleration<Number>{*this, frequency};
}

template <typename Number>
inline constexpr PlanarAcceleration<Number> Frequency<Number>::operator*(
    const PlanarVelocity<Number>& planar_velocity) const {
  return PlanarAcceleration<Number>{planar_velocity, *this};
}

template <typename Number>
inline constexpr PlanarAcceleration<Number> PlanarVelocity<Number>::operator/(
    const Time<Number>& time) const {
  return PlanarAcceleration<Number>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarAcceleration<Number>> {
  inline size_t operator()(const PhQ::PlanarAcceleration<Number>& planar_acceleration) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_ACCELERATION_HPP
