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
template <typename Number = double>
class TemperatureGradient : public DimensionalVector<Unit::TemperatureGradient, Number> {
public:
  // Default constructor. Constructs a temperature gradient vector with an uninitialized value.
  TemperatureGradient() = default;

  // Constructor. Constructs a temperature gradient vector with a given value expressed in a given
  // temperature gradient unit.
  TemperatureGradient(const Vector<Number>& value, const Unit::TemperatureGradient unit)
    : DimensionalVector<Unit::TemperatureGradient, Number>(value, unit) {}

  // Constructor. Constructs a temperature gradient vector from a given scalar temperature gradient
  // magnitude and direction.
  constexpr TemperatureGradient(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient,
      const Direction<Number>& direction)
    : TemperatureGradient<Number>(scalar_temperature_gradient.Value() * direction.Value()) {}

  // Destructor. Destroys this temperature gradient vector.
  ~TemperatureGradient() noexcept = default;

  // Copy constructor. Constructs a temperature gradient vector by copying another one.
  constexpr TemperatureGradient(const TemperatureGradient<Number>& other) = default;

  // Copy constructor. Constructs a temperature gradient vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr TemperatureGradient(const TemperatureGradient<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a temperature gradient vector by moving another one.
  constexpr TemperatureGradient(TemperatureGradient<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this temperature gradient vector by copying another one.
  constexpr TemperatureGradient<Number>& operator=(
      const TemperatureGradient<Number>& other) = default;

  // Copy assignment operator. Assigns this temperature gradient vector by copying another one.
  template <typename OtherNumber>
  constexpr TemperatureGradient<Number>& operator=(const TemperatureGradient<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this temperature gradient vector by moving another one.
  constexpr TemperatureGradient<Number>& operator=(
      TemperatureGradient<Number>&& other) noexcept = default;

  // Statically creates a temperature gradient vector of zero.
  static constexpr TemperatureGradient<Number> Zero() {
    return TemperatureGradient<Number>{Vector<Number>::Zero()};
  }

  // Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  // components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<Number> Create(
      const Number x, const Number y, const Number z) {
    return TemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector<Number>{x, y, z})};
  }

  // Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  // components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<Number> Create(const std::array<Number, 3>& x_y_z) {
    return TemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector<Number>{x_y_z})};
  }

  // Statically creates a temperature gradient vector with a given value expressed in a given
  // temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<Number> Create(const Vector<Number>& value) {
    return TemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  // Returns the x Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> x() const noexcept {
    return ScalarTemperatureGradient<Number>{value.x()};
  }

  // Returns the y Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> y() const noexcept {
    return ScalarTemperatureGradient<Number>{value.y()};
  }

  // Returns the z Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> z() const noexcept {
    return ScalarTemperatureGradient<Number>{value.z()};
  }

  // Returns the magnitude of this temperature gradient vector.
  [[nodiscard]] ScalarTemperatureGradient<Number> Magnitude() const {
    return ScalarTemperatureGradient<Number>{value.Magnitude()};
  }

  // Returns the direction of this temperature gradient vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return value.Direction();
  }

  // Returns the angle between this temperature gradient vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(
      const TemperatureGradient<Number>& temperature_gradient) const {
    return PhQ::Angle<Number>{*this, temperature_gradient};
  }

  constexpr TemperatureGradient<Number> operator+(
      const TemperatureGradient<Number>& temperature_gradient) const {
    return TemperatureGradient<Number>{value + temperature_gradient.value};
  }

  constexpr TemperatureGradient<Number> operator-(
      const TemperatureGradient<Number>& temperature_gradient) const {
    return TemperatureGradient<Number>{value - temperature_gradient.value};
  }

  constexpr TemperatureGradient<Number> operator*(const Number number) const {
    return TemperatureGradient<Number>{value * number};
  }

  constexpr TemperatureGradient<Number> operator/(const Number number) const {
    return TemperatureGradient<Number>{value / number};
  }

  constexpr void operator+=(const TemperatureGradient<Number>& temperature_gradient) noexcept {
    value += temperature_gradient.value;
  }

  constexpr void operator-=(const TemperatureGradient<Number>& temperature_gradient) noexcept {
    value -= temperature_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a temperature gradient vector with a given value expressed in the
  // standard temperature gradient unit.
  explicit constexpr TemperatureGradient(const Vector<Number>& value)
    : DimensionalVector<Unit::TemperatureGradient, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const TemperatureGradient<Number>& left, const TemperatureGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const TemperatureGradient<Number>& left, const TemperatureGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const TemperatureGradient<Number>& left, const TemperatureGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const TemperatureGradient<Number>& left, const TemperatureGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const TemperatureGradient<Number>& left, const TemperatureGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const TemperatureGradient<Number>& left, const TemperatureGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const TemperatureGradient<Number>& temperature_gradient) {
  stream << temperature_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr TemperatureGradient<Number> operator*(
    const Number number, const TemperatureGradient<Number>& temperature_gradient) {
  return temperature_gradient * number;
}

template <typename Number>
inline Direction<Number>::Direction(const TemperatureGradient<Number>& temperature_gradient)
  : Direction<Number>(temperature_gradient.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const TemperatureGradient<Number>& temperature_gradient_1,
                            const TemperatureGradient<Number>& temperature_gradient_2)
  : Angle<Number>(temperature_gradient_1.Value(), temperature_gradient_2.Value()) {}

template <typename Number>
inline constexpr TemperatureGradient<Number> Direction<Number>::operator*(
    const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const {
  return TemperatureGradient<Number>{scalar_temperature_gradient, *this};
}

template <typename Number>
inline constexpr TemperatureGradient<Number> ScalarTemperatureGradient<Number>::operator*(
    const Direction<Number>& direction) const {
  return TemperatureGradient<Number>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::TemperatureGradient<Number>> {
  inline size_t operator()(const PhQ::TemperatureGradient<Number>& temperature_gradient) const {
    return hash<PhQ::Vector<Number>>()(temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_GRADIENT_HPP
