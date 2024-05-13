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

#ifndef PHQ_STRAIN_RATE_HPP
#define PHQ_STRAIN_RATE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyad.hpp"
#include "Frequency.hpp"
#include "ScalarStrainRate.hpp"
#include "Strain.hpp"
#include "SymmetricDyad.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declaration for class PhQ::StrainRate.
template <typename Number>
class VelocityGradient;

// Strain rate symmetric dyadic tensor. Time rate of change of the strain symmetric dyadic tensor.
// See also PhQ::Strain and PhQ::ScalarStrainRate.
template <typename Number = double>
class StrainRate : public DimensionalSymmetricDyad<Unit::Frequency, Number> {
public:
  // Default constructor. Constructs a strain rate tensor with an uninitialized value.
  StrainRate() = default;

  // Constructor. Constructs a strain rate tensor with a given value expressed in a given frequency
  // unit.
  StrainRate(const SymmetricDyad<Number>& value, Unit::Frequency unit)
    : DimensionalSymmetricDyad<Unit::Frequency, Number>(value, unit) {}

  // Constructor. Constructs a strain rate tensor from a given strain tensor and time using the
  // definition of the strain rate tensor.
  constexpr StrainRate(const Strain<Number>& strain, const Time<Number>& time)
    : StrainRate<Number>(strain.Value() / time.Value()) {}

  // Constructor. Constructs a strain rate tensor from a given strain tensor and frequency using the
  // definition of the strain rate tensor.
  constexpr StrainRate(const Strain<Number>& strain, const Frequency<Number>& frequency)
    : StrainRate<Number>(strain.Value() * frequency.Value()) {}

  // Constructor. Constructs a strain rate tensor from a given velocity gradient using the
  // definition of the strain rate tensor.
  explicit constexpr StrainRate(const VelocityGradient<Number>& velocity_gradient);

  // Destructor. Destroys this strain rate tensor.
  ~StrainRate() noexcept = default;

  // Copy constructor. Constructs a strain rate tensor by copying another one.
  constexpr StrainRate(const StrainRate<Number>& other) = default;

  // Copy constructor. Constructs a strain rate tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr StrainRate(const StrainRate<OtherNumber>& other)
    : StrainRate(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a strain rate tensor by moving another one.
  constexpr StrainRate(StrainRate<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this strain rate tensor by copying another one.
  constexpr StrainRate<Number>& operator=(const StrainRate<Number>& other) = default;

  // Copy assignment operator. Assigns this strain rate tensor by copying another one.
  template <typename OtherNumber>
  constexpr StrainRate<Number>& operator=(const StrainRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this strain rate tensor by moving another one.
  constexpr StrainRate<Number>& operator=(StrainRate<Number>&& other) noexcept = default;

  // Statically creates a strain rate tensor of zero.
  static constexpr StrainRate<Number> Zero() {
    return StrainRate<Number>{SymmetricDyad<Number>::Zero()};
  }

  // Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate<Number> Create(const Number xx, const Number xy, const Number xz,
                                             const Number yy, const Number yz, const Number zz) {
    return StrainRate<Number>{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        SymmetricDyad<Number>{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate<Number> Create(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    return StrainRate<Number>{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        SymmetricDyad<Number>{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a strain rate tensor with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate<Number> Create(const SymmetricDyad<Number>& value) {
    return StrainRate<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  // Returns the xx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> xx() const noexcept {
    return ScalarStrainRate<Number>{this->value.xx()};
  }

  // Returns the xy = yx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> xy() const noexcept {
    return ScalarStrainRate<Number>{this->value.xy()};
  }

  // Returns the xz = zx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> xz() const noexcept {
    return ScalarStrainRate<Number>{this->value.xz()};
  }

  // Returns the yx = xy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> yx() const noexcept {
    return ScalarStrainRate<Number>{this->value.yx()};
  }

  // Returns the yy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> yy() const noexcept {
    return ScalarStrainRate<Number>{this->value.yy()};
  }

  // Returns the yz = zy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> yz() const noexcept {
    return ScalarStrainRate<Number>{this->value.yz()};
  }

  // Returns the zx = xz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> zx() const noexcept {
    return ScalarStrainRate<Number>{this->value.zx()};
  }

  // Returns the zy = yz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> zy() const noexcept {
    return ScalarStrainRate<Number>{this->value.zy()};
  }

  // Returns the zz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> zz() const noexcept {
    return ScalarStrainRate<Number>{this->value.zz()};
  }

  constexpr StrainRate operator+(const StrainRate<Number>& strain_rate) const {
    return StrainRate<Number>{this->value + strain_rate.value};
  }

  constexpr StrainRate<Number> operator-(const StrainRate<Number>& strain_rate) const {
    return StrainRate<Number>{this->value - strain_rate.value};
  }

  constexpr StrainRate<Number> operator*(const Number number) const {
    return StrainRate<Number>{this->value * number};
  }

  constexpr Strain<Number> operator*(const Time<Number>& time) const {
    return Strain<Number>{*this, time};
  }

  constexpr StrainRate<Number> operator/(const Number number) const {
    return StrainRate<Number>{this->value / number};
  }

  constexpr Strain<Number> operator/(const Frequency<Number>& frequency) const {
    return Strain<Number>{*this, frequency};
  }

  constexpr void operator+=(const StrainRate<Number>& strain_rate) noexcept {
    this->value += strain_rate.value;
  }

  constexpr void operator-=(const StrainRate<Number>& strain_rate) noexcept {
    this->value -= strain_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a strain rate tensor with a given value expressed in the standard
  // frequency unit.
  explicit constexpr StrainRate(const SymmetricDyad<Number>& value)
    : DimensionalSymmetricDyad<Unit::Frequency, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const StrainRate<Number>& strain_rate) {
  stream << strain_rate.Print();
  return stream;
}

template <typename Number>
inline constexpr StrainRate<Number> operator*(
    const Number number, const StrainRate<Number>& strain_rate) {
  return strain_rate * number;
}

template <typename Number>
inline constexpr Strain<Number>::Strain(
    const StrainRate<Number>& strain_rate, const Time<Number>& time)
  : Strain<Number>(strain_rate.Value() * time.Value()) {}

template <typename Number>
inline constexpr Strain<Number>::Strain(
    const StrainRate<Number>& strain_rate, const Frequency<Number>& frequency)
  : Strain<Number>(strain_rate.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr StrainRate<Number> Strain<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return StrainRate<Number>{*this, frequency};
}

template <typename Number>
inline constexpr StrainRate<Number> Strain<Number>::operator/(const Time<Number>& time) const {
  return StrainRate<Number>{*this, time};
}

template <typename Number>
inline constexpr Strain<Number> Time<Number>::operator*(
    const StrainRate<Number>& strain_rate) const {
  return Strain<Number>{strain_rate, *this};
}

template <typename Number>
inline constexpr StrainRate<Number> Frequency<Number>::operator*(
    const Strain<Number>& strain) const {
  return StrainRate<Number>{strain, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::StrainRate<Number>> {
  inline size_t operator()(const PhQ::StrainRate<Number>& strain_rate) const {
    return hash<PhQ::SymmetricDyad<Number>>()(strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_RATE_HPP
