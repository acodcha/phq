// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Direction.hpp"
#include "ForceMagnitude.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declaration.
class Traction;

class Force : public DimensionalVectorQuantity<Unit::Force> {

public:

  constexpr Force() noexcept : DimensionalVectorQuantity<Unit::Force>() {}

  Force(const Value::Vector& value, Unit::Force unit) noexcept : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr Force(const ForceMagnitude& force_magnitude, const Direction& direction) noexcept : Force(force_magnitude.Value() * direction.Value()) {}

  constexpr Force(const Traction& traction, const Area& area) noexcept;

  ForceMagnitude Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const Force& force) const noexcept {
    return {*this, force};
  }

  constexpr bool operator==(const Force& force) const noexcept {
    return value_ == force.value_;
  }

  constexpr bool operator!=(const Force& force) const noexcept {
    return value_ != force.value_;
  }

  Force operator+(const Force& force) const noexcept {
    return {value_ + force.value_};
  }

  constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  Force operator-(const Force& force) const noexcept {
    return {value_ - force.value_};
  }

  constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

  Traction operator/(const Area& area) const noexcept;

protected:

  constexpr Force(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Force>(value) {}

};

Direction::Direction(const Force& force) noexcept : Direction(force.Value()) {}

Angle::Angle(const Force& force_1, const Force& force_2) noexcept : Angle(force_1.Value(), force_2.Value()) {}

ForceMagnitude::ForceMagnitude(const Force& force) noexcept : ForceMagnitude(force.Value().Magnitude()) {}

Force Direction::operator*(const ForceMagnitude& force_magnitude) const noexcept {
  return {force_magnitude, *this};
}

Force ForceMagnitude::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Force> {
  size_t operator()(const PhQ::Force& force) const {
    return hash<PhQ::Value::Vector>()(force.Value());
  }
};

} // namespace std
