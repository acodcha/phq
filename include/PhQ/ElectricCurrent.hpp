// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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
template <typename NumericType = double>
class ElectricCurrent : public DimensionalScalar<Unit::ElectricCurrent, NumericType> {
public:
  /// \brief Default constructor. Constructs an electric current with an uninitialized value.
  ElectricCurrent() = default;

  /// \brief Constructor. Constructs an electric current with a given value expressed in a given
  /// electric current unit.
  ElectricCurrent(const NumericType value, const Unit::ElectricCurrent unit)
    : DimensionalScalar<Unit::ElectricCurrent, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an electric current from a given electric charge and time using
  /// the definition of electric current.
  constexpr ElectricCurrent(
      const ElectricCharge<NumericType>& electric_charge, const Time<NumericType>& time)
    : ElectricCurrent<NumericType>(electric_charge.Value() / time.Value()) {}

  /// \brief Constructor. Constructs an electric current from a given electric charge and frequency
  /// using the definition of electric current.
  constexpr ElectricCurrent(
      const ElectricCharge<NumericType>& electric_charge, const Frequency<NumericType>& frequency)
    : ElectricCurrent<NumericType>(electric_charge.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this electric current.
  ~ElectricCurrent() noexcept = default;

  /// \brief Copy constructor. Constructs an electric current by copying another one.
  constexpr ElectricCurrent(const ElectricCurrent<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an electric current by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ElectricCurrent(const ElectricCurrent<OtherNumericType>& other)
    : ElectricCurrent(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an electric current by moving another one.
  constexpr ElectricCurrent(ElectricCurrent<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this electric current by copying another one.
  constexpr ElectricCurrent<NumericType>& operator=(
      const ElectricCurrent<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this electric current by copying another one.
  template <typename OtherNumericType>
  constexpr ElectricCurrent<NumericType>& operator=(
      const ElectricCurrent<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this electric current by moving another one.
  constexpr ElectricCurrent<NumericType>& operator=(
      ElectricCurrent<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an electric current of zero.
  static constexpr ElectricCurrent<NumericType> Zero() {
    return ElectricCurrent<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an electric current with a given value expressed in a given electric
  /// current unit.
  template <Unit::ElectricCurrent Unit>
  static constexpr ElectricCurrent<NumericType> Create(const NumericType value) {
    return ElectricCurrent<NumericType>{
        ConvertStatically<Unit::ElectricCurrent, Unit, Standard<Unit::ElectricCurrent>>(value)};
  }

  constexpr ElectricCurrent<NumericType> operator+(
      const ElectricCurrent<NumericType>& electric_current) const {
    return ElectricCurrent<NumericType>{this->value + electric_current.value};
  }

  constexpr ElectricCurrent<NumericType> operator-(
      const ElectricCurrent<NumericType>& electric_current) const {
    return ElectricCurrent<NumericType>{this->value - electric_current.value};
  }

  constexpr ElectricCurrent<NumericType> operator*(const NumericType number) const {
    return ElectricCurrent<NumericType>{this->value * number};
  }

  constexpr ElectricCharge<NumericType> operator*(const Time<NumericType>& time) const {
    return ElectricCharge<NumericType>{*this, time};
  }

  constexpr ElectricCurrent<NumericType> operator/(const NumericType number) const {
    return ElectricCurrent<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const ElectricCurrent<NumericType>& electric_current) const noexcept {
    return this->value / electric_current.value;
  }

  constexpr ElectricCharge<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return ElectricCharge<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(
      const ElectricCharge<NumericType>& electric_charge) const {
    return Frequency<NumericType>{*this, electric_charge};
  }

  constexpr void operator+=(const ElectricCurrent<NumericType>& electric_current) noexcept {
    this->value += electric_current.value;
  }

  constexpr void operator-=(const ElectricCurrent<NumericType>& electric_current) noexcept {
    this->value -= electric_current.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an electric current with a given value expressed in the
  /// standard electric current unit.
  explicit constexpr ElectricCurrent(const NumericType value)
    : DimensionalScalar<Unit::ElectricCurrent, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const ElectricCurrent<NumericType>& left, const ElectricCurrent<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ElectricCurrent<NumericType>& left, const ElectricCurrent<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ElectricCurrent<NumericType>& left, const ElectricCurrent<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ElectricCurrent<NumericType>& left, const ElectricCurrent<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ElectricCurrent<NumericType>& left, const ElectricCurrent<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ElectricCurrent<NumericType>& left, const ElectricCurrent<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ElectricCurrent<NumericType>& electric_current) {
  stream << electric_current.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ElectricCurrent<NumericType> operator*(
    const NumericType number, const ElectricCurrent<NumericType>& electric_current) {
  return electric_current * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(const ElectricCharge<NumericType>& electric_charge,
                                         const ElectricCurrent<NumericType>& electric_current)
  : Time<NumericType>(electric_charge.Value() / electric_current.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const ElectricCurrent<NumericType>& electric_current,
    const ElectricCharge<NumericType>& electric_charge)
  : Frequency<NumericType>(electric_current.Value() / electric_charge.Value()) {}

template <typename NumericType>
inline constexpr ElectricCharge<NumericType>::ElectricCharge(
    const ElectricCurrent<NumericType>& electric_current, const Time<NumericType>& time)
  : ElectricCharge<NumericType>(electric_current.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr ElectricCharge<NumericType>::ElectricCharge(
    const ElectricCurrent<NumericType>& electric_current, const Frequency<NumericType>& frequency)
  : ElectricCharge<NumericType>(electric_current.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr ElectricCharge<NumericType> Time<NumericType>::operator*(
    const ElectricCurrent<NumericType>& electric_current) const {
  return ElectricCharge<NumericType>{electric_current, *this};
}

template <typename NumericType>
inline constexpr ElectricCurrent<NumericType> Frequency<NumericType>::operator*(
    const ElectricCharge<NumericType>& electric_charge) const {
  return ElectricCurrent<NumericType>{electric_charge, *this};
}

template <typename NumericType>
inline constexpr ElectricCurrent<NumericType> ElectricCharge<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return ElectricCurrent<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr ElectricCurrent<NumericType> ElectricCharge<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return ElectricCurrent<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> ElectricCharge<NumericType>::operator/(
    const ElectricCurrent<NumericType>& electric_current) const {
  return Time<NumericType>{*this, electric_current};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ElectricCurrent<NumericType>> {
  inline size_t operator()(const PhQ::ElectricCurrent<NumericType>& electric_current) const {
    return hash<NumericType>()(electric_current.Value());
  }
};

}  // namespace std

#endif  // PHQ_ELECTRIC_CURRENT_HPP
