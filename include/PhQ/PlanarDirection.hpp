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

#ifndef PHQ_PLANAR_DIRECTION_HPP
#define PHQ_PLANAR_DIRECTION_HPP

#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionlessPlanarVector.hpp"
#include "Dyad.hpp"
#include "PlanarVector.hpp"
#include "SymmetricDyad.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class Area;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class Length;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarAcceleration;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarDisplacement;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarForce;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarHeatFlux;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarPosition;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarTemperatureGradient;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarTraction;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class PlanarVelocity;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class ScalarAcceleration;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class ScalarForce;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class ScalarHeatFlux;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class ScalarTemperatureGradient;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class ScalarTraction;

// Forward declaration for class PhQ::PlanarDirection.
template <typename NumericType>
class Speed;

/// \brief two-dimensional Euclidean direction vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Guaranteed to be either a unit vector or the zero vector (0, 0).
/// For a three-dimensional Euclidean direction vector, see PhQ::Direction.
template <typename NumericType = double>
class PlanarDirection : public DimensionlessPlanarVector<NumericType> {
public:
  /// \brief Default constructor. Initializes a planar direction to the zero planar vector.
  constexpr PlanarDirection()
    : DimensionlessPlanarVector<NumericType>(PlanarVector<NumericType>::Zero()) {}

  /// \brief Constructor. Constructs a planar direction by normalizing the given x and y Cartesian
  /// components to a unit planar vector. If x = 0 and y = 0, initializes the planar direction to
  /// the zero planar vector.
  PlanarDirection(const NumericType x, const NumericType y)
    : DimensionlessPlanarVector<NumericType>() {
    Set(x, y);
  }

  /// \brief Constructor. Constructs a planar direction by normalizing a given array representing x
  /// and y Cartesian components to a unit planar vector. If x = 0 and y = 0, initializes the planar
  /// direction to the zero planar vector.
  explicit PlanarDirection(const std::array<NumericType, 2>& x_y)
    : DimensionlessPlanarVector<NumericType>() {
    Set(x_y);
  }

  /// \brief Constructor. Constructs a planar direction by normalizing the given planar vector to a
  /// unit planar vector. If the given planar vector is the zero planar vector, initializes the
  /// planar direction to the zero planar vector.
  explicit PlanarDirection(const PlanarVector<NumericType>& value)
    : DimensionlessPlanarVector<NumericType>() {
    Set(value);
  }

  /// \brief Constructor. Constructs a planar direction from a given direction by projecting the
  /// direction onto the XY plane.
  explicit constexpr PlanarDirection(const Direction<NumericType>& direction);

  /// \brief Constructor. Constructs a planar direction from a planar acceleration.
  explicit PlanarDirection(const PlanarAcceleration<NumericType>& planar_acceleration);

  /// \brief Constructor. Constructs a planar direction from a planar displacement.
  explicit PlanarDirection(const PlanarDisplacement<NumericType>& planar_displacement);

  /// \brief Constructor. Constructs a planar direction from a planar force.
  explicit PlanarDirection(const PlanarForce<NumericType>& planar_force);

  /// \brief Constructor. Constructs a planar direction from a planar heat flux.
  explicit PlanarDirection(const PlanarHeatFlux<NumericType>& planar_heat_flux);

  /// \brief Constructor. Constructs a planar direction from a planar position.
  explicit PlanarDirection(const PlanarPosition<NumericType>& planar_position);

  /// \brief Constructor. Constructs a planar direction from a planar temperature gradient.
  explicit PlanarDirection(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient);

  /// \brief Constructor. Constructs a planar direction from a planar traction.
  explicit PlanarDirection(const PlanarTraction<NumericType>& planar_traction);

  /// \brief Constructor. Constructs a planar direction from a planar velocity.
  explicit PlanarDirection(const PlanarVelocity<NumericType>& planar_velocity);

  /// \brief Destructor. Destroys this planar direction.
  ~PlanarDirection() noexcept = default;

