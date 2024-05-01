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

// Forward declaration for class DisplacementGradient.
class VelocityGradient;

// Displacement gradient dyadic tensor. Gradient of the displacement vector. In general, this dyadic
// tensor is asymmetric. See also PhQ::ScalarDisplacementGradient.
class DisplacementGradient : public DimensionlessDyad {
public:
  // Default constructor. Constructs a displacement gradient tensor with an uninitialized value.
  DisplacementGradient() = default;

  // Constructor. Constructs a displacement gradient tensor whose value has the given xx, xy, xz,
  // yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr DisplacementGradient(
      const double xx, const double xy, const double xz, const double yx, const double yy,
      const double yz, const double zx, const double zy, const double zz)
    : DimensionlessDyad(xx, xy, xz, yx, yy, yz, zx, zy, zz) {}

  // Constructor. Constructs a displacement gradient tensor from a given array representing its
  // value's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr DisplacementGradient(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : DimensionlessDyad(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  // Constructor. Constructs a displacement gradient tensor with a given value.
  explicit constexpr DisplacementGradient(const Dyad<double>& value) : DimensionlessDyad(value) {}

  // Constructor. Constructs a displacement gradient tensor from a given velocity gradient tensor
  // and time using the definition of speed.
  constexpr DisplacementGradient(const VelocityGradient& velocity_gradient, const Time& time);

  // Constructor. Constructs a displacement gradient tensor from a given velocity gradient tensor
  // and frequency using the definition of speed.
  constexpr DisplacementGradient(
      const VelocityGradient& velocity_gradient, const Frequency& frequency);

  // Destructor. Destroys this displacement gradient tensor.
  ~DisplacementGradient() noexcept = default;

  // Copy constructor. Constructs a displacement gradient tensor by copying another one.
  constexpr DisplacementGradient(const DisplacementGradient& other) = default;

  // Move constructor. Constructs a displacement gradient tensor by moving another one.
  constexpr DisplacementGradient(DisplacementGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this displacement gradient tensor by copying another one.
  constexpr DisplacementGradient& operator=(const DisplacementGradient& other) = default;

  // Move assignment operator. Assigns this displacement gradient tensor by moving another one.
  constexpr DisplacementGradient& operator=(DisplacementGradient&& other) noexcept = default;

  // Statically creates a displacement gradient tensor of zero.
  static constexpr DisplacementGradient Zero() {
    return DisplacementGradient{Dyad<double>::Zero()};
  }

  // Returns the xx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient xx() const noexcept {
    return ScalarDisplacementGradient{value.xx()};
  }

  // Returns the xy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient xy() const noexcept {
    return ScalarDisplacementGradient{value.xy()};
  }

  // Returns the xz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient xz() const noexcept {
    return ScalarDisplacementGradient{value.xz()};
  }

  // Returns the yx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient yx() const noexcept {
    return ScalarDisplacementGradient{value.yx()};
  }

  // Returns the yy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient yy() const noexcept {
    return ScalarDisplacementGradient{value.yy()};
  }

  // Returns the yz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient yz() const noexcept {
    return ScalarDisplacementGradient{value.yz()};
  }

  // Returns the zx Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient zx() const noexcept {
    return ScalarDisplacementGradient{value.zx()};
  }

  // Returns the zy Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient zy() const noexcept {
    return ScalarDisplacementGradient{value.zy()};
  }

  // Returns the zz Cartesian component of this displacement gradient tensor.
  [[nodiscard]] constexpr ScalarDisplacementGradient zz() const noexcept {
    return ScalarDisplacementGradient{value.zz()};
  }

  // Creates a strain tensor from this displacement gradient tensor using the definition of the
  // strain tensor.
  [[nodiscard]] constexpr PhQ::Strain Strain() const {
    return PhQ::Strain{*this};
  }

  constexpr DisplacementGradient operator+(
      const DisplacementGradient& displacement_gradient) const {
    return DisplacementGradient{value + displacement_gradient.value};
  }

  constexpr DisplacementGradient operator-(
      const DisplacementGradient& displacement_gradient) const {
    return DisplacementGradient{value - displacement_gradient.value};
  }

  constexpr DisplacementGradient operator*(const double number) const {
    return DisplacementGradient{value * number};
  }

  constexpr VelocityGradient operator*(const Frequency& frequency) const;

  constexpr DisplacementGradient operator/(const double number) const {
    return DisplacementGradient{value / number};
  }

  constexpr VelocityGradient operator/(const Time& time) const;

  constexpr void operator+=(const DisplacementGradient& displacement_gradient) noexcept {
    value += displacement_gradient.value;
  }

  constexpr void operator-=(const DisplacementGradient& displacement_gradient) noexcept {
    value -= displacement_gradient.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }
};

inline constexpr bool operator==(
    const DisplacementGradient& left, const DisplacementGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const DisplacementGradient& left, const DisplacementGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const DisplacementGradient& left, const DisplacementGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const DisplacementGradient& left, const DisplacementGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const DisplacementGradient& left, const DisplacementGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const DisplacementGradient& left, const DisplacementGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const DisplacementGradient& displacement_gradient) {
  stream << displacement_gradient.Print();
  return stream;
}

inline constexpr DisplacementGradient operator*(
    const double number, const DisplacementGradient& displacement_gradient) {
  return displacement_gradient * number;
}

inline constexpr Strain::Strain(const DisplacementGradient& displacement_gradient)
  : Strain(displacement_gradient.Value().xx(),
           0.5 * (displacement_gradient.Value().xy() + displacement_gradient.Value().yx()),
           0.5 * (displacement_gradient.Value().xz() + displacement_gradient.Value().zx()),
           displacement_gradient.Value().yy(),
           0.5 * (displacement_gradient.Value().yz() + displacement_gradient.Value().zy()),
           displacement_gradient.Value().zz()) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DisplacementGradient> {
  inline size_t operator()(const PhQ::DisplacementGradient& displacement_gradient) const {
    return hash<PhQ::Dyad<double>>()(displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_DISPLACEMENT_GRADIENT_HPP
