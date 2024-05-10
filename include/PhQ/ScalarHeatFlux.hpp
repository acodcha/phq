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

#ifndef PHQ_HEAT_FLUX_SCALAR_HPP
#define PHQ_HEAT_FLUX_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "ScalarTemperatureGradient.hpp"
#include "ScalarThermalConductivity.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarHeatFlux.
template <typename Number>
class HeatFlux;

// Scalar heat flux component or magnitude of a heat flux vector. See also PhQ::HeatFlux.
template <typename Number = double>
class ScalarHeatFlux : public DimensionalScalar<Unit::EnergyFlux, Number> {
public:
  // Default constructor. Constructs a scalar heat flux with an uninitialized value.
  ScalarHeatFlux() = default;

  // Constructor. Constructs a scalar heat flux with a given value expressed in a given energy flux
  // unit.
  ScalarHeatFlux(const Number value, const Unit::EnergyFlux unit)
    : DimensionalScalar<Unit::EnergyFlux, Number>(value, unit) {}

  // Constructor. Constructs a scalar heat flux from a given scalar thermal conductivity and scalar
  // temperature gradient using Fourier's law of heat conduction. Since heat flows opposite the
  // temperature gradient, the resulting scalar heat flux is negative.
  constexpr ScalarHeatFlux(const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
                           const ScalarTemperatureGradient<Number>& scalar_temperature_gradient)
    : ScalarHeatFlux<Number>(
        -scalar_thermal_conductivity.Value() * scalar_temperature_gradient.Value()) {}

  // Destructor. Destroys this scalar heat flux.
  ~ScalarHeatFlux() noexcept = default;

  // Copy constructor. Constructs a scalar heat flux by copying another one.
  constexpr ScalarHeatFlux(const ScalarHeatFlux<Number>& other) = default;

  // Copy constructor. Constructs a scalar heat flux by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarHeatFlux(const ScalarHeatFlux<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar heat flux by moving another one.
  constexpr ScalarHeatFlux(ScalarHeatFlux<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar heat flux by copying another one.
  constexpr ScalarHeatFlux<Number>& operator=(const ScalarHeatFlux<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar heat flux by copying another one.
  template <typename OtherNumber>
  constexpr ScalarHeatFlux<Number>& operator=(const ScalarHeatFlux<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar heat flux by moving another one.
  constexpr ScalarHeatFlux<Number>& operator=(ScalarHeatFlux<Number>&& other) noexcept = default;

  // Statically creates a scalar heat flux of zero.
  static constexpr ScalarHeatFlux<Number> Zero() {
    return ScalarHeatFlux<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar heat flux with a given value expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr ScalarHeatFlux<Number> Create(const Number value) {
    return ScalarHeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  constexpr ScalarHeatFlux<Number> operator+(const ScalarHeatFlux<Number>& scalar_heat_flux) const {
    return ScalarHeatFlux<Number>{value + scalar_heat_flux.value};
  }

  constexpr ScalarHeatFlux<Number> operator-(const ScalarHeatFlux<Number>& scalar_heat_flux) const {
    return ScalarHeatFlux<Number>{value - scalar_heat_flux.value};
  }

  constexpr ScalarHeatFlux<Number> operator*(const Number number) const {
    return ScalarHeatFlux<Number>{value * number};
  }

  constexpr HeatFlux<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarHeatFlux<Number> operator/(const Number number) const {
    return ScalarHeatFlux<Number>{value / number};
  }

  constexpr Number operator/(const ScalarHeatFlux<Number>& scalar_heat_flux) const noexcept {
    return value / scalar_heat_flux.value;
  }

  constexpr void operator+=(const ScalarHeatFlux<Number>& scalar_heat_flux) noexcept {
    value += scalar_heat_flux.value;
  }

  constexpr void operator-=(const ScalarHeatFlux<Number>& scalar_heat_flux) noexcept {
    value -= scalar_heat_flux.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar heat flux with a given value expressed in the standard energy
  // flux unit.
  explicit constexpr ScalarHeatFlux(const Number value)
    : DimensionalScalar<Unit::EnergyFlux, Number>(value) {}

  template <typename OtherNumber>
  friend class HeatFlux;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarHeatFlux<Number>& scalar_heat_flux) {
  stream << scalar_heat_flux.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarHeatFlux<Number> operator*(
    const Number number, const ScalarHeatFlux<Number>& scalar_heat_flux) {
  return scalar_heat_flux * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarHeatFlux<Number>> {
  inline size_t operator()(const PhQ::ScalarHeatFlux<Number>& scalar_heat_flux) const {
    return hash<Number>()(scalar_heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_FLUX_SCALAR_HPP
