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

#ifndef PHQ_DIMENSIONLESS_DYAD_HPP
#define PHQ_DIMENSIONLESS_DYAD_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Dyad.hpp"

namespace PhQ {

/// \brief Abstract base class that represents any dimensionless dyadic tensor physical quantity.
/// Such a physical quantity is composed only of a value where the value is a three-dimensional
/// dyadic tensor. The tensor may be non-symmetric. Such a physical quantity has no unit of measure
/// and no dimension set.
template <typename NumericType = double>
class DimensionlessDyad {
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
  [[nodiscard]] constexpr const PhQ::Dyad<NumericType>& Value() const noexcept {
    return value;
  }

  /// \brief Returns the value of this physical quantity as a mutable value.
  constexpr PhQ::Dyad<NumericType>& MutableValue() noexcept {
    return value;
  }

  /// \brief Sets the value of this physical quantity to the given value.
  constexpr void SetValue(const PhQ::Dyad<NumericType>& value) noexcept {
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
  /// \brief Default constructor. Constructs a dimensionless dyadic tensor physical quantity with an
  /// uninitialized value.
  DimensionlessDyad() = default;

  /// \brief Constructor. Constructs a dimensionless dyadic tensor physical quantity whose value has
  /// the given xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr DimensionlessDyad(const NumericType xx, const NumericType xy, const NumericType xz,
                              const NumericType yx, const NumericType yy, const NumericType yz,
                              const NumericType zx, const NumericType zy, const NumericType zz)
    : value(xx, xy, xz, yx, yy, yz, zx, zy, zz) {}

  /// \brief Constructor. Constructs a dimensionless dyadic tensor physical quantity from a given
  /// array representing its value's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr DimensionlessDyad(const std::array<NumericType, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : value(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  /// \brief Constructor. Constructs a dimensionless dyadic tensor physical quantity with a given
  /// value.
  explicit constexpr DimensionlessDyad(const PhQ::Dyad<NumericType>& value) : value(value) {}

  /// \brief Destructor. Destroys this dimensionless dyadic tensor physical quantity.
  ~DimensionlessDyad() noexcept = default;

  /// \brief Copy constructor. Constructs a dimensionless dyadic tensor physical quantity by copying
  /// another one.
  constexpr DimensionlessDyad(const DimensionlessDyad<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dimensionless dyadic tensor physical quantity by copying
  /// another one.
  template <typename OtherNumericType>
  explicit constexpr DimensionlessDyad(const DimensionlessDyad<OtherNumericType>& other)
    : value(static_cast<PhQ::Dyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a dimensionless dyadic tensor physical quantity by moving
  /// another one.
  constexpr DimensionlessDyad(DimensionlessDyad<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dimensionless dyadic tensor physical quantity by
  /// copying another one.
  constexpr DimensionlessDyad<NumericType>& operator=(
      const DimensionlessDyad<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dimensionless dyadic tensor physical quantity by
  /// copying another one.
  template <typename OtherNumericType>
  constexpr DimensionlessDyad<NumericType>& operator=(
      const DimensionlessDyad<OtherNumericType>& other) {
    value = static_cast<PhQ::Dyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dimensionless dyadic tensor physical quantity by
  /// moving another one.
  constexpr DimensionlessDyad<NumericType>& operator=(
      DimensionlessDyad<NumericType>&& other) noexcept = default;

  /// \brief Value of this physical quantity.
  PhQ::Dyad<NumericType> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONLESS_DYAD_HPP
