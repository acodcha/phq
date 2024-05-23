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

/// \brief Volume rate. Can represent a time rate of change of a volume or a volume flow rate.
template <typename Number = double>
class VolumeRate : public DimensionalScalar<Unit::VolumeRate, Number> {
public:
  /// \brief Default constructor. Constructs a volume rate with an uninitialized value.
  VolumeRate() = default;

  /// \brief Constructor. Constructs a volume rate with a given value expressed in a given volume
  /// rate unit.
  VolumeRate(const Number value, const Unit::VolumeRate unit)
    : DimensionalScalar<Unit::VolumeRate, Number>(value, unit) {}

  /// \brief Constructor. Constructs a volume rate from a given volume and time using the definition
  /// of volume rate.
  constexpr VolumeRate(const Volume<Number>& volume, const Time<Number>& time)
    : VolumeRate<Number>(volume.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a volume rate from a given volume and frequency using the
  /// definition of volume rate.
  constexpr VolumeRate(const Volume<Number>& volume, const Frequency<Number>& frequency)
    : VolumeRate<Number>(volume.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this volume rate.
  ~VolumeRate() noexcept = default;

  /// \brief Copy constructor. Constructs a volume rate by copying another one.
  constexpr VolumeRate(const VolumeRate<Number>& other) = default;

  /// \brief Copy constructor. Constructs a volume rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr VolumeRate(const VolumeRate<OtherNumber>& other)
    : VolumeRate(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a volume rate by moving another one.
  constexpr VolumeRate(VolumeRate<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this volume rate by copying another one.
  constexpr VolumeRate<Number>& operator=(const VolumeRate<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this volume rate by copying another one.
  template <typename OtherNumber>
  constexpr VolumeRate<Number>& operator=(const VolumeRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this volume rate by moving another one.
  constexpr VolumeRate<Number>& operator=(VolumeRate<Number>&& other) noexcept = default;

  /// \brief Statically creates a volume rate of zero.
  static constexpr VolumeRate<Number> Zero() {
    return VolumeRate<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a volume rate with a given value expressed in a given volume rate
  /// unit.
  template <Unit::VolumeRate Unit>
  static constexpr VolumeRate<Number> Create(const Number value) {
    return VolumeRate<Number>{
        StaticConvertCopy<Unit::VolumeRate, Unit, Standard<Unit::VolumeRate>>(value)};
  }

  constexpr VolumeRate<Number> operator+(const VolumeRate<Number>& volume_rate) const {
    return VolumeRate<Number>{this->value + volume_rate.value};
  }

  constexpr VolumeRate<Number> operator-(const VolumeRate<Number>& volume_rate) const {
    return VolumeRate<Number>{this->value - volume_rate.value};
  }

  constexpr VolumeRate<Number> operator*(const Number number) const {
    return VolumeRate<Number>{this->value * number};
  }

  constexpr Volume<Number> operator*(const Time<Number>& time) const {
    return Volume<Number>{*this, time};
  }

  constexpr VolumeRate<Number> operator/(const Number number) const {
    return VolumeRate<Number>{this->value / number};
  }

  constexpr Volume<Number> operator/(const Frequency<Number>& frequency) const {
    return Volume<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Volume<Number>& volume) const {
    return Frequency<Number>{*this, volume};
  }

  constexpr Number operator/(const VolumeRate<Number>& volume_rate) const noexcept {
    return this->value / volume_rate.value;
  }

  constexpr void operator+=(const VolumeRate<Number>& volume_rate) noexcept {
    this->value += volume_rate.value;
  }

  constexpr void operator-=(const VolumeRate<Number>& volume_rate) noexcept {
    this->value -= volume_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a volume rate with a given value expressed in the standard
  /// volume rate unit.
  explicit constexpr VolumeRate(const Number value)
    : DimensionalScalar<Unit::VolumeRate, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const VolumeRate<Number>& left, const VolumeRate<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const VolumeRate<Number>& left, const VolumeRate<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const VolumeRate<Number>& left, const VolumeRate<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const VolumeRate<Number>& left, const VolumeRate<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const VolumeRate<Number>& left, const VolumeRate<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const VolumeRate<Number>& left, const VolumeRate<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const VolumeRate<Number>& volume_rate) {
  stream << volume_rate.Print();
  return stream;
}

template <typename Number>
inline constexpr VolumeRate<Number> operator*(
    const Number number, const VolumeRate<Number>& volume_rate) {
  return volume_rate * number;
}

template <typename Number>
inline constexpr Volume<Number>::Volume(
    const VolumeRate<Number>& volume_rate, const Time<Number>& time)
  : Volume<Number>(volume_rate.Value() * time.Value()) {}

template <typename Number>
inline constexpr Volume<Number>::Volume(
    const VolumeRate<Number>& volume_rate, const Frequency<Number>& frequency)
  : Volume<Number>(volume_rate.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Time<Number>::Time(
    const Volume<Number>& volume, const VolumeRate<Number>& volume_rate)
  : Time<Number>(volume.Value() / volume_rate.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const VolumeRate<Number>& volume_rate, const Volume<Number>& volume)
  : Frequency<Number>(volume_rate.Value() / volume.Value()) {}

template <typename Number>
inline constexpr Volume<Number> Time<Number>::operator*(
    const VolumeRate<Number>& volume_rate) const {
  return Volume<Number>{volume_rate, *this};
}

template <typename Number>
inline constexpr VolumeRate<Number> Volume<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return VolumeRate<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Time<Number> Volume<Number>::operator/(
    const VolumeRate<Number>& volume_rate) const {
  return Time<Number>{*this, volume_rate};
}

template <typename Number>
inline constexpr VolumeRate<Number> Frequency<Number>::operator*(
    const Volume<Number>& volume) const {
  return VolumeRate<Number>{volume, *this};
}

template <typename Number>
inline constexpr VolumeRate<Number> Volume<Number>::operator/(const Time<Number>& time) const {
  return VolumeRate<Number>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::VolumeRate<Number>> {
  inline size_t operator()(const PhQ::VolumeRate<Number>& volume_rate) const {
    return hash<Number>()(volume_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUME_RATE_HPP
