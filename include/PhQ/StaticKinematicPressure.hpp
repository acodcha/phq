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

#ifndef PHQ_STATIC_KINEMATIC_PRESSURE_HPP
#define PHQ_STATIC_KINEMATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "StaticPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration for class PhQ::StaticKinematicPressure.
template <typename Number>
class DynamicKinematicPressure;

// Forward declaration for class PhQ::StaticKinematicPressure.
template <typename Number>
class TotalKinematicPressure;

// Static kinematic pressure, which is static pressure divided by mass density.
template <typename Number = double>
class StaticKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, Number> {
public:
  // Default constructor. Constructs a static kinematic pressure with an uninitialized value.
  StaticKinematicPressure() = default;

  // Constructor. Constructs a static kinematic pressure with a given value expressed in a given
  // specific energy unit.
  StaticKinematicPressure(const Number value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value, unit) {}

  // Constructor. Constructs a static kinematic pressure from a given total kinematic pressure and
  // dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr StaticKinematicPressure(
      const TotalKinematicPressure<Number>& total_kinematic_pressure,
      const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure);

  // Constructor. Constructs a static kinematic pressure from a given static pressure and mass
  // density using the definition of static kinematic pressure.
  constexpr StaticKinematicPressure(
      const StaticPressure<Number>& static_pressure, const MassDensity<Number>& mass_density)
    : StaticKinematicPressure<Number>(static_pressure.Value() / mass_density.Value()) {}

  // Destructor. Destroys this static kinematic pressure.
  ~StaticKinematicPressure() noexcept = default;

  // Copy constructor. Constructs a static kinematic pressure by copying another one.
  constexpr StaticKinematicPressure(const StaticKinematicPressure<Number>& other) = default;

  // Copy constructor. Constructs a static kinematic pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr StaticKinematicPressure(const StaticKinematicPressure<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure(StaticKinematicPressure<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this static kinematic pressure by copying another one.
  constexpr StaticKinematicPressure<Number>& operator=(
      const StaticKinematicPressure<Number>& other) = default;

  // Copy assignment operator. Assigns this static kinematic pressure by copying another one.
  template <typename OtherNumber>
  constexpr StaticKinematicPressure<Number>& operator=(
      const StaticKinematicPressure<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure<Number>& operator=(
      StaticKinematicPressure<Number>&& other) noexcept = default;

  // Statically creates a static kinematic pressure of zero.
  static constexpr StaticKinematicPressure<Number> Zero() {
    return StaticKinematicPressure<Number>{static_cast<Number>(0)};
  }

  // Statically creates a static kinematic pressure with a given value expressed in a given specific
  // energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr StaticKinematicPressure<Number> Create(const Number value) {
    return StaticKinematicPressure<Number>{
        StaticConvertCopy<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr StaticKinematicPressure<Number> operator+(
      const StaticKinematicPressure<Number>& other) const {
    return StaticKinematicPressure<Number>{value + other.value};
  }

  constexpr TotalKinematicPressure<Number> operator+(
      const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure) const;

  constexpr StaticKinematicPressure<Number> operator-(
      const StaticKinematicPressure<Number>& other) const {
    return StaticKinematicPressure<Number>{value - other.value};
  }

  constexpr StaticKinematicPressure<Number> operator*(const Number number) const {
    return StaticKinematicPressure<Number>{value * number};
  }

  constexpr StaticPressure<Number> operator*(const MassDensity<Number>& mass_density) const {
    return StaticPressure<Number>{mass_density, *this};
  }

  constexpr StaticKinematicPressure<Number> operator/(const Number number) const {
    return StaticKinematicPressure<Number>{value / number};
  }

  constexpr Number operator/(const StaticKinematicPressure<Number>& other) const noexcept {
    return value / other.value;
  }

  constexpr void operator+=(const StaticKinematicPressure<Number>& other) noexcept {
    value += other.value;
  }

  constexpr void operator-=(const StaticKinematicPressure<Number>& other) noexcept {
    value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a static kinematic pressure with a given value expressed in the
  // standard specific energy unit.
  explicit constexpr StaticKinematicPressure(const Number value)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const StaticKinematicPressure<Number>& left,
                                const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const StaticKinematicPressure<Number>& left,
                                const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const StaticKinematicPressure<Number>& static_kinematic_pressure) {
  stream << static_kinematic_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr StaticKinematicPressure<Number> operator*(
    const Number number, const StaticKinematicPressure<Number>& static_kinematic_pressure) {
  return static_kinematic_pressure * number;
}

template <typename Number>
inline constexpr StaticPressure<Number>::StaticPressure(
    const MassDensity<Number>& mass_density,
    const StaticKinematicPressure<Number>& static_kinematic_pressure)
  : StaticPressure<Number>(mass_density.Value() * static_kinematic_pressure.Value()) {}

template <typename Number>
inline constexpr StaticKinematicPressure<Number> StaticPressure<Number>::operator/(
    const MassDensity<Number>& mass_density) const {
  return StaticKinematicPressure<Number>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::StaticKinematicPressure<Number>> {
  inline size_t operator()(
      const PhQ::StaticKinematicPressure<Number>& static_kinematic_pressure) const {
    return hash<Number>()(static_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_STATIC_KINEMATIC_PRESSURE_HPP
