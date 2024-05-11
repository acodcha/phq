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

// Computer memory rate. Can represent the time rate of change of memory or a memory transfer speed.
template <typename Number = double>
class MemoryRate : public DimensionalScalar<Unit::MemoryRate, Number> {
public:
  // Default constructor. Constructs a memory rate with an uninitialized value.
  MemoryRate() = default;

  // Constructor. Constructs a memory rate with a given value expressed in a given memory rate unit.
  MemoryRate(const Number value, const Unit::MemoryRate unit)
    : DimensionalScalar<Unit::MemoryRate, Number>(value, unit) {}

  // Constructor. Constructs a memory rate from a given memory and time duration using the
  // definition of memory rate.
  constexpr MemoryRate(const Memory<Number>& memory, const Time<Number>& time)
    : MemoryRate<Number>(memory.Value() / time.Value()) {}

  // Constructor. Constructs a memory rate from a given memory and frequency using the definition of
  // memory rate.
  constexpr MemoryRate(const Memory<Number>& memory, const Frequency<Number>& frequency)
    : MemoryRate<Number>(memory.Value() * frequency.Value()) {}

  // Destructor. Destroys this memory rate.
  ~MemoryRate() noexcept = default;

  // Copy constructor. Constructs a memory rate by copying another one.
  constexpr MemoryRate(const MemoryRate<Number>& other) = default;

  // Copy constructor. Constructs a memory rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr MemoryRate(const MemoryRate<OtherNumber>& other)
    : MemoryRate(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a memory rate by moving another one.
  constexpr MemoryRate(MemoryRate<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this memory rate by copying another one.
  constexpr MemoryRate<Number>& operator=(const MemoryRate<Number>& other) = default;

  // Copy assignment operator. Assigns this memory rate by copying another one.
  template <typename OtherNumber>
  constexpr MemoryRate<Number>& operator=(const MemoryRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this memory rate by moving another one.
  constexpr MemoryRate<Number>& operator=(MemoryRate<Number>&& other) noexcept = default;

  // Statically creates a memory rate of zero.
  static constexpr MemoryRate<Number> Zero() {
    return MemoryRate<Number>{static_cast<Number>(0)};
  }

  // Statically creates a memory rate with a given value expressed in a given memory rate unit.
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
  // Constructor. Constructs a memory rate quantity with a given value expressed in the standard
  // memory rate unit.
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
