// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#ifndef PHQ_MEMORY_RATE_HPP
#define PHQ_MEMORY_RATE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Memory.hpp"
#include "Time.hpp"
#include "Unit/MemoryRate.hpp"

namespace PhQ {

/// \brief Computer memory rate. Can represent the time rate of change of memory or a memory
/// transfer speed.
template <typename Number = double>
class MemoryRate : public DimensionalScalar<Unit::MemoryRate, Number> {
public:
  /// \brief Default constructor. Constructs a memory rate with an uninitialized value.
  MemoryRate() = default;

  /// \brief Constructor. Constructs a memory rate with a given value expressed in a given memory
  /// rate unit.
  MemoryRate(const Number value, const Unit::MemoryRate unit)
    : DimensionalScalar<Unit::MemoryRate, Number>(value, unit) {}

  /// \brief Constructor. Constructs a memory rate from a given memory and time duration using the
  /// definition of memory rate.
  constexpr MemoryRate(const Memory<Number>& memory, const Time<Number>& time)
    : MemoryRate<Number>(memory.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a memory rate from a given memory and frequency using the
  /// definition of memory rate.
  constexpr MemoryRate(const Memory<Number>& memory, const Frequency<Number>& frequency)
    : MemoryRate<Number>(memory.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this memory rate.
  ~MemoryRate() noexcept = default;

  /// \brief Copy constructor. Constructs a memory rate by copying another one.
  constexpr MemoryRate(const MemoryRate<Number>& other) = default;

  /// \brief Copy constructor. Constructs a memory rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr MemoryRate(const MemoryRate<OtherNumber>& other)
    : MemoryRate(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a memory rate by moving another one.
  constexpr MemoryRate(MemoryRate<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this memory rate by copying another one.
  constexpr MemoryRate<Number>& operator=(const MemoryRate<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this memory rate by copying another one.
  template <typename OtherNumber>
  constexpr MemoryRate<Number>& operator=(const MemoryRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this memory rate by moving another one.
  constexpr MemoryRate<Number>& operator=(MemoryRate<Number>&& other) noexcept = default;

  /// \brief Statically creates a memory rate of zero.
  static constexpr MemoryRate<Number> Zero() {
    return MemoryRate<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a memory rate with a given value expressed in a given memory rate
  /// unit.
  template <Unit::MemoryRate Unit>
  static constexpr MemoryRate<Number> Create(const Number value) {
    return MemoryRate<Number>{
        StaticConvertCopy<Unit::MemoryRate, Unit, Standard<Unit::MemoryRate>>(value)};
  }

  constexpr MemoryRate<Number> operator+(const MemoryRate<Number>& memory_rate) const {
    return MemoryRate<Number>{this->value + memory_rate.value};
  }

  constexpr MemoryRate<Number> operator-(const MemoryRate<Number>& memory_rate) const {
    return MemoryRate<Number>{this->value - memory_rate.value};
  }

  constexpr MemoryRate<Number> operator*(const Number number) const {
    return MemoryRate<Number>{this->value * number};
  }

  constexpr Memory<Number> operator*(const Time<Number>& time) const {
    return Memory<Number>{*this, time};
  }

  constexpr MemoryRate<Number> operator/(const Number number) const {
    return MemoryRate<Number>{this->value / number};
  }

  constexpr Memory<Number> operator/(const Frequency<Number>& frequency) const {
    return Memory<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Memory<Number>& memory) const {
    return Frequency<Number>{*this, memory};
  }

  constexpr Number operator/(const MemoryRate<Number>& memory_rate) const noexcept {
    return this->value / memory_rate.value;
  }

  constexpr void operator+=(const MemoryRate<Number>& memory_rate) noexcept {
    this->value += memory_rate.value;
  }

  constexpr void operator-=(const MemoryRate<Number>& memory_rate) noexcept {
    this->value -= memory_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a memory rate quantity with a given value expressed in the
  /// standard memory rate unit.
  explicit constexpr MemoryRate(const Number value)
    : DimensionalScalar<Unit::MemoryRate, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const MemoryRate<Number>& left, const MemoryRate<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const MemoryRate<Number>& left, const MemoryRate<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const MemoryRate<Number>& left, const MemoryRate<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const MemoryRate<Number>& left, const MemoryRate<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const MemoryRate<Number>& left, const MemoryRate<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const MemoryRate<Number>& left, const MemoryRate<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const MemoryRate<Number>& memory_rate) {
  stream << memory_rate.Print();
  return stream;
}

template <typename Number>
inline constexpr MemoryRate<Number> operator*(
    const Number number, const MemoryRate<Number>& memory_rate) {
  return memory_rate * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(
    const Memory<Number>& memory, const MemoryRate<Number>& memory_rate)
  : Time<Number>(memory.Value() / memory_rate.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const MemoryRate<Number>& memory_rate, const Memory<Number>& memory)
  : Frequency<Number>(memory_rate.Value() / memory.Value()) {}

template <typename Number>
inline constexpr Memory<Number>::Memory(
    const MemoryRate<Number>& memory_rate, const Time<Number>& time)
  : Memory<Number>(memory_rate.Value() * time.Value()) {}

template <typename Number>
inline constexpr Memory<Number>::Memory(
    const MemoryRate<Number>& memory_rate, const Frequency<Number>& frequency)
  : Memory<Number>(memory_rate.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr MemoryRate<Number> Frequency<Number>::operator*(
    const Memory<Number>& memory) const {
  return MemoryRate<Number>{memory, *this};
}

template <typename Number>
inline constexpr MemoryRate<Number> Memory<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return MemoryRate<Number>{*this, frequency};
}

template <typename Number>
inline constexpr MemoryRate<Number> Memory<Number>::operator/(const Time<Number>& time) const {
  return MemoryRate<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> Memory<Number>::operator/(
    const MemoryRate<Number>& memory_rate) const {
  return Time<Number>{*this, memory_rate};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::MemoryRate<Number>> {
  inline size_t operator()(const PhQ::MemoryRate<Number>& memory_rate) const {
    return hash<Number>()(memory_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_MEMORY_RATE_HPP
