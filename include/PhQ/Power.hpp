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
template <typename Number>
class Speed;

// Forward declaration for class PhQ::Power.
template <typename Number>
class TransportEnergyConsumption;

/// \brief Power. Time rate of change of energy or energy transfer rate; see PhQ::Energy, PhQ::Time,
/// and PhQ::Frequency.
template <typename Number = double>
class Power : public DimensionalScalar<Unit::Power, Number> {
public:
  /// \brief Default constructor. Constructs a power quantity with an uninitialized value.
  Power() = default;

  /// \brief Constructor. Constructs a power quantity with a given value expressed in a given power
  /// unit.
  Power(const Number value, const Unit::Power unit)
    : DimensionalScalar<Unit::Power, Number>(value, unit) {}

  /// \brief Constructor. Constructs a power quantity from a given energy and time duration using
  /// the definition of power.
  constexpr Power(const Energy<Number>& energy, const Time<Number>& time)
    : Power<Number>(energy.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a power quantity from a given energy and frequency using the
  /// definition of power.
  constexpr Power(const Energy<Number>& energy, const Frequency<Number>& frequency)
    : Power<Number>(energy.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a power quantity from a given specific power and mass using the
  /// definition of specific power.
  constexpr Power(const SpecificPower<Number>& specific_power, const Mass<Number>& mass);

  /// \brief Constructor. Constructs a power quantity from a given transport energy consumption and
  /// speed using the definition of transport energy consumption.
  constexpr Power(const TransportEnergyConsumption<Number>& transport_energy_consumption,
                  const Speed<Number>& speed);

  /// \brief Destructor. Destroys this power quantity.
  ~Power() noexcept = default;

  /// \brief Copy constructor. Constructs a power quantity by copying another one.
  constexpr Power(const Power<Number>& other) = default;

  /// \brief Copy constructor. Constructs a power quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Power(const Power<OtherNumber>& other)
    : Power(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a power quantity by moving another one.
  constexpr Power(Power<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this power quantity by copying another one.
  constexpr Power<Number>& operator=(const Power<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this power quantity by copying another one.
  template <typename OtherNumber>
  constexpr Power<Number>& operator=(const Power<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this power quantity by moving another one.
  constexpr Power<Number>& operator=(Power<Number>&& other) noexcept = default;

  /// \brief Statically creates a power quantity of zero.
  static constexpr Power<Number> Zero() {
    return Power<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a power quantity with a given value expressed in a given power unit.
  template <Unit::Power Unit>
  static constexpr Power<Number> Create(const Number value) {
    return Power<Number>{StaticConvertCopy<Unit::Power, Unit, Standard<Unit::Power>>(value)};
  }

  constexpr Power<Number> operator+(const Power<Number>& power) const {
    return Power<Number>{this->value + power.value};
  }

  constexpr Power<Number> operator-(const Power<Number>& power) const {
    return Power<Number>{this->value - power.value};
  }

  constexpr Power<Number> operator*(const Number number) const {
    return Power<Number>{this->value * number};
  }

  constexpr Energy<Number> operator*(const Time<Number>& time) const {
    return Energy<Number>{*this, time};
  }

  constexpr Power<Number> operator/(const Number number) const {
    return Power<Number>{this->value / number};
  }

  constexpr Energy<Number> operator/(const Frequency<Number>& frequency) const {
    return Energy<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Energy<Number>& energy) const {
    return Frequency<Number>{*this, energy};
  }

  constexpr SpecificPower<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(const SpecificPower<Number>& specific_power) const;

  constexpr Number operator/(const Power<Number>& power) const noexcept {
    return this->value / power.value;
  }

  constexpr void operator+=(const Power<Number>& power) noexcept {
    this->value += power.value;
  }

  constexpr void operator-=(const Power<Number>& power) noexcept {
    this->value -= power.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a power quantity with a given value expressed in the standard
  /// power unit.
  explicit constexpr Power(const Number value) : DimensionalScalar<Unit::Power, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Power<Number>& power) {
  stream << power.Print();
  return stream;
}

template <typename Number>
inline constexpr Power<Number> operator*(const Number number, const Power<Number>& power) {
  return power * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(const Energy<Number>& energy, const Power<Number>& power)
  : Time<Number>(energy.Value() / power.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const Power<Number>& power, const Energy<Number>& energy)
  : Frequency<Number>(power.Value() / energy.Value()) {}

template <typename Number>
inline constexpr Energy<Number>::Energy(const Power<Number>& power, const Time<Number>& time)
  : Energy<Number>(power.Value() * time.Value()) {}

template <typename Number>
inline constexpr Energy<Number>::Energy(
    const Power<Number>& power, const Frequency<Number>& frequency)
  : Energy<Number>(power.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Energy<Number> Time<Number>::operator*(const Power<Number>& power) const {
  return Energy<Number>{power, *this};
}

template <typename Number>
inline constexpr Power<Number> Frequency<Number>::operator*(const Energy<Number>& energy) const {
  return Power<Number>{energy, *this};
}

template <typename Number>
inline constexpr Power<Number> Energy<Number>::operator*(const Frequency<Number>& frequency) const {
  return Power<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Power<Number> Energy<Number>::operator/(const Time<Number>& time) const {
  return Power<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> Energy<Number>::operator/(const Power<Number>& power) const {
  return Time<Number>{*this, power};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Power<Number>> {
  inline size_t operator()(const PhQ::Power<Number>& power) const {
    return hash<Number>()(power.Value());
  }
};

}  // namespace std

#endif  // PHQ_POWER_HPP
