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

#ifndef PHQ_ANGLE_HPP
#define PHQ_ANGLE_HPP

#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "PlanarVector.hpp"
#include "Unit/Angle.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Acceleration;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class AngularSpeed;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Displacement;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Force;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class HeatFlux;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarAcceleration;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarDirection;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarDisplacement;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarForce;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarHeatFlux;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarPosition;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarTemperatureGradient;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarTraction;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarVectorArea;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class PlanarVelocity;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Position;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class TemperatureGradient;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Traction;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class VectorArea;

// Forward declaration for class PhQ::Angle.
template <typename NumericType>
class Velocity;

/// \brief Plane angle between two lines or dihedral angle between two planes.
template <typename NumericType = double>
class Angle : public DimensionalScalar<Unit::Angle, NumericType> {
public:
  /// \brief Default constructor. Constructs an angle with an uninitialized value.
  Angle() = default;

  /// \brief Constructor. Constructs an angle with a given value expressed in a given angle unit.
  Angle(const NumericType value, const Unit::Angle unit)
    : DimensionalScalar<Unit::Angle, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// vectors.
  Angle(const PlanarVector<NumericType>& planar_vector_1,
        const PlanarVector<NumericType>& planar_vector_2)
    : Angle(std::acos(planar_vector_1.Dot(planar_vector_2)
                      / (planar_vector_1.Magnitude() * planar_vector_2.Magnitude()))) {}

  /// \brief Constructor. Constructs an angle by computing the angle between two given vectors.
  Angle(const Vector<NumericType>& vector1, const Vector<NumericType>& vector2)
    : Angle(std::acos(vector1.Dot(vector2) / (vector1.Magnitude() * vector2.Magnitude()))) {}

  /// \brief Constructor. Constructs an angle by computing the angle between a given planar vector
  /// and planar direction.
  Angle(const PlanarVector<NumericType>& planar_vector,
        const PlanarDirection<NumericType>& planar_direction);

  /// \brief Constructor. Constructs an angle by computing the angle between a given vector and
  /// direction.
  Angle(const Vector<NumericType>& vector, const Direction<NumericType>& direction);

  /// \brief Constructor. Constructs an angle by computing the angle between a given planar
  /// direction and planar vector.
  Angle(const PlanarDirection<NumericType>& planar_direction,
        const PlanarVector<NumericType>& planar_vector);

