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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_MAGNITUDE_HPP

#include "AngularSpeed.hpp"
#include "Unit/AngularAcceleration.hpp"

namespace PhQ {

class AngularAccelerationMagnitude
    : public DimensionalScalarQuantity<Unit::AngularAcceleration> {
public:
  constexpr AngularAccelerationMagnitude() noexcept
      : DimensionalScalarQuantity<Unit::AngularAcceleration>() {}

  AngularAccelerationMagnitude(const double value,
                               const Unit::AngularAcceleration unit) noexcept
      : DimensionalScalarQuantity<Unit::AngularAcceleration>(value, unit) {}

  constexpr AngularAccelerationMagnitude(const AngularSpeed& angular_speed,
                                         const Time& time) noexcept
      : AngularAccelerationMagnitude(angular_speed.Value() / time.Value()) {}

  constexpr AngularAccelerationMagnitude(const AngularSpeed& angular_speed,
                                         const Frequency& frequency) noexcept
      : AngularAccelerationMagnitude(angular_speed.Value() *
                                     frequency.Value()) {}

  template <Unit::AngularAcceleration Unit>
  static constexpr AngularAccelerationMagnitude Create(
      const double value) noexcept {
    return AngularAccelerationMagnitude{
        StaticConvertCopy<Unit::AngularAcceleration, Unit,
                          StandardUnit<Unit::AngularAcceleration>>(value)};
  }

  inline AngularAccelerationMagnitude operator+(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude)
      const noexcept {
    return AngularAccelerationMagnitude{value_ +
                                        angular_acceleration_magnitude.value_};
  }

  inline AngularAccelerationMagnitude operator-(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude)
      const noexcept {
    return AngularAccelerationMagnitude{value_ -
                                        angular_acceleration_magnitude.value_};
  }

  inline AngularAccelerationMagnitude operator*(
      const double number) const noexcept {
    return AngularAccelerationMagnitude{value_ * number};
  }

  inline AngularSpeed operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline AngularAccelerationMagnitude operator/(
      const double number) const noexcept {
    return AngularAccelerationMagnitude{value_ / number};
  }

  inline AngularSpeed operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline Frequency operator/(const AngularSpeed& angular_speed) const noexcept {
    return {*this, angular_speed};
  }

  inline constexpr void operator+=(
      const AngularAccelerationMagnitude&
          angular_acceleration_magnitude) noexcept {
    value_ += angular_acceleration_magnitude.value_;
  }

  inline constexpr void operator-=(
      const AngularAccelerationMagnitude&
          angular_acceleration_magnitude) noexcept {
    value_ -= angular_acceleration_magnitude.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr AngularAccelerationMagnitude(const double value) noexcept
      : DimensionalScalarQuantity<Unit::AngularAcceleration>(value) {}
};

inline constexpr bool operator==(
    const AngularAccelerationMagnitude& left,
    const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const AngularAccelerationMagnitude& left,
    const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const AngularAccelerationMagnitude& left,
    const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const AngularAccelerationMagnitude& left,
    const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const AngularAccelerationMagnitude& left,
    const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const AngularAccelerationMagnitude& left,
    const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const AngularAccelerationMagnitude&
                                    angular_acceleration_magnitude) noexcept {
  stream << angular_acceleration_magnitude.Print();
  return stream;
}

inline AngularAccelerationMagnitude operator*(
    const double number, const AngularAccelerationMagnitude&
                             angular_acceleration_magnitude) noexcept {
  return angular_acceleration_magnitude * number;
}

inline constexpr Time::Time(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude,
    const AngularSpeed& angular_speed) noexcept
    : Time(angular_speed.Value() / angular_acceleration_magnitude.Value()) {}

inline constexpr Frequency::Frequency(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude,
    const AngularSpeed& angular_speed) noexcept
    : Frequency(angular_acceleration_magnitude.Value() /
                angular_speed.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude,
    const Time& time) noexcept
    : AngularSpeed(angular_acceleration_magnitude.Value() * time.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude,
    const Frequency& frequency) noexcept
    : AngularSpeed(angular_acceleration_magnitude.Value() / frequency.Value()) {
}

inline AngularAccelerationMagnitude Frequency::operator*(
    const AngularSpeed& angular_speed) const noexcept {
  return {angular_speed, *this};
}

inline AngularAccelerationMagnitude AngularSpeed::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline AngularAccelerationMagnitude AngularSpeed::operator/(
    const Time& time) const noexcept {
  return {*this, time};
}

inline Time AngularSpeed::operator/(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude)
    const noexcept {
  return {angular_acceleration_magnitude, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AngularAccelerationMagnitude> {
  size_t operator()(const PhQ::AngularAccelerationMagnitude&
                        angular_acceleration_magnitude) const {
    return hash<double>()(angular_acceleration_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_MAGNITUDE_HPP
