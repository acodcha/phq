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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUME_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUME_HPP

#include "Area.hpp"
#include "Unit/Volume.hpp"

namespace PhQ {

// Forward declarations for class Volume.
class Time;
class Frequency;
class Mass;
class MassDensity;
class VolumeRate;

// Volume.
class Volume : public DimensionalScalarQuantity<Unit::Volume> {
public:
  Volume() = default;

  Volume(const double value, const Unit::Volume unit)
    : DimensionalScalarQuantity<Unit::Volume>(value, unit) {}

  constexpr Volume(const VolumeRate& volume_rate, const Time& time);

  constexpr Volume(const VolumeRate& volume_rate, const Frequency& frequency);

  constexpr Volume(const MassDensity& mass_density, const Mass& mass);

  static constexpr Volume Zero() {
    return Volume{0.0};
  }

  template <Unit::Volume Unit>
  static constexpr Volume Create(const double value) {
    return Volume{
        StaticConvertCopy<Unit::Volume, Unit, Standard<Unit::Volume>>(value)};
  }

  constexpr Volume operator+(const Volume& volume) const {
    return Volume{value_ + volume.value_};
  }

  constexpr Volume operator-(const Volume& volume) const {
    return Volume{value_ - volume.value_};
  }

  constexpr Volume operator*(const double number) const {
    return Volume{value_ * number};
  }

  constexpr Mass operator*(const MassDensity& mass_density) const;

  constexpr VolumeRate operator*(const Frequency& frequency) const;

  constexpr Volume operator/(const double number) const {
    return Volume{value_ / number};
  }

  constexpr Area operator/(const Length& length) const {
    return Area{value_ / length.Value()};
  }

  constexpr Length operator/(const Area& area) const {
    return Length{value_ / area.Value()};
  }

  constexpr VolumeRate operator/(const Time& time) const;

  constexpr Time operator/(const VolumeRate& volume_rate) const;

  constexpr double operator/(const Volume& volume) const noexcept {
    return value_ / volume.value_;
  }

  constexpr void operator+=(const Volume& volume) noexcept {
    value_ += volume.value_;
  }

  constexpr void operator-=(const Volume& volume) noexcept {
    value_ -= volume.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Volume(const double value)
    : DimensionalScalarQuantity<Unit::Volume>(value) {}

  friend class Length;
  friend class Area;
};

inline constexpr bool operator==(
    const Volume& left, const Volume& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Volume& left, const Volume& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Volume& left, const Volume& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Volume& left, const Volume& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Volume& left, const Volume& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Volume& left, const Volume& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Volume& volume) {
  stream << volume.Print();
  return stream;
}

inline constexpr Volume operator*(const double number, const Volume& volume) {
  return volume * number;
}

inline constexpr Volume Length::operator*(const Area& area) const {
  return Volume{value_ * area.Value()};
}

inline constexpr Volume Area::operator*(const Length& length) const {
  return Volume{value_ * length.Value()};
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUME_HPP
