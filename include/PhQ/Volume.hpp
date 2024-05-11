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

// Volume.
template <typename Number = double>
class Volume : public DimensionalScalar<Unit::Volume, Number> {
public:
  // Default constructor. Constructs a volume with an uninitialized value.
  Volume() = default;

  // Constructor. Constructs a volume with a given value expressed in a given volume unit.
  Volume(const Number value, const Unit::Volume unit)
    : DimensionalScalar<Unit::Volume, Number>(value, unit) {}

  // Constructor. Constructs a volume from a given area and length.
  constexpr Volume(const Area<Number>& area, const Length<Number>& length)
    : Volume<Number>(area.Value() * length.Value()) {}

  // Constructor. Constructs a volume from a given volume rate and time using the definition of
  // volume rate.
  constexpr Volume(const VolumeRate<Number>& volume_rate, const Time<Number>& time);

  // Constructor. Constructs a volume from a given volume rate and frequency using the definition of
  // volume rate.
  constexpr Volume(const VolumeRate<Number>& volume_rate, const Frequency<Number>& frequency);

  // Constructor. Constructs a volume from a given mass and mass density using the definition of
  // volume.
  constexpr Volume(const Mass<Number>& mass, const MassDensity<Number>& mass_density);

  // Destructor. Destroys this volume.
  ~Volume() noexcept = default;

  // Copy constructor. Constructs a volume by copying another one.
  constexpr Volume(const Volume<Number>& other) = default;

  // Copy constructor. Constructs a volume by copying another one.
  template <typename OtherNumber>
  explicit constexpr Volume(const Volume<OtherNumber>& other)
    : Volume(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a volume by moving another one.
  constexpr Volume(Volume<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this volume by copying another one.
  constexpr Volume<Number>& operator=(const Volume<Number>& other) = default;

  // Copy assignment operator. Assigns this volume by copying another one.
  template <typename OtherNumber>
  constexpr Volume<Number>& operator=(const Volume<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this volume by moving another one.
  constexpr Volume<Number>& operator=(Volume<Number>&& other) noexcept = default;

  // Statically creates a volume of zero.
  static constexpr Volume<Number> Zero() {
    return Volume<Number>{static_cast<Number>(0)};
  }

  // Statically creates a volume with a given value expressed in a given volume unit.
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
  // Constructor. Constructs a volume with a given value expressed in the standard volume unit.
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
