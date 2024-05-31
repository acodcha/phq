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

/// \brief Transport energy consumption, also known as energy consumption in transport. A measure of
/// energy use per distance traveled. Energy consumption in transport is often measured in joules
/// per metre (J/m), kilowatt-hours per kilometre (kW·hr/km), or kilowatt-hours per mile (kW·hr/mi).
template <typename NumericType = double>
class TransportEnergyConsumption
  : public DimensionalScalar<Unit::TransportEnergyConsumption, NumericType> {
public:
  /// \brief Default constructor. Constructs a transport energy consumption with an uninitialized
  /// value.
  TransportEnergyConsumption() = default;

  /// \brief Constructor. Constructs a transport energy consumption with a given value expressed in
  /// a given transport energy consumption unit.
  TransportEnergyConsumption(const NumericType value, const Unit::TransportEnergyConsumption unit)
    : DimensionalScalar<Unit::TransportEnergyConsumption, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a transport energy consumption from a given energy and length
  /// using the definition of transport energy consumption.
  constexpr TransportEnergyConsumption(
      const Energy<NumericType>& energy, const Length<NumericType>& length)
    : TransportEnergyConsumption<NumericType>(energy.Value() / length.Value()) {}

  /// \brief Destructor. Destroys this transport energy consumption.
  ~TransportEnergyConsumption() noexcept = default;

  /// \brief Copy constructor. Constructs a transport energy consumption by copying another one.
  constexpr TransportEnergyConsumption(
      const TransportEnergyConsumption<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a transport energy consumption by copying another one.
  template <typename OtherNumericType>
  explicit constexpr TransportEnergyConsumption(
      const TransportEnergyConsumption<OtherNumericType>& other)
    : TransportEnergyConsumption(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a transport energy consumption by moving another one.
  constexpr TransportEnergyConsumption(
      TransportEnergyConsumption<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this transport energy consumption by copying another
  /// one.
  constexpr TransportEnergyConsumption<NumericType>& operator=(
      const TransportEnergyConsumption<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this transport energy consumption by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr TransportEnergyConsumption<NumericType>& operator=(
      const TransportEnergyConsumption<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this transport energy consumption by moving another
  /// one.
  constexpr TransportEnergyConsumption<NumericType>& operator=(
      TransportEnergyConsumption<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a transport energy consumption of zero.
  static constexpr TransportEnergyConsumption<NumericType> Zero() {
    return TransportEnergyConsumption<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a transport energy consumption with a given value expressed in a
  /// given transport energy consumption unit.
  template <Unit::TransportEnergyConsumption Unit>
  static constexpr TransportEnergyConsumption<NumericType> Create(const NumericType value) {
    return TransportEnergyConsumption<NumericType>{
        ConvertStatically<Unit::TransportEnergyConsumption, Unit,
                          Standard<Unit::TransportEnergyConsumption>>(value)};
  }

  constexpr TransportEnergyConsumption<NumericType> operator+(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const {
    return TransportEnergyConsumption<NumericType>{
        this->value + transport_energy_consumption.value};
  }

  constexpr TransportEnergyConsumption<NumericType> operator-(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const {
    return TransportEnergyConsumption<NumericType>{
        this->value - transport_energy_consumption.value};
  }

  constexpr TransportEnergyConsumption<NumericType> operator*(const NumericType number) const {
    return TransportEnergyConsumption<NumericType>{this->value * number};
  }

  constexpr Energy<NumericType> operator*(const Length<NumericType> length) const {
    return Energy<NumericType>{*this, length};
  }

  constexpr Power<NumericType> operator*(const Speed<NumericType> speed) const {
    return Power<NumericType>{*this, speed};
  }

  constexpr TransportEnergyConsumption<NumericType> operator/(const NumericType number) const {
    return TransportEnergyConsumption<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const noexcept {
    return this->value / transport_energy_consumption.value;
  }

  constexpr void operator+=(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) noexcept {
    this->value += transport_energy_consumption.value;
  }

  constexpr void operator-=(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) noexcept {
    this->value -= transport_energy_consumption.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a transport energy consumption with a given value expressed in
  /// the standard transport energy consumption unit.
  explicit constexpr TransportEnergyConsumption(const NumericType value)
    : DimensionalScalar<Unit::TransportEnergyConsumption, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const TransportEnergyConsumption<NumericType>& left,
                                 const TransportEnergyConsumption<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const TransportEnergyConsumption<NumericType>& left,
                                 const TransportEnergyConsumption<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const TransportEnergyConsumption<NumericType>& left,
                                const TransportEnergyConsumption<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const TransportEnergyConsumption<NumericType>& left,
                                const TransportEnergyConsumption<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const TransportEnergyConsumption<NumericType>& left,
                                 const TransportEnergyConsumption<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const TransportEnergyConsumption<NumericType>& left,
                                 const TransportEnergyConsumption<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption) {
  stream << transport_energy_consumption.Print();
  return stream;
}

template <typename NumericType>
inline constexpr TransportEnergyConsumption<NumericType> operator*(
    const NumericType number,
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption) {
  return transport_energy_consumption * number;
}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const Energy<NumericType>& energy,
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption)
  : Length<NumericType>(energy.Value() / transport_energy_consumption.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType>::Energy(
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption,
    const Length<NumericType>& length)
  : Energy<NumericType>(transport_energy_consumption.Value() * length.Value()) {}

template <typename NumericType>
inline constexpr Power<NumericType>::Power(
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption,
    const Speed<NumericType>& speed)
  : Power<NumericType>(speed.Value() * transport_energy_consumption.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType> Length<NumericType>::operator*(
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const {
  return Energy<NumericType>{transport_energy_consumption, *this};
}

template <typename NumericType>
inline constexpr Power<NumericType> Speed<NumericType>::operator*(
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const {
  return Power<NumericType>{transport_energy_consumption, *this};
}

template <typename NumericType>
inline constexpr TransportEnergyConsumption<NumericType> Energy<NumericType>::operator/(
    const Length<NumericType>& length) const {
  return TransportEnergyConsumption<NumericType>{*this, length};
}

template <typename NumericType>
inline constexpr Length<NumericType> Energy<NumericType>::operator/(
    const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const {
  return Length<NumericType>{*this, transport_energy_consumption};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::TransportEnergyConsumption<NumericType>> {
  inline size_t operator()(
      const PhQ::TransportEnergyConsumption<NumericType>& transport_energy_consumption) const {
    return hash<NumericType>()(transport_energy_consumption.Value());
  }
};

}  // namespace std

#endif  // PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
