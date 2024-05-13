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

// Abstract base class that represents any dimensionless symmetric dyadic tensor physical quantity.
// Such a physical quantity is composed only of a value where the value is a three-dimensional
// symmetric dyadic tensor. Such a physical quantity has no unit of measure and no dimension set.
template <typename Number = double>
class DimensionlessSymmetricDyad {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of a physical quantity must be a floating-point number type.");

public:
  // Physical dimension set of this physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return PhQ::Dimensionless;
  }

  // Value of this physical quantity.
  [[nodiscard]] constexpr const PhQ::SymmetricDyad<Number>& Value() const noexcept {
    return value;
  }

  // Returns the value of this physical quantity as a mutable value.
  constexpr PhQ::SymmetricDyad<Number>& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this physical quantity to the given value.
  constexpr void SetValue(const PhQ::SymmetricDyad<Number>& value) noexcept {
    this->value = value;
  }

  // Prints this physical quantity as a string.
  [[nodiscard]] std::string Print() const {
    return value.Print();
  }

  // Serializes this physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return value.JSON();
  }

  // Serializes this physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return value.XML();
  }

  // Serializes this physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return value.YAML();
  }

protected:
  // Default constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity with
  // an uninitialized value.
  DimensionlessSymmetricDyad() = default;

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity whose value
  // has the given xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr DimensionlessSymmetricDyad(const Number xx, const Number xy, const Number xz,
                                       const Number yy, const Number yz, const Number zz)
    : value(xx, xy, xz, yy, yz, zz) {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity from a given
  // array representing its value's xx, xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr DimensionlessSymmetricDyad(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz)
    : value(xx_xy_xz_yy_yz_zz) {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity with a given
  // value.
  explicit constexpr DimensionlessSymmetricDyad(const PhQ::SymmetricDyad<Number>& value)
    : value(value) {}

  // Destructor. Destroys this dimensionless symmetric dyadic tensor physical quantity.
  ~DimensionlessSymmetricDyad() noexcept = default;

  // Copy constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // copying another one.
  constexpr DimensionlessSymmetricDyad(const DimensionlessSymmetricDyad<Number>& other) = default;

  // Copy constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // copying another one.
  template <typename OtherNumber>
  explicit constexpr DimensionlessSymmetricDyad(
      const DimensionlessSymmetricDyad<OtherNumber>& other)
    : value(static_cast<PhQ::SymmetricDyad<Number>>(other.Value())) {}

  // Move constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // moving another one.
  constexpr DimensionlessSymmetricDyad(
      DimensionlessSymmetricDyad<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by copying another one.
  constexpr DimensionlessSymmetricDyad<Number>& operator=(
      const DimensionlessSymmetricDyad<Number>& other) = default;

  // Copy assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by copying another one.
  template <typename OtherNumber>
  constexpr DimensionlessSymmetricDyad<Number>& operator=(
      const DimensionlessSymmetricDyad<OtherNumber>& other) {
    value = static_cast<PhQ::SymmetricDyad<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by moving another one.
  constexpr DimensionlessSymmetricDyad<Number>& operator=(
      DimensionlessSymmetricDyad<Number>&& other) noexcept = default;

  // Value of this physical quantity.
  PhQ::SymmetricDyad<Number> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP
