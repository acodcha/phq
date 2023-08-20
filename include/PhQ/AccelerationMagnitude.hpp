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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_MAGNITUDE_HPP

#include "Speed.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declarations for class AccelerationMagnitude.
class Acceleration;
class Direction;

// Acceleration scalar. Magnitude of the acceleration vector.
class AccelerationMagnitude
  : public DimensionalScalarQuantity<Unit::Acceleration> {
public:
  constexpr AccelerationMagnitude() noexcept
    : DimensionalScalarQuantity<Unit::Acceleration>() {}

  AccelerationMagnitude(
      const double value, const Unit::Acceleration unit) noexcept
    : DimensionalScalarQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude(const Speed& speed, const Time& time) noexcept
    : AccelerationMagnitude(speed.Value() / time.Value()) {}

  constexpr AccelerationMagnitude(
      const Speed& speed, const Frequency& frequency) noexcept
    : AccelerationMagnitude(speed.Value() * frequency.Value()) {}

  AccelerationMagnitude(const Acceleration& acceleration) noexcept;

  static constexpr AccelerationMagnitude Zero() noexcept {
    return AccelerationMagnitude{0.0};
  }

  template<Unit::Acceleration Unit>
  static constexpr AccelerationMagnitude Create(const double value) noexcept {
    return AccelerationMagnitude{
        StaticConvertCopy<Unit::Acceleration, Unit,
                          Standard<Unit::Acceleration>>(value)};
  }

  inline constexpr AccelerationMagnitude operator+(
      const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return AccelerationMagnitude{value_ + acceleration_magnitude.value_};
  }

  inline constexpr AccelerationMagnitude operator-(
      const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return AccelerationMagnitude{value_ - acceleration_magnitude.value_};
  }

  inline constexpr AccelerationMagnitude operator*(
      const double number) const noexcept {
    return AccelerationMagnitude{value_ * number};
  }

  inline constexpr Speed operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline constexpr Acceleration operator*(
      const Direction& direction) const noexcept;

  inline constexpr AccelerationMagnitude operator/(
      const double number) const noexcept {
    return AccelerationMagnitude{value_ / number};
  }

  inline constexpr Speed operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr Frequency operator/(const Speed& speed) const noexcept {
    return {*this, speed};
  }

  inline constexpr double operator/(
      const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ / acceleration_magnitude.value_;
  }

  inline constexpr void operator+=(
      const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ += acceleration_magnitude.value_;
  }

  inline constexpr void operator-=(
      const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ -= acceleration_magnitude.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr AccelerationMagnitude(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Acceleration>(value) {}
};

inline constexpr bool operator==(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const AccelerationMagnitude& left,
                                const AccelerationMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const AccelerationMagnitude& left,
                                const AccelerationMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const AccelerationMagnitude& acceleration_magnitude) noexcept {
  stream << acceleration_magnitude.Print();
  return stream;
}

inline constexpr AccelerationMagnitude operator*(
    const double number,
    const AccelerationMagnitude& acceleration_magnitude) noexcept {
  return acceleration_magnitude * number;
}

inline constexpr Time::Time(const AccelerationMagnitude& acceleration_magnitude,
                            const Speed& speed) noexcept
  : Time(speed.Value() / acceleration_magnitude.Value()) {}

inline constexpr Frequency::Frequency(
    const AccelerationMagnitude& acceleration_magnitude,
    const Speed& speed) noexcept
  : Frequency(acceleration_magnitude.Value() / speed.Value()) {}

inline constexpr Speed::Speed(
    const AccelerationMagnitude& acceleration_magnitude,
    const Time& time) noexcept
  : Speed(acceleration_magnitude.Value() * time.Value()) {}

inline constexpr Speed::Speed(
    const AccelerationMagnitude& acceleration_magnitude,
    const Frequency& frequency) noexcept
  : Speed(acceleration_magnitude.Value() / frequency.Value()) {}

inline constexpr AccelerationMagnitude Frequency::operator*(
    const Speed& speed) const noexcept {
  return {speed, *this};
}

inline constexpr AccelerationMagnitude Speed::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr AccelerationMagnitude Speed::operator/(
    const Time& time) const noexcept {
  return {*this, time};
}

inline constexpr Time Speed::operator/(
    const AccelerationMagnitude& acceleration_magnitude) const noexcept {
  return {acceleration_magnitude, *this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::AccelerationMagnitude> {
  size_t operator()(
      const PhQ::AccelerationMagnitude& acceleration_magnitude) const {
    return hash<double>()(acceleration_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_MAGNITUDE_HPP
