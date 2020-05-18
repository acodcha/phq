// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Angle.hpp"

namespace PhQ {

// Forward declarations.
class Acceleration;
class AngularSpeed;
class AreaVector;
class Displacement;
class Duration;
class Force;
class Frequency;
class Position;
class TemperatureGradient;
class Traction;
class Velocity;

class Angle : public DimensionalScalarQuantity<Unit::Angle> {

public:

  constexpr Angle() noexcept : DimensionalScalarQuantity<Unit::Angle>() {}

  constexpr Angle(double value, Unit::Angle unit) noexcept : DimensionalScalarQuantity<Unit::Angle>(value, unit) {}

  constexpr Angle(const Direction& direction_1, const Direction& direction_2) noexcept : Angle(std::acos(direction_1.dot(direction_2))) {}

  constexpr Angle(const Direction& direction, const Value::Vector& vector) noexcept : Angle(std::acos(direction.dot(vector) / vector.magnitude())) {}

  constexpr Angle(const Value::Vector& vector, const Direction& direction) noexcept : Angle(std::acos(vector.dot(direction) / vector.magnitude())) {}

  constexpr Angle(const Value::Vector& vector_1, const Value::Vector& vector_2) noexcept : Angle(std::acos(vector_1.dot(vector_2) / (vector_1.magnitude() * vector_2.magnitude()))) {}

  constexpr Angle(const AngularSpeed& angular_speed, const Duration& duration) noexcept;

  constexpr Angle(const AngularSpeed& angular_speed, const Frequency& frequency) noexcept;

  constexpr Angle(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept;

  constexpr Angle(const AreaVector& area_vector_1, const AreaVector& area_vector_2) noexcept;

  constexpr Angle(const Displacement& displacement_1, const Displacement& displacement_2) noexcept;

  constexpr Angle(const Force& force_1, const Force& force_2) noexcept;

  constexpr Angle(const Position& position_1, const Position& position_2) noexcept;

  constexpr Angle(const TemperatureGradient& temperature_gradient_1, const TemperatureGradient& temperature_gradient_2) noexcept;

  constexpr Angle(const Traction& traction_1, const Traction& traction_2) noexcept;

  constexpr Angle(const Velocity& velocity_1, const Velocity& velocity_2) noexcept;

  constexpr bool operator==(const Angle& angle) const noexcept {
    return value_ == angle.value_;
  }

  constexpr bool operator!=(const Angle& angle) const noexcept {
    return value_ != angle.value_;
  }

  constexpr bool operator<(const Angle& angle) const noexcept {
    return value_ < angle.value_;
  }

  constexpr bool operator<=(const Angle& angle) const noexcept {
    return value_ <= angle.value_;
  }

  constexpr bool operator>(const Angle& angle) const noexcept {
    return value_ > angle.value_;
  }

  constexpr bool operator>=(const Angle& angle) const noexcept {
    return value_ >= angle.value_;
  }

  constexpr Angle operator+(const Angle& angle) const noexcept {
    return {value_ + angle.value_};
  }

  constexpr void operator+=(const Angle& angle) noexcept {
    value_ += angle.value_;
  }

  constexpr Angle operator-(const Angle& angle) const noexcept {
    return {value_ - angle.value_};
  }

  constexpr void operator-=(const Angle& angle) noexcept {
    value_ -= angle.value_;
  }

  constexpr AngularSpeed operator*(const Frequency& frequency) const noexcept;

  constexpr AngularSpeed operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const AngularSpeed& angular_speed) const noexcept;

protected:

  constexpr Angle(double value) noexcept : DimensionalScalarQuantity<Unit::Angle>(value) {}

};

template <> constexpr bool sort(const Angle& angle_1, const Angle& angle_2) noexcept {
  return sort(angle_1.value(), angle_2.value());
}

constexpr Angle Direction::angle(const Direction& direction) const noexcept {
  return {*this, direction};
}

constexpr Angle Direction::angle(const Value::Vector& vector) const noexcept {
  return {*this, vector};
}

constexpr Angle Value::Vector::angle(const Direction& direction) const noexcept {
  return {*this, direction};
}

constexpr Angle Value::Vector::angle(const Value::Vector& vector) const noexcept {
  return {*this, vector};
}

} // namespace PhQ
