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

#ifndef PHQ_POWER_HPP
#define PHQ_POWER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Energy.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/Power.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Power.
template <typename NumericType>
class Speed;

// Forward declaration for class PhQ::Power.
template <typename NumericType>
class TransportEnergyConsumption;

/// \brief Power. Time rate of change of energy or energy transfer rate; see PhQ::Energy, PhQ::Time,
/// and PhQ::Frequency.
template <typename NumericType = double>
class Power : public DimensionalScalar<Unit::Power, NumericType> {
public:
  /// \brief Default constructor. Constructs a power quantity with an uninitialized value.
  Power() = default;

  /// \brief Constructor. Constructs a power quantity with a given value expressed in a given power
  /// unit.
  Power(const NumericType value, const Unit::Power unit)
    : DimensionalScalar<Unit::Power, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a power quantity from a given energy and time duration using
  /// the definition of power.
  constexpr Power(const Energy<NumericType>& energy, const Time<NumericType>& time)
    : Power<NumericType>(energy.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a power quantity from a given energy and frequency using the
  /// definition of power.
  constexpr Power(const Energy<NumericType>& energy, const Frequency<NumericType>& frequency)
    : Power<NumericType>(energy.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a power quantity from a given specific power and mass using the
  /// definition of specific power.
  constexpr Power(const SpecificPower<NumericType>& specific_power, const Mass<NumericType>& mass);

  /// \brief Constructor. Constructs a power quantity from a given transport energy consumption and
  /// speed using the definition of transport energy consumption.
  constexpr Power(const TransportEnergyConsumption<NumericType>& transport_energy_consumption,
                  const Speed<NumericType>& speed);

  /// \brief Destructor. Destroys this power quantity.
  ~Power() noexcept = default;

  /// \brief Copy constructor. Constructs a power quantity by copying another one.
  constexpr Power(const Power<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a power quantity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Power(const Power<OtherNumericType>& other)
    : Power(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a power quantity by moving another one.
  constexpr Power(Power<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this power quantity by copying another one.
  constexpr Power<NumericType>& operator=(const Power<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this power quantity by copying another one.
  template <typename OtherNumericType>
  constexpr Power<NumericType>& operator=(const Power<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this power quantity by moving another one.
  constexpr Power<NumericType>& operator=(Power<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a power quantity of zero.
  static constexpr Power<NumericType> Zero() {
    return Power<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a power quantity with a given value expressed in a given power unit.
  template <Unit::Power Unit>
  static constexpr Power<NumericType> Create(const NumericType value) {
    return Power<NumericType>{ConvertStatically<Unit::Power, Unit, Standard<Unit::Power>>(value)};
  }

  constexpr Power<NumericType> operator+(const Power<NumericType>& power) const {
    return Power<NumericType>{this->value + power.value};
  }

  constexpr Power<NumericType> operator-(const Power<NumericType>& power) const {
    return Power<NumericType>{this->value - power.value};
  }

  constexpr Power<NumericType> operator*(const NumericType number) const {
    return Power<NumericType>{this->value * number};
  }

  constexpr Energy<NumericType> operator*(const Time<NumericType>& time) const {
    return Energy<NumericType>{*this, time};
  }

  constexpr Power<NumericType> operator/(const NumericType number) const {
    return Power<NumericType>{this->value / number};
  }

  constexpr Energy<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Energy<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const Energy<NumericType>& energy) const {
    return Frequency<NumericType>{*this, energy};
  }

  constexpr SpecificPower<NumericType> operator/(const Mass<NumericType>& mass) const;

  constexpr Mass<NumericType> operator/(const SpecificPower<NumericType>& specific_power) const;

  constexpr NumericType operator/(const Power<NumericType>& power) const noexcept {
    return this->value / power.value;
  }

  constexpr void operator+=(const Power<NumericType>& power) noexcept {
    this->value += power.value;
  }

  constexpr void operator-=(const Power<NumericType>& power) noexcept {
    this->value -= power.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a power quantity with a given value expressed in the standard
  /// power unit.
  explicit constexpr Power(const NumericType value)
    : DimensionalScalar<Unit::Power, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Power<NumericType>& left, const Power<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Power<NumericType>& left, const Power<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Power<NumericType>& left, const Power<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Power<NumericType>& left, const Power<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Power<NumericType>& left, const Power<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Power<NumericType>& left, const Power<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Power<NumericType>& power) {
  stream << power.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Power<NumericType> operator*(
    const NumericType number, const Power<NumericType>& power) {
  return power * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Energy<NumericType>& energy, const Power<NumericType>& power)
  : Time<NumericType>(energy.Value() / power.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const Power<NumericType>& power, const Energy<NumericType>& energy)
  : Frequency<NumericType>(power.Value() / energy.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType>::Energy(
    const Power<NumericType>& power, const Time<NumericType>& time)
  : Energy<NumericType>(power.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType>::Energy(
    const Power<NumericType>& power, const Frequency<NumericType>& frequency)
  : Energy<NumericType>(power.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType> Time<NumericType>::operator*(
    const Power<NumericType>& power) const {
  return Energy<NumericType>{power, *this};
}

template <typename NumericType>
inline constexpr Power<NumericType> Frequency<NumericType>::operator*(
    const Energy<NumericType>& energy) const {
  return Power<NumericType>{energy, *this};
}

template <typename NumericType>
inline constexpr Power<NumericType> Energy<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return Power<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr Power<NumericType> Energy<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return Power<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> Energy<NumericType>::operator/(
    const Power<NumericType>& power) const {
  return Time<NumericType>{*this, power};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Power<NumericType>> {
  inline size_t operator()(const PhQ::Power<NumericType>& power) const {
    return hash<NumericType>()(power.Value());
  }
};

}  // namespace std

#endif  // PHQ_POWER_HPP
