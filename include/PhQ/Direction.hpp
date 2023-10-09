// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIRECTION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIRECTION_HPP

#include "Angle.hpp"
#include "DimensionlessVectorQuantity.hpp"
#include "Value/Dyad.hpp"

namespace PhQ {

// Forward declarations for class Direction.
class Acceleration;
class AccelerationMagnitude;
class Area;
class AreaVector;
class Displacement;
class Force;
class ForceMagnitude;
class HeatFlux;
class HeatFluxMagnitude;
class Length;
class Position;
class Speed;
class StaticPressure;
class TemperatureGradient;
class TemperatureGradientMagnitude;
class Traction;
class Velocity;

// Direction. This is guaranteed to be either a unit vector or the zero vector
// [0, 0, 0]. Use the Valid() method to check whether the direction is a unit
// vector or the zero vector.
class Direction : public DimensionlessVectorQuantity {
public:
  // Default constructor. Initializes the direction to the zero vector.
  constexpr Direction() : DimensionlessVectorQuantity(Value::Vector::Zero()) {}

  // Constructor. Constructs a direction by normalizing the given [x, y, z]
  // coordinates to a unit vector. If x = 0, y = 0, and z = 0, initializes the
  // direction to the zero vector.
  Direction(const double x, const double y, const double z)
    : DimensionlessVectorQuantity() {
    SetValue(x, y, z);
  }

  // Constructor. Constructs a direction by normalizing the given [x, y, z]
  // coordinates to a unit vector. If x = 0, y = 0, and z = 0, initializes the
  // direction to the zero vector.
  explicit Direction(const std::array<double, 3>& x_y_z)
    : DimensionlessVectorQuantity() {
    SetValue(x_y_z);
  }

  // Constructor. Constructs a direction by normalizing the given x-y-z vector
  // to a unit vector. If the given vector is a zero vector, initializes the
  // direction to the zero vector.
  explicit Direction(const Value::Vector& value)
    : DimensionlessVectorQuantity() {
    SetValue(value);
  }

  // Constructor. Constructs a direction from an acceleration.
  explicit Direction(const Acceleration& acceleration);

  // Constructor. Constructs a direction from a vector area.
  explicit Direction(const AreaVector& area_vector);

  // Constructor. Constructs a direction from a displacement.
  explicit Direction(const Displacement& displacement);

  // Constructor. Constructs a direction from a force.
  explicit Direction(const Force& force);

  // Constructor. Constructs a direction from a heat flux.
  explicit Direction(const HeatFlux& heat_flux);

  // Constructor. Constructs a direction from a position.
  explicit Direction(const Position& position);

  // Constructor. Constructs a direction from a temperature gradient.
  explicit Direction(const TemperatureGradient& temperature_gradient);

  // Constructor. Constructs a direction from a traction.
  explicit Direction(const Traction& traction);

  // Constructor. Constructs a direction from a velocity.
  explicit Direction(const Velocity& velocity);

  // Destructor. Destroys this direction.
  ~Direction() noexcept = default;

  // Copy constructor. Constructs a direction by copying another one.
  constexpr Direction(const Direction& other) = default;

  // Move constructor. Constructs a direction by moving another one.
  constexpr Direction(Direction&& other) noexcept = default;

  // Copy assignment operator. Assigns the value of this direction by copying
  // from another one.
  constexpr Direction& operator=(const Direction& other) {
    value_ = other.value_;
    return *this;
  }

  // Move assignment operator. Assigns the value of this direction by moving
  // another one.
  constexpr Direction& operator=(Direction&& other) noexcept {
    value_ = std::move(other.value_);
    return *this;
  }

  // Statically creates a direction with a value of zero.
  static constexpr Direction Zero() {
    return Direction{};
  }

  // Sets the value of this direction by normalizing the given x, y, and z
  // coordinates to a unit vector. If x = 0, y = 0, and z = 0, sets the
  // direction to the zero vector.
  constexpr void SetValue(const double x, const double y, const double z) {
    const double magnitude_squared{x * x + y * y + z * z};
    if (magnitude_squared > 0.0) {
      const double magnitude{std::sqrt(magnitude_squared)};
      value_ = Value::Vector{x / magnitude, y / magnitude, z / magnitude};
    } else {
      value_ = Value::Vector::Zero();
    }
  }

  // Sets the value of this direction by normalizing the given x, y, and z
  // coordinates to a unit vector. If x = 0, y = 0, and z = 0, sets the
  // direction to the zero vector.
  constexpr void SetValue(const std::array<double, 3>& x_y_z) {
    const double magnitude_squared{
        x_y_z[0] * x_y_z[0] + x_y_z[1] * x_y_z[1] + x_y_z[2] * x_y_z[2]};
    if (magnitude_squared > 0.0) {
      const double magnitude{std::sqrt(magnitude_squared)};
      value_ = Value::Vector{
          x_y_z[0] / magnitude, x_y_z[1] / magnitude, x_y_z[2] / magnitude};
    } else {
      value_ = Value::Vector::Zero();
    }
  }

  // Sets the value of this direction by normalizing the given x-y-z vector to a
  // unit vector. If the given vector is a zero vector, sets the direction to
  // the zero vector.
  constexpr void SetValue(const Value::Vector& value) {
    SetValue(value.x_y_z());
  }

