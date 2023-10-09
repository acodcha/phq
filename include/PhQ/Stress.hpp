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

#include "DimensionalSymmetricDyadQuantity.hpp"
#include "StressScalar.hpp"
#include "Traction.hpp"

namespace PhQ {

// Cauchy stress symmetric dyadic tensor.
class Stress : public DimensionalSymmetricDyadQuantity<Unit::Pressure> {
public:
  // Default constructor. Constructs a stress tensor with an uninitialized
  // value.
  Stress() = default;

  // Constructor. Constructs a stress tensor with a given value expressed in a
  // given pressure unit.
  Stress(const Value::SymmetricDyad& value, const Unit::Pressure unit)
    : DimensionalSymmetricDyadQuantity<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a stress tensor from a given static pressure using
  // the definition of stress due to pressure. Since pressure is compressive,
  // the negative of the static pressure contributes to the stress.
  constexpr Stress(const StaticPressure& static_pressure)
    : Stress({-1.0 * static_pressure.Value(), 0.0, 0.0,
              -1.0 * static_pressure.Value(), 0.0,
              -1.0 * static_pressure.Value()}) {}

  // Destructor. Destroys this stress tensor.
  ~Stress() noexcept = default;

  // Copy constructor. Constructs a stress tensor by copying another one.
  constexpr Stress(const Stress& other) = default;

  // Move constructor. Constructs a stress tensor by moving another one.
  constexpr Stress(Stress&& other) noexcept = default;

  // Copy assignment operator. Assigns this stress tensor by copying another
  // one.
  constexpr Stress& operator=(const Stress& other) = default;

  // Move assignment operator. Assigns this stress tensor by moving another one.
  constexpr Stress& operator=(Stress&& other) noexcept = default;

  // Statically creates a stress tensor of zero.
  static constexpr Stress Zero() {
    return Stress{Value::SymmetricDyad::Zero()};
  }

  // Statically creates a stress tensor with a given value expressed in a given
  // pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress Create(const Value::SymmetricDyad& value) {
    return Stress{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  // Creates a traction from this stress tensor using the definition of
  // traction.
  constexpr PhQ::Traction Traction(const Direction& direction) const {
    return {*this, direction};
  }

  // Computes the von Mises stress of this stress tensor using the von Mises
  // yield criterion.
  constexpr StressScalar VonMises() const {
    return StressScalar{std::sqrt(
        0.5
        * (std::pow(value_.xx() - value_.yy(), 2)
           + std::pow(value_.yy() - value_.zz(), 2)
           + std::pow(value_.zz() - value_.xx(), 2)
           + 6.0
                 * (std::pow(value_.xy(), 2) + std::pow(value_.xz(), 2)
                    + std::pow(value_.yz(), 2))))};
  }

  constexpr Stress operator+(const Stress& stress) const {
    return Stress{value_ + stress.value_};
  }

  constexpr Stress operator-(const Stress& stress) const {
    return Stress{value_ - stress.value_};
  }

  constexpr Stress operator*(const double number) const {
    return Stress{value_ * number};
  }

  constexpr Stress operator/(const double number) const {
    return Stress{value_ / number};
  }

  constexpr void operator+=(const Stress& stress) noexcept {
    value_ += stress.value_;
  }

  constexpr void operator-=(const Stress& stress) noexcept {
    value_ -= stress.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a stress tensor with a given value expressed in the
  // standard pressure unit.
  explicit constexpr Stress(const Value::SymmetricDyad& value)
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

inline std::ostream& operator<<(std::ostream& stream, const Stress& stress) {
  stream << stress.Print();
  return stream;
}

inline constexpr Stress operator*(const double number, const Stress& stress) {
  return stress * number;
}

inline constexpr Traction::Traction(
    const Stress& stress, const Direction& direction)
  : Traction({stress.Value() * direction}) {}

inline constexpr Stress StaticPressure::Stress() const {
  return {*this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Stress> {
  inline size_t operator()(const PhQ::Stress& stress) const {
    return hash<PhQ::Value::SymmetricDyad>()(stress.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_HPP
