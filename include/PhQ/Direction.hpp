// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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
#include "SymmetricDyad.hpp"
#include "Unit/Angle.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declarations for class Direction.
class Acceleration;
class Area;
class Displacement;
class Force;
class HeatFlux;
class Length;
class Position;
class Speed;
class ScalarAcceleration;
class ScalarForce;
class ScalarHeatFlux;
class ScalarTemperatureGradient;
class StaticPressure;
class TemperatureGradient;
class Traction;
class VectorArea;
class Velocity;

// Direction. This is guaranteed to be either a unit vector or the zero vector [0, 0, 0]. Use the
// Valid() method to check whether the direction is a unit vector or the zero vector.
class Direction : public DimensionlessVector {
public:
  // Default constructor. Initializes the direction to the zero vector.
  constexpr Direction() : DimensionlessVector(Vector::Zero()) {}

  // Constructor. Constructs a direction by normalizing the given x, y, and z Cartesian components
  // to a unit vector. If x = 0, y = 0, and z = 0, initializes the direction to the zero vector.
  Direction(const double x, const double y, const double z) : DimensionlessVector() {
    Set(x, y, z);
  }

  // Constructor. Constructs a direction by normalizing a given array representing x, y, and z
  // Cartesian components to a unit vector. If x = 0, y = 0, and z = 0, initializes the direction to
  // the zero vector.
  explicit Direction(const std::array<double, 3>& x_y_z) : DimensionlessVector() {
    Set(x_y_z);
  }

  // Constructor. Constructs a direction by normalizing the given vector to a unit vector. If the
  // given vector is a zero vector, initializes the direction to the zero vector.
  explicit Direction(const Vector& value) : DimensionlessVector() {
    Set(value);
  }

  // Constructor. Constructs a direction from an acceleration.
  explicit Direction(const Acceleration& acceleration);

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

  // Constructor. Constructs a direction from a vector area.
  explicit Direction(const VectorArea& vector_area);

  // Constructor. Constructs a direction from a velocity.
  explicit Direction(const Velocity& velocity);

  // Destructor. Destroys this direction.
  ~Direction() noexcept = default;

  // Copy constructor. Constructs a direction by copying another one.
  constexpr Direction(const Direction& other) = default;

  // Move constructor. Constructs a direction by moving another one.
  constexpr Direction(Direction&& other) noexcept = default;

  // Copy assignment operator. Assigns the value of this direction by copying from another one.
  constexpr Direction& operator=(const Direction& other) = default;

  // Move assignment operator. Assigns the value of this direction by moving another one.
  constexpr Direction& operator=(Direction&& other) noexcept = default;

  // Statically creates a direction with a value of zero.
  static constexpr Direction Zero() {
    return Direction{};
  }

  // Returns the x Cartesian component of this direction.
  [[nodiscard]] constexpr double x() const noexcept {
    return value_.x();
  }

  // Returns the y Cartesian component of this direction.
  [[nodiscard]] constexpr double y() const noexcept {
    return value_.y();
  }

  // Returns the z Cartesian component of this direction.
  [[nodiscard]] constexpr double z() const noexcept {
    return value_.z();
  }

  // Sets the value of this direction by normalizing the given x, y, and z Cartesian components to a
  // unit vector. If x = 0, y = 0, and z = 0, sets the direction to the zero vector.
  constexpr void Set(const double x, const double y, const double z) {
    const double magnitude_squared{x * x + y * y + z * z};
    if (magnitude_squared > 0.0) {
      const double magnitude{std::sqrt(magnitude_squared)};
      value_ = Vector{x / magnitude, y / magnitude, z / magnitude};
    } else {
      value_ = Vector::Zero();
    }
  }

  // Sets the value of this direction by normalizing the given x, y, and z Cartesian components to a
  // unit vector. If x = 0, y = 0, and z = 0, sets the direction to the zero vector.
  constexpr void Set(const std::array<double, 3>& x_y_z) {
    const double magnitude_squared{x_y_z[0] * x_y_z[0] + x_y_z[1] * x_y_z[1] + x_y_z[2] * x_y_z[2]};
    if (magnitude_squared > 0.0) {
      const double magnitude{std::sqrt(magnitude_squared)};
      value_ = Vector{x_y_z[0] / magnitude, x_y_z[1] / magnitude, x_y_z[2] / magnitude};
    } else {
      value_ = Vector::Zero();
    }
  }

  // Sets the value of this direction by normalizing the given vector to a unit vector. If the given
  // vector is a zero vector, sets the direction to the zero vector.
  constexpr void Set(const Vector& value) {
    Set(value.x_y_z());
  }

  // Returns true if the direction is a unit vector, or false if it is the zero vector.
  [[nodiscard]] constexpr bool Valid() const noexcept {
    return value_.x() != 0.0 || value_.y() != 0.0 || value_.z() != 0.0;
  }

