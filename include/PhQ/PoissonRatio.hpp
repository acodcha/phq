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

#ifndef PHQ_POISSON_RATIO_HPP
#define PHQ_POISSON_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

/// \brief Poisson's ratio of a deformable solid material. Measures the deformation of a deformable
/// solid material subjected to a load in directions perpendicular to the direction of loading.
/// Poisson's ratios range from -1 to 0.5, though most deformable solid materials have a
/// Poisson's ratio between 0 and 0.5.
template <typename NumericType = double>
class PoissonRatio : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a Poisson's ratio with an uninitialized value.
  PoissonRatio() = default;

  /// \brief Constructor. Constructs a Poisson's ratio with a given value.
  explicit constexpr PoissonRatio(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Destructor. Destroys this Poisson's ratio.
  ~PoissonRatio() noexcept = default;

  /// \brief Copy constructor. Constructs a Poisson's ratio by copying another one.
  constexpr PoissonRatio(const PoissonRatio<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a Poisson's ratio by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PoissonRatio(const PoissonRatio<OtherNumericType>& other)
    : PoissonRatio(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a Poisson's ratio by moving another one.
  constexpr PoissonRatio(PoissonRatio<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  constexpr PoissonRatio<NumericType>& operator=(const PoissonRatio<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  template <typename OtherNumericType>
  constexpr PoissonRatio<NumericType>& operator=(const PoissonRatio<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Poisson's ratio by moving another one.
  constexpr PoissonRatio<NumericType>& operator=(
      PoissonRatio<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a Poisson's ratio of zero.
  [[nodiscard]] static constexpr PoissonRatio<NumericType> Zero() {
    return PoissonRatio<NumericType>{static_cast<NumericType>(0)};
  }

  constexpr PoissonRatio<NumericType> operator+(
      const PoissonRatio<NumericType>& poisson_ratio) const {
    return PoissonRatio<NumericType>{this->value + poisson_ratio.value};
  }

  constexpr PoissonRatio<NumericType> operator-(
      const PoissonRatio<NumericType>& poisson_ratio) const {
    return PoissonRatio<NumericType>{this->value - poisson_ratio.value};
  }

  constexpr PoissonRatio<NumericType> operator*(const NumericType number) const {
    return PoissonRatio<NumericType>{this->value * number};
  }

  constexpr PoissonRatio<NumericType> operator/(const NumericType number) const {
    return PoissonRatio<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const PoissonRatio<NumericType>& poisson_ratio) const noexcept {
    return this->value / poisson_ratio.value;
  }

  constexpr void operator+=(const PoissonRatio<NumericType>& poisson_ratio) noexcept {
    this->value += poisson_ratio.value;
  }

  constexpr void operator-=(const PoissonRatio<NumericType>& poisson_ratio) noexcept {
    this->value -= poisson_ratio.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(
    const PoissonRatio<NumericType>& left, const PoissonRatio<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PoissonRatio<NumericType>& left, const PoissonRatio<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PoissonRatio<NumericType>& left, const PoissonRatio<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PoissonRatio<NumericType>& left, const PoissonRatio<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PoissonRatio<NumericType>& left, const PoissonRatio<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PoissonRatio<NumericType>& left, const PoissonRatio<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PoissonRatio<NumericType>& poisson_ratio) {
  stream << poisson_ratio.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PoissonRatio<NumericType> operator*(
    const NumericType number, const PoissonRatio<NumericType>& poisson_ratio) {
  return PoissonRatio<NumericType>{number * poisson_ratio.Value()};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PoissonRatio<NumericType>> {
  inline size_t operator()(const PhQ::PoissonRatio<NumericType>& poisson_ratio) const {
    return hash<NumericType>()(poisson_ratio.Value());
  }
};

}  // namespace std

#endif  // PHQ_POISSON_RATIO_HPP
