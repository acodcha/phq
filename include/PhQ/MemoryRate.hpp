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
/// transfer speed; see PhQ::Memory, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class MemoryRate : public DimensionalScalar<Unit::MemoryRate, NumericType> {
public:
  /// \brief Default constructor. Constructs a memory rate with an uninitialized value.
  MemoryRate() = default;

  /// \brief Constructor. Constructs a memory rate with a given value expressed in a given memory
  /// rate unit.
  MemoryRate(const NumericType value, const Unit::MemoryRate unit)
    : DimensionalScalar<Unit::MemoryRate, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a memory rate from a given memory and time duration using the
  /// definition of memory rate.
  constexpr MemoryRate(const Memory<NumericType>& memory, const Time<NumericType>& time)
    : MemoryRate<NumericType>(memory.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a memory rate from a given memory and frequency using the
  /// definition of memory rate.
  constexpr MemoryRate(const Memory<NumericType>& memory, const Frequency<NumericType>& frequency)
    : MemoryRate<NumericType>(memory.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this memory rate.
  ~MemoryRate() noexcept = default;

  /// \brief Copy constructor. Constructs a memory rate by copying another one.
  constexpr MemoryRate(const MemoryRate<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a memory rate by copying another one.
  template <typename OtherNumericType>
  explicit constexpr MemoryRate(const MemoryRate<OtherNumericType>& other)
    : MemoryRate(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a memory rate by moving another one.
  constexpr MemoryRate(MemoryRate<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this memory rate by copying another one.
  constexpr MemoryRate<NumericType>& operator=(const MemoryRate<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this memory rate by copying another one.
  template <typename OtherNumericType>
  constexpr MemoryRate<NumericType>& operator=(const MemoryRate<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this memory rate by moving another one.
  constexpr MemoryRate<NumericType>& operator=(MemoryRate<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a memory rate of zero.
  static constexpr MemoryRate<NumericType> Zero() {
    return MemoryRate<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a memory rate with a given value expressed in a given memory rate
  /// unit.
  template <Unit::MemoryRate Unit>
  static constexpr MemoryRate<NumericType> Create(const NumericType value) {
    return MemoryRate<NumericType>{
        ConvertStatically<Unit::MemoryRate, Unit, Standard<Unit::MemoryRate>>(value)};
  }

  constexpr MemoryRate<NumericType> operator+(const MemoryRate<NumericType>& memory_rate) const {
    return MemoryRate<NumericType>{this->value + memory_rate.value};
  }

  constexpr MemoryRate<NumericType> operator-(const MemoryRate<NumericType>& memory_rate) const {
    return MemoryRate<NumericType>{this->value - memory_rate.value};
  }

  constexpr MemoryRate<NumericType> operator*(const NumericType number) const {
    return MemoryRate<NumericType>{this->value * number};
  }

  constexpr Memory<NumericType> operator*(const Time<NumericType>& time) const {
    return Memory<NumericType>{*this, time};
  }

  constexpr MemoryRate<NumericType> operator/(const NumericType number) const {
    return MemoryRate<NumericType>{this->value / number};
  }

  constexpr Memory<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Memory<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const Memory<NumericType>& memory) const {
    return Frequency<NumericType>{*this, memory};
  }

  constexpr NumericType operator/(const MemoryRate<NumericType>& memory_rate) const noexcept {
    return this->value / memory_rate.value;
  }

  constexpr void operator+=(const MemoryRate<NumericType>& memory_rate) noexcept {
    this->value += memory_rate.value;
  }

  constexpr void operator-=(const MemoryRate<NumericType>& memory_rate) noexcept {
    this->value -= memory_rate.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a memory rate quantity with a given value expressed in the
  /// standard memory rate unit.
  explicit constexpr MemoryRate(const NumericType value)
    : DimensionalScalar<Unit::MemoryRate, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const MemoryRate<NumericType>& left, const MemoryRate<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const MemoryRate<NumericType>& left, const MemoryRate<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const MemoryRate<NumericType>& left, const MemoryRate<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const MemoryRate<NumericType>& left, const MemoryRate<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const MemoryRate<NumericType>& left, const MemoryRate<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const MemoryRate<NumericType>& left, const MemoryRate<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const MemoryRate<NumericType>& memory_rate) {
  stream << memory_rate.Print();
  return stream;
}

template <typename NumericType>
inline constexpr MemoryRate<NumericType> operator*(
    const NumericType number, const MemoryRate<NumericType>& memory_rate) {
  return memory_rate * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Memory<NumericType>& memory, const MemoryRate<NumericType>& memory_rate)
  : Time<NumericType>(memory.Value() / memory_rate.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const MemoryRate<NumericType>& memory_rate, const Memory<NumericType>& memory)
  : Frequency<NumericType>(memory_rate.Value() / memory.Value()) {}

template <typename NumericType>
inline constexpr Memory<NumericType>::Memory(
    const MemoryRate<NumericType>& memory_rate, const Time<NumericType>& time)
  : Memory<NumericType>(memory_rate.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Memory<NumericType>::Memory(
    const MemoryRate<NumericType>& memory_rate, const Frequency<NumericType>& frequency)
  : Memory<NumericType>(memory_rate.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr MemoryRate<NumericType> Frequency<NumericType>::operator*(
    const Memory<NumericType>& memory) const {
  return MemoryRate<NumericType>{memory, *this};
}

template <typename NumericType>
inline constexpr MemoryRate<NumericType> Memory<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return MemoryRate<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr MemoryRate<NumericType> Memory<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return MemoryRate<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Time<NumericType> Memory<NumericType>::operator/(
    const MemoryRate<NumericType>& memory_rate) const {
  return Time<NumericType>{*this, memory_rate};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::MemoryRate<NumericType>> {
  inline size_t operator()(const PhQ::MemoryRate<NumericType>& memory_rate) const {
    return hash<NumericType>()(memory_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_MEMORY_RATE_HPP
