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

#ifndef PHQ_ENERGY_HPP
#define PHQ_ENERGY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Energy.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class Length;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class Mass;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class Power;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class SpecificEnergy;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class SpecificPower;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Energy.
template <typename Number>
class TransportEnergyConsumption;

// Energy physical quantity. Can represent any kind of energy, such as kinetic energy, potential
// energy, internal energy, and so on.
template <typename Number = double>
class Energy : public DimensionalScalar<Unit::Energy, Number> {
public:
  // Default constructor. Constructs an energy quantity with an uninitialized value.
  Energy() = default;

  // Constructor. Constructs an energy quantity with a given value expressed in a given energy unit.
  Energy(const Number value, const Unit::Energy unit)
    : DimensionalScalar<Unit::Energy, Number>(value, unit) {}

  // Constructor. Constructs an energy quantity from a given power and time using the definition of
  // power.
  constexpr Energy(const Power<Number>& power, const Time<Number>& time);

  // Constructor. Constructs an energy quantity from a given power and frequency using the
  // definition of power.
  constexpr Energy(const Power<Number>& power, const Frequency<Number>& frequency);

  // Constructor. Constructs an energy quantity from a given specific energy quantity and mass using
  // the definition of specific energy.
  constexpr Energy(const SpecificEnergy<Number>& specific_energy, const Mass<Number>& mass);

  // Constructor. Constructs an energy quantity from a given transport energy consumption and length
  // using the definition of transport energy consumption.
  constexpr Energy(const TransportEnergyConsumption<Number>& transport_energy_consumption,
                   const Length<Number>& length);

  // Destructor. Destroys this energy quantity.
  ~Energy() noexcept = default;

  // Copy constructor. Constructs an energy quantity by copying another one.
  constexpr Energy(const Energy<Number>& other) = default;

  // Copy constructor. Constructs an energy quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Energy(const Energy<OtherNumber>& other)
    : Energy(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an energy quantity by moving another one.
  constexpr Energy(Energy<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this energy quantity by copying another one.
  constexpr Energy<Number>& operator=(const Energy<Number>& other) = default;

  // Copy assignment operator. Assigns this energy quantity by copying another one.
  template <typename OtherNumber>
  constexpr Energy<Number>& operator=(const Energy<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this energy quantity by moving another one.
  constexpr Energy<Number>& operator=(Energy<Number>&& other) noexcept = default;

  // Statically creates an energy quantity of zero.
  static constexpr Energy<Number> Zero() {
    return Energy<Number>{static_cast<Number>(0)};
  }

  // Statically creates an energy quantity with a given value expressed in a given energy unit.
  template <Unit::Energy Unit>
  static constexpr Energy<Number> Create(const Number value) {
    return Energy<Number>{StaticConvertCopy<Unit::Energy, Unit, Standard<Unit::Energy>>(value)};
  }

  constexpr Energy<Number> operator+(const Energy<Number>& energy) const {
    return Energy<Number>{this->value + energy.value};
  }

  constexpr Energy<Number> operator-(const Energy<Number>& energy) const {
    return Energy<Number>{this->value - energy.value};
  }

  constexpr Energy<Number> operator*(const Number number) const {
    return Energy<Number>{this->value * number};
  }

  constexpr Power<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Energy<Number> operator/(const Number number) const {
    return Energy<Number>{this->value / number};
  }

  constexpr Power<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const Power<Number>& power) const;

  constexpr SpecificEnergy<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(const SpecificEnergy<Number>& specific_energy) const;

  constexpr TransportEnergyConsumption<Number> operator/(const Length<Number>& length) const;

  constexpr Length<Number> operator/(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const;

  constexpr Number operator/(const Energy<Number>& energy) const noexcept {
    return this->value / energy.value;
  }

  constexpr void operator+=(const Energy<Number>& energy) noexcept {
    this->value += energy.value;
  }

  constexpr void operator-=(const Energy<Number>& energy) noexcept {
    this->value -= energy.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs an energy quantity with a given value expressed in the standard energy
  // unit.
  explicit constexpr Energy(const Number value) : DimensionalScalar<Unit::Energy, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Energy<Number>& left, const Energy<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Energy<Number>& left, const Energy<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Energy<Number>& left, const Energy<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Energy<Number>& left, const Energy<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Energy<Number>& left, const Energy<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Energy<Number>& left, const Energy<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Energy<Number>& energy) {
  stream << energy.Print();
  return stream;
}

template <typename Number>
inline constexpr Energy<Number> operator*(const Number number, const Energy<Number>& energy) {
  return energy * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Energy<Number>> {
  inline size_t operator()(const PhQ::Energy<Number>& energy) const {
    return hash<Number>()(energy.Value());
  }
};

}  // namespace std

#endif  // PHQ_ENERGY_HPP
