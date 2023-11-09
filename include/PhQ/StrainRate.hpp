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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_RATE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyadQuantity.hpp"
#include "Frequency.hpp"
#include "Strain.hpp"
#include "Unit/Frequency.hpp"
#include "Value/SymmetricDyad.hpp"

namespace PhQ {

// Forward declaration for class StrainRate.
class VelocityGradient;

// Strain rate symmetric dyadic tensor. Time rate of change of the strain symmetric dyadic tensor.
class StrainRate : public DimensionalSymmetricDyadQuantity<Unit::Frequency> {
public:
  // Default constructor. Constructs a strain rate tensor with an uninitialized value.
  StrainRate() = default;

  // Constructor. Constructs a strain rate tensor with a given value expressed in a given frequency
  // unit.
  StrainRate(const Value::SymmetricDyad& value, Unit::Frequency unit)
    : DimensionalSymmetricDyadQuantity<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a strain rate tensor from a given strain tensor and time using the
  // definition of the strain rate tensor.
  constexpr StrainRate(const Strain& strain, const Time& time)
    : StrainRate(strain.Value() / time.Value()) {}

  // Constructor. Constructs a strain rate tensor from a given strain tensor and frequency using the
  // definition of the strain rate tensor.
  constexpr StrainRate(const Strain& strain, const Frequency& frequency)
    : StrainRate(strain.Value() * frequency.Value()) {}

  // Constructor. Constructs a strain rate tensor from a given velocity gradient using the
  // definition of the strain rate tensor.
  explicit constexpr StrainRate(const VelocityGradient& velocity_gradient);

  // Destructor. Destroys this strain rate tensor.
  ~StrainRate() noexcept = default;

  // Copy constructor. Constructs a strain rate tensor by copying another one.
  constexpr StrainRate(const StrainRate& other) = default;

  // Move constructor. Constructs a strain rate tensor by moving another one.
  constexpr StrainRate(StrainRate&& other) noexcept = default;

  // Copy assignment operator. Assigns this strain rate tensor by copying another one.
  constexpr StrainRate& operator=(const StrainRate& other) = default;

  // Move assignment operator. Assigns this strain rate tensor by moving another one.
  constexpr StrainRate& operator=(StrainRate&& other) noexcept = default;

  // Statically creates a strain rate tensor of zero.
  static constexpr StrainRate Zero() {
    return StrainRate{Value::SymmetricDyad::Zero()};
  }

  // Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate Create(const double xx, const double xy, const double xz,
                                     const double yy, const double yz, const double zz) {
    return StrainRate{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        Value::SymmetricDyad{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate Create(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) {
    return StrainRate{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        Value::SymmetricDyad{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a strain rate tensor with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate Create(const Value::SymmetricDyad& value) {
    return StrainRate{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr StrainRate operator+(const StrainRate& strain_rate) const {
    return StrainRate{value_ + strain_rate.value_};
  }

  constexpr StrainRate operator-(const StrainRate& strain_rate) const {
    return StrainRate{value_ - strain_rate.value_};
  }

  constexpr StrainRate operator*(const double number) const {
    return StrainRate{value_ * number};
  }

  constexpr Strain operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr StrainRate operator/(const double number) const {
    return StrainRate{value_ / number};
  }

  constexpr Strain operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const StrainRate& strain_rate) noexcept {
    value_ += strain_rate.value_;
  }

  constexpr void operator-=(const StrainRate& strain_rate) noexcept {
    value_ -= strain_rate.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a strain rate tensor with a given value expressed in the standard
  // frequency unit.
  explicit constexpr StrainRate(const Value::SymmetricDyad& value)
    : DimensionalSymmetricDyadQuantity<Unit::Frequency>(value) {}
};

inline constexpr bool operator==(const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const StrainRate& strain_rate) {
  stream << strain_rate.Print();
  return stream;
}

inline constexpr StrainRate operator*(const double number, const StrainRate& strain_rate) {
  return strain_rate * number;
}

inline constexpr Strain::Strain(const StrainRate& strain_rate, const Time& time)
  : Strain(strain_rate.Value() * time.Value()) {}

inline constexpr Strain::Strain(const StrainRate& strain_rate, const Frequency& frequency)
  : Strain(strain_rate.Value() / frequency.Value()) {}

inline constexpr StrainRate Strain::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr StrainRate Strain::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Strain Time::operator*(const StrainRate& strain_rate) const {
  return {strain_rate, *this};
}

inline constexpr StrainRate Frequency::operator*(const Strain& strain) const {
  return {strain, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StrainRate> {
  inline size_t operator()(const PhQ::StrainRate& strain_rate) const {
    return hash<PhQ::Value::SymmetricDyad>()(strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_RATE_HPP
