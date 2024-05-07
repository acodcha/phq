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

#ifndef PHQ_BULK_DYNAMIC_VISCOSITY_HPP
#define PHQ_BULK_DYNAMIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

// Bulk dynamic viscosity, also known as volume dynamic viscosity or dilatational dynamic viscosity.
class BulkDynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, double> {
public:
  // Default constructor. Constructs a bulk dynamic viscosity with an uninitialized value.
  BulkDynamicViscosity() = default;

  // Constructor. Constructs a bulk dynamic viscosity with a given value expressed in a given
  // dynamic viscosity unit.
  BulkDynamicViscosity(const double value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity>(value, unit) {}

  // Destructor. Destroys this bulk dynamic viscosity.
  ~BulkDynamicViscosity() noexcept = default;

  // Copy constructor. Constructs a bulk dynamic viscosity by copying another one.
  constexpr BulkDynamicViscosity(const BulkDynamicViscosity& other) = default;

  // Move constructor. Constructs a bulk dynamic viscosity by moving another one.
  constexpr BulkDynamicViscosity(BulkDynamicViscosity&& other) noexcept = default;

  // Copy assignment operator. Assigns this bulk dynamic viscosity by copying another one.
  constexpr BulkDynamicViscosity& operator=(const BulkDynamicViscosity& other) = default;

  // Move assignment operator. Assigns this bulk dynamic viscosity by moving another one.
  constexpr BulkDynamicViscosity& operator=(BulkDynamicViscosity&& other) noexcept = default;

  // Statically creates a bulk dynamic viscosity of zero.
  static constexpr BulkDynamicViscosity Zero() {
    return BulkDynamicViscosity{0.0};
  }

  // Statically creates a bulk dynamic viscosity with a given value expressed in a given dynamic
  // viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr BulkDynamicViscosity Create(const double value) {
    return BulkDynamicViscosity{
        StaticConvertCopy<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr BulkDynamicViscosity operator+(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity{value + bulk_dynamic_viscosity.value};
  }

  constexpr BulkDynamicViscosity operator-(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity{value - bulk_dynamic_viscosity.value};
  }

  constexpr BulkDynamicViscosity operator*(const double number) const {
    return BulkDynamicViscosity{value * number};
  }

  constexpr BulkDynamicViscosity operator/(const double number) const {
    return BulkDynamicViscosity{value / number};
  }

  constexpr double operator/(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value / bulk_dynamic_viscosity.value;
  }

  constexpr void operator+=(const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept {
    value += bulk_dynamic_viscosity.value;
  }

  constexpr void operator-=(const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept {
    value -= bulk_dynamic_viscosity.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a bulk dynamic viscosity with a given value expressed in the standard
  // dynamic viscosity unit.
  explicit constexpr BulkDynamicViscosity(const double value)
    : DimensionalScalar<Unit::DynamicViscosity>(value) {}

  friend class ConstitutiveModel;
};

inline constexpr bool operator==(
    const BulkDynamicViscosity& left, const BulkDynamicViscosity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const BulkDynamicViscosity& left, const BulkDynamicViscosity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const BulkDynamicViscosity& left, const BulkDynamicViscosity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const BulkDynamicViscosity& left, const BulkDynamicViscosity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const BulkDynamicViscosity& left, const BulkDynamicViscosity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const BulkDynamicViscosity& left, const BulkDynamicViscosity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const BulkDynamicViscosity& mass_density) {
  stream << mass_density.Print();
  return stream;
}

inline constexpr BulkDynamicViscosity operator*(
    const double number, const BulkDynamicViscosity& mass_density) {
  return mass_density * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::BulkDynamicViscosity> {
  inline size_t operator()(const PhQ::BulkDynamicViscosity& bulk_dynamic_viscosity) const {
    return hash<double>()(bulk_dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_BULK_DYNAMIC_VISCOSITY_HPP
