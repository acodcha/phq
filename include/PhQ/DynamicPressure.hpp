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

#ifndef PHQ_DYNAMIC_PRESSURE_HPP
#define PHQ_DYNAMIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::DynamicPressure.
template <typename Number>
class DynamicKinematicPressure;

// Dynamic pressure, which is the additional pressure arising from a flowing fluid's kinetic energy.
// Dynamic pressure can be thought of as a flowing fluid's kinetic energy per unit volume.
template <typename Number = double>
class DynamicPressure : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a dynamic pressure with an uninitialized value.
  DynamicPressure() = default;

  // Constructor. Constructs a dynamic pressure with a given value expressed in a given pressure
  // unit.
  DynamicPressure(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Constructor. Constructs a dynamic pressure from a given mass density and speed using the
  // definition of dynamic pressure.
  constexpr DynamicPressure(const MassDensity<Number>& mass_density, const Speed<Number>& speed)
    : DynamicPressure<Number>(0.5 * mass_density.Value() * std::pow(speed.Value(), 2)) {}

  // Constructor. Constructs a dynamic pressure from a given total pressure and static pressure
  // using the definition of total pressure.
  constexpr DynamicPressure(
      const TotalPressure<Number>& total_pressure, const StaticPressure<Number>& static_pressure);

  // Constructor. Constructs a dynamic pressure from a given mass density and dynamic kinematic
  // pressure using the definition of dynamic kinematic pressure.
  constexpr DynamicPressure(const MassDensity<Number>& mass_density,
                            const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure);

  // Destructor. Destroys this dynamic pressure.
  ~DynamicPressure() noexcept = default;

  // Copy constructor. Constructs a dynamic pressure by copying another one.
  constexpr DynamicPressure(const DynamicPressure<Number>& other) = default;

  // Copy constructor. Constructs a dynamic pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr DynamicPressure(const DynamicPressure<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a dynamic pressure by moving another one.
  constexpr DynamicPressure(DynamicPressure<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this dynamic pressure by copying another one.
  constexpr DynamicPressure<Number>& operator=(const DynamicPressure<Number>& other) = default;

  // Copy assignment operator. Assigns this dynamic pressure by copying another one.
  template <typename OtherNumber>
  constexpr DynamicPressure<Number>& operator=(const DynamicPressure<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this dynamic pressure by moving another one.
  constexpr DynamicPressure<Number>& operator=(DynamicPressure<Number>&& other) noexcept = default;

  // Statically creates a dynamic pressure of zero.
  static constexpr DynamicPressure<Number> Zero() {
    return DynamicPressure<Number>{static_cast<Number>(0)};
  }

  // Statically creates a dynamic pressure with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr DynamicPressure<Number> Create(const Number value) {
    return DynamicPressure<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr DynamicPressure<Number> operator+(
      const DynamicPressure<Number>& dynamic_pressure) const {
    return DynamicPressure<Number>{value + dynamic_pressure.value};
  }

  constexpr TotalPressure<Number> operator+(const StaticPressure<Number>& static_pressure) const;

  constexpr DynamicPressure<Number> operator-(
      const DynamicPressure<Number>& dynamic_pressure) const {
    return DynamicPressure<Number>{value - dynamic_pressure.value};
  }

  constexpr DynamicPressure<Number> operator*(const Number number) const {
    return DynamicPressure<Number>{value * number};
  }

  constexpr DynamicPressure<Number> operator/(const Number number) const {
    return DynamicPressure<Number>{value / number};
  }

  constexpr Number operator/(const DynamicPressure<Number>& dynamic_pressure) const noexcept {
    return value / dynamic_pressure.value;
  }

  constexpr DynamicKinematicPressure<Number> operator/(
      const MassDensity<Number>& mass_density) const;

  constexpr void operator+=(const DynamicPressure<Number>& dynamic_pressure) noexcept {
    value += dynamic_pressure.value;
  }

  constexpr void operator-=(const DynamicPressure<Number>& dynamic_pressure) noexcept {
    value -= dynamic_pressure.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a dynamic pressure with a given value expressed in the standard
  // pressure unit.
  explicit constexpr DynamicPressure(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const DynamicPressure<Number>& dynamic_pressure) {
  stream << dynamic_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr DynamicPressure<Number> operator*(
    const Number number, const DynamicPressure<Number>& dynamic_pressure) {
  return dynamic_pressure * number;
}

template <typename Number>
inline constexpr MassDensity<Number>::MassDensity(
    const DynamicPressure<Number>& dynamic_pressure, const Speed<Number>& speed)
  : MassDensity<Number>(2.0 * dynamic_pressure.Value() / (speed.Value() * speed.Value())) {}

template <typename Number>
inline Speed<Number>::Speed(
    const DynamicPressure<Number>& dynamic_pressure, const MassDensity<Number>& mass_density)
  : Speed<Number>(std::sqrt(2.0 * dynamic_pressure.Value() / mass_density.Value())) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::DynamicPressure<Number>> {
  inline size_t operator()(const PhQ::DynamicPressure<Number>& dynamic_pressure) const {
    return hash<Number>()(dynamic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_PRESSURE_HPP
