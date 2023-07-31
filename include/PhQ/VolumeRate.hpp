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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUME_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUME_RATE_HPP

#include "Frequency.hpp"
#include "Unit/VolumeRate.hpp"
#include "Volume.hpp"

namespace PhQ {

// Volume rate. Can represent a time rate of change of a volume or a volume flow
// rate.
class VolumeRate : public DimensionalScalarQuantity<Unit::VolumeRate> {
public:
  constexpr VolumeRate() noexcept
    : DimensionalScalarQuantity<Unit::VolumeRate>() {}

  VolumeRate(const double value, const Unit::VolumeRate unit) noexcept
    : DimensionalScalarQuantity<Unit::VolumeRate>(value, unit) {}

  constexpr VolumeRate(const Volume& volume, const Time& time) noexcept
    : VolumeRate(volume.Value() / time.Value()) {}

  constexpr VolumeRate(
      const Volume& volume, const Frequency& frequency) noexcept
    : VolumeRate(volume.Value() * frequency.Value()) {}

  static constexpr VolumeRate Zero() noexcept { return VolumeRate{0.0}; }

  template<Unit::VolumeRate Unit>
  static constexpr VolumeRate Create(const double value) noexcept {
    return VolumeRate{StaticConvertCopy<Unit::VolumeRate, Unit,
                                        StandardUnit<Unit::VolumeRate>>(value)};
  }

  inline constexpr VolumeRate operator+(
      const VolumeRate& volume_rate) const noexcept {
    return VolumeRate{value_ + volume_rate.value_};
  }

  inline constexpr VolumeRate operator-(
      const VolumeRate& volume_rate) const noexcept {
    return VolumeRate{value_ - volume_rate.value_};
  }

  inline constexpr VolumeRate operator*(const double number) const noexcept {
    return VolumeRate{value_ * number};
  }

  inline constexpr Volume operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline constexpr VolumeRate operator/(const double number) const noexcept {
    return VolumeRate{value_ / number};
  }

  inline constexpr Volume operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr Frequency operator/(const Volume& volume) const noexcept {
    return {*this, volume};
  }

  inline constexpr double operator/(
      const VolumeRate& volume_rate) const noexcept {
    return value_ / volume_rate.value_;
  }

  inline constexpr void operator+=(const VolumeRate& volume_rate) noexcept {
    value_ += volume_rate.value_;
  }

  inline constexpr void operator-=(const VolumeRate& volume_rate) noexcept {
    value_ -= volume_rate.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr VolumeRate(const double value) noexcept
    : DimensionalScalarQuantity<Unit::VolumeRate>(value) {}
};

inline constexpr bool operator==(
    const VolumeRate& left, const VolumeRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const VolumeRate& left, const VolumeRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const VolumeRate& left, const VolumeRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const VolumeRate& left, const VolumeRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const VolumeRate& left, const VolumeRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const VolumeRate& left, const VolumeRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const VolumeRate& volume_rate) noexcept {
  stream << volume_rate.Print();
  return stream;
}

inline constexpr VolumeRate operator*(
    const double number, const VolumeRate& volume_rate) noexcept {
  return volume_rate * number;
}

inline constexpr Volume::Volume(
    const VolumeRate& volume_rate, const Time& time) noexcept
  : Volume(volume_rate.Value() * time.Value()) {}

inline constexpr Volume::Volume(
    const VolumeRate& volume_rate, const Frequency& frequency) noexcept
  : Volume(volume_rate.Value() / frequency.Value()) {}

inline constexpr Time::Time(
    const VolumeRate& volume_rate, const Volume& volume) noexcept
  : Time(volume.Value() / volume_rate.Value()) {}

inline constexpr Frequency::Frequency(
    const VolumeRate& volume_rate, const Volume& volume) noexcept
  : Frequency(volume_rate.Value() / volume.Value()) {}

inline constexpr Volume Time::operator*(
    const VolumeRate& volume_rate) const noexcept {
  return {volume_rate, *this};
}

inline constexpr VolumeRate Volume::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr Time Volume::operator/(
    const VolumeRate& volume_rate) const noexcept {
  return {volume_rate, *this};
}

inline constexpr VolumeRate Frequency::operator*(
    const Volume& volume) const noexcept {
  return {volume, *this};
}

inline constexpr VolumeRate Volume::operator/(const Time& time) const noexcept {
  return {*this, time};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::VolumeRate> {
  size_t operator()(const PhQ::VolumeRate& volume_rate) const {
    return hash<double>()(volume_rate.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUME_RATE_HPP
