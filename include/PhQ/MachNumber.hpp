// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_MACH_NUMBER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_MACH_NUMBER_HPP

#include "DimensionlessScalarQuantity.hpp"
#include "SoundSpeed.hpp"
#include "Speed.hpp"

namespace PhQ {

// Mach number of a fluid flow.
class MachNumber : public DimensionlessScalarQuantity {
public:
  // Default constructor. Constructs a Mach number with an uninitialized value.
  MachNumber() = default;

  // Constructor. Constructs a Mach number with a given value.
  explicit constexpr MachNumber(const double value)
    : DimensionlessScalarQuantity(value) {}

  // Constructor. Constructs a Mach number from a given speed and sound speed
  // using the definition of the Mach number.
  constexpr MachNumber(const Speed& speed, const SoundSpeed& sound_speed)
    : MachNumber(speed.Value() / sound_speed.Value()) {}

  // Destructor. Destroys this Mach number.
  ~MachNumber() noexcept = default;

  // Copy constructor. Constructs a Mach number by copying another one.
  constexpr MachNumber(const MachNumber& other) = default;

  // Move constructor. Constructs a Mach number by moving another one.
  constexpr MachNumber(MachNumber&& other) noexcept = default;

  // Copy assignment operator. Assigns this Mach number by copying another one.
  constexpr MachNumber& operator=(const MachNumber& other) = default;

  // Move assignment operator. Assigns this Mach number by moving another one.
  constexpr MachNumber& operator=(MachNumber&& other) noexcept = default;

  // Statically creates a Mach number of zero.
  static constexpr MachNumber Zero() {
    return MachNumber{0.0};
  }

  constexpr MachNumber operator+(const MachNumber& mach_number) const {
    return MachNumber{value_ + mach_number.value_};
  }

  constexpr MachNumber operator-(const MachNumber& mach_number) const {
    return MachNumber{value_ - mach_number.value_};
  }

  constexpr MachNumber operator*(const double number) const {
    return MachNumber{value_ * number};
  }

  constexpr MachNumber operator/(const double number) const {
    return MachNumber{value_ / number};
  }

  constexpr double operator/(const MachNumber& mach_number) const noexcept {
    return value_ / mach_number.value_;
  }

  constexpr void operator+=(const MachNumber& mach_number) noexcept {
    value_ += mach_number.value_;
  }

  constexpr void operator-=(const MachNumber& mach_number) noexcept {
    value_ -= mach_number.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const MachNumber& left, const MachNumber& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const MachNumber& left, const MachNumber& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const MachNumber& left, const MachNumber& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const MachNumber& left, const MachNumber& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const MachNumber& left, const MachNumber& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const MachNumber& left, const MachNumber& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const MachNumber& mach_number) {
  stream << mach_number.Print();
  return stream;
}

inline constexpr MachNumber operator*(
    const double number, const MachNumber& mach_number) {
  return MachNumber{number * mach_number.Value()};
}

constexpr SoundSpeed::SoundSpeed(
    const Speed& speed, const MachNumber& mach_number)
  : SoundSpeed(speed.Value() / mach_number.Value()) {}

constexpr Speed::Speed(
    const SoundSpeed& sound_speed, const MachNumber& mach_number)
  : Speed(sound_speed.Value() * mach_number.Value()) {}

inline constexpr MachNumber Speed::operator/(
    const SoundSpeed& sound_speed) const {
  return {*this, sound_speed};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::MachNumber> {
  inline size_t operator()(const PhQ::MachNumber& mach_number) const {
    return hash<double>()(mach_number.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_MACH_NUMBER_HPP
