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

#ifndef PHQ_STRAIN_RATE_SCALAR_HPP
#define PHQ_STRAIN_RATE_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "ScalarStrain.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Scalar component or resultant of a strain rate tensor. Time rate of change of a scalar strain.
// See also PhQ::StrainRate and PhQ::ScalarStrain.
class ScalarStrainRate : public DimensionalScalar<Unit::Frequency> {
public:
  // Default constructor. Constructs a scalar strain rate with an uninitialized value.
  ScalarStrainRate() = default;

  // Constructor. Constructs a scalar strain rate with a given value expressed in a given frequency
  // unit.
  ScalarStrainRate(const double value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a scalar strain rate from a given scalar strain and time using the
  // definition of strain rate.
  constexpr ScalarStrainRate(const ScalarStrain& scalar_strain, const Time& time)
    : ScalarStrainRate(scalar_strain.Value() / time.Value()) {}

  // Constructor. Constructs a scalar strain rate from a given scalar strain and frequency using the
  // definition of strain rate.
  constexpr ScalarStrainRate(const ScalarStrain& scalar_strain, const Frequency& frequency)
    : ScalarStrainRate(scalar_strain.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar strain rate.
  ~ScalarStrainRate() noexcept = default;

  // Copy constructor. Constructs a scalar strain rate by copying another one.
  constexpr ScalarStrainRate(const ScalarStrainRate& other) = default;

  // Move constructor. Constructs a scalar strain rate by moving another one.
  constexpr ScalarStrainRate(ScalarStrainRate&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar strain rate by copying another one.
  constexpr ScalarStrainRate& operator=(const ScalarStrainRate& other) = default;

  // Move assignment operator. Assigns this scalar strain rate by moving another one.
  constexpr ScalarStrainRate& operator=(ScalarStrainRate&& other) noexcept = default;

  // Statically creates a scalar strain rate of zero.
  static constexpr ScalarStrainRate Zero() {
    return ScalarStrainRate{0.0};
  }

  // Statically creates a scalar strain rate with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr ScalarStrainRate Create(const double value) {
    return ScalarStrainRate{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr ScalarStrainRate operator+(const ScalarStrainRate& other) const {
    return ScalarStrainRate{value_ + other.value_};
  }

  constexpr ScalarStrainRate operator-(const ScalarStrainRate& other) const {
    return ScalarStrainRate{value_ - other.value_};
  }

  constexpr ScalarStrainRate operator*(const double number) const {
    return ScalarStrainRate{value_ * number};
  }

  constexpr ScalarStrainRate operator/(const double number) const {
    return ScalarStrainRate{value_ / number};
  }

  constexpr ScalarStrain operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr double operator/(const ScalarStrainRate& other) const noexcept {
    return value_ / other.value_;
  }

  constexpr ScalarStrain operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const ScalarStrainRate& other) noexcept {
    value_ += other.value_;
  }

  constexpr void operator-=(const ScalarStrainRate& other) noexcept {
    value_ -= other.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar strain rate with a given value expressed in the standard
  // frequency unit.
  explicit constexpr ScalarStrainRate(const double value)
    : DimensionalScalar<Unit::Frequency>(value) {}

  friend class StrainRate;
};

inline constexpr bool operator==(
    const ScalarStrainRate& left, const ScalarStrainRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ScalarStrainRate& left, const ScalarStrainRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ScalarStrainRate& left, const ScalarStrainRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ScalarStrainRate& left, const ScalarStrainRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ScalarStrainRate& left, const ScalarStrainRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ScalarStrainRate& left, const ScalarStrainRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ScalarStrainRate& scalar_strain_rate) {
  stream << scalar_strain_rate.Print();
  return stream;
}

inline constexpr ScalarStrainRate operator*(
    const double number, const ScalarStrainRate& scalar_strain_rate) {
  return scalar_strain_rate * number;
}

inline constexpr ScalarStrain::ScalarStrain(
    const ScalarStrainRate& scalar_strain_rate, const Time& time)
  : ScalarStrain(scalar_strain_rate.Value() * time.Value()) {}

inline constexpr ScalarStrain::ScalarStrain(
    const ScalarStrainRate& scalar_strain_rate, const Frequency& frequency)
  : ScalarStrain(scalar_strain_rate.Value() / frequency.Value()) {}

inline constexpr ScalarStrainRate ScalarStrain::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr ScalarStrainRate ScalarStrain::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr ScalarStrain Time::operator*(const ScalarStrainRate& scalar_strain_rate) const {
  return {scalar_strain_rate, *this};
}

inline constexpr ScalarStrainRate Frequency::operator*(const ScalarStrain& scalar_strain) const {
  return {scalar_strain, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarStrainRate> {
  inline size_t operator()(const PhQ::ScalarStrainRate& scalar_strain_rate) const {
    return hash<double>()(scalar_strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_RATE_SCALAR_HPP
