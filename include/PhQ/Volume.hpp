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
template <typename Number>
class Time;

// Forward declaration for class PhQ::Volume.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Volume.
template <typename Number>
class Mass;

// Forward declaration for class PhQ::Volume.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::Volume.
template <typename Number>
class VolumeRate;

/// \brief Volume.
template <typename Number = double>
class Volume : public DimensionalScalar<Unit::Volume, Number> {
public:
  /// \brief Default constructor. Constructs a volume with an uninitialized value.
  Volume() = default;

  /// \brief Constructor. Constructs a volume with a given value expressed in a given volume unit.
  Volume(const Number value, const Unit::Volume unit)
    : DimensionalScalar<Unit::Volume, Number>(value, unit) {}

  /// \brief Constructor. Constructs a volume from a given area and length.
  constexpr Volume(const Area<Number>& area, const Length<Number>& length)
    : Volume<Number>(area.Value() * length.Value()) {}

  /// \brief Constructor. Constructs a volume from a given volume rate and time using the definition
  /// of volume rate.
  constexpr Volume(const VolumeRate<Number>& volume_rate, const Time<Number>& time);

  /// \brief Constructor. Constructs a volume from a given volume rate and frequency using the
  /// definition of volume rate.
  constexpr Volume(const VolumeRate<Number>& volume_rate, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs a volume from a given mass and mass density using the
  /// definition of volume.
  constexpr Volume(const Mass<Number>& mass, const MassDensity<Number>& mass_density);

  /// \brief Destructor. Destroys this volume.
  ~Volume() noexcept = default;

  /// \brief Copy constructor. Constructs a volume by copying another one.
  constexpr Volume(const Volume<Number>& other) = default;

  /// \brief Copy constructor. Constructs a volume by copying another one.
  template <typename OtherNumber>
  explicit constexpr Volume(const Volume<OtherNumber>& other)
    : Volume(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a volume by moving another one.
  constexpr Volume(Volume<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this volume by copying another one.
  constexpr Volume<Number>& operator=(const Volume<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this volume by copying another one.
  template <typename OtherNumber>
  constexpr Volume<Number>& operator=(const Volume<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this volume by moving another one.
  constexpr Volume<Number>& operator=(Volume<Number>&& other) noexcept = default;

  /// \brief Statically creates a volume of zero.
  static constexpr Volume<Number> Zero() {
    return Volume<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a volume with a given value expressed in a given volume unit.
  template <Unit::Volume Unit>
  static constexpr Volume<Number> Create(const Number value) {
    return Volume<Number>{StaticConvertCopy<Unit::Volume, Unit, Standard<Unit::Volume>>(value)};
  }

  constexpr Volume<Number> operator+(const Volume<Number>& volume) const {
    return Volume<Number>{this->value + volume.value};
  }

  constexpr Volume<Number> operator-(const Volume<Number>& volume) const {
    return Volume<Number>{this->value - volume.value};
  }

  constexpr Volume<Number> operator*(const Number number) const {
    return Volume<Number>{this->value * number};
  }

  constexpr Mass<Number> operator*(const MassDensity<Number>& mass_density) const;

  constexpr VolumeRate<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Volume<Number> operator/(const Number number) const {
    return Volume<Number>{this->value / number};
  }

  constexpr Area<Number> operator/(const Length<Number>& length) const {
    return Area<Number>{*this, length};
  }

  constexpr Length<Number> operator/(const Area<Number>& area) const {
    return Length<Number>{*this, area};
  }

  constexpr VolumeRate<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const VolumeRate<Number>& volume_rate) const;

  constexpr Number operator/(const Volume<Number>& volume) const noexcept {
    return this->value / volume.value;
  }

  constexpr void operator+=(const Volume<Number>& volume) noexcept {
    this->value += volume.value;
  }

  constexpr void operator-=(const Volume<Number>& volume) noexcept {
    this->value -= volume.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a volume with a given value expressed in the standard volume
  /// unit.
  explicit constexpr Volume(const Number value) : DimensionalScalar<Unit::Volume, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Volume<Number>& left, const Volume<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Volume<Number>& left, const Volume<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Volume<Number>& left, const Volume<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Volume<Number>& left, const Volume<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Volume<Number>& left, const Volume<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Volume<Number>& left, const Volume<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Volume<Number>& volume) {
  stream << volume.Print();
  return stream;
}

template <typename Number>
inline constexpr Volume<Number> operator*(const Number number, const Volume<Number>& volume) {
  return volume * number;
}

template <typename Number>
inline constexpr Length<Number>::Length(const Volume<Number>& volume, const Area<Number>& area)
  : Length<Number>(volume.Value() / area.Value()) {}

template <typename Number>
inline constexpr Area<Number>::Area(const Volume<Number>& volume, const Length<Number>& length)
  : Area<Number>(volume.Value() / length.Value()) {}

template <typename Number>
inline constexpr Volume<Number> Length<Number>::operator*(const Area<Number>& area) const {
  return Volume<Number>{area, *this};
}

template <typename Number>
inline constexpr Volume<Number> Area<Number>::operator*(const Length<Number>& length) const {
  return Volume<Number>{*this, length};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Volume<Number>> {
  inline size_t operator()(const PhQ::Volume<Number>& volume) const {
    return hash<Number>()(volume.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUME_HPP
