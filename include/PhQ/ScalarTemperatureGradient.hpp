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

#ifndef PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP
#define PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP

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
class TemperatureGradient;

// Scalar temperature gradient component or magnitude of a temperature gradient vector. See also
// PhQ::TemperatureGradient.
template <typename Number = double>
class ScalarTemperatureGradient : public DimensionalScalar<Unit::TemperatureGradient, Number> {
public:
  // Default constructor. Constructs a scalar temperature gradient with an uninitialized value.
  ScalarTemperatureGradient() = default;

  // Constructor. Constructs a scalar temperature gradient with a given value expressed in a given
  // temperature gradient unit.
  ScalarTemperatureGradient(const Number value, const Unit::TemperatureGradient unit)
    : DimensionalScalar<Unit::TemperatureGradient, Number>(value, unit) {}

  // Constructor. Constructs a scalar temperature gradient from a given temperature difference and
  // length using the definition of temperature gradient.
  constexpr ScalarTemperatureGradient(
      const TemperatureDifference<Number>& temperature_difference, const Length<Number>& length)
    : ScalarTemperatureGradient<Number>(temperature_difference.Value() / length.Value()) {}

  // Destructor. Destroys this scalar temperature gradient.
  ~ScalarTemperatureGradient() noexcept = default;

  // Copy constructor. Constructs a scalar temperature gradient by copying another one.
  constexpr ScalarTemperatureGradient(const ScalarTemperatureGradient<Number>& other) = default;

  // Copy constructor. Constructs a scalar temperature gradient by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarTemperatureGradient(const ScalarTemperatureGradient<OtherNumber>& other)
    : ScalarTemperatureGradient(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar temperature gradient by moving another one.
  constexpr ScalarTemperatureGradient(ScalarTemperatureGradient<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar temperature gradient by copying another one.
  constexpr ScalarTemperatureGradient<Number>& operator=(
      const ScalarTemperatureGradient<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar temperature gradient by copying another one.
  template <typename OtherNumber>
  constexpr ScalarTemperatureGradient<Number>& operator=(
      const ScalarTemperatureGradient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar temperature gradient by moving another one.
  constexpr ScalarTemperatureGradient<Number>& operator=(
      ScalarTemperatureGradient<Number>&& other) noexcept = default;

  // Statically creates a scalar temperature gradient of zero.
  static constexpr ScalarTemperatureGradient<Number> Zero() {
    return ScalarTemperatureGradient<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar temperature gradient with a given value expressed in a given
  // temperature gradient unit.
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
  // Constructor. Constructs a scalar temperature gradient with a given value expressed in the
  // standard temperature gradient unit.
  explicit constexpr ScalarTemperatureGradient(const Number value)
    : DimensionalScalar<Unit::TemperatureGradient, Number>(value) {}

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

#endif  // PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP
