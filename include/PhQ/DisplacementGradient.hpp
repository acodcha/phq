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
template <typename Number>
class VelocityGradient;

// Displacement gradient dyadic tensor. Gradient of the displacement vector. In general, this dyadic
// tensor is asymmetric. See also PhQ::ScalarDisplacementGradient.
template <typename Number = double>
class DisplacementGradient : public DimensionlessDyad<Number> {
public:
  // Default constructor. Constructs a displacement gradient tensor with an uninitialized value.
  DisplacementGradient() = default;

  // Constructor. Constructs a displacement gradient tensor whose value has the given xx, xy, xz,
  // yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr DisplacementGradient(
      const Number xx, const Number xy, const Number xz, const Number yx, const Number yy,
      const Number yz, const Number zx, const Number zy, const Number zz)
    : DimensionlessDyad<Number>(xx, xy, xz, yx, yy, yz, zx, zy, zz) {}

  // Constructor. Constructs a displacement gradient tensor from a given array representing its
  // value's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr DisplacementGradient(const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : DimensionlessDyad<Number>(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  // Constructor. Constructs a displacement gradient tensor with a given value.
  explicit constexpr DisplacementGradient(const Dyad<Number>& value)
    : DimensionlessDyad<Number>(value) {}

  // Constructor. Constructs a displacement gradient tensor from a given velocity gradient tensor
  // and time using the definition of speed.
  constexpr DisplacementGradient(
      const VelocityGradient<Number>& velocity_gradient, const Time<Number>& time);

  // Constructor. Constructs a displacement gradient tensor from a given velocity gradient tensor
  // and frequency using the definition of speed.
  constexpr DisplacementGradient(
      const VelocityGradient<Number>& velocity_gradient, const Frequency<Number>& frequency);

  // Destructor. Destroys this displacement gradient tensor.
  ~DisplacementGradient() noexcept = default;

  // Copy constructor. Constructs a displacement gradient tensor by copying another one.
  constexpr DisplacementGradient(const DisplacementGradient<Number>& other) = default;

  // Copy constructor. Constructs a displacement gradient tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr DisplacementGradient(const DisplacementGradient<OtherNumber>& other)
    : value(static_cast<Dyad<Number>>(other.Value())) {}

  // Move constructor. Constructs a displacement gradient tensor by moving another one.
  constexpr DisplacementGradient(DisplacementGradient<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this displacement gradient tensor by copying another one.
  constexpr DisplacementGradient<Number>& operator=(
      const DisplacementGradient<Number>& other) = default;

  // Copy assignment operator. Assigns this displacement gradient tensor by copying another one.
  template <typename OtherNumber>
  constexpr DisplacementGradient<Number>& operator=(
      const DisplacementGradient<OtherNumber>& other) {
    value = static_cast<Dyad<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this displacement gradient tensor by moving another one.
  constexpr DisplacementGradient<Number>& operator=(
      DisplacementGradient<Number>&& other) noexcept = default;

  // Statically creates a displacement gradient tensor of zero.
  static constexpr DisplacementGradient<Number> Zero() {
    return DisplacementGradient<Number>{Dyad<Number>::Zero()};
  }

  // Returns the xx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> xx() const noexcept {
    return ScalarDisplacementGradient<Number>{value.xx()};
  }

  // Returns the xy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> xy() const noexcept {
    return ScalarDisplacementGradient<Number>{value.xy()};
  }

  // Returns the xz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> xz() const noexcept {
    return ScalarDisplacementGradient<Number>{value.xz()};
  }

  // Returns the yx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> yx() const noexcept {
    return ScalarDisplacementGradient<Number>{value.yx()};
  }

  // Returns the yy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> yy() const noexcept {
    return ScalarDisplacementGradient<Number>{value.yy()};
  }

  // Returns the yz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> yz() const noexcept {
    return ScalarDisplacementGradient<Number>{value.yz()};
  }

  // Returns the zx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> zx() const noexcept {
    return ScalarDisplacementGradient<Number>{value.zx()};
  }

  // Returns the zy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> zy() const noexcept {
    return ScalarDisplacementGradient<Number>{value.zy()};
  }

  // Returns the zz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient<Number> zz() const noexcept {
    return ScalarDisplacementGradient<Number>{value.zz()};
  }

  // Creates a strain tensor from this displacement gradient tensor using the definition of the
  // strain tensor.
  [[nodiscard]] constexpr PhQ::Strain<Number> Strain() const {
    return PhQ::Strain<Number>{*this};
  }

  constexpr DisplacementGradient<Number> operator+(
      const DisplacementGradient<Number>& displacement_gradient) const {
    return DisplacementGradient<Number>{value + displacement_gradient.value};
  }

  constexpr DisplacementGradient<Number> operator-(
      const DisplacementGradient<Number>& displacement_gradient) const {
    return DisplacementGradient<Number>{value - displacement_gradient.value};
  }

  constexpr DisplacementGradient<Number> operator*(const Number number) const {
    return DisplacementGradient<Number>{value * number};
  }

  constexpr VelocityGradient<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr DisplacementGradient<Number> operator/(const Number number) const {
    return DisplacementGradient<Number>{value / number};
  }

  constexpr VelocityGradient<Number> operator/(const Time<Number>& time) const;

  constexpr void operator+=(const DisplacementGradient<Number>& displacement_gradient) noexcept {
    value += displacement_gradient.value;
  }

  constexpr void operator-=(const DisplacementGradient<Number>& displacement_gradient) noexcept {
    value -= displacement_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(
    const DisplacementGradient<Number>& left, const DisplacementGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const DisplacementGradient<Number>& left, const DisplacementGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const DisplacementGradient<Number>& left, const DisplacementGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const DisplacementGradient<Number>& left, const DisplacementGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const DisplacementGradient<Number>& left, const DisplacementGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const DisplacementGradient<Number>& left, const DisplacementGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const DisplacementGradient<Number>& displacement_gradient) {
  stream << displacement_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr DisplacementGradient<Number> operator*(
    const Number number, const DisplacementGradient<Number>& displacement_gradient) {
  return displacement_gradient * number;
}

template <typename Number>
inline constexpr Strain<Number>::Strain(const DisplacementGradient<Number>& displacement_gradient)
  : Strain<Number>(displacement_gradient.Value().xx(),
                   0.5 * (displacement_gradient.Value().xy() + displacement_gradient.Value().yx()),
                   0.5 * (displacement_gradient.Value().xz() + displacement_gradient.Value().zx()),
                   displacement_gradient.Value().yy(),
                   0.5 * (displacement_gradient.Value().yz() + displacement_gradient.Value().zy()),
                   displacement_gradient.Value().zz()) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::DisplacementGradient<Number>> {
  inline size_t operator()(const PhQ::DisplacementGradient<Number>& displacement_gradient) const {
    return hash<PhQ::Dyad<Number>>()(displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_DISPLACEMENT_GRADIENT_HPP
