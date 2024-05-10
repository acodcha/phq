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

#ifndef PHQ_HEAT_FLUX_HPP
#define PHQ_HEAT_FLUX_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "ScalarHeatFlux.hpp"
#include "ScalarThermalConductivity.hpp"
#include "TemperatureGradient.hpp"
#include "ThermalConductivity.hpp"
#include "Unit/EnergyFlux.hpp"
#include "Vector.hpp"

namespace PhQ {

// Heat flux vector. See also PhQ::ScalarHeatFlux.
template <typename Number = double>
class HeatFlux : public DimensionalVector<Unit::EnergyFlux, Number> {
public:
  // Default constructor. Constructs a heat flux with an uninitialized value.
  HeatFlux() = default;

  // Constructor. Constructs a heat flux vector with a given value expressed in a given energy flux
  // unit.
  HeatFlux(const Vector<Number>& value, const Unit::EnergyFlux unit)
    : DimensionalVector<Unit::EnergyFlux, Number>(value, unit) {}

  // Constructor. Constructs a heat flux vector from a given scalar heat flux magnitude and
  // direction.
  constexpr HeatFlux(
      const ScalarHeatFlux<Number>& scalar_heat_flux, const Direction<Number>& direction)
    : HeatFlux<Number>(scalar_heat_flux.Value() * direction.Value()) {}

  // Constructor. Constructs a heat flux vector from a given scalar thermal conductivity and
  // temperature gradient vector using Fourier's law of heat conduction. Since heat flows opposite
  // the temperature gradient, the resulting heat flux direction is opposite the temperature
  // gradient direction.
  constexpr HeatFlux(const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
                     const TemperatureGradient<Number>& temperature_gradient)
    : HeatFlux<Number>(-scalar_thermal_conductivity.Value() * temperature_gradient.Value()) {}

  // Constructor. Constructs a heat flux vector from a given thermal conductivity tensor and
  // temperature gradient vector using Fourier's law of heat conduction. Since heat flows opposite
  // the temperature gradient, the resulting heat flux direction is opposite the temperature
  // gradient direction.
  constexpr HeatFlux(const ThermalConductivity<Number>& thermal_conductivity,
                     const TemperatureGradient<Number>& temperature_gradient)
    : HeatFlux<Number>(-1.0 * thermal_conductivity.Value() * temperature_gradient.Value()) {}

  // Destructor. Destroys this heat flux vector.
  ~HeatFlux() noexcept = default;

  // Copy constructor. Constructs a heat flux vector by copying another one.
  constexpr HeatFlux(const HeatFlux<Number>& other) = default;

  // Copy constructor. Constructs a heat flux vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr HeatFlux(const HeatFlux<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a heat flux vector by moving another one.
  constexpr HeatFlux(HeatFlux<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this heat flux vector by copying another one.
  constexpr HeatFlux<Number>& operator=(const HeatFlux<Number>& other) = default;

  // Copy assignment operator. Assigns this heat flux vector by copying another one.
  template <typename OtherNumber>
  constexpr HeatFlux<Number>& operator=(const HeatFlux<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this heat flux vector by moving another one.
  constexpr HeatFlux<Number>& operator=(HeatFlux<Number>&& other) noexcept = default;

  // Statically creates a heat flux vector of zero.
  static constexpr HeatFlux<Number> Zero() {
    return HeatFlux<Number>{Vector<Number>::Zero()};
  }

  // Statically creates a heat flux vector from the given x, y, and z Cartesian components expressed
  // in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<Number> Create(const Number x, const Number y, const Number z) {
    return HeatFlux<Number>{StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
        Vector<Number>{x, y, z})};
  }

  // Statically creates a heat flux vector from the given x, y, and z Cartesian components expressed
  // in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<Number> Create(const std::array<Number, 3>& x_y_z) {
    return HeatFlux<Number>{StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
        Vector<Number>{x_y_z})};
  }

  // Statically creates a heat flux vector with a given value expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<Number> Create(const Vector<Number>& value) {
    return HeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  // Returns the x Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> x() const noexcept {
    return ScalarHeatFlux<Number>{value.x()};
  }

  // Returns the y Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> y() const noexcept {
    return ScalarHeatFlux<Number>{value.y()};
  }

  // Returns the z Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> z() const noexcept {
    return ScalarHeatFlux<Number>{value.z()};
  }

  // Returns the magnitude of this heat flux vector.
  [[nodiscard]] ScalarHeatFlux<Number> Magnitude() const {
    return ScalarHeatFlux<Number>{value.Magnitude()};
  }

  // Returns the direction of this heat flux vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return value.Direction();
  }

  // Returns the angle between this heat flux vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const HeatFlux<Number>& heat_flux) const {
    return PhQ::Angle<Number>{*this, heat_flux};
  }

  constexpr HeatFlux<Number> operator+(const HeatFlux<Number>& heat_flux) const {
    return HeatFlux<Number>{value + heat_flux.value};
  }

  constexpr HeatFlux<Number> operator-(const HeatFlux<Number>& heat_flux) const {
    return HeatFlux<Number>{value - heat_flux.value};
  }

  constexpr HeatFlux<Number> operator*(const Number number) const {
    return HeatFlux<Number>{value * number};
  }

  constexpr HeatFlux<Number> operator/(const Number number) const {
    return HeatFlux<Number>{value / number};
  }

  constexpr void operator+=(const HeatFlux<Number>& heat_flux) noexcept {
    value += heat_flux.value;
  }

  constexpr void operator-=(const HeatFlux<Number>& heat_flux) noexcept {
    value -= heat_flux.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a heat flux vector with a given value expressed in the standard energy
  // flux unit.
  explicit constexpr HeatFlux(const Vector<Number>& value)
    : DimensionalVector<Unit::EnergyFlux, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const HeatFlux<Number>& left, const HeatFlux<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const HeatFlux<Number>& left, const HeatFlux<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const HeatFlux<Number>& left, const HeatFlux<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const HeatFlux<Number>& left, const HeatFlux<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const HeatFlux<Number>& left, const HeatFlux<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const HeatFlux<Number>& left, const HeatFlux<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const HeatFlux<Number>& heat_flux) {
  stream << heat_flux.Print();
  return stream;
}

template <typename Number>
inline constexpr HeatFlux<Number> operator*(
    const Number number, const HeatFlux<Number>& heat_flux) {
  return heat_flux * number;
}

template <typename Number>
inline Direction<Number>::Direction(const HeatFlux<Number>& heat_flux)
  : Direction<Number>(heat_flux.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const HeatFlux<Number>& heat_flux_1, const HeatFlux<Number>& heat_flux_2)
  : Angle<Number>(heat_flux_1.Value(), heat_flux_2.Value()) {}

template <typename Number>
inline constexpr HeatFlux<Number> Direction<Number>::operator*(
    const ScalarHeatFlux<Number>& scalar_heat_flux) const {
  return HeatFlux<Number>{scalar_heat_flux, *this};
}

template <typename Number>
inline constexpr HeatFlux<Number> ScalarHeatFlux<Number>::operator*(
    const Direction<Number>& direction) const {
  return HeatFlux<Number>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::HeatFlux<Number>> {
  inline size_t operator()(const PhQ::HeatFlux<Number>& heat_flux) const {
    return hash<PhQ::Vector<Number>>()(heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_FLUX_HPP
