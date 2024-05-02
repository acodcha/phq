// Copyright 2020-2024 Alexandre Coderre-Chabot
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

// Forward declarations for class Angle.
class Acceleration;
class AngularSpeed;
class Direction;
class Displacement;
class Time;
class Force;
class Frequency;
class HeatFlux;
class Position;
class TemperatureGradient;
class Traction;
class VectorArea;
class Velocity;

// Planar angle.
class Angle : public DimensionalScalar<Unit::Angle> {
public:
  // Default constructor. Constructs an angle with an uninitialized value.
  Angle() = default;

  // Constructor. Constructs an angle with a given value expressed in a given angle unit.
  Angle(const double value, const Unit::Angle unit) : DimensionalScalar<Unit::Angle>(value, unit) {}

  // Constructor. Constructs an angle by computing the angle between two given vector values.
  Angle(const Vector<double>& vector1, const Vector<double>& vector2)
    : Angle(std::acos(vector1.Dot(vector2) / (vector1.Magnitude() * vector2.Magnitude()))) {}

  // Constructor. Constructs an angle by computing the angle between a given vector and direction.
  Angle(const Vector<double>& vector, const Direction& direction);

  // Constructor. Constructs an angle by computing the angle between a given direction and vector.
  Angle(const Direction& direction, const Vector<double>& vector);

  // Constructor. Constructs an angle by computing the angle between two given directions.
  Angle(const Direction& direction1, const Direction& direction2);

  // Constructor. Constructs an angle from a given angular speed and time using the definition of
  // angular speed.
  constexpr Angle(const AngularSpeed& angular_speed, const Time& time);

  // Constructor. Constructs an angle from a given angular speed and frequency using the definition
  // of angular speed.
  constexpr Angle(const AngularSpeed& angular_speed, const Frequency& frequency);

  // Constructor. Constructs an angle by computing the angle between two given acceleration vectors.
  Angle(const Acceleration& acceleration1, const Acceleration& acceleration2);

  // Constructor. Constructs an angle by computing the angle between two given vector areas.
  Angle(const VectorArea& vector_area_1, const VectorArea& vector_area_2);

  // Constructor. Constructs an angle by computing the angle between two given displacements.
  Angle(const Displacement& displacement1, const Displacement& displacement2);

  // Constructor. Constructs an angle by computing the angle between two given forces.
  Angle(const Force& force1, const Force& force2);

  // Constructor. Constructs an angle by computing the angle between two given heat fluxes.
  Angle(const HeatFlux& heat_flux_1, const HeatFlux& heat_flux_2);

  // Constructor. Constructs an angle by computing the angle between two given positions.
  Angle(const Position& position1, const Position& position2);

  // Constructor. Constructs an angle by computing the angle between two given temperature
  // gradients.
  Angle(const TemperatureGradient& temperature_gradient_1,
        const TemperatureGradient& temperature_gradient_2);

  // Constructor. Constructs an angle by computing the angle between two given tractions.
  Angle(const Traction& traction1, const Traction& traction2);

  // Constructor. Constructs an angle by computing the angle between two given velocities.
  Angle(const Velocity& velocity1, const Velocity& velocity2);

  // Destructor. Destroys this angle.
  ~Angle() noexcept = default;

  // Copy constructor. Constructs an angle by copying another one.
  constexpr Angle(const Angle& other) = default;

  // Move constructor. Constructs an angle by moving another one.
  constexpr Angle(Angle&& other) noexcept = default;

  // Copy assignment operator. Assigns this angle by copying another one.
  constexpr Angle& operator=(const Angle& other) = default;

  // Move assignment operator. Assigns this angle by moving another one.
  constexpr Angle& operator=(Angle&& other) noexcept = default;

  // Statically creates an angle of zero.
  static constexpr Angle Zero() {
    return Angle{0.0};
  }

  // Statically creates an angle with a given value expressed in a given angle unit.
  template <Unit::Angle Unit>
  static constexpr Angle Create(const double value) {
    return Angle{StaticConvertCopy<Unit::Angle, Unit, Standard<Unit::Angle>>(value)};
  }

  constexpr Angle operator+(const Angle& other) const {
    return Angle{value + other.value};
  }

  constexpr Angle operator-(const Angle& other) const {
    return Angle{value - other.value};
  }

  constexpr Angle operator*(const double number) const {
    return Angle{value * number};
  }

  constexpr AngularSpeed operator*(const Frequency& frequency) const;

  constexpr Angle operator/(const double number) const {
    return Angle{value / number};
  }

  constexpr AngularSpeed operator/(const Time& time) const;

  constexpr Time operator/(const AngularSpeed& angular_speed) const;

  constexpr double operator/(const Angle& angle) const noexcept {
    return value / angle.value;
  }

  constexpr void operator+=(const Angle& angle) noexcept {
    value += angle.value;
  }

  constexpr void operator-=(const Angle& angle) noexcept {
    value -= angle.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an angle with a given value expressed in the standard angle unit.
  explicit constexpr Angle(const double value) : DimensionalScalar<Unit::Angle>(value) {}
};

inline constexpr bool operator==(const Angle& left, const Angle& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Angle& left, const Angle& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Angle& left, const Angle& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Angle& left, const Angle& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Angle& left, const Angle& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Angle& left, const Angle& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Angle& angle) {
  stream << angle.Print();
  return stream;
}

inline constexpr Angle operator*(const double number, const Angle& angle) {
  return angle * number;
}

template <typename Number>
inline PhQ::Angle Vector<Number>::Angle(const Vector<Number>& vector) const {
  return PhQ::Angle{*this, vector};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Angle> {
  inline size_t operator()(const PhQ::Angle& angle) const {
    return hash<double>()(angle.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGLE_HPP
