// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base/String.hpp"
#include "Base/Type.hpp"

namespace PhQ {

// Forward declarations.
namespace Value {
class Vector;
class SymmetricDyadic;
class Dyadic;
} // namespace Value
class Acceleration;
class AccelerationMagnitude;
class Area;
class AreaVector;
class Angle;
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

class Direction {

public:

  constexpr Direction() noexcept : x_(), y_(), z_() {}

  constexpr Direction(double x, double y, double z) : x_(), y_(), z_() {
    const double magnitude{std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2))};
    if (magnitude > 0.0) {
      x_ = x / magnitude;
      y_ = y / magnitude;
      z_ = z / magnitude;
    } else {
      throw std::runtime_error{"Attempting to create a direction from (0, 0, 0)."};
    }
  }

  constexpr Direction(const Value::Vector& vector);

  constexpr Direction(const Acceleration& acceleration);

  constexpr Direction(const AreaVector& area_vector);

  constexpr Direction(const Displacement& displacement);

  constexpr Direction(const Force& force);

  constexpr Direction(const HeatFlux& heat_flux);

  constexpr Direction(const Position& position);

  constexpr Direction(const TemperatureGradient& temperature_gradient);

  constexpr Direction(const Traction& traction);

  constexpr Direction(const Velocity& velocity);

  constexpr double x() const noexcept {
    return x_;
  }

  constexpr double y() const noexcept {
    return y_;
  }

  constexpr double z() const noexcept {
    return z_;
  }

  constexpr double magnitude() const noexcept {
    return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2) + std::pow(z_, 2));
  }

  constexpr double dot(const Direction& direction) const noexcept {
    return x_ * direction.x_ + y_ * direction.y_ + z_ * direction.z_;
  }

  constexpr double dot(const Value::Vector& vector) const noexcept;

  constexpr Direction cross(const Direction& direction) const noexcept {
    return {
      y_ * direction.z_ - z_ * direction.y_,
      z_ * direction.x_ - x_ * direction.z_,
      x_ * direction.y_ - y_ * direction.x_};
  }

  constexpr Value::Vector cross(const Value::Vector& vector) const noexcept;

  constexpr Value::Dyadic dyadic(const Direction& direction) const noexcept;

  constexpr Value::Dyadic dyadic(const Value::Vector& vector) const noexcept;

  constexpr Angle angle(const Direction& direction) const noexcept;

  constexpr Angle angle(const Value::Vector& vector) const noexcept;

  std::string print() const noexcept {
    return
      "(" + PhQ::number_to_string(x_) + ", " +
      PhQ::number_to_string(y_) + ", " +
      PhQ::number_to_string(z_) + ")";
  }

  std::string yaml() const noexcept {
    return
      "{x:" + PhQ::number_to_string(x_) +
      " , y:" + PhQ::number_to_string(y_) +
      " , z:" + PhQ::number_to_string(z_) + "}";
  }

  std::string json() const noexcept {
    return
      "{\"x\":" + PhQ::number_to_string(x_) +
      " , \"y\":" + PhQ::number_to_string(y_) +
      " , \"z\":" + PhQ::number_to_string(z_) + "}";
  }

  std::string xml() const noexcept {
    return
      "<x>" + PhQ::number_to_string(x_) +
      "</x><y>" + PhQ::number_to_string(y_) +
      "</y><z>" + PhQ::number_to_string(z_) + "</z>";
  }

  constexpr bool operator==(const Direction& direction) const noexcept {
    return x_ == direction.x_ && y_ == direction.y_ && z_ == direction.z_;
  }

  constexpr bool operator!=(const Direction& direction) const noexcept {
    return x_ != direction.x_ || y_ != direction.y_ || z_ != direction.z_;
  }

  constexpr Acceleration operator*(const AccelerationMagnitude& acceleration_magnitude) const noexcept;

  constexpr AreaVector operator*(const Area& area) const noexcept;

  constexpr Displacement operator*(const Length& length) const noexcept;

  constexpr Force operator*(const ForceMagnitude& force_magnitude) const noexcept;

  constexpr HeatFlux operator*(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept;

  constexpr Traction operator*(const StaticPressure& static_pressure) const noexcept;

  constexpr Velocity operator*(const Speed& speed) const noexcept;

  constexpr TemperatureGradient operator*(const TemperatureGradientMagnitude& temperature_gradient_magnitude) const noexcept;

private:

  double x_;

  double y_;

  double z_;

};

template <> constexpr bool sort(const Direction& direction_1, const Direction& direction_2) noexcept {
  if (direction_1.x() == direction_2.x()) {
    if (direction_1.y() == direction_2.y()) {
      return direction_1.z() < direction_2.z();
    } else {
      return direction_1.y() < direction_2.y();
    }
  } else {
    return direction_1.x() < direction_2.x();
  }
}

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Direction& direction) noexcept {
  output_stream << direction.print();
  return output_stream;
}
