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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRACTION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRACTION_HPP

#include "Force.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

class Traction : public DimensionalVectorQuantity<Unit::Pressure> {
public:
  constexpr Traction() noexcept : DimensionalVectorQuantity<Unit::Pressure>() {}

  Traction(const Value::Vector& value, const Unit::Pressure unit) noexcept
      : DimensionalVectorQuantity<Unit::Pressure>(value, unit) {}

  constexpr Traction(const StaticPressure& static_pressure,
                     const Direction& direction) noexcept
      : Traction(-static_pressure.Value() * direction.Value()) {}

  constexpr Traction(const Force& force, const Area& area) noexcept
      : Traction(force.Value() / area.Value()) {}

  constexpr Traction(const Stress& stress, const Direction& direction) noexcept;

  template <Unit::Pressure Unit>
  static constexpr Traction Create(const Value::Vector& value) noexcept {
    return Traction{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr StaticPressure Magnitude() const noexcept { return {*this}; }

  inline PhQ::Angle Angle(const Traction& traction) const noexcept {
    return {*this, traction};
  }

  inline constexpr Traction operator+(const Traction& traction) const noexcept {
    return Traction{value_ + traction.value_};
  }

  inline constexpr Traction operator-(const Traction& traction) const noexcept {
    return Traction{value_ - traction.value_};
  }

  inline constexpr Traction operator*(const double number) const noexcept {
    return Traction{value_ * number};
  }

  inline constexpr Force operator*(const Area& area) const noexcept {
    return {*this, area};
  }

  inline constexpr Traction operator/(const double number) const noexcept {
    return Traction{value_ / number};
  }

  inline constexpr void operator+=(const Traction& traction) noexcept {
    value_ += traction.value_;
  }

  inline constexpr void operator-=(const Traction& traction) noexcept {
    value_ -= traction.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Traction(const Value::Vector& value) noexcept
      : DimensionalVectorQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const Traction& left,
                                 const Traction& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Traction& left,
                                 const Traction& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Traction& left,
                                const Traction& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Traction& left,
                                const Traction& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Traction& left,
                                 const Traction& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Traction& left,
                                 const Traction& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Traction& traction) noexcept {
  stream << traction.Print();
  return stream;
}

inline constexpr Traction operator*(const double number,
                                    const Traction& traction) noexcept {
  return traction * number;
}

inline constexpr Direction::Direction(const Traction& traction) noexcept
    : Direction(traction.Value()) {}

inline Angle::Angle(const Traction& traction_1,
                    const Traction& traction_2) noexcept
    : Angle(traction_1.Value(), traction_2.Value()) {}

inline constexpr StaticPressure::StaticPressure(
    const Traction& traction) noexcept
    : StaticPressure(traction.Value().Magnitude()) {}

inline constexpr Force::Force(const Traction& traction,
                              const Area& area) noexcept
    : Force(traction.Value() * area.Value()) {}

inline constexpr Traction Direction::operator*(
    const StaticPressure& static_pressure) const noexcept {
  return {static_pressure, *this};
}

inline constexpr Traction StaticPressure::operator*(
    const Direction& direction) const noexcept {
  return {*this, direction};
}

inline constexpr Traction Force::operator/(const Area& area) const noexcept {
  return {*this, area};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Traction> {
  size_t operator()(const PhQ::Traction& traction) const {
    return hash<PhQ::Value::Vector>()(traction.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRACTION_HPP
