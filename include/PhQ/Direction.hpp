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
template <typename Number>
class Acceleration;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Area;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Displacement;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Force;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class HeatFlux;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Length;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Position;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class ScalarAcceleration;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class ScalarForce;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class ScalarHeatFlux;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class ScalarTemperatureGradient;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class ScalarTraction;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Speed;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class TemperatureGradient;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Traction;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class VectorArea;

// Forward declaration for class PhQ::Direction.
template <typename Number>
class Velocity;

/// \brief Three-dimensional Euclidean direction vector. Contains three components in Cartesian
/// coordinates: x, y, and z. Guaranteed to be either a unit vector or the zero vector (0, 0, 0).
/// For a two-dimensional Euclidean direction vector in the XY plane, see PhQ::PlanarDirection.
template <typename Number = double>
class Direction : public DimensionlessVector<Number> {
public:
  /// \brief Default constructor. Initializes a direction to the zero vector.
  constexpr Direction() : DimensionlessVector<Number>(Vector<Number>::Zero()) {}

  /// \brief Constructor. Constructs a direction by normalizing the given x, y, and z Cartesian
  /// components to a unit vector. If x = 0, y = 0, and z = 0, initializes the direction to the zero
  /// vector.
  Direction(const Number x, const Number y, const Number z) : DimensionlessVector<Number>() {
    Set(x, y, z);
  }

  /// \brief Constructor. Constructs a direction by normalizing a given array representing x, y, and
  /// z Cartesian components to a unit vector. If x = 0, y = 0, and z = 0, initializes the direction
  /// to the zero vector.
  explicit Direction(const std::array<Number, 3>& x_y_z) : DimensionlessVector<Number>() {
    Set(x_y_z);
  }

  /// \brief Constructor. Constructs a direction by normalizing the given vector to a unit vector.
  /// If the given vector is the zero vector, initializes the direction to the zero vector.
  explicit Direction(const Vector<Number>& value) : DimensionlessVector<Number>() {
    Set(value);
  }

  /// \brief Constructor. Constructs a direction from a given planar direction in the XY plane. This
  /// direction's z-component is initialized to zero.
  explicit constexpr Direction(const PlanarDirection<Number>& planar_direction)
    : Direction<Number>(Vector<Number>{planar_direction.Value()}) {}

  /// \brief Constructor. Constructs a direction from an acceleration.
  explicit Direction(const Acceleration<Number>& acceleration);

  /// \brief Constructor. Constructs a direction from a displacement.
  explicit Direction(const Displacement<Number>& displacement);

  /// \brief Constructor. Constructs a direction from a force.
  explicit Direction(const Force<Number>& force);

  /// \brief Constructor. Constructs a direction from a heat flux.
  explicit Direction(const HeatFlux<Number>& heat_flux);

  /// \brief Constructor. Constructs a direction from a position.
  explicit Direction(const Position<Number>& position);

  /// \brief Constructor. Constructs a direction from a temperature gradient.
  explicit Direction(const TemperatureGradient<Number>& temperature_gradient);

  /// \brief Constructor. Constructs a direction from a traction.
  explicit Direction(const Traction<Number>& traction);

  /// \brief Constructor. Constructs a direction from a vector area.
  explicit Direction(const VectorArea<Number>& vector_area);

  /// \brief Constructor. Constructs a direction from a velocity.
  explicit Direction(const Velocity<Number>& velocity);

  /// \brief Destructor. Destroys this direction.
  ~Direction() noexcept = default;

  /// \brief Copy constructor. Constructs a direction by copying another one.
  constexpr Direction(const Direction<Number>& other) = default;

