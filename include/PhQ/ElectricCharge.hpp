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

#ifndef PHQ_ELECTRIC_CHARGE_HPP
#define PHQ_ELECTRIC_CHARGE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/ElectricCharge.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ElectricCharge.
template <typename Number>
class ElectricCurrent;

// Forward declaration for class PhQ::ElectricCharge.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::ElectricCharge.
template <typename Number>
class Time;

/// \brief Electric charge.
template <typename Number = double>
class ElectricCharge : public DimensionalScalar<Unit::ElectricCharge, Number> {
public:
  /// \brief Default constructor. Constructs an electric charge with an uninitialized value.
  ElectricCharge() = default;

  /// \brief Constructor. Constructs an electric charge with a given value expressed in a given
  /// electric charge unit.
  ElectricCharge(const Number value, const Unit::ElectricCharge unit)
    : DimensionalScalar<Unit::ElectricCharge, Number>(value, unit) {}

  /// \brief Constructor. Constructs an electric charge from a given electric current and time using
  /// the definition of electric current.
  constexpr ElectricCharge(
      const ElectricCurrent<Number>& electric_current, const Time<Number>& time);

  /// \brief Constructor. Constructs an electric charge from a given electric current and frequency
  /// using the definition of electric current.
  constexpr ElectricCharge(
      const ElectricCurrent<Number>& electric_current, const Frequency<Number>& frequency);

  /// \brief Destructor. Destroys this electric charge.
  ~ElectricCharge() noexcept = default;

  /// \brief Copy constructor. Constructs an electric charge by copying another one.
  constexpr ElectricCharge(const ElectricCharge<Number>& other) = default;

  /// \brief Copy constructor. Constructs an electric charge by copying another one.
  template <typename OtherNumber>
  explicit constexpr ElectricCharge(const ElectricCharge<OtherNumber>& other)
    : ElectricCharge(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an electric charge by moving another one.
  constexpr ElectricCharge(ElectricCharge<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this electric charge by copying another one.
  constexpr ElectricCharge<Number>& operator=(const ElectricCharge<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this electric charge by copying another one.
  template <typename OtherNumber>
  constexpr ElectricCharge<Number>& operator=(const ElectricCharge<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this electric charge by moving another one.
  constexpr ElectricCharge<Number>& operator=(ElectricCharge<Number>&& other) noexcept = default;

  /// \brief Statically creates an electric charge of zero.
  static constexpr ElectricCharge<Number> Zero() {
    return ElectricCharge<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an electric charge with a given value expressed in a given electric
  /// charge unit.
  template <Unit::ElectricCharge Unit>
  static constexpr ElectricCharge<Number> Create(const Number value) {
    return ElectricCharge<Number>{
        StaticConvertCopy<Unit::ElectricCharge, Unit, Standard<Unit::ElectricCharge>>(value)};
  }

  constexpr ElectricCharge<Number> operator+(const ElectricCharge<Number>& electric_charge) const {
    return ElectricCharge<Number>{this->value + electric_charge.value};
  }

  constexpr ElectricCharge<Number> operator-(const ElectricCharge<Number>& electric_charge) const {
    return ElectricCharge<Number>{this->value - electric_charge.value};
  }

  constexpr ElectricCharge<Number> operator*(const Number number) const {
    return ElectricCharge<Number>{this->value * number};
  }

  constexpr ElectricCurrent<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr ElectricCharge<Number> operator/(const Number number) const {
    return ElectricCharge<Number>{this->value / number};
  }

  constexpr Number operator/(const ElectricCharge<Number>& electric_charge) const noexcept {
    return this->value / electric_charge.value;
  }

  constexpr ElectricCurrent<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const ElectricCurrent<Number>& electric_current) const;

  constexpr void operator+=(const ElectricCharge<Number>& electric_charge) noexcept {
    this->value += electric_charge.value;
  }

  constexpr void operator-=(const ElectricCharge<Number>& electric_charge) noexcept {
    this->value -= electric_charge.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an electric charge with a given value expressed in the standard
  /// electric charge unit.
  explicit constexpr ElectricCharge(const Number value)
    : DimensionalScalar<Unit::ElectricCharge, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const ElectricCharge<Number>& left, const ElectricCharge<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ElectricCharge<Number>& left, const ElectricCharge<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ElectricCharge<Number>& left, const ElectricCharge<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ElectricCharge<Number>& left, const ElectricCharge<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ElectricCharge<Number>& left, const ElectricCharge<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ElectricCharge<Number>& left, const ElectricCharge<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ElectricCharge<Number>& electric_charge) {
  stream << electric_charge.Print();
  return stream;
}

template <typename Number>
inline constexpr ElectricCharge<Number> operator*(
    const Number number, const ElectricCharge<Number>& electric_charge) {
  return electric_charge * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ElectricCharge<Number>> {
  inline size_t operator()(const PhQ::ElectricCharge<Number>& electric_charge) const {
    return hash<Number>()(electric_charge.Value());
  }
};

}  // namespace std

#endif  // PHQ_ELECTRIC_CHARGE_HPP
