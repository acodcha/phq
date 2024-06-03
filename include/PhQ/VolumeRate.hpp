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

#ifndef PHQ_VOLUME_RATE_HPP
#define PHQ_VOLUME_RATE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/VolumeRate.hpp"
#include "Volume.hpp"

namespace PhQ {

// Forward declaration for class PhQ::VolumeRate.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::VolumeRate.
template <typename NumericType>
class MassRate;

/// \brief Volume rate. Can represent a time rate of change of a volume or a volume flow rate. See
/// also PhQ::Volume, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class VolumeRate : public DimensionalScalar<Unit::VolumeRate, NumericType> {
public:
  /// \brief Default constructor. Constructs a volume rate with an uninitialized value.
  VolumeRate() = default;

  /// \brief Constructor. Constructs a volume rate with a given value expressed in a given volume
  /// rate unit.
  VolumeRate(const NumericType value, const Unit::VolumeRate unit)
    : DimensionalScalar<Unit::VolumeRate, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a volume rate from a given volume and time using the definition
  /// of volume rate.
  constexpr VolumeRate(const Volume<NumericType>& volume, const Time<NumericType>& time)
    : VolumeRate<NumericType>(volume.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a volume rate from a given volume and frequency using the
  /// definition of volume rate.
  constexpr VolumeRate(const Volume<NumericType>& volume, const Frequency<NumericType>& frequency)
    : VolumeRate<NumericType>(volume.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a volume rate from a given mass rate and mass density using the
  /// definition of mass density.
  constexpr VolumeRate(
      const MassRate<NumericType>& mass_rate, const MassDensity<NumericType>& mass_density);

  /// \brief Destructor. Destroys this volume rate.
  ~VolumeRate() noexcept = default;

  /// \brief Copy constructor. Constructs a volume rate by copying another one.
  constexpr VolumeRate(const VolumeRate<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a volume rate by copying another one.
  template <typename OtherNumericType>
  explicit constexpr VolumeRate(const VolumeRate<OtherNumericType>& other)
    : VolumeRate(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a volume rate by moving another one.
  constexpr VolumeRate(VolumeRate<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this volume rate by copying another one.
  constexpr VolumeRate<NumericType>& operator=(const VolumeRate<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this volume rate by copying another one.
  template <typename OtherNumericType>
  constexpr VolumeRate<NumericType>& operator=(const VolumeRate<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this volume rate by moving another one.
  constexpr VolumeRate<NumericType>& operator=(VolumeRate<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a volume rate of zero.
  [[nodiscard]] static constexpr VolumeRate<NumericType> Zero() {
    return VolumeRate<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a volume rate with a given value expressed in a given volume rate
  /// unit.
  template <Unit::VolumeRate Unit>
  [[nodiscard]] static constexpr VolumeRate<NumericType> Create(const NumericType value) {
    return VolumeRate<NumericType>{
        ConvertStatically<Unit::VolumeRate, Unit, Standard<Unit::VolumeRate>>(value)};
  }

  constexpr VolumeRate<NumericType> operator+(const VolumeRate<NumericType>& volume_rate) const {
    return VolumeRate<NumericType>{this->value + volume_rate.value};
  }

  constexpr VolumeRate<NumericType> operator-(const VolumeRate<NumericType>& volume_rate) const {
    return VolumeRate<NumericType>{this->value - volume_rate.value};
  }

  constexpr VolumeRate<NumericType> operator*(const NumericType number) const {
    return VolumeRate<NumericType>{this->value * number};
  }

  constexpr Volume<NumericType> operator*(const Time<NumericType>& time) const {
    return Volume<NumericType>{*this, time};
  }

  constexpr MassRate<NumericType> operator*(const MassDensity<NumericType>& mass_density) const;

  constexpr VolumeRate<NumericType> operator/(const NumericType number) const {
    return VolumeRate<NumericType>{this->value / number};
  }

  constexpr Volume<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Volume<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const Volume<NumericType>& volume) const {
    return Frequency<NumericType>{*this, volume};
  }

  constexpr NumericType operator/(const VolumeRate<NumericType>& volume_rate) const noexcept {
    return this->value / volume_rate.value;
  }

  constexpr void operator+=(const VolumeRate<NumericType>& volume_rate) noexcept {
    this->value += volume_rate.value;
  }

  constexpr void operator-=(const VolumeRate<NumericType>& volume_rate) noexcept {
    this->value -= volume_rate.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a volume rate with a given value expressed in the standard
  /// volume rate unit.
  explicit constexpr VolumeRate(const NumericType value)
    : DimensionalScalar<Unit::VolumeRate, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const VolumeRate<NumericType>& left, const VolumeRate<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const VolumeRate<NumericType>& left, const VolumeRate<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const VolumeRate<NumericType>& left, const VolumeRate<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const VolumeRate<NumericType>& left, const VolumeRate<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const VolumeRate<NumericType>& left, const VolumeRate<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const VolumeRate<NumericType>& left, const VolumeRate<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const VolumeRate<NumericType>& volume_rate) {
  stream << volume_rate.Print();
  return stream;
}

template <typename NumericType>
inline constexpr VolumeRate<NumericType> operator*(
    const NumericType number, const VolumeRate<NumericType>& volume_rate) {
  return volume_rate * number;
}

template <typename NumericType>
inline constexpr Volume<NumericType>::Volume(
    const VolumeRate<NumericType>& volume_rate, const Time<NumericType>& time)
  : Volume<NumericType>(volume_rate.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Volume<NumericType>::Volume(
    const VolumeRate<NumericType>& volume_rate, const Frequency<NumericType>& frequency)
  : Volume<NumericType>(volume_rate.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Volume<NumericType>& volume, const VolumeRate<NumericType>& volume_rate)
  : Time<NumericType>(volume.Value() / volume_rate.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const VolumeRate<NumericType>& volume_rate, const Volume<NumericType>& volume)
  : Frequency<NumericType>(volume_rate.Value() / volume.Value()) {}

template <typename NumericType>
inline constexpr Volume<NumericType> Time<NumericType>::operator*(
    const VolumeRate<NumericType>& volume_rate) const {
  return Volume<NumericType>{volume_rate, *this};
}

template <typename NumericType>
inline constexpr VolumeRate<NumericType> Volume<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return VolumeRate<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr Time<NumericType> Volume<NumericType>::operator/(
    const VolumeRate<NumericType>& volume_rate) const {
  return Time<NumericType>{*this, volume_rate};
}

template <typename NumericType>
inline constexpr VolumeRate<NumericType> Frequency<NumericType>::operator*(
    const Volume<NumericType>& volume) const {
  return VolumeRate<NumericType>{volume, *this};
}

template <typename NumericType>
inline constexpr VolumeRate<NumericType> Volume<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return VolumeRate<NumericType>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::VolumeRate<NumericType>> {
  inline size_t operator()(const PhQ::VolumeRate<NumericType>& volume_rate) const {
    return hash<NumericType>()(volume_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUME_RATE_HPP