  /// \brief Copy constructor. Constructs a direction by copying another one.
  template <typename OtherNumber>
  explicit constexpr Direction(const Direction<OtherNumber>& other)
    : Direction(static_cast<Vector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a direction by moving another one.
  constexpr Direction(Direction<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this direction by copying another one.
  constexpr Direction<Number>& operator=(const Direction<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this direction by copying another one.
  template <typename OtherNumber>
  constexpr Direction<Number>& operator=(const Direction<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns the value of this direction by moving another one.
  constexpr Direction<Number>& operator=(Direction<Number>&& other) noexcept = default;

  /// \brief Statically creates a direction whose value is the zero vector.
  static constexpr Direction<Number> Zero() {
    return Direction<Number>{};
  }

  /// \brief Returns the x Cartesian component of this direction.
  [[nodiscard]] constexpr Number x() const noexcept {
    return this->value.x();
  }

  /// \brief Returns the y Cartesian component of this direction.
  [[nodiscard]] constexpr Number y() const noexcept {
    return this->value.y();
  }

  /// \brief Returns the z Cartesian component of this direction.
  [[nodiscard]] constexpr Number z() const noexcept {
    return this->value.z();
  }

  /// \brief Sets the value of this direction by normalizing the given x, y, and z Cartesian
  /// components to a unit vector. If x = 0, y = 0, and z = 0, sets the direction to the zero
  /// vector.
  constexpr void Set(const Number x, const Number y, const Number z) {
    const Number magnitude_squared{x * x + y * y + z * z};
    if (magnitude_squared > static_cast<Number>(0)) {
      const Number magnitude{std::sqrt(magnitude_squared)};
      this->value = Vector{x / magnitude, y / magnitude, z / magnitude};
    } else {
      this->value = Vector<>::Zero();
    }
  }

  /// \brief Sets the value of this direction by normalizing the given x, y, and z Cartesian
  /// components to a unit vector. If x = 0, y = 0, and z = 0, sets the direction to the zero
  /// vector.
  constexpr void Set(const std::array<Number, 3>& x_y_z) {
    const Number magnitude_squared{x_y_z[0] * x_y_z[0] + x_y_z[1] * x_y_z[1] + x_y_z[2] * x_y_z[2]};
    if (magnitude_squared > static_cast<Number>(0)) {
      const Number magnitude{std::sqrt(magnitude_squared)};
      this->value = Vector{x_y_z[0] / magnitude, x_y_z[1] / magnitude, x_y_z[2] / magnitude};
    } else {
      this->value = Vector<>::Zero();
    }
  }

  /// \brief Sets the value of this direction by normalizing the given vector to a unit vector. If
  /// the given vector is a zero vector, sets the direction to the zero vector.
  constexpr void Set(const Vector<Number>& value) {
    Set(value.x_y_z());
  }

  /// \brief Returns the square of the magnitude of this direction. This is guaranteed to be exactly
  /// 1 if the direction is not the zero vector, or 0 if the direction is the zero vector.
  [[nodiscard]] constexpr Number MagnitudeSquared() const noexcept {
    return this->value.MagnitudeSquared();
  }

  /// \brief Returns the magnitude of this direction. This is guaranteed to be exactly 1 if the
  /// direction is not the zero vector, or 0 if the direction is the zero vector.
  [[nodiscard]] Number Magnitude() const noexcept {
    return this->value.Magnitude();
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// direction with the given vector.
  [[nodiscard]] constexpr Number Dot(const Vector<Number>& vector) const noexcept {
    return this->value.Dot(vector);
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// direction with the given other direction.
  [[nodiscard]] constexpr Number Dot(const Direction<Number>& direction) const noexcept {
    return this->value.Dot(direction.value);
  }

  /// \brief Returns the cross product of this direction with the given vector.
  [[nodiscard]] constexpr Vector<Number> Cross(const Vector<Number>& vector) const {
    return this->value.Cross(vector);
  }

  /// \brief Returns the cross product of this direction with the given other direction.
  [[nodiscard]] Direction<Number> Cross(const Direction<Number>& direction) const {
    return Direction<Number>{this->value.Cross(direction.value)};
  }

  /// \brief Returns the dyadic product of this direction with the given vector.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const Vector<Number>& vector) const {
    return this->value.Dyadic(vector);
  }

  /// \brief Returns the dyadic product of this direction with the given other direction.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const Direction<Number>& direction) const {
    return this->value.Dyadic(direction.value);
  }

  /// \brief Returns the angle between this direction and the given vector.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Vector<Number>& vector) const {
    return PhQ::Angle<Number>{*this, vector};
  }

  /// \brief Returns the angle between this direction and the given other direction.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Direction<Number>& direction) const {
    return PhQ::Angle<Number>{*this, direction};
  }

  constexpr Acceleration<Number> operator*(
      const ScalarAcceleration<Number>& scalar_acceleration) const;

  constexpr VectorArea<Number> operator*(const Area<Number>& area) const;

  constexpr Position<Number> operator*(const Length<Number>& length) const;

  constexpr Force<Number> operator*(const ScalarForce<Number>& scalar_force) const;

  constexpr HeatFlux<Number> operator*(const ScalarHeatFlux<Number>& scalar_heat_flux) const;

  constexpr TemperatureGradient<Number> operator*(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const;

  constexpr Traction<Number> operator*(const ScalarTraction<Number>& scalar_traction) const;

  constexpr Velocity<Number> operator*(const Speed<Number>& speed) const;
};

template <typename Number>
inline constexpr bool operator==(
    const Direction<Number>& left, const Direction<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Direction<Number>& left, const Direction<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Direction<Number>& left, const Direction<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Direction<Number>& left, const Direction<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Direction<Number>& left, const Direction<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Direction<Number>& left, const Direction<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const PhQ::Direction<Number>& direction) {
  stream << direction.Print();
  return stream;
}

template <typename Number>
inline constexpr Vector<Number>::Vector(
    const Number magnitude, const PhQ::Direction<Number>& direction)
  : x_y_z_(std::array<Number, 3>{(direction.Value() * magnitude).x_y_z_}) {}

template <typename Number>
inline PhQ::Direction<Number> Vector<Number>::Direction() const {
  return PhQ::Direction<Number>{*this};
}

template <typename Number>
inline constexpr Number Vector<Number>::Dot(
    const PhQ::Direction<Number>& direction) const noexcept {
  return Dot(direction.Value());
}

template <typename Number>
inline constexpr Vector<Number> Vector<Number>::Cross(
    const PhQ::Direction<Number>& direction) const {
  return Cross(direction.Value());
}

template <typename Number>
inline constexpr Dyad<Number> Vector<Number>::Dyadic(
    const PhQ::Direction<Number>& direction) const {
  return Dyadic(direction.Value());
}

template <typename Number>
inline constexpr Vector<Number> operator*(
    const SymmetricDyad<Number>& symmetric_dyad, const Direction<Number>& direction) {
  return symmetric_dyad * direction.Value();
}

template <typename Number>
inline constexpr Vector<Number> operator*(
    const Dyad<Number>& dyad, const Direction<Number>& direction) {
  return dyad * direction.Value();
}

template <typename Number>
inline Angle<Number> Vector<Number>::Angle(const PhQ::Direction<Number>& direction) const {
  return PhQ::Angle<Number>{*this, direction};
}

template <typename Number>
inline Angle<Number>::Angle(const Vector<Number>& vector, const Direction<Number>& direction)
  : Angle(std::acos(vector.Dot(direction) / vector.Magnitude())) {}

template <typename Number>
inline Angle<Number>::Angle(const Direction<Number>& direction, const Vector<Number>& vector)
  : Angle(std::acos(direction.Dot(vector) / vector.Magnitude())) {}

template <typename Number>
inline Angle<Number>::Angle(
    const Direction<Number>& direction1, const Direction<Number>& direction2)
  : Angle(std::acos(direction1.Dot(direction2))) {}

template <typename Number>
inline constexpr PlanarDirection<Number>::PlanarDirection(const Direction<Number>& direction)
  : PlanarDirection(PlanarVector<Number>{direction.Value()}) {}

template <typename Number>
Direction<Number> PlanarDirection<Number>::Cross(
    const PlanarDirection<Number>& planar_direction) const {
  return Direction<Number>{this->value.Cross(planar_direction.value)};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Direction<Number>> {
  inline size_t operator()(const PhQ::Direction<Number>& direction) const {
    return hash<PhQ::Vector<Number>>()(direction.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIRECTION_HPP
