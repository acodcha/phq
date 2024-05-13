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

#ifndef PHQ_MACH_NUMBER_HPP
#define PHQ_MACH_NUMBER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"
#include "SoundSpeed.hpp"
#include "Speed.hpp"

namespace PhQ {

// Mach number of a fluid flow.
template <typename Number = double>
class MachNumber : public DimensionlessScalar<Number> {
public:
  // Default constructor. Constructs a Mach number with an uninitialized value.
  MachNumber() = default;

  // Constructor. Constructs a Mach number with a given value.
  explicit constexpr MachNumber(const Number value) : DimensionlessScalar<Number>(value) {}

  // Constructor. Constructs a Mach number from a given speed and sound speed using the definition
  // of the Mach number.
  constexpr MachNumber(const Speed<Number>& speed, const SoundSpeed<Number>& sound_speed)
    : MachNumber<Number>(speed.Value() / sound_speed.Value()) {}

  // Destructor. Destroys this Mach number.
  ~MachNumber() noexcept = default;

  // Copy constructor. Constructs a Mach number by copying another one.
  constexpr MachNumber(const MachNumber<Number>& other) = default;

  // Copy constructor. Constructs a Mach number by copying another one.
  template <typename OtherNumber>
  explicit constexpr MachNumber(const MachNumber<OtherNumber>& other)
    : MachNumber(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a Mach number by moving another one.
  constexpr MachNumber(MachNumber<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this Mach number by copying another one.
  constexpr MachNumber<Number>& operator=(const MachNumber<Number>& other) = default;

  // Copy assignment operator. Assigns this Mach number by copying another one.
  template <typename OtherNumber>
  constexpr MachNumber<Number>& operator=(const MachNumber<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this Mach number by moving another one.
  constexpr MachNumber<Number>& operator=(MachNumber<Number>&& other) noexcept = default;

  // Statically creates a Mach number of zero.
  static constexpr MachNumber<Number> Zero() {
    return MachNumber<Number>{static_cast<Number>(0)};
  }

  constexpr MachNumber<Number> operator+(const MachNumber<Number>& mach_number) const {
    return MachNumber<Number>{this->value + mach_number.value};
  }

  constexpr MachNumber<Number> operator-(const MachNumber<Number>& mach_number) const {
    return MachNumber<Number>{this->value - mach_number.value};
  }

  constexpr MachNumber<Number> operator*(const Number number) const {
    return MachNumber<Number>{this->value * number};
  }

  constexpr Speed<Number> operator*(const SoundSpeed<Number>& sound_speed) const {
    return Speed<Number>{sound_speed, *this};
  }

  constexpr MachNumber<Number> operator/(const Number number) const {
    return MachNumber<Number>{this->value / number};
  }

  constexpr Number operator/(const MachNumber<Number>& mach_number) const noexcept {
    return this->value / mach_number.value;
  }

  constexpr void operator+=(const MachNumber<Number>& mach_number) noexcept {
    this->value += mach_number.value;
  }

  constexpr void operator-=(const MachNumber<Number>& mach_number) noexcept {
    this->value -= mach_number.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(
    const MachNumber<Number>& left, const MachNumber<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const MachNumber<Number>& left, const MachNumber<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const MachNumber<Number>& left, const MachNumber<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const MachNumber<Number>& left, const MachNumber<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const MachNumber<Number>& left, const MachNumber<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const MachNumber<Number>& left, const MachNumber<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const MachNumber<Number>& mach_number) {
  stream << mach_number.Print();
  return stream;
}

template <typename Number>
inline constexpr MachNumber<Number> operator*(
    const Number number, const MachNumber<Number>& mach_number) {
  return MachNumber<Number>{number * mach_number.Value()};
}

template <typename Number>
constexpr SoundSpeed<Number>::SoundSpeed(
    const Speed<Number>& speed, const MachNumber<Number>& mach_number)
  : SoundSpeed<Number>(speed.Value() / mach_number.Value()) {}

template <typename Number>
constexpr Speed<Number>::Speed(
    const SoundSpeed<Number>& sound_speed, const MachNumber<Number>& mach_number)
  : Speed<Number>(sound_speed.Value() * mach_number.Value()) {}

template <typename Number>
inline constexpr Speed<Number> SoundSpeed<Number>::operator*(
    const MachNumber<Number>& mach_number) const {
  return Speed<Number>{*this, mach_number};
}

template <typename Number>
inline constexpr MachNumber<Number> Speed<Number>::operator/(
    const SoundSpeed<Number>& sound_speed) const {
  return MachNumber<Number>{*this, sound_speed};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::MachNumber<Number>> {
  inline size_t operator()(const PhQ::MachNumber<Number>& mach_number) const {
    return hash<Number>()(mach_number.Value());
  }
};

}  // namespace std

#endif  // PHQ_MACH_NUMBER_HPP
