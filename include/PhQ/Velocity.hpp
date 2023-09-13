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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_HPP

#include "Position.hpp"
#include "Speed.hpp"

namespace PhQ {

// Forward declaration for class Velocity.
class Acceleration;

// Velocity vector.
class Velocity : public DimensionalVectorQuantity<Unit::Speed> {
public:
  constexpr Velocity() noexcept : DimensionalVectorQuantity<Unit::Speed>() {}

  Velocity(const Value::Vector& value, const Unit::Speed unit) noexcept
    : DimensionalVectorQuantity<Unit::Speed>(value, unit) {}

  constexpr Velocity(const Speed& speed, const Direction& direction) noexcept
    : Velocity(speed.Value() * direction.Value()) {}

  constexpr Velocity(
      const Displacement& displacement, const Time& time) noexcept
    : Velocity(displacement.Value() / time.Value()) {}

  constexpr Velocity(
      const Displacement& displacement, const Frequency& frequency) noexcept
    : Velocity(displacement.Value() * frequency.Value()) {}

  constexpr Velocity(
      const Acceleration& acceleration, const Time& time) noexcept;

  constexpr Velocity(
      const Acceleration& acceleration, const Frequency& frequency) noexcept;

  static constexpr Velocity Zero() noexcept {
    return Velocity{Value::Vector::Zero()};
  }

  template <Unit::Speed Unit>
  static constexpr Velocity Create(const Value::Vector& value) noexcept {
    return Velocity{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  Speed Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const Velocity& velocity) const noexcept {
    return {*this, velocity};
  }

  constexpr Velocity operator+(const Velocity& velocity) const noexcept {
    return Velocity{value_ + velocity.value_};
  }

  constexpr Velocity operator-(const Velocity& velocity) const noexcept {
    return Velocity{value_ - velocity.value_};
  }

  constexpr Velocity operator*(const double number) const noexcept {
    return Velocity{value_ * number};
  }

  constexpr Displacement operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  constexpr Acceleration operator*(const Frequency& frequency) const noexcept;

  constexpr Velocity operator/(const double number) const noexcept {
    return Velocity{value_ / number};
  }

  constexpr Acceleration operator/(const Time& time) const noexcept;

  constexpr Displacement operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr void operator+=(const Velocity& velocity) noexcept {
    value_ += velocity.value_;
  }

  constexpr void operator-=(const Velocity& velocity) noexcept {
    value_ -= velocity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Velocity(const Value::Vector& value) noexcept
    : DimensionalVectorQuantity<Unit::Speed>(value) {}
};

inline constexpr bool operator==(
    const Velocity& left, const Velocity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Velocity& left, const Velocity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Velocity& left, const Velocity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Velocity& left, const Velocity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Velocity& left, const Velocity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Velocity& left, const Velocity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Velocity& velocity) noexcept {
  stream << velocity.Print();
  return stream;
}

inline constexpr Velocity operator*(
    const double number, const Velocity& velocity) noexcept {
  return velocity * number;
}

inline Direction::Direction(const Velocity& velocity) noexcept
  : Direction(velocity.Value()) {}

inline Angle::Angle(
    const Velocity& velocity1, const Velocity& velocity2) noexcept
  : Angle(velocity1.Value(), velocity2.Value()) {}

inline constexpr Displacement::Displacement(
    const Velocity& velocity, const Time& time) noexcept
  : Displacement(velocity.Value() * time.Value()) {}

inline constexpr Displacement::Displacement(
    const Velocity& velocity, const Frequency& frequency) noexcept
  : Displacement(velocity.Value() / frequency.Value()) {}

inline Speed::Speed(const Velocity& velocity) noexcept
  : Speed(velocity.Value().Magnitude()) {}

inline constexpr Velocity Direction::operator*(
    const Speed& speed) const noexcept {
  return {speed, *this};
}

inline constexpr Displacement Time::operator*(
    const Velocity& velocity) const noexcept {
  return {velocity, *this};
}

inline constexpr Velocity Speed::operator*(
    const Direction& direction) const noexcept {
  return {*this, direction};
}

inline constexpr Velocity Frequency::operator*(
    const Displacement& displacement) const noexcept {
  return {displacement, *this};
}

inline constexpr Velocity Displacement::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr Velocity Displacement::operator/(
    const Time& time) const noexcept {
  return {*this, time};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Velocity> {
  inline size_t operator()(const PhQ::Velocity& velocity) const {
    return hash<PhQ::Value::Vector>()(velocity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_HPP
