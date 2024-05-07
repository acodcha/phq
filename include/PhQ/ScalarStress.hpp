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

#ifndef PHQ_STRESS_SCALAR_HPP
#define PHQ_STRESS_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class ScalarStress.
class Stress;

// Scalar component or resultant of a Cauchy stress tensor. See also PhQ::Stress.
class ScalarStress : public DimensionalScalar<Unit::Pressure, double> {
public:
  // Default constructor. Constructs a scalar stress with an uninitialized value.
  ScalarStress() = default;

  // Constructor. Constructs a scalar stress with a given value expressed in a given pressure unit.
  ScalarStress(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this scalar stress.
  ~ScalarStress() noexcept = default;

  // Copy constructor. Constructs a scalar stress by copying another one.
  constexpr ScalarStress(const ScalarStress& other) = default;

  // Move constructor. Constructs a scalar stress by moving another one.
  constexpr ScalarStress(ScalarStress&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar stress by copying another one.
  constexpr ScalarStress& operator=(const ScalarStress& other) = default;

  // Move assignment operator. Assigns this scalar stress by moving another one.
  constexpr ScalarStress& operator=(ScalarStress&& other) noexcept = default;

  // Statically creates a scalar stress of zero.
  static constexpr ScalarStress Zero() {
    return ScalarStress{0.0};
  }

  // Statically creates a scalar stress with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr ScalarStress Create(const double value) {
    return ScalarStress{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ScalarStress operator+(const ScalarStress& scalar_stress) const {
    return ScalarStress{value + scalar_stress.value};
  }

  constexpr ScalarStress operator-(const ScalarStress& scalar_stress) const {
    return ScalarStress{value - scalar_stress.value};
  }

  constexpr ScalarStress operator*(const double number) const {
    return ScalarStress{value * number};
  }

  constexpr ScalarStress operator/(const double number) const {
    return ScalarStress{value / number};
  }

  constexpr double operator/(const ScalarStress& scalar_stress) const noexcept {
    return value / scalar_stress.value;
  }

  constexpr void operator+=(const ScalarStress& scalar_stress) noexcept {
    value += scalar_stress.value;
  }

  constexpr void operator-=(const ScalarStress& scalar_stress) noexcept {
    value -= scalar_stress.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar stress with a given value expressed in the standard pressure
  // unit.
  explicit constexpr ScalarStress(const double value) : DimensionalScalar<Unit::Pressure>(value) {}

  friend class Stress;
};

inline constexpr bool operator==(const ScalarStress& left, const ScalarStress& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ScalarStress& left, const ScalarStress& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ScalarStress& left, const ScalarStress& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ScalarStress& left, const ScalarStress& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ScalarStress& left, const ScalarStress& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ScalarStress& left, const ScalarStress& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ScalarStress& scalar_stress) {
  stream << scalar_stress.Print();
  return stream;
}

inline constexpr ScalarStress operator*(const double number, const ScalarStress& scalar_stress) {
  return scalar_stress * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarStress> {
  inline size_t operator()(const PhQ::ScalarStress& scalar_stress) const {
    return hash<double>()(scalar_stress.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRESS_SCALAR_HPP
