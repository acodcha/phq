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

#ifndef PHQ_TEMPERATURE_HPP
#define PHQ_TEMPERATURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

// Temperature.
template <typename Number = double>
class Temperature : public DimensionalScalar<Unit::Temperature, Number> {
public:
  // Default constructor. Constructs a temperature with an uninitialized value.
  Temperature() = default;

  // Constructor. Constructs a temperature with a given value expressed in a given temperature unit.
  Temperature(const Number value, const Unit::Temperature unit)
    : DimensionalScalar<Unit::Temperature, Number>(value, unit) {}

  // Destructor. Destroys this temperature.
  ~Temperature() noexcept = default;

  // Copy constructor. Constructs a temperature by copying another one.
  constexpr Temperature(const Temperature<Number>& other) = default;

  // Copy constructor. Constructs a temperature by copying another one.
  template <typename OtherNumber>
  explicit constexpr Temperature(const Temperature<OtherNumber>& other)
    : Temperature(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a temperature by moving another one.
  constexpr Temperature(Temperature<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this temperature by copying another one.
  constexpr Temperature<Number>& operator=(const Temperature<Number>& other) = default;

  // Copy assignment operator. Assigns this temperature by copying another one.
  template <typename OtherNumber>
  constexpr Temperature<Number>& operator=(const Temperature<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this temperature by moving another one.
  constexpr Temperature<Number>& operator=(Temperature<Number>&& other) noexcept = default;

  // Statically creates a temperature of absolute zero.
  static constexpr Temperature<Number> Zero() {
    return Temperature<Number>{static_cast<Number>(0)};
  }

  // Statically creates a temperature with a given value expressed in a given temperature unit.
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
  // Constructor. Constructs a temperature with a given value expressed in the standard temperature
  // unit.
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
  return Temperature<Number>{value + temperature.Value()};
}

template <typename Number>
inline constexpr Temperature<Number> TemperatureDifference<Number>::operator-(
    const Temperature<Number>& temperature) const {
  return Temperature<Number>{value - temperature.Value()};
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
