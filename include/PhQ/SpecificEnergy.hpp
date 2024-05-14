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

#ifndef PHQ_SPECIFIC_ENERGY_HPP
#define PHQ_SPECIFIC_ENERGY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Energy.hpp"
#include "Frequency.hpp"
#include "Mass.hpp"
#include "Power.hpp"
#include "Time.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration for class PhQ::SpecificEnergy.
template <typename Number>
class SpecificPower;

// Specific energy. Energy per unit mass.
template <typename Number = double>
class SpecificEnergy : public DimensionalScalar<Unit::SpecificEnergy, Number> {
public:
  // Default constructor. Constructs a specific energy quantity with an uninitialized value.
  SpecificEnergy() = default;

  // Constructor. Constructs a specific energy quantity with a given value expressed in a given
  // specific energy unit.
  SpecificEnergy(const Number value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value, unit) {}

  // Constructor. Constructs a specific energy quantity from a given energy and mass using the
  // definition of specific energy.
  constexpr SpecificEnergy(const Energy<Number>& energy, const Mass<Number>& mass)
    : SpecificEnergy<Number>(energy.Value() / mass.Value()) {}

  // Constructor. Constructs a specific energy quantity from a given specific power and time
  // duration using the definition of specific power.
  constexpr SpecificEnergy(const SpecificPower<Number>& specific_power, const Time<Number>& time);

  // Constructor. Constructs a specific energy quantity from a given specific power and frequency
  // using the definition of specific power.
  constexpr SpecificEnergy(
      const SpecificPower<Number>& specific_power, const Frequency<Number>& frequency);

  // Destructor. Destroys this specific energy quantity.
  ~SpecificEnergy() noexcept = default;

  // Copy constructor. Constructs a specific energy quantity by copying another one.
  constexpr SpecificEnergy(const SpecificEnergy<Number>& other) = default;

  // Copy constructor. Constructs a specific energy quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr SpecificEnergy(const SpecificEnergy<OtherNumber>& other)
    : SpecificEnergy(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a specific energy quantity by moving another one.
  constexpr SpecificEnergy(SpecificEnergy<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific energy quantity by copying another one.
  constexpr SpecificEnergy<Number>& operator=(const SpecificEnergy<Number>& other) = default;

  // Copy assignment operator. Assigns this specific energy quantity by copying another one.
  template <typename OtherNumber>
  constexpr SpecificEnergy<Number>& operator=(const SpecificEnergy<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this specific energy quantity by moving another one.
  constexpr SpecificEnergy<Number>& operator=(SpecificEnergy<Number>&& other) noexcept = default;

  // Statically creates a specific energy quantity of zero.
  static constexpr SpecificEnergy<Number> Zero() {
    return SpecificEnergy<Number>{static_cast<Number>(0)};
  }

  // Statically creates a specific energy quantity with a given value expressed in a given specific
  // energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr SpecificEnergy<Number> Create(const Number value) {
    return SpecificEnergy<Number>{
        StaticConvertCopy<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr SpecificEnergy<Number> operator+(const SpecificEnergy<Number>& specific_energy) const {
    return SpecificEnergy<Number>{this->value + specific_energy.value};
  }

  constexpr SpecificEnergy<Number> operator-(const SpecificEnergy<Number>& specific_energy) const {
    return SpecificEnergy<Number>{this->value - specific_energy.value};
  }

  constexpr SpecificEnergy<Number> operator*(const Number number) const {
    return SpecificEnergy<Number>{this->value * number};
  }

  constexpr Energy<Number> operator*(const Mass<Number>& mass) const {
    return Energy<Number>{*this, mass};
  }

  constexpr SpecificPower<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr SpecificEnergy<Number> operator/(const Number number) const {
    return SpecificEnergy<Number>{this->value / number};
  }

  constexpr SpecificPower<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const SpecificPower<Number>& specific_power) const;

  constexpr Number operator/(const SpecificEnergy<Number>& specific_energy) const noexcept {
    return this->value / specific_energy.value;
  }

  constexpr void operator+=(const SpecificEnergy<Number>& specific_energy) noexcept {
    this->value += specific_energy.value;
  }

  constexpr void operator-=(const SpecificEnergy<Number>& specific_energy) noexcept {
    this->value -= specific_energy.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a specific energy quantity with a given value expressed in the standard
  // specific energy unit.
  explicit constexpr SpecificEnergy(const Number value)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const SpecificEnergy<Number>& left, const SpecificEnergy<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const SpecificEnergy<Number>& left, const SpecificEnergy<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const SpecificEnergy<Number>& left, const SpecificEnergy<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const SpecificEnergy<Number>& left, const SpecificEnergy<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const SpecificEnergy<Number>& left, const SpecificEnergy<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const SpecificEnergy<Number>& left, const SpecificEnergy<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const SpecificEnergy<Number>& specific_energy) {
  stream << specific_energy.Print();
  return stream;
}

template <typename Number>
inline constexpr SpecificEnergy<Number> operator*(
    const Number number, const SpecificEnergy<Number>& specific_energy) {
  return specific_energy * number;
}

template <typename Number>
inline constexpr Mass<Number>::Mass(
    const Energy<Number>& energy, const SpecificEnergy<Number>& specific_energy)
  : Mass<Number>(energy.Value() / specific_energy.Value()) {}

template <typename Number>
inline constexpr Energy<Number>::Energy(
    const SpecificEnergy<Number>& specific_energy, const Mass<Number>& mass)
  : Energy<Number>(specific_energy.Value() * mass.Value()) {}

template <typename Number>
inline constexpr Energy<Number> Mass<Number>::operator*(
    const SpecificEnergy<Number>& specific_energy) const {
  return Energy<Number>{specific_energy, *this};
}

template <typename Number>
inline constexpr Mass<Number> Energy<Number>::operator/(
    const SpecificEnergy<Number>& specific_energy) const {
  return Mass<Number>{*this, specific_energy};
}

template <typename Number>
inline constexpr SpecificEnergy<Number> Energy<Number>::operator/(const Mass<Number>& mass) const {
  return SpecificEnergy<Number>{*this, mass};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SpecificEnergy<Number>> {
  inline size_t operator()(const PhQ::SpecificEnergy<Number>& specific_energy) const {
    return hash<Number>()(specific_energy.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_ENERGY_HPP
