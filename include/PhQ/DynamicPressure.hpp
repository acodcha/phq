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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declaration for class DynamicPressure.
class DynamicKinematicPressure;

// Dynamic pressure, which is the additional pressure arising from a flowing fluid's kinetic energy.
// Dynamic pressure can be thought of as a flowing fluid's kinetic energy per unit volume.
class DynamicPressure : public DimensionalScalar<Unit::Pressure> {
public:
  // Default constructor. Constructs a dynamic pressure with an uninitialized value.
  DynamicPressure() = default;

  // Constructor. Constructs a dynamic pressure with a given value expressed in a given pressure
  // unit.
  DynamicPressure(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a dynamic pressure from a given mass density and speed using the
  // definition of dynamic pressure.
  constexpr DynamicPressure(const MassDensity& mass_density, const Speed& speed)
    : DynamicPressure(0.5 * mass_density.Value() * std::pow(speed.Value(), 2)) {}

  // Constructor. Constructs a dynamic pressure from a given total pressure and static pressure
  // using the definition of total pressure.
  constexpr DynamicPressure(
      const TotalPressure& total_pressure, const StaticPressure& static_pressure);

  // Constructor. Constructs a dynamic pressure from a given mass density and dynamic kinematic
  // pressure using the definition of dynamic kinematic pressure.
  constexpr DynamicPressure(
      const MassDensity& mass_density, const DynamicKinematicPressure& dynamic_kinematic_pressure);

  // Destructor. Destroys this dynamic pressure.
  ~DynamicPressure() noexcept = default;

  // Copy constructor. Constructs a dynamic pressure by copying another one.
  constexpr DynamicPressure(const DynamicPressure& other) = default;

  // Move constructor. Constructs a dynamic pressure by moving another one.
  constexpr DynamicPressure(DynamicPressure&& other) noexcept = default;

  // Copy assignment operator. Assigns this dynamic pressure by copying another one.
  constexpr DynamicPressure& operator=(const DynamicPressure& other) = default;

  // Move assignment operator. Assigns this dynamic pressure by moving another one.
  constexpr DynamicPressure& operator=(DynamicPressure&& other) noexcept = default;

  // Statically creates a dynamic pressure of zero.
  static constexpr DynamicPressure Zero() {
    return DynamicPressure{0.0};
  }

  // Statically creates a dynamic pressure with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr DynamicPressure Create(const double value) {
    return DynamicPressure{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr DynamicPressure operator+(const DynamicPressure& dynamic_pressure) const {
    return DynamicPressure{value_ + dynamic_pressure.value_};
  }

  constexpr TotalPressure operator+(const StaticPressure& static_pressure) const;

  constexpr DynamicPressure operator-(const DynamicPressure& dynamic_pressure) const {
    return DynamicPressure{value_ - dynamic_pressure.value_};
  }

  constexpr DynamicPressure operator*(const double number) const {
    return DynamicPressure{value_ * number};
  }

  constexpr DynamicPressure operator/(const double number) const {
    return DynamicPressure{value_ / number};
  }

  constexpr double operator/(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ / dynamic_pressure.value_;
  }

  constexpr DynamicKinematicPressure operator/(const MassDensity& mass_density) const;

  constexpr void operator+=(const DynamicPressure& dynamic_pressure) noexcept {
    value_ += dynamic_pressure.value_;
  }

  constexpr void operator-=(const DynamicPressure& dynamic_pressure) noexcept {
    value_ -= dynamic_pressure.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a dynamic pressure with a given value expressed in the standard
  // pressure unit.
  explicit constexpr DynamicPressure(const double value)
    : DimensionalScalar<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const DynamicPressure& left, const DynamicPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const DynamicPressure& dynamic_pressure) {
  stream << dynamic_pressure.Print();
  return stream;
}

inline constexpr DynamicPressure operator*(
    const double number, const DynamicPressure& dynamic_pressure) {
  return dynamic_pressure * number;
}

inline constexpr MassDensity::MassDensity(
    const DynamicPressure& dynamic_pressure, const Speed& speed)
  : MassDensity(2.0 * dynamic_pressure.Value() / (speed.Value() * speed.Value())) {}

inline Speed::Speed(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density)
  : Speed(std::sqrt(2.0 * dynamic_pressure.Value() / mass_density.Value())) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DynamicPressure> {
  inline size_t operator()(const PhQ::DynamicPressure& dynamic_pressure) const {
    return hash<double>()(dynamic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_PRESSURE_HPP
