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

  constexpr Angle(const Direction& direction_1, const Direction& direction_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(direction_1.angle(direction_2)) {}

  constexpr Angle(const Direction& direction, const Value::Vector& vector) noexcept : DimensionalScalarQuantity<Unit::Angle>(direction.angle(vector)) {}

  constexpr Angle(const Value::Vector& vector, const Direction& direction) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector.angle(direction)) {}

  constexpr Angle(const Value::Vector& vector_1, const Value::Vector& vector_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector_1.angle(vector_2)) {}

  constexpr Angle(const Position& position_1, const Position& position_2) noexcept;

  constexpr Angle(const Displacement& displacement_1, const Displacement& displacement_2) noexcept;

  constexpr Angle(const Velocity& velocity_1, const Velocity& velocity_2) noexcept;

  constexpr Angle(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept;

  constexpr Angle(const Force& force_1, const Force& force_2) noexcept;

  constexpr Angle(const Traction& traction_1, const Traction& traction_2) noexcept;

  constexpr Angle(const AreaVector& vector_area_1, const AreaVector& vector_area_2) noexcept;

  constexpr Angle(const TemperatureGradient& temperature_gradient_1, const TemperatureGradient& temperature_gradient_2) noexcept;

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

  AngularSpeed operator/(const Duration& time) const;

protected:

  constexpr Angle(double value) noexcept : DimensionalScalarQuantity<Unit::Angle>(value) {}

  friend class AngularSpeed;
  friend class Duration;
  friend class Frequency;
  friend Angle Direction::angle(const Direction& direction) const noexcept;
  friend Angle Direction::angle(const Value::Vector& vector) const noexcept;
  friend Angle Value::Vector::angle(const Direction& direction) const noexcept;
  friend Angle Value::Vector::angle(const Value::Vector& vector) const noexcept;

};

template <> constexpr bool sort(const Angle& angle_1, const Angle& angle_2) noexcept {
  return angle_1.value() < angle_2.value();
}

constexpr Angle Direction::angle(const Direction& direction) const noexcept {
  return {std::acos(dot(direction))};
}

constexpr Angle Direction::angle(const Value::Vector& vector) const noexcept {
  return {std::acos(dot(vector) / vector.magnitude())};
}

constexpr Angle Value::Vector::angle(const Direction& direction) const noexcept {
  return {std::acos(dot(direction) / magnitude())};
}

constexpr Angle Value::Vector::angle(const Value::Vector& vector) const noexcept {
  return {std::acos(dot(vector) / (magnitude() * vector.magnitude()))};
}

} // namespace PhQ
