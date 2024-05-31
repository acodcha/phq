// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

/// \brief Three-dimensional Euclidean velocity gradient dyadic tensor. Gradient of the velocity
/// vector. May be symmetric or asymmetric. Contains nine components in Cartesian coordinates: xx,
/// xy, xz, yx, yy, yz, zx, zy, and zz. For the scalar components or resultants of a velocity
/// gradient tensor, see PhQ::ScalarVelocityGradient. Can also represent the time rate of change of
/// a displacement gradient; see PhQ::DisplacementGradient, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class VelocityGradient : public DimensionalDyad<Unit::Frequency, NumericType> {
public:
  /// \brief Default constructor. Constructs a velocity gradient tensor with an uninitialized value.
  VelocityGradient() = default;

  /// \brief Constructor. Constructs a velocity gradient tensor with a given value expressed in a
  /// given frequency unit.
  VelocityGradient(const Dyad<NumericType>& value, const Unit::Frequency& unit)
    : DimensionalDyad<Unit::Frequency, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a velocity gradient tensor from a given set of scalar velocity
  /// gradient components.
  VelocityGradient(
      const ScalarVelocityGradient<NumericType>& xx, const ScalarVelocityGradient<NumericType>& xy,
      const ScalarVelocityGradient<NumericType>& xz, const ScalarVelocityGradient<NumericType>& yx,
      const ScalarVelocityGradient<NumericType>& yy, const ScalarVelocityGradient<NumericType>& yz,
      const ScalarVelocityGradient<NumericType>& zx, const ScalarVelocityGradient<NumericType>& zy,
      const ScalarVelocityGradient<NumericType>& zz)
    : VelocityGradient<NumericType>({xx.Value(), xy.Value(), xz.Value(), yx.Value(), yy.Value(),
                                     yz.Value(), zx.Value(), zy.Value(), zz.Value()}) {}

  /// \brief Constructor. Constructs a velocity gradient tensor from a given displacement gradient
  /// tensor and time using the definition of speed.
  constexpr VelocityGradient(
      const DisplacementGradient<NumericType>& displacement_gradient, const Time<NumericType>& time)
    : VelocityGradient<NumericType>(displacement_gradient.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a velocity gradient tensor from a given displacement gradient
  /// tensor and frequency using the definition of speed.
  constexpr VelocityGradient(const DisplacementGradient<NumericType>& displacement_gradient,
                             const Frequency<NumericType>& frequency)
    : VelocityGradient<NumericType>(displacement_gradient.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this velocity gradient tensor.
  ~VelocityGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a velocity gradient tensor by copying another one.
  constexpr VelocityGradient(const VelocityGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a velocity gradient tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr VelocityGradient(const VelocityGradient<OtherNumericType>& other)
    : VelocityGradient(static_cast<Dyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a velocity gradient tensor by moving another one.
  constexpr VelocityGradient(VelocityGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  constexpr VelocityGradient<NumericType>& operator=(
      const VelocityGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this velocity gradient tensor by copying another one.
  template <typename OtherNumericType>
  constexpr VelocityGradient<NumericType>& operator=(
      const VelocityGradient<OtherNumericType>& other) {
    this->value = static_cast<Dyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this velocity gradient tensor by moving another one.
  constexpr VelocityGradient<NumericType>& operator=(
      VelocityGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a velocity gradient tensor of zero.
  static constexpr VelocityGradient<NumericType> Zero() {
    return VelocityGradient<NumericType>{Dyad<NumericType>::Zero()};
  }

  /// \brief Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz,
  /// zx,zy, and zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<NumericType> Create(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yx,
      const NumericType yy, const NumericType yz, const NumericType zx, const NumericType zy,
      const NumericType zz) {
    return VelocityGradient<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            Dyad<NumericType>{xx, xy, xz, yx, yy, yz, zx, zy, zz})};
  }

  /// \brief Statically creates a velocity gradient tensor from the given xx, xy, xz, yx, yy, yz,
  /// zx,zy, and zz Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<NumericType> Create(
      const std::array<NumericType, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) {
    return VelocityGradient<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            Dyad<NumericType>{xx_xy_xz_yx_yy_yz_zx_zy_zz})};
  }

  /// \brief Statically creates a velocity gradient tensor with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradient<NumericType> Create(const Dyad<NumericType>& value) {
    return VelocityGradient<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  /// \brief Returns the xx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> xx() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.xx()};
  }

  /// \brief Returns the xy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> xy() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.xy()};
  }

  /// \brief Returns the xz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> xz() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.xz()};
  }

  /// \brief Returns the yx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> yx() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> yy() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.yy()};
  }

  /// \brief Returns the yz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> yz() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.yz()};
  }

  /// \brief Returns the zx Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> zx() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.zx()};
  }

  /// \brief Returns the zy Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> zy() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this velocity gradient tensor.
  [[nodiscard]] constexpr ScalarVelocityGradient<NumericType> zz() const noexcept {
    return ScalarVelocityGradient<NumericType>{this->value.zz()};
  }

  /// \brief Creates a strain rate tensor from this velocity gradient tensor using the definition of
  /// the strain rate tensor.
  [[nodiscard]] constexpr PhQ::StrainRate<NumericType> StrainRate() const {
    return PhQ::StrainRate<NumericType>{*this};
  }

  constexpr VelocityGradient<NumericType> operator+(
      const VelocityGradient<NumericType>& velocity_gradient) const {
    return VelocityGradient<NumericType>{this->value + velocity_gradient.value};
  }

  constexpr VelocityGradient<NumericType> operator-(
      const VelocityGradient<NumericType>& velocity_gradient) const {
    return VelocityGradient<NumericType>{this->value - velocity_gradient.value};
  }

  constexpr VelocityGradient<NumericType> operator*(const NumericType number) const {
    return VelocityGradient<NumericType>{this->value * number};
  }

  constexpr DisplacementGradient<NumericType> operator*(const Time<NumericType>& time) const {
    return DisplacementGradient<NumericType>{*this, time};
  }

  constexpr VelocityGradient<NumericType> operator/(const NumericType number) const {
    return VelocityGradient<NumericType>{this->value / number};
  }

  constexpr DisplacementGradient<NumericType> operator/(
      const Frequency<NumericType>& frequency) const {
    return DisplacementGradient<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const VelocityGradient<NumericType>& velocity_gradient) noexcept {
    this->value += velocity_gradient.value;
  }

  constexpr void operator-=(const VelocityGradient<NumericType>& velocity_gradient) noexcept {
    this->value -= velocity_gradient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a velocity gradient tensor with a given value expressed in the
  /// standard frequency unit.
  explicit constexpr VelocityGradient(const Dyad<NumericType>& value)
    : DimensionalDyad<Unit::Frequency, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const VelocityGradient<NumericType>& left,
                                 const VelocityGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const VelocityGradient<NumericType>& left,
                                 const VelocityGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const VelocityGradient<NumericType>& left,
                                const VelocityGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const VelocityGradient<NumericType>& left,
                                const VelocityGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const VelocityGradient<NumericType>& left,
                                 const VelocityGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const VelocityGradient<NumericType>& left,
                                 const VelocityGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const VelocityGradient<NumericType>& velocity_gradient) {
  stream << velocity_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr VelocityGradient<NumericType> operator*(
    const NumericType number, const VelocityGradient<NumericType>& velocity_gradient) {
  return velocity_gradient * number;
}

template <typename NumericType>
inline constexpr StrainRate<NumericType>::StrainRate(
    const VelocityGradient<NumericType>& velocity_gradient)
  : StrainRate<NumericType>(
      {velocity_gradient.Value().xx(),
       0.5 * (velocity_gradient.Value().xy() + velocity_gradient.Value().yx()),
       0.5 * (velocity_gradient.Value().xz() + velocity_gradient.Value().zx()),
       velocity_gradient.Value().yy(),
       0.5 * (velocity_gradient.Value().yz() + velocity_gradient.Value().zy()),
       velocity_gradient.Value().zz()}) {}

template <typename NumericType>
inline constexpr DisplacementGradient<NumericType>::DisplacementGradient(
    const VelocityGradient<NumericType>& scalar_velocity_gradient, const Time<NumericType>& time)
  : DisplacementGradient<NumericType>(scalar_velocity_gradient.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr DisplacementGradient<NumericType>::DisplacementGradient(
    const VelocityGradient<NumericType>& scalar_velocity_gradient,
    const Frequency<NumericType>& frequency)
  : DisplacementGradient<NumericType>(scalar_velocity_gradient.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr VelocityGradient<NumericType> DisplacementGradient<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return VelocityGradient<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr VelocityGradient<NumericType> DisplacementGradient<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return VelocityGradient<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr DisplacementGradient<NumericType> Time<NumericType>::operator*(
    const VelocityGradient<NumericType>& velocity_gradient) const {
  return DisplacementGradient<NumericType>{velocity_gradient, *this};
}

template <typename NumericType>
inline constexpr VelocityGradient<NumericType> Frequency<NumericType>::operator*(
    const DisplacementGradient<NumericType>& displacement_gradient) const {
  return VelocityGradient<NumericType>{displacement_gradient, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::VelocityGradient<NumericType>> {
  inline size_t operator()(const PhQ::VelocityGradient<NumericType>& velocity_gradient) const {
    return hash<PhQ::Dyad<NumericType>>()(velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_VELOCITY_GRADIENT_HPP
