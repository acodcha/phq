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
#include "Direction.hpp"
#include "ForceMagnitude.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declaration for class Force.
class Traction;

class Force : public DimensionalVectorQuantity<Unit::Force> {
public:
  constexpr Force() noexcept : DimensionalVectorQuantity<Unit::Force>() {}

  Force(const Value::Vector& value, const Unit::Force unit) noexcept
      : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr Force(const ForceMagnitude& force_magnitude,
                  const Direction& direction) noexcept
      : Force(force_magnitude.Value() * direction.Value()) {}

  constexpr Force(const Traction& traction, const Area& area) noexcept;

  template <Unit::Force Unit>
  static constexpr Force Create(const Value::Vector& value) noexcept {
    return Force{
        StaticConvertCopy<Unit::Force, Unit, StandardUnit<Unit::Force>>(value)};
  }

  inline ForceMagnitude Magnitude() const noexcept { return {*this}; }

  inline PhQ::Angle Angle(const Force& force) const noexcept {
    return {*this, force};
  }

  inline Force operator+(const Force& force) const noexcept {
    return Force{value_ + force.value_};
  }

  inline Force operator-(const Force& force) const noexcept {
    return Force{value_ - force.value_};
  }

  inline Force operator*(const double number) const noexcept {
    return Force{value_ * number};
  }

  inline Force operator/(const double number) const noexcept {
    return Force{value_ / number};
  }

  inline Traction operator/(const Area& area) const noexcept;

  inline constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  inline constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Force(const Value::Vector& value) noexcept
      : DimensionalVectorQuantity<Unit::Force>(value) {}
};

inline constexpr bool operator==(const Force& left,
                                 const Force& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Force& left,
                                 const Force& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Force& left,
                                const Force& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Force& left,
                                const Force& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Force& left,
                                 const Force& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Force& left,
                                 const Force& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Force& force) noexcept {
  stream << force.Print();
  return stream;
}

inline Force operator*(const double number, const Force& force) noexcept {
  return force * number;
}

inline Direction::Direction(const Force& force) noexcept
    : Direction(force.Value()) {}

inline Angle::Angle(const Force& force1, const Force& force2) noexcept
    : Angle(force1.Value(), force2.Value()) {}

inline ForceMagnitude::ForceMagnitude(const Force& force) noexcept
    : ForceMagnitude(force.Value().Magnitude()) {}

inline Force Direction::operator*(
    const ForceMagnitude& force_magnitude) const noexcept {
  return {force_magnitude, *this};
}

inline Force ForceMagnitude::operator*(
    const Direction& direction) const noexcept {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Force> {
  size_t operator()(const PhQ::Force& force) const {
    return hash<PhQ::Value::Vector>()(force.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP
