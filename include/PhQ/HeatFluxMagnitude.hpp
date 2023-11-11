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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_MAGNITUDE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "TemperatureGradientMagnitude.hpp"
#include "ThermalConductivityScalar.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

// Forward declaration for class HeatFluxMagnitude.
class HeatFlux;

// Heat flux scalar. Magnitude of the heat flux vector.
class HeatFluxMagnitude : public DimensionalScalar<Unit::EnergyFlux> {
public:
  // Default constructor. Constructs a heat flux magnitude with an uninitialized value.
  HeatFluxMagnitude() = default;

  // Constructor. Constructs a heat flux magnitude with a given value expressed in a given energy
  // flux unit.
  HeatFluxMagnitude(const double value, const Unit::EnergyFlux unit)
    : DimensionalScalar<Unit::EnergyFlux>(value, unit) {}

  // Constructor. Constructs a heat flux magnitude from a given thermal conductivity scalar and
  // temperature gradient magnitude using Fourier's law of heat conduction. Since heat flows
  // opposite the temperature gradient, the resulting heat flux magnitude is negative.
  constexpr HeatFluxMagnitude(const ThermalConductivityScalar& thermal_conductivity_scalar,
                              const TemperatureGradientMagnitude& temperature_gradient_magnitude)
    : HeatFluxMagnitude(
        -thermal_conductivity_scalar.Value() * temperature_gradient_magnitude.Value()) {}

  // Constructor. Constructs a heat flux magnitude from a given heat flux vector.
  explicit HeatFluxMagnitude(const HeatFlux& heat_flux);

  // Destructor. Destroys this heat flux magnitude.
  ~HeatFluxMagnitude() noexcept = default;

  // Copy constructor. Constructs a heat flux magnitude by copying another one.
  constexpr HeatFluxMagnitude(const HeatFluxMagnitude& other) = default;

  // Move constructor. Constructs a heat flux magnitude by moving another one.
  constexpr HeatFluxMagnitude(HeatFluxMagnitude&& other) noexcept = default;

  // Copy assignment operator. Assigns this heat flux magnitude by copying another one.
  constexpr HeatFluxMagnitude& operator=(const HeatFluxMagnitude& other) = default;

  // Move assignment operator. Assigns this heat flux magnitude by moving another one.
  constexpr HeatFluxMagnitude& operator=(HeatFluxMagnitude&& other) noexcept = default;

  // Statically creates a heat flux magnitude of zero.
  static constexpr HeatFluxMagnitude Zero() {
    return HeatFluxMagnitude{0.0};
  }

  // Statically creates a heat flux magnitude with a given value expressed in a given energy flux
  // unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFluxMagnitude Create(const double value) {
    return HeatFluxMagnitude{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  constexpr HeatFluxMagnitude operator+(const HeatFluxMagnitude& heat_flux_magnitude) const {
    return HeatFluxMagnitude{value_ + heat_flux_magnitude.value_};
  }

  constexpr HeatFluxMagnitude operator-(const HeatFluxMagnitude& heat_flux_magnitude) const {
    return HeatFluxMagnitude{value_ - heat_flux_magnitude.value_};
  }

  constexpr HeatFluxMagnitude operator*(const double number) const {
    return HeatFluxMagnitude{value_ * number};
  }

  constexpr HeatFlux operator*(const Direction& direction) const;

  constexpr HeatFluxMagnitude operator/(const double number) const {
    return HeatFluxMagnitude{value_ / number};
  }

  constexpr double operator/(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ / heat_flux_magnitude.value_;
  }

  constexpr void operator+=(const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ += heat_flux_magnitude.value_;
  }

  constexpr void operator-=(const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ -= heat_flux_magnitude.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a heat flux magnitude with a given value expressed in the standard
  // energy flux unit.
  explicit constexpr HeatFluxMagnitude(const double value)
    : DimensionalScalar<Unit::EnergyFlux>(value) {}
};

inline constexpr bool operator==(
    const HeatFluxMagnitude& left, const HeatFluxMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const HeatFluxMagnitude& left, const HeatFluxMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const HeatFluxMagnitude& left, const HeatFluxMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const HeatFluxMagnitude& left, const HeatFluxMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const HeatFluxMagnitude& left, const HeatFluxMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const HeatFluxMagnitude& left, const HeatFluxMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const HeatFluxMagnitude& heat_flux_magnitude) {
  stream << heat_flux_magnitude.Print();
  return stream;
}

inline constexpr HeatFluxMagnitude operator*(
    const double number, const HeatFluxMagnitude& heat_flux_magnitude) {
  return heat_flux_magnitude * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::HeatFluxMagnitude> {
  inline size_t operator()(const PhQ::HeatFluxMagnitude& heat_flux_magnitude) const {
    return hash<double>()(heat_flux_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_MAGNITUDE_HPP
