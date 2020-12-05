// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Frequency.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration.
class AngularAccelerationMagnitude;

class AngularSpeed : public DimensionalScalarQuantity<Unit::AngularSpeed> {

public:

  constexpr AngularSpeed() noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>() {}

  constexpr AngularSpeed(double value, Unit::AngularSpeed unit) noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>(value, unit) {}

  constexpr AngularSpeed(const Angle& angle, const Duration& duration) noexcept : AngularSpeed(angle.value() / duration.value()) {}

  constexpr AngularSpeed(const Angle& angle, const Frequency& frequency) noexcept : AngularSpeed(angle.value() * frequency.value()) {}

  constexpr AngularSpeed(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const Duration& duration) noexcept;

  constexpr AngularSpeed(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const Frequency& frequency) noexcept;

  constexpr bool operator==(const AngularSpeed& angular_speed) const noexcept {
    return value_ == angular_speed.value_;
  }

  constexpr bool operator!=(const AngularSpeed& angular_speed) const noexcept {
    return value_ != angular_speed.value_;
  }

  constexpr bool operator<(const AngularSpeed& angular_speed) const noexcept {
    return value_ < angular_speed.value_;
  }

  constexpr bool operator<=(const AngularSpeed& angular_speed) const noexcept {
    return value_ <= angular_speed.value_;
  }

  constexpr bool operator>(const AngularSpeed& angular_speed) const noexcept {
    return value_ > angular_speed.value_;
  }

  constexpr bool operator>=(const AngularSpeed& angular_speed) const noexcept {
    return value_ >= angular_speed.value_;
  }

  constexpr AngularSpeed operator+(const AngularSpeed& angular_speed) const noexcept {
    return {value_ + angular_speed.value_};
  }

  constexpr void operator+=(const AngularSpeed& angular_speed) noexcept {
    value_ += angular_speed.value_;
  }

  constexpr AngularSpeed operator-(const AngularSpeed& angular_speed) const noexcept {
    return {value_ - angular_speed.value_};
  }

  constexpr void operator-=(const AngularSpeed& angular_speed) noexcept {
    value_ -= angular_speed.value_;
  }

  constexpr Angle operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr AngularAccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  constexpr Angle operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Angle& angle) const noexcept {
    return {*this, angle};
  }

  constexpr AngularAccelerationMagnitude operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept;

protected:

  constexpr AngularSpeed(double value) noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>(value) {}

};

template <> constexpr bool sort(const AngularSpeed& angular_speed_1, const AngularSpeed& angular_speed_2) noexcept {
  return sort(angular_speed_1.value(), angular_speed_2.value());
}

constexpr Angle::Angle(const AngularSpeed& angular_speed, const Duration& duration) noexcept : Angle(angular_speed.value() * duration.value()) {}

constexpr Angle::Angle(const AngularSpeed& angular_speed, const Frequency& frequency) noexcept : Angle(angular_speed.value() / frequency.value()) {}

constexpr Duration::Duration(const AngularSpeed& angular_speed, const Angle& angle) noexcept : Duration(angle.value() / angular_speed.value()) {}

constexpr Frequency::Frequency(const AngularSpeed& angular_speed, const Angle& angle) noexcept : Frequency(angular_speed.value() / angle.value()) {}

constexpr AngularSpeed Angle::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr AngularSpeed Frequency::operator*(const Angle& angle) const noexcept {
  return {angle, *this};
}

constexpr AngularSpeed Angle::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

constexpr Duration Angle::operator/(const AngularSpeed& angular_speed) const noexcept {
  return {angular_speed, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::AngularSpeed> {
  size_t operator()(const PhQ::AngularSpeed& angular_speed) const {
    return hash<double>()(angular_speed.value());
  }
};

} // namespace std
