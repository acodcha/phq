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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Mass.hpp"
#include "Power.hpp"
#include "SpecificEnergy.hpp"
#include "Time.hpp"
#include "Unit/SpecificPower.hpp"

namespace PhQ {

// Specific power. Power per unit mass.
class SpecificPower : public DimensionalScalar<Unit::SpecificPower> {
public:
  // Default constructor. Constructs a specific power quantity with an uninitialized value.
  SpecificPower() = default;

  // Constructor. Constructs a specific power quantity with a given value expressed in a given
  // specific power unit.
  SpecificPower(const double value, const Unit::SpecificPower unit)
    : DimensionalScalar<Unit::SpecificPower>(value, unit) {}

  // Constructor. Constructs a specific power quantity from a given specific energy and time
  // duration using the definition of specific power.
  constexpr SpecificPower(const SpecificEnergy& specific_energy, const Time& time)
    : SpecificPower(specific_energy.Value() / time.Value()) {}

  // Constructor. Constructs a specific power quantity from a given specific energy and frequency
  // using the definition of specific power.
  constexpr SpecificPower(const SpecificEnergy& specific_energy, const Frequency& frequency)
    : SpecificPower(specific_energy.Value() * frequency.Value()) {}

  // Constructor. Constructs a specific power quantity from a given power and mass using the
  // definition of specific power.
  constexpr SpecificPower(const Power& power, const Mass& mass)
    : SpecificPower(power.Value() / mass.Value()) {}

  // Destructor. Destroys this specific power quantity.
  ~SpecificPower() noexcept = default;

  // Copy constructor. Constructs a specific power quantity by copying another one.
  constexpr SpecificPower(const SpecificPower& other) = default;

  // Move constructor. Constructs a specific power quantity by moving another one.
  constexpr SpecificPower(SpecificPower&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific power quantity by copying another one.
  constexpr SpecificPower& operator=(const SpecificPower& other) = default;

  // Move assignment operator. Assigns this specific power quantity by moving another one.
  constexpr SpecificPower& operator=(SpecificPower&& other) noexcept = default;

  // Statically creates a specific power quantity of zero.
  static constexpr SpecificPower Zero() {
    return SpecificPower{0.0};
  }

  // Statically creates a specific power quantity with a given value expressed in a given specific
  // power unit.
  template <Unit::SpecificPower Unit>
  static constexpr SpecificPower Create(const double value) {
    return SpecificPower{
        StaticConvertCopy<Unit::SpecificPower, Unit, Standard<Unit::SpecificPower>>(value)};
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

  constexpr double operator/(const SpecificPower& specific_power) const noexcept {
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
  // Constructor. Constructs a specific power quantity with a given value expressed in the standard
  // specific power unit.
  explicit constexpr SpecificPower(const double value)
    : DimensionalScalar<Unit::SpecificPower>(value) {}
};

inline constexpr bool operator==(const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const SpecificPower& left, const SpecificPower& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const SpecificPower& specific_power) {
  stream << specific_power.Print();
  return stream;
}

inline constexpr SpecificPower operator*(const double number, const SpecificPower& specific_power) {
  return specific_power * number;
}

inline constexpr Time::Time(
    const SpecificEnergy& specific_energy, const SpecificPower& specific_power)
  : Time(specific_energy.Value() / specific_power.Value()) {}

inline constexpr Frequency::Frequency(
    const SpecificPower& specific_power, const SpecificEnergy& specific_energy)
  : Frequency(specific_power.Value() / specific_energy.Value()) {}

inline constexpr Mass::Mass(const Power& power, const SpecificPower& specific_power)
  : Mass(power.Value() / specific_power.Value()) {}

inline constexpr Power::Power(const SpecificPower& specific_power, const Mass& mass)
  : Power(specific_power.Value() * mass.Value()) {}

inline constexpr SpecificEnergy::SpecificEnergy(
    const SpecificPower& specific_power, const Time& time)
  : SpecificEnergy(specific_power.Value() * time.Value()) {}

inline constexpr SpecificEnergy::SpecificEnergy(
    const SpecificPower& specific_power, const Frequency& frequency)
  : SpecificEnergy(specific_power.Value() / frequency.Value()) {}

inline constexpr Power Mass::operator*(const SpecificPower& specific_power) const {
  return {specific_power, *this};
}

inline constexpr SpecificEnergy Time::operator*(const SpecificPower& specific_power) const {
  return {specific_power, *this};
}

inline constexpr SpecificPower Frequency::operator*(const SpecificEnergy& specific_energy) const {
  return {specific_energy, *this};
}

inline constexpr SpecificPower SpecificEnergy::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr Mass Power::operator/(const SpecificPower& specific_power) const {
  return {*this, specific_power};
}

inline constexpr SpecificPower Power::operator/(const Mass& mass) const {
  return {*this, mass};
}

inline constexpr SpecificPower SpecificEnergy::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time SpecificEnergy::operator/(const SpecificPower& specific_power) const {
  return {*this, specific_power};
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
