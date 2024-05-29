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

#ifndef PHQ_ELECTRIC_CURRENT_HPP
#define PHQ_ELECTRIC_CURRENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "ElectricCharge.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/ElectricCurrent.hpp"

namespace PhQ {

/// \brief Electric current, also known as amperage. Represents a flow of electric charge or a time
/// rate of change of electric charge.
template <typename Number = double>
class ElectricCurrent : public DimensionalScalar<Unit::ElectricCurrent, Number> {
public:
  /// \brief Default constructor. Constructs an electric current with an uninitialized value.
  ElectricCurrent() = default;

  /// \brief Constructor. Constructs an electric current with a given value expressed in a given
  /// electric current unit.
  ElectricCurrent(const Number value, const Unit::ElectricCurrent unit)
    : DimensionalScalar<Unit::ElectricCurrent, Number>(value, unit) {}

  /// \brief Constructor. Constructs an electric current from a given electric charge and time using
  /// the definition of electric current.
  constexpr ElectricCurrent(const ElectricCharge<Number>& electric_charge, const Time<Number>& time)
    : ElectricCurrent<Number>(electric_charge.Value() / time.Value()) {}

  /// \brief Constructor. Constructs an electric current from a given electric charge and frequency
  /// using the definition of electric current.
  constexpr ElectricCurrent(
      const ElectricCharge<Number>& electric_charge, const Frequency<Number>& frequency)
    : ElectricCurrent<Number>(electric_charge.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this electric current.
  ~ElectricCurrent() noexcept = default;

  /// \brief Copy constructor. Constructs an electric current by copying another one.
  constexpr ElectricCurrent(const ElectricCurrent<Number>& other) = default;

  /// \brief Copy constructor. Constructs an electric current by copying another one.
  template <typename OtherNumber>
  explicit constexpr ElectricCurrent(const ElectricCurrent<OtherNumber>& other)
    : ElectricCurrent(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an electric current by moving another one.
  constexpr ElectricCurrent(ElectricCurrent<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this electric current by copying another one.
  constexpr ElectricCurrent<Number>& operator=(const ElectricCurrent<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this electric current by copying another one.
  template <typename OtherNumber>
  constexpr ElectricCurrent<Number>& operator=(const ElectricCurrent<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this electric current by moving another one.
  constexpr ElectricCurrent<Number>& operator=(ElectricCurrent<Number>&& other) noexcept = default;

  /// \brief Statically creates an electric current of zero.
  static constexpr ElectricCurrent<Number> Zero() {
    return ElectricCurrent<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an electric current with a given value expressed in a given electric
  /// current unit.
  template <Unit::ElectricCurrent Unit>
  static constexpr ElectricCurrent<Number> Create(const Number value) {
    return ElectricCurrent<Number>{
        StaticConvertCopy<Unit::ElectricCurrent, Unit, Standard<Unit::ElectricCurrent>>(value)};
  }

  constexpr ElectricCurrent<Number> operator+(
      const ElectricCurrent<Number>& electric_current) const {
    return ElectricCurrent<Number>{this->value + electric_current.value};
  }

  constexpr ElectricCurrent<Number> operator-(
      const ElectricCurrent<Number>& electric_current) const {
    return ElectricCurrent<Number>{this->value - electric_current.value};
  }

  constexpr ElectricCurrent<Number> operator*(const Number number) const {
    return ElectricCurrent<Number>{this->value * number};
  }

  constexpr ElectricCharge<Number> operator*(const Time<Number>& time) const {
    return ElectricCharge<Number>{*this, time};
  }

  constexpr ElectricCurrent<Number> operator/(const Number number) const {
    return ElectricCurrent<Number>{this->value / number};
  }

  constexpr Number operator/(const ElectricCurrent<Number>& electric_current) const noexcept {
    return this->value / electric_current.value;
  }

  constexpr ElectricCharge<Number> operator/(const Frequency<Number>& frequency) const {
    return ElectricCharge<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const ElectricCharge<Number>& electric_charge) const {
    return Frequency<Number>{*this, electric_charge};
  }

  constexpr void operator+=(const ElectricCurrent<Number>& electric_current) noexcept {
    this->value += electric_current.value;
  }

  constexpr void operator-=(const ElectricCurrent<Number>& electric_current) noexcept {
    this->value -= electric_current.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an electric current with a given value expressed in the
  /// standard electric current unit.
  explicit constexpr ElectricCurrent(const Number value)
    : DimensionalScalar<Unit::ElectricCurrent, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const ElectricCurrent<Number>& left, const ElectricCurrent<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ElectricCurrent<Number>& left, const ElectricCurrent<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ElectricCurrent<Number>& left, const ElectricCurrent<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ElectricCurrent<Number>& left, const ElectricCurrent<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ElectricCurrent<Number>& left, const ElectricCurrent<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ElectricCurrent<Number>& left, const ElectricCurrent<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ElectricCurrent<Number>& electric_current) {
  stream << electric_current.Print();
  return stream;
}

template <typename Number>
inline constexpr ElectricCurrent<Number> operator*(
    const Number number, const ElectricCurrent<Number>& electric_current) {
  return electric_current * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(
    const ElectricCharge<Number>& electric_charge, const ElectricCurrent<Number>& electric_current)
  : Time<Number>(electric_charge.Value() / electric_current.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const ElectricCurrent<Number>& electric_current, const ElectricCharge<Number>& electric_charge)
  : Frequency<Number>(electric_current.Value() / electric_charge.Value()) {}

template <typename Number>
inline constexpr ElectricCharge<Number>::ElectricCharge(
    const ElectricCurrent<Number>& electric_current, const Time<Number>& time)
  : ElectricCharge<Number>(electric_current.Value() * time.Value()) {}

template <typename Number>
inline constexpr ElectricCharge<Number>::ElectricCharge(
    const ElectricCurrent<Number>& electric_current, const Frequency<Number>& frequency)
  : ElectricCharge<Number>(electric_current.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr ElectricCharge<Number> Time<Number>::operator*(
    const ElectricCurrent<Number>& electric_current) const {
  return ElectricCharge<Number>{electric_current, *this};
}

template <typename Number>
inline constexpr ElectricCurrent<Number> Frequency<Number>::operator*(
    const ElectricCharge<Number>& electric_charge) const {
  return ElectricCurrent<Number>{electric_charge, *this};
}

template <typename Number>
inline constexpr ElectricCurrent<Number> ElectricCharge<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return ElectricCurrent<Number>{*this, frequency};
}

template <typename Number>
inline constexpr ElectricCurrent<Number> ElectricCharge<Number>::operator/(
    const Time<Number>& time) const {
  return ElectricCurrent<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> ElectricCharge<Number>::operator/(
    const ElectricCurrent<Number>& electric_current) const {
  return Time<Number>{*this, electric_current};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ElectricCurrent<Number>> {
  inline size_t operator()(const PhQ::ElectricCurrent<Number>& electric_current) const {
    return hash<Number>()(electric_current.Value());
  }
};

}  // namespace std

#endif  // PHQ_ELECTRIC_CURRENT_HPP
