// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Computer memory.
template <typename Number = double>
class Memory : public DimensionalScalar<Unit::Memory, Number> {
public:
  /// \brief Default constructor. Constructs a memory quantity with an uninitialized value.
  Memory() = default;

  /// \brief Constructor. Constructs a memory quantity with a given value expressed in a given
  /// memory unit.
  Memory(const Number value, const Unit::Memory unit)
    : DimensionalScalar<Unit::Memory, Number>(value, unit) {}

  /// \brief Constructor. Constructs a memory quantity from a given memory rate and time duration
  /// using the definition of memory rate.
  constexpr Memory(const MemoryRate<Number>& memory_rate, const Time<Number>& time);

  /// \brief Constructor. Constructs a memory quantity from a given memory rate and frequency using
  /// the definition of memory rate.
  constexpr Memory(const MemoryRate<Number>& memory_rate, const Frequency<Number>& frequency);

  /// \brief Destructor. Destroys this memory quantity.
  ~Memory() noexcept = default;

  /// \brief Copy constructor. Constructs a memory quantity by copying another one.
  constexpr Memory(const Memory<Number>& other) = default;

  /// \brief Copy constructor. Constructs a memory quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Memory(const Memory<OtherNumber>& other)
    : Memory(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a memory quantity by moving another one.
  constexpr Memory(Memory<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this memory quantity by copying another one.
  constexpr Memory<Number>& operator=(const Memory<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this memory quantity by copying another one.
  template <typename OtherNumber>
  constexpr Memory<Number>& operator=(const Memory<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this memory quantity by moving another one.
  constexpr Memory<Number>& operator=(Memory<Number>&& other) noexcept = default;

  /// \brief Statically creates a memory quantity of zero.
  static constexpr Memory<Number> Zero() {
    return Memory<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a memory quantity with a given value expressed in a given memory
  /// unit.
  template <Unit::Memory Unit>
  static constexpr Memory<Number> Create(const Number value) {
    return Memory<Number>{StaticConvertCopy<Unit::Memory, Unit, Standard<Unit::Memory>>(value)};
  }

  constexpr Memory<Number> operator+(const Memory<Number>& memory) const {
    return Memory<Number>{this->value + memory.value};
  }

  constexpr Memory<Number> operator-(const Memory<Number>& memory) const {
    return Memory<Number>{this->value - memory.value};
  }

  constexpr Memory<Number> operator*(const Number number) const {
    return Memory<Number>{this->value * number};
  }

  constexpr MemoryRate<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Memory<Number> operator/(const Number number) const {
    return Memory<Number>{this->value / number};
  }

  constexpr MemoryRate<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const MemoryRate<Number>& memory_rate) const;

  constexpr Number operator/(const Memory<Number>& memory) const noexcept {
    return this->value / memory.value;
  }

  constexpr void operator+=(const Memory<Number>& memory) noexcept {
    this->value += memory.value;
  }

  constexpr void operator-=(const Memory<Number>& memory) noexcept {
    this->value -= memory.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a memory quantity with a given value expressed in the standard
  /// memory unit.
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