  // Returns true if the direction is a unit vector, or false if it is the zero
  // vector.
  constexpr bool Valid() const noexcept {
    return value_.x() != 0.0 || value_.y() != 0.0 || value_.z() != 0.0;
  }

  // Returns the square of the magnitude of the direction. This is guaranteed to
  // be exactly 1 if the direction is valid, or 0 if the direction is the zero
  // vector.
  constexpr double MagnitudeSquared() const noexcept {
    return value_.MagnitudeSquared();
  }

  // Returns the magnitude of the direction. This is guaranteed to be exactly 1
  // if the direction is valid, or 0 if the direction is the zero vector.
  double Magnitude() const noexcept {
    return value_.Magnitude();
  }

  // Returns the dot product (also known as the scalar product or the inner
  // product) of the direction with the given vector.
  constexpr double Dot(const Value::Vector& vector) const noexcept {
    return value_.Dot(vector);
  }

  // Returns the dot product (also known as the scalar product or the inner
  // product) of the direction with the given other direction.
  constexpr double Dot(const Direction& direction) const noexcept {
    return value_.Dot(direction.value_);
  }

  // Returns the cross product of the direction with the given vector.
  constexpr Value::Vector Cross(const Value::Vector& vector) const {
    return value_.Cross(vector);
  }

  // Returns the cross product of the direction with the given other direction.
  Direction Cross(const Direction& direction) const {
    return Direction{value_.Cross(direction.value_)};
  }

  // Returns the dyadic product of the direction with the given vector.
  constexpr Value::Dyad Dyadic(const Value::Vector& vector) const {
    return value_.Dyadic(vector);
  }

  // Returns the dyadic product of the direction with the given other direction.
  constexpr Value::Dyad Dyadic(const Direction& direction) const {
    return value_.Dyadic(direction.value_);
  }

  // Returns the angle between the direction and the given vector.
  PhQ::Angle Angle(const Value::Vector& vector) const {
    return PhQ::Angle{*this, vector};
  }

  // Returns the angle between the direction and the given other direction.
  PhQ::Angle Angle(const Direction& direction) const {
    return PhQ::Angle{*this, direction};
  }

  constexpr Acceleration operator*(
      const AccelerationMagnitude& acceleration_magnitude) const;

  constexpr AreaVector operator*(const Area& area) const;

  constexpr Position operator*(const Length& length) const;

  constexpr Force operator*(const ForceMagnitude& force_magnitude) const;

  constexpr HeatFlux operator*(
      const HeatFluxMagnitude& heat_flux_magnitude) const;

  constexpr TemperatureGradient operator*(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude) const;

  constexpr Traction operator*(const StaticPressure& static_pressure) const;

  constexpr Velocity operator*(const Speed& speed) const;
};

inline constexpr bool operator==(
    const Direction& left, const Direction& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Direction& left, const Direction& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Direction& left, const Direction& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Direction& left, const Direction& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Direction& left, const Direction& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Direction& left, const Direction& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Direction& direction) {
  stream << direction.Print();
  return stream;
}

// Constructs a vector from a magnitude and a direction.
inline constexpr Value::Vector::Vector(
    const double magnitude, const PhQ::Direction& direction)
  : x_y_z_(std::array<double, 3>{(direction.Value() * magnitude).x_y_z_}) {}

// Returns the direction of the vector.
inline PhQ::Direction Value::Vector::Direction() const {
  return PhQ::Direction{*this};
}

// Returns the dot product (also known as the scalar product or the inner
// product) of the vector with the given direction.
inline constexpr double Value::Vector::Dot(
    const PhQ::Direction& direction) const noexcept {
  return Dot(direction.Value());
}

// Returns the cross product of the vector with the given direction.
inline constexpr Value::Vector Value::Vector::Cross(
    const PhQ::Direction& direction) const {
  return Cross(direction.Value());
}

// Returns the dyadic product of the vector with the given direction.
inline constexpr Value::Dyad Value::Vector::Dyadic(
    const PhQ::Direction& direction) const {
  return Dyadic(direction.Value());
}

inline constexpr Value::Vector operator*(
    const Value::SymmetricDyad& symdyad, const Direction& direction) {
  return symdyad * direction.Value();
}

inline constexpr Value::Vector operator*(
    const Value::Dyad& dyad, const Direction& direction) {
  return dyad * direction.Value();
}

// Returns the angle between the vector and the given direction.
inline Angle Value::Vector::Angle(const PhQ::Direction& direction) const {
  return PhQ::Angle{*this, direction};
}

// Constructs an angle formed from the angle between a vector and a direction.
inline Angle::Angle(const Value::Vector& vector, const Direction& direction)
  : DimensionalScalarQuantity<Unit::Angle>(
      std::acos(vector.Dot(direction) / vector.Magnitude())) {}

// Constructs an angle formed from the angle between a direction and a vector.
inline Angle::Angle(const Direction& direction, const Value::Vector& vector)
  : DimensionalScalarQuantity<Unit::Angle>(
      std::acos(direction.Dot(vector) / vector.Magnitude())) {}

// Constructs an angle formed from the angle between two directions.
inline Angle::Angle(const Direction& direction1, const Direction& direction2)
  : DimensionalScalarQuantity<Unit::Angle>(
      std::acos(direction1.Dot(direction2))) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Direction> {
  inline size_t operator()(const PhQ::Direction& direction) const {
    return hash<PhQ::Value::Vector>()(direction.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIRECTION_HPP
