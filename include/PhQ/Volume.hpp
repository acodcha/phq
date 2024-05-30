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

#ifndef PHQ_VOLUME_HPP
#define PHQ_VOLUME_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "Unit/Volume.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Volume.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Volume.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Volume.
template <typename NumericType>
class Mass;

// Forward declaration for class PhQ::Volume.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::Volume.
template <typename NumericType>
class VolumeRate;

/// \brief Volume. For the time rate of change of volume, see PhQ::VolumeRate; see also PhQ::Time
/// and PhQ::Frequency.
template <typename NumericType = double>
class Volume : public DimensionalScalar<Unit::Volume, NumericType> {
public:
  /// \brief Default constructor. Constructs a volume with an uninitialized value.
  Volume() = default;

  /// \brief Constructor. Constructs a volume with a given value expressed in a given volume unit.
  Volume(const NumericType value, const Unit::Volume unit)
    : DimensionalScalar<Unit::Volume, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a volume from a given area and length.
  constexpr Volume(const Area<NumericType>& area, const Length<NumericType>& length)
    : Volume<NumericType>(area.Value() * length.Value()) {}

  /// \brief Constructor. Constructs a volume from a given volume rate and time using the definition
  /// of volume rate.
  constexpr Volume(const VolumeRate<NumericType>& volume_rate, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a volume from a given volume rate and frequency using the
  /// definition of volume rate.
  constexpr Volume(
      const VolumeRate<NumericType>& volume_rate, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a volume from a given mass and mass density using the
  /// definition of volume.
  constexpr Volume(const Mass<NumericType>& mass, const MassDensity<NumericType>& mass_density);

  /// \brief Destructor. Destroys this volume.
  ~Volume() noexcept = default;

  /// \brief Copy constructor. Constructs a volume by copying another one.
  constexpr Volume(const Volume<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a volume by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Volume(const Volume<OtherNumericType>& other)
    : Volume(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a volume by moving another one.
  constexpr Volume(Volume<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this volume by copying another one.
  constexpr Volume<NumericType>& operator=(const Volume<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this volume by copying another one.
  template <typename OtherNumericType>
  constexpr Volume<NumericType>& operator=(const Volume<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this volume by moving another one.
  constexpr Volume<NumericType>& operator=(Volume<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a volume of zero.
  static constexpr Volume<NumericType> Zero() {
    return Volume<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a volume with a given value expressed in a given volume unit.
  template <Unit::Volume Unit>
  static constexpr Volume<NumericType> Create(const NumericType value) {
    return Volume<NumericType>{
        StaticConvertCopy<Unit::Volume, Unit, Standard<Unit::Volume>>(value)};
  }

  constexpr Volume<NumericType> operator+(const Volume<NumericType>& volume) const {
    return Volume<NumericType>{this->value + volume.value};
  }

  constexpr Volume<NumericType> operator-(const Volume<NumericType>& volume) const {
    return Volume<NumericType>{this->value - volume.value};
  }

  constexpr Volume<NumericType> operator*(const NumericType number) const {
    return Volume<NumericType>{this->value * number};
  }

  constexpr Mass<NumericType> operator*(const MassDensity<NumericType>& mass_density) const;

  constexpr VolumeRate<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Volume<NumericType> operator/(const NumericType number) const {
    return Volume<NumericType>{this->value / number};
  }

  constexpr Area<NumericType> operator/(const Length<NumericType>& length) const {
    return Area<NumericType>{*this, length};
  }

  constexpr Length<NumericType> operator/(const Area<NumericType>& area) const {
    return Length<NumericType>{*this, area};
  }

  constexpr VolumeRate<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const VolumeRate<NumericType>& volume_rate) const;

  constexpr NumericType operator/(const Volume<NumericType>& volume) const noexcept {
    return this->value / volume.value;
  }

  constexpr void operator+=(const Volume<NumericType>& volume) noexcept {
    this->value += volume.value;
  }

  constexpr void operator-=(const Volume<NumericType>& volume) noexcept {
    this->value -= volume.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a volume with a given value expressed in the standard volume
  /// unit.
  explicit constexpr Volume(const NumericType value)
    : DimensionalScalar<Unit::Volume, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Volume<NumericType>& left, const Volume<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Volume<NumericType>& left, const Volume<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Volume<NumericType>& left, const Volume<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Volume<NumericType>& left, const Volume<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Volume<NumericType>& left, const Volume<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Volume<NumericType>& left, const Volume<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Volume<NumericType>& volume) {
  stream << volume.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Volume<NumericType> operator*(
    const NumericType number, const Volume<NumericType>& volume) {
  return volume * number;
}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const Volume<NumericType>& volume, const Area<NumericType>& area)
  : Length<NumericType>(volume.Value() / area.Value()) {}

template <typename NumericType>
inline constexpr Area<NumericType>::Area(
    const Volume<NumericType>& volume, const Length<NumericType>& length)
  : Area<NumericType>(volume.Value() / length.Value()) {}

template <typename NumericType>
inline constexpr Volume<NumericType> Length<NumericType>::operator*(
    const Area<NumericType>& area) const {
  return Volume<NumericType>{area, *this};
}

template <typename NumericType>
inline constexpr Volume<NumericType> Area<NumericType>::operator*(
    const Length<NumericType>& length) const {
  return Volume<NumericType>{*this, length};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Volume<NumericType>> {
  inline size_t operator()(const PhQ::Volume<NumericType>& volume) const {
    return hash<NumericType>()(volume.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUME_HPP
