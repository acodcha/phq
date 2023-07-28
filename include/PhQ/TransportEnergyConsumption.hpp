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

#include "Energy.hpp"
#include "Length.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Energy consumption in transport, which is a measure of energy use per
// distance traveled. Note that energy per length results in units of force.
// Energy consumption in transport is often measured in joules per metre (J/m)
// or kilowatt-hours per kilometre (kW·hr/km).
class TransportEnergyConsumption
  : public DimensionalScalarQuantity<Unit::Force> {
public:
  constexpr TransportEnergyConsumption() noexcept
    : DimensionalScalarQuantity<Unit::Force>() {}

  TransportEnergyConsumption(
      const double value, const Unit::Force unit) noexcept
    : DimensionalScalarQuantity<Unit::Force>(value, unit) {}

  constexpr TransportEnergyConsumption(
      const Length& length, const Energy& energy) noexcept
    : TransportEnergyConsumption(energy.Value() / length.Value()) {}

  template<Unit::Force Unit> static constexpr TransportEnergyConsumption Create(
      const double value) noexcept {
    return TransportEnergyConsumption{
        StaticConvertCopy<Unit::Force, Unit, StandardUnit<Unit::Force>>(value)};
  }

  inline constexpr TransportEnergyConsumption
  operator+(const TransportEnergyConsumption& transport_energy_consumption)
      const noexcept {
    return TransportEnergyConsumption{
        value_ + transport_energy_consumption.value_};
  }

  inline constexpr TransportEnergyConsumption
  operator-(const TransportEnergyConsumption& transport_energy_consumption)
      const noexcept {
    return TransportEnergyConsumption{
        value_ - transport_energy_consumption.value_};
  }

  inline constexpr TransportEnergyConsumption operator*(
      const double number) const noexcept {
    return TransportEnergyConsumption{value_ * number};
  }

  inline constexpr Energy operator*(const Length length) const noexcept {
    return Energy{length, *this};
  }

  inline constexpr TransportEnergyConsumption operator/(
      const double number) const noexcept {
    return TransportEnergyConsumption{value_ / number};
  }

  inline constexpr void operator+=(
      const TransportEnergyConsumption& transport_energy_consumption) noexcept {
    value_ += transport_energy_consumption.value_;
  }

  inline constexpr void operator-=(
      const TransportEnergyConsumption& transport_energy_consumption) noexcept {
    value_ -= transport_energy_consumption.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TransportEnergyConsumption(const double value) noexcept
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
    const TransportEnergyConsumption& transport_energy_consumption) noexcept {
  stream << transport_energy_consumption.Print();
  return stream;
}

inline constexpr TransportEnergyConsumption operator*(
    const double number,
    const TransportEnergyConsumption& transport_energy_consumption) noexcept {
  return transport_energy_consumption * number;
}

inline constexpr Length::Length(
    const Energy& energy,
    const TransportEnergyConsumption& transport_energy_consumption) noexcept
  : Length(energy.Value() / transport_energy_consumption.Value()) {}

inline constexpr Energy::Energy(
    const Length& length,
    const TransportEnergyConsumption& transport_energy_consumption) noexcept
  : Energy(transport_energy_consumption.Value() * length.Value()) {}

inline constexpr TransportEnergyConsumption Energy::operator/(
    const Length& length) const noexcept {
  return {length, *this};
}

inline constexpr Length Energy::operator/(
    const TransportEnergyConsumption& transport_energy_consumption)
    const noexcept {
  return {*this, transport_energy_consumption};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::TransportEnergyConsumption> {
  size_t operator()(
      const PhQ::TransportEnergyConsumption& transport_energy_consumption)
      const {
    return hash<double>()(transport_energy_consumption.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TRANSPORT_ENERGY_CONSUMPTION_HPP
