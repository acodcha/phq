// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Velocity gradient dyadic tensor. In general, this dyadic tensor is asymmetric. See also
/// PhQ::ScalarVelocityGradient and PhQ::DisplacementGradient.
template <typename Number = double>
class VelocityGradient : public DimensionalDyad<Unit::Frequency, Number> {
public:
  /// \brief Default constructor. Constructs a velocity gradient tensor with an uninitialized value.
  VelocityGradient() = default;

  /// \brief Constructor. Constructs a velocity gradient tensor with a given value expressed in a
  /// given frequency unit.
  VelocityGradient(const Dyad<Number>& value, const Unit::Frequency& unit)
    : DimensionalDyad<Unit::Frequency, Number>(value, unit) {}

  /// \brief Constructor. Constructs a velocity gradient tensor from a given displacement gradient
  /// tensor and time using the definition of speed.
  constexpr VelocityGradient(
      const DisplacementGradient<Number>& displacement_gradient, const Time<Number>& time)
    : VelocityGradient<Number>(displacement_gradient.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a velocity gradient tensor from a given displacement gradient
  /// tensor and frequency using the definition of speed.
  constexpr VelocityGradient(
      const DisplacementGradient<Number>& displacement_gradient, const Frequency<Number>& frequency)
    : VelocityGradient<Number>(displacement_gradient.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this velocity gradient tensor.
  ~VelocityGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a velocity gradient tensor by copying another one.
  constexpr VelocityGradient(const VelocityGradient<Number>& other) = default;

  /// \brief Copy constructor. Constructs a velocity gradient tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr VelocityGradient(const VelocityGradient<OtherNumber>& other)
    : VelocityGradient(static_cast<Dyad<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a velocity gradient tensor by moving another one.
  constexpr VelocityGradient(VelocityGradient<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  constexpr VelocityGradient<Number>& operator=(const VelocityGradient<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  template <typename OtherNumber>
  constexpr VelocityGradient<Number>& operator=(const VelocityGradient<OtherNumber>& other) {
    this->value = static_cast<Dyad<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this velocity gradient tensor by moving another one.
  constexpr VelocityGradient<Number>& operator=(
      VelocityGradient<Number>&& other) noexcept = default;

  /// \brief Statically creates a velocity gradient tensor of zero.
  static constexpr VelocityGradient<Number> Zero() {
    return VelocityGradient<Number>{Dyad<Number>::Zero()};
  }

  /// \brief Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz,
  /// zx,zy, and zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<Number> Create(
      const Number xx, const Number xy, const Number xz, const Number yx, const Number yy,
      const Number yz, const Number zx, const Number zy, const Number zz) {
    return VelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            Dyad<Number>{xx, xy, xz, yx, yy, yz, zx, zy, zz})};
  }

  /// \brief Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz,
  /// zx,zy, and zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<Number> Create(
      const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) {
    return VelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            Dyad<Number>{xx_xy_xz_yx_yy_yz_zx_zy_zz})};
  }

  /// \brief Statically creates a velocity gradient tensor with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<Number> Create(const Dyad<Number>& value) {
    return VelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  /// \brief Returns the xx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> xx() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.xx()};
  }

  /// \brief Returns the xy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> xy() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.xy()};
  }

  /// \brief Returns the xz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> xz() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.xz()};
  }

  /// \brief Returns the yx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> yx() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> yy() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.yy()};
  }

  /// \brief Returns the yz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> yz() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.yz()};
  }

  /// \brief Returns the zx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> zx() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.zx()};
  }

  /// \brief Returns the zy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> zy() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<Number> zz() const noexcept {
    return ScalarVelocityGradient<Number>{this->value.zz()};
  }

  /// \brief Creates a strain rate tensor from this velocity gradient tensor using the definition of
  /// the strain rate tensor.
  [[nodiscard]] constexpr PhQ::StrainRate<Number> StrainRate() const {
    return PhQ::StrainRate<Number>{*this};
  }

  constexpr VelocityGradient<Number> operator+(
      const VelocityGradient<Number>& velocity_gradient) const {
    return VelocityGradient<Number>{this->value + velocity_gradient.value};
  }

  constexpr VelocityGradient<Number> operator-(
      const VelocityGradient<Number>& velocity_gradient) const {
    return VelocityGradient<Number>{this->value - velocity_gradient.value};
  }

  constexpr VelocityGradient<Number> operator*(const Number number) const {
    return VelocityGradient<Number>{this->value * number};
  }

  constexpr DisplacementGradient<Number> operator*(const Time<Number>& time) const {
    return DisplacementGradient<Number>{*this, time};
  }

  constexpr VelocityGradient<Number> operator/(const Number number) const {
    return VelocityGradient<Number>{this->value / number};
  }

  constexpr DisplacementGradient<Number> operator/(const Frequency<Number>& frequency) const {
    return DisplacementGradient<Number>{*this, frequency};
  }

  constexpr void operator+=(const VelocityGradient<Number>& velocity_gradient) noexcept {
    this->value += velocity_gradient.value;
  }

  constexpr void operator-=(const VelocityGradient<Number>& velocity_gradient) noexcept {
    this->value -= velocity_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a velocity gradient tensor with a given value expressed in the
  /// standard frequency unit.
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
