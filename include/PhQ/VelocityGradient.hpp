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

#ifndef PHQ_VELOCITY_GRADIENT_HPP
#define PHQ_VELOCITY_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalDyad.hpp"
#include "DisplacementGradient.hpp"
#include "Dyad.hpp"
#include "Frequency.hpp"
#include "ScalarVelocityGradient.hpp"
#include "StrainRate.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Velocity gradient dyadic tensor. In general, this dyadic tensor is asymmetric. See also
// PhQ::ScalarVelocityGradient and PhQ::DisplacementGradient.
template <typename Number = double>
class VelocityGradient : public DimensionalDyad<Unit::Frequency, Number> {
public:
  // Default constructor. Constructs a velocity gradient tensor with an uninitialized value.
  VelocityGradient() = default;

  // Constructor. Constructs a velocity gradient tensor with a given value expressed in a given
  // frequency unit.
  VelocityGradient(const Dyad<Number>& value, const Unit::Frequency& unit)
    : DimensionalDyad<Unit::Frequency, Number>(value, unit) {}

  // Constructor. Constructs a velocity gradient tensor from a given displacement gradient tensor
  // and time using the definition of speed.
  constexpr VelocityGradient(
      const DisplacementGradient<Number>& displacement_gradient, const Time<Number>& time)
    : VelocityGradient<Number>(displacement_gradient.Value() / time.Value()) {}

  // Constructor. Constructs a velocity gradient tensor from a given displacement gradient tensor
  // and frequency using the definition of speed.
  constexpr VelocityGradient(
      const DisplacementGradient<Number>& displacement_gradient, const Frequency<Number>& frequency)
    : VelocityGradient<Number>(displacement_gradient.Value() * frequency.Value()) {}

  // Destructor. Destroys this velocity gradient tensor.
  ~VelocityGradient() noexcept = default;

  // Copy constructor. Constructs a velocity gradient tensor by copying another one.
  constexpr VelocityGradient(const VelocityGradient<Number>& other) = default;

