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

#ifndef PHQ_SCALAR_TEMPERATURE_GRADIENT_HPP
#define PHQ_SCALAR_TEMPERATURE_GRADIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename Number>
class PlanarDirection;

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename Number>
class PlanarTemperatureGradient;

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename Number>
class TemperatureGradient;

/// \brief Scalar temperature gradient component or magnitude of a temperature gradient vector. See
/// also PhQ::TemperatureGradient.
template <typename Number = double>
class ScalarTemperatureGradient : public DimensionalScalar<Unit::TemperatureGradient, Number> {
public:
  /// \brief Default constructor. Constructs a scalar temperature gradient with an uninitialized
  /// value.
  ScalarTemperatureGradient() = default;

  /// \brief Constructor. Constructs a scalar temperature gradient with a given value expressed in a
  /// given temperature gradient unit.
  ScalarTemperatureGradient(const Number value, const Unit::TemperatureGradient unit)
    : DimensionalScalar<Unit::TemperatureGradient, Number>(value, unit) {}

  /// \brief Constructor. Constructs a scalar temperature gradient from a given temperature
  /// difference and length using the definition of temperature gradient.
  constexpr ScalarTemperatureGradient(
      const TemperatureDifference<Number>& temperature_difference, const Length<Number>& length)
    : ScalarTemperatureGradient<Number>(temperature_difference.Value() / length.Value()) {}

  /// \brief Destructor. Destroys this scalar temperature gradient.
  ~ScalarTemperatureGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar temperature gradient by copying another one.
  constexpr ScalarTemperatureGradient(const ScalarTemperatureGradient<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar temperature gradient by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarTemperatureGradient(const ScalarTemperatureGradient<OtherNumber>& other)
    : ScalarTemperatureGradient(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar temperature gradient by moving another one.
  constexpr ScalarTemperatureGradient(ScalarTemperatureGradient<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar temperature gradient by copying another
  /// one.
  constexpr ScalarTemperatureGradient<Number>& operator=(
      const ScalarTemperatureGradient<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar temperature gradient by copying another
  /// one.
  template <typename OtherNumber>
  constexpr ScalarTemperatureGradient<Number>& operator=(
      const ScalarTemperatureGradient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar temperature gradient by moving another
  /// one.
  constexpr ScalarTemperatureGradient<Number>& operator=(
      ScalarTemperatureGradient<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar temperature gradient of zero.
  static constexpr ScalarTemperatureGradient<Number> Zero() {
    return ScalarTemperatureGradient<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a scalar temperature gradient with a given value expressed in a
  /// given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr ScalarTemperatureGradient<Number> Create(const Number value) {
    return ScalarTemperatureGradient<Number>{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  constexpr ScalarTemperatureGradient<Number> operator+(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const {
    return ScalarTemperatureGradient<Number>{this->value + scalar_temperature_gradient.value};
  }

  constexpr ScalarTemperatureGradient<Number> operator-(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const {
    return ScalarTemperatureGradient<Number>{this->value - scalar_temperature_gradient.value};
  }

  constexpr ScalarTemperatureGradient<Number> operator*(const Number number) const {
    return ScalarTemperatureGradient<Number>{this->value * number};
  }

  constexpr TemperatureDifference<Number> operator*(const Length<Number>& length) const {
    return TemperatureDifference<Number>{*this, length};
  }

  constexpr PlanarTemperatureGradient<Number> operator*(
      const PlanarDirection<Number>& planar_direction) const;

  constexpr TemperatureGradient<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarTemperatureGradient<Number> operator/(const Number number) const {
    return ScalarTemperatureGradient<Number>{this->value / number};
  }

  constexpr Number operator/(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const noexcept {
    return this->value / scalar_temperature_gradient.value;
  }

  constexpr void operator+=(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) noexcept {
    this->value += scalar_temperature_gradient.value;
  }

  constexpr void operator-=(
      const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) noexcept {
    this->value -= scalar_temperature_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar temperature gradient with a given value expressed in
  /// the standard temperature gradient unit.
  explicit constexpr ScalarTemperatureGradient(const Number value)
    : DimensionalScalar<Unit::TemperatureGradient, Number>(value) {}

  template <typename OtherNumber>
  friend class PlanarTemperatureGradient;

  template <typename OtherNumber>
  friend class TemperatureGradient;
};

template <typename Number>
inline constexpr bool operator==(const ScalarTemperatureGradient<Number>& left,
                                 const ScalarTemperatureGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const ScalarTemperatureGradient<Number>& left,
                                 const ScalarTemperatureGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const ScalarTemperatureGradient<Number>& left,
                                const ScalarTemperatureGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const ScalarTemperatureGradient<Number>& left,
                                const ScalarTemperatureGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const ScalarTemperatureGradient<Number>& left,
                                 const ScalarTemperatureGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const ScalarTemperatureGradient<Number>& left,
                                 const ScalarTemperatureGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) {
  stream << scalar_temperature_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarTemperatureGradient<Number> operator*(
    const Number number, const ScalarTemperatureGradient<Number>& scalar_temperature_gradient) {
  return scalar_temperature_gradient * number;
}

template <typename Number>
inline constexpr TemperatureDifference<Number>::TemperatureDifference(
    const ScalarTemperatureGradient<Number>& scalar_temperature_gradient,
    const Length<Number>& length)
  : TemperatureDifference<Number>(scalar_temperature_gradient.Value() * length.Value()) {}

template <typename Number>
inline constexpr ScalarTemperatureGradient<Number> TemperatureDifference<Number>::operator/(
    const Length<Number>& length) const {
  return ScalarTemperatureGradient<Number>{*this, length};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarTemperatureGradient<Number>> {
  inline size_t operator()(
      const PhQ::ScalarTemperatureGradient<Number>& scalar_temperature_gradient) const {
    return hash<Number>()(scalar_temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_TEMPERATURE_GRADIENT_HPP
