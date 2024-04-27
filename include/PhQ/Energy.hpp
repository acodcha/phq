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

#ifndef PHQ_ENERGY_HPP
#define PHQ_ENERGY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declarations for class Energy.
class Frequency;
class Length;
class Mass;
class Power;
class SpecificEnergy;
class SpecificPower;
class Time;
class TransportEnergyConsumption;

// Energy physical quantity. Can represent any kind of energy, such as kinetic energy, potential
// energy, internal energy, and so on.
class Energy : public DimensionalScalar<Unit::Energy> {
public:
  // Default constructor. Constructs an energy quantity with an uninitialized value.
  Energy() = default;

  // Constructor. Constructs an energy quantity with a given value expressed in a given energy unit.
  Energy(const double value, const Unit::Energy unit)
    : DimensionalScalar<Unit::Energy>(value, unit) {}

  // Constructor. Constructs an energy quantity from a given power and time using the definition of
  // power.
  constexpr Energy(const Power& power, const Time& time);

  // Constructor. Constructs an energy quantity from a given power and frequency using the
  // definition of power.
  constexpr Energy(const Power& power, const Frequency& frequency);

  // Constructor. Constructs an energy quantity from a given specific energy quantity and mass using
  // the definition of specific energy.
  constexpr Energy(const SpecificEnergy& specific_energy, const Mass& mass);

  // Constructor. Constructs an energy quantity from a given transport energy consumption and length
  // using the definition of transport energy consumption.
  constexpr Energy(
      const TransportEnergyConsumption& transport_energy_consumption, const Length& length);

  // Destructor. Destroys this energy quantity.
  ~Energy() noexcept = default;

  // Copy constructor. Constructs an energy quantity by copying another one.
  constexpr Energy(const Energy& other) = default;

  // Move constructor. Constructs an energy quantity by moving another one.
  constexpr Energy(Energy&& other) noexcept = default;

  // Copy assignment operator. Assigns this energy quantity by copying another one.
  constexpr Energy& operator=(const Energy& other) = default;

  // Move assignment operator. Assigns this energy quantity by moving another one.
  constexpr Energy& operator=(Energy&& other) noexcept = default;

  // Statically creates an energy quantity of zero.
  static constexpr Energy Zero() {
    return Energy{0.0};
  }

  // Statically creates an energy quantity with a given value expressed in a given energy unit.
  template <Unit::Energy Unit>
  static constexpr Energy Create(const double value) {
    return Energy{StaticConvertCopy<Unit::Energy, Unit, Standard<Unit::Energy>>(value)};
  }

  constexpr Energy operator+(const Energy& energy) const {
    return Energy{value + energy.value};
  }

  constexpr Energy operator-(const Energy& energy) const {
    return Energy{value - energy.value};
  }

  constexpr Energy operator*(const double number) const {
    return Energy{value * number};
  }

  constexpr Power operator*(const Frequency& frequency) const;

  constexpr Energy operator/(const double number) const {
    return Energy{value / number};
  }

  constexpr Power operator/(const Time& time) const;

  constexpr Time operator/(const Power& power) const;

  constexpr SpecificEnergy operator/(const Mass& mass) const;

  constexpr Mass operator/(const SpecificEnergy& specific_energy) const;

  constexpr TransportEnergyConsumption operator/(const Length& length) const;

  constexpr Length operator/(const TransportEnergyConsumption& transport_energy_consumption) const;

  constexpr double operator/(const Energy& energy) const noexcept {
    return value / energy.value;
  }

  constexpr void operator+=(const Energy& energy) noexcept {
    value += energy.value;
  }

  constexpr void operator-=(const Energy& energy) noexcept {
    value -= energy.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an energy quantity with a given value expressed in the standard energy
  // unit.
  explicit constexpr Energy(const double value) : DimensionalScalar<Unit::Energy>(value) {}
};

inline constexpr bool operator==(const Energy& left, const Energy& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Energy& left, const Energy& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Energy& left, const Energy& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Energy& left, const Energy& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Energy& left, const Energy& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Energy& left, const Energy& right) noexcept {
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

#endif  // PHQ_ENERGY_HPP
