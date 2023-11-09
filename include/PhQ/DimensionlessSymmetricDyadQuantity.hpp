// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_QUANTITY_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Value/SymmetricDyad.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless symmetric dyadic tensor physical quantity.
// Such a physical quantity is composed only of a value where the value is a symmetric tensor of
// rank two and dimension three. Such a physical quantity has no unit of measure and no dimension
// set.
class DimensionlessSymmetricDyadQuantity {
public:
  // Physical dimension set of this dimensionless physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr const PhQ::Dimensions Dimensions() {
    return {};
  }

  // Value of this dimensionless physical quantity.
  [[nodiscard]] constexpr const Value::SymmetricDyad& Value() const noexcept {
    return value_;
  }

  // Returns the value of this dimensionless physical quantity as a mutable value.
  constexpr Value::SymmetricDyad& MutableValue() noexcept {
    return value_;
  }

  // Sets the value of this dimensionless physical quantity to the given value.
  constexpr void SetValue(const Value::SymmetricDyad& value) noexcept {
    value_ = value;
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless physical quantity's
  // value is printed to double floating point precision.
  [[nodiscard]] std::string Print() const {
    return value_.Print();
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless physical quantity's
  // value is printed to the given floating point precision.
  [[nodiscard]] std::string Print(const Precision precision) const {
    return value_.Print(precision);
  }

  // Serializes this dimensionless physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return value_.JSON();
  }

  // Serializes this dimensionless physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return value_.XML();
  }

  // Serializes this dimensionless physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return value_.YAML();
  }

protected:
  // Default constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity with
  // an uninitialized value.
  DimensionlessSymmetricDyadQuantity() = default;

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity whose value
  // has the given xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr DimensionlessSymmetricDyadQuantity(const double xx, const double xy, const double xz,
                                               const double yy, const double yz, const double zz)
    : value_(xx, xy, xz, yy, yz, zz) {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity from a given
  // array representing its value's xx, xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr DimensionlessSymmetricDyadQuantity(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz)
    : value_(xx_xy_xz_yy_yz_zz) {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity with a given
  // value.
  explicit constexpr DimensionlessSymmetricDyadQuantity(const Value::SymmetricDyad& value)
    : value_(value) {}

  // Destructor. Destroys this dimensionless symmetric dyadic tensor physical quantity.
  ~DimensionlessSymmetricDyadQuantity() noexcept = default;

  // Copy constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // copying another one.
  constexpr DimensionlessSymmetricDyadQuantity(
      const DimensionlessSymmetricDyadQuantity& other) = default;

  // Move constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // moving another one.
  constexpr DimensionlessSymmetricDyadQuantity(
      DimensionlessSymmetricDyadQuantity&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by copying another one.
  constexpr DimensionlessSymmetricDyadQuantity& operator=(
      const DimensionlessSymmetricDyadQuantity& other) = default;

  // Move assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by moving another one.
  constexpr DimensionlessSymmetricDyadQuantity& operator=(
      DimensionlessSymmetricDyadQuantity&& other) noexcept = default;

  // Value of this dimensionless symmetric dyadic tensor physical quantity.
  Value::SymmetricDyad value_;
};

inline std::ostream& operator<<(
    std::ostream& stream, const DimensionlessSymmetricDyadQuantity& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DimensionlessSymmetricDyadQuantity> {
  inline size_t operator()(const PhQ::DimensionlessSymmetricDyadQuantity& quantity) const {
    return hash<PhQ::Value::SymmetricDyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_QUANTITY_HPP
