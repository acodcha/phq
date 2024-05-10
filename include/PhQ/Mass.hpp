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

#ifndef PHQ_MASS_HPP
#define PHQ_MASS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Mass.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Mass.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class Energy;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class GasConstant;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class IsobaricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class IsochoricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class MassRate;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class Power;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class SpecificEnergy;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class SpecificGasConstant;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class SpecificIsochoricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class SpecificPower;

// Forward declaration for class PhQ::Mass.
template <typename Number>
class Volume;

// Mass.
template <typename Number = double>
class Mass : public DimensionalScalar<Unit::Mass, Number> {
public:
  // Default constructor. Constructs a mass with an uninitialized value.
  Mass() = default;

  // Constructor. Constructs a mass with a given value expressed in a given mass unit.
  Mass(const Number value, const Unit::Mass unit)
    : DimensionalScalar<Unit::Mass, Number>(value, unit) {}

  // Constructor. Constructs a mass from a given mass density and volume using the definition of
  // mass density.
  constexpr Mass(const MassDensity<Number>& mass_density, const Volume<Number>& volume);

  // Constructor. Constructs a mass from a given mass rate and time using the definition of mass
  // rate.
  constexpr Mass(const MassRate<Number>& mass_rate, const Time<Number>& time);

  // Constructor. Constructs a mass from a given mass rate and frequency using the definition of
  // mass rate.
  constexpr Mass(const MassRate<Number>& mass_rate, const Frequency<Number>& frequency);

  // Constructor. Constructs a mass from a given energy and specific energy using the definition of
  // specific energy.
  constexpr Mass(const Energy<Number>& energy, const SpecificEnergy<Number>& specific_energy);

  // Constructor. Constructs a mass from a given power and specific power using the definition of
  // specific power.
  constexpr Mass(const Power<Number>& power, const SpecificPower<Number>& specific_power);

  // Constructor. Constructs a mass from a given gas constant and specific gas constant using the
  // definition of the specific gas constant.
  constexpr Mass(const GasConstant<Number>& gas_constant,
                 const SpecificGasConstant<Number>& specific_gas_constant);

  // Constructor. Constructs a mass from a given isobaric heat capacity and specific isobaric heat
  // capacity using the definition of the specific isobaric heat capacity.
  constexpr Mass(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                 const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity);

  // Constructor. Constructs a mass from a given isochoric heat capacity and specific isochoric heat
  // capacity using the definition of the specific isochoric heat capacity.
  constexpr Mass(const IsochoricHeatCapacity<Number>& isochoric_heat_capacity,
                 const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity);

  // Destructor. Destroys this mass.
  ~Mass() noexcept = default;

  // Copy constructor. Constructs a mass by copying another one.
  constexpr Mass(const Mass<Number>& other) = default;

  // Copy constructor. Constructs a mass by copying another one.
  template <typename OtherNumber>
  explicit constexpr Mass(const Mass<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a mass by moving another one.
  constexpr Mass(Mass<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this mass by copying another one.
  constexpr Mass<Number>& operator=(const Mass<Number>& other) = default;

  // Copy assignment operator. Assigns this mass by copying another one.
  template <typename OtherNumber>
  constexpr Mass<Number>& operator=(const Mass<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this mass by moving another one.
  constexpr Mass<Number>& operator=(Mass<Number>&& other) noexcept = default;

  // Statically creates a mass of zero.
  static constexpr Mass<Number> Zero() {
    return Mass<Number>{static_cast<Number>(0)};
  }

  // Statically creates a mass with a given value expressed in a given mass unit.
  template <Unit::Mass Unit>
  static constexpr Mass<Number> Create(const Number value) {
    return Mass<Number>{StaticConvertCopy<Unit::Mass, Unit, Standard<Unit::Mass>>(value)};
  }

  constexpr Mass<Number> operator+(const Mass<Number>& mass) const {
    return Mass<Number>{value + mass.value};
  }

  constexpr Mass<Number> operator-(const Mass<Number>& mass) const {
    return Mass<Number>{value - mass.value};
  }

  constexpr Mass<Number> operator*(const Number number) const {
    return Mass<Number>{value * number};
  }

  constexpr MassRate<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Energy<Number> operator*(const SpecificEnergy<Number>& specific_energy) const;

  constexpr Power<Number> operator*(const SpecificPower<Number>& specific_power) const;

  constexpr IsobaricHeatCapacity<Number> operator*(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const;

  constexpr IsochoricHeatCapacity<Number> operator*(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const;

  constexpr GasConstant<Number> operator*(
      const SpecificGasConstant<Number>& specific_gas_constant) const;

  constexpr Mass<Number> operator/(const Number number) const {
    return Mass<Number>{value / number};
  }

  constexpr MassDensity<Number> operator/(const Volume<Number>& volume) const;

  constexpr Volume<Number> operator/(const MassDensity<Number>& mass_density) const;

  constexpr MassRate<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const MassRate<Number>& mass_rate) const;

  constexpr Number operator/(const Mass<Number>& mass) const noexcept {
    return value / mass.value;
  }

  constexpr void operator+=(const Mass<Number>& mass) noexcept {
    value += mass.value;
  }

  constexpr void operator-=(const Mass<Number>& mass) noexcept {
    value -= mass.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a mass with a given value expressed in the standard mass unit.
  explicit constexpr Mass(const Number value) : DimensionalScalar<Unit::Mass, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Mass<Number>& left, const Mass<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Mass<Number>& left, const Mass<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Mass<Number>& left, const Mass<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Mass<Number>& left, const Mass<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Mass<Number>& left, const Mass<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Mass<Number>& left, const Mass<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Mass<Number>& mass) {
  stream << mass.Print();
  return stream;
}

template <typename Number>
inline constexpr Mass<Number> operator*(const Number number, const Mass<Number>& mass) {
  return mass * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Mass<Number>> {
  inline size_t operator()(const PhQ::Mass<Number>& mass) const {
    return hash<Number>()(mass.Value());
  }
};

}  // namespace std

#endif  // PHQ_MASS_HPP
