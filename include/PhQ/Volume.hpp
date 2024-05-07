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

// Forward declarations for class Volume.
class Time;
class Frequency;
class Mass;
class MassDensity;
class VolumeRate;

// Volume.
class Volume : public DimensionalScalar<Unit::Volume, double> {
public:
  // Default constructor. Constructs a volume with an uninitialized value.
  Volume() = default;

  // Constructor. Constructs a volume with a given value expressed in a given volume unit.
  Volume(const double value, const Unit::Volume unit)
    : DimensionalScalar<Unit::Volume>(value, unit) {}

  // Constructor. Constructs a volume from a given area and length.
  constexpr Volume(const Area& area, const Length& length)
    : Volume(area.Value() * length.Value()) {}

  // Constructor. Constructs a volume from a given volume rate and time using the definition of
  // volume rate.
  constexpr Volume(const VolumeRate& volume_rate, const Time& time);

  // Constructor. Constructs a volume from a given volume rate and frequency using the definition of
  // volume rate.
  constexpr Volume(const VolumeRate& volume_rate, const Frequency& frequency);

  // Constructor. Constructs a volume from a given mass and mass density using the definition of
  // volume.
  constexpr Volume(const Mass& mass, const MassDensity& mass_density);

  // Destructor. Destroys this volume.
  ~Volume() noexcept = default;

  // Copy constructor. Constructs a volume by copying another one.
  constexpr Volume(const Volume& other) = default;

  // Move constructor. Constructs a volume by moving another one.
  constexpr Volume(Volume&& other) noexcept = default;

  // Copy assignment operator. Assigns this volume by copying another one.
  constexpr Volume& operator=(const Volume& other) = default;

  // Move assignment operator. Assigns this volume by moving another one.
  constexpr Volume& operator=(Volume&& other) noexcept = default;

  // Statically creates a volume of zero.
  static constexpr Volume Zero() {
    return Volume{0.0};
  }

  // Statically creates a volume with a given value expressed in a given volume unit.
  template <Unit::Volume Unit>
  static constexpr Volume Create(const double value) {
    return Volume{StaticConvertCopy<Unit::Volume, Unit, Standard<Unit::Volume>>(value)};
  }

  constexpr Volume operator+(const Volume& volume) const {
    return Volume{value + volume.value};
  }

  constexpr Volume operator-(const Volume& volume) const {
    return Volume{value - volume.value};
  }

  constexpr Volume operator*(const double number) const {
    return Volume{value * number};
  }

  constexpr Mass operator*(const MassDensity& mass_density) const;

  constexpr VolumeRate operator*(const Frequency& frequency) const;

  constexpr Volume operator/(const double number) const {
    return Volume{value / number};
  }

  constexpr Area operator/(const Length& length) const {
    return Area{*this, length};
  }

  constexpr Length operator/(const Area& area) const {
    return Length{*this, area};
  }

  constexpr VolumeRate operator/(const Time& time) const;

  constexpr Time operator/(const VolumeRate& volume_rate) const;

  constexpr double operator/(const Volume& volume) const noexcept {
    return value / volume.value;
  }

  constexpr void operator+=(const Volume& volume) noexcept {
    value += volume.value;
  }

  constexpr void operator-=(const Volume& volume) noexcept {
    value -= volume.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a volume with a given value expressed in the standard volume unit.
  explicit constexpr Volume(const double value) : DimensionalScalar<Unit::Volume>(value) {}
};

inline constexpr bool operator==(const Volume& left, const Volume& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Volume& left, const Volume& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Volume& left, const Volume& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Volume& left, const Volume& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Volume& left, const Volume& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Volume& left, const Volume& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Volume& volume) {
  stream << volume.Print();
  return stream;
}

inline constexpr Volume operator*(const double number, const Volume& volume) {
  return volume * number;
}

inline constexpr Length::Length(const Volume& volume, const Area& area)
  : Length(volume.Value() / area.Value()) {}

inline constexpr Area::Area(const Volume& volume, const Length& length)
  : Area(volume.Value() / length.Value()) {}

inline constexpr Volume Length::operator*(const Area& area) const {
  return Volume{area, *this};
}

inline constexpr Volume Area::operator*(const Length& length) const {
  return Volume{*this, length};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Volume> {
  inline size_t operator()(const PhQ::Volume& volume) const {
    return hash<double>()(volume.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUME_HPP
