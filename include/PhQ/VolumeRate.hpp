// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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

// Volume rate. Can represent a time rate of change of a volume or a volume flow rate.
template <typename Number = double>
class VolumeRate : public DimensionalScalar<Unit::VolumeRate, Number> {
public:
  // Default constructor. Constructs a volume rate with an uninitialized value.
  VolumeRate() = default;

  // Constructor. Constructs a volume rate with a given value expressed in a given volume rate unit.
  VolumeRate(const Number value, const Unit::VolumeRate unit)
    : DimensionalScalar<Unit::VolumeRate, Number>(value, unit) {}

  // Constructor. Constructs a volume rate from a given volume and time using the definition of
  // volume rate.
  constexpr VolumeRate(const Volume<Number>& volume, const Time<Number>& time)
    : VolumeRate<Number>(volume.Value() / time.Value()) {}

  // Constructor. Constructs a volume rate from a given volume and frequency using the definition of
  // volume rate.
  constexpr VolumeRate(const Volume<Number>& volume, const Frequency<Number>& frequency)
    : VolumeRate<Number>(volume.Value() * frequency.Value()) {}

  // Destructor. Destroys this volume rate.
  ~VolumeRate() noexcept = default;

  // Copy constructor. Constructs a volume rate by copying another one.
  constexpr VolumeRate(const VolumeRate<Number>& other) = default;

  // Copy constructor. Constructs a volume rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr VolumeRate(const VolumeRate<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a volume rate by moving another one.
  constexpr VolumeRate(VolumeRate<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this volume rate by copying another one.
  constexpr VolumeRate<Number>& operator=(const VolumeRate<Number>& other) = default;

  // Copy assignment operator. Assigns this volume rate by copying another one.
  template <typename OtherNumber>
  constexpr VolumeRate<Number>& operator=(const VolumeRate<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this volume rate by moving another one.
  constexpr VolumeRate<Number>& operator=(VolumeRate<Number>&& other) noexcept = default;

  // Statically creates a volume rate of zero.
  static constexpr VolumeRate<Number> Zero() {
    return VolumeRate<Number>{static_cast<Number>(0)};
  }

  // Statically creates a volume rate with a given value expressed in a given volume rate unit.
  template <Unit::VolumeRate Unit>
  static constexpr VolumeRate<Number> Create(const Number value) {
    return VolumeRate<Number>{
        StaticConvertCopy<Unit::VolumeRate, Unit, Standard<Unit::VolumeRate>>(value)};
  }

  constexpr VolumeRate<Number> operator+(const VolumeRate<Number>& volume_rate) const {
    return VolumeRate<Number>{value + volume_rate.value};
  }

  constexpr VolumeRate<Number> operator-(const VolumeRate<Number>& volume_rate) const {
    return VolumeRate<Number>{value - volume_rate.value};
  }

  constexpr VolumeRate<Number> operator*(const Number number) const {
    return VolumeRate<Number>{value * number};
  }

  constexpr Volume<Number> operator*(const Time<Number>& time) const {
    return Volume<Number>{*this, time};
  }

  constexpr VolumeRate<Number> operator/(const Number number) const {
    return VolumeRate<Number>{value / number};
  }

  constexpr Volume<Number> operator/(const Frequency<Number>& frequency) const {
    return Volume<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Volume<Number>& volume) const {
    return Frequency<Number>{*this, volume};
  }

  constexpr Number operator/(const VolumeRate<Number>& volume_rate) const noexcept {
    return value / volume_rate.value;
  }

  constexpr void operator+=(const VolumeRate<Number>& volume_rate) noexcept {
    value += volume_rate.value;
  }

  constexpr void operator-=(const VolumeRate<Number>& volume_rate) noexcept {
    value -= volume_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a volume rate with a given value expressed in the standard volume rate
  // unit.
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
