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

#ifndef PHQ_POISSON_RATIO_HPP
#define PHQ_POISSON_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Poisson's ratio of a deformable solid material.
template <typename Number = double>
class PoissonRatio : public DimensionlessScalar<Number> {
public:
  // Default constructor. Constructs a Poisson's ratio with an uninitialized value.
  PoissonRatio() = default;

  // Constructor. Constructs a Poisson's ratio with a given value.
  explicit constexpr PoissonRatio(const Number value) : DimensionlessScalar<Number>(value) {}

  // Destructor. Destroys this Poisson's ratio.
  ~PoissonRatio() noexcept = default;

  // Copy constructor. Constructs a Poisson's ratio by copying another one.
  constexpr PoissonRatio(const PoissonRatio<Number>& other) = default;

  // Copy constructor. Constructs a Poisson's ratio by copying another one.
  template <typename OtherNumber>
  explicit constexpr PoissonRatio(const PoissonRatio<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a Poisson's ratio by moving another one.
  constexpr PoissonRatio(PoissonRatio<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  constexpr PoissonRatio<Number>& operator=(const PoissonRatio<Number>& other) = default;

  // Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  template <typename OtherNumber>
  constexpr PoissonRatio<Number>& operator=(const PoissonRatio<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this Poisson's ratio by moving another one.
  constexpr PoissonRatio<Number>& operator=(PoissonRatio<Number>&& other) noexcept = default;

  // Statically creates a Poisson's ratio of zero.
  static constexpr PoissonRatio<Number> Zero() {
    return PoissonRatio<Number>{static_cast<Number>(0)};
  }

  constexpr PoissonRatio<Number> operator+(const PoissonRatio<Number>& poisson_ratio) const {
    return PoissonRatio<Number>{value + poisson_ratio.value};
  }

  constexpr PoissonRatio<Number> operator-(const PoissonRatio<Number>& poisson_ratio) const {
    return PoissonRatio<Number>{value - poisson_ratio.value};
  }

  constexpr PoissonRatio<Number> operator*(const Number number) const {
    return PoissonRatio<Number>{value * number};
  }

  constexpr PoissonRatio<Number> operator/(const Number number) const {
    return PoissonRatio<Number>{value / number};
  }

  constexpr Number operator/(const PoissonRatio<Number>& poisson_ratio) const noexcept {
    return value / poisson_ratio.value;
  }

  constexpr void operator+=(const PoissonRatio<Number>& poisson_ratio) noexcept {
    value += poisson_ratio.value;
  }

  constexpr void operator-=(const PoissonRatio<Number>& poisson_ratio) noexcept {
    value -= poisson_ratio.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(
    const PoissonRatio<Number>& left, const PoissonRatio<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PoissonRatio<Number>& left, const PoissonRatio<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PoissonRatio<Number>& left, const PoissonRatio<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PoissonRatio<Number>& left, const PoissonRatio<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PoissonRatio<Number>& left, const PoissonRatio<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PoissonRatio<Number>& left, const PoissonRatio<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const PoissonRatio<Number>& poisson_ratio) {
  stream << poisson_ratio.Print();
  return stream;
}

template <typename Number>
inline constexpr PoissonRatio<Number> operator*(
    const Number number, const PoissonRatio<Number>& poisson_ratio) {
  return PoissonRatio<Number>{number * poisson_ratio.Value()};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PoissonRatio<Number>> {
  inline size_t operator()(const PhQ::PoissonRatio<Number>& poisson_ratio) const {
    return hash<Number>()(poisson_ratio.Value());
  }
};

}  // namespace std

#endif  // PHQ_POISSON_RATIO_HPP
