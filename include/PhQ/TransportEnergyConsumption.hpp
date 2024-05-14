// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#ifndef PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
#define PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "Power.hpp"
#include "Speed.hpp"
#include "Unit/TransportEnergyConsumption.hpp"

namespace PhQ {

// Transport energy consumption, also known as energy consumption in transport. A measure of energy
// use per distance traveled. Energy consumption in transport is often measured in joules per metre
// (J/m), kilowatt-hours per kilometre (kW·hr/km), or kilowatt-hours per mile (kW·hr/mi).
template <typename Number = double>
class TransportEnergyConsumption
  : public DimensionalScalar<Unit::TransportEnergyConsumption, Number> {
public:
  // Default constructor. Constructs a transport energy consumption with an uninitialized value.
  TransportEnergyConsumption() = default;

  // Constructor. Constructs a transport energy consumption with a given value expressed in a given
  // transport energy consumption unit.
  TransportEnergyConsumption(const Number value, const Unit::TransportEnergyConsumption unit)
    : DimensionalScalar<Unit::TransportEnergyConsumption, Number>(value, unit) {}

  // Constructor. Constructs a transport energy consumption from a given energy and length using the
  // definition of transport energy consumption.
  constexpr TransportEnergyConsumption(const Energy<Number>& energy, const Length<Number>& length)
    : TransportEnergyConsumption<Number>(energy.Value() / length.Value()) {}

  // Destructor. Destroys this transport energy consumption.
  ~TransportEnergyConsumption() noexcept = default;

  // Copy constructor. Constructs a transport energy consumption by copying another one.
  constexpr TransportEnergyConsumption(const TransportEnergyConsumption<Number>& other) = default;

  // Copy constructor. Constructs a transport energy consumption by copying another one.
  template <typename OtherNumber>
  explicit constexpr TransportEnergyConsumption(
      const TransportEnergyConsumption<OtherNumber>& other)
    : TransportEnergyConsumption(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a transport energy consumption by moving another one.
  constexpr TransportEnergyConsumption(
      TransportEnergyConsumption<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this transport energy consumption by copying another one.
  constexpr TransportEnergyConsumption<Number>& operator=(
      const TransportEnergyConsumption<Number>& other) = default;

  // Copy assignment operator. Assigns this transport energy consumption by copying another one.
  template <typename OtherNumber>
  constexpr TransportEnergyConsumption<Number>& operator=(
      const TransportEnergyConsumption<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this transport energy consumption by moving another one.
  constexpr TransportEnergyConsumption<Number>& operator=(
      TransportEnergyConsumption<Number>&& other) noexcept = default;

  // Statically creates a transport energy consumption of zero.
  static constexpr TransportEnergyConsumption<Number> Zero() {
    return TransportEnergyConsumption<Number>{static_cast<Number>(0)};
  }

  // Statically creates a transport energy consumption with a given value expressed in a given
  // transport energy consumption unit.
  template <Unit::TransportEnergyConsumption Unit>
  static constexpr TransportEnergyConsumption<Number> Create(const Number value) {
    return TransportEnergyConsumption<Number>{
        StaticConvertCopy<Unit::TransportEnergyConsumption, Unit,
                          Standard<Unit::TransportEnergyConsumption>>(value)};
  }

  constexpr TransportEnergyConsumption<Number> operator+(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const {
    return TransportEnergyConsumption<Number>{this->value + transport_energy_consumption.value};
  }

  constexpr TransportEnergyConsumption<Number> operator-(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const {
    return TransportEnergyConsumption<Number>{this->value - transport_energy_consumption.value};
  }

  constexpr TransportEnergyConsumption<Number> operator*(const Number number) const {
    return TransportEnergyConsumption<Number>{this->value * number};
  }

  constexpr Energy<Number> operator*(const Length<Number> length) const {
    return Energy<Number>{*this, length};
  }

  constexpr Power<Number> operator*(const Speed<Number> speed) const {
    return Power<Number>{*this, speed};
  }

  constexpr TransportEnergyConsumption<Number> operator/(const Number number) const {
    return TransportEnergyConsumption<Number>{this->value / number};
  }

  constexpr Number operator/(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const noexcept {
    return this->value / transport_energy_consumption.value;
  }

  constexpr void operator+=(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) noexcept {
    this->value += transport_energy_consumption.value;
  }

  constexpr void operator-=(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) noexcept {
    this->value -= transport_energy_consumption.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a transport energy consumption with a given value expressed in the
  // standard transport energy consumption unit.
  explicit constexpr TransportEnergyConsumption(const Number value)
    : DimensionalScalar<Unit::TransportEnergyConsumption, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const TransportEnergyConsumption<Number>& left,
                                 const TransportEnergyConsumption<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const TransportEnergyConsumption<Number>& left,
                                 const TransportEnergyConsumption<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const TransportEnergyConsumption<Number>& left,
                                const TransportEnergyConsumption<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const TransportEnergyConsumption<Number>& left,
                                const TransportEnergyConsumption<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const TransportEnergyConsumption<Number>& left,
                                 const TransportEnergyConsumption<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const TransportEnergyConsumption<Number>& left,
                                 const TransportEnergyConsumption<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const TransportEnergyConsumption<Number>& transport_energy_consumption) {
  stream << transport_energy_consumption.Print();
  return stream;
}

template <typename Number>
inline constexpr TransportEnergyConsumption<Number> operator*(
    const Number number, const TransportEnergyConsumption<Number>& transport_energy_consumption) {
  return transport_energy_consumption * number;
}

template <typename Number>
inline constexpr Length<Number>::Length(
    const Energy<Number>& energy,
    const TransportEnergyConsumption<Number>& transport_energy_consumption)
  : Length<Number>(energy.Value() / transport_energy_consumption.Value()) {}

template <typename Number>
inline constexpr Energy<Number>::Energy(
    const TransportEnergyConsumption<Number>& transport_energy_consumption,
    const Length<Number>& length)
  : Energy<Number>(transport_energy_consumption.Value() * length.Value()) {}

template <typename Number>
inline constexpr Power<Number>::Power(
    const TransportEnergyConsumption<Number>& transport_energy_consumption,
    const Speed<Number>& speed)
  : Power<Number>(speed.Value() * transport_energy_consumption.Value()) {}

template <typename Number>
inline constexpr Energy<Number> Length<Number>::operator*(
    const TransportEnergyConsumption<Number>& transport_energy_consumption) const {
  return Energy<Number>{transport_energy_consumption, *this};
}

template <typename Number>
inline constexpr Power<Number> Speed<Number>::operator*(
    const TransportEnergyConsumption<Number>& transport_energy_consumption) const {
  return Power<Number>{transport_energy_consumption, *this};
}

template <typename Number>
inline constexpr TransportEnergyConsumption<Number> Energy<Number>::operator/(
    const Length<Number>& length) const {
  return TransportEnergyConsumption<Number>{*this, length};
}

template <typename Number>
inline constexpr Length<Number> Energy<Number>::operator/(
    const TransportEnergyConsumption<Number>& transport_energy_consumption) const {
  return Length<Number>{*this, transport_energy_consumption};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::TransportEnergyConsumption<Number>> {
  inline size_t operator()(
      const PhQ::TransportEnergyConsumption<Number>& transport_energy_consumption) const {
    return hash<Number>()(transport_energy_consumption.Value());
  }
};

}  // namespace std

#endif  // PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
