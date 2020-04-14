// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Memory.hpp"

namespace PhQ {

// Forward declaration.
class Duration;
class Frequency;
class MemoryRate;

class Memory : public DimensionalScalarQuantity<Unit::Memory> {

public:

  constexpr Memory() noexcept : DimensionalScalarQuantity<Unit::Memory>() {}

  constexpr Memory(double value, Unit::Memory unit) noexcept : DimensionalScalarQuantity<Unit::Memory>(value, unit) {}

  constexpr bool operator==(const Memory& memory) const noexcept {
    return value_ == memory.value_;
  }

  constexpr bool operator!=(const Memory& memory) const noexcept {
    return value_ != memory.value_;
  }

  constexpr bool operator<(const Memory& memory) const noexcept {
    return value_ < memory.value_;
  }

  constexpr bool operator<=(const Memory& memory) const noexcept {
    return value_ <= memory.value_;
  }

  constexpr bool operator>(const Memory& memory) const noexcept {
    return value_ > memory.value_;
  }

  constexpr bool operator>=(const Memory& memory) const noexcept {
    return value_ >= memory.value_;
  }

  Memory operator+(const Memory& memory) const noexcept {
    return {value_ + memory.value_};
  }

  constexpr void operator+=(const Memory& memory) noexcept {
    value_ += memory.value_;
  }

  Memory operator-(const Memory& memory) const noexcept {
    return {value_ - memory.value_};
  }

  constexpr void operator-=(const Memory& memory) noexcept {
    value_ -= memory.value_;
  }

  constexpr MemoryRate operator*(const Frequency& frequency) const noexcept;

  MemoryRate operator/(const Duration& duration) const;

protected:

  constexpr Memory(double value) noexcept : DimensionalScalarQuantity<Unit::Memory>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class MemoryRate;

};

template <> constexpr bool sort(const Memory& memory_1, const Memory& memory_2) noexcept {
  return memory_1.value() < memory_2.value();
}

} // namespace PhQ
