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
template <typename NumericType>
class ElectricCurrent;

// Forward declaration for class PhQ::ElectricCharge.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::ElectricCharge.
template <typename NumericType>
class Time;

/// \brief Electric charge.
template <typename NumericType = double>
class ElectricCharge : public DimensionalScalar<Unit::ElectricCharge, NumericType> {
public:
  /// \brief Default constructor. Constructs an electric charge with an uninitialized value.
  ElectricCharge() = default;

  /// \brief Constructor. Constructs an electric charge with a given value expressed in a given
  /// electric charge unit.
  ElectricCharge(const NumericType value, const Unit::ElectricCharge unit)
    : DimensionalScalar<Unit::ElectricCharge, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an electric charge from a given electric current and time using
  /// the definition of electric current.
  constexpr ElectricCharge(
      const ElectricCurrent<NumericType>& electric_current, const Time<NumericType>& time);

  /// \brief Constructor. Constructs an electric charge from a given electric current and frequency
  /// using the definition of electric current.
  constexpr ElectricCharge(const ElectricCurrent<NumericType>& electric_current,
                           const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this electric charge.
  ~ElectricCharge() noexcept = default;

  /// \brief Copy constructor. Constructs an electric charge by copying another one.
  constexpr ElectricCharge(const ElectricCharge<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an electric charge by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ElectricCharge(const ElectricCharge<OtherNumericType>& other)
    : ElectricCharge(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an electric charge by moving another one.
  constexpr ElectricCharge(ElectricCharge<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this electric charge by copying another one.
  constexpr ElectricCharge<NumericType>& operator=(
      const ElectricCharge<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this electric charge by copying another one.
  template <typename OtherNumericType>
  constexpr ElectricCharge<NumericType>& operator=(const ElectricCharge<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this electric charge by moving another one.
  constexpr ElectricCharge<NumericType>& operator=(
      ElectricCharge<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an electric charge of zero.
  static constexpr ElectricCharge<NumericType> Zero() {
    return ElectricCharge<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an electric charge with a given value expressed in a given electric
  /// charge unit.
  template <Unit::ElectricCharge Unit>
  static constexpr ElectricCharge<NumericType> Create(const NumericType value) {
    return ElectricCharge<NumericType>{
        ConvertStatically<Unit::ElectricCharge, Unit, Standard<Unit::ElectricCharge>>(value)};
  }

  constexpr ElectricCharge<NumericType> operator+(
      const ElectricCharge<NumericType>& electric_charge) const {
    return ElectricCharge<NumericType>{this->value + electric_charge.value};
  }

  constexpr ElectricCharge<NumericType> operator-(
      const ElectricCharge<NumericType>& electric_charge) const {
    return ElectricCharge<NumericType>{this->value - electric_charge.value};
  }

  constexpr ElectricCharge<NumericType> operator*(const NumericType number) const {
    return ElectricCharge<NumericType>{this->value * number};
  }

  constexpr ElectricCurrent<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr ElectricCharge<NumericType> operator/(const NumericType number) const {
    return ElectricCharge<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const ElectricCharge<NumericType>& electric_charge) const noexcept {
    return this->value / electric_charge.value;
  }

  constexpr ElectricCurrent<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const ElectricCurrent<NumericType>& electric_current) const;

  constexpr void operator+=(const ElectricCharge<NumericType>& electric_charge) noexcept {
    this->value += electric_charge.value;
  }

  constexpr void operator-=(const ElectricCharge<NumericType>& electric_charge) noexcept {
    this->value -= electric_charge.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an electric charge with a given value expressed in the standard
  /// electric charge unit.
  explicit constexpr ElectricCharge(const NumericType value)
    : DimensionalScalar<Unit::ElectricCharge, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const ElectricCharge<NumericType>& left, const ElectricCharge<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ElectricCharge<NumericType>& left, const ElectricCharge<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ElectricCharge<NumericType>& left, const ElectricCharge<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ElectricCharge<NumericType>& left, const ElectricCharge<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ElectricCharge<NumericType>& left, const ElectricCharge<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ElectricCharge<NumericType>& left, const ElectricCharge<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ElectricCharge<NumericType>& electric_charge) {
  stream << electric_charge.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ElectricCharge<NumericType> operator*(
    const NumericType number, const ElectricCharge<NumericType>& electric_charge) {
  return electric_charge * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ElectricCharge<NumericType>> {
  inline size_t operator()(const PhQ::ElectricCharge<NumericType>& electric_charge) const {
    return hash<NumericType>()(electric_charge.Value());
  }
};

}  // namespace std

#endif  // PHQ_ELECTRIC_CHARGE_HPP
