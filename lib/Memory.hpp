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

} // namespace PhQ
