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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_HPP

#include "Angle.hpp"
#include "Direction.hpp"
#include "Quantity/DimensionalVector.hpp"
#include "TemperatureGradientMagnitude.hpp"

namespace PhQ {

// Temperature gradient vector.
class TemperatureGradient
  : public DimensionalVectorQuantity<Unit::TemperatureGradient> {
public:
  constexpr TemperatureGradient() noexcept
    : DimensionalVectorQuantity<Unit::TemperatureGradient>() {}

  TemperatureGradient(
      const Value::Vector& value, const Unit::TemperatureGradient unit) noexcept
    : DimensionalVectorQuantity<Unit::TemperatureGradient>(value, unit) {}

  constexpr TemperatureGradient(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude,
      const Direction& direction) noexcept
    : TemperatureGradient(
        temperature_gradient_magnitude.Value() * direction.Value()) {}

  static constexpr TemperatureGradient Zero() noexcept {
    return TemperatureGradient{Value::Vector::Zero()};
  }

  template<Unit::TemperatureGradient Unit> static constexpr TemperatureGradient
  Create(const Value::Vector& value) noexcept {
    return TemperatureGradient{
        StaticConvertCopy<Unit::TemperatureGradient, Unit,
                          StandardUnit<Unit::TemperatureGradient>>(value)};
  }

  inline constexpr TemperatureGradientMagnitude Magnitude() const noexcept {
    return {*this};
  }

  inline PhQ::Angle Angle(
      const TemperatureGradient& temperature_gradient) const noexcept {
    return {*this, temperature_gradient};
  }

  inline constexpr TemperatureGradient operator+(
      const TemperatureGradient& temperature_gradient) const noexcept {
    return TemperatureGradient{value_ + temperature_gradient.value_};
  }

  inline constexpr TemperatureGradient operator-(
      const TemperatureGradient& temperature_gradient) const noexcept {
    return TemperatureGradient{value_ - temperature_gradient.value_};
  }

  inline constexpr TemperatureGradient operator*(
      const double number) const noexcept {
    return TemperatureGradient{value_ * number};
  }

  inline constexpr TemperatureGradient operator/(
      const double number) const noexcept {
    return TemperatureGradient{value_ / number};
  }

  inline constexpr void operator+=(
      const TemperatureGradient& temperature_gradient) noexcept {
    value_ += temperature_gradient.value_;
  }

  inline constexpr void operator-=(
      const TemperatureGradient& temperature_gradient) noexcept {
    value_ -= temperature_gradient.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TemperatureGradient(const Value::Vector& value) noexcept
    : DimensionalVectorQuantity<Unit::TemperatureGradient>(value) {}
};

inline constexpr bool operator==(const TemperatureGradient& left,
                                 const TemperatureGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const TemperatureGradient& left,
                                 const TemperatureGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const TemperatureGradient& left,
                                const TemperatureGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const TemperatureGradient& left,
                                const TemperatureGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const TemperatureGradient& left,
                                 const TemperatureGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const TemperatureGradient& left,
                                 const TemperatureGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const TemperatureGradient& temperature_gradient) noexcept {
  stream << temperature_gradient.Print();
  return stream;
}

inline constexpr TemperatureGradient operator*(
    const double number,
    const TemperatureGradient& temperature_gradient) noexcept {
  return temperature_gradient * number;
}

inline constexpr Direction::Direction(
    const TemperatureGradient& temperature_gradient) noexcept
  : Direction(temperature_gradient.Value()) {}

inline Angle::Angle(const TemperatureGradient& temperature_gradient_1,
                    const TemperatureGradient& temperature_gradient_2) noexcept
  : Angle(temperature_gradient_1.Value(), temperature_gradient_2.Value()) {}

inline constexpr TemperatureGradientMagnitude::TemperatureGradientMagnitude(
    const TemperatureGradient& temperature_gradient) noexcept
  : TemperatureGradientMagnitude(temperature_gradient.Value().Magnitude()) {}

inline constexpr TemperatureGradient Direction::operator*(
    const TemperatureGradientMagnitude& temperature_gradient_magnitude)
    const noexcept {
  return {temperature_gradient_magnitude, *this};
}

inline constexpr TemperatureGradient TemperatureGradientMagnitude::operator*(
    const Direction& direction) const noexcept {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::TemperatureGradient> {
  size_t operator()(
      const PhQ::TemperatureGradient& temperature_gradient) const {
    return hash<PhQ::Value::Vector>()(temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_HPP
