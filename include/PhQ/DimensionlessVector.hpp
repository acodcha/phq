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

#ifndef PHQ_DIMENSIONLESS_VECTOR_HPP
#define PHQ_DIMENSIONLESS_VECTOR_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Vector.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless vector physical quantity. Such a physical
// quantity is composed only of a value where the value is a three-dimensional vector. Such a
// physical quantity has no unit of measure and no dimension set.
template <typename Number = double>
class DimensionlessVector {
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
  [[nodiscard]] constexpr const PhQ::Vector<Number>& Value() const noexcept {
    return value;
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
  // Default constructor. Constructs a dimensionless vector physical quantity with an uninitialized
  // value.
  DimensionlessVector() = default;

  // Constructor. Constructs a dimensionless vector physical quantity whose value has the given x,
  // y, and z Cartesian components.
  constexpr DimensionlessVector(const Number x, const Number y, const Number z) : value(x, y, z) {}

  // Constructor. Constructs a dimensionless vector physical quantity from a given array
  // representing its value's x, y, and z Cartesian components.
  explicit constexpr DimensionlessVector(const std::array<Number, 3>& x_y_z) : value(x_y_z) {}

  // Constructor. Constructs a dimensionless vector physical quantity with a given value.
  explicit constexpr DimensionlessVector(const PhQ::Vector<Number>& value) : value(value) {}

  // Destructor. Destroys this dimensionless vector physical quantity.
  ~DimensionlessVector() noexcept = default;

  // Copy constructor. Constructs a dimensionless vector physical quantity by copying another one.
  constexpr DimensionlessVector(const DimensionlessVector<Number>& other) = default;

  // Copy constructor. Constructs a dimensionless vector physical quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr DimensionlessVector(const DimensionlessVector<OtherNumber>& other)
    : value(static_cast<PhQ::Vector<Number>>(other.Value())) {}

  // Move constructor. Constructs a dimensionless vector physical quantity by moving another one.
  constexpr DimensionlessVector(DimensionlessVector<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless vector physical quantity by copying
  // another one.
  constexpr DimensionlessVector<Number>& operator=(
      const DimensionlessVector<Number>& other) = default;

  // Copy assignment operator. Assigns this dimensionless vector physical quantity by copying
  // another one.
  template <typename OtherNumber>
  constexpr DimensionlessVector<Number>& operator=(const DimensionlessVector<OtherNumber>& other) {
    value = static_cast<PhQ::Vector<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this dimensionless vector physical quantity by moving another
  // one.
  constexpr DimensionlessVector<Number>& operator=(
      DimensionlessVector<Number>&& other) noexcept = default;

  // Value of this physical quantity.
  PhQ::Vector<Number> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONLESS_VECTOR_HPP
