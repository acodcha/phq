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
#include "DimensionalVectorQuantity.hpp"
#include "Direction.hpp"
#include "TemperatureGradientMagnitude.hpp"

namespace PhQ {

// Temperature gradient vector.
class TemperatureGradient
  : public DimensionalVectorQuantity<Unit::TemperatureGradient> {
public:
  // Default constructor. Constructs a temperature gradient with an
  // uninitialized value.
  TemperatureGradient() = default;

  // Constructor. Constructs a temperature gradient with a given value expressed
  // in a given temperature gradient unit.
  TemperatureGradient(
      const Value::Vector& value, const Unit::TemperatureGradient unit)
    : DimensionalVectorQuantity<Unit::TemperatureGradient>(value, unit) {}

  // Constructor. Constructs a temperature gradient from a given temperature
  // gradient magnitude and direction.
  constexpr TemperatureGradient(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude,
      const Direction& direction)
    : TemperatureGradient(
        temperature_gradient_magnitude.Value() * direction.Value()) {}

  // Destructor. Destroys this temperature gradient.
  ~TemperatureGradient() noexcept = default;

  // Copy constructor. Constructs a temperature gradient by copying another one.
  constexpr TemperatureGradient(const TemperatureGradient& other) = default;

  // Move constructor. Constructs a temperature gradient by moving another one.
  constexpr TemperatureGradient(TemperatureGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this temperature gradient by copying
  // another one.
  constexpr TemperatureGradient& operator=(
      const TemperatureGradient& other) = default;

  // Move assignment operator. Assigns this temperature gradient by moving
  // another one.
  constexpr TemperatureGradient& operator=(
      TemperatureGradient&& other) noexcept = default;

  // Statically creates a temperature gradient of zero.
  static constexpr TemperatureGradient Zero() {
    return TemperatureGradient{Value::Vector::Zero()};
  }

  // Statically creates a temperature gradient from the given x, y, and z
  // Cartesian components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient
  Create(const double x, const double y, const double z) {
    return TemperatureGradient{StaticConvertCopy<
        Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
        Value::Vector{x, y, z})};
  }

  // Statically creates a temperature gradient from the given x, y, and z
  // Cartesian components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient
  Create(const std::array<double, 3>& x_y_z) {
    return TemperatureGradient{StaticConvertCopy<
        Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
        Value::Vector{x_y_z})};
  }

  // Statically creates a temperature gradient with a given value expressed in a
  // given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient Create(const Value::Vector& value) {
    return TemperatureGradient{
        StaticConvertCopy<Unit::TemperatureGradient, Unit,
                          Standard<Unit::TemperatureGradient>>(value)};
  }

  // Returns the magnitude of this temperature gradient.
  TemperatureGradientMagnitude Magnitude() const {
    return {*this};
  }

  // Returns the angle between this temperature gradient and another one.
  PhQ::Angle Angle(const TemperatureGradient& temperature_gradient) const {
    return {*this, temperature_gradient};
  }

  constexpr TemperatureGradient operator+(
      const TemperatureGradient& temperature_gradient) const {
    return TemperatureGradient{value_ + temperature_gradient.value_};
  }

  constexpr TemperatureGradient operator-(
      const TemperatureGradient& temperature_gradient) const {
    return TemperatureGradient{value_ - temperature_gradient.value_};
  }

  constexpr TemperatureGradient operator*(const double number) const {
    return TemperatureGradient{value_ * number};
  }

  constexpr TemperatureGradient operator/(const double number) const {
    return TemperatureGradient{value_ / number};
  }

  constexpr void operator+=(
      const TemperatureGradient& temperature_gradient) noexcept {
    value_ += temperature_gradient.value_;
  }

  constexpr void operator-=(
      const TemperatureGradient& temperature_gradient) noexcept {
    value_ -= temperature_gradient.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a temperature gradient with a given value expressed
  // in the standard temperature gradient unit.
  explicit constexpr TemperatureGradient(const Value::Vector& value)
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
    std::ostream& stream, const TemperatureGradient& temperature_gradient) {
  stream << temperature_gradient.Print();
  return stream;
}

inline constexpr TemperatureGradient operator*(
    const double number, const TemperatureGradient& temperature_gradient) {
  return temperature_gradient * number;
}

inline Direction::Direction(const TemperatureGradient& temperature_gradient)
  : Direction(temperature_gradient.Value()) {}

inline Angle::Angle(const TemperatureGradient& temperature_gradient_1,
                    const TemperatureGradient& temperature_gradient_2)
  : Angle(temperature_gradient_1.Value(), temperature_gradient_2.Value()) {}

inline TemperatureGradientMagnitude::TemperatureGradientMagnitude(
    const TemperatureGradient& temperature_gradient)
  : TemperatureGradientMagnitude(temperature_gradient.Value().Magnitude()) {}

inline constexpr TemperatureGradient Direction::operator*(
    const TemperatureGradientMagnitude& temperature_gradient_magnitude) const {
  return {temperature_gradient_magnitude, *this};
}

inline constexpr TemperatureGradient TemperatureGradientMagnitude::operator*(
    const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TemperatureGradient> {
  inline size_t operator()(
      const PhQ::TemperatureGradient& temperature_gradient) const {
    return hash<PhQ::Value::Vector>()(temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_HPP