  // Copy constructor. Constructs a velocity gradient tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr VelocityGradient(const VelocityGradient<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a velocity gradient tensor by moving another one.
  constexpr VelocityGradient(VelocityGradient<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  constexpr VelocityGradient<Number>& operator=(const VelocityGradient<Number>& other) = default;

  // Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  template <typename OtherNumber>
  constexpr VelocityGradient<Number>& operator=(const VelocityGradient<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this velocity gradient tensor by moving another one.
  constexpr VelocityGradient<Number>& operator=(
      VelocityGradient<Number>&& other) noexcept = default;

  // Statically creates a velocity gradient tensor of zero.
  static constexpr VelocityGradient<Number> Zero() {
    return VelocityGradient<Number>{Dyad<Number>::Zero()};
  }

  // Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz, zx,zy, and
  // zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<Number> Create(
      const Number xx, const Number xy, const Number xz, const Number yx, const Number yy,
      const Number yz, const Number zx, const Number zy, const Number zz) {
    return VelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            Dyad<Number>{xx, xy, xz, yx, yy, yz, zx, zy, zz})};
  }

  // Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz, zx,zy, and
  // zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<Number> Create(
      const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) {
    return VelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            Dyad<Number>{xx_xy_xz_yx_yy_yz_zx_zy_zz})};
  }

  // Statically creates a velocity gradient tensor with a given value expressed in a given frequency
  // unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<Number> Create(const Dyad<Number>& value) {
    return VelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  // Returns the xx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> xx() const noexcept {
    return ScalarVelocityGradient<Number>{value.xx()};
  }

  // Returns the xy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> xy() const noexcept {
    return ScalarVelocityGradient<Number>{value.xy()};
  }

  // Returns the xz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> xz() const noexcept {
    return ScalarVelocityGradient<Number>{value.xz()};
  }

  // Returns the yx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> yx() const noexcept {
    return ScalarVelocityGradient<Number>{value.yx()};
  }

  // Returns the yy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> yy() const noexcept {
    return ScalarVelocityGradient<Number>{value.yy()};
  }

  // Returns the yz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> yz() const noexcept {
    return ScalarVelocityGradient<Number>{value.yz()};
  }

  // Returns the zx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> zx() const noexcept {
    return ScalarVelocityGradient<Number>{value.zx()};
  }

  // Returns the zy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> zy() const noexcept {
    return ScalarVelocityGradient<Number>{value.zy()};
  }

  // Returns the zz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> zz() const noexcept {
    return ScalarVelocityGradient<Number>{value.zz()};
  }

  // Creates a strain rate tensor from this velocity gradient tensor using the definition of the
  // strain rate tensor.
  [[nodiscard]] constexpr PhQ::StrainRate<Number> StrainRate() const {
    return PhQ::StrainRate<Number>{*this};
  }

  constexpr VelocityGradient<Number> operator+(
      const VelocityGradient<Number>& velocity_gradient) const {
    return VelocityGradient<Number>{value + velocity_gradient.value};
  }

  constexpr VelocityGradient<Number> operator-(
      const VelocityGradient<Number>& velocity_gradient) const {
    return VelocityGradient<Number>{value - velocity_gradient.value};
  }

  constexpr VelocityGradient<Number> operator*(const Number number) const {
    return VelocityGradient<Number>{value * number};
  }

  constexpr DisplacementGradient<Number> operator*(const Time<Number>& time) const {
    return DisplacementGradient<Number>{*this, time};
  }

  constexpr VelocityGradient<Number> operator/(const Number number) const {
    return VelocityGradient<Number>{value / number};
  }

  constexpr DisplacementGradient<Number> operator/(const Frequency<Number>& frequency) const {
    return DisplacementGradient<Number>{*this, frequency};
  }

  constexpr void operator+=(const VelocityGradient<Number>& velocity_gradient) noexcept {
    value += velocity_gradient.value;
  }

  constexpr void operator-=(const VelocityGradient<Number>& velocity_gradient) noexcept {
    value -= velocity_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a velocity gradient tensor with a given value expressed in the standard
  // frequency unit.
  explicit constexpr VelocityGradient(const Dyad<Number>& value)
    : DimensionalDyad<Unit::Frequency, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const VelocityGradient<Number>& left, const VelocityGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const VelocityGradient<Number>& left, const VelocityGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const VelocityGradient<Number>& left, const VelocityGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const VelocityGradient<Number>& left, const VelocityGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const VelocityGradient<Number>& left, const VelocityGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const VelocityGradient<Number>& left, const VelocityGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const VelocityGradient<Number>& velocity_gradient) {
  stream << velocity_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr VelocityGradient<Number> operator*(
    const Number number, const VelocityGradient<Number>& velocity_gradient) {
  return velocity_gradient * number;
}

template <typename Number>
inline constexpr StrainRate<Number>::StrainRate(const VelocityGradient<Number>& velocity_gradient)
  : StrainRate<Number>(
      {velocity_gradient.Value().xx(),
       0.5 * (velocity_gradient.Value().xy() + velocity_gradient.Value().yx()),
       0.5 * (velocity_gradient.Value().xz() + velocity_gradient.Value().zx()),
       velocity_gradient.Value().yy(),
       0.5 * (velocity_gradient.Value().yz() + velocity_gradient.Value().zy()),
       velocity_gradient.Value().zz()}) {}

template <typename Number>
inline constexpr DisplacementGradient<Number>::DisplacementGradient(
    const VelocityGradient<Number>& scalar_velocity_gradient, const Time<Number>& time)
  : DisplacementGradient<Number>(scalar_velocity_gradient.Value() * time.Value()) {}

template <typename Number>
inline constexpr DisplacementGradient<Number>::DisplacementGradient(
    const VelocityGradient<Number>& scalar_velocity_gradient, const Frequency<Number>& frequency)
  : DisplacementGradient<Number>(scalar_velocity_gradient.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr VelocityGradient<Number> DisplacementGradient<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return VelocityGradient<Number>{*this, frequency};
}

template <typename Number>
inline constexpr VelocityGradient<Number> DisplacementGradient<Number>::operator/(
    const Time<Number>& time) const {
  return VelocityGradient<Number>{*this, time};
}

template <typename Number>
inline constexpr DisplacementGradient<Number> Time<Number>::operator*(
    const VelocityGradient<Number>& velocity_gradient) const {
  return DisplacementGradient<Number>{velocity_gradient, *this};
}

template <typename Number>
inline constexpr VelocityGradient<Number> Frequency<Number>::operator*(
    const DisplacementGradient<Number>& displacement_gradient) const {
  return VelocityGradient<Number>{displacement_gradient, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::VelocityGradient<Number>> {
  inline size_t operator()(const PhQ::VelocityGradient<Number>& velocity_gradient) const {
    return hash<PhQ::Dyad<Number>>()(velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_VELOCITY_GRADIENT_HPP
