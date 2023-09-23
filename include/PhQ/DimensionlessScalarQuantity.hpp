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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SCALAR_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SCALAR_QUANTITY_HPP

#include "Dimensions.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless scalar physical
// quantity. Such a physical quantity is composed only of a value where the
// value is a scalar number. Such a physical quantity has no unit of measure and
// no dimension set.
class DimensionlessScalarQuantity {
public:
  // Physical dimension set of this dimensionless physical quantity. Since this
  // physical quantity is dimensionless, its physical dimension set is simply
  // the null set.
  static constexpr const PhQ::Dimensions Dimensions() {
    return {};
  }

  // Value of this dimensionless physical quantity.
  inline constexpr double Value() const noexcept {
    return value_;
  }

  // Returns the value of this dimensionless physical quantity as a mutable
  // value.
  inline constexpr double& MutableValue() noexcept {
    return value_;
  }

  // Sets the value of this dimensionless physical quantity to the given value.
  inline constexpr void SetValue(const double value) noexcept {
    value_ = value;
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless
  // physical quantity's value is printed to double floating point precision.
  std::string Print() const {
    return PhQ::Print(value_);
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless
  // physical quantity's value is printed to the given floating point precision.
  std::string Print(const Precision precision) const {
    return PhQ::Print(value_, precision);
  }

  // Serializes this dimensionless physical quantity as a JSON message.
  std::string JSON() const {
    return PhQ::Print(value_);
  }

  // Serializes this dimensionless physical quantity as an XML message.
  std::string XML() const {
    return PhQ::Print(value_);
  }

  // Serializes this dimensionless physical quantity as a YAML message.
  std::string YAML() const {
    return PhQ::Print(value_);
  }

protected:
  // Default constructor. Constructs a dimensionless scalar physical quantity
  // with an uninitialized value.
  DimensionlessScalarQuantity() = default;

  // Constructor. Constructs a dimensionless scalar physical quantity with a
  // given value.
  explicit constexpr DimensionlessScalarQuantity(const double value)
    : value_(value) {}

  // Destructor. Destroys this dimensionless scalar physical quantity.
  ~DimensionlessScalarQuantity() noexcept = default;

  // Copy constructor. Constructs a dimensionless scalar physical quantity by
  // copying another one.
  constexpr DimensionlessScalarQuantity(
      const DimensionlessScalarQuantity& other) = default;

  // Move constructor. Constructs a dimensionless scalar physical quantity by
  // moving another one.
  constexpr DimensionlessScalarQuantity(
      DimensionlessScalarQuantity&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless scalar physical
  // quantity by copying another one.
  constexpr DimensionlessScalarQuantity& operator=(
      const DimensionlessScalarQuantity& other) = default;

  // Move assignment operator. Assigns this dimensionless scalar physical
  // quantity by moving another one.
  constexpr DimensionlessScalarQuantity& operator=(
      DimensionlessScalarQuantity&& other) noexcept = default;

  // Value of this dimensionless scalar physical quantity.
  double value_;
};

inline std::ostream& operator<<(
    std::ostream& stream, const DimensionlessScalarQuantity& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

constexpr double abs(const PhQ::DimensionlessScalarQuantity& quantity) {
  return abs(quantity.Value());
}

double cbrt(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return cbrt(quantity.Value());
};

double exp(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return exp(quantity.Value());
};

double log(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return log(quantity.Value());
};

double log2(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return log2(quantity.Value());
};

double log10(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return log10(quantity.Value());
};

constexpr double pow(
    const PhQ::DimensionlessScalarQuantity& quantity, const int64_t exponent) {
  return pow(quantity.Value(), exponent);
};

double pow(const PhQ::DimensionlessScalarQuantity& quantity,
           const double exponent) noexcept {
  return pow(quantity.Value(), exponent);
};

double sqrt(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return sqrt(quantity.Value());
};

template <>
struct hash<PhQ::DimensionlessScalarQuantity> {
  inline size_t operator()(
      const PhQ::DimensionlessScalarQuantity& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SCALAR_QUANTITY_HPP
