// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_PLANAR_HEAT_FLUX_HPP
#define PHQ_PLANAR_HEAT_FLUX_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarTemperatureGradient.hpp"
#include "PlanarVector.hpp"
#include "ScalarHeatFlux.hpp"
#include "ScalarThermalConductivity.hpp"
#include "ThermalConductivity.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

/// \brief Two-dimensional Euclidean heat flux vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. For a three-dimensional Euclidean heat flux vector, see
/// PhQ::HeatFlux. For scalar heat flux components or for the magnitude of a heat flux vector, see
/// PhQ::ScalarHeatFlux.
template <typename Number = double>
class PlanarHeatFlux : public DimensionalPlanarVector<Unit::EnergyFlux, Number> {
public:
  /// \brief Default constructor. Constructs a planar heat flux vector with an uninitialized value.
  PlanarHeatFlux() = default;

  /// \brief Constructor. Constructs a planar heat flux vector with a given value expressed in a
  /// given energy flux unit.
  PlanarHeatFlux(const PlanarVector<Number>& value, const Unit::EnergyFlux unit)
    : DimensionalPlanarVector<Unit::EnergyFlux, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given set of scalar heat flux
  /// components.
  PlanarHeatFlux(const ScalarHeatFlux<Number>& x, const ScalarHeatFlux<Number>& y)
    : PlanarHeatFlux<Number>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given scalar heat flux
  /// magnitude and planar direction.
  constexpr PlanarHeatFlux(const ScalarHeatFlux<Number>& scalar_heat_flux,
                           const PlanarDirection<Number>& planar_direction)
    : PlanarHeatFlux<Number>(scalar_heat_flux.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given heat flux vector by
  /// projecting the heat flux vector onto the XY plane.
  explicit constexpr PlanarHeatFlux(const HeatFlux<Number>& heat_flux);

  /// \brief Constructor. Constructs a planar heat flux vector from a given scalar thermal
  /// conductivity and planar temperature gradient vector using Fourier's law of heat conduction.
  /// Since heat flows opposite the temperature gradient, the resulting heat flux direction is
  /// opposite the temperature gradient direction.
  constexpr PlanarHeatFlux(const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
                           const PlanarTemperatureGradient<Number>& planar_temperature_gradient)
    : PlanarHeatFlux<Number>(
        -scalar_thermal_conductivity.Value() * planar_temperature_gradient.Value()) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given thermal conductivity
  /// tensor and planar temperature gradient vector using Fourier's law of heat conduction. Since
  /// heat flows opposite the temperature gradient, the resulting heat flux direction is opposite
  /// the temperature gradient direction.
  constexpr PlanarHeatFlux(const ThermalConductivity<Number>& thermal_conductivity,
                           const PlanarTemperatureGradient<Number>& planar_temperature_gradient)
    : PlanarHeatFlux<Number>(PlanarVector<Number>{Vector<Number>{
        -1.0 * thermal_conductivity.Value() * planar_temperature_gradient.Value()}}) {}

  /// \brief Destructor. Destroys this planar heat flux vector.
  ~PlanarHeatFlux() noexcept = default;

  /// \brief Copy constructor. Constructs a planar heat flux vector by copying another one.
  constexpr PlanarHeatFlux(const PlanarHeatFlux<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar heat flux vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarHeatFlux(const PlanarHeatFlux<OtherNumber>& other)
    : PlanarHeatFlux(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar heat flux vector by moving another one.
  constexpr PlanarHeatFlux(PlanarHeatFlux<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar heat flux vector by copying another one.
  constexpr PlanarHeatFlux<Number>& operator=(const PlanarHeatFlux<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar heat flux vector by copying another one.
  template <typename OtherNumber>
  constexpr PlanarHeatFlux<Number>& operator=(const PlanarHeatFlux<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar heat flux vector by moving another one.
  constexpr PlanarHeatFlux<Number>& operator=(PlanarHeatFlux<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar heat flux vector of zero.
  static constexpr PlanarHeatFlux<Number> Zero() {
    return PlanarHeatFlux<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar heat flux vector from the given x and y Cartesian
  /// components expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr PlanarHeatFlux<Number> Create(const Number x, const Number y) {
    return PlanarHeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
            PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar heat flux vector from the given x and y Cartesian
  /// components expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr PlanarHeatFlux<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarHeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
            PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar heat flux vector with a given value expressed in a given
  /// energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr PlanarHeatFlux<Number> Create(const PlanarVector<Number>& value) {
    return PlanarHeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> x() const noexcept {
    return ScalarHeatFlux<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> y() const noexcept {
    return ScalarHeatFlux<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar heat flux vector.
  [[nodiscard]] ScalarHeatFlux<Number> Magnitude() const {
    return ScalarHeatFlux<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar heat flux vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar heat flux vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarHeatFlux<Number>& planar_heat_flux) const {
    return PhQ::Angle<Number>{*this, planar_heat_flux};
  }

  constexpr PlanarHeatFlux<Number> operator+(const PlanarHeatFlux<Number>& planar_heat_flux) const {
    return PlanarHeatFlux<Number>{this->value + planar_heat_flux.value};
  }

  constexpr PlanarHeatFlux<Number> operator-(const PlanarHeatFlux<Number>& planar_heat_flux) const {
    return PlanarHeatFlux<Number>{this->value - planar_heat_flux.value};
  }

  constexpr PlanarHeatFlux<Number> operator*(const Number number) const {
    return PlanarHeatFlux<Number>{this->value * number};
  }

  constexpr PlanarHeatFlux<Number> operator/(const Number number) const {
    return PlanarHeatFlux<Number>{this->value / number};
  }

  constexpr void operator+=(const PlanarHeatFlux<Number>& planar_heat_flux) noexcept {
    this->value += planar_heat_flux.value;
  }

  constexpr void operator-=(const PlanarHeatFlux<Number>& planar_heat_flux) noexcept {
    this->value -= planar_heat_flux.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar heat flux vector with a given value expressed in the
  /// standard energy flux unit.
  explicit constexpr PlanarHeatFlux(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::EnergyFlux, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarHeatFlux<Number>& left, const PlanarHeatFlux<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarHeatFlux<Number>& left, const PlanarHeatFlux<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarHeatFlux<Number>& left, const PlanarHeatFlux<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarHeatFlux<Number>& left, const PlanarHeatFlux<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarHeatFlux<Number>& left, const PlanarHeatFlux<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarHeatFlux<Number>& left, const PlanarHeatFlux<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarHeatFlux<Number>& planar_heat_flux) {
  stream << planar_heat_flux.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarHeatFlux<Number> operator*(
    const Number number, const PlanarHeatFlux<Number>& planar_heat_flux) {
  return planar_heat_flux * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(const PlanarHeatFlux<Number>& planar_heat_flux)
  : PlanarDirection<Number>(planar_heat_flux.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarHeatFlux<Number>& planar_heat_flux_1,
                            const PlanarHeatFlux<Number>& planar_heat_flux_2)
  : Angle<Number>(planar_heat_flux_1.Value(), planar_heat_flux_2.Value()) {}

template <typename Number>
inline constexpr PlanarHeatFlux<Number> PlanarDirection<Number>::operator*(
    const ScalarHeatFlux<Number>& scalar_heat_flux) const {
  return PlanarHeatFlux<Number>{scalar_heat_flux, *this};
}

template <typename Number>
inline constexpr PlanarHeatFlux<Number> ScalarHeatFlux<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarHeatFlux<Number>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarHeatFlux<Number>> {
  inline size_t operator()(const PhQ::PlanarHeatFlux<Number>& planar_heat_flux) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_HEAT_FLUX_HPP
