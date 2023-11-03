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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_PWAVE_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_PWAVE_MODULUS_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Frequency.hpp"
#include "StrainScalar.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Scalar component or resultant of the strain rate tensor. Time rate of change
// of a scalar strain component.
class StrainRateScalar : public DimensionalScalarQuantity<Unit::Frequency> {
public:
  // Default constructor. Constructs a scalar strain rate with an uninitialized
  // value.
  StrainRateScalar() = default;

  // Constructor. Constructs a scalar strain rate with a given value expressed
  // in a given frequency unit.
  StrainRateScalar(const double value, const Unit::Frequency unit)
    : DimensionalScalarQuantity<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a scalar strain rate from a given scalar strain and
  // time using the definition of strain rate.
  constexpr StrainRateScalar(
      const StrainScalar& strain_scalar, const Time& time)
    : StrainRateScalar(strain_scalar.Value() / time.Value()) {}

  // Constructor. Constructs a scalar strain rate from a given scalar strain and
  // frequency using the definition of strain rate.
  constexpr StrainRateScalar(
      const StrainScalar& strain_scalar, const Frequency& frequency)
    : StrainRateScalar(strain_scalar.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar strain rate.
  ~StrainRateScalar() noexcept = default;

  // Copy constructor. Constructs a scalar strain rate by copying another one.
  constexpr StrainRateScalar(const StrainRateScalar& other) = default;

  // Move constructor. Constructs a scalar strain rate by moving another one.
  constexpr StrainRateScalar(StrainRateScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar strain rate by copying
  // another one.
  constexpr StrainRateScalar& operator=(
      const StrainRateScalar& other) = default;

  // Move assignment operator. Assigns this scalar strain rate by moving another
  // one.
  constexpr StrainRateScalar& operator=(
      StrainRateScalar&& other) noexcept = default;

  // Statically creates a scalar strain rate of zero.
  static constexpr StrainRateScalar Zero() {
    return StrainRateScalar{0.0};
  }

  // Statically creates a scalar strain rate with a given value expressed in a
  // given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRateScalar Create(const double value) {
    return StrainRateScalar{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            value)};
  }

  constexpr StrainRateScalar operator+(const StrainRateScalar& other) const {
    return StrainRateScalar{value_ + other.value_};
  }

  constexpr StrainRateScalar operator-(const StrainRateScalar& other) const {
    return StrainRateScalar{value_ - other.value_};
  }

  constexpr StrainRateScalar operator*(const double number) const {
    return StrainRateScalar{value_ * number};
  }

  constexpr StrainRateScalar operator/(const double number) const {
    return StrainRateScalar{value_ / number};
  }

  constexpr StrainScalar operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr double operator/(const StrainRateScalar& other) const noexcept {
    return value_ / other.value_;
  }

  constexpr StrainScalar operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const StrainRateScalar& other) noexcept {
    value_ += other.value_;
  }

  constexpr void operator-=(const StrainRateScalar& other) noexcept {
    value_ -= other.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar strain rate with a given value expressed
  // in the standard frequency unit.
  explicit constexpr StrainRateScalar(const double value)
    : DimensionalScalarQuantity<Unit::Frequency>(value) {}
};

inline constexpr bool operator==(
    const StrainRateScalar& left, const StrainRateScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StrainRateScalar& left, const StrainRateScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const StrainRateScalar& left, const StrainRateScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const StrainRateScalar& left, const StrainRateScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StrainRateScalar& left, const StrainRateScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StrainRateScalar& left, const StrainRateScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const StrainRateScalar& strain_rate_scalar) {
  stream << strain_rate_scalar.Print();
  return stream;
}

inline constexpr StrainRateScalar operator*(
    const double number, const StrainRateScalar& strain_rate_scalar) {
  return strain_rate_scalar * number;
}

inline constexpr StrainScalar::StrainScalar(
    const StrainRateScalar& strain_rate_scalar, const Time& time)
  : StrainScalar(strain_rate_scalar.Value() * time.Value()) {}

inline constexpr StrainScalar::StrainScalar(
    const StrainRateScalar& strain_rate_scalar, const Frequency& frequency)
  : StrainScalar(strain_rate_scalar.Value() / frequency.Value()) {}

inline constexpr StrainRateScalar StrainScalar::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr StrainRateScalar StrainScalar::operator/(
    const Time& time) const {
  return {*this, time};
}

inline constexpr StrainScalar Time::operator*(
    const StrainRateScalar& strain_rate_scalar) const {
  return {strain_rate_scalar, *this};
}

inline constexpr StrainRateScalar Frequency::operator*(
    const StrainScalar& strain_scalar) const {
  return {strain_scalar, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StrainRateScalar> {
  inline size_t operator()(
      const PhQ::StrainRateScalar& strain_rate_scalar) const {
    return hash<double>()(strain_rate_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_PWAVE_MODULUS_HPP
