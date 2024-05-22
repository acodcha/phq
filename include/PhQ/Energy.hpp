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

/// \brief Energy physical quantity. Can represent any kind of energy, such as kinetic energy,
/// potential energy, internal energy, and so on.
template <typename Number = double>
class Energy : public DimensionalScalar<Unit::Energy, Number> {
public:
  /// \brief Default constructor. Constructs an energy quantity with an uninitialized value.
  Energy() = default;

  /// \brief Constructor. Constructs an energy quantity with a given value expressed in a given
  /// energy unit.
  Energy(const Number value, const Unit::Energy unit)
    : DimensionalScalar<Unit::Energy, Number>(value, unit) {}

  /// \brief Constructor. Constructs an energy quantity from a given power and time using the
  /// definition of power.
  constexpr Energy(const Power<Number>& power, const Time<Number>& time);

  /// \brief Constructor. Constructs an energy quantity from a given power and frequency using the
  /// definition of power.
  constexpr Energy(const Power<Number>& power, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs an energy quantity from a given specific energy quantity and
  /// mass using the definition of specific energy.
  constexpr Energy(const SpecificEnergy<Number>& specific_energy, const Mass<Number>& mass);

  /// \brief Constructor. Constructs an energy quantity from a given transport energy consumption
  /// and length using the definition of transport energy consumption.
  constexpr Energy(const TransportEnergyConsumption<Number>& transport_energy_consumption,
                   const Length<Number>& length);

  /// \brief Destructor. Destroys this energy quantity.
  ~Energy() noexcept = default;

  /// \brief Copy constructor. Constructs an energy quantity by copying another one.
  constexpr Energy(const Energy<Number>& other) = default;

  /// \brief Copy constructor. Constructs an energy quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Energy(const Energy<OtherNumber>& other)
    : Energy(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an energy quantity by moving another one.
  constexpr Energy(Energy<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this energy quantity by copying another one.
  constexpr Energy<Number>& operator=(const Energy<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this energy quantity by copying another one.
  template <typename OtherNumber>
  constexpr Energy<Number>& operator=(const Energy<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this energy quantity by moving another one.
  constexpr Energy<Number>& operator=(Energy<Number>&& other) noexcept = default;

  /// \brief Statically creates an energy quantity of zero.
  static constexpr Energy<Number> Zero() {
    return Energy<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an energy quantity with a given value expressed in a given energy
  /// unit.
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
  /// \brief Constructor. Constructs an energy quantity with a given value expressed in the standard
  /// energy unit.
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