  /// \brief Constructor. Constructs an angle by computing the angle between a given direction and
  /// vector.
  Angle(const Direction<NumericType>& direction, const Vector<NumericType>& vector);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// directions.
  Angle(const PlanarDirection<NumericType>& planar_direction_1,
        const PlanarDirection<NumericType>& planar_direction_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given directions.
  Angle(const Direction<NumericType>& direction1, const Direction<NumericType>& direction2);

  /// \brief Constructor. Constructs an angle from a given angular speed and time using the
  /// definition of angular speed.
  constexpr Angle(const AngularSpeed<NumericType>& angular_speed, const Time<NumericType>& time);

  /// \brief Constructor. Constructs an angle from a given angular speed and frequency using the
  /// definition of angular speed.
  constexpr Angle(
      const AngularSpeed<NumericType>& angular_speed, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs an angle by computing the angle between two given acceleration
  /// vectors.
  Angle(const Acceleration<NumericType>& acceleration1,
        const Acceleration<NumericType>& acceleration2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given vector areas.
  Angle(const VectorArea<NumericType>& vector_area_1, const VectorArea<NumericType>& vector_area_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given
  /// displacements.
  Angle(const Displacement<NumericType>& displacement1,
        const Displacement<NumericType>& displacement2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given forces.
  Angle(const Force<NumericType>& force1, const Force<NumericType>& force2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given heat fluxes.
  Angle(const HeatFlux<NumericType>& heat_flux_1, const HeatFlux<NumericType>& heat_flux_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// acceleration vectors.
  Angle(const PlanarAcceleration<NumericType>& planar_acceleration_1,
        const PlanarAcceleration<NumericType>& planar_acceleration_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar vector
  /// areas.
  Angle(const PlanarVectorArea<NumericType>& planar_vector_area_1,
        const PlanarVectorArea<NumericType>& planar_vector_area_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// displacements.
  Angle(const PlanarDisplacement<NumericType>& planar_displacement_1,
        const PlanarDisplacement<NumericType>& planar_displacement_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// forces.
  Angle(const PlanarForce<NumericType>& planar_force_1,
        const PlanarForce<NumericType>& planar_force_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar heat
  /// fluxes.
  Angle(const PlanarHeatFlux<NumericType>& planar_heat_flux_1,
        const PlanarHeatFlux<NumericType>& planar_heat_flux_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// positions.
  Angle(const PlanarPosition<NumericType>& planar_position_1,
        const PlanarPosition<NumericType>& planar_position_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// temperature gradients.
  Angle(const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient_1,
        const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// tractions.
  Angle(const PlanarTraction<NumericType>& planar_traction_1,
        const PlanarTraction<NumericType>& planar_traction_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given planar
  /// velocities.
  Angle(const PlanarVelocity<NumericType>& planar_velocity_1,
        const PlanarVelocity<NumericType>& planar_velocity_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given positions.
  Angle(const Position<NumericType>& position1, const Position<NumericType>& position2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given temperature
  /// gradients.
  Angle(const TemperatureGradient<NumericType>& temperature_gradient_1,
        const TemperatureGradient<NumericType>& temperature_gradient_2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given tractions.
  Angle(const Traction<NumericType>& traction1, const Traction<NumericType>& traction2);

  /// \brief Constructor. Constructs an angle by computing the angle between two given velocities.
  Angle(const Velocity<NumericType>& velocity1, const Velocity<NumericType>& velocity2);

  /// \brief Destructor. Destroys this angle.
  ~Angle() noexcept = default;

  /// \brief Copy constructor. Constructs an angle by copying another one.
  constexpr Angle(const Angle<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an angle by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Angle(const Angle<OtherNumericType>& other)
    : Angle(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an angle by moving another one.
  constexpr Angle(Angle<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this angle by copying another one.
  constexpr Angle<NumericType>& operator=(const Angle<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this angle by copying another one.
  template <typename OtherNumericType>
  constexpr Angle<NumericType>& operator=(const Angle<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this angle by moving another one.
  constexpr Angle<NumericType>& operator=(Angle<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an angle of zero.
  static constexpr Angle<NumericType> Zero() {
    return Angle<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an angle with a given value expressed in a given angle unit.
  template <Unit::Angle Unit>
  static constexpr Angle<NumericType> Create(const NumericType value) {
    return Angle<NumericType>{ConvertStatically<Unit::Angle, Unit, Standard<Unit::Angle>>(value)};
  }

  constexpr Angle<NumericType> operator+(const Angle<NumericType>& other) const {
    return Angle<NumericType>{this->value + other.value};
  }

  constexpr Angle<NumericType> operator-(const Angle<NumericType>& other) const {
    return Angle<NumericType>{this->value - other.value};
  }

  constexpr Angle<NumericType> operator*(const NumericType number) const {
    return Angle<NumericType>{this->value * number};
  }

  constexpr AngularSpeed<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Angle<NumericType> operator/(const NumericType number) const {
    return Angle<NumericType>{this->value / number};
  }

  constexpr AngularSpeed<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const AngularSpeed<NumericType>& angular_speed) const;

  constexpr NumericType operator/(const Angle<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const Angle<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const Angle<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an angle with a given value expressed in the standard angle
  /// unit.
  explicit constexpr Angle(const NumericType value)
    : DimensionalScalar<Unit::Angle, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Angle<NumericType>& left, const Angle<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Angle<NumericType>& left, const Angle<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Angle<NumericType>& left, const Angle<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Angle<NumericType>& left, const Angle<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Angle<NumericType>& left, const Angle<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Angle<NumericType>& left, const Angle<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Angle<NumericType>& angle) {
  stream << angle.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Angle<NumericType> operator*(
    const NumericType number, const Angle<NumericType>& angle) {
  return angle * number;
}

template <typename NumericType>
inline PhQ::Angle<NumericType> PlanarVector<NumericType>::Angle(
    const PlanarVector<NumericType>& planar_vector) const {
  return PhQ::Angle{*this, planar_vector};
}

template <typename NumericType>
inline PhQ::Angle<NumericType> Vector<NumericType>::Angle(const Vector<NumericType>& vector) const {
  return PhQ::Angle{*this, vector};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Angle<NumericType>> {
  inline size_t operator()(const PhQ::Angle<NumericType>& angle) const {
    return hash<NumericType>()(angle.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGLE_HPP
