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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP

#include "Angle.hpp"
#include "DimensionalVectorQuantity.hpp"
#include "Direction.hpp"
#include "ForceMagnitude.hpp"

namespace PhQ {

// Forward declaration for class Force.
class Traction;

// Force vector.
class Force : public DimensionalVectorQuantity<Unit::Force> {
public:
  constexpr Force() : DimensionalVectorQuantity<Unit::Force>() {}

  Force(const Value::Vector& value, const Unit::Force unit)
    : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr Force(
      const ForceMagnitude& force_magnitude, const Direction& direction)
    : Force(force_magnitude.Value() * direction.Value()) {}

  constexpr Force(const Traction& traction, const Area& area);

  static constexpr Force Zero() {
    return Force{Value::Vector::Zero()};
  }

  template <Unit::Force Unit>
  static constexpr Force Create(const Value::Vector& value) {
    return Force{
        StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  ForceMagnitude Magnitude() const {
    return {*this};
  }

  PhQ::Angle Angle(const Force& force) const {
    return {*this, force};
  }

  constexpr Force operator+(const Force& force) const {
    return Force{value_ + force.value_};
  }

  constexpr Force operator-(const Force& force) const {
    return Force{value_ - force.value_};
  }

  constexpr Force operator*(const double number) const {
    return Force{value_ * number};
  }

  constexpr Force operator/(const double number) const {
    return Force{value_ / number};
  }

  constexpr Traction operator/(const Area& area) const;

  constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Force(const Value::Vector& value)
    : DimensionalVectorQuantity<Unit::Force>(value) {}
};

inline constexpr bool operator==(
    const Force& left, const Force& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Force& left, const Force& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Force& left, const Force& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Force& left, const Force& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Force& left, const Force& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Force& left, const Force& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Force& force) {
  stream << force.Print();
  return stream;
}

inline constexpr Force operator*(const double number, const Force& force) {
  return force * number;
}

inline Direction::Direction(const Force& force) : Direction(force.Value()) {}

inline Angle::Angle(const Force& force1, const Force& force2)
  : Angle(force1.Value(), force2.Value()) {}

inline ForceMagnitude::ForceMagnitude(const Force& force)
  : ForceMagnitude(force.Value().Magnitude()) {}

inline constexpr Force Direction::operator*(
    const ForceMagnitude& force_magnitude) const {
  return {force_magnitude, *this};
}

inline constexpr Force ForceMagnitude::operator*(
    const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Force> {
  inline size_t operator()(const PhQ::Force& force) const {
    return hash<PhQ::Value::Vector>()(force.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP
