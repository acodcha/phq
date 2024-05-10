// Copyright 2020-2024 Alexandre Coderre-Chabot
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

// Forward declaration for class PhQ::Memory.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Memory.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Memory.
template <typename Number>
class MemoryRate;

// Computer memory.
template <typename Number = double>
class Memory : public DimensionalScalar<Unit::Memory, Number> {
public:
  // Default constructor. Constructs a memory quantity with an uninitialized value.
  Memory() = default;

  // Constructor. Constructs a memory quantity with a given value expressed in a given memory unit.
  Memory(const Number value, const Unit::Memory unit)
    : DimensionalScalar<Unit::Memory, Number>(value, unit) {}

  // Constructor. Constructs a memory quantity from a given memory rate and time duration using the
  // definition of memory rate.
  constexpr Memory(const MemoryRate<Number>& memory_rate, const Time<Number>& time);

  // Constructor. Constructs a memory quantity from a given memory rate and frequency using the
  // definition of memory rate.
  constexpr Memory(const MemoryRate<Number>& memory_rate, const Frequency<Number>& frequency);

  // Destructor. Destroys this memory quantity.
  ~Memory() noexcept = default;

  // Copy constructor. Constructs a memory quantity by copying another one.
  constexpr Memory(const Memory<Number>& other) = default;

  // Copy constructor. Constructs a memory quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Memory(const Memory<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a memory quantity by moving another one.
  constexpr Memory(Memory<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this memory quantity by copying another one.
  constexpr Memory<Number>& operator=(const Memory<Number>& other) = default;

  // Copy assignment operator. Assigns this memory quantity by copying another one.
  template <typename OtherNumber>
  constexpr Memory<Number>& operator=(const Memory<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this memory quantity by moving another one.
  constexpr Memory<Number>& operator=(Memory<Number>&& other) noexcept = default;

  // Statically creates a memory quantity of zero.
  static constexpr Memory<Number> Zero() {
    return Memory<Number>{static_cast<Number>(0)};
  }

  // Statically creates a memory quantity with a given value expressed in a given memory unit.
  template <Unit::Memory Unit>
  static constexpr Memory<Number> Create(const Number value) {
    return Memory<Number>{StaticConvertCopy<Unit::Memory, Unit, Standard<Unit::Memory>>(value)};
  }

  constexpr Memory<Number> operator+(const Memory<Number>& memory) const {
    return Memory<Number>{value + memory.value};
  }

  constexpr Memory<Number> operator-(const Memory<Number>& memory) const {
    return Memory<Number>{value - memory.value};
  }

  constexpr Memory<Number> operator*(const Number number) const {
    return Memory<Number>{value * number};
  }

  constexpr MemoryRate<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Memory<Number> operator/(const Number number) const {
    return Memory<Number>{value / number};
  }

  constexpr MemoryRate<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const MemoryRate<Number>& memory_rate) const;

  constexpr Number operator/(const Memory<Number>& memory) const noexcept {
    return value / memory.value;
  }

  constexpr void operator+=(const Memory<Number>& memory) noexcept {
    value += memory.value;
  }

  constexpr void operator-=(const Memory<Number>& memory) noexcept {
    value -= memory.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a memory quantity with a given value expressed in the standard memory
  // unit.
  explicit constexpr Memory(const Number value) : DimensionalScalar<Unit::Memory, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Memory<Number>& left, const Memory<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Memory<Number>& left, const Memory<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Memory<Number>& left, const Memory<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Memory<Number>& left, const Memory<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Memory<Number>& left, const Memory<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Memory<Number>& left, const Memory<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Memory<Number>& memory) {
  stream << memory.Print();
  return stream;
}

template <typename Number>
inline constexpr Memory<Number> operator*(const Number number, const Memory<Number>& memory) {
  return memory * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Memory<Number>> {
  inline size_t operator()(const PhQ::Memory<Number>& memory) const {
    return hash<Number>()(memory.Value());
  }
};

}  // namespace std

#endif  // PHQ_MEMORY_HPP
