// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_HPP

#include "DimensionalDyadQuantity.hpp"
#include "StrainRate.hpp"

namespace PhQ {

// Velocity gradient dyadic tensor.
class VelocityGradient : public DimensionalDyadQuantity<Unit::Frequency> {
public:
  constexpr VelocityGradient() noexcept
    : DimensionalDyadQuantity<Unit::Frequency>() {}

  VelocityGradient(
      const Value::Dyad& value, const Unit::Frequency& unit) noexcept
    : DimensionalDyadQuantity<Unit::Frequency>(value, unit) {}

  static constexpr VelocityGradient Zero() noexcept {
    return VelocityGradient{Value::Dyad::Zero()};
  }

  template <Unit::Frequency Unit>
  static constexpr VelocityGradient Create(const Value::Dyad& value) noexcept {
    return VelocityGradient{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            value)};
  }

  constexpr PhQ::StrainRate StrainRate() const noexcept {
    return PhQ::StrainRate{*this};
  }

  constexpr VelocityGradient operator+(
      const VelocityGradient& velocity_gradient) const noexcept {
    return VelocityGradient{value_ + velocity_gradient.value_};
  }

  constexpr VelocityGradient operator-(
      const VelocityGradient& velocity_gradient) const noexcept {
    return VelocityGradient{value_ - velocity_gradient.value_};
  }

  constexpr VelocityGradient operator*(const double number) const noexcept {
    return VelocityGradient{value_ * number};
  }

  constexpr VelocityGradient operator/(const double number) const noexcept {
    return VelocityGradient{value_ / number};
  }

  constexpr void operator+=(
      const VelocityGradient& velocity_gradient) noexcept {
    value_ += velocity_gradient.value_;
  }

  constexpr void operator-=(
      const VelocityGradient& velocity_gradient) noexcept {
    value_ -= velocity_gradient.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr VelocityGradient(const Value::Dyad& value) noexcept
    : DimensionalDyadQuantity<Unit::Frequency>(value) {}
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

inline std::ostream& operator<<(
    std::ostream& stream, const VelocityGradient& velocity_gradient) noexcept {
  stream << velocity_gradient.Print();
  return stream;
}

inline constexpr VelocityGradient operator*(
    const double number, const VelocityGradient& velocity_gradient) noexcept {
  return velocity_gradient * number;
}

inline constexpr StrainRate::StrainRate(
    const VelocityGradient& velocity_gradient) noexcept
  : StrainRate({value_.xx(), 0.5 * (value_.xy() + value_.yx()),
                0.5 * (value_.xz() + value_.zx()), value_.yy(),
                0.5 * (value_.yz() + value_.zy()), value_.zz()}) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::VelocityGradient> {
  inline size_t operator()(
      const PhQ::VelocityGradient& velocity_gradient) const {
    return hash<PhQ::Value::Dyad>()(velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_HPP
