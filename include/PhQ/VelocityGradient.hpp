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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalDyad.hpp"
#include "DisplacementGradient.hpp"
#include "Dyad.hpp"
#include "Frequency.hpp"
#include "StrainRate.hpp"
#include "Unit/Frequency.hpp"
#include "VelocityGradientScalar.hpp"

namespace PhQ {

// Velocity gradient dyadic tensor. In general, this dyadic tensor is asymmetric.
class VelocityGradient : public DimensionalDyad<Unit::Frequency> {
public:
  // Default constructor. Constructs a velocity gradient tensor with an uninitialized value.
  VelocityGradient() = default;

  // Constructor. Constructs a velocity gradient tensor with a given value expressed in a given
  // frequency unit.
  VelocityGradient(const Dyad& value, const Unit::Frequency& unit)
    : DimensionalDyad<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a velocity gradient tensor from a given displacement gradient tensor
  // and time using the definition of speed.
  constexpr VelocityGradient(const DisplacementGradient& displacement_gradient, const Time& time)
    : VelocityGradient(displacement_gradient.Value() / time.Value()) {}

  // Constructor. Constructs a velocity gradient tensor from a given displacement gradient tensor
  // and frequency using the definition of speed.
  constexpr VelocityGradient(
      const DisplacementGradient& displacement_gradient, const Frequency& frequency)
    : VelocityGradient(displacement_gradient.Value() * frequency.Value()) {}

  // Destructor. Destroys this velocity gradient tensor.
  ~VelocityGradient() noexcept = default;

  // Copy constructor. Constructs a velocity gradient tensor by copying another one.
  constexpr VelocityGradient(const VelocityGradient& other) = default;

  // Move constructor. Constructs a velocity gradient tensor by moving another one.
  constexpr VelocityGradient(VelocityGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  constexpr VelocityGradient& operator=(const VelocityGradient& other) = default;

  // Move assignment operator. Assigns this velocity gradient tensor by moving another one.
  constexpr VelocityGradient& operator=(VelocityGradient&& other) noexcept = default;

  // Statically creates a velocity gradient tensor of zero.
  static constexpr VelocityGradient Zero() {
    return VelocityGradient{Dyad::Zero()};
  }

  // Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz, zx,zy, and
  // zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient
  Create(const double xx, const double xy, const double xz, const double yx, const double yy,
         const double yz, const double zx, const double zy, const double zz) {
    return VelocityGradient{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        Dyad{xx, xy, xz, yx, yy, yz, zx, zy, zz})};
  }

  // Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz, zx,zy, and
  // zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient
  Create(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) {
    return VelocityGradient{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        Dyad{xx_xy_xz_yx_yy_yz_zx_zy_zz})};
  }

  // Statically creates a velocity gradient tensor with a given value expressed in a given frequency
  // unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient Create(const Dyad& value) {
    return VelocityGradient{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  // Returns the xx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar xx() const noexcept {
    return VelocityGradientScalar{value_.xx()};
  }

  // Returns the xy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar xy() const noexcept {
    return VelocityGradientScalar{value_.xy()};
  }

  // Returns the xz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar xz() const noexcept {
    return VelocityGradientScalar{value_.xz()};
  }

  // Returns the yx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar yx() const noexcept {
    return VelocityGradientScalar{value_.yx()};
  }

  // Returns the yy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar yy() const noexcept {
    return VelocityGradientScalar{value_.yy()};
  }

  // Returns the yz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar yz() const noexcept {
    return VelocityGradientScalar{value_.yz()};
  }

  // Returns the zx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar zx() const noexcept {
    return VelocityGradientScalar{value_.zx()};
  }

  // Returns the zy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar zy() const noexcept {
    return VelocityGradientScalar{value_.zy()};
  }

  // Returns the zz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr VelocityGradientScalar zz() const noexcept {
    return VelocityGradientScalar{value_.zz()};
  }

  // Creates a strain rate tensor from this velocity gradient tensor using the definition of the
  // strain rate tensor.
  [[nodiscard]] constexpr PhQ::StrainRate StrainRate() const {
    return PhQ::StrainRate{*this};
  }

  constexpr VelocityGradient operator+(const VelocityGradient& velocity_gradient) const {
    return VelocityGradient{value_ + velocity_gradient.value_};
  }

  constexpr VelocityGradient operator-(const VelocityGradient& velocity_gradient) const {
    return VelocityGradient{value_ - velocity_gradient.value_};
  }

  constexpr VelocityGradient operator*(const double number) const {
    return VelocityGradient{value_ * number};
  }

  constexpr DisplacementGradient operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr VelocityGradient operator/(const double number) const {
    return VelocityGradient{value_ / number};
  }

  constexpr DisplacementGradient operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const VelocityGradient& velocity_gradient) noexcept {
    value_ += velocity_gradient.value_;
  }

  constexpr void operator-=(const VelocityGradient& velocity_gradient) noexcept {
    value_ -= velocity_gradient.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a velocity gradient tensor with a given value expressed in the standard
  // frequency unit.
  explicit constexpr VelocityGradient(const Dyad& value)
    : DimensionalDyad<Unit::Frequency>(value) {}
};

inline constexpr bool operator==(
    const VelocityGradient& left, const VelocityGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const VelocityGradient& left, const VelocityGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const VelocityGradient& left, const VelocityGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const VelocityGradient& left, const VelocityGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const VelocityGradient& left, const VelocityGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const VelocityGradient& left, const VelocityGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const VelocityGradient& velocity_gradient) {
  stream << velocity_gradient.Print();
  return stream;
}

inline constexpr VelocityGradient operator*(
    const double number, const VelocityGradient& velocity_gradient) {
  return velocity_gradient * number;
}

inline constexpr StrainRate::StrainRate(const VelocityGradient& velocity_gradient)
  : StrainRate({velocity_gradient.Value().xx(),
                0.5 * (velocity_gradient.Value().xy() + velocity_gradient.Value().yx()),
                0.5 * (velocity_gradient.Value().xz() + velocity_gradient.Value().zx()),
                velocity_gradient.Value().yy(),
                0.5 * (velocity_gradient.Value().yz() + velocity_gradient.Value().zy()),
                velocity_gradient.Value().zz()}) {}

inline constexpr DisplacementGradient::DisplacementGradient(
    const VelocityGradient& velocity_gradient_scalar, const Time& time)
  : DisplacementGradient(velocity_gradient_scalar.Value() * time.Value()) {}

inline constexpr DisplacementGradient::DisplacementGradient(
    const VelocityGradient& velocity_gradient_scalar, const Frequency& frequency)
  : DisplacementGradient(velocity_gradient_scalar.Value() / frequency.Value()) {}

inline constexpr VelocityGradient DisplacementGradient::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr VelocityGradient DisplacementGradient::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr DisplacementGradient Time::operator*(
    const VelocityGradient& velocity_gradient) const {
  return {velocity_gradient, *this};
}

inline constexpr VelocityGradient Frequency::operator*(
    const DisplacementGradient& displacement_gradient) const {
  return {displacement_gradient, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::VelocityGradient> {
  inline size_t operator()(const PhQ::VelocityGradient& velocity_gradient) const {
    return hash<PhQ::Dyad>()(velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_HPP
