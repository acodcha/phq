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

#ifndef PHQ_DISPLACEMENT_GRADIENT_HPP
#define PHQ_DISPLACEMENT_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessDyad.hpp"
#include "Dyad.hpp"
#include "ScalarDisplacementGradient.hpp"
#include "Strain.hpp"

namespace PhQ {

// Forward declaration for class PhQ::DisplacementGradient.
template <typename NumericType>
class VelocityGradient;

/// \brief Three-dimensional Euclidean displacement gradient dyadic tensor. Gradient of the
/// displacement vector. May be symmetric or asymmetric. Contains nine components in Cartesian
/// coordinates: xx, xy, xz, yx, yy, yz, zx, zy, and zz. For the scalar components or resultants of
/// a displacement gradient tensor, see PhQ::ScalarDisplacementGradient. The time rate of change of
/// a displacement gradient is a velocity gradient; see PhQ::VelocityGradient, PhQ::Time, and
/// PhQ::Frequency.
template <typename NumericType = double>
class DisplacementGradient : public DimensionlessDyad<NumericType> {
public:
  /// \brief Default constructor. Constructs a displacement gradient tensor with an uninitialized
  /// value.
  DisplacementGradient() = default;

  /// \brief Constructor. Constructs a displacement gradient tensor whose value has the given xx,
  /// xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr DisplacementGradient(const NumericType xx, const NumericType xy, const NumericType xz,
                                 const NumericType yx, const NumericType yy, const NumericType yz,
                                 const NumericType zx, const NumericType zy, const NumericType zz)
    : DimensionlessDyad<NumericType>(xx, xy, xz, yx, yy, yz, zx, zy, zz) {}

  /// \brief Constructor. Constructs a displacement gradient tensor from a given array representing
  /// its value's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr DisplacementGradient(
      const std::array<NumericType, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : DimensionlessDyad<NumericType>(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  /// \brief Constructor. Constructs a displacement gradient tensor with a given value.
  explicit constexpr DisplacementGradient(const Dyad<NumericType>& value)
    : DimensionlessDyad<NumericType>(value) {}

  /// \brief Constructor. Constructs a displacement gradient tensor from a given velocity gradient
  /// tensor and time using the definition of speed.
  constexpr DisplacementGradient(
      const VelocityGradient<NumericType>& velocity_gradient, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a displacement gradient tensor from a given velocity gradient
  /// tensor and frequency using the definition of speed.
  constexpr DisplacementGradient(const VelocityGradient<NumericType>& velocity_gradient,
                                 const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this displacement gradient tensor.
  ~DisplacementGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a displacement gradient tensor by copying another one.
  constexpr DisplacementGradient(const DisplacementGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a displacement gradient tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr DisplacementGradient(const DisplacementGradient<OtherNumericType>& other)
    : DisplacementGradient(static_cast<Dyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a displacement gradient tensor by moving another one.
  constexpr DisplacementGradient(DisplacementGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this displacement gradient tensor by copying another
  /// one.
  constexpr DisplacementGradient<NumericType>& operator=(
      const DisplacementGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this displacement gradient tensor by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr DisplacementGradient<NumericType>& operator=(
      const DisplacementGradient<OtherNumericType>& other) {
    this->value = static_cast<Dyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this displacement gradient tensor by moving another
  /// one.
  constexpr DisplacementGradient<NumericType>& operator=(
      DisplacementGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a displacement gradient tensor of zero.
  static constexpr DisplacementGradient<NumericType> Zero() {
    return DisplacementGradient<NumericType>{Dyad<NumericType>::Zero()};
  }

  /// \brief Returns the xx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> xx() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.xx()};
  }

  /// \brief Returns the xy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> xy() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.xy()};
  }

  /// \brief Returns the xz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> xz() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.xz()};
  }

  /// \brief Returns the yx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> yx() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> yy() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.yy()};
  }

  /// \brief Returns the yz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> yz() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.yz()};
  }

  /// \brief Returns the zx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> zx() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.zx()};
  }

  /// \brief Returns the zy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> zy() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<NumericType> zz() const noexcept {
    return ScalarDisplacementGradient<NumericType>{this->value.zz()};
  }

  /// \brief Creates a strain tensor from this displacement gradient tensor using the definition of
  /// the strain tensor.
  [[nodiscard]] constexpr PhQ::Strain<NumericType> Strain() const {
    return PhQ::Strain<NumericType>{*this};
  }

  constexpr DisplacementGradient<NumericType> operator+(
      const DisplacementGradient<NumericType>& displacement_gradient) const {
    return DisplacementGradient<NumericType>{this->value + displacement_gradient.value};
  }

  constexpr DisplacementGradient<NumericType> operator-(
      const DisplacementGradient<NumericType>& displacement_gradient) const {
    return DisplacementGradient<NumericType>{this->value - displacement_gradient.value};
  }

  constexpr DisplacementGradient<NumericType> operator*(const NumericType number) const {
    return DisplacementGradient<NumericType>{this->value * number};
  }

  constexpr VelocityGradient<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr DisplacementGradient<NumericType> operator/(const NumericType number) const {
    return DisplacementGradient<NumericType>{this->value / number};
  }

  constexpr VelocityGradient<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr void operator+=(
      const DisplacementGradient<NumericType>& displacement_gradient) noexcept {
    this->value += displacement_gradient.value;
  }

  constexpr void operator-=(
      const DisplacementGradient<NumericType>& displacement_gradient) noexcept {
    this->value -= displacement_gradient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(const DisplacementGradient<NumericType>& left,
                                 const DisplacementGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const DisplacementGradient<NumericType>& left,
                                 const DisplacementGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const DisplacementGradient<NumericType>& left,
                                const DisplacementGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const DisplacementGradient<NumericType>& left,
                                const DisplacementGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const DisplacementGradient<NumericType>& left,
                                 const DisplacementGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const DisplacementGradient<NumericType>& left,
                                 const DisplacementGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const DisplacementGradient<NumericType>& displacement_gradient) {
  stream << displacement_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr DisplacementGradient<NumericType> operator*(
    const NumericType number, const DisplacementGradient<NumericType>& displacement_gradient) {
  return displacement_gradient * number;
}

template <typename NumericType>
inline constexpr Strain<NumericType>::Strain(
    const DisplacementGradient<NumericType>& displacement_gradient)
  : Strain<NumericType>(
      displacement_gradient.Value().xx(),
      0.5 * (displacement_gradient.Value().xy() + displacement_gradient.Value().yx()),
      0.5 * (displacement_gradient.Value().xz() + displacement_gradient.Value().zx()),
      displacement_gradient.Value().yy(),
      0.5 * (displacement_gradient.Value().yz() + displacement_gradient.Value().zy()),
      displacement_gradient.Value().zz()) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::DisplacementGradient<NumericType>> {
  inline size_t operator()(
      const PhQ::DisplacementGradient<NumericType>& displacement_gradient) const {
    return hash<PhQ::Dyad<NumericType>>()(displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_DISPLACEMENT_GRADIENT_HPP
