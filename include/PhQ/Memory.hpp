// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_MEMORY_HPP
#define PHQ_MEMORY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Memory.hpp"

namespace PhQ {

// Forward declarations for class Memory.
class Time;
class Frequency;
class MemoryRate;

// Computer memory.
class Memory : public DimensionalScalar<Unit::Memory> {
public:
  // Default constructor. Constructs a memory quantity with an uninitialized value.
  Memory() = default;

  // Constructor. Constructs a memory quantity with a given value expressed in a given memory unit.
  Memory(const double value, const Unit::Memory unit)
    : DimensionalScalar<Unit::Memory>(value, unit) {}

  // Constructor. Constructs a memory quantity from a given memory rate and time duration using the
  // definition of memory rate.
  constexpr Memory(const MemoryRate& memory_rate, const Time& time);

  // Constructor. Constructs a memory quantity from a given memory rate and frequency using the
  // definition of memory rate.
  constexpr Memory(const MemoryRate& memory_rate, const Frequency& frequency);

  // Destructor. Destroys this memory quantity.
  ~Memory() noexcept = default;

  // Copy constructor. Constructs a memory quantity by copying another one.
  constexpr Memory(const Memory& other) = default;

  // Move constructor. Constructs a memory quantity by moving another one.
  constexpr Memory(Memory&& other) noexcept = default;

  // Copy assignment operator. Assigns this memory quantity by copying another one.
  constexpr Memory& operator=(const Memory& other) = default;

  // Move assignment operator. Assigns this memory quantity by moving another one.
  constexpr Memory& operator=(Memory&& other) noexcept = default;

  // Statically creates a memory quantity of zero.
  static constexpr Memory Zero() {
    return Memory{0.0};
  }

  // Statically creates a memory quantity with a given value expressed in a given memory unit.
  template <Unit::Memory Unit>
  static constexpr Memory Create(const double value) {
    return Memory{StaticConvertCopy<Unit::Memory, Unit, Standard<Unit::Memory>>(value)};
  }

  constexpr Memory operator+(const Memory& memory) const {
    return Memory{value + memory.value};
  }

  constexpr Memory operator-(const Memory& memory) const {
    return Memory{value - memory.value};
  }

  constexpr Memory operator*(const double number) const {
    return Memory{value * number};
  }

  constexpr MemoryRate operator*(const Frequency& frequency) const;

  constexpr Memory operator/(const double number) const {
    return Memory{value / number};
  }

  constexpr MemoryRate operator/(const Time& time) const;

  constexpr Time operator/(const MemoryRate& memory_rate) const;

  constexpr double operator/(const Memory& memory) const noexcept {
    return value / memory.value;
  }

  constexpr void operator+=(const Memory& memory) noexcept {
    value += memory.value;
  }

  constexpr void operator-=(const Memory& memory) noexcept {
    value -= memory.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a memory quantity with a given value expressed in the standard memory
  // unit.
  explicit constexpr Memory(const double value) : DimensionalScalar<Unit::Memory>(value) {}
};

inline constexpr bool operator==(const Memory& left, const Memory& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Memory& left, const Memory& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Memory& left, const Memory& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Memory& left, const Memory& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Memory& left, const Memory& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Memory& left, const Memory& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Memory& memory) {
  stream << memory.Print();
  return stream;
}

inline constexpr Memory operator*(const double number, const Memory& memory) {
  return memory * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Memory> {
  inline size_t operator()(const PhQ::Memory& memory) const {
    return hash<double>()(memory.Value());
  }
};

}  // namespace std

#endif  // PHQ_MEMORY_HPP
