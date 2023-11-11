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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations for class StrainScalar.
class Frequency;
class LinearThermalExpansionCoefficient;
class StrainRateScalar;
class TemperatureDifference;
class Time;

// Scalar strain component or resultant of the strain tensor.
class StrainScalar : public DimensionlessScalar {
public:
  // Default constructor. Constructs a scalar strain with an uninitialized value.
  StrainScalar() = default;

  // Constructor. Constructs a scalar strain with a given value.
  explicit constexpr StrainScalar(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a scalar strain from a given scalar strain rate and time using the
  // definition of strain rate.
  constexpr StrainScalar(const StrainRateScalar& strain_rate_scalar, const Time& time);

  // Constructor. Constructs a scalar strain from a given scalar strain rate and frequency using the
  // definition of strain rate.
  constexpr StrainScalar(const StrainRateScalar& strain_rate_scalar, const Frequency& frequency);

  // Constructor. Constructs a scalar strain from a given linear thermal expansion coefficient and
  // temperature difference using the definition of the linear thermal expansion coefficient.
  constexpr StrainScalar(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient,
      const TemperatureDifference& temperature_difference);

  // Destructor. Destroys this scalar strain.
  ~StrainScalar() noexcept = default;

  // Copy constructor. Constructs a scalar strain by copying another one.
  constexpr StrainScalar(const StrainScalar& other) = default;

  // Move constructor. Constructs a scalar strain by moving another one.
  constexpr StrainScalar(StrainScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar strain by copying another one.
  constexpr StrainScalar& operator=(const StrainScalar& other) = default;

  // Move assignment operator. Assigns this scalar strain by moving another one.
  constexpr StrainScalar& operator=(StrainScalar&& other) noexcept = default;

  // Statically creates a scalar strain of zero.
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

  constexpr StrainRateScalar operator*(const Frequency& frequency) const;

  constexpr StrainScalar operator/(const double number) const {
    return StrainScalar{value_ / number};
  }

  constexpr StrainRateScalar operator/(const Time& time) const;

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

inline constexpr bool operator==(const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const StrainScalar& left, const StrainScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const StrainScalar& strain_scalar) {
  stream << strain_scalar.Print();
  return stream;
}

inline constexpr StrainScalar operator*(const double number, const StrainScalar& strain_scalar) {
  return StrainScalar{number * strain_scalar.Value()};
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
