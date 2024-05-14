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

#ifndef PHQ_BULK_DYNAMIC_VISCOSITY_HPP
#define PHQ_BULK_DYNAMIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

// Bulk dynamic viscosity, also known as volume dynamic viscosity or dilatational dynamic viscosity.
template <typename Number = double>
class BulkDynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, Number> {
public:
  // Default constructor. Constructs a bulk dynamic viscosity with an uninitialized value.
  BulkDynamicViscosity() = default;

  // Constructor. Constructs a bulk dynamic viscosity with a given value expressed in a given
  // dynamic viscosity unit.
  BulkDynamicViscosity(const Number value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity, Number>(value, unit) {}

  // Destructor. Destroys this bulk dynamic viscosity.
  ~BulkDynamicViscosity() noexcept = default;

  // Copy constructor. Constructs a bulk dynamic viscosity by copying another one.
  constexpr BulkDynamicViscosity(const BulkDynamicViscosity<Number>& other) = default;

  // Copy constructor. Constructs a bulk dynamic viscosity by copying another one.
  template <typename OtherNumber>
  explicit constexpr BulkDynamicViscosity(const BulkDynamicViscosity<OtherNumber>& other)
    : BulkDynamicViscosity(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a bulk dynamic viscosity by moving another one.
  constexpr BulkDynamicViscosity(BulkDynamicViscosity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this bulk dynamic viscosity by copying another one.
  constexpr BulkDynamicViscosity<Number>& operator=(
      const BulkDynamicViscosity<Number>& other) = default;

  // Copy assignment operator. Assigns this bulk dynamic viscosity by copying another one.
  template <typename OtherNumber>
  constexpr BulkDynamicViscosity<Number>& operator=(
      const BulkDynamicViscosity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this bulk dynamic viscosity by moving another one.
  constexpr BulkDynamicViscosity<Number>& operator=(
      BulkDynamicViscosity<Number>&& other) noexcept = default;

  // Statically creates a bulk dynamic viscosity of zero.
  static constexpr BulkDynamicViscosity<Number> Zero() {
    return BulkDynamicViscosity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a bulk dynamic viscosity with a given value expressed in a given dynamic
  // viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr BulkDynamicViscosity<Number> Create(const Number value) {
    return BulkDynamicViscosity<Number>{
        StaticConvertCopy<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr BulkDynamicViscosity<Number> operator+(
      const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity<Number>{this->value + bulk_dynamic_viscosity.value};
  }

  constexpr BulkDynamicViscosity<Number> operator-(
      const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity<Number>{this->value - bulk_dynamic_viscosity.value};
  }

  constexpr BulkDynamicViscosity<Number> operator*(const Number number) const {
    return BulkDynamicViscosity<Number>{this->value * number};
  }

  constexpr BulkDynamicViscosity<Number> operator/(const Number number) const {
    return BulkDynamicViscosity<Number>{this->value / number};
  }

  constexpr Number operator/(
      const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity) const noexcept {
    return this->value / bulk_dynamic_viscosity.value;
  }

  constexpr void operator+=(const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity) noexcept {
    this->value += bulk_dynamic_viscosity.value;
  }

  constexpr void operator-=(const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity) noexcept {
    this->value -= bulk_dynamic_viscosity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a bulk dynamic viscosity with a given value expressed in the standard
  // dynamic viscosity unit.
  explicit constexpr BulkDynamicViscosity(const Number value)
    : DimensionalScalar<Unit::DynamicViscosity, Number>(value) {}

  friend class ConstitutiveModel;
};

template <typename Number>
inline constexpr bool operator==(
    const BulkDynamicViscosity<Number>& left, const BulkDynamicViscosity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const BulkDynamicViscosity<Number>& left, const BulkDynamicViscosity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const BulkDynamicViscosity<Number>& left, const BulkDynamicViscosity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const BulkDynamicViscosity<Number>& left, const BulkDynamicViscosity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const BulkDynamicViscosity<Number>& left, const BulkDynamicViscosity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const BulkDynamicViscosity<Number>& left, const BulkDynamicViscosity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const BulkDynamicViscosity<Number>& mass_density) {
  stream << mass_density.Print();
  return stream;
}

template <typename Number>
inline constexpr BulkDynamicViscosity<Number> operator*(
    const Number number, const BulkDynamicViscosity<Number>& mass_density) {
  return mass_density * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::BulkDynamicViscosity<Number>> {
  inline size_t operator()(const PhQ::BulkDynamicViscosity<Number>& bulk_dynamic_viscosity) const {
    return hash<Number>()(bulk_dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_BULK_DYNAMIC_VISCOSITY_HPP