  /// \brief Copy constructor. Constructs a planar direction by copying another one.
  constexpr PlanarDirection(const PlanarDirection<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar direction by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarDirection(const PlanarDirection<OtherNumericType>& other)
    : PlanarDirection(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar direction by moving another one.
  constexpr PlanarDirection(PlanarDirection<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar direction by copying another one.
  constexpr PlanarDirection<NumericType>& operator=(
      const PlanarDirection<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar direction by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarDirection<NumericType>& operator=(
      const PlanarDirection<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns the value of this planar direction by moving another
  /// one.
  constexpr PlanarDirection<NumericType>& operator=(
      PlanarDirection<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar direction whose value is the zero vector.
  [[nodiscard]] static constexpr PlanarDirection<NumericType> Zero() {
    return PlanarDirection<NumericType>{};
  }

  /// \brief Returns the x Cartesian component of this planar direction.
  [[nodiscard]] constexpr NumericType x() const noexcept {
    return this->value.x();
  }

  /// \brief Returns the y Cartesian component of this planar direction.
  [[nodiscard]] constexpr NumericType y() const noexcept {
    return this->value.y();
  }

  /// \brief Sets the value of this planar direction by normalizing the given x and y Cartesian
  /// components to a unit planar vector. If x = 0 and y = 0, sets the planar direction to the zero
  /// planar vector.
  constexpr void Set(const NumericType x, const NumericType y) {
    const NumericType magnitude_squared{x * x + y * y};
    if (magnitude_squared > static_cast<NumericType>(0)) {
      const NumericType magnitude{std::sqrt(magnitude_squared)};
      this->value = PlanarVector{x / magnitude, y / magnitude};
    } else {
      this->value = PlanarVector<>::Zero();
    }
  }

  /// \brief Sets the value of this planar direction by normalizing the given x and y Cartesian
  /// components to a unit planar vector. If x = 0 and y = 0, sets the planar direction to the zero
  /// planar vector.
  constexpr void Set(const std::array<NumericType, 2>& x_y) {
    const NumericType magnitude_squared{x_y[0] * x_y[0] + x_y[1] * x_y[1]};
    if (magnitude_squared > static_cast<NumericType>(0)) {
      const NumericType magnitude{std::sqrt(magnitude_squared)};
      this->value = PlanarVector{x_y[0] / magnitude, x_y[1] / magnitude};
    } else {
      this->value = PlanarVector<>::Zero();
    }
  }

  /// \brief Sets the value of this planar direction by normalizing the given planar vector to a
  /// unit planar vector. If the given planar vector is the zero planar vector, sets the planar
  /// direction to the zero planar vector.
  constexpr void Set(const PlanarVector<NumericType>& value) {
    Set(value.x_y());
  }

  /// \brief Returns the square of the magnitude of this planar direction. This is guaranteed to be
  /// exactly 1 if the planar direction is not the zero planar vector, or 0 if the planar direction
  /// is the zero planar vector.
  [[nodiscard]] constexpr NumericType MagnitudeSquared() const noexcept {
    return this->value.MagnitudeSquared();
  }

  /// \brief Returns the magnitude of this planar direction. This is guaranteed to be exactly 1 if
  /// the planar direction is not the zero planar vector, or 0 if the planar direction is the zero
  /// planar vector.
  [[nodiscard]] NumericType Magnitude() const noexcept {
    return this->value.Magnitude();
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// planar direction with the given planar vector.
  [[nodiscard]] constexpr NumericType Dot(
      const PlanarVector<NumericType>& planar_vector) const noexcept {
    return this->value.Dot(planar_vector);
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// planar direction with the given other planar direction.
  [[nodiscard]] constexpr NumericType Dot(
      const PlanarDirection<NumericType>& planar_direction) const noexcept {
    return this->value.Dot(planar_direction.value);
  }

  /// \brief Returns the cross product of this planar direction with the given planar vector.
  [[nodiscard]] constexpr Vector<NumericType> Cross(
      const PlanarVector<NumericType>& planar_vector) const {
    return this->value.Cross(planar_vector);
  }

  /// \brief Returns the cross product of this planar direction with the given other planar
  /// direction.
  [[nodiscard]] Direction<NumericType> Cross(
      const PlanarDirection<NumericType>& planar_direction) const;

  /// \brief Returns the dyadic product of this planar direction with the given planar vector.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(
      const PlanarVector<NumericType>& planar_vector) const {
    return this->value.Dyadic(planar_vector);
  }

  /// \brief Returns the dyadic product of this planar direction with the given other planar
  /// direction.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(
      const PlanarDirection<NumericType>& planar_direction) const {
    return this->value.Dyadic(planar_direction.value);
  }

  /// \brief Returns the angle between this planar direction and the given planar vector.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarVector<NumericType>& planar_vector) const {
    return PhQ::Angle<NumericType>{*this, planar_vector};
  }

  /// \brief Returns the angle between this planar direction and the given other planar direction.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarDirection<NumericType>& planar_direction) const {
    return PhQ::Angle<NumericType>{*this, planar_direction};
  }

  constexpr PlanarAcceleration<NumericType> operator*(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const;

  constexpr PlanarPosition<NumericType> operator*(const Length<NumericType>& length) const;

  constexpr PlanarForce<NumericType> operator*(const ScalarForce<NumericType>& scalar_force) const;

  constexpr PlanarHeatFlux<NumericType> operator*(
      const ScalarHeatFlux<NumericType>& scalar_heat_flux) const;

  constexpr PlanarTemperatureGradient<NumericType> operator*(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const;

  constexpr PlanarTraction<NumericType> operator*(
      const ScalarTraction<NumericType>& scalar_traction) const;

  constexpr PlanarVelocity<NumericType> operator*(const Speed<NumericType>& speed) const;
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarDirection<NumericType>& left, const PlanarDirection<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarDirection<NumericType>& left, const PlanarDirection<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarDirection<NumericType>& left, const PlanarDirection<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarDirection<NumericType>& left, const PlanarDirection<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarDirection<NumericType>& left, const PlanarDirection<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarDirection<NumericType>& left, const PlanarDirection<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PhQ::PlanarDirection<NumericType>& planar_direction) {
  stream << planar_direction.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarVector<NumericType>::PlanarVector(
    const NumericType magnitude, const PhQ::PlanarDirection<NumericType>& planar_direction)
  : x_y_(std::array<NumericType, 2>{(planar_direction.Value() * magnitude).x_y_}) {}

template <typename NumericType>
inline PhQ::PlanarDirection<NumericType> PlanarVector<NumericType>::PlanarDirection() const {
  return PhQ::PlanarDirection<NumericType>{*this};
}

template <typename NumericType>
inline constexpr NumericType PlanarVector<NumericType>::Dot(
    const PhQ::PlanarDirection<NumericType>& planar_direction) const noexcept {
  return Dot(planar_direction.Value());
}

template <typename NumericType>
inline constexpr Vector<NumericType> PlanarVector<NumericType>::Cross(
    const PhQ::PlanarDirection<NumericType>& planar_direction) const {
  return Cross(planar_direction.Value());
}

template <typename NumericType>
inline constexpr Dyad<NumericType> PlanarVector<NumericType>::Dyadic(
    const PhQ::PlanarDirection<NumericType>& planar_direction) const {
  return Dyadic(planar_direction.Value());
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const SymmetricDyad<NumericType>& symmetric_dyad,
    const PlanarDirection<NumericType>& planar_direction) {
  return symmetric_dyad * planar_direction.Value();
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const Dyad<NumericType>& dyad, const PlanarDirection<NumericType>& planar_direction) {
  return dyad * planar_direction.Value();
}

template <typename NumericType>
inline Angle<NumericType> PlanarVector<NumericType>::Angle(
    const PhQ::PlanarDirection<NumericType>& planar_direction) const {
  return PhQ::Angle<NumericType>{*this, planar_direction};
}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarVector<NumericType>& planar_vector,
                                 const PlanarDirection<NumericType>& planar_direction)
  : Angle(std::acos(planar_vector.Dot(planar_direction) / planar_vector.Magnitude())) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarDirection<NumericType>& planar_direction,
                                 const PlanarVector<NumericType>& planar_vector)
  : Angle(std::acos(planar_direction.Dot(planar_vector) / planar_vector.Magnitude())) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarDirection<NumericType>& planar_direction_1,
                                 const PlanarDirection<NumericType>& planar_direction_2)
  : Angle(std::acos(planar_direction_1.Dot(planar_direction_2))) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarDirection<NumericType>> {
  inline size_t operator()(const PhQ::PlanarDirection<NumericType>& planar_direction) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_direction.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_DIRECTION_HPP
