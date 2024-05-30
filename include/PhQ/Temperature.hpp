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
template <typename NumericType = double>
class Temperature : public DimensionalScalar<Unit::Temperature, NumericType> {
public:
  /// \brief Default constructor. Constructs a temperature with an uninitialized value.
  Temperature() = default;

  /// \brief Constructor. Constructs a temperature with a given value expressed in a given
  /// temperature unit.
  Temperature(const NumericType value, const Unit::Temperature unit)
    : DimensionalScalar<Unit::Temperature, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this temperature.
  ~Temperature() noexcept = default;

  /// \brief Copy constructor. Constructs a temperature by copying another one.
  constexpr Temperature(const Temperature<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a temperature by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Temperature(const Temperature<OtherNumericType>& other)
    : Temperature(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a temperature by moving another one.
  constexpr Temperature(Temperature<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this temperature by copying another one.
  constexpr Temperature<NumericType>& operator=(const Temperature<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this temperature by copying another one.
  template <typename OtherNumericType>
  constexpr Temperature<NumericType>& operator=(const Temperature<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this temperature by moving another one.
  constexpr Temperature<NumericType>& operator=(
      Temperature<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a temperature of absolute zero.
  static constexpr Temperature<NumericType> Zero() {
    return Temperature<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a temperature with a given value expressed in a given temperature
  /// unit.
  template <Unit::Temperature Unit>
  static constexpr Temperature<NumericType> Create(const NumericType value) {
    return Temperature<NumericType>{
        StaticConvertCopy<Unit::Temperature, Unit, Standard<Unit::Temperature>>(value)};
  }

  constexpr Temperature<NumericType> operator+(const Temperature<NumericType>& temperature) const {
    return Temperature<NumericType>{this->value + temperature.value};
  }

  constexpr Temperature<NumericType> operator+(
      const TemperatureDifference<NumericType>& temperature_difference) const {
    return Temperature<NumericType>{this->value + temperature_difference.Value()};
  }

  constexpr TemperatureDifference<NumericType> operator-(
      const Temperature<NumericType>& temperature) const {
    return TemperatureDifference<NumericType>{this->value - temperature.value};
  }

  constexpr Temperature<NumericType> operator-(
      const TemperatureDifference<NumericType>& temperature_difference) const {
    return Temperature<NumericType>{this->value - temperature_difference.Value()};
  }

  constexpr Temperature<NumericType> operator*(const NumericType number) const {
    return Temperature<NumericType>{this->value * number};
  }

  constexpr Temperature<NumericType> operator/(const NumericType number) const {
    return Temperature<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const Temperature<NumericType>& temperature) const noexcept {
    return this->value / temperature.value;
  }

  constexpr void operator+=(const Temperature<NumericType>& temperature) noexcept {
    this->value += temperature.value;
  }

  constexpr void operator+=(
      const TemperatureDifference<NumericType>& temperature_difference) noexcept {
    this->value += temperature_difference.Value();
  }

  constexpr void operator-=(const Temperature<NumericType>& temperature) noexcept {
    this->value -= temperature.value;
  }

  constexpr void operator-=(
      const TemperatureDifference<NumericType>& temperature_difference) noexcept {
    this->value -= temperature_difference.Value();
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a temperature with a given value expressed in the standard
  /// temperature unit.
  explicit constexpr Temperature(const NumericType value)
    : DimensionalScalar<Unit::Temperature, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class TemperatureDifference;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Temperature<NumericType>& left, const Temperature<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Temperature<NumericType>& left, const Temperature<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Temperature<NumericType>& left, const Temperature<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Temperature<NumericType>& left, const Temperature<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Temperature<NumericType>& left, const Temperature<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Temperature<NumericType>& left, const Temperature<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Temperature<NumericType>& temperature) {
  stream << temperature.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Temperature<NumericType> operator*(
    const NumericType number, const Temperature<NumericType>& temperature) {
  return temperature * number;
}

template <typename NumericType>
inline constexpr Temperature<NumericType> TemperatureDifference<NumericType>::operator+(
    const Temperature<NumericType>& temperature) const {
  return Temperature<NumericType>{this->value + temperature.Value()};
}

template <typename NumericType>
inline constexpr Temperature<NumericType> TemperatureDifference<NumericType>::operator-(
    const Temperature<NumericType>& temperature) const {
  return Temperature<NumericType>{this->value - temperature.Value()};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Temperature<NumericType>> {
  inline size_t operator()(const PhQ::Temperature<NumericType>& temperature) const {
    return hash<NumericType>()(temperature.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_HPP
