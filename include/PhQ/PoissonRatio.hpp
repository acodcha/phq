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

#ifndef PHQ_POISSON_RATIO_HPP
#define PHQ_POISSON_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

/// \brief Poisson's ratio of a deformable solid material.
template <typename Number = double>
class PoissonRatio : public DimensionlessScalar<Number> {
public:
  /// \brief Default constructor. Constructs a Poisson's ratio with an uninitialized value.
  PoissonRatio() = default;

  /// \brief Constructor. Constructs a Poisson's ratio with a given value.
  explicit constexpr PoissonRatio(const Number value) : DimensionlessScalar<Number>(value) {}

  /// \brief Destructor. Destroys this Poisson's ratio.
  ~PoissonRatio() noexcept = default;

  /// \brief Copy constructor. Constructs a Poisson's ratio by copying another one.
  constexpr PoissonRatio(const PoissonRatio<Number>& other) = default;

  /// \brief Copy constructor. Constructs a Poisson's ratio by copying another one.
  template <typename OtherNumber>
  explicit constexpr PoissonRatio(const PoissonRatio<OtherNumber>& other)
    : PoissonRatio(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a Poisson's ratio by moving another one.
  constexpr PoissonRatio(PoissonRatio<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  constexpr PoissonRatio<Number>& operator=(const PoissonRatio<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  template <typename OtherNumber>
  constexpr PoissonRatio<Number>& operator=(const PoissonRatio<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Poisson's ratio by moving another one.
  constexpr PoissonRatio<Number>& operator=(PoissonRatio<Number>&& other) noexcept = default;

  /// \brief Statically creates a Poisson's ratio of zero.
  static constexpr PoissonRatio<Number> Zero() {
    return PoissonRatio<Number>{static_cast<Number>(0)};
  }

  constexpr PoissonRatio<Number> operator+(const PoissonRatio<Number>& poisson_ratio) const {
    return PoissonRatio<Number>{this->value + poisson_ratio.value};
  }

  constexpr PoissonRatio<Number> operator-(const PoissonRatio<Number>& poisson_ratio) const {
    return PoissonRatio<Number>{this->value - poisson_ratio.value};
  }

  constexpr PoissonRatio<Number> operator*(const Number number) const {
    return PoissonRatio<Number>{this->value * number};
  }

  constexpr PoissonRatio<Number> operator/(const Number number) const {
    return PoissonRatio<Number>{this->value / number};
  }

  constexpr Number operator/(const PoissonRatio<Number>& poisson_ratio) const noexcept {
    return this->value / poisson_ratio.value;
  }

  constexpr void operator+=(const PoissonRatio<Number>& poisson_ratio) noexcept {
    this->value += poisson_ratio.value;
  }

  constexpr void operator-=(const PoissonRatio<Number>& poisson_ratio) noexcept {
    this->value -= poisson_ratio.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
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
