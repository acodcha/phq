// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP

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
class TransportEnergyConsumption : public DimensionalScalar<Unit::TransportEnergyConsumption> {
public:
  // Default constructor. Constructs a transport energy consumption with an uninitialized value.
  TransportEnergyConsumption() = default;

  // Constructor. Constructs a transport energy consumption with a given value expressed in a given
  // transport energy consumption unit.
  TransportEnergyConsumption(const double value, const Unit::TransportEnergyConsumption unit)
    : DimensionalScalar<Unit::TransportEnergyConsumption>(value, unit) {}

  // Constructor. Constructs a transport energy consumption from a given energy and length using the
  // definition of transport energy consumption.
  constexpr TransportEnergyConsumption(const Energy& energy, const Length& length)
    : TransportEnergyConsumption(energy.Value() / length.Value()) {}

  // Destructor. Destroys this transport energy consumption.
  ~TransportEnergyConsumption() noexcept = default;

  // Copy constructor. Constructs a transport energy consumption by copying another one.
  constexpr TransportEnergyConsumption(const TransportEnergyConsumption& other) = default;

  // Move constructor. Constructs a transport energy consumption by moving another one.
  constexpr TransportEnergyConsumption(TransportEnergyConsumption&& other) noexcept = default;

  // Copy assignment operator. Assigns this transport energy consumption by copying another one.
  constexpr TransportEnergyConsumption& operator=(
      const TransportEnergyConsumption& other) = default;

  // Move assignment operator. Assigns this transport energy consumption by moving another one.
  constexpr TransportEnergyConsumption& operator=(
      TransportEnergyConsumption&& other) noexcept = default;

  // Statically creates a transport energy consumption of zero.
  static constexpr TransportEnergyConsumption Zero() {
    return TransportEnergyConsumption{0.0};
  }

  // Statically creates a transport energy consumption with a given value expressed in a given
  // transport energy consumption unit.
  template <Unit::TransportEnergyConsumption Unit>
  static constexpr TransportEnergyConsumption Create(const double value) {
    return TransportEnergyConsumption{
        StaticConvertCopy<Unit::TransportEnergyConsumption, Unit,
                          Standard<Unit::TransportEnergyConsumption>>(value)};
  }

  constexpr TransportEnergyConsumption operator+(
      const TransportEnergyConsumption& transport_energy_consumption) const {
    return TransportEnergyConsumption{value_ + transport_energy_consumption.value_};
  }

  constexpr TransportEnergyConsumption operator-(
      const TransportEnergyConsumption& transport_energy_consumption) const {
    return TransportEnergyConsumption{value_ - transport_energy_consumption.value_};
  }

  constexpr TransportEnergyConsumption operator*(const double number) const {
    return TransportEnergyConsumption{value_ * number};
  }

  constexpr Energy operator*(const Length length) const {
    return Energy{*this, length};
  }

  constexpr Power operator*(const Speed speed) const {
    return Power{*this, speed};
  }

  constexpr TransportEnergyConsumption operator/(const double number) const {
    return TransportEnergyConsumption{value_ / number};
  }

  constexpr double operator/(
      const TransportEnergyConsumption& transport_energy_consumption) const noexcept {
    return value_ / transport_energy_consumption.value_;
  }

  constexpr void operator+=(
      const TransportEnergyConsumption& transport_energy_consumption) noexcept {
    value_ += transport_energy_consumption.value_;
  }

  constexpr void operator-=(
      const TransportEnergyConsumption& transport_energy_consumption) noexcept {
    value_ -= transport_energy_consumption.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a transport energy consumption with a given value expressed in the
  // standard transport energy consumption unit.
  explicit constexpr TransportEnergyConsumption(const double value)
    : DimensionalScalar<Unit::TransportEnergyConsumption>(value) {}
};

inline constexpr bool operator==(
    const TransportEnergyConsumption& left, const TransportEnergyConsumption& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TransportEnergyConsumption& left, const TransportEnergyConsumption& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TransportEnergyConsumption& left, const TransportEnergyConsumption& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TransportEnergyConsumption& left, const TransportEnergyConsumption& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TransportEnergyConsumption& left, const TransportEnergyConsumption& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TransportEnergyConsumption& left, const TransportEnergyConsumption& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TransportEnergyConsumption& transport_energy_consumption) {
  stream << transport_energy_consumption.Print();
  return stream;
}

inline constexpr TransportEnergyConsumption operator*(
    const double number, const TransportEnergyConsumption& transport_energy_consumption) {
  return transport_energy_consumption * number;
}

inline constexpr Length::Length(
    const Energy& energy, const TransportEnergyConsumption& transport_energy_consumption)
  : Length(energy.Value() / transport_energy_consumption.Value()) {}

inline constexpr Energy::Energy(
    const TransportEnergyConsumption& transport_energy_consumption, const Length& length)
  : Energy(transport_energy_consumption.Value() * length.Value()) {}

inline constexpr Power::Power(
    const TransportEnergyConsumption& transport_energy_consumption, const Speed& speed)
  : Power(speed.Value() * transport_energy_consumption.Value()) {}

inline constexpr Energy Length::operator*(
    const TransportEnergyConsumption& transport_energy_consumption) const {
  return {transport_energy_consumption, *this};
}

inline constexpr Power Speed::operator*(
    const TransportEnergyConsumption& transport_energy_consumption) const {
  return {transport_energy_consumption, *this};
}

inline constexpr TransportEnergyConsumption Energy::operator/(const Length& length) const {
  return {*this, length};
}

inline constexpr Length Energy::operator/(
    const TransportEnergyConsumption& transport_energy_consumption) const {
  return {*this, transport_energy_consumption};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TransportEnergyConsumption> {
  inline size_t operator()(
      const PhQ::TransportEnergyConsumption& transport_energy_consumption) const {
    return hash<double>()(transport_energy_consumption.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
