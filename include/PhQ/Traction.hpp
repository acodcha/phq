// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Force.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

class Traction : public DimensionalVectorQuantity<Unit::Pressure> {

public:

  constexpr Traction() noexcept : DimensionalVectorQuantity<Unit::Pressure>() {}

  constexpr Traction(const Value::Vector& value, Unit::Pressure unit) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value, unit) {}

  constexpr Traction(const StaticPressure& static_pressure, const Direction& direction) noexcept : Traction({-static_pressure.value() * direction.x(), -static_pressure.value() * direction.y(), -static_pressure.value() * direction.z()}) {}

  constexpr Traction(const Force& force, const Area& area) noexcept : Traction(force.value() / area.value()) {}

  constexpr Traction(const Stress& stress, const Direction& direction) noexcept;

  constexpr StaticPressure magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const Traction& traction) const noexcept {
    return {*this, traction};
  }

  constexpr bool operator==(const Traction& traction) const noexcept {
    return value_ == traction.value_;
  }

  constexpr bool operator!=(const Traction& traction) const noexcept {
    return value_ != traction.value_;
  }

  constexpr Traction operator+(const Traction& traction) const noexcept {
    return {value_ + traction.value_};
  }

  constexpr void operator+=(const Traction& traction) noexcept {
    value_ += traction.value_;
  }

  constexpr Traction operator-(const Traction& traction) const noexcept {
    return {value_ - traction.value_};
  }

  constexpr void operator-=(const Traction& traction) noexcept {
    value_ -= traction.value_;
  }

  constexpr Force operator*(const Area& area) const noexcept {
    return {*this, area};
  }

protected:

  constexpr Traction(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const Traction& traction_1, const Traction& traction_2) noexcept {
  return sort(traction_1.value(), traction_2.value());
}

constexpr Direction::Direction(const Traction& traction) : Direction(traction.value()) {}

constexpr Angle::Angle(const Traction& traction_1, const Traction& traction_2) noexcept : Angle(traction_1.value(), traction_2.value()) {}

constexpr StaticPressure::StaticPressure(const Traction& traction) noexcept : StaticPressure(traction.value().magnitude()) {}

constexpr Force::Force(const Traction& traction, const Area& area) noexcept : Force(traction.value() * area.value()) {}

constexpr Traction Direction::operator*(const StaticPressure& static_pressure) const noexcept {
  return {static_pressure, *this};
}

constexpr Traction StaticPressure::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

constexpr Traction Force::operator/(const Area& area) const noexcept {
  return {*this, area};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Traction> {
  size_t operator()(const PhQ::Traction& traction) const {
    return hash<PhQ::Value::Vector>()(traction.value());
  }
};

} // namespace std
