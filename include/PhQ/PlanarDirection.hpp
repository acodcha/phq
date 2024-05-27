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
template <typename Number>
class Area;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class Length;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarAcceleration;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarDisplacement;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarForce;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarHeatFlux;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarPosition;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarTemperatureGradient;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarTraction;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarVectorArea;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class PlanarVelocity;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class ScalarAcceleration;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class ScalarForce;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class ScalarHeatFlux;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class ScalarTemperatureGradient;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class ScalarTraction;

// Forward declaration for class PhQ::PlanarDirection.
template <typename Number>
class Speed;

/// \brief two-dimensional Euclidean direction vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Guaranteed to be either a unit vector or the zero vector (0, 0).
/// For a three-dimensional Euclidean direction vector, see PhQ::Direction.
template <typename Number = double>
class PlanarDirection : public DimensionlessPlanarVector<Number> {
public:
  /// \brief Default constructor. Initializes a planar direction to the zero planar vector.
  constexpr PlanarDirection() : DimensionlessPlanarVector<Number>(PlanarVector<Number>::Zero()) {}

  /// \brief Constructor. Constructs a planar direction by normalizing the given x and y Cartesian
  /// components to a unit planar vector. If x = 0 and y = 0, initializes the planar direction to
  /// the zero planar vector.
  PlanarDirection(const Number x, const Number y) : DimensionlessPlanarVector<Number>() {
    Set(x, y);
  }

  /// \brief Constructor. Constructs a planar direction by normalizing a given array representing x
  /// and y Cartesian components to a unit planar vector. If x = 0 and y = 0, initializes the planar
  /// direction to the zero planar vector.
  explicit PlanarDirection(const std::array<Number, 2>& x_y) : DimensionlessPlanarVector<Number>() {
    Set(x_y);
  }

  /// \brief Constructor. Constructs a planar direction by normalizing the given planar vector to a
  /// unit planar vector. If the given planar vector is the zero planar vector, initializes the
  /// planar direction to the zero planar vector.
  explicit PlanarDirection(const PlanarVector<Number>& value)
    : DimensionlessPlanarVector<Number>() {
    Set(value);
  }

  /// \brief Constructor. Constructs a planar direction from a given direction by projecting the
  /// direction onto the XY plane.
  explicit constexpr PlanarDirection(const Direction<Number>& direction);

  /// \brief Constructor. Constructs a planar direction from a planar acceleration.
  explicit PlanarDirection(const PlanarAcceleration<Number>& planar_acceleration);

  /// \brief Constructor. Constructs a planar direction from a planar displacement.
  explicit PlanarDirection(const PlanarDisplacement<Number>& planar_displacement);

  /// \brief Constructor. Constructs a planar direction from a planar force.
  explicit PlanarDirection(const PlanarForce<Number>& planar_force);

  /// \brief Constructor. Constructs a planar direction from a planar heat flux.
  explicit PlanarDirection(const PlanarHeatFlux<Number>& planar_heat_flux);

  /// \brief Constructor. Constructs a planar direction from a planar position.
  explicit PlanarDirection(const PlanarPosition<Number>& planar_position);

  /// \brief Constructor. Constructs a planar direction from a planar temperature gradient.
  explicit PlanarDirection(const PlanarTemperatureGradient<Number>& planar_temperature_gradient);

  /// \brief Constructor. Constructs a planar direction from a planar traction.
  explicit PlanarDirection(const PlanarTraction<Number>& planar_traction);

  /// \brief Constructor. Constructs a planar direction from a planar vector area.
  explicit PlanarDirection(const PlanarVectorArea<Number>& planar_vector_area);

  /// \brief Constructor. Constructs a planar direction from a planar velocity.
  explicit PlanarDirection(const PlanarVelocity<Number>& planar_velocity);

  /// \brief Destructor. Destroys this planar direction.
  ~PlanarDirection() noexcept = default;

