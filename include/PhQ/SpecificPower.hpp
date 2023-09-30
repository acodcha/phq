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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP

#include "SpecificEnergy.hpp"
#include "Unit/SpecificPower.hpp"

namespace PhQ {

// Specific power. Power per unit mass.
class SpecificPower : public DimensionalScalarQuantity<Unit::SpecificPower> {
public:
  SpecificPower() = default;

  SpecificPower(const double value, const Unit::SpecificPower unit)
    : DimensionalScalarQuantity<Unit::SpecificPower>(value, unit) {}

  constexpr SpecificPower(
      const SpecificEnergy& specific_energy, const Time& time)
    : SpecificPower(specific_energy.Value() / time.Value()) {}

  constexpr SpecificPower(
      const SpecificEnergy& specific_energy, const Frequency& frequency)
    : SpecificPower(specific_energy.Value() * frequency.Value()) {}

  constexpr SpecificPower(const Power& power, const Mass& mass)
    : SpecificPower(power.Value() / mass.Value()) {}

  static constexpr SpecificPower Zero() {
    return SpecificPower{0.0};
  }

  template <Unit::SpecificPower Unit>
  static constexpr SpecificPower Create(const double value) {
    return SpecificPower{
        StaticConvertCopy<Unit::SpecificPower, Unit,
                          Standard<Unit::SpecificPower>>(value)};
  }

  constexpr SpecificPower operator+(const SpecificPower& specific_power) const {
    return SpecificPower{value_ + specific_power.value_};
  }

  constexpr SpecificPower operator-(const SpecificPower& specific_power) const {
    return SpecificPower{value_ - specific_power.value_};
  }

  constexpr SpecificPower operator*(const double number) const {
    return SpecificPower{value_ * number};
  }

  constexpr SpecificEnergy operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Power operator*(const Mass& mass) const {
    return {*this, mass};
  }

  constexpr SpecificPower operator/(const double number) const {
    return SpecificPower{value_ / number};
  }

  constexpr SpecificEnergy operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const SpecificEnergy& specific_energy) const {
    return {*this, specific_energy};
  }

  constexpr double operator/(
      const SpecificPower& specific_power) const noexcept {
    return value_ / specific_power.value_;
  }

  constexpr void operator+=(const SpecificPower& specific_power) noexcept {
    value_ += specific_power.value_;
  }

  constexpr void operator-=(const SpecificPower& specific_power) noexcept {
    value_ -= specific_power.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificPower(const double value)
    : DimensionalScalarQuantity<Unit::SpecificPower>(value) {}
};

inline constexpr bool operator==(
    const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const SpecificPower& specific_power) {
  stream << specific_power.Print();
  return stream;
}

inline constexpr SpecificPower operator*(
    const double number, const SpecificPower& specific_power) {
  return specific_power * number;
}

inline constexpr Time::Time(
    const SpecificPower& specific_power, const SpecificEnergy& specific_energy)
  : Time(specific_energy.Value() / specific_power.Value()) {}

inline constexpr Frequency::Frequency(
    const SpecificPower& specific_power, const SpecificEnergy& specific_energy)
  : Frequency(specific_power.Value() / specific_energy.Value()) {}

inline constexpr Mass::Mass(
    const SpecificPower& specific_power, const Power& power)
  : Mass(power.Value() / specific_power.Value()) {}

inline constexpr Power::Power(
    const SpecificPower& specific_power, const Mass& mass)
  : Power(specific_power.Value() * mass.Value()) {}

inline constexpr SpecificEnergy::SpecificEnergy(
    const SpecificPower& specific_power, const Time& time)
  : SpecificEnergy(specific_power.Value() * time.Value()) {}

inline constexpr SpecificEnergy::SpecificEnergy(
    const SpecificPower& specific_power, const Frequency& frequency)
  : SpecificEnergy(specific_power.Value() / frequency.Value()) {}

inline constexpr Power Mass::operator*(
    const SpecificPower& specific_power) const {
  return {specific_power, *this};
}

inline constexpr Mass Power::operator/(
    const SpecificPower& specific_power) const {
  return {specific_power, *this};
}

inline constexpr SpecificEnergy Time::operator*(
    const SpecificPower& specific_power) const {
  return {specific_power, *this};
}

inline constexpr SpecificPower Frequency::operator*(
    const SpecificEnergy& specific_energy) const {
  return {specific_energy, *this};
}

inline constexpr SpecificPower Power::operator/(const Mass& mass) const {
  return {*this, mass};
}

inline constexpr SpecificPower SpecificEnergy::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr SpecificPower SpecificEnergy::operator/(
    const Time& time) const {
  return {*this, time};
}

inline constexpr Time SpecificEnergy::operator/(
    const SpecificPower& specific_power) const {
  return {specific_power, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificPower> {
  inline size_t operator()(const PhQ::SpecificPower& specific_power) const {
    return hash<double>()(specific_power.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP
