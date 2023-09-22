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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_POWER_HPP

#include "Energy.hpp"
#include "Frequency.hpp"
#include "Unit/Power.hpp"

namespace PhQ {

// Forward declarations for class Power.
class Speed;
class TransportEnergyConsumption;

// Power. Time rate of change of energy. Can also represent an energy transfer
// rate.
class Power : public DimensionalScalarQuantity<Unit::Power> {
public:
  constexpr Power() : DimensionalScalarQuantity<Unit::Power>() {}

  Power(const double value, const Unit::Power unit)
    : DimensionalScalarQuantity<Unit::Power>(value, unit) {}

  constexpr Power(const Energy& energy, const Time& time)
    : Power(energy.Value() / time.Value()) {}

  constexpr Power(const Energy& energy, const Frequency& frequency)
    : Power(energy.Value() * frequency.Value()) {}

  constexpr Power(const SpecificPower& specific_power, const Mass& mass);

  constexpr Power(
      const Speed& speed,
      const TransportEnergyConsumption& transport_energy_consumption);

  static constexpr Power Zero() {
    return Power{0.0};
  }

  template <Unit::Power Unit>
  static constexpr Power Create(const double value) {
    return Power{
        StaticConvertCopy<Unit::Power, Unit, Standard<Unit::Power>>(value)};
  }

  constexpr Power operator+(const Power& power) const {
    return Power{value_ + power.value_};
  }

  constexpr Power operator-(const Power& power) const {
    return Power{value_ - power.value_};
  }

  constexpr Power operator*(const double number) const {
    return Power{value_ * number};
  }

  constexpr Energy operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Power operator/(const double number) const {
    return Power{value_ / number};
  }

  constexpr Energy operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Energy& energy) const {
    return {*this, energy};
  }

  constexpr SpecificPower operator/(const Mass& mass) const;

  constexpr Mass operator/(const SpecificPower& specific_power) const;

  constexpr double operator/(const Power& power) const noexcept {
    return value_ / power.value_;
  }

  constexpr void operator+=(const Power& power) noexcept {
    value_ += power.value_;
  }

  constexpr void operator-=(const Power& power) noexcept {
    value_ -= power.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Power(const double value)
    : DimensionalScalarQuantity<Unit::Power>(value) {}
};

inline constexpr bool operator==(
    const Power& left, const Power& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Power& left, const Power& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Power& left, const Power& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Power& left, const Power& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Power& left, const Power& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Power& left, const Power& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Power& power) {
  stream << power.Print();
  return stream;
}

inline constexpr Power operator*(const double number, const Power& power) {
  return power * number;
}

inline constexpr Time::Time(const Power& power, const Energy& energy)
  : Time(energy.Value() / power.Value()) {}

inline constexpr Frequency::Frequency(const Power& power, const Energy& energy)
  : Frequency(power.Value() / energy.Value()) {}

inline constexpr Energy::Energy(const Power& power, const Time& time)
  : Energy(power.Value() * time.Value()) {}

inline constexpr Energy::Energy(const Power& power, const Frequency& frequency)
  : Energy(power.Value() / frequency.Value()) {}

inline constexpr Energy Time::operator*(const Power& power) const {
  return {power, *this};
}

inline constexpr Power Frequency::operator*(const Energy& energy) const {
  return {energy, *this};
}

inline constexpr Power Energy::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr Power Energy::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time Energy::operator/(const Power& power) const {
  return {power, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Power> {
  inline size_t operator()(const PhQ::Power& power) const {
    return hash<double>()(power.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_POWER_HPP
