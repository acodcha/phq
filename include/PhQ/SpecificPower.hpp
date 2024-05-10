// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_SPECIFIC_POWER_HPP
#define PHQ_SPECIFIC_POWER_HPP

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
template <typename Number = double>
class SpecificPower : public DimensionalScalar<Unit::SpecificPower, Number> {
public:
  // Default constructor. Constructs a specific power quantity with an uninitialized value.
  SpecificPower() = default;

  // Constructor. Constructs a specific power quantity with a given value expressed in a given
  // specific power unit.
  SpecificPower(const Number value, const Unit::SpecificPower unit)
    : DimensionalScalar<Unit::SpecificPower, Number>(value, unit) {}

  // Constructor. Constructs a specific power quantity from a given specific energy and time
  // duration using the definition of specific power.
  constexpr SpecificPower(const SpecificEnergy<Number>& specific_energy, const Time<Number>& time)
    : SpecificPower<Number>(specific_energy.Value() / time.Value()) {}

  // Constructor. Constructs a specific power quantity from a given specific energy and frequency
  // using the definition of specific power.
  constexpr SpecificPower(
      const SpecificEnergy<Number>& specific_energy, const Frequency<Number>& frequency)
    : SpecificPower<Number>(specific_energy.Value() * frequency.Value()) {}

  // Constructor. Constructs a specific power quantity from a given power and mass using the
  // definition of specific power.
  constexpr SpecificPower(const Power<Number>& power, const Mass<Number>& mass)
    : SpecificPower<Number>(power.Value() / mass.Value()) {}

  // Destructor. Destroys this specific power quantity.
  ~SpecificPower() noexcept = default;

  // Copy constructor. Constructs a specific power quantity by copying another one.
  constexpr SpecificPower(const SpecificPower<Number>& other) = default;

