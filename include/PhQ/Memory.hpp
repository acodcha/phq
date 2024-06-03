// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_MEMORY_HPP
#define PHQ_MEMORY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Memory.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Memory.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Memory.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Memory.
template <typename NumericType>
class MemoryRate;

/// \brief Computer memory. For the time rate of change of computer memory, see PhQ::MemoryRate; see
/// also PhQ::Time and PhQ::Frequency.
template <typename NumericType = double>
class Memory : public DimensionalScalar<Unit::Memory, NumericType> {
public:
  /// \brief Default constructor. Constructs a memory quantity with an uninitialized value.
  Memory() = default;

  /// \brief Constructor. Constructs a memory quantity with a given value expressed in a given
  /// memory unit.
  Memory(const NumericType value, const Unit::Memory unit)
    : DimensionalScalar<Unit::Memory, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a memory quantity from a given memory rate and time duration
  /// using the definition of memory rate.
  constexpr Memory(const MemoryRate<NumericType>& memory_rate, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a memory quantity from a given memory rate and frequency using
  /// the definition of memory rate.
  constexpr Memory(
      const MemoryRate<NumericType>& memory_rate, const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this memory quantity.
  ~Memory() noexcept = default;

  /// \brief Copy constructor. Constructs a memory quantity by copying another one.
  constexpr Memory(const Memory<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a memory quantity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Memory(const Memory<OtherNumericType>& other)
    : Memory(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a memory quantity by moving another one.
  constexpr Memory(Memory<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this memory quantity by copying another one.
  constexpr Memory<NumericType>& operator=(const Memory<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this memory quantity by copying another one.
  template <typename OtherNumericType>
  constexpr Memory<NumericType>& operator=(const Memory<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this memory quantity by moving another one.
  constexpr Memory<NumericType>& operator=(Memory<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a memory quantity of zero.
  [[nodiscard]] static constexpr Memory<NumericType> Zero() {
    return Memory<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a memory quantity with a given value expressed in a given memory
  /// unit.
  template <Unit::Memory Unit>
  [[nodiscard]] static constexpr Memory<NumericType> Create(const NumericType value) {
    return Memory<NumericType>{
        ConvertStatically<Unit::Memory, Unit, Standard<Unit::Memory>>(value)};
  }

  constexpr Memory<NumericType> operator+(const Memory<NumericType>& memory) const {
    return Memory<NumericType>{this->value + memory.value};
  }

  constexpr Memory<NumericType> operator-(const Memory<NumericType>& memory) const {
    return Memory<NumericType>{this->value - memory.value};
  }

  constexpr Memory<NumericType> operator*(const NumericType number) const {
    return Memory<NumericType>{this->value * number};
  }

  constexpr MemoryRate<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Memory<NumericType> operator/(const NumericType number) const {
    return Memory<NumericType>{this->value / number};
  }

  constexpr MemoryRate<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const MemoryRate<NumericType>& memory_rate) const;

  constexpr NumericType operator/(const Memory<NumericType>& memory) const noexcept {
    return this->value / memory.value;
  }

  constexpr void operator+=(const Memory<NumericType>& memory) noexcept {
    this->value += memory.value;
  }

  constexpr void operator-=(const Memory<NumericType>& memory) noexcept {
    this->value -= memory.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a memory quantity with a given value expressed in the standard
  /// memory unit.
  explicit constexpr Memory(const NumericType value)
    : DimensionalScalar<Unit::Memory, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Memory<NumericType>& left, const Memory<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Memory<NumericType>& left, const Memory<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Memory<NumericType>& left, const Memory<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Memory<NumericType>& left, const Memory<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Memory<NumericType>& left, const Memory<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Memory<NumericType>& left, const Memory<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Memory<NumericType>& memory) {
  stream << memory.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Memory<NumericType> operator*(
    const NumericType number, const Memory<NumericType>& memory) {
  return memory * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Memory<NumericType>> {
  inline size_t operator()(const PhQ::Memory<NumericType>& memory) const {
    return hash<NumericType>()(memory.Value());
  }
};

}  // namespace std

#endif  // PHQ_MEMORY_HPP
