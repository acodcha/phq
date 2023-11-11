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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "SymmetricDyad.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless symmetric dyadic tensor physical quantity.
// Such a physical quantity is composed only of a value where the value is a three-dimensional
// symmetric dyadic tensor. Such a physical quantity has no unit of measure and no dimension set.
class DimensionlessSymmetricDyad {
public:
  // Physical dimension set of this dimensionless physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return Dimensionless;
  }

  // Value of this dimensionless physical quantity.
  [[nodiscard]] constexpr const SymmetricDyad& Value() const noexcept {
    return value_;
  }

  // Returns the value of this dimensionless physical quantity as a mutable value.
  constexpr SymmetricDyad& MutableValue() noexcept {
    return value_;
  }

  // Sets the value of this dimensionless physical quantity to the given value.
  constexpr void SetValue(const SymmetricDyad& value) noexcept {
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
  DimensionlessSymmetricDyad() = default;

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity whose value
  // has the given xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr DimensionlessSymmetricDyad(const double xx, const double xy, const double xz,
                                       const double yy, const double yz, const double zz)
    : value_(xx, xy, xz, yy, yz, zz) {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity from a given
  // array representing its value's xx, xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr DimensionlessSymmetricDyad(const std::array<double, 6>& xx_xy_xz_yy_yz_zz)
    : value_(xx_xy_xz_yy_yz_zz) {}

  // Constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity with a given
  // value.
  explicit constexpr DimensionlessSymmetricDyad(const SymmetricDyad& value) : value_(value) {}

  // Destructor. Destroys this dimensionless symmetric dyadic tensor physical quantity.
  ~DimensionlessSymmetricDyad() noexcept = default;

  // Copy constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // copying another one.
  constexpr DimensionlessSymmetricDyad(const DimensionlessSymmetricDyad& other) = default;

  // Move constructor. Constructs a dimensionless symmetric dyadic tensor physical quantity by
  // moving another one.
  constexpr DimensionlessSymmetricDyad(DimensionlessSymmetricDyad&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by copying another one.
  constexpr DimensionlessSymmetricDyad& operator=(
      const DimensionlessSymmetricDyad& other) = default;

  // Move assignment operator. Assigns this dimensionless symmetric dyadic tensor physical quantity
  // by moving another one.
  constexpr DimensionlessSymmetricDyad& operator=(
      DimensionlessSymmetricDyad&& other) noexcept = default;

  // Value of this dimensionless symmetric dyadic tensor physical quantity.
  SymmetricDyad value_;
};

inline std::ostream& operator<<(std::ostream& stream, const DimensionlessSymmetricDyad& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DimensionlessSymmetricDyad> {
  inline size_t operator()(const PhQ::DimensionlessSymmetricDyad& quantity) const {
    return hash<PhQ::SymmetricDyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SYMMETRIC_DYAD_HPP