  // Copy constructor. Constructs a specific power quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr SpecificPower(const SpecificPower<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a specific power quantity by moving another one.
  constexpr SpecificPower(SpecificPower<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific power quantity by copying another one.
  constexpr SpecificPower<Number>& operator=(const SpecificPower<Number>& other) = default;

  // Copy assignment operator. Assigns this specific power quantity by copying another one.
  template <typename OtherNumber>
  constexpr SpecificPower<Number>& operator=(const SpecificPower<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this specific power quantity by moving another one.
  constexpr SpecificPower<Number>& operator=(SpecificPower<Number>&& other) noexcept = default;

  // Statically creates a specific power quantity of zero.
  static constexpr SpecificPower<Number> Zero() {
    return SpecificPower<Number>{static_cast<Number>(0)};
  }

  // Statically creates a specific power quantity with a given value expressed in a given specific
  // power unit.
  template <Unit::SpecificPower Unit>
  static constexpr SpecificPower<Number> Create(const Number value) {
    return SpecificPower<Number>{
        StaticConvertCopy<Unit::SpecificPower, Unit, Standard<Unit::SpecificPower>>(value)};
  }

  constexpr SpecificPower<Number> operator+(const SpecificPower<Number>& specific_power) const {
    return SpecificPower<Number>{value + specific_power.value};
  }

  constexpr SpecificPower<Number> operator-(const SpecificPower<Number>& specific_power) const {
    return SpecificPower<Number>{value - specific_power.value};
  }

  constexpr SpecificPower<Number> operator*(const Number number) const {
    return SpecificPower<Number>{value * number};
  }

  constexpr SpecificEnergy<Number> operator*(const Time<Number>& time) const {
    return SpecificEnergy<Number>{*this, time};
  }

  constexpr Power<Number> operator*(const Mass<Number>& mass) const {
    return Power<Number>{*this, mass};
  }

  constexpr SpecificPower<Number> operator/(const Number number) const {
    return SpecificPower<Number>{value / number};
  }

  constexpr SpecificEnergy<Number> operator/(const Frequency<Number>& frequency) const {
    return SpecificEnergy<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const SpecificEnergy<Number>& specific_energy) const {
    return Frequency<Number>{*this, specific_energy};
  }

  constexpr Number operator/(const SpecificPower<Number>& specific_power) const noexcept {
    return value / specific_power.value;
  }

  constexpr void operator+=(const SpecificPower<Number>& specific_power) noexcept {
    value += specific_power.value;
  }

  constexpr void operator-=(const SpecificPower<Number>& specific_power) noexcept {
    value -= specific_power.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a specific power quantity with a given value expressed in the standard
  // specific power unit.
  explicit constexpr SpecificPower(const Number value)
    : DimensionalScalar<Unit::SpecificPower, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const SpecificPower<Number>& left, const SpecificPower<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const SpecificPower<Number>& left, const SpecificPower<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const SpecificPower<Number>& left, const SpecificPower<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const SpecificPower<Number>& left, const SpecificPower<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const SpecificPower<Number>& left, const SpecificPower<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const SpecificPower<Number>& left, const SpecificPower<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const SpecificPower<Number>& specific_power) {
  stream << specific_power.Print();
  return stream;
}

template <typename Number>
inline constexpr SpecificPower<Number> operator*(
    const Number number, const SpecificPower<Number>& specific_power) {
  return specific_power * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(
    const SpecificEnergy<Number>& specific_energy, const SpecificPower<Number>& specific_power)
  : Time<Number>(specific_energy.Value() / specific_power.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const SpecificPower<Number>& specific_power, const SpecificEnergy<Number>& specific_energy)
  : Frequency<Number>(specific_power.Value() / specific_energy.Value()) {}

template <typename Number>
inline constexpr Mass<Number>::Mass(
    const Power<Number>& power, const SpecificPower<Number>& specific_power)
  : Mass<Number>(power.Value() / specific_power.Value()) {}

template <typename Number>
inline constexpr Power<Number>::Power(
    const SpecificPower<Number>& specific_power, const Mass<Number>& mass)
  : Power<Number>(specific_power.Value() * mass.Value()) {}

template <typename Number>
inline constexpr SpecificEnergy<Number>::SpecificEnergy(
    const SpecificPower<Number>& specific_power, const Time<Number>& time)
  : SpecificEnergy<Number>(specific_power.Value() * time.Value()) {}

template <typename Number>
inline constexpr SpecificEnergy<Number>::SpecificEnergy(
    const SpecificPower<Number>& specific_power, const Frequency<Number>& frequency)
  : SpecificEnergy<Number>(specific_power.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Power<Number> Mass<Number>::operator*(
    const SpecificPower<Number>& specific_power) const {
  return Power<Number>{specific_power, *this};
}

template <typename Number>
inline constexpr SpecificEnergy<Number> Time<Number>::operator*(
    const SpecificPower<Number>& specific_power) const {
  return SpecificEnergy<Number>{specific_power, *this};
}

template <typename Number>
inline constexpr SpecificPower<Number> Frequency<Number>::operator*(
    const SpecificEnergy<Number>& specific_energy) const {
  return SpecificPower<Number>{specific_energy, *this};
}

template <typename Number>
inline constexpr SpecificPower<Number> SpecificEnergy<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return SpecificPower<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Mass<Number> Power<Number>::operator/(
    const SpecificPower<Number>& specific_power) const {
  return Mass<Number>{*this, specific_power};
}

template <typename Number>
inline constexpr SpecificPower<Number> Power<Number>::operator/(const Mass<Number>& mass) const {
  return SpecificPower<Number>{*this, mass};
}

template <typename Number>
inline constexpr SpecificPower<Number> SpecificEnergy<Number>::operator/(
    const Time<Number>& time) const {
  return SpecificPower<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> SpecificEnergy<Number>::operator/(
    const SpecificPower<Number>& specific_power) const {
  return Time<Number>{*this, specific_power};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SpecificPower<Number>> {
  inline size_t operator()(const PhQ::SpecificPower<Number>& specific_power) const {
    return hash<Number>()(specific_power.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_POWER_HPP
