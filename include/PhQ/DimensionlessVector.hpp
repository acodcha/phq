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

#ifndef PHQ_DIMENSIONLESS_VECTOR_HPP
#define PHQ_DIMENSIONLESS_VECTOR_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Vector.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless vector physical quantity. Such a physical
// quantity is composed only of a value where the value is a three-dimensional vector. Such a
// physical quantity has no unit of measure and no dimension set.
class DimensionlessVector {
public:
  // Physical dimension set of this dimensionless physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return Dimensionless;
  }

  // Value of this dimensionless physical quantity.
  [[nodiscard]] constexpr const Vector& Value() const noexcept {
    return value;
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless physical quantity's
  // value is printed to double floating point precision.
  [[nodiscard]] std::string Print() const {
    return value.Print();
  }

  // Serializes this dimensionless physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return value.JSON();
  }

  // Serializes this dimensionless physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return value.XML();
  }

  // Serializes this dimensionless physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return value.YAML();
  }

protected:
  // Default constructor. Constructs a dimensionless vector physical quantity with an uninitialized
  // value.
  DimensionlessVector() = default;

  // Constructor. Constructs a dimensionless vector physical quantity whose value has the given x,
  // y, and z Cartesian components.
  constexpr DimensionlessVector(const double x, const double y, const double z) : value(x, y, z) {}

  // Constructor. Constructs a dimensionless vector physical quantity from a given array
  // representing its value's x, y, and z Cartesian components.
  explicit constexpr DimensionlessVector(const std::array<double, 3>& x_y_z) : value(x_y_z) {}

  // Constructor. Constructs a dimensionless vector physical quantity with a given value.
  explicit constexpr DimensionlessVector(const Vector& value) : value(value) {}

  // Destructor. Destroys this dimensionless vector physical quantity.
  ~DimensionlessVector() noexcept = default;

  // Copy constructor. Constructs a dimensionless vector physical quantity by copying another one.
  constexpr DimensionlessVector(const DimensionlessVector& other) = default;

  // Move constructor. Constructs a dimensionless vector physical quantity by moving another one.
  constexpr DimensionlessVector(DimensionlessVector&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless vector physical quantity by copying
  // another one.
  constexpr DimensionlessVector& operator=(const DimensionlessVector& other) = default;

  // Move assignment operator. Assigns this dimensionless vector physical quantity by moving another
  // one.
  constexpr DimensionlessVector& operator=(DimensionlessVector&& other) noexcept = default;

  // Value of this dimensionless vector physical quantity.
  Vector value;
};

inline std::ostream& operator<<(std::ostream& stream, const DimensionlessVector& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DimensionlessVector> {
  inline size_t operator()(const PhQ::DimensionlessVector& quantity) const {
    return hash<PhQ::Vector>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONLESS_VECTOR_HPP
