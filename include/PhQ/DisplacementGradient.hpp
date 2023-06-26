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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_HPP

#include "Quantity/DimensionlessDyad.hpp"
#include "Strain.hpp"

namespace PhQ {

class DisplacementGradient : public DimensionlessDyadQuantity {
public:
  constexpr DisplacementGradient() noexcept : DimensionlessDyadQuantity() {}

  explicit constexpr DisplacementGradient(const Value::Dyad& value) noexcept
    : DimensionlessDyadQuantity(value) {}

  inline constexpr PhQ::Strain Strain() const noexcept {
    return PhQ::Strain{*this};
  }

  inline constexpr DisplacementGradient operator+(
      const DisplacementGradient& displacement_gradient) const noexcept {
    return DisplacementGradient{value_ + displacement_gradient.value_};
  }

  inline constexpr DisplacementGradient operator-(
      const DisplacementGradient& displacement_gradient) const noexcept {
    return DisplacementGradient{value_ - displacement_gradient.value_};
  }

  inline constexpr DisplacementGradient operator*(
      const double number) const noexcept {
    return DisplacementGradient{value_ * number};
  }

  inline constexpr DisplacementGradient operator/(
      const double number) const noexcept {
    return DisplacementGradient{value_ / number};
  }

  inline constexpr void operator+=(
      const DisplacementGradient& displacement_gradient) noexcept {
    value_ += displacement_gradient.value_;
  }

  inline constexpr void operator-=(
      const DisplacementGradient& displacement_gradient) noexcept {
    value_ -= displacement_gradient.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(const DisplacementGradient& left,
                                 const DisplacementGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const DisplacementGradient& left,
                                 const DisplacementGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const DisplacementGradient& left,
                                const DisplacementGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const DisplacementGradient& left,
                                const DisplacementGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const DisplacementGradient& left,
                                 const DisplacementGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const DisplacementGradient& left,
                                 const DisplacementGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const DisplacementGradient& displacement_gradient) noexcept {
  stream << displacement_gradient.Print();
  return stream;
}

inline constexpr DisplacementGradient operator*(
    const double number,
    const DisplacementGradient& displacement_gradient) noexcept {
  return displacement_gradient * number;
}

inline constexpr Strain::Strain(
    const DisplacementGradient& displacement_gradient) noexcept
  : Strain({value_.xx(), 0.5 * (value_.xy() + value_.yx()),
            0.5 * (value_.xz() + value_.zx()), value_.yy(),
            0.5 * (value_.yz() + value_.zy()), value_.zz()}) {}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::DisplacementGradient> {
  size_t operator()(
      const PhQ::DisplacementGradient& displacement_gradient) const {
    return hash<PhQ::Value::Dyad>()(displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_HPP
