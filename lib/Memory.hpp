#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Memory.hpp"

namespace PhQ {

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

protected:

  constexpr Memory(double value) noexcept : DimensionalScalarQuantity<Unit::Memory>(value) {}

};

} // namespace PhQ
