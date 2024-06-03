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
template <typename NumericType>
class SpecificPower;

/// \brief Mass-specific energy. Energy per unit mass; see PhQ::Energy and PhQ::Mass.
template <typename NumericType = double>
class SpecificEnergy : public DimensionalScalar<Unit::SpecificEnergy, NumericType> {
public:
  /// \brief Default constructor. Constructs a specific energy quantity with an uninitialized value.
  SpecificEnergy() = default;

  /// \brief Constructor. Constructs a specific energy quantity with a given value expressed in a
  /// given specific energy unit.
  SpecificEnergy(const NumericType value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a specific energy quantity from a given energy and mass using
  /// the definition of specific energy.
  constexpr SpecificEnergy(const Energy<NumericType>& energy, const Mass<NumericType>& mass)
    : SpecificEnergy<NumericType>(energy.Value() / mass.Value()) {}

  /// \brief Constructor. Constructs a specific energy quantity from a given specific power and time
  /// duration using the definition of specific power.
  constexpr SpecificEnergy(
      const SpecificPower<NumericType>& specific_power, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a specific energy quantity from a given specific power and
  /// frequency using the definition of specific power.
  constexpr SpecificEnergy(
      const SpecificPower<NumericType>& specific_power, const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this specific energy quantity.
  ~SpecificEnergy() noexcept = default;

  /// \brief Copy constructor. Constructs a specific energy quantity by copying another one.
  constexpr SpecificEnergy(const SpecificEnergy<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a specific energy quantity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SpecificEnergy(const SpecificEnergy<OtherNumericType>& other)
    : SpecificEnergy(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a specific energy quantity by moving another one.
  constexpr SpecificEnergy(SpecificEnergy<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this specific energy quantity by copying another one.
  constexpr SpecificEnergy<NumericType>& operator=(
      const SpecificEnergy<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this specific energy quantity by copying another one.
  template <typename OtherNumericType>
  constexpr SpecificEnergy<NumericType>& operator=(const SpecificEnergy<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this specific energy quantity by moving another one.
  constexpr SpecificEnergy<NumericType>& operator=(
      SpecificEnergy<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a specific energy quantity of zero.
  [[nodiscard]] static constexpr SpecificEnergy<NumericType> Zero() {
    return SpecificEnergy<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a specific energy quantity with a given value expressed in a given
  /// specific energy unit.
  template <Unit::SpecificEnergy Unit>
  [[nodiscard]] static constexpr SpecificEnergy<NumericType> Create(const NumericType value) {
    return SpecificEnergy<NumericType>{
        ConvertStatically<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr SpecificEnergy<NumericType> operator+(
      const SpecificEnergy<NumericType>& specific_energy) const {
    return SpecificEnergy<NumericType>{this->value + specific_energy.value};
  }

  constexpr SpecificEnergy<NumericType> operator-(
      const SpecificEnergy<NumericType>& specific_energy) const {
    return SpecificEnergy<NumericType>{this->value - specific_energy.value};
  }

  constexpr SpecificEnergy<NumericType> operator*(const NumericType number) const {
    return SpecificEnergy<NumericType>{this->value * number};
  }

  constexpr Energy<NumericType> operator*(const Mass<NumericType>& mass) const {
    return Energy<NumericType>{*this, mass};
  }

  constexpr SpecificPower<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr SpecificEnergy<NumericType> operator/(const NumericType number) const {
    return SpecificEnergy<NumericType>{this->value / number};
  }

  constexpr SpecificPower<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const SpecificPower<NumericType>& specific_power) const;

  constexpr NumericType operator/(
      const SpecificEnergy<NumericType>& specific_energy) const noexcept {
    return this->value / specific_energy.value;
  }

  constexpr void operator+=(const SpecificEnergy<NumericType>& specific_energy) noexcept {
    this->value += specific_energy.value;
  }

  constexpr void operator-=(const SpecificEnergy<NumericType>& specific_energy) noexcept {
    this->value -= specific_energy.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a specific energy quantity with a given value expressed in the
  /// standard specific energy unit.
  explicit constexpr SpecificEnergy(const NumericType value)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const SpecificEnergy<NumericType>& left, const SpecificEnergy<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const SpecificEnergy<NumericType>& left, const SpecificEnergy<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const SpecificEnergy<NumericType>& left, const SpecificEnergy<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const SpecificEnergy<NumericType>& left, const SpecificEnergy<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const SpecificEnergy<NumericType>& left, const SpecificEnergy<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const SpecificEnergy<NumericType>& left, const SpecificEnergy<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const SpecificEnergy<NumericType>& specific_energy) {
  stream << specific_energy.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SpecificEnergy<NumericType> operator*(
    const NumericType number, const SpecificEnergy<NumericType>& specific_energy) {
  return specific_energy * number;
}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const Energy<NumericType>& energy, const SpecificEnergy<NumericType>& specific_energy)
  : Mass<NumericType>(energy.Value() / specific_energy.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType>::Energy(
    const SpecificEnergy<NumericType>& specific_energy, const Mass<NumericType>& mass)
  : Energy<NumericType>(specific_energy.Value() * mass.Value()) {}

template <typename NumericType>
inline constexpr Energy<NumericType> Mass<NumericType>::operator*(
    const SpecificEnergy<NumericType>& specific_energy) const {
  return Energy<NumericType>{specific_energy, *this};
}

template <typename NumericType>
inline constexpr Mass<NumericType> Energy<NumericType>::operator/(
    const SpecificEnergy<NumericType>& specific_energy) const {
  return Mass<NumericType>{*this, specific_energy};
}

template <typename NumericType>
inline constexpr SpecificEnergy<NumericType> Energy<NumericType>::operator/(
    const Mass<NumericType>& mass) const {
  return SpecificEnergy<NumericType>{*this, mass};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SpecificEnergy<NumericType>> {
  inline size_t operator()(const PhQ::SpecificEnergy<NumericType>& specific_energy) const {
    return hash<NumericType>()(specific_energy.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_ENERGY_HPP
