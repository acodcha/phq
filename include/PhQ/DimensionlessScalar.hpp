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

#ifndef PHQ_DIMENSIONLESS_SCALAR_HPP
#define PHQ_DIMENSIONLESS_SCALAR_HPP

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Dimensions.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless scalar physical quantity. Such a physical
// quantity is composed only of a value where the value is a scalar number. Such a physical quantity
// has no unit of measure and no dimension set.
template <typename Number = double>
class DimensionlessScalar {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of a physical quantity must be a floating-point number type.");

public:
  // Physical dimension set of this physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return Dimensionless;
  }

  // Value of this physical quantity.
  [[nodiscard]] inline constexpr Number Value() const noexcept {
    return value;
  }

  // Returns the value of this physical quantity as a mutable value.
  inline constexpr Number& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this physical quantity to the given value.
  inline constexpr void SetValue(const Number value) noexcept {
    this->value = value;
  }

  // Prints this physical quantity as a string.
  [[nodiscard]] std::string Print() const {
    return PhQ::Print(value);
  }

  // Serializes this physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return PhQ::Print(value);
  }

  // Serializes this physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return PhQ::Print(value);
  }

  // Serializes this physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return PhQ::Print(value);
  }

protected:
  // Default constructor. Constructs a dimensionless scalar physical quantity with an uninitialized
  // value.
  DimensionlessScalar() = default;

  // Constructor. Constructs a dimensionless scalar physical quantity with a given value.
  explicit constexpr DimensionlessScalar(const Number value) : value(value) {}

  // Destructor. Destroys this dimensionless scalar physical quantity.
  ~DimensionlessScalar() noexcept = default;

  // Copy constructor. Constructs a dimensionless scalar physical quantity by copying another one.
  constexpr DimensionlessScalar(const DimensionlessScalar& other) = default;

  // Copy constructor. Constructs a dimensionless scalar physical quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr DimensionlessScalar(const DimensionlessScalar<OtherNumber>& other)
    : value(static_cast<Number>(other.value)) {}

  // Move constructor. Constructs a dimensionless scalar physical quantity by moving another one.
  constexpr DimensionlessScalar(DimensionlessScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless scalar physical quantity by copying
  // another one.
  constexpr DimensionlessScalar& operator=(const DimensionlessScalar& other) = default;

  // Copy assignment operator. Assigns this dimensionless scalar physical quantity by copying
  // another one.
  template <typename OtherNumber>
  constexpr DimensionlessScalar& operator=(const DimensionlessScalar<OtherNumber>& other) {
    value = static_cast<Number>(other.value);
    return *this;
  }

  // Move assignment operator. Assigns this dimensionless scalar physical quantity by moving another
  // one.
  constexpr DimensionlessScalar& operator=(DimensionlessScalar&& other) noexcept = default;

  // Value of this physical quantity.
  Number value;

  template <typename OtherNumber>
  friend class DimensionlessScalar;
};

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) {
  stream << dimensionless_scalar.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
inline constexpr Number abs(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) {
  return abs(dimensionless_scalar.Value());
}

template <typename Number>
inline Number cbrt(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return cbrt(dimensionless_scalar.Value());
};

template <typename Number>
inline Number exp(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return exp(dimensionless_scalar.Value());
};

template <typename Number>
inline Number log(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return log(dimensionless_scalar.Value());
};

template <typename Number>
inline Number log2(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return log2(dimensionless_scalar.Value());
};

template <typename Number>
inline Number log10(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return log10(dimensionless_scalar.Value());
};

template <typename Number>
inline constexpr Number pow(
    const PhQ::DimensionlessScalar<Number>& dimensionless_scalar, const int64_t exponent) {
  return pow(dimensionless_scalar.Value(), exponent);
};

template <typename Number>
inline Number pow(
    const PhQ::DimensionlessScalar<Number>& dimensionless_scalar, const Number exponent) noexcept {
  return pow(dimensionless_scalar.Value(), exponent);
};

template <typename Number>
inline Number sqrt(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) noexcept {
  return sqrt(dimensionless_scalar.Value());
};

template <typename Number>
struct hash<PhQ::DimensionlessScalar<Number>> {
  inline size_t operator()(const PhQ::DimensionlessScalar<Number>& dimensionless_scalar) const {
    return hash<Number>()(dimensionless_scalar.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONLESS_SCALAR_HPP
