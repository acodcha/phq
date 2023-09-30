// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP

#include "Length.hpp"
#include "Power.hpp"
#include "Speed.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Energy consumption in transport, which is a measure of energy use per
// distance traveled. Note that energy per length results in units of force.
// Energy consumption in transport is often measured in joules per metre (J/m)
// or kilowatt-hours per kilometre (kW·hr/km).
class TransportEnergyConsumption
  : public DimensionalScalarQuantity<Unit::Force> {
public:
  TransportEnergyConsumption() = default;

  TransportEnergyConsumption(const double value, const Unit::Force unit)
    : DimensionalScalarQuantity<Unit::Force>(value, unit) {}

  constexpr TransportEnergyConsumption(
      const Length& length, const Energy& energy)
    : TransportEnergyConsumption(energy.Value() / length.Value()) {}

  static constexpr TransportEnergyConsumption Zero() {
    return TransportEnergyConsumption{0.0};
  }

  template <Unit::Force Unit>
  static constexpr TransportEnergyConsumption Create(const double value) {
    return TransportEnergyConsumption{
        StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  constexpr TransportEnergyConsumption operator+(
      const TransportEnergyConsumption& transport_energy_consumption) const {
    return TransportEnergyConsumption{
        value_ + transport_energy_consumption.value_};
  }

  constexpr TransportEnergyConsumption operator-(
      const TransportEnergyConsumption& transport_energy_consumption) const {
    return TransportEnergyConsumption{
        value_ - transport_energy_consumption.value_};
  }

  constexpr TransportEnergyConsumption operator*(const double number) const {
    return TransportEnergyConsumption{value_ * number};
  }

  constexpr Energy operator*(const Length length) const {
    return Energy{length, *this};
  }

  constexpr Power operator*(const Speed speed) const {
    return Power{speed, *this};
  }

  constexpr TransportEnergyConsumption operator/(const double number) const {
    return TransportEnergyConsumption{value_ / number};
  }

  constexpr double
  operator/(const TransportEnergyConsumption& transport_energy_consumption)
      const noexcept {
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
  explicit constexpr TransportEnergyConsumption(const double value)
    : DimensionalScalarQuantity<Unit::Force>(value) {}
};

inline constexpr bool operator==(
    const TransportEnergyConsumption& left,
    const TransportEnergyConsumption& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TransportEnergyConsumption& left,
    const TransportEnergyConsumption& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TransportEnergyConsumption& left,
    const TransportEnergyConsumption& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TransportEnergyConsumption& left,
    const TransportEnergyConsumption& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TransportEnergyConsumption& left,
    const TransportEnergyConsumption& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TransportEnergyConsumption& left,
    const TransportEnergyConsumption& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const TransportEnergyConsumption& transport_energy_consumption) {
  stream << transport_energy_consumption.Print();
  return stream;
}

inline constexpr TransportEnergyConsumption operator*(
    const double number,
    const TransportEnergyConsumption& transport_energy_consumption) {
  return transport_energy_consumption * number;
}

inline constexpr Length::Length(
    const Energy& energy,
    const TransportEnergyConsumption& transport_energy_consumption)
  : Length(energy.Value() / transport_energy_consumption.Value()) {}

inline constexpr Energy::Energy(
    const Length& length,
    const TransportEnergyConsumption& transport_energy_consumption)
  : Energy(transport_energy_consumption.Value() * length.Value()) {}

inline constexpr Power::Power(
    const Speed& speed,
    const TransportEnergyConsumption& transport_energy_consumption)
  : Power(speed.Value() * transport_energy_consumption.Value()) {}

inline constexpr Energy Length::operator*(
    const TransportEnergyConsumption& transport_energy_consumption) const {
  return {*this, transport_energy_consumption};
}

inline constexpr Power Speed::operator*(
    const TransportEnergyConsumption& transport_energy_consumption) const {
  return {*this, transport_energy_consumption};
}

inline constexpr TransportEnergyConsumption Energy::operator/(
    const Length& length) const {
  return {length, *this};
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
      const PhQ::TransportEnergyConsumption& transport_energy_consumption)
      const {
    return hash<double>()(transport_energy_consumption.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
