// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "ForceMagnitude.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declaration.
class Traction;

class Force : public DimensionalVectorQuantity<Unit::Force> {

public:

  constexpr Force() noexcept : DimensionalVectorQuantity<Unit::Force>() {}

  constexpr Force(const Value::Vector& value, Unit::Force unit) noexcept : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr Force(const ForceMagnitude& force_magnitude, const Direction& direction) noexcept : Force({force_magnitude.value() * direction.x(), force_magnitude.value() * direction.y(), force_magnitude.value() * direction.z()}) {}

  constexpr Force(const Traction& traction, const Area& area) noexcept;

  constexpr ForceMagnitude magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const Force& force) const noexcept {
    return {*this, force};
  }

  constexpr bool operator==(const Force& force) const noexcept {
    return value_ == force.value_;
  }

  constexpr bool operator!=(const Force& force) const noexcept {
    return value_ != force.value_;
  }

  constexpr Force operator+(const Force& force) const noexcept {
    return {value_ + force.value_};
  }

  constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  constexpr Force operator-(const Force& force) const noexcept {
    return {value_ - force.value_};
  }

  constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

  constexpr Traction operator/(const Area& area) const noexcept;

protected:

  constexpr Force(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Force>(value) {}

};

template <> constexpr bool sort(const Force& force_1, const Force& force_2) noexcept {
  return sort(force_1.value(), force_2.value());
}

constexpr Direction::Direction(const Force& force) : Direction(force.value()) {}

constexpr Angle::Angle(const Force& force_1, const Force& force_2) noexcept : Angle(force_1.angle(force_2)) {}

constexpr ForceMagnitude::ForceMagnitude(const Force& force) noexcept : ForceMagnitude(force.value().magnitude()) {}

constexpr Force Direction::operator*(const ForceMagnitude& force_magnitude) const noexcept {
  return {force_magnitude, *this};
}

constexpr Force ForceMagnitude::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ
