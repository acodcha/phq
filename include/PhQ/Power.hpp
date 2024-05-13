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

#ifndef PHQ_POWER_HPP
#define PHQ_POWER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Energy.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/Power.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Power.
template <typename Number>
class Speed;

// Forward declaration for class PhQ::Power.
template <typename Number>
class TransportEnergyConsumption;

// Power. Time rate of change of energy. Can also represent an energy transfer rate.
template <typename Number = double>
class Power : public DimensionalScalar<Unit::Power, Number> {
public:
  // Default constructor. Constructs a power quantity with an uninitialized value.
  Power() = default;

  // Constructor. Constructs a power quantity with a given value expressed in a given power unit.
  Power(const Number value, const Unit::Power unit)
    : DimensionalScalar<Unit::Power, Number>(value, unit) {}

  // Constructor. Constructs a power quantity from a given energy and time duration using the
  // definition of power.
  constexpr Power(const Energy<Number>& energy, const Time<Number>& time)
    : Power<Number>(energy.Value() / time.Value()) {}

  // Constructor. Constructs a power quantity from a given energy and frequency using the definition
  // of power.
  constexpr Power(const Energy<Number>& energy, const Frequency<Number>& frequency)
    : Power<Number>(energy.Value() * frequency.Value()) {}

  // Constructor. Constructs a power quantity from a given specific power and mass using the
  // definition of specific power.
  constexpr Power(const SpecificPower<Number>& specific_power, const Mass<Number>& mass);

  // Constructor. Constructs a power quantity from a given transport energy consumption and speed
  // using the definition of transport energy consumption.
  constexpr Power(const TransportEnergyConsumption<Number>& transport_energy_consumption,
                  const Speed<Number>& speed);

  // Destructor. Destroys this power quantity.
  ~Power() noexcept = default;

  // Copy constructor. Constructs a power quantity by copying another one.
  constexpr Power(const Power<Number>& other) = default;

  // Copy constructor. Constructs a power quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Power(const Power<OtherNumber>& other)
    : Power(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a power quantity by moving another one.
  constexpr Power(Power<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this power quantity by copying another one.
  constexpr Power<Number>& operator=(const Power<Number>& other) = default;

  // Copy assignment operator. Assigns this power quantity by copying another one.
  template <typename OtherNumber>
  constexpr Power<Number>& operator=(const Power<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this power quantity by moving another one.
  constexpr Power<Number>& operator=(Power<Number>&& other) noexcept = default;

  // Statically creates a power quantity of zero.
  static constexpr Power<Number> Zero() {
    return Power<Number>{static_cast<Number>(0)};
  }

  // Statically creates a power quantity with a given value expressed in a given power unit.
  template <Unit::Power Unit>
  static constexpr Power<Number> Create(const Number value) {
    return Power<Number>{StaticConvertCopy<Unit::Power, Unit, Standard<Unit::Power>>(value)};
  }

  constexpr Power<Number> operator+(const Power<Number>& power) const {
    return Power<Number>{this->value + power.value};
  }

  constexpr Power<Number> operator-(const Power<Number>& power) const {
    return Power<Number>{this->value - power.value};
  }

  constexpr Power<Number> operator*(const Number number) const {
    return Power<Number>{this->value * number};
  }

  constexpr Energy<Number> operator*(const Time<Number>& time) const {
    return Energy<Number>{*this, time};
  }

  constexpr Power<Number> operator/(const Number number) const {
    return Power<Number>{this->value / number};
  }

  constexpr Energy<Number> operator/(const Frequency<Number>& frequency) const {
    return Energy<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Energy<Number>& energy) const {
    return Frequency<Number>{*this, energy};
  }

  constexpr SpecificPower<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(const SpecificPower<Number>& specific_power) const;

  constexpr Number operator/(const Power<Number>& power) const noexcept {
    return this->value / power.value;
  }

  constexpr void operator+=(const Power<Number>& power) noexcept {
    this->value += power.value;
  }

  constexpr void operator-=(const Power<Number>& power) noexcept {
    this->value -= power.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a power quantity with a given value expressed in the standard power
  // unit.
  explicit constexpr Power(const Number value) : DimensionalScalar<Unit::Power, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Power<Number>& left, const Power<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Power<Number>& power) {
  stream << power.Print();
  return stream;
}

template <typename Number>
inline constexpr Power<Number> operator*(const Number number, const Power<Number>& power) {
  return power * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(const Energy<Number>& energy, const Power<Number>& power)
  : Time<Number>(energy.Value() / power.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const Power<Number>& power, const Energy<Number>& energy)
  : Frequency<Number>(power.Value() / energy.Value()) {}

template <typename Number>
inline constexpr Energy<Number>::Energy(const Power<Number>& power, const Time<Number>& time)
  : Energy<Number>(power.Value() * time.Value()) {}

template <typename Number>
inline constexpr Energy<Number>::Energy(
    const Power<Number>& power, const Frequency<Number>& frequency)
  : Energy<Number>(power.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Energy<Number> Time<Number>::operator*(const Power<Number>& power) const {
  return Energy<Number>{power, *this};
}

template <typename Number>
inline constexpr Power<Number> Frequency<Number>::operator*(const Energy<Number>& energy) const {
  return Power<Number>{energy, *this};
}

template <typename Number>
inline constexpr Power<Number> Energy<Number>::operator*(const Frequency<Number>& frequency) const {
  return Power<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Power<Number> Energy<Number>::operator/(const Time<Number>& time) const {
  return Power<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> Energy<Number>::operator/(const Power<Number>& power) const {
  return Time<Number>{*this, power};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Power<Number>> {
  inline size_t operator()(const PhQ::Power<Number>& power) const {
    return hash<Number>()(power.Value());
  }
};

}  // namespace std

#endif  // PHQ_POWER_HPP
