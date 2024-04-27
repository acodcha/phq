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

#ifndef PHQ_STRAIN_SCALAR_HPP
#define PHQ_STRAIN_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations for class ScalarStrain.
class Frequency;
class LinearThermalExpansionCoefficient;
class ScalarStrainRate;
class TemperatureDifference;
class Time;

// Scalar component or resultant of a strain tensor. See also PhQ::Strain and PhQ::ScalarStrainRate.
class ScalarStrain : public DimensionlessScalar {
public:
  // Default constructor. Constructs a scalar strain with an uninitialized value.
  ScalarStrain() = default;

  // Constructor. Constructs a scalar strain with a given value.
  explicit constexpr ScalarStrain(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a scalar strain from a given scalar strain rate and time using the
  // definition of strain rate.
  constexpr ScalarStrain(const ScalarStrainRate& scalar_strain_rate, const Time& time);

  // Constructor. Constructs a scalar strain from a given scalar strain rate and frequency using the
  // definition of strain rate.
  constexpr ScalarStrain(const ScalarStrainRate& scalar_strain_rate, const Frequency& frequency);

  // Constructor. Constructs a scalar strain from a given linear thermal expansion coefficient and
  // temperature difference using the definition of the linear thermal expansion coefficient.
  constexpr ScalarStrain(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient,
      const TemperatureDifference& temperature_difference);

  // Destructor. Destroys this scalar strain.
  ~ScalarStrain() noexcept = default;

  // Copy constructor. Constructs a scalar strain by copying another one.
  constexpr ScalarStrain(const ScalarStrain& other) = default;

  // Move constructor. Constructs a scalar strain by moving another one.
  constexpr ScalarStrain(ScalarStrain&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar strain by copying another one.
  constexpr ScalarStrain& operator=(const ScalarStrain& other) = default;

  // Move assignment operator. Assigns this scalar strain by moving another one.
  constexpr ScalarStrain& operator=(ScalarStrain&& other) noexcept = default;

  // Statically creates a scalar strain of zero.
  static constexpr ScalarStrain Zero() {
    return ScalarStrain{0.0};
  }

  constexpr ScalarStrain operator+(const ScalarStrain& scalar_strain) const {
    return ScalarStrain{value + scalar_strain.value};
  }

  constexpr ScalarStrain operator-(const ScalarStrain& scalar_strain) const {
    return ScalarStrain{value - scalar_strain.value};
  }

  constexpr ScalarStrain operator*(const double number) const {
    return ScalarStrain{value * number};
  }

  constexpr ScalarStrainRate operator*(const Frequency& frequency) const;

  constexpr ScalarStrain operator/(const double number) const {
    return ScalarStrain{value / number};
  }

  constexpr ScalarStrainRate operator/(const Time& time) const;

  constexpr double operator/(const ScalarStrain& scalar_strain) const noexcept {
    return value / scalar_strain.value;
  }

  constexpr void operator+=(const ScalarStrain& scalar_strain) noexcept {
    value += scalar_strain.value;
  }

  constexpr void operator-=(const ScalarStrain& scalar_strain) noexcept {
    value -= scalar_strain.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }
};

inline constexpr bool operator==(const ScalarStrain& left, const ScalarStrain& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ScalarStrain& left, const ScalarStrain& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ScalarStrain& left, const ScalarStrain& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ScalarStrain& left, const ScalarStrain& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ScalarStrain& left, const ScalarStrain& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ScalarStrain& left, const ScalarStrain& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ScalarStrain& scalar_strain) {
  stream << scalar_strain.Print();
  return stream;
}

inline constexpr ScalarStrain operator*(const double number, const ScalarStrain& scalar_strain) {
  return ScalarStrain{number * scalar_strain.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarStrain> {
  inline size_t operator()(const PhQ::ScalarStrain& scalar_strain) const {
    return hash<double>()(scalar_strain.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_SCALAR_HPP
