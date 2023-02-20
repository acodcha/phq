// Copyright 2020 Alexandre Coderre-Chabot
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

#include <array>

#include "Base/String.hpp"

namespace PhQ {

namespace Value {

class Vector;
class SymmetricDyad;
class Dyad;

}  // namespace Value

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
  constexpr Direction() noexcept : x_y_z_({1.0, 0.0, 0.0}) {}

  Direction(const double x, const double y, const double z) {
    const double magnitude{std::sqrt(x * x + y * y + z * z)};
    if (magnitude > 0.0) {
      x_y_z_[0] = x / magnitude;
      x_y_z_[1] = y / magnitude;
      x_y_z_[2] = z / magnitude;
    } else {
      throw std::runtime_error{
          "Attempting to create a direction from (0, 0, 0)."};
    }
  }

  Direction(const std::array<double, 3>& x_y_z) {
    const double magnitude{std::sqrt(x_y_z[0] * x_y_z[0] + x_y_z[1] * x_y_z[1] +
                                     x_y_z[2] * x_y_z[2])};
    if (magnitude > 0.0) {
      x_y_z_[0] = x_y_z[0] / magnitude;
      x_y_z_[1] = x_y_z[1] / magnitude;
      x_y_z_[2] = x_y_z[2] / magnitude;
    } else {
      throw std::runtime_error{
          "Attempting to create a direction from (0, 0, 0)."};
    }
  }

  Direction(const Value::Vector& vector);

  Direction(const Acceleration& acceleration);

  Direction(const AreaVector& area_vector);

  Direction(const Displacement& displacement);

  Direction(const Force& force);

  Direction(const HeatFlux& heat_flux);

  Direction(const Position& position);

  Direction(const TemperatureGradient& temperature_gradient);

  Direction(const Traction& traction);

  Direction(const Velocity& velocity);

  inline constexpr double x() const noexcept { return x_y_z_[0]; }

  inline constexpr double y() const noexcept { return x_y_z_[1]; }

  inline constexpr double z() const noexcept { return x_y_z_[2]; }

  inline constexpr const std::array<double, 3>& Value() const noexcept {
    return x_y_z_;
  }

  inline constexpr double Dot(const Direction& direction) const noexcept {
    return x_y_z_[0] * direction.x_y_z_[0] + x_y_z_[1] * direction.x_y_z_[1] +
           x_y_z_[2] * direction.x_y_z_[2];
  }

  constexpr double Dot(const Value::Vector& vector) const noexcept;

  inline Direction Cross(const Direction& direction) const noexcept {
    return {x_y_z_[1] * direction.x_y_z_[2] - x_y_z_[2] * direction.x_y_z_[1],
            x_y_z_[2] * direction.x_y_z_[0] - x_y_z_[0] * direction.x_y_z_[2],
            x_y_z_[0] * direction.x_y_z_[1] - x_y_z_[1] * direction.x_y_z_[0]};
  }

  constexpr Value::Vector Cross(const Value::Vector& vector) const noexcept;

  constexpr Value::Dyad Dyadic(const Direction& direction) const noexcept;

  constexpr Value::Dyad Dyadic(const Value::Vector& vector) const noexcept;

  constexpr PhQ::Angle Angle(const Direction& direction) const noexcept;

  constexpr PhQ::Angle Angle(const Value::Vector& vector) const noexcept;

  inline std::string Print() const noexcept {
    return "(" + PhQ::Print(x_y_z_[0]) + ", " + PhQ::Print(x_y_z_[1]) + ", " +
           PhQ::Print(x_y_z_[2]) + ")";
  }

  inline std::string Json() const noexcept {
    return "{\"x\":" + PhQ::Print(x_y_z_[0]) +
           ",\"y\":" + PhQ::Print(x_y_z_[1]) +
           ",\"z\":" + PhQ::Print(x_y_z_[2]) + "}";
  }

  inline std::string Xml() const noexcept {
    return "<x>" + PhQ::Print(x_y_z_[0]) + "</x><y>" + PhQ::Print(x_y_z_[1]) +
           "</y><z>" + PhQ::Print(x_y_z_[2]) + "</z>";
  }

  inline std::string Yaml() const noexcept {
    return "{x:" + PhQ::Print(x_y_z_[0]) + ",y:" + PhQ::Print(x_y_z_[1]) +
           ",z:" + PhQ::Print(x_y_z_[2]) + "}";
  }

  constexpr Acceleration operator*(
      const AccelerationMagnitude& acceleration_magnitude) const noexcept;

  constexpr AreaVector operator*(const Area& area) const noexcept;

  constexpr Displacement operator*(const Length& length) const noexcept;

  constexpr Force operator*(
      const ForceMagnitude& force_magnitude) const noexcept;

  constexpr HeatFlux operator*(
      const HeatFluxMagnitude& heat_flux_magnitude) const noexcept;

  constexpr Traction operator*(
      const StaticPressure& static_pressure) const noexcept;

  constexpr Velocity operator*(const Speed& speed) const noexcept;

  constexpr TemperatureGradient operator*(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude)
      const noexcept;

private:
  std::array<double, 3> x_y_z_;
};

inline constexpr bool operator==(const Direction& left,
                                 const Direction& right) noexcept {
  return left.x() == right.x() && left.y() == right.y() &&
         left.z() == right.z();
}

inline constexpr bool operator!=(const Direction& left,
                                 const Direction& right) noexcept {
  return left.x() != right.x() || left.y() != right.y() ||
         left.z() != right.z();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Direction& direction) noexcept {
  stream << direction.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Direction> {
  size_t operator()(const PhQ::Direction& direction) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(direction.x());
    result = 31 * result + hash<double>()(direction.y());
    result = 31 * result + hash<double>()(direction.z());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIRECTION_HPP
