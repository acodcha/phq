// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
    : Mass(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a mass by moving another one.
  constexpr Mass(Mass<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this mass by copying another one.
  constexpr Mass<Number>& operator=(const Mass<Number>& other) = default;

  // Copy assignment operator. Assigns this mass by copying another one.
  template <typename OtherNumber>
  constexpr Mass<Number>& operator=(const Mass<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
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
    return Mass<Number>{this->value + mass.value};
  }

  constexpr Mass<Number> operator-(const Mass<Number>& mass) const {
    return Mass<Number>{this->value - mass.value};
  }

  constexpr Mass<Number> operator*(const Number number) const {
    return Mass<Number>{this->value * number};
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
    return Mass<Number>{this->value / number};
  }

  constexpr MassDensity<Number> operator/(const Volume<Number>& volume) const;

  constexpr Volume<Number> operator/(const MassDensity<Number>& mass_density) const;

  constexpr MassRate<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const MassRate<Number>& mass_rate) const;

  constexpr Number operator/(const Mass<Number>& mass) const noexcept {
    return this->value / mass.value;
  }

  constexpr void operator+=(const Mass<Number>& mass) noexcept {
    this->value += mass.value;
  }

  constexpr void operator-=(const Mass<Number>& mass) noexcept {
    this->value -= mass.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
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
