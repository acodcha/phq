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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP

#include "Angle.hpp"
#include "Frequency.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration for class AngularSpeed.
class AngularAccelerationMagnitude;

// Planar angular speed. Magnitude of angular velocity. Time rate of change of
// an angle. Typically measured in radians per second. Can also represent a
// circular frequency.
class AngularSpeed : public DimensionalScalarQuantity<Unit::AngularSpeed> {
public:
  constexpr AngularSpeed() noexcept
    : DimensionalScalarQuantity<Unit::AngularSpeed>() {}

  AngularSpeed(const double value, const Unit::AngularSpeed unit) noexcept
    : DimensionalScalarQuantity<Unit::AngularSpeed>(value, unit) {}

  constexpr AngularSpeed(const Angle& angle, const Time& time) noexcept
    : AngularSpeed(angle.Value() / time.Value()) {}

  constexpr AngularSpeed(
      const Angle& angle, const Frequency& frequency) noexcept
    : AngularSpeed(angle.Value() * frequency.Value()) {}

  constexpr AngularSpeed(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const Time& time) noexcept;

  constexpr AngularSpeed(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const Frequency& frequency) noexcept;

  static constexpr AngularSpeed Zero() noexcept { return AngularSpeed{0.0}; }

  template<Unit::AngularSpeed Unit>
  static constexpr AngularSpeed Create(const double value) noexcept {
    return AngularSpeed{
        StaticConvertCopy<Unit::AngularSpeed, Unit,
                          StandardUnit<Unit::AngularSpeed>>(value)};
  }

  inline constexpr AngularSpeed operator+(
      const AngularSpeed& angular_speed) const noexcept {
    return AngularSpeed{value_ + angular_speed.value_};
  }

  inline constexpr AngularSpeed operator-(
      const AngularSpeed& angular_speed) const noexcept {
    return AngularSpeed{value_ - angular_speed.value_};
  }

  inline constexpr AngularSpeed operator*(const double number) const noexcept {
    return AngularSpeed{value_ * number};
  }

  inline constexpr Angle operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline constexpr AngularAccelerationMagnitude operator*(
      const Frequency& frequency) const noexcept;

  inline constexpr AngularSpeed operator/(const double number) const noexcept {
    return AngularSpeed{value_ / number};
  }

  inline constexpr Angle operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr Frequency operator/(const Angle& angle) const noexcept {
    return {*this, angle};
  }

  inline constexpr AngularAccelerationMagnitude operator/(
      const Time& time) const noexcept;

  inline constexpr Time
  operator/(const AngularAccelerationMagnitude& angular_acceleration_magnitude)
      const noexcept;

  inline constexpr void operator+=(const AngularSpeed& angular_speed) noexcept {
    value_ += angular_speed.value_;
  }

  inline constexpr void operator-=(const AngularSpeed& angular_speed) noexcept {
    value_ -= angular_speed.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr AngularSpeed(const double value) noexcept
    : DimensionalScalarQuantity<Unit::AngularSpeed>(value) {}
};

inline constexpr bool operator==(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const AngularSpeed& angular_speed) noexcept {
  stream << angular_speed.Print();
  return stream;
}

inline constexpr AngularSpeed operator*(
    const double number, const AngularSpeed& angular_speed) noexcept {
  return angular_speed * number;
}

inline constexpr Angle::Angle(
    const AngularSpeed& angular_speed, const Time& time) noexcept
  : Angle(angular_speed.Value() * time.Value()) {}

inline constexpr Angle::Angle(
    const AngularSpeed& angular_speed, const Frequency& frequency) noexcept
  : Angle(angular_speed.Value() / frequency.Value()) {}

inline constexpr Time::Time(
    const AngularSpeed& angular_speed, const Angle& angle) noexcept
  : Time(angle.Value() / angular_speed.Value()) {}

inline constexpr Frequency::Frequency(
    const AngularSpeed& angular_speed, const Angle& angle) noexcept
  : Frequency(angular_speed.Value() / angle.Value()) {}

inline constexpr AngularSpeed Angle::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr AngularSpeed Frequency::operator*(
    const Angle& angle) const noexcept {
  return {angle, *this};
}

inline constexpr AngularSpeed Angle::operator/(
    const Time& time) const noexcept {
  return {*this, time};
}

inline constexpr Time Angle::operator/(
    const AngularSpeed& angular_speed) const noexcept {
  return {angular_speed, *this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::AngularSpeed> {
  size_t operator()(const PhQ::AngularSpeed& angular_speed) const {
    return hash<double>()(angular_speed.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP
