// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP
#define PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "SymmetricDyad.hpp"

namespace PhQ {

/// \brief Abstract base class that represents any dimensionless symmetric dyadic tensor physical
/// quantity. Such a physical quantity is composed only of a value where the value is a
/// three-dimensional symmetric dyadic tensor. Such a physical quantity has no unit of measure and
/// no dimension set.
template <typename NumericType = double>
class DimensionlessSymmetricDyad {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of a physical quantity must be a numeric "
                "floating-point type: float, double, or long double.");

public:
  /// \brief Physical dimension set of this physical quantity. Since this physical quantity is
  /// dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return PhQ::Dimensionless;
  }

  /// \brief Value of this physical quantity.
  [[nodiscard]] constexpr const PhQ::SymmetricDyad<NumericType>& Value() const noexcept {
    return value;
  }

  /// \brief Returns the value of this physical quantity as a mutable value.
  constexpr PhQ::SymmetricDyad<NumericType>& MutableValue() noexcept {
    return value;
  }

  /// \brief Sets the value of this physical quantity to the given value.
  constexpr void SetValue(const PhQ::SymmetricDyad<NumericType>& value) noexcept {
    this->value = value;
  }

  /// \brief Prints this physical quantity as a string.
  [[nodiscard]] std::string Print() const {
    return value.Print();
  }

  /// \brief Serializes this physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return value.JSON();
  }

  /// \brief Serializes this physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return value.XML();
  }

  /// \brief Serializes this physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return value.YAML();
  }

protected:
  /// \brief Default constructor. Constructs a dimensionless symmetric dyadic tensor physical
  /// quantity with an uninitialized value.
  DimensionlessSymmetricDyad() = default;

  /// \brief Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity whose
  /// value has the given xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr DimensionlessSymmetricDyad(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yy,
      const NumericType yz, const NumericType zz)
    : value(xx, xy, xz, yy, yz, zz) {}

  /// \brief Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity from
  /// a given array representing its value's xx, xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr DimensionlessSymmetricDyad(const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz)
    : value(xx_xy_xz_yy_yz_zz) {}

  /// \brief Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity with
  /// a given value.
  explicit constexpr DimensionlessSymmetricDyad(const PhQ::SymmetricDyad<NumericType>& value)
    : value(value) {}

  /// \brief Destructor. Destroys this dimensionless symmetric dyadic tensor physical quantity.
  ~DimensionlessSymmetricDyad() noexcept = default;

  /// \brief Copy constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity
  /// by copying another one.
  constexpr DimensionlessSymmetricDyad(
      const DimensionlessSymmetricDyad<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity
  /// by copying another one.
  template <typename OtherNumericType>
  explicit constexpr DimensionlessSymmetricDyad(
      const DimensionlessSymmetricDyad<OtherNumericType>& other)
    : value(static_cast<PhQ::SymmetricDyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity
  /// by moving another one.
  constexpr DimensionlessSymmetricDyad(
      DimensionlessSymmetricDyad<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dimensionless symmetric dyadic tensor physical
  /// quantity by copying another one.
  constexpr DimensionlessSymmetricDyad<NumericType>& operator=(
      const DimensionlessSymmetricDyad<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dimensionless symmetric dyadic tensor physical
  /// quantity by copying another one.
  template <typename OtherNumericType>
  constexpr DimensionlessSymmetricDyad<NumericType>& operator=(
      const DimensionlessSymmetricDyad<OtherNumericType>& other) {
    value = static_cast<PhQ::SymmetricDyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dimensionless symmetric dyadic tensor physical
  /// quantity by moving another one.
  constexpr DimensionlessSymmetricDyad<NumericType>& operator=(
      DimensionlessSymmetricDyad<NumericType>&& other) noexcept = default;

  /// \brief Value of this physical quantity.
  PhQ::SymmetricDyad<NumericType> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP
