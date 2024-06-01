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

#ifndef PHQ_DIRECTION_HPP
#define PHQ_DIRECTION_HPP

#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionlessVector.hpp"
#include "Dyad.hpp"
#include "PlanarDirection.hpp"
#include "SymmetricDyad.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Acceleration;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Area;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Displacement;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Force;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class HeatFlux;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Length;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Position;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class ScalarAcceleration;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class ScalarForce;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class ScalarHeatFlux;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class ScalarTemperatureGradient;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class ScalarTraction;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Speed;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class TemperatureGradient;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Traction;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class VectorArea;

// Forward declaration for class PhQ::Direction.
template <typename NumericType>
class Velocity;

/// \brief Three-dimensional Euclidean direction vector. Contains three components in Cartesian
/// coordinates: x, y, and z. Guaranteed to be either a unit vector or the zero vector (0, 0, 0).
/// For a two-dimensional Euclidean direction vector in the XY plane, see PhQ::PlanarDirection.
template <typename NumericType = double>
class Direction : public DimensionlessVector<NumericType> {
public:
  /// \brief Default constructor. Initializes a direction to the zero vector.
  constexpr Direction() : DimensionlessVector<NumericType>(Vector<NumericType>::Zero()) {}

  /// \brief Constructor. Constructs a direction by normalizing the given x, y, and z Cartesian
  /// components to a unit vector. If x = 0, y = 0, and z = 0, initializes the direction to the zero
  /// vector.
  Direction(const NumericType x, const NumericType y, const NumericType z)
    : DimensionlessVector<NumericType>() {
    Set(x, y, z);
  }

  /// \brief Constructor. Constructs a direction by normalizing a given array representing x, y, and
  /// z Cartesian components to a unit vector. If x = 0, y = 0, and z = 0, initializes the direction
  /// to the zero vector.
  explicit Direction(const std::array<NumericType, 3>& x_y_z) : DimensionlessVector<NumericType>() {
    Set(x_y_z);
  }

  /// \brief Constructor. Constructs a direction by normalizing the given vector to a unit vector.
  /// If the given vector is the zero vector, initializes the direction to the zero vector.
  explicit Direction(const Vector<NumericType>& value) : DimensionlessVector<NumericType>() {
    Set(value);
  }

  /// \brief Constructor. Constructs a direction from a given planar direction in the XY plane. This
  /// direction's z-component is initialized to zero.
  explicit constexpr Direction(const PlanarDirection<NumericType>& planar_direction)
    : Direction<NumericType>(Vector<NumericType>{planar_direction.Value()}) {}

  /// \brief Constructor. Constructs a direction from an acceleration.
  explicit Direction(const Acceleration<NumericType>& acceleration);

  /// \brief Constructor. Constructs a direction from a displacement.
  explicit Direction(const Displacement<NumericType>& displacement);

  /// \brief Constructor. Constructs a direction from a force.
  explicit Direction(const Force<NumericType>& force);

  /// \brief Constructor. Constructs a direction from a heat flux.
  explicit Direction(const HeatFlux<NumericType>& heat_flux);

  /// \brief Constructor. Constructs a direction from a position.
  explicit Direction(const Position<NumericType>& position);

  /// \brief Constructor. Constructs a direction from a temperature gradient.
  explicit Direction(const TemperatureGradient<NumericType>& temperature_gradient);

  /// \brief Constructor. Constructs a direction from a traction.
  explicit Direction(const Traction<NumericType>& traction);

  /// \brief Constructor. Constructs a direction from a vector area.
  explicit Direction(const VectorArea<NumericType>& vector_area);

  /// \brief Constructor. Constructs a direction from a velocity.
  explicit Direction(const Velocity<NumericType>& velocity);

  /// \brief Destructor. Destroys this direction.
  ~Direction() noexcept = default;

