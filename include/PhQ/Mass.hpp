// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class Energy;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class GasConstant;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class IsobaricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class IsochoricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class MassRate;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class Power;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class SpecificEnergy;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class SpecificGasConstant;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class SpecificIsochoricHeatCapacity;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class SpecificPower;

// Forward declaration for class PhQ::Mass.
template <typename NumericType>
class Volume;

/// \brief Mass. For the time rate of change of mass, see PhQ::MassRate; see also PhQ::Time and
/// PhQ::Frequency.
template <typename NumericType = double>
class Mass : public DimensionalScalar<Unit::Mass, NumericType> {
public:
  /// \brief Default constructor. Constructs a mass with an uninitialized value.
  Mass() = default;

  /// \brief Constructor. Constructs a mass with a given value expressed in a given mass unit.
  Mass(const NumericType value, const Unit::Mass unit)
    : DimensionalScalar<Unit::Mass, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a mass from a given mass density and volume using the
  /// definition of mass density.
  constexpr Mass(const MassDensity<NumericType>& mass_density, const Volume<NumericType>& volume);

  /// \brief Constructor. Constructs a mass from a given mass rate and time using the definition of
  /// mass rate.
  constexpr Mass(const MassRate<NumericType>& mass_rate, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a mass from a given mass rate and frequency using the
  /// definition of mass rate.
  constexpr Mass(const MassRate<NumericType>& mass_rate, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a mass from a given energy and specific energy using the
  /// definition of specific energy.
  constexpr Mass(
      const Energy<NumericType>& energy, const SpecificEnergy<NumericType>& specific_energy);

  /// \brief Constructor. Constructs a mass from a given power and specific power using the
  /// definition of specific power.
  constexpr Mass(const Power<NumericType>& power, const SpecificPower<NumericType>& specific_power);

  /// \brief Constructor. Constructs a mass from a given gas constant and specific gas constant
  /// using the definition of the specific gas constant.
  constexpr Mass(const GasConstant<NumericType>& gas_constant,
                 const SpecificGasConstant<NumericType>& specific_gas_constant);

  /// \brief Constructor. Constructs a mass from a given isobaric heat capacity and specific
  /// isobaric heat capacity using the definition of the specific isobaric heat capacity.
  constexpr Mass(const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
                 const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity);

  /// \brief Constructor. Constructs a mass from a given isochoric heat capacity and specific
  /// isochoric heat capacity using the definition of the specific isochoric heat capacity.
  constexpr Mass(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity,
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity);

  /// \brief Destructor. Destroys this mass.
  ~Mass() noexcept = default;

  /// \brief Copy constructor. Constructs a mass by copying another one.
  constexpr Mass(const Mass<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a mass by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Mass(const Mass<OtherNumericType>& other)
    : Mass(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a mass by moving another one.
  constexpr Mass(Mass<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this mass by copying another one.
  constexpr Mass<NumericType>& operator=(const Mass<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this mass by copying another one.
  template <typename OtherNumericType>
  constexpr Mass<NumericType>& operator=(const Mass<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this mass by moving another one.
  constexpr Mass<NumericType>& operator=(Mass<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a mass of zero.
  static constexpr Mass<NumericType> Zero() {
    return Mass<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a mass with a given value expressed in a given mass unit.
  template <Unit::Mass Unit>
  static constexpr Mass<NumericType> Create(const NumericType value) {
    return Mass<NumericType>{ConvertStatically<Unit::Mass, Unit, Standard<Unit::Mass>>(value)};
  }

  constexpr Mass<NumericType> operator+(const Mass<NumericType>& mass) const {
    return Mass<NumericType>{this->value + mass.value};
  }

  constexpr Mass<NumericType> operator-(const Mass<NumericType>& mass) const {
    return Mass<NumericType>{this->value - mass.value};
  }

  constexpr Mass<NumericType> operator*(const NumericType number) const {
    return Mass<NumericType>{this->value * number};
  }

  constexpr MassRate<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Energy<NumericType> operator*(const SpecificEnergy<NumericType>& specific_energy) const;

  constexpr Power<NumericType> operator*(const SpecificPower<NumericType>& specific_power) const;

  constexpr IsobaricHeatCapacity<NumericType> operator*(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const;

  constexpr IsochoricHeatCapacity<NumericType> operator*(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const;

  constexpr GasConstant<NumericType> operator*(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const;

  constexpr Mass<NumericType> operator/(const NumericType number) const {
    return Mass<NumericType>{this->value / number};
  }

  constexpr MassDensity<NumericType> operator/(const Volume<NumericType>& volume) const;

  constexpr Volume<NumericType> operator/(const MassDensity<NumericType>& mass_density) const;

  constexpr MassRate<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const MassRate<NumericType>& mass_rate) const;

  constexpr NumericType operator/(const Mass<NumericType>& mass) const noexcept {
    return this->value / mass.value;
  }

  constexpr void operator+=(const Mass<NumericType>& mass) noexcept {
    this->value += mass.value;
  }

  constexpr void operator-=(const Mass<NumericType>& mass) noexcept {
    this->value -= mass.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a mass with a given value expressed in the standard mass unit.
  explicit constexpr Mass(const NumericType value)
    : DimensionalScalar<Unit::Mass, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Mass<NumericType>& left, const Mass<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Mass<NumericType>& left, const Mass<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Mass<NumericType>& left, const Mass<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Mass<NumericType>& left, const Mass<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Mass<NumericType>& left, const Mass<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Mass<NumericType>& left, const Mass<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Mass<NumericType>& mass) {
  stream << mass.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Mass<NumericType> operator*(
    const NumericType number, const Mass<NumericType>& mass) {
  return mass * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Mass<NumericType>> {
  inline size_t operator()(const PhQ::Mass<NumericType>& mass) const {
    return hash<NumericType>()(mass.Value());
  }
};

}  // namespace std

#endif  // PHQ_MASS_HPP
