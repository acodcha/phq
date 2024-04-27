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

// Forward declaration for class ScalarHeatFlux.
class HeatFlux;

// Scalar heat flux component or magnitude of a heat flux vector. See also PhQ::HeatFlux.
class ScalarHeatFlux : public DimensionalScalar<Unit::EnergyFlux> {
public:
  // Default constructor. Constructs a scalar heat flux with an uninitialized value.
  ScalarHeatFlux() = default;

  // Constructor. Constructs a scalar heat flux with a given value expressed in a given energy flux
  // unit.
  ScalarHeatFlux(const double value, const Unit::EnergyFlux unit)
    : DimensionalScalar<Unit::EnergyFlux>(value, unit) {}

  // Constructor. Constructs a scalar heat flux from a given scalar thermal conductivity and scalar
  // temperature gradient using Fourier's law of heat conduction. Since heat flows opposite the
  // temperature gradient, the resulting scalar heat flux is negative.
  constexpr ScalarHeatFlux(const ScalarThermalConductivity& scalar_thermal_conductivity,
                           const ScalarTemperatureGradient& scalar_temperature_gradient)
    : ScalarHeatFlux(-scalar_thermal_conductivity.Value() * scalar_temperature_gradient.Value()) {}

  // Destructor. Destroys this scalar heat flux.
  ~ScalarHeatFlux() noexcept = default;

  // Copy constructor. Constructs a scalar heat flux by copying another one.
  constexpr ScalarHeatFlux(const ScalarHeatFlux& other) = default;

  // Move constructor. Constructs a scalar heat flux by moving another one.
  constexpr ScalarHeatFlux(ScalarHeatFlux&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar heat flux by copying another one.
  constexpr ScalarHeatFlux& operator=(const ScalarHeatFlux& other) = default;

  // Move assignment operator. Assigns this scalar heat flux by moving another one.
  constexpr ScalarHeatFlux& operator=(ScalarHeatFlux&& other) noexcept = default;

  // Statically creates a scalar heat flux of zero.
  static constexpr ScalarHeatFlux Zero() {
    return ScalarHeatFlux{0.0};
  }

  // Statically creates a scalar heat flux with a given value expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr ScalarHeatFlux Create(const double value) {
    return ScalarHeatFlux{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  constexpr ScalarHeatFlux operator+(const ScalarHeatFlux& scalar_heat_flux) const {
    return ScalarHeatFlux{value + scalar_heat_flux.value};
  }

  constexpr ScalarHeatFlux operator-(const ScalarHeatFlux& scalar_heat_flux) const {
    return ScalarHeatFlux{value - scalar_heat_flux.value};
  }

  constexpr ScalarHeatFlux operator*(const double number) const {
    return ScalarHeatFlux{value * number};
  }

  constexpr HeatFlux operator*(const Direction& direction) const;

  constexpr ScalarHeatFlux operator/(const double number) const {
    return ScalarHeatFlux{value / number};
  }

  constexpr double operator/(const ScalarHeatFlux& scalar_heat_flux) const noexcept {
    return value / scalar_heat_flux.value;
  }

  constexpr void operator+=(const ScalarHeatFlux& scalar_heat_flux) noexcept {
    value += scalar_heat_flux.value;
  }

  constexpr void operator-=(const ScalarHeatFlux& scalar_heat_flux) noexcept {
    value -= scalar_heat_flux.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar heat flux with a given value expressed in the standard energy
  // flux unit.
  explicit constexpr ScalarHeatFlux(const double value)
    : DimensionalScalar<Unit::EnergyFlux>(value) {}

  friend class HeatFlux;
};

inline constexpr bool operator==(const ScalarHeatFlux& left, const ScalarHeatFlux& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ScalarHeatFlux& left, const ScalarHeatFlux& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ScalarHeatFlux& left, const ScalarHeatFlux& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ScalarHeatFlux& left, const ScalarHeatFlux& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ScalarHeatFlux& left, const ScalarHeatFlux& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ScalarHeatFlux& left, const ScalarHeatFlux& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ScalarHeatFlux& scalar_heat_flux) {
  stream << scalar_heat_flux.Print();
  return stream;
}

inline constexpr ScalarHeatFlux operator*(
    const double number, const ScalarHeatFlux& scalar_heat_flux) {
  return scalar_heat_flux * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarHeatFlux> {
  inline size_t operator()(const PhQ::ScalarHeatFlux& scalar_heat_flux) const {
    return hash<double>()(scalar_heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_FLUX_SCALAR_HPP
