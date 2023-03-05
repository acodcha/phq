// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Memory.hpp"
#include "Unit/MemoryRate.hpp"

namespace PhQ {

class MemoryRate : public DimensionalScalarQuantity<Unit::MemoryRate> {

public:

  constexpr MemoryRate() noexcept : DimensionalScalarQuantity<Unit::MemoryRate>() {}

  MemoryRate(double value, Unit::MemoryRate unit) noexcept : DimensionalScalarQuantity<Unit::MemoryRate>(value, unit) {}

  constexpr MemoryRate(const Memory& memory, const Time& time) noexcept : MemoryRate(memory.Value() / time.Value()) {}

  constexpr MemoryRate(const Memory& memory, const Frequency& frequency) noexcept : MemoryRate(memory.Value() * frequency.Value()) {}

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

  Memory operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  Memory operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  Frequency operator/(const Memory& memory) const noexcept {
    return {*this, memory};
  }

protected:

  constexpr MemoryRate(double value) noexcept : DimensionalScalarQuantity<Unit::MemoryRate>(value) {}

};

constexpr Time::Time(const MemoryRate& memory_rate, const Memory& memory) noexcept : Time(memory.Value() / memory_rate.Value()) {}

constexpr Frequency::Frequency(const MemoryRate& memory_rate, const Memory& memory) noexcept : Frequency(memory_rate.Value() / memory.Value()) {}

constexpr Memory::Memory(const MemoryRate& memory_rate, const Time& time) noexcept : Memory(memory_rate.Value() * time.Value()) {}

constexpr Memory::Memory(const MemoryRate& memory_rate, const Frequency& frequency) noexcept : Memory(memory_rate.Value() / frequency.Value()) {}

MemoryRate Frequency::operator*(const Memory& memory) const noexcept {
  return {memory, *this};
}

MemoryRate Memory::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

MemoryRate Memory::operator/(const Time& time) const noexcept {
  return {*this, time};
}

Time Memory::operator/(const MemoryRate& memory_rate) const noexcept {
  return {memory_rate, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::MemoryRate> {
  size_t operator()(const PhQ::MemoryRate& memory_rate) const {
    return hash<double>()(memory_rate.Value());
  }
};

} // namespace std
