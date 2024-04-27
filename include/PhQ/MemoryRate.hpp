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
class MemoryRate : public DimensionalScalar<Unit::MemoryRate> {
public:
  // Default constructor. Constructs a memory rate with an uninitialized value.
  MemoryRate() = default;

  // Constructor. Constructs a memory rate with a given value expressed in a given memory rate unit.
  MemoryRate(const double value, const Unit::MemoryRate unit)
    : DimensionalScalar<Unit::MemoryRate>(value, unit) {}

  // Constructor. Constructs a memory rate from a given memory and time duration using the
  // definition of memory rate.
  constexpr MemoryRate(const Memory& memory, const Time& time)
    : MemoryRate(memory.Value() / time.Value()) {}

  // Constructor. Constructs a memory rate from a given memory and frequency using the definition of
  // memory rate.
  constexpr MemoryRate(const Memory& memory, const Frequency& frequency)
    : MemoryRate(memory.Value() * frequency.Value()) {}

  // Destructor. Destroys this memory rate.
  ~MemoryRate() noexcept = default;

  // Copy constructor. Constructs a memory rate by copying another one.
  constexpr MemoryRate(const MemoryRate& other) = default;

  // Move constructor. Constructs a memory rate by moving another one.
  constexpr MemoryRate(MemoryRate&& other) noexcept = default;

  // Copy assignment operator. Assigns this memory rate by copying another one.
  constexpr MemoryRate& operator=(const MemoryRate& other) = default;

  // Move assignment operator. Assigns this memory rate by moving another one.
  constexpr MemoryRate& operator=(MemoryRate&& other) noexcept = default;

  // Statically creates a memory rate of zero.
  static constexpr MemoryRate Zero() {
    return MemoryRate{0.0};
  }

  // Statically creates a memory rate with a given value expressed in a given memory rate unit.
  template <Unit::MemoryRate Unit>
  static constexpr MemoryRate Create(const double value) {
    return MemoryRate{StaticConvertCopy<Unit::MemoryRate, Unit, Standard<Unit::MemoryRate>>(value)};
  }

  constexpr MemoryRate operator+(const MemoryRate& memory_rate) const {
    return MemoryRate{value + memory_rate.value};
  }

  constexpr MemoryRate operator-(const MemoryRate& memory_rate) const {
    return MemoryRate{value - memory_rate.value};
  }

  constexpr MemoryRate operator*(const double number) const {
    return MemoryRate{value * number};
  }

  constexpr Memory operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr MemoryRate operator/(const double number) const {
    return MemoryRate{value / number};
  }

  constexpr Memory operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Memory& memory) const {
    return {*this, memory};
  }

  constexpr double operator/(const MemoryRate& memory_rate) const noexcept {
    return value / memory_rate.value;
  }

  constexpr void operator+=(const MemoryRate& memory_rate) noexcept {
    value += memory_rate.value;
  }

  constexpr void operator-=(const MemoryRate& memory_rate) noexcept {
    value -= memory_rate.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a memory rate quantity with a given value expressed in the standard
  // memory rate unit.
  explicit constexpr MemoryRate(const double value) : DimensionalScalar<Unit::MemoryRate>(value) {}
};

inline constexpr bool operator==(const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const MemoryRate& memory_rate) {
  stream << memory_rate.Print();
  return stream;
}

inline constexpr MemoryRate operator*(const double number, const MemoryRate& memory_rate) {
  return memory_rate * number;
}

inline constexpr Time::Time(const Memory& memory, const MemoryRate& memory_rate)
  : Time(memory.Value() / memory_rate.Value()) {}

inline constexpr Frequency::Frequency(const MemoryRate& memory_rate, const Memory& memory)
  : Frequency(memory_rate.Value() / memory.Value()) {}

inline constexpr Memory::Memory(const MemoryRate& memory_rate, const Time& time)
  : Memory(memory_rate.Value() * time.Value()) {}

inline constexpr Memory::Memory(const MemoryRate& memory_rate, const Frequency& frequency)
  : Memory(memory_rate.Value() / frequency.Value()) {}

inline constexpr MemoryRate Frequency::operator*(const Memory& memory) const {
  return {memory, *this};
}

inline constexpr MemoryRate Memory::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr MemoryRate Memory::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time Memory::operator/(const MemoryRate& memory_rate) const {
  return {*this, memory_rate};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::MemoryRate> {
  inline size_t operator()(const PhQ::MemoryRate& memory_rate) const {
    return hash<double>()(memory_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_MEMORY_RATE_HPP
