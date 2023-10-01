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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP

#include "DimensionlessScalarQuantity.hpp"

namespace PhQ {

// Forward declarations for class StrainScalar.
class LinearThermalExpansionCoefficient;
class TemperatureDifference;

// Strain scalar. Component or resultant of the strain tensor.
class StrainScalar : public DimensionlessScalarQuantity {
public:
  // Default constructor. Constructs a strain scalar with an uninitialized
  // value.
  StrainScalar() = default;

  // Constructor. Constructs a strain scalar with a given value.
  explicit constexpr StrainScalar(const double value)
    : DimensionlessScalarQuantity(value) {}

  // Constructor. Constructs a strain scalar from a given linear thermal
  // expansion coefficient and temperature difference using the definition of
  // the linear thermal expansion coefficient.
  constexpr StrainScalar(const LinearThermalExpansionCoefficient&
                             linear_thermal_expansion_coefficient,
                         const TemperatureDifference& temperature_difference);

  // Destructor. Destroys this strain scalar.
  ~StrainScalar() noexcept = default;

  // Copy constructor. Constructs a strain scalar by copying another one.
  constexpr StrainScalar(const StrainScalar& other) = default;

  // Move constructor. Constructs a strain scalar by moving another one.
  constexpr StrainScalar(StrainScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this strain scalar by copying another
  // one.
  constexpr StrainScalar& operator=(const StrainScalar& other) = default;

  // Move assignment operator. Assigns this strain scalar by moving another one.
  constexpr StrainScalar& operator=(StrainScalar&& other) noexcept = default;

  // Statically creates a strain scalar of zero.
  static constexpr StrainScalar Zero() {
    return StrainScalar{0.0};
  }

  constexpr StrainScalar operator+(const StrainScalar& strain_scalar) const {
    return StrainScalar{value_ + strain_scalar.value_};
  }

  constexpr StrainScalar operator-(const StrainScalar& strain_scalar) const {
    return StrainScalar{value_ - strain_scalar.value_};
  }

  constexpr StrainScalar operator*(const double number) const {
    return StrainScalar{value_ * number};
  }

  constexpr StrainScalar operator/(const double number) const {
    return StrainScalar{value_ / number};
  }

  constexpr double operator/(const StrainScalar& strain_scalar) const noexcept {
    return value_ / strain_scalar.value_;
  }

  constexpr void operator+=(const StrainScalar& strain_scalar) noexcept {
    value_ += strain_scalar.value_;
  }

  constexpr void operator-=(const StrainScalar& strain_scalar) noexcept {
    value_ -= strain_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const StrainScalar& strain_scalar) {
  stream << strain_scalar.Print();
  return stream;
}

inline constexpr StrainScalar operator+(
    const double number, const StrainScalar& strain_scalar) {
  return StrainScalar{number + strain_scalar.Value()};
}

inline constexpr StrainScalar operator-(
    const double number, const StrainScalar& strain_scalar) {
  return StrainScalar{number - strain_scalar.Value()};
}

inline constexpr StrainScalar operator*(
    const double number, const StrainScalar& strain_scalar) {
  return StrainScalar{number * strain_scalar.Value()};
}

inline constexpr double operator/(
    const double number, const StrainScalar& strain_scalar) {
  return number / strain_scalar.Value();
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StrainScalar> {
  inline size_t operator()(const PhQ::StrainScalar& strain_scalar) const {
    return hash<double>()(strain_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP
