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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_MEMORY_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_MEMORY_RATE_HPP

#include "Frequency.hpp"
#include "Memory.hpp"
#include "Unit/MemoryRate.hpp"

namespace PhQ {

// Computer memory rate. Can represent the time rate of change of memory or a
// memory transfer speed.
class MemoryRate : public DimensionalScalarQuantity<Unit::MemoryRate> {
public:
  constexpr MemoryRate() noexcept
    : DimensionalScalarQuantity<Unit::MemoryRate>() {}

  MemoryRate(const double value, const Unit::MemoryRate unit) noexcept
    : DimensionalScalarQuantity<Unit::MemoryRate>(value, unit) {}

  constexpr MemoryRate(const Memory& memory, const Time& time) noexcept
    : MemoryRate(memory.Value() / time.Value()) {}

  constexpr MemoryRate(
      const Memory& memory, const Frequency& frequency) noexcept
    : MemoryRate(memory.Value() * frequency.Value()) {}

  static constexpr MemoryRate Zero() noexcept { return MemoryRate{0.0}; }

  template<Unit::MemoryRate Unit>
  static constexpr MemoryRate Create(const double value) noexcept {
    return MemoryRate{StaticConvertCopy<Unit::MemoryRate, Unit,
                                        StandardUnit<Unit::MemoryRate>>(value)};
  }

  inline constexpr MemoryRate operator+(
      const MemoryRate& memory_rate) const noexcept {
    return MemoryRate{value_ + memory_rate.value_};
  }

  inline constexpr MemoryRate operator-(
      const MemoryRate& memory_rate) const noexcept {
    return MemoryRate{value_ - memory_rate.value_};
  }

  inline constexpr MemoryRate operator*(const double number) const noexcept {
    return MemoryRate{value_ * number};
  }

  inline constexpr Memory operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline constexpr MemoryRate operator/(const double number) const noexcept {
    return MemoryRate{value_ / number};
  }

  inline constexpr Memory operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr Frequency operator/(const Memory& memory) const noexcept {
    return {*this, memory};
  }

  inline constexpr double operator/(
      const MemoryRate& memory_rate) const noexcept {
    return value_ / memory_rate.value_;
  }

  inline constexpr void operator+=(const MemoryRate& memory_rate) noexcept {
    value_ += memory_rate.value_;
  }

  inline constexpr void operator-=(const MemoryRate& memory_rate) noexcept {
    value_ -= memory_rate.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr MemoryRate(const double value) noexcept
    : DimensionalScalarQuantity<Unit::MemoryRate>(value) {}
};

inline constexpr bool operator==(
    const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const MemoryRate& left, const MemoryRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const MemoryRate& memory_rate) noexcept {
  stream << memory_rate.Print();
  return stream;
}

inline constexpr MemoryRate operator*(
    const double number, const MemoryRate& memory_rate) noexcept {
  return memory_rate * number;
}

inline constexpr Time::Time(
    const MemoryRate& memory_rate, const Memory& memory) noexcept
  : Time(memory.Value() / memory_rate.Value()) {}

inline constexpr Frequency::Frequency(
    const MemoryRate& memory_rate, const Memory& memory) noexcept
  : Frequency(memory_rate.Value() / memory.Value()) {}

inline constexpr Memory::Memory(
    const MemoryRate& memory_rate, const Time& time) noexcept
  : Memory(memory_rate.Value() * time.Value()) {}

inline constexpr Memory::Memory(
    const MemoryRate& memory_rate, const Frequency& frequency) noexcept
  : Memory(memory_rate.Value() / frequency.Value()) {}

inline constexpr MemoryRate Frequency::operator*(
    const Memory& memory) const noexcept {
  return {memory, *this};
}

inline constexpr MemoryRate Memory::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr MemoryRate Memory::operator/(const Time& time) const noexcept {
  return {*this, time};
}

inline constexpr Time Memory::operator/(
    const MemoryRate& memory_rate) const noexcept {
  return {memory_rate, *this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::MemoryRate> {
  size_t operator()(const PhQ::MemoryRate& memory_rate) const {
    return hash<double>()(memory_rate.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_MEMORY_RATE_HPP
