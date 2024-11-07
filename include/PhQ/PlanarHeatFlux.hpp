// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
template <typename NumericType = double>
class PlanarHeatFlux : public DimensionalPlanarVector<Unit::EnergyFlux, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar heat flux vector with an uninitialized value.
  PlanarHeatFlux() = default;

  /// \brief Constructor. Constructs a planar heat flux vector with a given value expressed in a
  /// given energy flux unit.
  PlanarHeatFlux(const PlanarVector<NumericType>& value, const Unit::EnergyFlux unit)
    : DimensionalPlanarVector<Unit::EnergyFlux, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given set of scalar heat flux
  /// components.
  PlanarHeatFlux(const ScalarHeatFlux<NumericType>& x, const ScalarHeatFlux<NumericType>& y)
    : PlanarHeatFlux<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given scalar heat flux
  /// magnitude and planar direction.
  constexpr PlanarHeatFlux(const ScalarHeatFlux<NumericType>& scalar_heat_flux,
                           const PlanarDirection<NumericType>& planar_direction)
    : PlanarHeatFlux<NumericType>(scalar_heat_flux.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given heat flux vector by
  /// projecting the heat flux vector onto the XY plane.
  explicit constexpr PlanarHeatFlux(const HeatFlux<NumericType>& heat_flux);

  /// \brief Constructor. Constructs a planar heat flux vector from a given scalar thermal
  /// conductivity and planar temperature gradient vector using Fourier's law of heat conduction.
  /// Since heat flows opposite the temperature gradient, the resulting heat flux direction is
  /// opposite the temperature gradient direction.
  constexpr PlanarHeatFlux(
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient)
    : PlanarHeatFlux<NumericType>(
          -scalar_thermal_conductivity.Value() * planar_temperature_gradient.Value()) {}

  /// \brief Constructor. Constructs a planar heat flux vector from a given thermal conductivity
  /// tensor and planar temperature gradient vector using Fourier's law of heat conduction. Since
  /// heat flows opposite the temperature gradient, the resulting heat flux direction is opposite
  /// the temperature gradient direction.
  constexpr PlanarHeatFlux(
      const ThermalConductivity<NumericType>& thermal_conductivity,
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient)
    : PlanarHeatFlux<NumericType>(PlanarVector<NumericType>{Vector<NumericType>{
        -1.0 * thermal_conductivity.Value() * planar_temperature_gradient.Value()}}) {}

  /// \brief Destructor. Destroys this planar heat flux vector.
  ~PlanarHeatFlux() noexcept = default;

  /// \brief Copy constructor. Constructs a planar heat flux vector by copying another one.
  constexpr PlanarHeatFlux(const PlanarHeatFlux<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar heat flux vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarHeatFlux(const PlanarHeatFlux<OtherNumericType>& other)
    : PlanarHeatFlux(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar heat flux vector by moving another one.
  constexpr PlanarHeatFlux(PlanarHeatFlux<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar heat flux vector by copying another one.
  constexpr PlanarHeatFlux<NumericType>& operator=(
      const PlanarHeatFlux<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar heat flux vector by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarHeatFlux<NumericType>& operator=(const PlanarHeatFlux<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar heat flux vector by moving another one.
  constexpr PlanarHeatFlux<NumericType>& operator=(
      PlanarHeatFlux<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar heat flux vector of zero.
  [[nodiscard]] static constexpr PlanarHeatFlux<NumericType> Zero() {
    return PlanarHeatFlux<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar heat flux vector from the given x and y Cartesian
  /// components expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  [[nodiscard]] static constexpr PlanarHeatFlux<NumericType> Create(
      const NumericType x, const NumericType y) {
    return PlanarHeatFlux<NumericType>{
      ConvertStatically<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
          PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar heat flux vector from the given x and y Cartesian
  /// components expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  [[nodiscard]] static constexpr PlanarHeatFlux<NumericType> Create(
      const std::array<NumericType, 2>& x_y) {
    return PlanarHeatFlux<NumericType>{
      ConvertStatically<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
          PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar heat flux vector with a given value expressed in a given
  /// energy flux unit.
  template <Unit::EnergyFlux Unit>
  [[nodiscard]] static constexpr PlanarHeatFlux<NumericType> Create(
      const PlanarVector<NumericType>& value) {
    return PlanarHeatFlux<NumericType>{
      ConvertStatically<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<NumericType> x() const noexcept {
    return ScalarHeatFlux<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<NumericType> y() const noexcept {
    return ScalarHeatFlux<NumericType>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar heat flux vector.
  [[nodiscard]] ScalarHeatFlux<NumericType> Magnitude() const {
    return ScalarHeatFlux<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar heat flux vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar heat flux vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarHeatFlux<NumericType>& planar_heat_flux) const {
    return PhQ::Angle<NumericType>{*this, planar_heat_flux};
  }

  constexpr PlanarHeatFlux<NumericType> operator+(
      const PlanarHeatFlux<NumericType>& planar_heat_flux) const {
    return PlanarHeatFlux<NumericType>{this->value + planar_heat_flux.value};
  }

  constexpr PlanarHeatFlux<NumericType> operator-(
      const PlanarHeatFlux<NumericType>& planar_heat_flux) const {
    return PlanarHeatFlux<NumericType>{this->value - planar_heat_flux.value};
  }

  constexpr PlanarHeatFlux<NumericType> operator*(const NumericType number) const {
    return PlanarHeatFlux<NumericType>{this->value * number};
  }

  constexpr PlanarHeatFlux<NumericType> operator/(const NumericType number) const {
    return PlanarHeatFlux<NumericType>{this->value / number};
  }

  constexpr void operator+=(const PlanarHeatFlux<NumericType>& planar_heat_flux) noexcept {
    this->value += planar_heat_flux.value;
  }

  constexpr void operator-=(const PlanarHeatFlux<NumericType>& planar_heat_flux) noexcept {
    this->value -= planar_heat_flux.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar heat flux vector with a given value expressed in the
  /// standard energy flux unit.
  explicit constexpr PlanarHeatFlux(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::EnergyFlux, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarHeatFlux<NumericType>& left, const PlanarHeatFlux<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarHeatFlux<NumericType>& left, const PlanarHeatFlux<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarHeatFlux<NumericType>& left, const PlanarHeatFlux<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarHeatFlux<NumericType>& left, const PlanarHeatFlux<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarHeatFlux<NumericType>& left, const PlanarHeatFlux<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarHeatFlux<NumericType>& left, const PlanarHeatFlux<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarHeatFlux<NumericType>& planar_heat_flux) {
  stream << planar_heat_flux.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarHeatFlux<NumericType> operator*(
    const NumericType number, const PlanarHeatFlux<NumericType>& planar_heat_flux) {
  return planar_heat_flux * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarHeatFlux<NumericType>& planar_heat_flux)
  : PlanarDirection<NumericType>(planar_heat_flux.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarHeatFlux<NumericType>& planar_heat_flux_1,
                                 const PlanarHeatFlux<NumericType>& planar_heat_flux_2)
  : Angle<NumericType>(planar_heat_flux_1.Value(), planar_heat_flux_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarHeatFlux<NumericType> PlanarDirection<NumericType>::operator*(
    const ScalarHeatFlux<NumericType>& scalar_heat_flux) const {
  return PlanarHeatFlux<NumericType>{scalar_heat_flux, *this};
}

template <typename NumericType>
inline constexpr PlanarHeatFlux<NumericType> ScalarHeatFlux<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarHeatFlux<NumericType>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarHeatFlux<NumericType>> {
  inline size_t operator()(const PhQ::PlanarHeatFlux<NumericType>& planar_heat_flux) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_HEAT_FLUX_HPP
