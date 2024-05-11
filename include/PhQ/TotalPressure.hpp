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

#ifndef PHQ_TOTAL_PRESSURE_HPP
#define PHQ_TOTAL_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "DynamicPressure.hpp"
#include "MassDensity.hpp"
#include "StaticPressure.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::TotalPressure.
template <typename Number>
class TotalKinematicPressure;

// Total pressure, which is the sum of static pressure and dynamic pressure.
template <typename Number = double>
class TotalPressure : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a total pressure with an uninitialized value.
  TotalPressure() = default;

  // Constructor. Constructs a total pressure with a given value expressed in a given pressure unit.
  TotalPressure(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Constructor. Constructs a total pressure from a given static pressure and dynamic pressure
  // using the definition of total pressure.
  constexpr TotalPressure(const StaticPressure<Number>& static_pressure,
                          const DynamicPressure<Number>& dynamic_pressure)
    : TotalPressure<Number>(static_pressure.Value() + dynamic_pressure.Value()) {}

  // Constructor. Constructs a total pressure from a given mass density and total kinematic pressure
  // using the definition of total kinematic pressure.
  constexpr TotalPressure(const MassDensity<Number>& mass_density,
                          const TotalKinematicPressure<Number>& total_kinematic_pressure);

  // Destructor. Destroys this total pressure.
  ~TotalPressure() noexcept = default;

  // Copy constructor. Constructs a total pressure by copying another one.
  constexpr TotalPressure(const TotalPressure<Number>& other) = default;

  // Copy constructor. Constructs a total pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr TotalPressure(const TotalPressure<OtherNumber>& other)
    : TotalPressure(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a total pressure by moving another one.
  constexpr TotalPressure(TotalPressure<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this total pressure by copying another one.
  constexpr TotalPressure<Number>& operator=(const TotalPressure<Number>& other) = default;

  // Copy assignment operator. Assigns this total pressure by copying another one.
  template <typename OtherNumber>
  constexpr TotalPressure<Number>& operator=(const TotalPressure<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this total pressure by moving another one.
  constexpr TotalPressure<Number>& operator=(TotalPressure<Number>&& other) noexcept = default;

  // Statically creates a total pressure of zero.
  static constexpr TotalPressure<Number> Zero() {
    return TotalPressure<Number>{static_cast<Number>(0)};
  }

  // Statically creates a total pressure with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr TotalPressure<Number> Create(const Number value) {
    return TotalPressure<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr TotalPressure<Number> operator+(const TotalPressure<Number>& total_pressure) const {
    return TotalPressure<Number>{this->value + total_pressure.value};
  }

  constexpr TotalPressure<Number> operator-(const TotalPressure<Number>& total_pressure) const {
    return TotalPressure<Number>{this->value - total_pressure.value};
  }

  constexpr DynamicPressure<Number> operator-(const StaticPressure<Number>& static_pressure) const {
    return DynamicPressure<Number>{*this, static_pressure};
  }

  constexpr StaticPressure<Number> operator-(
      const DynamicPressure<Number>& dynamic_pressure) const {
    return StaticPressure<Number>{*this, dynamic_pressure};
  }

  constexpr TotalPressure<Number> operator*(const Number number) const {
    return TotalPressure<Number>{this->value * number};
  }

  constexpr TotalPressure<Number> operator/(const Number number) const {
    return TotalPressure<Number>{this->value / number};
  }

  constexpr Number operator/(const TotalPressure<Number>& total_pressure) const noexcept {
    return this->value / total_pressure.value;
  }

  constexpr TotalKinematicPressure<Number> operator/(const MassDensity<Number>& mass_density) const;

  constexpr void operator+=(const TotalPressure<Number>& total_pressure) noexcept {
    this->value += total_pressure.value;
  }

  constexpr void operator-=(const TotalPressure<Number>& total_pressure) noexcept {
    this->value -= total_pressure.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a total pressure with a given value expressed in the standard pressure
  // unit.
  explicit constexpr TotalPressure(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const TotalPressure<Number>& left, const TotalPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const TotalPressure<Number>& left, const TotalPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const TotalPressure<Number>& left, const TotalPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const TotalPressure<Number>& left, const TotalPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const TotalPressure<Number>& left, const TotalPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const TotalPressure<Number>& left, const TotalPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const TotalPressure<Number>& total_pressure) {
  stream << total_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr TotalPressure<Number> operator*(
    const Number number, const TotalPressure<Number>& total_pressure) {
  return total_pressure * number;
}

template <typename Number>
inline constexpr StaticPressure<Number>::StaticPressure(
    const TotalPressure<Number>& total_pressure, const DynamicPressure<Number>& dynamic_pressure)
  : StaticPressure<Number>(total_pressure.Value() - dynamic_pressure.Value()) {}

template <typename Number>
inline constexpr DynamicPressure<Number>::DynamicPressure(
    const TotalPressure<Number>& total_pressure, const StaticPressure<Number>& static_pressure)
  : DynamicPressure<Number>(total_pressure.Value() - static_pressure.Value()) {}

template <typename Number>
inline constexpr TotalPressure<Number> StaticPressure<Number>::operator+(
    const DynamicPressure<Number>& dynamic_pressure) const {
  return TotalPressure<Number>{*this, dynamic_pressure};
}

template <typename Number>
inline constexpr TotalPressure<Number> DynamicPressure<Number>::operator+(
    const StaticPressure<Number>& static_pressure) const {
  return TotalPressure<Number>{static_pressure, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::TotalPressure<Number>> {
  inline size_t operator()(const PhQ::TotalPressure<Number>& total_pressure) const {
    return hash<Number>()(total_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_TOTAL_PRESSURE_HPP
