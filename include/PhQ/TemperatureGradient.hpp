// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_TEMPERATURE_GRADIENT_HPP
#define PHQ_TEMPERATURE_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "ScalarTemperatureGradient.hpp"
#include "Unit/TemperatureGradient.hpp"
#include "Vector.hpp"

namespace PhQ {

// Temperature gradient vector. See also PhQ::ScalarTemperatureGradient.
class TemperatureGradient : public DimensionalVector<Unit::TemperatureGradient> {
public:
  // Default constructor. Constructs a temperature gradient vector with an uninitialized value.
  TemperatureGradient() = default;

  // Constructor. Constructs a temperature gradient vector with a given value expressed in a given
  // temperature gradient unit.
  TemperatureGradient(const Vector& value, const Unit::TemperatureGradient unit)
    : DimensionalVector<Unit::TemperatureGradient>(value, unit) {}

  // Constructor. Constructs a temperature gradient vector from a given scalar temperature gradient
  // magnitude and direction.
  constexpr TemperatureGradient(
      const ScalarTemperatureGradient& scalar_temperature_gradient, const Direction& direction)
    : TemperatureGradient(scalar_temperature_gradient.Value() * direction.Value()) {}

  // Destructor. Destroys this temperature gradient vector.
  ~TemperatureGradient() noexcept = default;

  // Copy constructor. Constructs a temperature gradient vector by copying another one.
  constexpr TemperatureGradient(const TemperatureGradient& other) = default;

  // Move constructor. Constructs a temperature gradient vector by moving another one.
  constexpr TemperatureGradient(TemperatureGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this temperature gradient vector by copying another one.
  constexpr TemperatureGradient& operator=(const TemperatureGradient& other) = default;

  // Move assignment operator. Assigns this temperature gradient vector by moving another one.
  constexpr TemperatureGradient& operator=(TemperatureGradient&& other) noexcept = default;

  // Statically creates a temperature gradient vector of zero.
  static constexpr TemperatureGradient Zero() {
    return TemperatureGradient{Vector::Zero()};
  }

  // Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  // components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient Create(const double x, const double y, const double z) {
    return TemperatureGradient{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector{x, y, z})};
  }

  // Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  // components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient Create(const std::array<double, 3>& x_y_z) {
    return TemperatureGradient{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector{x_y_z})};
  }

  // Statically creates a temperature gradient vector with a given value expressed in a given
  // temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient Create(const Vector& value) {
    return TemperatureGradient{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  // Returns the x Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient x() const noexcept {
    return ScalarTemperatureGradient{value.x()};
  }

  // Returns the y Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient y() const noexcept {
    return ScalarTemperatureGradient{value.y()};
  }

  // Returns the z Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient z() const noexcept {
    return ScalarTemperatureGradient{value.z()};
  }

  // Returns the magnitude of this temperature gradient vector.
  [[nodiscard]] ScalarTemperatureGradient Magnitude() const {
    return ScalarTemperatureGradient{value.Magnitude()};
  }

  // Returns the direction of this temperature gradient vector.
  [[nodiscard]] PhQ::Direction Direction() const {
    return value.Direction();
  }

  // Returns the angle between this temperature gradient vector and another one.
  [[nodiscard]] PhQ::Angle Angle(const TemperatureGradient& temperature_gradient) const {
    return {*this, temperature_gradient};
  }

  constexpr TemperatureGradient operator+(const TemperatureGradient& temperature_gradient) const {
    return TemperatureGradient{value + temperature_gradient.value};
  }

  constexpr TemperatureGradient operator-(const TemperatureGradient& temperature_gradient) const {
    return TemperatureGradient{value - temperature_gradient.value};
  }

  constexpr TemperatureGradient operator*(const double number) const {
    return TemperatureGradient{value * number};
  }

  constexpr TemperatureGradient operator/(const double number) const {
    return TemperatureGradient{value / number};
  }

  constexpr void operator+=(const TemperatureGradient& temperature_gradient) noexcept {
    value += temperature_gradient.value;
  }

  constexpr void operator-=(const TemperatureGradient& temperature_gradient) noexcept {
    value -= temperature_gradient.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a temperature gradient vector with a given value expressed in the
  // standard temperature gradient unit.
  explicit constexpr TemperatureGradient(const Vector& value)
    : DimensionalVector<Unit::TemperatureGradient>(value) {}
};

inline constexpr bool operator==(
    const TemperatureGradient& left, const TemperatureGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TemperatureGradient& left, const TemperatureGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TemperatureGradient& left, const TemperatureGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TemperatureGradient& left, const TemperatureGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TemperatureGradient& left, const TemperatureGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TemperatureGradient& left, const TemperatureGradient& right) noexcept {
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

inline constexpr TemperatureGradient Direction::operator*(
    const ScalarTemperatureGradient& scalar_temperature_gradient) const {
  return {scalar_temperature_gradient, *this};
}

inline constexpr TemperatureGradient ScalarTemperatureGradient::operator*(
    const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TemperatureGradient> {
  inline size_t operator()(const PhQ::TemperatureGradient& temperature_gradient) const {
    return hash<PhQ::Vector>()(temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_GRADIENT_HPP
