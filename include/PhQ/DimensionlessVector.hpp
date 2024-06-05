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

/// \brief Abstract base class that represents any dimensionless vector physical quantity. Such a
/// physical quantity is composed only of a value where the value is a three-dimensional vector.
/// Such a physical quantity has no unit of measure and no dimension set.
/// \tparam NumericType Floating-point numeric type: float, double, or long double. Defaults to
/// double if unspecified.
template <typename NumericType = double>
class DimensionlessVector {
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
  [[nodiscard]] constexpr const PhQ::Vector<NumericType>& Value() const noexcept {
    return value;
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
  /// \brief Default constructor. Constructs a dimensionless vector physical quantity with an
  /// uninitialized value.
  DimensionlessVector() = default;

  /// \brief Constructor. Constructs a dimensionless vector physical quantity whose value has the
  /// given x, y, and z Cartesian components.
  constexpr DimensionlessVector(const NumericType x, const NumericType y, const NumericType z)
    : value(x, y, z) {}

  /// \brief Constructor. Constructs a dimensionless vector physical quantity from a given array
  /// representing its value's x, y, and z Cartesian components.
  explicit constexpr DimensionlessVector(const std::array<NumericType, 3>& x_y_z) : value(x_y_z) {}

  /// \brief Constructor. Constructs a dimensionless vector physical quantity with a given value.
  explicit constexpr DimensionlessVector(const PhQ::Vector<NumericType>& value) : value(value) {}

  /// \brief Destructor. Destroys this dimensionless vector physical quantity.
  ~DimensionlessVector() noexcept = default;

  /// \brief Copy constructor. Constructs a dimensionless vector physical quantity by copying
  /// another one.
  constexpr DimensionlessVector(const DimensionlessVector<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dimensionless vector physical quantity by copying
  /// another one.
  /// \tparam OtherNumericType Floating-point numeric type of the other physical quantity. Deduced
  /// automatically.
  template <typename OtherNumericType>
  explicit constexpr DimensionlessVector(const DimensionlessVector<OtherNumericType>& other)
    : value(static_cast<PhQ::Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a dimensionless vector physical quantity by moving another
  /// one.
  constexpr DimensionlessVector(DimensionlessVector<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dimensionless vector physical quantity by
  /// copying another one.
  constexpr DimensionlessVector<NumericType>& operator=(
      const DimensionlessVector<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dimensionless vector physical quantity by
  /// copying another one.
  /// \tparam OtherNumericType Floating-point numeric type of the other physical quantity. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr DimensionlessVector<NumericType>& operator=(
      const DimensionlessVector<OtherNumericType>& other) {
    value = static_cast<PhQ::Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dimensionless vector physical quantity by moving
  /// another one.
  constexpr DimensionlessVector<NumericType>& operator=(
      DimensionlessVector<NumericType>&& other) noexcept = default;

  /// \brief Value of this physical quantity.
  PhQ::Vector<NumericType> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONLESS_VECTOR_HPP
