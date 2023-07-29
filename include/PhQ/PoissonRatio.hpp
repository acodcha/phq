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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_POISSON_RATIO_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_POISSON_RATIO_HPP

#include "Quantity/DimensionlessScalar.hpp"

namespace PhQ {

// Poisson's ratio of a deformable solid material.
class PoissonRatio : public DimensionlessScalarQuantity {
public:
  constexpr PoissonRatio() noexcept : DimensionlessScalarQuantity() {}

  explicit constexpr PoissonRatio(const double value) noexcept
    : DimensionlessScalarQuantity(value) {}

  static constexpr PoissonRatio Zero() noexcept { return PoissonRatio{0.0}; }

  inline constexpr PoissonRatio operator+(
      const PoissonRatio& poisson_ratio) const noexcept {
    return PoissonRatio{value_ + poisson_ratio.value_};
  }

  inline constexpr PoissonRatio operator-(
      const PoissonRatio& poisson_ratio) const noexcept {
    return PoissonRatio{value_ - poisson_ratio.value_};
  }

  inline constexpr PoissonRatio operator*(const double number) const noexcept {
    return PoissonRatio{value_ * number};
  }

  inline constexpr PoissonRatio operator/(const double number) const noexcept {
    return PoissonRatio{value_ / number};
  }

  inline constexpr void operator+=(const PoissonRatio& poisson_ratio) noexcept {
    value_ += poisson_ratio.value_;
  }

  inline constexpr void operator-=(const PoissonRatio& poisson_ratio) noexcept {
    value_ -= poisson_ratio.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const PoissonRatio& poisson_ratio) noexcept {
  stream << poisson_ratio.Print();
  return stream;
}

inline constexpr PoissonRatio operator+(
    const double number, const PoissonRatio& poisson_ratio) noexcept {
  return PoissonRatio{number + poisson_ratio.Value()};
}

inline constexpr PoissonRatio operator-(
    const double number, const PoissonRatio& poisson_ratio) noexcept {
  return PoissonRatio{number - poisson_ratio.Value()};
}

inline constexpr PoissonRatio operator*(
    const double number, const PoissonRatio& poisson_ratio) noexcept {
  return PoissonRatio{number * poisson_ratio.Value()};
}

inline constexpr double operator/(
    const double number, const PoissonRatio& poisson_ratio) noexcept {
  return number / poisson_ratio.Value();
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::PoissonRatio> {
  size_t operator()(const PhQ::PoissonRatio& poisson_ratio) const {
    return hash<double>()(poisson_ratio.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_POISSON_RATIO_HPP