  /// \brief Copy constructor. Constructs a direction by copying another one.
  constexpr Direction(const Direction<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a direction by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Direction(const Direction<OtherNumericType>& other)
    : Direction(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a direction by moving another one.
  constexpr Direction(Direction<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this direction by copying another one.
  constexpr Direction<NumericType>& operator=(const Direction<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this direction by copying another one.
  template <typename OtherNumericType>
  constexpr Direction<NumericType>& operator=(const Direction<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns the value of this direction by moving another one.
  constexpr Direction<NumericType>& operator=(Direction<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a direction whose value is the zero vector.
  static constexpr Direction<NumericType> Zero() {
    return Direction<NumericType>{};
  }

  /// \brief Returns the x Cartesian component of this direction.
  [[nodiscard]] constexpr NumericType x() const noexcept {
    return this->value.x();
  }

  /// \brief Returns the y Cartesian component of this direction.
  [[nodiscard]] constexpr NumericType y() const noexcept {
    return this->value.y();
  }

  /// \brief Returns the z Cartesian component of this direction.
  [[nodiscard]] constexpr NumericType z() const noexcept {
    return this->value.z();
  }

  /// \brief Sets the value of this direction by normalizing the given x, y, and z Cartesian
  /// components to a unit vector. If x = 0, y = 0, and z = 0, sets the direction to the zero
  /// vector.
  constexpr void Set(const NumericType x, const NumericType y, const NumericType z) {
    const NumericType magnitude_squared{x * x + y * y + z * z};
    if (magnitude_squared > static_cast<NumericType>(0)) {
      const NumericType magnitude{std::sqrt(magnitude_squared)};
      this->value = Vector{x / magnitude, y / magnitude, z / magnitude};
    } else {
      this->value = Vector<>::Zero();
    }
  }

  /// \brief Sets the value of this direction by normalizing the given x, y, and z Cartesian
  /// components to a unit vector. If x = 0, y = 0, and z = 0, sets the direction to the zero
  /// vector.
  constexpr void Set(const std::array<NumericType, 3>& x_y_z) {
    const NumericType magnitude_squared{
        x_y_z[0] * x_y_z[0] + x_y_z[1] * x_y_z[1] + x_y_z[2] * x_y_z[2]};
    if (magnitude_squared > static_cast<NumericType>(0)) {
      const NumericType magnitude{std::sqrt(magnitude_squared)};
      this->value = Vector{x_y_z[0] / magnitude, x_y_z[1] / magnitude, x_y_z[2] / magnitude};
    } else {
      this->value = Vector<>::Zero();
    }
  }

  /// \brief Sets the value of this direction by normalizing the given vector to a unit vector. If
  /// the given vector is a zero vector, sets the direction to the zero vector.
  constexpr void Set(const Vector<NumericType>& value) {
    Set(value.x_y_z());
  }

  /// \brief Returns the square of the magnitude of this direction. This is guaranteed to be exactly
  /// 1 if the direction is not the zero vector, or 0 if the direction is the zero vector.
  [[nodiscard]] constexpr NumericType MagnitudeSquared() const noexcept {
    return this->value.MagnitudeSquared();
  }

  /// \brief Returns the magnitude of this direction. This is guaranteed to be exactly 1 if the
  /// direction is not the zero vector, or 0 if the direction is the zero vector.
  [[nodiscard]] NumericType Magnitude() const noexcept {
    return this->value.Magnitude();
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// direction with the given vector.
  [[nodiscard]] constexpr NumericType Dot(const Vector<NumericType>& vector) const noexcept {
    return this->value.Dot(vector);
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// direction with the given other direction.
  [[nodiscard]] constexpr NumericType Dot(const Direction<NumericType>& direction) const noexcept {
    return this->value.Dot(direction.value);
  }

  /// \brief Returns the cross product of this direction with the given vector.
  [[nodiscard]] constexpr Vector<NumericType> Cross(const Vector<NumericType>& vector) const {
    return this->value.Cross(vector);
  }

  /// \brief Returns the cross product of this direction with the given other direction.
  [[nodiscard]] Direction<NumericType> Cross(const Direction<NumericType>& direction) const {
    return Direction<NumericType>{this->value.Cross(direction.value)};
  }

  /// \brief Returns the dyadic product of this direction with the given vector.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(const Vector<NumericType>& vector) const {
    return this->value.Dyadic(vector);
  }

  /// \brief Returns the dyadic product of this direction with the given other direction.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(const Direction<NumericType>& direction) const {
    return this->value.Dyadic(direction.value);
  }

  /// \brief Returns the angle between this direction and the given vector.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Vector<NumericType>& vector) const {
    return PhQ::Angle<NumericType>{*this, vector};
  }

  /// \brief Returns the angle between this direction and the given other direction.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Direction<NumericType>& direction) const {
    return PhQ::Angle<NumericType>{*this, direction};
  }

  constexpr Acceleration<NumericType> operator*(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const;

  constexpr VectorArea<NumericType> operator*(const Area<NumericType>& area) const;

  constexpr Position<NumericType> operator*(const Length<NumericType>& length) const;

  constexpr Force<NumericType> operator*(const ScalarForce<NumericType>& scalar_force) const;

  constexpr HeatFlux<NumericType> operator*(
      const ScalarHeatFlux<NumericType>& scalar_heat_flux) const;

  constexpr TemperatureGradient<NumericType> operator*(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const;

  constexpr Traction<NumericType> operator*(
      const ScalarTraction<NumericType>& scalar_traction) const;

  constexpr Velocity<NumericType> operator*(const Speed<NumericType>& speed) const;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Direction<NumericType>& left, const Direction<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Direction<NumericType>& left, const Direction<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Direction<NumericType>& left, const Direction<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Direction<NumericType>& left, const Direction<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Direction<NumericType>& left, const Direction<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Direction<NumericType>& left, const Direction<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PhQ::Direction<NumericType>& direction) {
  stream << direction.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Vector<NumericType>::Vector(
    const NumericType magnitude, const PhQ::Direction<NumericType>& direction)
  : x_y_z_(std::array<NumericType, 3>{(direction.Value() * magnitude).x_y_z_}) {}

template <typename NumericType>
inline PhQ::Direction<NumericType> Vector<NumericType>::Direction() const {
  return PhQ::Direction<NumericType>{*this};
}

template <typename NumericType>
inline constexpr NumericType Vector<NumericType>::Dot(
    const PhQ::Direction<NumericType>& direction) const noexcept {
  return Dot(direction.Value());
}

template <typename NumericType>
inline constexpr Vector<NumericType> Vector<NumericType>::Cross(
    const PhQ::Direction<NumericType>& direction) const {
  return Cross(direction.Value());
}

template <typename NumericType>
inline constexpr Dyad<NumericType> Vector<NumericType>::Dyadic(
    const PhQ::Direction<NumericType>& direction) const {
  return Dyadic(direction.Value());
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const SymmetricDyad<NumericType>& symmetric_dyad, const Direction<NumericType>& direction) {
  return symmetric_dyad * direction.Value();
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const Dyad<NumericType>& dyad, const Direction<NumericType>& direction) {
  return dyad * direction.Value();
}

template <typename NumericType>
inline Angle<NumericType> Vector<NumericType>::Angle(
    const PhQ::Direction<NumericType>& direction) const {
  return PhQ::Angle<NumericType>{*this, direction};
}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Vector<NumericType>& vector, const Direction<NumericType>& direction)
  : Angle(std::acos(vector.Dot(direction) / vector.Magnitude())) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Direction<NumericType>& direction, const Vector<NumericType>& vector)
  : Angle(std::acos(direction.Dot(vector) / vector.Magnitude())) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Direction<NumericType>& direction1, const Direction<NumericType>& direction2)
  : Angle(std::acos(direction1.Dot(direction2))) {}

template <typename NumericType>
inline constexpr PlanarDirection<NumericType>::PlanarDirection(
    const Direction<NumericType>& direction)
  : PlanarDirection(PlanarVector<NumericType>{direction.Value()}) {}

template <typename NumericType>
Direction<NumericType> PlanarDirection<NumericType>::Cross(
    const PlanarDirection<NumericType>& planar_direction) const {
  return Direction<NumericType>{this->value.Cross(planar_direction.value)};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Direction<NumericType>> {
  inline size_t operator()(const PhQ::Direction<NumericType>& direction) const {
    return hash<PhQ::Vector<NumericType>>()(direction.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIRECTION_HPP
