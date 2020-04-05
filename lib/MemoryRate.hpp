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

protected:

  constexpr MemoryRate(double value) noexcept : DimensionalScalarQuantity<Unit::MemoryRate>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class Memory;

};

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
