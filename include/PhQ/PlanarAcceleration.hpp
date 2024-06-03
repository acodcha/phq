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

/// \brief Two-dimensional Euclidean acceleration vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. For a three-dimensional Euclidean acceleration vector, see
/// PhQ::Acceleration. For scalar acceleration components or for the magnitude of an acceleration
/// vector, see PhQ::ScalarAcceleration.
template <typename NumericType = double>
class PlanarAcceleration : public DimensionalPlanarVector<Unit::Acceleration, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar acceleration vector with an uninitialized
  /// value.
  PlanarAcceleration() = default;

  /// \brief Constructor. Constructs a planar acceleration vector with a given value expressed in a
  /// given acceleration unit.
  PlanarAcceleration(const PlanarVector<NumericType>& value, const Unit::Acceleration unit)
    : DimensionalPlanarVector<Unit::Acceleration, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given set of scalar
  /// acceleration components.
  PlanarAcceleration(
      const ScalarAcceleration<NumericType>& x, const ScalarAcceleration<NumericType>& y)
    : PlanarAcceleration<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given scalar acceleration
  /// magnitude and planar direction.
  constexpr PlanarAcceleration(const ScalarAcceleration<NumericType>& scalar_acceleration,
                               const PlanarDirection<NumericType>& planar_direction)
    : PlanarAcceleration<NumericType>(scalar_acceleration.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given acceleration vector
  /// by projecting the acceleration vector onto the XY plane.
  explicit constexpr PlanarAcceleration(const Acceleration<NumericType>& acceleration);

  /// \brief Constructor. Constructs a planar acceleration vector from a given planar velocity and
  /// time using the definition of acceleration.
  constexpr PlanarAcceleration(
      const PlanarVelocity<NumericType>& planar_velocity, const Time<NumericType>& time)
    : PlanarAcceleration<NumericType>(planar_velocity.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a planar acceleration vector from a given planar velocity and
  /// frequency using the definition of acceleration.
  constexpr PlanarAcceleration(
      const PlanarVelocity<NumericType>& planar_velocity, const Frequency<NumericType>& frequency)
    : PlanarAcceleration<NumericType>(planar_velocity.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this acceleration vector.
  ~PlanarAcceleration() noexcept = default;

  /// \brief Copy constructor. Constructs a planar acceleration vector by copying another one.
  constexpr PlanarAcceleration(const PlanarAcceleration<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar acceleration vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarAcceleration(const PlanarAcceleration<OtherNumericType>& other)
    : PlanarAcceleration(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar acceleration vector by moving another one.
  constexpr PlanarAcceleration(PlanarAcceleration<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this acceleration vector by copying another one.
  constexpr PlanarAcceleration<NumericType>& operator=(
      const PlanarAcceleration<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this acceleration vector by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarAcceleration<NumericType>& operator=(
      const PlanarAcceleration<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this acceleration vector by moving another one.
  constexpr PlanarAcceleration<NumericType>& operator=(
      PlanarAcceleration<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar acceleration vector of zero.
  [[nodiscard]] static constexpr PlanarAcceleration<NumericType> Zero() {
    return PlanarAcceleration<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar acceleration vector from the given x and y Cartesian
  /// components expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  [[nodiscard]] static constexpr PlanarAcceleration<NumericType> Create(
      const NumericType x, const NumericType y) {
    return PlanarAcceleration<NumericType>{
        ConvertStatically<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar acceleration vector from the given x and y Cartesian
  /// components expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  [[nodiscard]] static constexpr PlanarAcceleration<NumericType> Create(
      const std::array<NumericType, 2>& x_y) {
    return PlanarAcceleration<NumericType>{
        ConvertStatically<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar acceleration vector with a given value expressed in a given
  /// acceleration unit.
  template <Unit::Acceleration Unit>
  [[nodiscard]] static constexpr PlanarAcceleration<NumericType> Create(
      const PlanarVector<NumericType>& value) {
    return PlanarAcceleration<NumericType>{
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

  /// \brief Returns the magnitude of this acceleration vector.
  [[nodiscard]] ScalarAcceleration<NumericType> Magnitude() const {
    return ScalarAcceleration<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this acceleration vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this acceleration vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const PlanarAcceleration<NumericType>& other) const {
    return PhQ::Angle<NumericType>{*this, other};
  }

  constexpr PlanarAcceleration<NumericType> operator+(
      const PlanarAcceleration<NumericType>& other) const {
    return PlanarAcceleration<NumericType>{this->value + other.value};
  }

  constexpr PlanarAcceleration<NumericType> operator-(
      const PlanarAcceleration<NumericType>& other) const {
    return PlanarAcceleration<NumericType>{this->value - other.value};
  }

  constexpr PlanarAcceleration<NumericType> operator*(const NumericType number) const {
    return PlanarAcceleration<NumericType>{this->value * number};
  }

  constexpr PlanarVelocity<NumericType> operator*(const Time<NumericType>& time) const {
    return PlanarVelocity<NumericType>{*this, time};
  }

  constexpr PlanarAcceleration<NumericType> operator/(const NumericType number) const {
    return PlanarAcceleration<NumericType>{this->value / number};
  }

  constexpr PlanarVelocity<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return PlanarVelocity<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const PlanarAcceleration<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const PlanarAcceleration<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar acceleration vector with a given value expressed in
  /// the standard acceleration unit.
  explicit constexpr PlanarAcceleration(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::Acceleration, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const PlanarAcceleration<NumericType>& left,
                                 const PlanarAcceleration<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const PlanarAcceleration<NumericType>& left,
                                 const PlanarAcceleration<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const PlanarAcceleration<NumericType>& left,
                                const PlanarAcceleration<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const PlanarAcceleration<NumericType>& left,
                                const PlanarAcceleration<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const PlanarAcceleration<NumericType>& left,
                                 const PlanarAcceleration<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const PlanarAcceleration<NumericType>& left,
                                 const PlanarAcceleration<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarAcceleration<NumericType>& planar_acceleration) {
  stream << planar_acceleration.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType> operator*(
    const NumericType number, const PlanarAcceleration<NumericType>& planar_acceleration) {
  return planar_acceleration * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarAcceleration<NumericType>& planar_acceleration)
  : PlanarDirection<NumericType>(planar_acceleration.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarAcceleration<NumericType>& planar_acceleration_1,
                                 const PlanarAcceleration<NumericType>& planar_acceleration_2)
  : Angle<NumericType>(planar_acceleration_1.Value(), planar_acceleration_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType>::PlanarVelocity(
    const PlanarAcceleration<NumericType>& planar_acceleration, const Time<NumericType>& time)
  : PlanarVelocity<NumericType>(planar_acceleration.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType>::PlanarVelocity(
    const PlanarAcceleration<NumericType>& planar_acceleration,
    const Frequency<NumericType>& frequency)
  : PlanarVelocity<NumericType>(planar_acceleration.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType> PlanarDirection<NumericType>::operator*(
    const ScalarAcceleration<NumericType>& scalar_acceleration) const {
  return PlanarAcceleration<NumericType>{scalar_acceleration, *this};
}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> Time<NumericType>::operator*(
    const PlanarAcceleration<NumericType>& planar_acceleration) const {
  return PlanarVelocity<NumericType>{planar_acceleration, *this};
}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType> ScalarAcceleration<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarAcceleration<NumericType>{*this, planar_direction};
}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType> PlanarVelocity<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return PlanarAcceleration<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType> Frequency<NumericType>::operator*(
    const PlanarVelocity<NumericType>& planar_velocity) const {
  return PlanarAcceleration<NumericType>{planar_velocity, *this};
}

template <typename NumericType>
inline constexpr PlanarAcceleration<NumericType> PlanarVelocity<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return PlanarAcceleration<NumericType>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarAcceleration<NumericType>> {
  inline size_t operator()(const PhQ::PlanarAcceleration<NumericType>& planar_acceleration) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_ACCELERATION_HPP
