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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "TemperatureGradientScalar.hpp"
#include "ThermalConductivityScalar.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

// Forward declaration for class HeatFluxScalar.
class HeatFlux;

// Scalar heat flux component or magnitude of a heat flux vector.
class HeatFluxScalar : public DimensionalScalar<Unit::EnergyFlux> {
public:
  // Default constructor. Constructs a scalar heat flux with an uninitialized value.
  HeatFluxScalar() = default;

  // Constructor. Constructs a scalar heat flux with a given value expressed in a given energy flux
  // unit.
  HeatFluxScalar(const double value, const Unit::EnergyFlux unit)
    : DimensionalScalar<Unit::EnergyFlux>(value, unit) {}

  // Constructor. Constructs a scalar heat flux from a given scalar thermal conductivity and scalar
  // temperature gradient using Fourier's law of heat conduction. Since heat flows opposite the
  // temperature gradient, the resulting scalar heat flux is negative.
  constexpr HeatFluxScalar(const ThermalConductivityScalar& thermal_conductivity_scalar,
                           const TemperatureGradientScalar& temperature_gradient_scalar)
    : HeatFluxScalar(-thermal_conductivity_scalar.Value() * temperature_gradient_scalar.Value()) {}

  // Constructor. Constructs a scalar heat flux from the magnitude of a given heat flux vector.
  explicit HeatFluxScalar(const HeatFlux& heat_flux);

  // Destructor. Destroys this scalar heat flux.
  ~HeatFluxScalar() noexcept = default;

  // Copy constructor. Constructs a scalar heat flux by copying another one.
  constexpr HeatFluxScalar(const HeatFluxScalar& other) = default;

  // Move constructor. Constructs a scalar heat flux by moving another one.
  constexpr HeatFluxScalar(HeatFluxScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar heat flux by copying another one.
  constexpr HeatFluxScalar& operator=(const HeatFluxScalar& other) = default;

  // Move assignment operator. Assigns this scalar heat flux by moving another one.
  constexpr HeatFluxScalar& operator=(HeatFluxScalar&& other) noexcept = default;

  // Statically creates a scalar heat flux of zero.
  static constexpr HeatFluxScalar Zero() {
    return HeatFluxScalar{0.0};
  }

  // Statically creates a scalar heat flux with a given value expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFluxScalar Create(const double value) {
    return HeatFluxScalar{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  constexpr HeatFluxScalar operator+(const HeatFluxScalar& heat_flux_scalar) const {
    return HeatFluxScalar{value_ + heat_flux_scalar.value_};
  }

  constexpr HeatFluxScalar operator-(const HeatFluxScalar& heat_flux_scalar) const {
    return HeatFluxScalar{value_ - heat_flux_scalar.value_};
  }

  constexpr HeatFluxScalar operator*(const double number) const {
    return HeatFluxScalar{value_ * number};
  }

  constexpr HeatFlux operator*(const Direction& direction) const;

  constexpr HeatFluxScalar operator/(const double number) const {
    return HeatFluxScalar{value_ / number};
  }

  constexpr double operator/(const HeatFluxScalar& heat_flux_scalar) const noexcept {
    return value_ / heat_flux_scalar.value_;
  }

  constexpr void operator+=(const HeatFluxScalar& heat_flux_scalar) noexcept {
    value_ += heat_flux_scalar.value_;
  }

  constexpr void operator-=(const HeatFluxScalar& heat_flux_scalar) noexcept {
    value_ -= heat_flux_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar heat flux with a given value expressed in the standard energy
  // flux unit.
  explicit constexpr HeatFluxScalar(const double value)
    : DimensionalScalar<Unit::EnergyFlux>(value) {}
};

inline constexpr bool operator==(const HeatFluxScalar& left, const HeatFluxScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const HeatFluxScalar& left, const HeatFluxScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const HeatFluxScalar& left, const HeatFluxScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const HeatFluxScalar& left, const HeatFluxScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const HeatFluxScalar& left, const HeatFluxScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const HeatFluxScalar& left, const HeatFluxScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const HeatFluxScalar& heat_flux_scalar) {
  stream << heat_flux_scalar.Print();
  return stream;
}

inline constexpr HeatFluxScalar operator*(
    const double number, const HeatFluxScalar& heat_flux_scalar) {
  return heat_flux_scalar * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::HeatFluxScalar> {
  inline size_t operator()(const PhQ::HeatFluxScalar& heat_flux_scalar) const {
    return hash<double>()(heat_flux_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_SCALAR_HPP
