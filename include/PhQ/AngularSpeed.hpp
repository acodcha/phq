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

class AngularSpeed : public DimensionalScalarQuantity<Unit::AngularSpeed> {
public:
  constexpr AngularSpeed() noexcept
      : DimensionalScalarQuantity<Unit::AngularSpeed>() {}

  AngularSpeed(const double value, const Unit::AngularSpeed unit) noexcept
      : DimensionalScalarQuantity<Unit::AngularSpeed>(value, unit) {}

  constexpr AngularSpeed(const Angle& angle, const Duration& duration) noexcept
      : AngularSpeed(angle.Value() / duration.Value()) {}

  constexpr AngularSpeed(const Angle& angle,
                         const Frequency& frequency) noexcept
      : AngularSpeed(angle.Value() * frequency.Value()) {}

  constexpr AngularSpeed(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const Duration& duration) noexcept;

  constexpr AngularSpeed(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const Frequency& frequency) noexcept;

  inline AngularSpeed operator+(
      const AngularSpeed& angular_speed) const noexcept {
    return AngularSpeed{value_ + angular_speed.value_};
  }

  inline AngularSpeed operator-(
      const AngularSpeed& angular_speed) const noexcept {
    return AngularSpeed{value_ - angular_speed.value_};
  }

  inline AngularSpeed operator*(const double number) const noexcept {
    return AngularSpeed{value_ * number};
  }

  inline Angle operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  inline AngularAccelerationMagnitude operator*(
      const Frequency& frequency) const noexcept;

  inline AngularSpeed operator/(const double number) const noexcept {
    return AngularSpeed{value_ / number};
  }

  inline Angle operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline Frequency operator/(const Angle& angle) const noexcept {
    return {*this, angle};
  }

  inline AngularAccelerationMagnitude operator/(
      const Duration& duration) const noexcept;

  inline Duration operator/(const AngularAccelerationMagnitude&
                                angular_acceleration_magnitude) const noexcept;

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

inline constexpr bool operator==(const AngularSpeed& left,
                                 const AngularSpeed& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const AngularSpeed& left,
                                 const AngularSpeed& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const AngularSpeed& left,
                                const AngularSpeed& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const AngularSpeed& left,
                                const AngularSpeed& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const AngularSpeed& left,
                                 const AngularSpeed& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const AngularSpeed& left,
                                 const AngularSpeed& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const AngularSpeed& angular_speed) noexcept {
  stream << angular_speed.Print();
  return stream;
}

inline AngularSpeed operator*(const double number,
                              const AngularSpeed& angular_speed) noexcept {
  return angular_speed * number;
}

inline constexpr Angle::Angle(const AngularSpeed& angular_speed,
                              const Duration& duration) noexcept
    : Angle(angular_speed.Value() * duration.Value()) {}

inline constexpr Angle::Angle(const AngularSpeed& angular_speed,
                              const Frequency& frequency) noexcept
    : Angle(angular_speed.Value() / frequency.Value()) {}

inline constexpr Duration::Duration(const AngularSpeed& angular_speed,
                                    const Angle& angle) noexcept
    : Duration(angle.Value() / angular_speed.Value()) {}

inline constexpr Frequency::Frequency(const AngularSpeed& angular_speed,
                                      const Angle& angle) noexcept
    : Frequency(angular_speed.Value() / angle.Value()) {}

inline AngularSpeed Angle::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline AngularSpeed Frequency::operator*(const Angle& angle) const noexcept {
  return {angle, *this};
}

inline AngularSpeed Angle::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

inline Duration Angle::operator/(
    const AngularSpeed& angular_speed) const noexcept {
  return {angular_speed, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AngularSpeed> {
  size_t operator()(const PhQ::AngularSpeed& angular_speed) const {
    return hash<double>()(angular_speed.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP
