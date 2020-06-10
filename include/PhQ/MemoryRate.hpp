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

  constexpr MemoryRate(const Memory& memory, const Duration& duration) noexcept : MemoryRate(memory.value() / duration.value()) {}

  constexpr MemoryRate(const Memory& memory, const Frequency& frequency) noexcept : MemoryRate(memory.value() * frequency.value()) {}

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

  constexpr MemoryRate operator+(const MemoryRate& memory_rate) const noexcept {
    return {value_ + memory_rate.value_};
  }

  constexpr void operator+=(const MemoryRate& memory_rate) noexcept {
    value_ += memory_rate.value_;
  }

  constexpr MemoryRate operator-(const MemoryRate& memory_rate) const noexcept {
    return {value_ - memory_rate.value_};
  }

  constexpr void operator-=(const MemoryRate& memory_rate) noexcept {
    value_ -= memory_rate.value_;
  }

  constexpr Memory operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr Memory operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Memory& memory) const noexcept {
    return {*this, memory};
  }

protected:

  constexpr MemoryRate(double value) noexcept : DimensionalScalarQuantity<Unit::MemoryRate>(value) {}

};

template <> constexpr bool sort(const MemoryRate& memory_rate_1, const MemoryRate& memory_rate_2) noexcept {
  return sort(memory_rate_1.value(), memory_rate_2.value());
}

constexpr Duration::Duration(const MemoryRate& memory_rate, const Memory& memory) noexcept : Duration(memory.value() / memory_rate.value()) {}

constexpr Frequency::Frequency(const MemoryRate& memory_rate, const Memory& memory) noexcept : Frequency(memory_rate.value() / memory.value()) {}

constexpr Memory::Memory(const MemoryRate& memory_rate, const Duration& duration) noexcept : Memory(memory_rate.value() * duration.value()) {}

constexpr Memory::Memory(const MemoryRate& memory_rate, const Frequency& frequency) noexcept : Memory(memory_rate.value() / frequency.value()) {}

constexpr MemoryRate Frequency::operator*(const Memory& memory) const noexcept {
  return {memory, *this};
}

constexpr MemoryRate Memory::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr MemoryRate Memory::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

constexpr Duration Memory::operator/(const MemoryRate& memory_rate) const noexcept {
  return {memory_rate, *this};
}

} // namespace PhQ
