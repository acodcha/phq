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

#ifndef PHQ_TEMPERATURE_HPP
#define PHQ_TEMPERATURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

/// \brief Temperature. For a temperature difference, see PhQ::TemperatureDifference. For the
/// gradient of temperature, see PhQ::TemperatureGradient.
template <typename Number = double>
class Temperature : public DimensionalScalar<Unit::Temperature, Number> {
public:
  /// \brief Default constructor. Constructs a temperature with an uninitialized value.
  Temperature() = default;

  /// \brief Constructor. Constructs a temperature with a given value expressed in a given
  /// temperature unit.
  Temperature(const Number value, const Unit::Temperature unit)
    : DimensionalScalar<Unit::Temperature, Number>(value, unit) {}

  /// \brief Destructor. Destroys this temperature.
  ~Temperature() noexcept = default;

  /// \brief Copy constructor. Constructs a temperature by copying another one.
  constexpr Temperature(const Temperature<Number>& other) = default;

  /// \brief Copy constructor. Constructs a temperature by copying another one.
  template <typename OtherNumber>
  explicit constexpr Temperature(const Temperature<OtherNumber>& other)
    : Temperature(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a temperature by moving another one.
  constexpr Temperature(Temperature<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this temperature by copying another one.
  constexpr Temperature<Number>& operator=(const Temperature<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this temperature by copying another one.
  template <typename OtherNumber>
  constexpr Temperature<Number>& operator=(const Temperature<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this temperature by moving another one.
  constexpr Temperature<Number>& operator=(Temperature<Number>&& other) noexcept = default;

  /// \brief Statically creates a temperature of absolute zero.
  static constexpr Temperature<Number> Zero() {
    return Temperature<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a temperature with a given value expressed in a given temperature
  /// unit.
  template <Unit::Temperature Unit>
  static constexpr Temperature<Number> Create(const Number value) {
    return Temperature<Number>{
        StaticConvertCopy<Unit::Temperature, Unit, Standard<Unit::Temperature>>(value)};
  }

  constexpr Temperature<Number> operator+(const Temperature<Number>& temperature) const {
    return Temperature<Number>{this->value + temperature.value};
  }

  constexpr Temperature<Number> operator+(
      const TemperatureDifference<Number>& temperature_difference) const {
    return Temperature<Number>{this->value + temperature_difference.Value()};
  }

  constexpr TemperatureDifference<Number> operator-(const Temperature<Number>& temperature) const {
    return TemperatureDifference<Number>{this->value - temperature.value};
  }

  constexpr Temperature<Number> operator-(
      const TemperatureDifference<Number>& temperature_difference) const {
    return Temperature<Number>{this->value - temperature_difference.Value()};
  }

  constexpr Temperature<Number> operator*(const Number number) const {
    return Temperature<Number>{this->value * number};
  }

  constexpr Temperature<Number> operator/(const Number number) const {
    return Temperature<Number>{this->value / number};
  }

  constexpr Number operator/(const Temperature<Number>& temperature) const noexcept {
    return this->value / temperature.value;
  }

  constexpr void operator+=(const Temperature<Number>& temperature) noexcept {
    this->value += temperature.value;
  }

  constexpr void operator+=(const TemperatureDifference<Number>& temperature_difference) noexcept {
    this->value += temperature_difference.Value();
  }

  constexpr void operator-=(const Temperature<Number>& temperature) noexcept {
    this->value -= temperature.value;
  }

  constexpr void operator-=(const TemperatureDifference<Number>& temperature_difference) noexcept {
    this->value -= temperature_difference.Value();
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a temperature with a given value expressed in the standard
  /// temperature unit.
  explicit constexpr Temperature(const Number value)
    : DimensionalScalar<Unit::Temperature, Number>(value) {}

  template <typename OtherNumber>
  friend class TemperatureDifference;
};

template <typename Number>
inline constexpr bool operator==(
    const Temperature<Number>& left, const Temperature<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Temperature<Number>& left, const Temperature<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Temperature<Number>& left, const Temperature<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Temperature<Number>& left, const Temperature<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Temperature<Number>& left, const Temperature<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Temperature<Number>& left, const Temperature<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Temperature<Number>& temperature) {
  stream << temperature.Print();
  return stream;
}

template <typename Number>
inline constexpr Temperature<Number> operator*(
    const Number number, const Temperature<Number>& temperature) {
  return temperature * number;
}

template <typename Number>
inline constexpr Temperature<Number> TemperatureDifference<Number>::operator+(
    const Temperature<Number>& temperature) const {
  return Temperature<Number>{this->value + temperature.Value()};
}

template <typename Number>
inline constexpr Temperature<Number> TemperatureDifference<Number>::operator-(
    const Temperature<Number>& temperature) const {
  return Temperature<Number>{this->value - temperature.Value()};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Temperature<Number>> {
  inline size_t operator()(const PhQ::Temperature<Number>& temperature) const {
    return hash<Number>()(temperature.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_HPP
