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

#ifndef PHQ_BULK_DYNAMIC_VISCOSITY_HPP
#define PHQ_BULK_DYNAMIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

/// \brief Bulk dynamic viscosity, also known as volume dynamic viscosity or dilatational dynamic
/// viscosity. Not to be confused with dynamic viscosity; see PhQ::DynamicViscosity.
template <typename NumericType = double>
class BulkDynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, NumericType> {
public:
  /// \brief Default constructor. Constructs a bulk dynamic viscosity with an uninitialized value.
  BulkDynamicViscosity() = default;

  /// \brief Constructor. Constructs a bulk dynamic viscosity with a given value expressed in a
  /// given dynamic viscosity unit.
  BulkDynamicViscosity(const NumericType value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this bulk dynamic viscosity.
  ~BulkDynamicViscosity() noexcept = default;

  /// \brief Copy constructor. Constructs a bulk dynamic viscosity by copying another one.
  constexpr BulkDynamicViscosity(const BulkDynamicViscosity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a bulk dynamic viscosity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr BulkDynamicViscosity(const BulkDynamicViscosity<OtherNumericType>& other)
    : BulkDynamicViscosity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a bulk dynamic viscosity by moving another one.
  constexpr BulkDynamicViscosity(BulkDynamicViscosity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this bulk dynamic viscosity by copying another one.
  constexpr BulkDynamicViscosity<NumericType>& operator=(
      const BulkDynamicViscosity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this bulk dynamic viscosity by copying another one.
  template <typename OtherNumericType>
  constexpr BulkDynamicViscosity<NumericType>& operator=(
      const BulkDynamicViscosity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this bulk dynamic viscosity by moving another one.
  constexpr BulkDynamicViscosity<NumericType>& operator=(
      BulkDynamicViscosity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a bulk dynamic viscosity of zero.
  static constexpr BulkDynamicViscosity<NumericType> Zero() {
    return BulkDynamicViscosity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a bulk dynamic viscosity with a given value expressed in a given
  /// dynamic viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr BulkDynamicViscosity<NumericType> Create(const NumericType value) {
    return BulkDynamicViscosity<NumericType>{
        ConvertStatically<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr BulkDynamicViscosity<NumericType> operator+(
      const BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity<NumericType>{this->value + bulk_dynamic_viscosity.value};
  }

  constexpr BulkDynamicViscosity<NumericType> operator-(
      const BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity<NumericType>{this->value - bulk_dynamic_viscosity.value};
  }

  constexpr BulkDynamicViscosity<NumericType> operator*(const NumericType number) const {
    return BulkDynamicViscosity<NumericType>{this->value * number};
  }

  constexpr BulkDynamicViscosity<NumericType> operator/(const NumericType number) const {
    return BulkDynamicViscosity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity) const noexcept {
    return this->value / bulk_dynamic_viscosity.value;
  }

  constexpr void operator+=(
      const BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity) noexcept {
    this->value += bulk_dynamic_viscosity.value;
  }

  constexpr void operator-=(
      const BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity) noexcept {
    this->value -= bulk_dynamic_viscosity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a bulk dynamic viscosity with a given value expressed in the
  /// standard dynamic viscosity unit.
  explicit constexpr BulkDynamicViscosity(const NumericType value)
    : DimensionalScalar<Unit::DynamicViscosity, NumericType>(value) {}

  friend class ConstitutiveModel;
};

template <typename NumericType>
inline constexpr bool operator==(const BulkDynamicViscosity<NumericType>& left,
                                 const BulkDynamicViscosity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const BulkDynamicViscosity<NumericType>& left,
                                 const BulkDynamicViscosity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const BulkDynamicViscosity<NumericType>& left,
                                const BulkDynamicViscosity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const BulkDynamicViscosity<NumericType>& left,
                                const BulkDynamicViscosity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const BulkDynamicViscosity<NumericType>& left,
                                 const BulkDynamicViscosity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const BulkDynamicViscosity<NumericType>& left,
                                 const BulkDynamicViscosity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const BulkDynamicViscosity<NumericType>& mass_density) {
  stream << mass_density.Print();
  return stream;
}

template <typename NumericType>
inline constexpr BulkDynamicViscosity<NumericType> operator*(
    const NumericType number, const BulkDynamicViscosity<NumericType>& mass_density) {
  return mass_density * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::BulkDynamicViscosity<NumericType>> {
  inline size_t operator()(
      const PhQ::BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity) const {
    return hash<NumericType>()(bulk_dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_BULK_DYNAMIC_VISCOSITY_HPP
