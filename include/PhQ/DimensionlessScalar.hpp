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
/// \tparam NumericType Floating-point numeric type: float, double, or long double. Defaults to
/// double if unspecified.
template <typename NumericType = double>
class DimensionlessScalar {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of a physical quantity must be a numeric "
                "floating-point type: float, double, or long double.");

public:
  /// \brief Physical dimension set of this physical quantity. Since this physical quantity is
  /// dimensionless, its physical dimension set is simply the null set.
  [[nodiscard]] static constexpr PhQ::Dimensions Dimensions() {
    return PhQ::Dimensionless;
  }

  /// \brief Value of this physical quantity.
  [[nodiscard]] inline constexpr NumericType Value() const noexcept {
    return value;
  }

  /// \brief Returns the value of this physical quantity as a mutable value.
  [[nodiscard]] inline constexpr NumericType& MutableValue() noexcept {
    return value;
  }

  /// \brief Sets the value of this physical quantity to the given value.
  inline constexpr void SetValue(const NumericType value) noexcept {
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
  explicit constexpr DimensionlessScalar(const NumericType value) : value(value) {}

  /// \brief Destructor. Destroys this dimensionless scalar physical quantity.
  ~DimensionlessScalar() noexcept = default;

  /// \brief Copy constructor. Constructs a dimensionless scalar physical quantity by copying
  /// another one.
  constexpr DimensionlessScalar(const DimensionlessScalar<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dimensionless scalar physical quantity by copying
  /// another one.
  /// \tparam OtherNumericType Floating-point numeric type of the other physical quantity. Deduced
  /// automatically.
  template <typename OtherNumericType>
  explicit constexpr DimensionlessScalar(const DimensionlessScalar<OtherNumericType>& other)
    : value(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a dimensionless scalar physical quantity by moving another
  /// one.
  constexpr DimensionlessScalar(DimensionlessScalar<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dimensionless scalar physical quantity by
  /// copying another one.
  constexpr DimensionlessScalar<NumericType>& operator=(
      const DimensionlessScalar<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dimensionless scalar physical quantity by
  /// copying another one.
  /// \tparam OtherNumericType Floating-point numeric type of the other physical quantity. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr DimensionlessScalar<NumericType>& operator=(
      const DimensionlessScalar<OtherNumericType>& other) {
    value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dimensionless scalar physical quantity by moving
  /// another one.
  constexpr DimensionlessScalar<NumericType>& operator=(
      DimensionlessScalar<NumericType>&& other) noexcept = default;

  /// \brief Value of this physical quantity.
  NumericType value;
};

}  // namespace PhQ

namespace std {

template <typename NumericType>
inline constexpr NumericType abs(
    const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) {
  return abs(dimensionless_scalar.Value());
}

template <typename NumericType>
inline NumericType cbrt(
    const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) noexcept {
  return cbrt(dimensionless_scalar.Value());
};

template <typename NumericType>
inline NumericType exp(const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) noexcept {
  return exp(dimensionless_scalar.Value());
};

template <typename NumericType>
inline NumericType log(const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) noexcept {
  return log(dimensionless_scalar.Value());
};

template <typename NumericType>
inline NumericType log2(
    const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) noexcept {
  return log2(dimensionless_scalar.Value());
};

template <typename NumericType>
inline NumericType log10(
    const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) noexcept {
  return log10(dimensionless_scalar.Value());
};

template <typename NumericType, typename OtherNumericType>
inline NumericType pow(const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar,
                       const OtherNumericType exponent) noexcept {
  return pow(dimensionless_scalar.Value(), exponent);
};

template <typename NumericType>
inline NumericType sqrt(
    const PhQ::DimensionlessScalar<NumericType>& dimensionless_scalar) noexcept {
  return sqrt(dimensionless_scalar.Value());
};

}  // namespace std

#endif  // PHQ_DIMENSIONLESS_SCALAR_HPP
