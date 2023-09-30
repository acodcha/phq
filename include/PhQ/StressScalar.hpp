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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_SCALAR_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class StressScalar.
class Stress;

// Stress scalar. Represents either a component of the Cauchy stress tensor or a
// related quantity such as principal stress or Von Mises stress.
class StressScalar : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  StressScalar() = default;

  StressScalar(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  static constexpr StressScalar Zero() {
    return StressScalar{0.0};
  }

  template <Unit::Pressure Unit>
  static constexpr StressScalar Create(const double value) {
    return StressScalar{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr StressScalar operator+(const StressScalar& stress_scalar) const {
    return StressScalar{value_ + stress_scalar.value_};
  }

  constexpr StressScalar operator-(const StressScalar& stress_scalar) const {
    return StressScalar{value_ - stress_scalar.value_};
  }

  constexpr StressScalar operator*(const double number) const {
    return StressScalar{value_ * number};
  }

  constexpr StressScalar operator/(const double number) const {
    return StressScalar{value_ / number};
  }

  constexpr double operator/(const StressScalar& stress_scalar) const noexcept {
    return value_ / stress_scalar.value_;
  }

  constexpr void operator+=(const StressScalar& stress_scalar) noexcept {
    value_ += stress_scalar.value_;
  }

  constexpr void operator-=(const StressScalar& stress_scalar) noexcept {
    value_ -= stress_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr StressScalar(const double value)
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend Stress;
};

inline constexpr bool operator==(
    const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const StressScalar& stress_scalar) {
  stream << stress_scalar.Print();
  return stream;
}

inline constexpr StressScalar operator*(
    const double number, const StressScalar& stress_scalar) {
  return stress_scalar * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StressScalar> {
  inline size_t operator()(const PhQ::StressScalar& stress_scalar) const {
    return hash<double>()(stress_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_SCALAR_HPP
