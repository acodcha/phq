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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_HPP

#include "HeatFluxMagnitude.hpp"
#include "TemperatureGradient.hpp"
#include "ThermalConductivity.hpp"

namespace PhQ {

// Heat flux vector.
class HeatFlux : public DimensionalVectorQuantity<Unit::EnergyFlux> {
public:
  // Default constructor. Constructs a heat flux with an uninitialized value.
  HeatFlux() = default;

  // Constructor. Constructs a heat flux with a given value expressed in a given
  // energy flux unit.
  HeatFlux(const Value::Vector& value, const Unit::EnergyFlux unit)
    : DimensionalVectorQuantity<Unit::EnergyFlux>(value, unit) {}

  // Constructor. Constructs a heat flux from a given heat flux magnitude and
  // direction.
  constexpr HeatFlux(
      const HeatFluxMagnitude& heat_flux_magnitude, const Direction& direction)
    : HeatFlux(heat_flux_magnitude.Value() * direction.Value()) {}

  // Constructor. Constructs a heat flux from a given thermal conductivity
  // scalar and temperature gradient using Fourier's law of heat conduction.
  // Since heat flows opposite the temperature gradient, the resulting heat flux
  // direction is opposite the temperature gradient direction.
  constexpr HeatFlux(
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const TemperatureGradient& temperature_gradient)
    : HeatFlux(
        -thermal_conductivity_scalar.Value() * temperature_gradient.Value()) {}

  // Constructor. Constructs a heat flux from a given thermal conductivity and
  // temperature gradient using Fourier's law of heat conduction. Since heat
  // flows opposite the temperature gradient, the resulting heat flux direction
  // is opposite the temperature gradient direction.
  constexpr HeatFlux(const ThermalConductivity& thermal_conductivity,
                     const TemperatureGradient& temperature_gradient)
    : HeatFlux(
        -1.0 * thermal_conductivity.Value() * temperature_gradient.Value()) {}

  // Destructor. Destroys this heat flux.
  ~HeatFlux() noexcept = default;

  // Copy constructor. Constructs a heat flux by copying another one.
  constexpr HeatFlux(const HeatFlux& other) = default;

  // Move constructor. Constructs a heat flux by moving another one.
  constexpr HeatFlux(HeatFlux&& other) noexcept = default;

  // Copy assignment operator. Assigns this heat flux by copying another one.
  constexpr HeatFlux& operator=(const HeatFlux& other) = default;

  // Move assignment operator. Assigns this heat flux by moving another one.
  constexpr HeatFlux& operator=(HeatFlux&& other) noexcept = default;

  // Statically creates a heat flux of zero.
  static constexpr HeatFlux Zero() {
    return HeatFlux{Value::Vector::Zero()};
  }

  // Statically creates a heat flux with a given value expressed in a given
  // energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux Create(const Value::Vector& value) {
    return HeatFlux{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
            value)};
  }

  // Returns the magnitude of this heat flux.
  HeatFluxMagnitude Magnitude() const {
    return {*this};
  }

  // Returns the angle between this heat flux and another one.
  PhQ::Angle Angle(const HeatFlux& heat_flux) const {
    return {*this, heat_flux};
  }

  constexpr HeatFlux operator+(const HeatFlux& heat_flux) const {
    return HeatFlux{value_ + heat_flux.value_};
  }

  constexpr HeatFlux operator-(const HeatFlux& heat_flux) const {
    return HeatFlux{value_ - heat_flux.value_};
  }

  constexpr HeatFlux operator*(const double number) const {
    return HeatFlux{value_ * number};
  }

  constexpr HeatFlux operator/(const double number) const {
    return HeatFlux{value_ / number};
  }

  constexpr void operator+=(const HeatFlux& heat_flux) noexcept {
    value_ += heat_flux.value_;
  }

  constexpr void operator-=(const HeatFlux& heat_flux) noexcept {
    value_ -= heat_flux.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a heat flux with a given value expressed in the
  // standard energy flux unit.
  explicit constexpr HeatFlux(const Value::Vector& value)
    : DimensionalVectorQuantity<Unit::EnergyFlux>(value) {}
};

inline constexpr bool operator==(
    const HeatFlux& left, const HeatFlux& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const HeatFlux& left, const HeatFlux& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const HeatFlux& left, const HeatFlux& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const HeatFlux& left, const HeatFlux& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const HeatFlux& left, const HeatFlux& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const HeatFlux& left, const HeatFlux& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const HeatFlux& heat_flux) {
  stream << heat_flux.Print();
  return stream;
}

inline constexpr HeatFlux operator*(
    const double number, const HeatFlux& heat_flux) {
  return heat_flux * number;
}

inline Direction::Direction(const HeatFlux& heat_flux)
  : Direction(heat_flux.Value()) {}

inline Angle::Angle(const HeatFlux& heat_flux_1, const HeatFlux& heat_flux_2)
  : Angle(heat_flux_1.Value(), heat_flux_2.Value()) {}

inline HeatFluxMagnitude::HeatFluxMagnitude(const HeatFlux& heat_flux)
  : HeatFluxMagnitude(heat_flux.Value().Magnitude()) {}

inline constexpr HeatFlux Direction::operator*(
    const HeatFluxMagnitude& heat_flux_magnitude) const {
  return {heat_flux_magnitude, *this};
}

inline constexpr HeatFlux HeatFluxMagnitude::operator*(
    const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::HeatFlux> {
  inline size_t operator()(const PhQ::HeatFlux& heat_flux) const {
    return hash<PhQ::Value::Vector>()(heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_HPP
