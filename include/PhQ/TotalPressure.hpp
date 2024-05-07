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

// Forward declaration for class TotalPressure.
class TotalKinematicPressure;

// Total pressure, which is the sum of static pressure and dynamic pressure.
class TotalPressure : public DimensionalScalar<Unit::Pressure, double> {
public:
  // Default constructor. Constructs a total pressure with an uninitialized value.
  TotalPressure() = default;

  // Constructor. Constructs a total pressure with a given value expressed in a given pressure unit.
  TotalPressure(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a total pressure from a given static pressure and dynamic pressure
  // using the definition of total pressure.
  constexpr TotalPressure(
      const StaticPressure& static_pressure, const DynamicPressure& dynamic_pressure)
    : TotalPressure(static_pressure.Value() + dynamic_pressure.Value()) {}

  // Constructor. Constructs a total pressure from a given mass density and total kinematic pressure
  // using the definition of total kinematic pressure.
  constexpr TotalPressure(
      const MassDensity& mass_density, const TotalKinematicPressure& total_kinematic_pressure);

  // Destructor. Destroys this total pressure.
  ~TotalPressure() noexcept = default;

  // Copy constructor. Constructs a total pressure by copying another one.
  constexpr TotalPressure(const TotalPressure& other) = default;

  // Move constructor. Constructs a total pressure by moving another one.
  constexpr TotalPressure(TotalPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this total pressure by copying another one.
  constexpr TotalPressure& operator=(const TotalPressure& other) = default;

  // Move assignment operator. Assigns this total pressure by moving another one.
  constexpr TotalPressure& operator=(TotalPressure&& other) noexcept = default;

  // Statically creates a total pressure of zero.
  static constexpr TotalPressure Zero() {
    return TotalPressure{0.0};
  }

  // Statically creates a total pressure with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr TotalPressure Create(const double value) {
    return TotalPressure{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr TotalPressure operator+(const TotalPressure& total_pressure) const {
    return TotalPressure{value + total_pressure.value};
  }

  constexpr TotalPressure operator-(const TotalPressure& total_pressure) const {
    return TotalPressure{value - total_pressure.value};
  }

  constexpr DynamicPressure operator-(const StaticPressure& static_pressure) const {
    return {*this, static_pressure};
  }

  constexpr StaticPressure operator-(const DynamicPressure& dynamic_pressure) const {
    return {*this, dynamic_pressure};
  }

  constexpr TotalPressure operator*(const double number) const {
    return TotalPressure{value * number};
  }

  constexpr TotalPressure operator/(const double number) const {
    return TotalPressure{value / number};
  }

  constexpr double operator/(const TotalPressure& total_pressure) const noexcept {
    return value / total_pressure.value;
  }

  constexpr TotalKinematicPressure operator/(const MassDensity& mass_density) const;

  constexpr void operator+=(const TotalPressure& total_pressure) noexcept {
    value += total_pressure.value;
  }

  constexpr void operator-=(const TotalPressure& total_pressure) noexcept {
    value -= total_pressure.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a total pressure with a given value expressed in the standard pressure
  // unit.
  explicit constexpr TotalPressure(const double value) : DimensionalScalar<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const TotalPressure& total_pressure) {
  stream << total_pressure.Print();
  return stream;
}

inline constexpr TotalPressure operator*(const double number, const TotalPressure& total_pressure) {
  return total_pressure * number;
}

inline constexpr StaticPressure::StaticPressure(
    const TotalPressure& total_pressure, const DynamicPressure& dynamic_pressure)
  : StaticPressure(total_pressure.Value() - dynamic_pressure.Value()) {}

inline constexpr DynamicPressure::DynamicPressure(
    const TotalPressure& total_pressure, const StaticPressure& static_pressure)
  : DynamicPressure(total_pressure.Value() - static_pressure.Value()) {}

inline constexpr TotalPressure StaticPressure::operator+(
    const DynamicPressure& dynamic_pressure) const {
  return {*this, dynamic_pressure};
}

inline constexpr TotalPressure DynamicPressure::operator+(
    const StaticPressure& static_pressure) const {
  return {static_pressure, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TotalPressure> {
  inline size_t operator()(const PhQ::TotalPressure& total_pressure) const {
    return hash<double>()(total_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_TOTAL_PRESSURE_HPP
