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

#ifndef PHQ_ANGLE_HPP
#define PHQ_ANGLE_HPP

#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Angle.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Acceleration;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class AngularSpeed;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Displacement;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Force;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class HeatFlux;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Position;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class TemperatureGradient;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Traction;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class VectorArea;

// Forward declaration for class PhQ::Angle.
template <typename Number>
class Velocity;

/// \brief Planar angle.
template <typename Number = double>
class Angle : public DimensionalScalar<Unit::Angle, Number> {
public:
  /// \brief Default constructor. Constructs an angle with an uninitialized value.
  Angle() = default;

  /// \brief Constructor. Constructs an angle with a given value expressed in a given angle unit.
  Angle(const Number value, const Unit::Angle unit) : DimensionalScalar<Unit::Angle>(value, unit) {}

  /// \brief Constructor. Constructs an angle by computing the angle between two given vector
  /// values.
  Angle(const Vector<Number>& vector1, const Vector<Number>& vector2)
    : Angle(std::acos(vector1.Dot(vector2) / (vector1.Magnitude() * vector2.Magnitude()))) {}

  /// \brief Constructor. Constructs an angle by computing the angle between a given vector and
  /// direction.
  Angle(const Vector<Number>& vector, const Direction<Number>& direction);

  /// \brief Constructor. Constructs an angle by computing the angle between a given direction and
  /// vector.
  Angle(const Direction<Number>& direction, const Vector<Number>& vector);

  /// \brief Constructor. Constructs an angle by computing the angle between two given directions.
  Angle(const Direction<Number>& direction1, const Direction<Number>& direction2);

  /// \brief Constructor. Constructs an angle from a given angular speed and time using the
  /// definition of angular speed.
  constexpr Angle(const AngularSpeed<Number>& angular_speed, const Time<Number>& time);

  /// \brief Constructor. Constructs an angle from a given angular speed and frequency using the
  /// definition of angular speed.
  constexpr Angle(const AngularSpeed<Number>& angular_speed, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs an angle by computing the angle between two given acceleration
  /// vectors.
  Angle(const Acceleration<Number>& acceleration1, const Acceleration<Number>& acceleration2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given vector areas.
  Angle(const VectorArea<Number>& vector_area_1, const VectorArea<Number>& vector_area_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given
  /// displacements.
  Angle(const Displacement<Number>& displacement1, const Displacement<Number>& displacement2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given forces.
  Angle(const Force<Number>& force1, const Force<Number>& force2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given heat fluxes.
  Angle(const HeatFlux<Number>& heat_flux_1, const HeatFlux<Number>& heat_flux_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given positions.
  Angle(const Position<Number>& position1, const Position<Number>& position2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given temperature
  /// gradients.
  Angle(const TemperatureGradient<Number>& temperature_gradient_1,
        const TemperatureGradient<Number>& temperature_gradient_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given tractions.
  Angle(const Traction<Number>& traction1, const Traction<Number>& traction2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given velocities.
  Angle(const Velocity<Number>& velocity1, const Velocity<Number>& velocity2);

  /// \brief Destructor. Destroys this angle.
  ~Angle() noexcept = default;

  /// \brief Copy constructor. Constructs an angle by copying another one.
  constexpr Angle(const Angle<Number>& other) = default;

  /// \brief Copy constructor. Constructs an angle by copying another one.
  template <typename OtherNumber>
  explicit constexpr Angle(const Angle<OtherNumber>& other)
    : Angle(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an angle by moving another one.
  constexpr Angle(Angle<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this angle by copying another one.
  constexpr Angle<Number>& operator=(const Angle<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this angle by copying another one.
  template <typename OtherNumber>
  constexpr Angle<Number>& operator=(const Angle<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this angle by moving another one.
  constexpr Angle<Number>& operator=(Angle<Number>&& other) noexcept = default;

  /// \brief Statically creates an angle of zero.
  static constexpr Angle<Number> Zero() {
    return Angle<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an angle with a given value expressed in a given angle unit.
  template <Unit::Angle Unit>
  static constexpr Angle<Number> Create(const Number value) {
    return Angle<Number>{StaticConvertCopy<Unit::Angle, Unit, Standard<Unit::Angle>>(value)};
  }

  constexpr Angle<Number> operator+(const Angle<Number>& other) const {
    return Angle<Number>{this->value + other.value};
  }

  constexpr Angle<Number> operator-(const Angle<Number>& other) const {
    return Angle<Number>{this->value - other.value};
  }

  constexpr Angle<Number> operator*(const Number number) const {
    return Angle<Number>{this->value * number};
  }

  constexpr AngularSpeed<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Angle<Number> operator/(const Number number) const {
    return Angle<Number>{this->value / number};
  }

  constexpr AngularSpeed<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const AngularSpeed<Number>& angular_speed) const;

  constexpr Number operator/(const Angle<Number>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const Angle<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const Angle<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an angle with a given value expressed in the standard angle
  /// unit.
  explicit constexpr Angle(const Number value) : DimensionalScalar<Unit::Angle, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Angle<Number>& left, const Angle<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Angle<Number>& left, const Angle<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Angle<Number>& left, const Angle<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Angle<Number>& left, const Angle<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Angle<Number>& left, const Angle<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Angle<Number>& left, const Angle<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Angle<Number>& angle) {
  stream << angle.Print();
  return stream;
}

template <typename Number>
inline constexpr Angle<Number> operator*(const Number number, const Angle<Number>& angle) {
  return angle * number;
}

template <typename Number>
inline PhQ::Angle<Number> Vector<Number>::Angle(const Vector<Number>& vector) const {
  return PhQ::Angle{*this, vector};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Angle<Number>> {
  inline size_t operator()(const PhQ::Angle<Number>& angle) const {
    return hash<Number>()(angle.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGLE_HPP
