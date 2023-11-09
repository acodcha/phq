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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessDyadQuantity.hpp"
#include "Strain.hpp"
#include "Value/Dyad.hpp"

namespace PhQ {

// Displacement gradient dyadic tensor. Gradient of the displacement vector. In general, this dyadic
// tensor is asymmetric.
class DisplacementGradient : public DimensionlessDyadQuantity {
public:
  // Default constructor. Constructs a displacement gradient tensor with an uninitialized value.
  DisplacementGradient() = default;

  // Constructor. Constructs a displacement gradient tensor whose value has the given xx, xy, xz,
  // yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr DisplacementGradient(
      const double xx, const double xy, const double xz, const double yx, const double yy,
      const double yz, const double zx, const double zy, const double zz)
    : DimensionlessDyadQuantity(xx, xy, xz, yx, yy, yz, zx, zy, zz) {}

  // Constructor. Constructs a displacement gradient tensor from a given array representing its
  // value's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr DisplacementGradient(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : DimensionlessDyadQuantity(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  // Constructor. Constructs a displacement gradient tensor with a given value.
  explicit constexpr DisplacementGradient(const Value::Dyad& value)
    : DimensionlessDyadQuantity(value) {}

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
    return DisplacementGradient{Value::Dyad::Zero()};
  }

  // Creates a strain tensor from this displacement gradient tensor using the definition of the
  // strain tensor.
  [[nodiscard]] constexpr PhQ::Strain Strain() const {
    return PhQ::Strain{*this};
  }

  constexpr DisplacementGradient operator+(
      const DisplacementGradient& displacement_gradient) const {
    return DisplacementGradient{value_ + displacement_gradient.value_};
  }

  constexpr DisplacementGradient operator-(
      const DisplacementGradient& displacement_gradient) const {
    return DisplacementGradient{value_ - displacement_gradient.value_};
  }

  constexpr DisplacementGradient operator*(const double number) const {
    return DisplacementGradient{value_ * number};
  }

  constexpr DisplacementGradient operator/(const double number) const {
    return DisplacementGradient{value_ / number};
  }

  constexpr void operator+=(const DisplacementGradient& displacement_gradient) noexcept {
    value_ += displacement_gradient.value_;
  }

  constexpr void operator-=(const DisplacementGradient& displacement_gradient) noexcept {
    value_ -= displacement_gradient.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
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
    return hash<PhQ::Value::Dyad>()(displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_HPP
