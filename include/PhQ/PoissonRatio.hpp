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

#ifndef PHQ_POISSON_RATIO_HPP
#define PHQ_POISSON_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Poisson's ratio of a deformable solid material.
class PoissonRatio : public DimensionlessScalar<double> {
public:
  // Default constructor. Constructs a Poisson's ratio with an uninitialized value.
  PoissonRatio() = default;

  // Constructor. Constructs a Poisson's ratio with a given value.
  explicit constexpr PoissonRatio(const double value) : DimensionlessScalar(value) {}

  // Destructor. Destroys this Poisson's ratio.
  ~PoissonRatio() noexcept = default;

  // Copy constructor. Constructs a Poisson's ratio by copying another one.
  constexpr PoissonRatio(const PoissonRatio& other) = default;

  // Move constructor. Constructs a Poisson's ratio by moving another one.
  constexpr PoissonRatio(PoissonRatio&& other) noexcept = default;

  // Copy assignment operator. Assigns this Poisson's ratio by copying another one.
  constexpr PoissonRatio& operator=(const PoissonRatio& other) = default;

  // Move assignment operator. Assigns this Poisson's ratio by moving another one.
  constexpr PoissonRatio& operator=(PoissonRatio&& other) noexcept = default;

  // Statically creates a Poisson's ratio of zero.
  static constexpr PoissonRatio Zero() {
    return PoissonRatio{0.0};
  }

  constexpr PoissonRatio operator+(const PoissonRatio& poisson_ratio) const {
    return PoissonRatio{value + poisson_ratio.value};
  }

  constexpr PoissonRatio operator-(const PoissonRatio& poisson_ratio) const {
    return PoissonRatio{value - poisson_ratio.value};
  }

  constexpr PoissonRatio operator*(const double number) const {
    return PoissonRatio{value * number};
  }

  constexpr PoissonRatio operator/(const double number) const {
    return PoissonRatio{value / number};
  }

  constexpr double operator/(const PoissonRatio& poisson_ratio) const noexcept {
    return value / poisson_ratio.value;
  }

  constexpr void operator+=(const PoissonRatio& poisson_ratio) noexcept {
    value += poisson_ratio.value;
  }

  constexpr void operator-=(const PoissonRatio& poisson_ratio) noexcept {
    value -= poisson_ratio.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }
};

inline constexpr bool operator==(const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const PoissonRatio& left, const PoissonRatio& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const PoissonRatio& poisson_ratio) {
  stream << poisson_ratio.Print();
  return stream;
}

inline constexpr PoissonRatio operator*(const double number, const PoissonRatio& poisson_ratio) {
  return PoissonRatio{number * poisson_ratio.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::PoissonRatio> {
  inline size_t operator()(const PhQ::PoissonRatio& poisson_ratio) const {
    return hash<double>()(poisson_ratio.Value());
  }
};

}  // namespace std

#endif  // PHQ_POISSON_RATIO_HPP
