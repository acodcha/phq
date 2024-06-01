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

#ifndef PHQ_MACH_NUMBER_HPP
#define PHQ_MACH_NUMBER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"
#include "SoundSpeed.hpp"
#include "Speed.hpp"

namespace PhQ {

/// \brief Mach number of a fluid flow. Measures the local compressibility of a fluid flow.
/// Represents the ratio of a fluid's local speed to its local speed of sound. See also PhQ::Speed
/// and PhQ::SoundSpeed.
template <typename NumericType = double>
class MachNumber : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a Mach number with an uninitialized value.
  MachNumber() = default;

  /// \brief Constructor. Constructs a Mach number with a given value.
  explicit constexpr MachNumber(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Constructor. Constructs a Mach number from a given speed and sound speed using the
  /// definition of the Mach number.
  constexpr MachNumber(const Speed<NumericType>& speed, const SoundSpeed<NumericType>& sound_speed)
    : MachNumber<NumericType>(speed.Value() / sound_speed.Value()) {}

  /// \brief Destructor. Destroys this Mach number.
  ~MachNumber() noexcept = default;

  /// \brief Copy constructor. Constructs a Mach number by copying another one.
  constexpr MachNumber(const MachNumber<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a Mach number by copying another one.
  template <typename OtherNumericType>
  explicit constexpr MachNumber(const MachNumber<OtherNumericType>& other)
    : MachNumber(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a Mach number by moving another one.
  constexpr MachNumber(MachNumber<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Mach number by copying another one.
  constexpr MachNumber<NumericType>& operator=(const MachNumber<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this Mach number by copying another one.
  template <typename OtherNumericType>
  constexpr MachNumber<NumericType>& operator=(const MachNumber<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Mach number by moving another one.
  constexpr MachNumber<NumericType>& operator=(MachNumber<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a Mach number of zero.
  static constexpr MachNumber<NumericType> Zero() {
    return MachNumber<NumericType>{static_cast<NumericType>(0)};
  }

  constexpr MachNumber<NumericType> operator+(const MachNumber<NumericType>& mach_number) const {
    return MachNumber<NumericType>{this->value + mach_number.value};
  }

  constexpr MachNumber<NumericType> operator-(const MachNumber<NumericType>& mach_number) const {
    return MachNumber<NumericType>{this->value - mach_number.value};
  }

  constexpr MachNumber<NumericType> operator*(const NumericType number) const {
    return MachNumber<NumericType>{this->value * number};
  }

  constexpr Speed<NumericType> operator*(const SoundSpeed<NumericType>& sound_speed) const {
    return Speed<NumericType>{sound_speed, *this};
  }

  constexpr MachNumber<NumericType> operator/(const NumericType number) const {
    return MachNumber<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const MachNumber<NumericType>& mach_number) const noexcept {
    return this->value / mach_number.value;
  }

  constexpr void operator+=(const MachNumber<NumericType>& mach_number) noexcept {
    this->value += mach_number.value;
  }

  constexpr void operator-=(const MachNumber<NumericType>& mach_number) noexcept {
    this->value -= mach_number.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(
    const MachNumber<NumericType>& left, const MachNumber<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const MachNumber<NumericType>& left, const MachNumber<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const MachNumber<NumericType>& left, const MachNumber<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const MachNumber<NumericType>& left, const MachNumber<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const MachNumber<NumericType>& left, const MachNumber<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const MachNumber<NumericType>& left, const MachNumber<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const MachNumber<NumericType>& mach_number) {
  stream << mach_number.Print();
  return stream;
}

template <typename NumericType>
inline constexpr MachNumber<NumericType> operator*(
    const NumericType number, const MachNumber<NumericType>& mach_number) {
  return MachNumber<NumericType>{number * mach_number.Value()};
}

template <typename NumericType>
constexpr SoundSpeed<NumericType>::SoundSpeed(
    const Speed<NumericType>& speed, const MachNumber<NumericType>& mach_number)
  : SoundSpeed<NumericType>(speed.Value() / mach_number.Value()) {}

template <typename NumericType>
constexpr Speed<NumericType>::Speed(
    const SoundSpeed<NumericType>& sound_speed, const MachNumber<NumericType>& mach_number)
  : Speed<NumericType>(sound_speed.Value() * mach_number.Value()) {}

template <typename NumericType>
inline constexpr Speed<NumericType> SoundSpeed<NumericType>::operator*(
    const MachNumber<NumericType>& mach_number) const {
  return Speed<NumericType>{*this, mach_number};
}

template <typename NumericType>
inline constexpr MachNumber<NumericType> Speed<NumericType>::operator/(
    const SoundSpeed<NumericType>& sound_speed) const {
  return MachNumber<NumericType>{*this, sound_speed};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::MachNumber<NumericType>> {
  inline size_t operator()(const PhQ::MachNumber<NumericType>& mach_number) const {
    return hash<NumericType>()(mach_number.Value());
  }
};

}  // namespace std

#endif  // PHQ_MACH_NUMBER_HPP
