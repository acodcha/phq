// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_ENERGY_HPP
#define PHQ_ENERGY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class Length;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class Mass;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class Power;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class SpecificEnergy;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class SpecificPower;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Energy.
template <typename NumericType>
class TransportEnergyConsumption;

/// \brief Energy physical quantity. Can represent any kind of energy, such as kinetic energy,
/// potential energy, internal energy, and so on. The time rate of change of energy is power; see
/// PhQ::Power, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class Energy : public DimensionalScalar<Unit::Energy, NumericType> {
public:
  /// \brief Default constructor. Constructs an energy quantity with an uninitialized value.
  Energy() = default;

  /// \brief Constructor. Constructs an energy quantity with a given value expressed in a given
  /// energy unit.
  Energy(const NumericType value, const Unit::Energy unit)
    : DimensionalScalar<Unit::Energy, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an energy quantity from a given power and time using the
  /// definition of power.
  constexpr Energy(const Power<NumericType>& power, const Time<NumericType>& time);

  /// \brief Constructor. Constructs an energy quantity from a given power and frequency using the
  /// definition of power.
  constexpr Energy(const Power<NumericType>& power, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs an energy quantity from a given specific energy quantity and
  /// mass using the definition of specific energy.
  constexpr Energy(
      const SpecificEnergy<NumericType>& specific_energy, const Mass<NumericType>& mass);

  /// \brief Constructor. Constructs an energy quantity from a given transport energy consumption
  /// and length using the definition of transport energy consumption.
  constexpr Energy(const TransportEnergyConsumption<NumericType>& transport_energy_consumption,
                   const Length<NumericType>& length);

  /// \brief Destructor. Destroys this energy quantity.
  ~Energy() noexcept = default;

  /// \brief Copy constructor. Constructs an energy quantity by copying another one.
  constexpr Energy(const Energy<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an energy quantity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Energy(const Energy<OtherNumericType>& other)
    : Energy(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an energy quantity by moving another one.
  constexpr Energy(Energy<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this energy quantity by copying another one.
  constexpr Energy<NumericType>& operator=(const Energy<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this energy quantity by copying another one.
  template <typename OtherNumericType>
  constexpr Energy<NumericType>& operator=(const Energy<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this energy quantity by moving another one.
  constexpr Energy<NumericType>& operator=(Energy<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an energy quantity of zero.
  [[nodiscard]] static constexpr Energy<NumericType> Zero() {
    return Energy<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an energy quantity with a given value expressed in a given energy
  /// unit.
  template <Unit::Energy Unit>
  [[nodiscard]] static constexpr Energy<NumericType> Create(const NumericType value) {
    return Energy<NumericType>{
        ConvertStatically<Unit::Energy, Unit, Standard<Unit::Energy>>(value)};
  }

  constexpr Energy<NumericType> operator+(const Energy<NumericType>& energy) const {
    return Energy<NumericType>{this->value + energy.value};
  }

  constexpr Energy<NumericType> operator-(const Energy<NumericType>& energy) const {
    return Energy<NumericType>{this->value - energy.value};
  }

  constexpr Energy<NumericType> operator*(const NumericType number) const {
    return Energy<NumericType>{this->value * number};
  }

  constexpr Power<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Energy<NumericType> operator/(const NumericType number) const {
    return Energy<NumericType>{this->value / number};
  }

  constexpr Power<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const Power<NumericType>& power) const;

  constexpr SpecificEnergy<NumericType> operator/(const Mass<NumericType>& mass) const;

  constexpr Mass<NumericType> operator/(const SpecificEnergy<NumericType>& specific_energy) const;

  constexpr TransportEnergyConsumption<NumericType> operator/(
      const Length<NumericType>& length) const;

  constexpr Length<NumericType> operator/(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const;

  constexpr NumericType operator/(const Energy<NumericType>& energy) const noexcept {
    return this->value / energy.value;
  }

  constexpr void operator+=(const Energy<NumericType>& energy) noexcept {
    this->value += energy.value;
  }

  constexpr void operator-=(const Energy<NumericType>& energy) noexcept {
    this->value -= energy.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an energy quantity with a given value expressed in the standard
  /// energy unit.
  explicit constexpr Energy(const NumericType value)
    : DimensionalScalar<Unit::Energy, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Energy<NumericType>& left, const Energy<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Energy<NumericType>& left, const Energy<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Energy<NumericType>& left, const Energy<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Energy<NumericType>& left, const Energy<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Energy<NumericType>& left, const Energy<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Energy<NumericType>& left, const Energy<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Energy<NumericType>& energy) {
  stream << energy.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Energy<NumericType> operator*(
    const NumericType number, const Energy<NumericType>& energy) {
  return energy * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Energy<NumericType>> {
  inline size_t operator()(const PhQ::Energy<NumericType>& energy) const {
    return hash<NumericType>()(energy.Value());
  }
};

}  // namespace std

#endif  // PHQ_ENERGY_HPP
