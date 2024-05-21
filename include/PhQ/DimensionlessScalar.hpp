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

#ifndef PHQ_DIMENSIONLESS_SCALAR_HPP
#define PHQ_DIMENSIONLESS_SCALAR_HPP

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Dimensions.hpp"

namespace PhQ {

/// \brief Abstract base class that represents any dimensionless scalar physical quantity. Such a
/// physical quantity is composed only of a value where the value is a scalar number. Such a
/// physical quantity has no unit of measure and no dimension set.
template <typename Number = double>
class DimensionlessScalar {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of a physical quantity must be a floating-point number type.");

public:
  /// \brief Physical dimension set of this physical quantity. Since this physical quantity is
  /// dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return PhQ::Dimensionless;
  }

  /// \brief Value of this physical quantity.
  [[nodiscard]] inline constexpr Number Value() const noexcept {
    return value;
  }

  /// \brief Returns the value of this physical quantity as a mutable value.
  inline constexpr Number& MutableValue() noexcept {
    return value;
  }

  /// \brief Sets the value of this physical quantity to the given value.
  inline constexpr void SetValue(const Number value) noexcept {
    this->value = value;
  }

  /// \brief Prints this physical quantity as a string.
  [[nodiscard]] std::string Print() const {
    return PhQ::Print(value);
  }

  /// \brief Serializes this physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return PhQ::Print(value);
  }

  /// \brief Serializes this physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return PhQ::Print(value);
  }

  /// \brief Serializes this physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return PhQ::Print(value);
  }

protected:
  /// \brief Default constructor. Constructs a dimensionless scalar physical quantity with an
  /// uninitialized value.
  DimensionlessScalar() = default;

  /// \brief Constructor. Constructs a dimensionless scalar physical quantity with a given value.
  explicit constexpr DimensionlessScalar(const Number value) : value(value) {}

  /// \brief Destructor. Destroys this dimensionless scalar physical quantity.
  ~DimensionlessScalar() noexcept = default;

  /// \brief Copy constructor. Constructs a dimensionless scalar physical quantity by copying
  /// another one.
  constexpr DimensionlessScalar(const DimensionlessScalar<Number>& other) = default;

  /// \brief Copy constructor. Constructs a dimensionless scalar physical quantity by copying
  /// another one.
  template <typename OtherNumber>
  explicit constexpr DimensionlessScalar(const DimensionlessScalar<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a dimensionless scalar physical quantity by moving another
  /// one.
  constexpr DimensionlessScalar(DimensionlessScalar<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dimensionless scalar physical quantity by
  /// copying another one.
  constexpr DimensionlessScalar<Number>& operator=(
      const DimensionlessScalar<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this dimensionless scalar physical quantity by
  /// copying another one.
  template <typename OtherNumber>
  constexpr DimensionlessScalar<Number>& operator=(const DimensionlessScalar<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dimensionless scalar physical quantity by moving
  /// another one.
  constexpr DimensionlessScalar<Number>& operator=(
      DimensionlessScalar<Number>&& other) noexcept = default;

  /// \brief Value of this physical quantity.
  Number value;
};

}  // namespace PhQ

namespace std {

template <typename Number>
inline constexpr Number abs(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) {
  return abs(dimensionless_scalar.Value());
}

template <typename Number>
inline Number cbrt(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return cbrt(dimensionless_scalar.Value());
};

template <typename Number>
inline Number exp(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return exp(dimensionless_scalar.Value());
};

template <typename Number>
inline Number log(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return log(dimensionless_scalar.Value());
};

template <typename Number>
inline Number log2(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return log2(dimensionless_scalar.Value());
};

template <typename Number>
inline Number log10(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return log10(dimensionless_scalar.Value());
};

template <typename Number, typename OtherNumber>
inline Number pow(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar,
                  const OtherNumber exponent) noexcept {
  return pow(dimensionless_scalar.Value(), exponent);
};

template <typename Number>
inline Number sqrt(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return sqrt(dimensionless_scalar.Value());
};

}  // namespace std

#endif  // PHQ_DIMENSIONLESS_SCALAR_HPP
