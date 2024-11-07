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

/// \brief Mass-specific power. Power per unit mass; see PhQ::Power and PhQ::Mass.
template <typename NumericType = double>
class SpecificPower : public DimensionalScalar<Unit::SpecificPower, NumericType> {
public:
  /// \brief Default constructor. Constructs a specific power quantity with an uninitialized value.
  SpecificPower() = default;

  /// \brief Constructor. Constructs a specific power quantity with a given value expressed in a
  /// given specific power unit.
  SpecificPower(const NumericType value, const Unit::SpecificPower unit)
    : DimensionalScalar<Unit::SpecificPower, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a specific power quantity from a given specific energy and time
  /// duration using the definition of specific power.
  constexpr SpecificPower(
      const SpecificEnergy<NumericType>& specific_energy, const Time<NumericType>& time)
    : SpecificPower<NumericType>(specific_energy.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a specific power quantity from a given specific energy and
  /// frequency using the definition of specific power.
  constexpr SpecificPower(
      const SpecificEnergy<NumericType>& specific_energy, const Frequency<NumericType>& frequency)
    : SpecificPower<NumericType>(specific_energy.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a specific power quantity from a given power and mass using the
  /// definition of specific power.
  constexpr SpecificPower(const Power<NumericType>& power, const Mass<NumericType>& mass)
    : SpecificPower<NumericType>(power.Value() / mass.Value()) {}

  /// \brief Destructor. Destroys this specific power quantity.
  ~SpecificPower() noexcept = default;

  /// \brief Copy constructor. Constructs a specific power quantity by copying another one.
  constexpr SpecificPower(const SpecificPower<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a specific power quantity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SpecificPower(const SpecificPower<OtherNumericType>& other)
    : SpecificPower(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a specific power quantity by moving another one.
  constexpr SpecificPower(SpecificPower<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this specific power quantity by copying another one.
  constexpr SpecificPower<NumericType>& operator=(
      const SpecificPower<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this specific power quantity by copying another one.
  template <typename OtherNumericType>
  constexpr SpecificPower<NumericType>& operator=(const SpecificPower<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this specific power quantity by moving another one.
  constexpr SpecificPower<NumericType>& operator=(
      SpecificPower<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a specific power quantity of zero.
  [[nodiscard]] static constexpr SpecificPower<NumericType> Zero() {
    return SpecificPower<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a specific power quantity with a given value expressed in a given
  /// specific power unit.
  template <Unit::SpecificPower Unit>
  [[nodiscard]] static constexpr SpecificPower<NumericType> Create(const NumericType value) {
    return SpecificPower<NumericType>{
      ConvertStatically<Unit::SpecificPower, Unit, Standard<Unit::SpecificPower>>(value)};
  }

  constexpr SpecificPower<NumericType> operator+(
      const SpecificPower<NumericType>& specific_power) const {
    return SpecificPower<NumericType>{this->value + specific_power.value};
  }

  constexpr SpecificPower<NumericType> operator-(
      const SpecificPower<NumericType>& specific_power) const {
    return SpecificPower<NumericType>{this->value - specific_power.value};
  }

  constexpr SpecificPower<NumericType> operator*(const NumericType number) const {
    return SpecificPower<NumericType>{this->value * number};
  }

  constexpr SpecificEnergy<NumericType> operator*(const Time<NumericType>& time) const {
    return SpecificEnergy<NumericType>{*this, time};
  }

  constexpr Power<NumericType> operator*(const Mass<NumericType>& mass) const {
    return Power<NumericType>{*this, mass};
  }

  constexpr SpecificPower<NumericType> operator/(const NumericType number) const {
    return SpecificPower<NumericType>{this->value / number};
  }

  constexpr SpecificEnergy<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return SpecificEnergy<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(
      const SpecificEnergy<NumericType>& specific_energy) const {
    return Frequency<NumericType>{*this, specific_energy};
  }

  constexpr NumericType operator/(const SpecificPower<NumericType>& specific_power) const noexcept {
    return this->value / specific_power.value;
  }

  constexpr void operator+=(const SpecificPower<NumericType>& specific_power) noexcept {
    this->value += specific_power.value;
  }

  constexpr void operator-=(const SpecificPower<NumericType>& specific_power) noexcept {
    this->value -= specific_power.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a specific power quantity with a given value expressed in the
  /// standard specific power unit.
  explicit constexpr SpecificPower(const NumericType value)
    : DimensionalScalar<Unit::SpecificPower, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const SpecificPower<NumericType>& left, const SpecificPower<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const SpecificPower<NumericType>& left, const SpecificPower<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const SpecificPower<NumericType>& left, const SpecificPower<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const SpecificPower<NumericType>& left, const SpecificPower<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const SpecificPower<NumericType>& left, const SpecificPower<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const SpecificPower<NumericType>& left, const SpecificPower<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const SpecificPower<NumericType>& specific_power) {
  stream << specific_power.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SpecificPower<NumericType> operator*(
    const NumericType number, const SpecificPower<NumericType>& specific_power) {
  return specific_power * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(const SpecificEnergy<NumericType>& specific_energy,
                                         const SpecificPower<NumericType>& specific_power)
  : Time<NumericType>(specific_energy.Value() / specific_power.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const SpecificPower<NumericType>& specific_power,
    const SpecificEnergy<NumericType>& specific_energy)
  : Frequency<NumericType>(specific_power.Value() / specific_energy.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const Power<NumericType>& power, const SpecificPower<NumericType>& specific_power)
  : Mass<NumericType>(power.Value() / specific_power.Value()) {}

template <typename NumericType>
inline constexpr Power<NumericType>::Power(
    const SpecificPower<NumericType>& specific_power, const Mass<NumericType>& mass)
  : Power<NumericType>(specific_power.Value() * mass.Value()) {}

template <typename NumericType>
inline constexpr SpecificEnergy<NumericType>::SpecificEnergy(
    const SpecificPower<NumericType>& specific_power, const Time<NumericType>& time)
  : SpecificEnergy<NumericType>(specific_power.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr SpecificEnergy<NumericType>::SpecificEnergy(
    const SpecificPower<NumericType>& specific_power, const Frequency<NumericType>& frequency)
  : SpecificEnergy<NumericType>(specific_power.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Power<NumericType> Mass<NumericType>::operator*(
    const SpecificPower<NumericType>& specific_power) const {
  return Power<NumericType>{specific_power, *this};
}

template <typename NumericType>
inline constexpr SpecificEnergy<NumericType> Time<NumericType>::operator*(
    const SpecificPower<NumericType>& specific_power) const {
  return SpecificEnergy<NumericType>{specific_power, *this};
}

template <typename NumericType>
inline constexpr SpecificPower<NumericType> Frequency<NumericType>::operator*(
    const SpecificEnergy<NumericType>& specific_energy) const {
  return SpecificPower<NumericType>{specific_energy, *this};
}

template <typename NumericType>
inline constexpr SpecificPower<NumericType> SpecificEnergy<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return SpecificPower<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr Mass<NumericType> Power<NumericType>::operator/(
    const SpecificPower<NumericType>& specific_power) const {
  return Mass<NumericType>{*this, specific_power};
}

template <typename NumericType>
inline constexpr SpecificPower<NumericType> Power<NumericType>::operator/(
    const Mass<NumericType>& mass) const {
  return SpecificPower<NumericType>{*this, mass};
}

template <typename NumericType>
inline constexpr SpecificPower<NumericType> SpecificEnergy<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return SpecificPower<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> SpecificEnergy<NumericType>::operator/(
    const SpecificPower<NumericType>& specific_power) const {
  return Time<NumericType>{*this, specific_power};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SpecificPower<NumericType>> {
  inline size_t operator()(const PhQ::SpecificPower<NumericType>& specific_power) const {
    return hash<NumericType>()(specific_power.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_POWER_HPP
