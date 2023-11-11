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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRESS_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class StressScalar.
class Stress;

// Stress scalar. Represents either a component of the Cauchy stress tensor or a related quantity
// such as principal stress or Von Mises stress.
class StressScalar : public DimensionalScalar<Unit::Pressure> {
public:
  // Default constructor. Constructs a stress scalar with an uninitialized value.
  StressScalar() = default;

  // Constructor. Constructs a stress scalar with a given value expressed in a given pressure unit.
  StressScalar(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this stress scalar.
  ~StressScalar() noexcept = default;

  // Copy constructor. Constructs a stress scalar by copying another one.
  constexpr StressScalar(const StressScalar& other) = default;

  // Move constructor. Constructs a stress scalar by moving another one.
  constexpr StressScalar(StressScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this stress scalar by copying another one.
  constexpr StressScalar& operator=(const StressScalar& other) = default;

  // Move assignment operator. Assigns this stress scalar by moving another one.
  constexpr StressScalar& operator=(StressScalar&& other) noexcept = default;

  // Statically creates a stress scalar of zero.
  static constexpr StressScalar Zero() {
    return StressScalar{0.0};
  }

  // Statically creates a stress scalar with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr StressScalar Create(const double value) {
    return StressScalar{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
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
  // Constructor. Constructs a stress scalar with a given value expressed in the standard pressure
  // unit.
  explicit constexpr StressScalar(const double value) : DimensionalScalar<Unit::Pressure>(value) {}

  friend class Stress;
};

inline constexpr bool operator==(const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const StressScalar& left, const StressScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const StressScalar& stress_scalar) {
  stream << stress_scalar.Print();
  return stream;
}

inline constexpr StressScalar operator*(const double number, const StressScalar& stress_scalar) {
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