  // Returns the square of the magnitude of the direction. This is guaranteed to be exactly 1 if the
  // direction is valid, or 0 if the direction is the zero vector.
  [[nodiscard]] constexpr double MagnitudeSquared() const noexcept {
    return value_.MagnitudeSquared();
  }

  // Returns the magnitude of the direction. This is guaranteed to be exactly 1 if the direction is
  // valid, or 0 if the direction is the zero vector.
  [[nodiscard]] double Magnitude() const noexcept {
    return value_.Magnitude();
  }

  // Returns the dot product (also known as the scalar product or the inner product) of the
  // direction with the given vector.
  [[nodiscard]] constexpr double Dot(const Vector& vector) const noexcept {
    return value_.Dot(vector);
  }

  // Returns the dot product (also known as the scalar product or the inner product) of the
  // direction with the given other direction.
  [[nodiscard]] constexpr double Dot(const Direction& direction) const noexcept {
    return value_.Dot(direction.value_);
  }

  // Returns the cross product of the direction with the given vector.
  [[nodiscard]] constexpr Vector Cross(const Vector& vector) const {
    return value_.Cross(vector);
  }

  // Returns the cross product of the direction with the given other direction.
  [[nodiscard]] Direction Cross(const Direction& direction) const {
    return Direction{value_.Cross(direction.value_)};
  }

  // Returns the dyadic product of the direction with the given vector.
  [[nodiscard]] constexpr Dyad Dyadic(const Vector& vector) const {
    return value_.Dyadic(vector);
  }

  // Returns the dyadic product of the direction with the given other direction.
  [[nodiscard]] constexpr Dyad Dyadic(const Direction& direction) const {
    return value_.Dyadic(direction.value_);
  }

  // Returns the angle between the direction and the given vector.
  [[nodiscard]] PhQ::Angle Angle(const Vector& vector) const {
    return PhQ::Angle{*this, vector};
  }

  // Returns the angle between the direction and the given other direction.
  [[nodiscard]] PhQ::Angle Angle(const Direction& direction) const {
    return PhQ::Angle{*this, direction};
  }

  constexpr Acceleration operator*(const ScalarAcceleration& scalar_acceleration) const;

  constexpr VectorArea operator*(const Area& area) const;

  constexpr Position operator*(const Length& length) const;

  constexpr Force operator*(const ScalarForce& scalar_force) const;

  constexpr HeatFlux operator*(const ScalarHeatFlux& scalar_heat_flux) const;

  constexpr TemperatureGradient operator*(
      const ScalarTemperatureGradient& scalar_temperature_gradient) const;

  constexpr Traction operator*(const StaticPressure& static_pressure) const;

  constexpr Velocity operator*(const Speed& speed) const;
};

inline constexpr bool operator==(const Direction& left, const Direction& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Direction& left, const Direction& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Direction& left, const Direction& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Direction& left, const Direction& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Direction& left, const Direction& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Direction& left, const Direction& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Direction& direction) {
  stream << direction.Print();
  return stream;
}

inline constexpr Vector::Vector(const double magnitude, const PhQ::Direction& direction)
  : x_y_z_(std::array<double, 3>{(direction.Value() * magnitude).x_y_z_}) {}

inline PhQ::Direction Vector::Direction() const {
  return PhQ::Direction{*this};
}

inline constexpr double Vector::Dot(const PhQ::Direction& direction) const noexcept {
  return Dot(direction.Value());
}

inline constexpr Vector Vector::Cross(const PhQ::Direction& direction) const {
  return Cross(direction.Value());
}

inline constexpr Dyad Vector::Dyadic(const PhQ::Direction& direction) const {
  return Dyadic(direction.Value());
}

inline constexpr Vector operator*(const SymmetricDyad& symdyad, const Direction& direction) {
  return symdyad * direction.Value();
}

inline constexpr Vector operator*(const Dyad& dyad, const Direction& direction) {
  return dyad * direction.Value();
}

inline Angle Vector::Angle(const PhQ::Direction& direction) const {
  return PhQ::Angle{*this, direction};
}

inline Angle::Angle(const Vector& vector, const Direction& direction)
  : Angle(std::acos(vector.Dot(direction) / vector.Magnitude())) {}

inline Angle::Angle(const Direction& direction, const Vector& vector)
  : Angle(std::acos(direction.Dot(vector) / vector.Magnitude())) {}

inline Angle::Angle(const Direction& direction1, const Direction& direction2)
  : Angle(std::acos(direction1.Dot(direction2))) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Direction> {
  inline size_t operator()(const PhQ::Direction& direction) const {
    return hash<PhQ::Vector>()(direction.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIRECTION_HPP
