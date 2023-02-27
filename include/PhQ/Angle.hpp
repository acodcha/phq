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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGLE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGLE_HPP

#include "Direction.hpp"
#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Angle.hpp"

namespace PhQ {

// Forward declarations for class Angle.
class Acceleration;
class AngularSpeed;
class AreaVector;
class Displacement;
class Duration;
class Force;
class Frequency;
class HeatFlux;
class Position;
class TemperatureGradient;
class Traction;
class Velocity;

class Angle : public DimensionalScalarQuantity<Unit::Angle> {
public:
  constexpr Angle() noexcept : DimensionalScalarQuantity<Unit::Angle>() {}

  Angle(const double value, const Unit::Angle unit) noexcept
      : DimensionalScalarQuantity<Unit::Angle>(value, unit) {}

  constexpr Angle(const Direction& direction1,
                  const Direction& direction2) noexcept
      : DimensionalScalarQuantity<Unit::Angle>(
            std::acos(direction1.Dot(direction2))) {}

  Angle(const Direction& direction, const Value::Vector& vector) noexcept
      : DimensionalScalarQuantity<Unit::Angle>(
            std::acos(direction.Dot(vector) / vector.Magnitude())) {}

  Angle(const Value::Vector& vector, const Direction& direction) noexcept
      : DimensionalScalarQuantity<Unit::Angle>(
            std::acos(vector.Dot(direction) / vector.Magnitude())) {}

  Angle(const Value::Vector& vector1, const Value::Vector& vector2) noexcept
      : DimensionalScalarQuantity<Unit::Angle>(
            std::acos(vector1.Dot(vector2) /
                      (vector1.Magnitude() * vector2.Magnitude()))) {}

  constexpr Angle(const AngularSpeed& angular_speed,
                  const Duration& duration) noexcept;

  constexpr Angle(const AngularSpeed& angular_speed,
                  const Frequency& frequency) noexcept;

  constexpr Angle(const Acceleration& acceleration_1,
                  const Acceleration& acceleration_2) noexcept;

  constexpr Angle(const AreaVector& area_vector_1,
                  const AreaVector& area_vector_2) noexcept;

  constexpr Angle(const Displacement& displacement_1,
                  const Displacement& displacement_2) noexcept;

  constexpr Angle(const Force& force_1, const Force& force_2) noexcept;

  constexpr Angle(const HeatFlux& heat_flux_1,
                  const HeatFlux& heat_flux_2) noexcept;

  constexpr Angle(const Position& position_1,
                  const Position& position_2) noexcept;

  constexpr Angle(const TemperatureGradient& temperature_gradient_1,
                  const TemperatureGradient& temperature_gradient_2) noexcept;

  constexpr Angle(const Traction& traction_1,
                  const Traction& traction_2) noexcept;

  constexpr Angle(const Velocity& velocity_1,
                  const Velocity& velocity_2) noexcept;

  inline Angle operator+(const Angle& other) const noexcept {
    return PhQ::Angle{value_ + other.value_};
  }

  inline Angle operator-(const Angle& other) const noexcept {
    return PhQ::Angle{value_ - other.value_};
  }

  inline Angle operator*(const double number) const noexcept {
    return PhQ::Angle{value_ * number};
  }
  inline Angle operator/(const double number) const noexcept {
    return PhQ::Angle{value_ / number};
  }

  inline constexpr void operator+=(const Angle& angle) noexcept {
    value_ += angle.value_;
  }

  inline constexpr void operator-=(const Angle& angle) noexcept {
    value_ -= angle.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

  inline constexpr AngularSpeed operator*(
      const Frequency& frequency) const noexcept;

  inline constexpr AngularSpeed operator/(
      const Duration& duration) const noexcept;

  inline constexpr Duration operator/(
      const AngularSpeed& angular_speed) const noexcept;

private:
  explicit constexpr Angle(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Angle>(value) {}
};

inline constexpr bool operator==(const Angle& left,
                                 const Angle& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Angle& left,
                                 const Angle& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Angle& left,
                                const Angle& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Angle& left,
                                const Angle& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Angle& left,
                                 const Angle& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Angle& left,
                                 const Angle& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Angle& angle) noexcept {
  stream << angle.Print();
  return stream;
}

inline PhQ::Angle Direction::Angle(const Direction& direction) const noexcept {
  return PhQ::Angle{*this, direction};
}

inline PhQ::Angle Direction::Angle(const Value::Vector& vector) const noexcept {
  return PhQ::Angle{*this, vector};
}

inline PhQ::Angle Value::Vector::Angle(
    const PhQ::Direction& direction) const noexcept {
  return PhQ::Angle{*this, direction};
}

inline PhQ::Angle Value::Vector::Angle(
    const Value::Vector& vector) const noexcept {
  return PhQ::Angle{*this, vector};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Angle> {
  size_t operator()(const PhQ::Angle& angle) const {
    return hash<double>()(angle.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGLE_HPP
