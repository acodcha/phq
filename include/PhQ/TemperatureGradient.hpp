// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Temperature gradient vector. See also PhQ::ScalarTemperatureGradient.
template <typename Number = double>
class TemperatureGradient : public DimensionalVector<Unit::TemperatureGradient, Number> {
public:
  /// \brief Default constructor. Constructs a temperature gradient vector with an uninitialized
  /// value.
  TemperatureGradient() = default;

  /// \brief Constructor. Constructs a temperature gradient vector with a given value expressed in a
  /// given temperature gradient unit.
  TemperatureGradient(const Vector<Number>& value, const Unit::TemperatureGradient unit)
    : DimensionalVector<Unit::TemperatureGradient, Number>(value, unit) {}

  /// \brief Constructor. Constructs a temperature gradient vector from a given scalar temperature
  /// gradient magnitude and direction.
  constexpr TemperatureGradient(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient,
      const Direction<Number>& direction)
    : TemperatureGradient<Number>(scalar_temperature_gradient.Value() * direction.Value()) {}

  /// \brief Destructor. Destroys this temperature gradient vector.
  ~TemperatureGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a temperature gradient vector by copying another one.
  constexpr TemperatureGradient(const TemperatureGradient<Number>& other) = default;

  /// \brief Copy constructor. Constructs a temperature gradient vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr TemperatureGradient(const TemperatureGradient<OtherNumber>& other)
    : TemperatureGradient(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a temperature gradient vector by moving another one.
  constexpr TemperatureGradient(TemperatureGradient<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this temperature gradient vector by copying another
  /// one.
  constexpr TemperatureGradient<Number>& operator=(
      const TemperatureGradient<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this temperature gradient vector by copying another
  /// one.
  template <typename OtherNumber>
  constexpr TemperatureGradient<Number>& operator=(const TemperatureGradient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this temperature gradient vector by moving another
  /// one.
  constexpr TemperatureGradient<Number>& operator=(
      TemperatureGradient<Number>&& other) noexcept = default;

  /// \brief Statically creates a temperature gradient vector of zero.
  static constexpr TemperatureGradient<Number> Zero() {
    return TemperatureGradient<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  /// components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<Number> Create(
      const Number x, const Number y, const Number z) {
    return TemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  /// components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<Number> Create(const std::array<Number, 3>& x_y_z) {
    return TemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a temperature gradient vector with a given value expressed in a
  /// given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<Number> Create(const Vector<Number>& value) {
    return TemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  /// \brief Returns the x Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> x() const noexcept {
    return ScalarTemperatureGradient<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> y() const noexcept {
    return ScalarTemperatureGradient<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> z() const noexcept {
    return ScalarTemperatureGradient<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this temperature gradient vector.
  [[nodiscard]] ScalarTemperatureGradient<Number> Magnitude() const {
    return ScalarTemperatureGradient<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this temperature gradient vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this temperature gradient vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(
      const TemperatureGradient<Number>& temperature_gradient) const {
    return PhQ::Angle<Number>{*this, temperature_gradient};
  }

  constexpr TemperatureGradient<Number> operator+(
      const TemperatureGradient<Number>& temperature_gradient) const {
    return TemperatureGradient<Number>{this->value + temperature_gradient.value};
  }

  constexpr TemperatureGradient<Number> operator-(
      const TemperatureGradient<Number>& temperature_gradient) const {
    return TemperatureGradient<Number>{this->value - temperature_gradient.value};
  }

  constexpr TemperatureGradient<Number> operator*(const Number number) const {
    return TemperatureGradient<Number>{this->value * number};
  }

  constexpr TemperatureGradient<Number> operator/(const Number number) const {
    return TemperatureGradient<Number>{this->value / number};
  }

  constexpr void operator+=(const TemperatureGradient<Number>& temperature_gradient) noexcept {
    this->value += temperature_gradient.value;
  }

  constexpr void operator-=(const TemperatureGradient<Number>& temperature_gradient) noexcept {
    this->value -= temperature_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a temperature gradient vector with a given value expressed in
  /// the standard temperature gradient unit.
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
