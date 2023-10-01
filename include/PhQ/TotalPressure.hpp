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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_PRESSURE_HPP

#include "DynamicPressure.hpp"

namespace PhQ {

// Forward declaration for class TotalPressure.
class TotalKinematicPressure;

// Total pressure. Total pressure is the sum of static pressure and dynamic
// pressure.
class TotalPressure : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  // Default constructor. Constructs a total pressure with an uninitialized
  // value.
  TotalPressure() = default;

  // Constructor. Constructs a total pressure with a given value expressed in a
  // given pressure unit.
  TotalPressure(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a total pressure from a given dynamic pressure and
  // static pressure using the definition of total pressure.
  constexpr TotalPressure(const DynamicPressure& dynamic_pressure,
                          const StaticPressure& static_pressure)
    : TotalPressure(dynamic_pressure.Value() + static_pressure.Value()) {}

  // Constructor. Constructs a total pressure from a given total kinematic
  // pressure and mass density using the definition of total kinematic pressure.
  constexpr TotalPressure(
      const TotalKinematicPressure& total_kinematic_pressure,
      const MassDensity& mass_density);

  // Destructor. Destroys this total pressure.
  ~TotalPressure() noexcept = default;

  // Copy constructor. Constructs a total pressure by copying another one.
  constexpr TotalPressure(const TotalPressure& other) = default;

  // Move constructor. Constructs a total pressure by moving another one.
  constexpr TotalPressure(TotalPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this total pressure by copying another
  // one.
  constexpr TotalPressure& operator=(const TotalPressure& other) = default;

  // Move assignment operator. Assigns this total pressure by moving another
  // one.
  constexpr TotalPressure& operator=(TotalPressure&& other) noexcept = default;

  // Statically creates a total pressure of zero.
  static constexpr TotalPressure Zero() {
    return TotalPressure{0.0};
  }

  // Statically creates a total pressure with a given value expressed in a given
  // pressure unit.
  template <Unit::Pressure Unit>
  static constexpr TotalPressure Create(const double value) {
    return TotalPressure{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr TotalPressure operator+(const TotalPressure& total_pressure) const {
    return TotalPressure{value_ + total_pressure.value_};
  }

  constexpr TotalPressure operator-(const TotalPressure& total_pressure) const {
    return TotalPressure{value_ - total_pressure.value_};
  }

  constexpr DynamicPressure operator-(
      const StaticPressure& static_pressure) const {
    return {*this, static_pressure};
  }

  constexpr StaticPressure operator-(
      const DynamicPressure& dynamic_pressure) const {
    return {*this, dynamic_pressure};
  }

  constexpr TotalPressure operator*(const double number) const {
    return TotalPressure{value_ * number};
  }

  constexpr TotalPressure operator/(const double number) const {
    return TotalPressure{value_ / number};
  }

  constexpr double operator/(
      const TotalPressure& total_pressure) const noexcept {
    return value_ / total_pressure.value_;
  }

  constexpr void operator+=(const TotalPressure& total_pressure) noexcept {
    value_ += total_pressure.value_;
  }

  constexpr void operator-=(const TotalPressure& total_pressure) noexcept {
    value_ -= total_pressure.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a total pressure with a given value expressed in
  // the standard pressure unit.
  explicit constexpr TotalPressure(const double value)
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TotalPressure& left, const TotalPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TotalPressure& total_pressure) {
  stream << total_pressure.Print();
  return stream;
}

inline constexpr TotalPressure operator*(
    const double number, const TotalPressure& total_pressure) {
  return total_pressure * number;
}

inline constexpr StaticPressure::StaticPressure(
    const TotalPressure& total_pressure,
    const DynamicPressure& dynamic_pressure)
  : StaticPressure(total_pressure.Value() - dynamic_pressure.Value()) {}

inline constexpr DynamicPressure::DynamicPressure(
    const TotalPressure& total_pressure, const StaticPressure& static_pressure)
  : DynamicPressure(total_pressure.Value() - static_pressure.Value()) {}

inline constexpr TotalPressure StaticPressure::operator+(
    const DynamicPressure& dynamic_pressure) const {
  return {dynamic_pressure, *this};
}

inline constexpr TotalPressure DynamicPressure::operator+(
    const StaticPressure& static_pressure) const {
  return {*this, static_pressure};
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_PRESSURE_HPP
