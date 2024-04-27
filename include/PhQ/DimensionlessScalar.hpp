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

#ifndef PHQ_DIMENSIONLESS_SCALAR_HPP
#define PHQ_DIMENSIONLESS_SCALAR_HPP

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless scalar physical quantity. Such a physical
// quantity is composed only of a value where the value is a scalar number. Such a physical quantity
// has no unit of measure and no dimension set.
class DimensionlessScalar {
public:
  // Physical dimension set of this dimensionless physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return Dimensionless;
  }

  // Value of this dimensionless physical quantity.
  [[nodiscard]] inline constexpr double Value() const noexcept {
    return value;
  }

  // Returns the value of this dimensionless physical quantity as a mutable value.
  inline constexpr double& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this dimensionless physical quantity to the given value.
  inline constexpr void SetValue(const double value) noexcept {
    this->value = value;
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless physical quantity's
  // value is printed to double floating point precision.
  [[nodiscard]] std::string Print() const {
    return PhQ::Print(value);
  }

  // Prints this dimensionless physical quantity as a string. This dimensionless physical quantity's
  // value is printed to the given floating point precision.
  [[nodiscard]] std::string Print(const Precision precision) const {
    return PhQ::Print(value, precision);
  }

  // Serializes this dimensionless physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return PhQ::Print(value);
  }

  // Serializes this dimensionless physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return PhQ::Print(value);
  }

  // Serializes this dimensionless physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return PhQ::Print(value);
  }

protected:
  // Default constructor. Constructs a dimensionless scalar physical quantity with an uninitialized
  // value.
  DimensionlessScalar() = default;

  // Constructor. Constructs a dimensionless scalar physical quantity with a given value.
  explicit constexpr DimensionlessScalar(const double value) : value(value) {}

  // Destructor. Destroys this dimensionless scalar physical quantity.
  ~DimensionlessScalar() noexcept = default;

  // Copy constructor. Constructs a dimensionless scalar physical quantity by copying another one.
  constexpr DimensionlessScalar(const DimensionlessScalar& other) = default;

  // Move constructor. Constructs a dimensionless scalar physical quantity by moving another one.
  constexpr DimensionlessScalar(DimensionlessScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless scalar physical quantity by copying
  // another one.
  constexpr DimensionlessScalar& operator=(const DimensionlessScalar& other) = default;

  // Move assignment operator. Assigns this dimensionless scalar physical quantity by moving another
  // one.
  constexpr DimensionlessScalar& operator=(DimensionlessScalar&& other) noexcept = default;

  // Value of this dimensionless scalar physical quantity.
  double value;
};

inline std::ostream& operator<<(std::ostream& stream, const DimensionlessScalar& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

inline constexpr double abs(const PhQ::DimensionlessScalar& quantity) {
  return abs(quantity.Value());
}

inline double cbrt(const PhQ::DimensionlessScalar& quantity) noexcept {
  return cbrt(quantity.Value());
};

inline double exp(const PhQ::DimensionlessScalar& quantity) noexcept {
  return exp(quantity.Value());
};

inline double log(const PhQ::DimensionlessScalar& quantity) noexcept {
  return log(quantity.Value());
};

inline double log2(const PhQ::DimensionlessScalar& quantity) noexcept {
  return log2(quantity.Value());
};

inline double log10(const PhQ::DimensionlessScalar& quantity) noexcept {
  return log10(quantity.Value());
};

inline constexpr double pow(const PhQ::DimensionlessScalar& quantity, const int64_t exponent) {
  return pow(quantity.Value(), exponent);
};

inline double pow(const PhQ::DimensionlessScalar& quantity, const double exponent) noexcept {
  return pow(quantity.Value(), exponent);
};

inline double sqrt(const PhQ::DimensionlessScalar& quantity) noexcept {
  return sqrt(quantity.Value());
};

template <>
struct hash<PhQ::DimensionlessScalar> {
  inline size_t operator()(const PhQ::DimensionlessScalar& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONLESS_SCALAR_HPP
