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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_HPP

#include "AccelerationMagnitude.hpp"
#include "Velocity.hpp"

namespace PhQ {

class Acceleration : public DimensionalVectorQuantity<Unit::Acceleration> {
public:
  constexpr Acceleration() noexcept
      : DimensionalVectorQuantity<Unit::Acceleration>() {}

  Acceleration(const Value::Vector& value,
               const Unit::Acceleration unit) noexcept
      : DimensionalVectorQuantity<Unit::Acceleration>(value, unit) {}

  constexpr Acceleration(const AccelerationMagnitude& acceleration_magnitude,
                         const Direction& direction) noexcept
      : Acceleration(acceleration_magnitude.Value() * direction.Value()) {}

  constexpr Acceleration(const Velocity& velocity, const Time& time) noexcept
      : Acceleration(velocity.Value() / time.Value()) {}

  constexpr Acceleration(const Velocity& velocity,
                         const Frequency& frequency) noexcept
      : Acceleration(velocity.Value() * frequency.Value()) {}

  template <Unit::Acceleration Unit>
  static constexpr Acceleration Create(const Value::Vector& value) noexcept {
    return Acceleration{
        StaticConvertCopy<Unit::Acceleration, Unit,
                          StandardUnit<Unit::Acceleration>>(value)};
  }

  inline AccelerationMagnitude Magnitude() const noexcept { return {*this}; }

  inline PhQ::Angle Angle(const Acceleration& acceleration) const noexcept {
    return {*this, acceleration};
  }

  inline Acceleration operator+(
      const Acceleration& acceleration) const noexcept {
    return Acceleration{value_ + acceleration.value_};
  }

  inline Acceleration operator-(
      const Acceleration& acceleration) const noexcept {
    return Acceleration{value_ - acceleration.value_};
  }

  inline Acceleration operator*(const double number) const noexcept {
    return Acceleration{value_ * number};
  }

  inline Velocity operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline Acceleration operator/(const double number) const noexcept {
    return Acceleration{value_ / number};
  }

  inline Velocity operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr void operator+=(const Acceleration& acceleration) noexcept {
    value_ += acceleration.value_;
  }

  inline constexpr void operator-=(const Acceleration& acceleration) noexcept {
    value_ -= acceleration.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Acceleration(const Value::Vector& value) noexcept
      : DimensionalVectorQuantity<Unit::Acceleration>(value) {}
};

inline constexpr bool operator==(const Acceleration& left,
                                 const Acceleration& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Acceleration& left,
                                 const Acceleration& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Acceleration& left,
                                const Acceleration& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Acceleration& left,
                                const Acceleration& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Acceleration& left,
                                 const Acceleration& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Acceleration& left,
                                 const Acceleration& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Acceleration& acceleration) noexcept {
  stream << acceleration.Print();
  return stream;
}

inline Acceleration operator*(const double number,
                              const Acceleration& acceleration) noexcept {
  return acceleration * number;
}

inline Direction::Direction(const Acceleration& acceleration) noexcept
    : Direction(acceleration.Value()) {}

inline Angle::Angle(const Acceleration& acceleration_1,
                    const Acceleration& acceleration_2) noexcept
    : Angle(acceleration_1.Value(), acceleration_2.Value()) {}

inline AccelerationMagnitude::AccelerationMagnitude(
    const Acceleration& acceleration) noexcept
    : AccelerationMagnitude(acceleration.Value().Magnitude()) {}

inline constexpr Velocity::Velocity(const Acceleration& acceleration,
                                    const Time& time) noexcept
    : Velocity(acceleration.Value() * time.Value()) {}

inline constexpr Velocity::Velocity(const Acceleration& acceleration,
                                    const Frequency& frequency) noexcept
    : Velocity(acceleration.Value() / frequency.Value()) {}

inline Acceleration Direction::operator*(
    const AccelerationMagnitude& acceleration_magnitude) const noexcept {
  return {acceleration_magnitude, *this};
}

inline Velocity Time::operator*(
    const Acceleration& acceleration) const noexcept {
  return {acceleration, *this};
}

inline Acceleration AccelerationMagnitude::operator*(
    const Direction& direction) const noexcept {
  return {*this, direction};
}

inline Acceleration Velocity::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline Acceleration Velocity::operator/(const Time& time) const noexcept {
  return {*this, time};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Acceleration> {
  size_t operator()(const PhQ::Acceleration& acceleration) const {
    return hash<PhQ::Value::Vector>()(acceleration.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_HPP
