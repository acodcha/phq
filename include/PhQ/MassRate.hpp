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

#ifndef PHQ_MASS_RATE_HPP
#define PHQ_MASS_RATE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Mass.hpp"
#include "Time.hpp"
#include "Unit/MassRate.hpp"

namespace PhQ {

// Forward declaration for class PhQ::MassRate.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::MassRate.
template <typename NumericType>
class VolumeRate;

/// \brief Mass rate. Can represent the time rate of change of a mass or a mass flow rate; see
/// PhQ::Mass, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class MassRate : public DimensionalScalar<Unit::MassRate, NumericType> {
public:
  /// \brief Default constructor. Constructs a mass rate with an uninitialized value.
  MassRate() = default;

  /// \brief Constructor. Constructs a mass rate with a given value expressed in a given mass rate
  /// unit.
  MassRate(const NumericType value, const Unit::MassRate unit)
    : DimensionalScalar<Unit::MassRate, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a mass rate from a given mass and time using the definition of
  /// mass rate.
  constexpr MassRate(const Mass<NumericType>& mass, const Time<NumericType>& time)
    : MassRate<NumericType>(mass.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a mass rate from a given mass and frequency using the
  /// definition of mass rate.
  constexpr MassRate(const Mass<NumericType>& mass, const Frequency<NumericType>& frequency)
    : MassRate<NumericType>(mass.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a mass rate from a given mass density and volume rate using the
  /// definition of mass density.
  constexpr MassRate(
      const MassDensity<NumericType>& mass_density, const VolumeRate<NumericType>& volume_rate);

  /// \brief Destructor. Destroys this mass rate.
  ~MassRate() noexcept = default;

  /// \brief Copy constructor. Constructs a mass rate by copying another one.
  constexpr MassRate(const MassRate<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a mass rate by copying another one.
  template <typename OtherNumericType>
  explicit constexpr MassRate(const MassRate<OtherNumericType>& other)
    : MassRate(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a mass rate by moving another one.
  constexpr MassRate(MassRate<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this mass rate by copying another one.
  constexpr MassRate<NumericType>& operator=(const MassRate<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this mass rate by copying another one.
  template <typename OtherNumericType>
  constexpr MassRate<NumericType>& operator=(const MassRate<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this mass rate by moving another one.
  constexpr MassRate<NumericType>& operator=(MassRate<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a mass rate of zero.
  static constexpr MassRate<NumericType> Zero() {
    return MassRate<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a mass rate with a given value expressed in a given mass rate unit.
  template <Unit::MassRate Unit>
  static constexpr MassRate<NumericType> Create(const NumericType value) {
    return MassRate<NumericType>{
        ConvertStatically<Unit::MassRate, Unit, Standard<Unit::MassRate>>(value)};
  }

  constexpr MassRate<NumericType> operator+(const MassRate<NumericType>& mass_rate) const {
    return MassRate<NumericType>{this->value + mass_rate.value};
  }

  constexpr MassRate<NumericType> operator-(const MassRate<NumericType>& mass_rate) const {
    return MassRate<NumericType>{this->value - mass_rate.value};
  }

  constexpr MassRate<NumericType> operator*(const NumericType number) const {
    return MassRate<NumericType>{this->value * number};
  }

  constexpr Mass<NumericType> operator*(const Time<NumericType>& time) const {
    return Mass<NumericType>{*this, time};
  }

  constexpr MassRate<NumericType> operator/(const NumericType number) const {
    return MassRate<NumericType>{this->value / number};
  }

  constexpr Frequency<NumericType> operator/(const Mass<NumericType>& mass) const {
    return Frequency<NumericType>{*this, mass};
  }

  constexpr Mass<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Mass<NumericType>{*this, frequency};
  }

  constexpr MassDensity<NumericType> operator/(const VolumeRate<NumericType>& volume_rate) const;

  constexpr VolumeRate<NumericType> operator/(const MassDensity<NumericType>& mass_density) const;

  constexpr NumericType operator/(const MassRate<NumericType>& mass_rate) const noexcept {
    return this->value / mass_rate.value;
  }

  constexpr void operator+=(const MassRate<NumericType>& mass_rate) noexcept {
    this->value += mass_rate.value;
  }

  constexpr void operator-=(const MassRate<NumericType>& mass_rate) noexcept {
    this->value -= mass_rate.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a mass rate with a given value expressed in the standard mass
  /// rate unit.
  explicit constexpr MassRate(const NumericType value)
    : DimensionalScalar<Unit::MassRate, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const MassRate<NumericType>& left, const MassRate<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const MassRate<NumericType>& left, const MassRate<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const MassRate<NumericType>& left, const MassRate<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const MassRate<NumericType>& left, const MassRate<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const MassRate<NumericType>& left, const MassRate<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const MassRate<NumericType>& left, const MassRate<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const MassRate<NumericType>& mass_rate) {
  stream << mass_rate.Print();
  return stream;
}

template <typename NumericType>
inline constexpr MassRate<NumericType> operator*(
    const NumericType number, const MassRate<NumericType>& mass_rate) {
  return mass_rate * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Mass<NumericType>& mass, const MassRate<NumericType>& mass_rate)
  : Time<NumericType>(mass.Value() / mass_rate.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const MassRate<NumericType>& mass_rate, const Mass<NumericType>& mass)
  : Frequency<NumericType>(mass_rate.Value() / mass.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const MassRate<NumericType>& mass_rate, const Time<NumericType>& time)
  : Mass<NumericType>(mass_rate.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const MassRate<NumericType>& mass_rate, const Frequency<NumericType>& frequency)
  : Mass<NumericType>(mass_rate.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType> Time<NumericType>::operator*(
    const MassRate<NumericType>& mass_rate) const {
  return Mass<NumericType>{mass_rate, *this};
}

template <typename NumericType>
inline constexpr MassRate<NumericType> Mass<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return MassRate<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr MassRate<NumericType> Frequency<NumericType>::operator*(
    const Mass<NumericType>& mass) const {
  return MassRate<NumericType>{mass, *this};
}

template <typename NumericType>
inline constexpr MassRate<NumericType> Mass<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return MassRate<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> Mass<NumericType>::operator/(
    const MassRate<NumericType>& mass_rate) const {
  return Time<NumericType>{*this, mass_rate};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::MassRate<NumericType>> {
  inline size_t operator()(const PhQ::MassRate<NumericType>& mass_rate) const {
    return hash<NumericType>()(mass_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_MASS_RATE_HPP
