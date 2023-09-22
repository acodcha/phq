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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ENERGY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ENERGY_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declaration for class Energy.
class Frequency;

// Forward declaration for class Energy.
class Length;

// Forward declaration for class Energy.
class Mass;

// Forward declaration for class Energy.
class Power;

// Forward declaration for class Energy.
class SpecificEnergy;

// Forward declaration for class Energy.
class SpecificPower;

// Forward declaration for class Energy.
class Time;

// Forward declaration for class Energy.
class TransportEnergyConsumption;

// Energy.
class Energy : public DimensionalScalarQuantity<Unit::Energy> {
public:
  constexpr Energy() : DimensionalScalarQuantity<Unit::Energy>() {}

  Energy(const double value, const Unit::Energy unit)
    : DimensionalScalarQuantity<Unit::Energy>(value, unit) {}

  constexpr Energy(const Power& power, const Time& time);

  constexpr Energy(const Power& power, const Frequency& frequency);

  constexpr Energy(const SpecificEnergy& specific_energy, const Mass& mass);

  constexpr Energy(
      const Length& length,
      const TransportEnergyConsumption& transport_energy_consumption);

  static constexpr Energy Zero() {
    return Energy{0.0};
  }

  template <Unit::Energy Unit>
  static constexpr Energy Create(const double value) {
    return Energy{
        StaticConvertCopy<Unit::Energy, Unit, Standard<Unit::Energy>>(value)};
  }

  constexpr Energy operator+(const Energy& energy) const {
    return Energy{value_ + energy.value_};
  }

  constexpr Energy operator-(const Energy& energy) const {
    return Energy{value_ - energy.value_};
  }

  constexpr Energy operator*(const double number) const {
    return Energy{value_ * number};
  }

  constexpr Power operator*(const Frequency& frequency) const;

  constexpr Energy operator/(const double number) const {
    return Energy{value_ / number};
  }

  constexpr Power operator/(const Time& time) const;

  constexpr Time operator/(const Power& power) const;

  constexpr SpecificEnergy operator/(const Mass& mass) const;

  constexpr Mass operator/(const SpecificEnergy& specific_energy) const;

  constexpr TransportEnergyConsumption operator/(const Length& length) const;

  constexpr Length operator/(
      const TransportEnergyConsumption& transport_energy_consumption) const;

  constexpr double operator/(const Energy& energy) const noexcept {
    return value_ / energy.value_;
  }

  constexpr void operator+=(const Energy& energy) noexcept {
    value_ += energy.value_;
  }

  constexpr void operator-=(const Energy& energy) noexcept {
    value_ -= energy.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Energy(const double value)
    : DimensionalScalarQuantity<Unit::Energy>(value) {}
};

inline constexpr bool operator==(
    const Energy& left, const Energy& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Energy& left, const Energy& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Energy& left, const Energy& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Energy& left, const Energy& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Energy& left, const Energy& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Energy& left, const Energy& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Energy& energy) {
  stream << energy.Print();
  return stream;
}

inline constexpr Energy operator*(const double number, const Energy& energy) {
  return energy * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Energy> {
  inline size_t operator()(const PhQ::Energy& energy) const {
    return hash<double>()(energy.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ENERGY_HPP
