// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

#ifndef PHQ_PLANAR_TEMPERATURE_GRADIENT_HPP
#define PHQ_PLANAR_TEMPERATURE_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "ScalarTemperatureGradient.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

/// \brief Two-dimensional Euclidean temperature gradient vector in the XY plane. Contains two
/// components in Cartesian coordinates: x and y. For a three-dimensional Euclidean temperature
/// gradient vector, see PhQ::TemperatureGradient. For scalar temperature gradient components or for
/// the magnitude of a temperature gradient vector, see PhQ::ScalarTemperatureGradient.
template <typename Number = double>
class PlanarTemperatureGradient
  : public DimensionalPlanarVector<Unit::TemperatureGradient, Number> {
public:
  /// \brief Default constructor. Constructs a planar temperature gradient vector with an
  /// uninitialized value.
  PlanarTemperatureGradient() = default;

  /// \brief Constructor. Constructs a planar temperature gradient vector with a given value
  /// expressed in a given temperature gradient unit.
  PlanarTemperatureGradient(const PlanarVector<Number>& value, const Unit::TemperatureGradient unit)
    : DimensionalPlanarVector<Unit::TemperatureGradient, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar temperature gradient vector from a given scalar
  /// temperature gradient magnitude and planar direction.
  constexpr PlanarTemperatureGradient(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient,
      const PlanarDirection<Number>& planar_direction)
    : PlanarTemperatureGradient<Number>(
        scalar_temperature_gradient.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar temperature gradient vector from a given temperature
  /// gradient vector by projecting the temperature gradient vector onto the XY plane.
  explicit constexpr PlanarTemperatureGradient(
      const TemperatureGradient<Number>& temperature_gradient);

  /// \brief Destructor. Destroys this planar temperature gradient vector.
  ~PlanarTemperatureGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a planar temperature gradient vector by copying another
  /// one.
  constexpr PlanarTemperatureGradient(const PlanarTemperatureGradient<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar temperature gradient vector by copying another
  /// one.
  template <typename OtherNumber>
  explicit constexpr PlanarTemperatureGradient(const PlanarTemperatureGradient<OtherNumber>& other)
    : PlanarTemperatureGradient(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar temperature gradient vector by moving another
  /// one.
  constexpr PlanarTemperatureGradient(PlanarTemperatureGradient<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar temperature gradient vector by copying
  /// another one.
  constexpr PlanarTemperatureGradient<Number>& operator=(
      const PlanarTemperatureGradient<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar temperature gradient vector by copying
  /// another one.
  template <typename OtherNumber>
  constexpr PlanarTemperatureGradient<Number>& operator=(
      const PlanarTemperatureGradient<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar temperature gradient vector by moving
  /// another one.
  constexpr PlanarTemperatureGradient<Number>& operator=(
      PlanarTemperatureGradient<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar temperature gradient vector of zero.
  static constexpr PlanarTemperatureGradient<Number> Zero() {
    return PlanarTemperatureGradient<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar temperature gradient vector from the given x and y
  /// Cartesian components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr PlanarTemperatureGradient<Number> Create(const Number x, const Number y) {
    return PlanarTemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar temperature gradient vector from the given x and y
  /// Cartesian components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr PlanarTemperatureGradient<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarTemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar temperature gradient vector with a given value expressed in
  /// a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr PlanarTemperatureGradient<Number> Create(const PlanarVector<Number>& value) {
    return PlanarTemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  /// \brief Returns the x Cartesian component of this planar temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> x() const noexcept {
    return ScalarTemperatureGradient<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<Number> y() const noexcept {
    return ScalarTemperatureGradient<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar temperature gradient vector.
  [[nodiscard]] ScalarTemperatureGradient<Number> Magnitude() const {
    return ScalarTemperatureGradient<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar temperature gradient vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar temperature gradient vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(
      const PlanarTemperatureGradient<Number>& planar_temperature_gradient) const {
    return PhQ::Angle<Number>{*this, planar_temperature_gradient};
  }

  constexpr PlanarTemperatureGradient<Number> operator+(
      const PlanarTemperatureGradient<Number>& planar_temperature_gradient) const {
    return PlanarTemperatureGradient<Number>{this->value + planar_temperature_gradient.value};
  }

  constexpr PlanarTemperatureGradient<Number> operator-(
      const PlanarTemperatureGradient<Number>& planar_temperature_gradient) const {
    return PlanarTemperatureGradient<Number>{this->value - planar_temperature_gradient.value};
  }

  constexpr PlanarTemperatureGradient<Number> operator*(const Number number) const {
    return PlanarTemperatureGradient<Number>{this->value * number};
  }

  constexpr PlanarTemperatureGradient<Number> operator/(const Number number) const {
    return PlanarTemperatureGradient<Number>{this->value / number};
  }

  constexpr void operator+=(
      const PlanarTemperatureGradient<Number>& planar_temperature_gradient) noexcept {
    this->value += planar_temperature_gradient.value;
  }

  constexpr void operator-=(
      const PlanarTemperatureGradient<Number>& planar_temperature_gradient) noexcept {
    this->value -= planar_temperature_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar temperature gradient vector with a given value
  /// expressed in the standard temperature gradient unit.
  explicit constexpr PlanarTemperatureGradient(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::TemperatureGradient, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const PlanarTemperatureGradient<Number>& left,
                                 const PlanarTemperatureGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const PlanarTemperatureGradient<Number>& left,
                                 const PlanarTemperatureGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const PlanarTemperatureGradient<Number>& left,
                                const PlanarTemperatureGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const PlanarTemperatureGradient<Number>& left,
                                const PlanarTemperatureGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const PlanarTemperatureGradient<Number>& left,
                                 const PlanarTemperatureGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const PlanarTemperatureGradient<Number>& left,
                                 const PlanarTemperatureGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarTemperatureGradient<Number>& planar_temperature_gradient) {
  stream << planar_temperature_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarTemperatureGradient<Number> operator*(
    const Number number, const PlanarTemperatureGradient<Number>& planar_temperature_gradient) {
  return planar_temperature_gradient * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(
    const PlanarTemperatureGradient<Number>& planar_temperature_gradient)
  : PlanarDirection<Number>(planar_temperature_gradient.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarTemperatureGradient<Number>& planar_temperature_gradient_1,
                            const PlanarTemperatureGradient<Number>& planar_temperature_gradient_2)
  : Angle<Number>(planar_temperature_gradient_1.Value(), planar_temperature_gradient_2.Value()) {}

template <typename Number>
inline constexpr PlanarTemperatureGradient<Number> PlanarDirection<Number>::operator*(
    const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const {
  return PlanarTemperatureGradient<Number>{scalar_temperature_gradient, *this};
}

template <typename Number>
inline constexpr PlanarTemperatureGradient<Number> ScalarTemperatureGradient<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarTemperatureGradient<Number>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarTemperatureGradient<Number>> {
  inline size_t operator()(
      const PhQ::PlanarTemperatureGradient<Number>& planar_temperature_gradient) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_TEMPERATURE_GRADIENT_HPP
