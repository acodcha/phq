// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_MEMORY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_MEMORY_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Memory.hpp"

namespace PhQ {

// Forward declarations for class Memory.
class Time;
class Frequency;
class MemoryRate;

// Computer memory.
class Memory : public DimensionalScalarQuantity<Unit::Memory> {
public:
  constexpr Memory() noexcept : DimensionalScalarQuantity<Unit::Memory>() {}

  Memory(const double value, const Unit::Memory unit) noexcept
    : DimensionalScalarQuantity<Unit::Memory>(value, unit) {}

  constexpr Memory(const MemoryRate& memory_rate, const Time& time) noexcept;

  constexpr Memory(
      const MemoryRate& memory_rate, const Frequency& frequency) noexcept;

  static constexpr Memory Zero() noexcept { return Memory{0.0}; }

  template<Unit::Memory Unit>
  static constexpr Memory Create(const double value) noexcept {
    return Memory{
        StaticConvertCopy<Unit::Memory, Unit, StandardUnit<Unit::Memory>>(
            value)};
  }

  inline constexpr Memory operator+(const Memory& memory) const noexcept {
    return Memory{value_ + memory.value_};
  }

  inline constexpr Memory operator-(const Memory& memory) const noexcept {
    return Memory{value_ - memory.value_};
  }

  inline constexpr Memory operator*(const double number) const noexcept {
    return Memory{value_ * number};
  }

  inline constexpr MemoryRate operator*(
      const Frequency& frequency) const noexcept;

  inline constexpr Memory operator/(const double number) const noexcept {
    return Memory{value_ / number};
  }

  inline constexpr MemoryRate operator/(const Time& time) const noexcept;

  inline constexpr Time operator/(const MemoryRate& memory_rate) const noexcept;

  inline constexpr double operator/(const Memory& memory) const noexcept {
    return value_ / memory.value_;
  }

  inline constexpr void operator+=(const Memory& memory) noexcept {
    value_ += memory.value_;
  }

  inline constexpr void operator-=(const Memory& memory) noexcept {
    value_ -= memory.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Memory(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Memory>(value) {}
};

inline constexpr bool operator==(
    const Memory& left, const Memory& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Memory& left, const Memory& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Memory& left, const Memory& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Memory& left, const Memory& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Memory& left, const Memory& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Memory& left, const Memory& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Memory& memory) noexcept {
  stream << memory.Print();
  return stream;
}

inline constexpr Memory operator*(
    const double number, const Memory& memory) noexcept {
  return memory * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::Memory> {
  size_t operator()(const PhQ::Memory& memory) const {
    return hash<double>()(memory.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_MEMORY_HPP
