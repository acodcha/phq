// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_QUANTITY_HPP

#include "Dimensions.hpp"
#include "Value/SymmetricDyad.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless symmetric dyadic tensor
// physical quantity. Such a physical quantity is composed only of a value where
// the value is a symmetric tensor of rank two and dimension three. Such a
// physical quantity has no unit of measure and no dimension set.
class DimensionlessSymmetricDyadQuantity {
public:
  // Physical dimension set of this dimensionless physical quantity. Since this
  // physical quantity is dimensionless, its physical dimension set is simply
  // the null set.
  static constexpr const PhQ::Dimensions Dimensions() {
    return {};
  }

  // Value of this dimensionless physical quantity.
  constexpr const Value::SymmetricDyad& Value() const noexcept {
    return value_;
  }

  // Returns the value of this dimensionless physical quantity as a mutable
  // value.
  constexpr Value::SymmetricDyad& MutableValue() noexcept {
    return value_;
  }

  // Sets the value of this dimensionless physical quantity to the given value.
  constexpr void SetValue(const Value::SymmetricDyad& value) noexcept {
    value_ = value;
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless
  // physical quantity's value is printed to double floating point precision.
  std::string Print() const {
    return value_.Print();
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless
  // physical quantity's value is printed to the given floating point precision.
  std::string Print(const Precision precision) const {
    return value_.Print(precision);
  }

  // Serializes this dimensionless physical quantity as a JSON message.
  std::string JSON() const {
    return value_.JSON();
  }

  // Serializes this dimensionless physical quantity as an XML message.
  std::string XML() const {
    return value_.XML();
  }

  // Serializes this dimensionless physical quantity as a YAML message.
  std::string YAML() const {
    return value_.YAML();
  }

protected:
  // Default constructor. Constructs a dimensionless symmetric dyadic tensor
  // physical quantity with an uninitialized value.
  constexpr DimensionlessSymmetricDyadQuantity() : value_() {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical
  // quantity with a given value.
  constexpr DimensionlessSymmetricDyadQuantity(
      const Value::SymmetricDyad& value)
    : value_(value) {}

  // Move constructor. Constructs a dimensionless symmetric dyadic tensor
  // physical quantity with a given value by moving the value.
  constexpr DimensionlessSymmetricDyadQuantity(
      Value::SymmetricDyad&& value) noexcept
    : value_(std::move(value)) {}

  // Destructor. Destroys this dimensionless symmetric dyadic tensor physical
  // quantity.
  ~DimensionlessSymmetricDyadQuantity() noexcept = default;

  // Copy assignment operator. Assigns the value of this dimensionless symmetric
  // dyadic tensor physical quantity by copying a given value.
  void operator=(const Value::SymmetricDyad& value) {
    value_ = value;
  }

  // Move assignment operator. Assigns the components of this dimensionless
  // symmetric dyadic tensor physical quantity by moving a given vector value.
  void operator=(Value::SymmetricDyad&& value) noexcept {
    value_ = std::move(value);
  }

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
  inline size_t operator()(
      const PhQ::DimensionlessSymmetricDyadQuantity& quantity) const {
    return hash<PhQ::Value::SymmetricDyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_QUANTITY_HPP
