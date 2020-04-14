// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Memory.hpp"
#include "Unit/MemoryRate.hpp"

namespace PhQ {

class MemoryRate : public DimensionalScalarQuantity<Unit::MemoryRate> {

public:

  constexpr MemoryRate() noexcept : DimensionalScalarQuantity<Unit::MemoryRate>() {}

  constexpr MemoryRate(double value, Unit::MemoryRate unit) noexcept : DimensionalScalarQuantity<Unit::MemoryRate>(value, unit) {}

  constexpr bool operator==(const MemoryRate& memory_rate) const noexcept {
    return value_ == memory_rate.value_;
  }

  constexpr bool operator!=(const MemoryRate& memory_rate) const noexcept {
    return value_ != memory_rate.value_;
  }

  constexpr bool operator<(const MemoryRate& memory_rate) const noexcept {
    return value_ < memory_rate.value_;
  }

  constexpr bool operator<=(const MemoryRate& memory_rate) const noexcept {
    return value_ <= memory_rate.value_;
  }

  constexpr bool operator>(const MemoryRate& memory_rate) const noexcept {
    return value_ > memory_rate.value_;
  }

  constexpr bool operator>=(const MemoryRate& memory_rate) const noexcept {
    return value_ >= memory_rate.value_;
  }

  MemoryRate operator+(const MemoryRate& memory_rate) const noexcept {
    return {value_ + memory_rate.value_};
  }

  constexpr void operator+=(const MemoryRate& memory_rate) noexcept {
    value_ += memory_rate.value_;
  }

  MemoryRate operator-(const MemoryRate& memory_rate) const noexcept {
    return {value_ - memory_rate.value_};
  }

  constexpr void operator-=(const MemoryRate& memory_rate) noexcept {
    value_ -= memory_rate.value_;
  }

  Memory operator*(const Duration& duration) const noexcept {
    return {value_ + duration.value_};
  }

  Memory operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Memory& memory) const {
    if (memory.value_ != 0.0) {
      return {value_ / memory.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + memory.print() + "."};
    }
  }

protected:

  constexpr MemoryRate(double value) noexcept : DimensionalScalarQuantity<Unit::MemoryRate>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class Memory;

};

template <> constexpr bool sort(const MemoryRate& memory_rate_1, const MemoryRate& memory_rate_2) noexcept {
  return memory_rate_1.value() < memory_rate_2.value();
}

constexpr MemoryRate Frequency::operator*(const Memory& memory) const noexcept {
  return {value_ * memory.value_};
}

constexpr MemoryRate Memory::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

MemoryRate Memory::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