  /// \brief Copy constructor. Constructs a planar direction by copying another one.
  constexpr PlanarDirection(const PlanarDirection<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar direction by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarDirection(const PlanarDirection<OtherNumber>& other)
    : PlanarDirection(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar direction by moving another one.
  constexpr PlanarDirection(PlanarDirection<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar direction by copying another one.
  constexpr PlanarDirection<Number>& operator=(const PlanarDirection<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar direction by copying another one.
  template <typename OtherNumber>
  constexpr PlanarDirection<Number>& operator=(const PlanarDirection<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns the value of this planar direction by moving another
  /// one.
  constexpr PlanarDirection<Number>& operator=(PlanarDirection<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar direction whose value is the zero vector.
  static constexpr PlanarDirection<Number> Zero() {
    return PlanarDirection<Number>{};
  }

  /// \brief Returns the x Cartesian component of this planar direction.
  [[nodiscard]] constexpr Number x() const noexcept {
    return this->value.x();
  }

  /// \brief Returns the y Cartesian component of this planar direction.
  [[nodiscard]] constexpr Number y() const noexcept {
    return this->value.y();
  }

  /// \brief Sets the value of this planar direction by normalizing the given x and y Cartesian
  /// components to a unit planar vector. If x = 0 and y = 0, sets the planar direction to the zero
  /// planar vector.
  constexpr void Set(const Number x, const Number y) {
    const Number magnitude_squared{x * x + y * y};
    if (magnitude_squared > static_cast<Number>(0)) {
      const Number magnitude{std::sqrt(magnitude_squared)};
      this->value = PlanarVector{x / magnitude, y / magnitude};
    } else {
      this->value = PlanarVector<>::Zero();
    }
  }

  /// \brief Sets the value of this planar direction by normalizing the given x and y Cartesian
  /// components to a unit planar vector. If x = 0 and y = 0, sets the planar direction to the zero
  /// planar vector.
  constexpr void Set(const std::array<Number, 2>& x_y) {
    const Number magnitude_squared{x_y[0] * x_y[0] + x_y[1] * x_y[1]};
    if (magnitude_squared > static_cast<Number>(0)) {
      const Number magnitude{std::sqrt(magnitude_squared)};
      this->value = PlanarVector{x_y[0] / magnitude, x_y[1] / magnitude};
    } else {
      this->value = PlanarVector<>::Zero();
    }
  }

  /// \brief Sets the value of this planar direction by normalizing the given planar vector to a
  /// unit planar vector. If the given planar vector is the zero planar vector, sets the planar
  /// direction to the zero planar vector.
  constexpr void Set(const PlanarVector<Number>& value) {
    Set(value.x_y());
  }

  /// \brief Returns the square of the magnitude of this planar direction. This is guaranteed to be
  /// exactly 1 if the planar direction is not the zero planar vector, or 0 if the planar direction
  /// is the zero planar vector.
  [[nodiscard]] constexpr Number MagnitudeSquared() const noexcept {
    return this->value.MagnitudeSquared();
  }

  /// \brief Returns the magnitude of this planar direction. This is guaranteed to be exactly 1 if
  /// the planar direction is not the zero planar vector, or 0 if the planar direction is the zero
  /// planar vector.
  [[nodiscard]] Number Magnitude() const noexcept {
    return this->value.Magnitude();
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// planar direction with the given planar vector.
  [[nodiscard]] constexpr Number Dot(const PlanarVector<Number>& planar_vector) const noexcept {
    return this->value.Dot(planar_vector);
  }

  /// \brief Returns the dot product (also known as the scalar product or the inner product) of this
  /// planar direction with the given other planar direction.
  [[nodiscard]] constexpr Number Dot(
      const PlanarDirection<Number>& planar_direction) const noexcept {
    return this->value.Dot(planar_direction.value);
  }

  /// \brief Returns the cross product of this planar direction with the given planar vector.
  [[nodiscard]] constexpr Vector<Number> Cross(const PlanarVector<Number>& planar_vector) const {
    return this->value.Cross(planar_vector);
  }

  /// \brief Returns the cross product of this planar direction with the given other planar
  /// direction.
  [[nodiscard]] Direction<Number> Cross(const PlanarDirection<Number>& planar_direction) const;

  /// \brief Returns the dyadic product of this planar direction with the given planar vector.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const PlanarVector<Number>& planar_vector) const {
    return this->value.Dyadic(planar_vector);
  }

  /// \brief Returns the dyadic product of this planar direction with the given other planar
  /// direction.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(
      const PlanarDirection<Number>& planar_direction) const {
    return this->value.Dyadic(planar_direction.value);
  }

  /// \brief Returns the angle between this planar direction and the given planar vector.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarVector<Number>& planar_vector) const {
    return PhQ::Angle<Number>{*this, planar_vector};
  }

  /// \brief Returns the angle between this planar direction and the given other planar direction.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarDirection<Number>& planar_direction) const {
    return PhQ::Angle<Number>{*this, planar_direction};
  }

  constexpr PlanarAcceleration<Number> operator*(
      const ScalarAcceleration<Number>& scalar_acceleration) const;

  constexpr PlanarVectorArea<Number> operator*(const Area<Number>& area) const;

  constexpr PlanarPosition<Number> operator*(const Length<Number>& length) const;

  constexpr PlanarForce<Number> operator*(const ScalarForce<Number>& scalar_force) const;

  constexpr PlanarHeatFlux<Number> operator*(const ScalarHeatFlux<Number>& scalar_heat_flux) const;

  constexpr PlanarTemperatureGradient<Number> operator*(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const;

  constexpr PlanarTraction<Number> operator*(const ScalarTraction<Number>& scalar_traction) const;

  constexpr PlanarVelocity<Number> operator*(const Speed<Number>& speed) const;
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarDirection<Number>& left, const PlanarDirection<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarDirection<Number>& left, const PlanarDirection<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarDirection<Number>& left, const PlanarDirection<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarDirection<Number>& left, const PlanarDirection<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarDirection<Number>& left, const PlanarDirection<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarDirection<Number>& left, const PlanarDirection<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PhQ::PlanarDirection<Number>& planar_direction) {
  stream << planar_direction.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarVector<Number>::PlanarVector(
    const Number magnitude, const PhQ::PlanarDirection<Number>& planar_direction)
  : x_y_(std::array<Number, 2>{(planar_direction.Value() * magnitude).x_y_}) {}

template <typename Number>
inline PhQ::PlanarDirection<Number> PlanarVector<Number>::PlanarDirection() const {
  return PhQ::PlanarDirection<Number>{*this};
}

template <typename Number>
inline constexpr Number PlanarVector<Number>::Dot(
    const PhQ::PlanarDirection<Number>& planar_direction) const noexcept {
  return Dot(planar_direction.Value());
}

template <typename Number>
inline constexpr Vector<Number> PlanarVector<Number>::Cross(
    const PhQ::PlanarDirection<Number>& planar_direction) const {
  return Cross(planar_direction.Value());
}

template <typename Number>
inline constexpr Dyad<Number> PlanarVector<Number>::Dyadic(
    const PhQ::PlanarDirection<Number>& planar_direction) const {
  return Dyadic(planar_direction.Value());
}

template <typename Number>
inline constexpr Vector<Number> operator*(
    const SymmetricDyad<Number>& symmetric_dyad, const PlanarDirection<Number>& planar_direction) {
  return symmetric_dyad * planar_direction.Value();
}

template <typename Number>
inline constexpr Vector<Number> operator*(
    const Dyad<Number>& dyad, const PlanarDirection<Number>& planar_direction) {
  return dyad * planar_direction.Value();
}

template <typename Number>
inline Angle<Number> PlanarVector<Number>::Angle(
    const PhQ::PlanarDirection<Number>& planar_direction) const {
  return PhQ::Angle<Number>{*this, planar_direction};
}

template <typename Number>
inline Angle<Number>::Angle(
    const PlanarVector<Number>& planar_vector, const PlanarDirection<Number>& planar_direction)
  : Angle(std::acos(planar_vector.Dot(planar_direction) / planar_vector.Magnitude())) {}

template <typename Number>
inline Angle<Number>::Angle(
    const PlanarDirection<Number>& planar_direction, const PlanarVector<Number>& planar_vector)
  : Angle(std::acos(planar_direction.Dot(planar_vector) / planar_vector.Magnitude())) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarDirection<Number>& planar_direction_1,
                            const PlanarDirection<Number>& planar_direction_2)
  : Angle(std::acos(planar_direction_1.Dot(planar_direction_2))) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarDirection<Number>> {
  inline size_t operator()(const PhQ::PlanarDirection<Number>& planar_direction) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_direction.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_DIRECTION_HPP
