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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_HPP

#include "Quantity/DimensionalSymmetricDyad.hpp"
#include "StressScalar.hpp"
#include "Traction.hpp"

namespace PhQ {

// Cauchy stress dyadic tensor.
class Stress : public DimensionalSymmetricDyadQuantity<Unit::Pressure> {
public:
  constexpr Stress() noexcept
    : DimensionalSymmetricDyadQuantity<Unit::Pressure>() {}

  Stress(const Value::SymmetricDyad& value, const Unit::Pressure unit) noexcept
    : DimensionalSymmetricDyadQuantity<Unit::Pressure>(value, unit) {}

  constexpr Stress(const StaticPressure& static_pressure) noexcept
    : Stress({-1.0 * static_pressure.Value(), 0.0, 0.0,
              -1.0 * static_pressure.Value(), 0.0,
              -1.0 * static_pressure.Value()}) {}

  static constexpr Stress Zero() noexcept {
    return Stress{Value::SymmetricDyad::Zero()};
  }

  template<Unit::Pressure Unit>
  static constexpr Stress Create(const Value::SymmetricDyad& value) noexcept {
    return Stress{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr PhQ::Traction Traction(const Direction& direction) const noexcept {
    return {*this, direction};
  }

  constexpr StressScalar VonMises() const noexcept {
    return StressScalar{
        0.5
        * (std::pow(value_.xx() - value_.yy(), 2)
           + std::pow(value_.yy() - value_.zz(), 2)
           + std::pow(value_.zz() - value_.xx(), 2)
           + 6.0
                 * (std::pow(value_.xy(), 2) + std::pow(value_.xz(), 2)
                    + std::pow(value_.yz(), 2)))};
  }

  constexpr Stress operator+(const Stress& stress) const noexcept {
    return Stress{value_ + stress.value_};
  }

  constexpr Stress operator-(const Stress& stress) const noexcept {
    return Stress{value_ - stress.value_};
  }

  constexpr Stress operator*(const double number) const noexcept {
    return Stress{value_ * number};
  }

  constexpr Stress operator/(const double number) const noexcept {
    return Stress{value_ / number};
  }

  constexpr void operator+=(const Stress& stress) noexcept {
    value_ += stress.value_;
  }

  constexpr void operator-=(const Stress& stress) noexcept {
    value_ -= stress.value_;
  }

  constexpr void operator*=(const double number) noexcept { value_ *= number; }

  constexpr void operator/=(const double number) noexcept { value_ /= number; }

private:
  explicit constexpr Stress(const Value::SymmetricDyad& value) noexcept
    : DimensionalSymmetricDyadQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const Stress& left, const Stress& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Stress& left, const Stress& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Stress& left, const Stress& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Stress& left, const Stress& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Stress& left, const Stress& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Stress& left, const Stress& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Stress& stress) noexcept {
  stream << stress.Print();
  return stream;
}

inline constexpr Stress operator*(
    const double number, const Stress& stress) noexcept {
  return stress * number;
}

inline constexpr Traction::Traction(
    const Stress& stress, const Direction& direction) noexcept
  : Traction({stress.Value() * direction}) {}

inline constexpr Stress StaticPressure::Stress() const noexcept {
  return {*this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::Stress> {
  inline size_t operator()(const PhQ::Stress& stress) const {
    return hash<PhQ::Value::SymmetricDyad>()(stress.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_HPP
