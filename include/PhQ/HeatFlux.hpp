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

#ifndef PHQ_HEAT_FLUX_HPP
#define PHQ_HEAT_FLUX_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "PlanarHeatFlux.hpp"
#include "ScalarHeatFlux.hpp"
#include "ScalarThermalConductivity.hpp"
#include "TemperatureGradient.hpp"
#include "ThermalConductivity.hpp"
#include "Unit/EnergyFlux.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Three-dimensional Euclidean heat flux vector. Contains three components in Cartesian
/// coordinates: x, y, and z. For a two-dimensional Euclidean heat flux vector in the XY plane, see
/// PhQ::PlanarHeatFlux. For scalar heat flux components or for the magnitude of a heat flux vector,
/// see PhQ::ScalarHeatFlux.
template <typename NumericType = double>
class HeatFlux : public DimensionalVector<Unit::EnergyFlux, NumericType> {
public:
  /// \brief Default constructor. Constructs a heat flux vector with an uninitialized value.
  HeatFlux() = default;

  /// \brief Constructor. Constructs a heat flux vector with a given value expressed in a given
  /// energy flux unit.
  HeatFlux(const Vector<NumericType>& value, const Unit::EnergyFlux unit)
    : DimensionalVector<Unit::EnergyFlux, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a heat flux vector from a given set of scalar heat flux
  /// components.
  HeatFlux(const ScalarHeatFlux<NumericType>& x, const ScalarHeatFlux<NumericType>& y,
           const ScalarHeatFlux<NumericType>& z)
    : HeatFlux<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a heat flux vector from a given scalar heat flux magnitude and
  /// direction.
  constexpr HeatFlux(
      const ScalarHeatFlux<NumericType>& scalar_heat_flux, const Direction<NumericType>& direction)
    : HeatFlux<NumericType>(scalar_heat_flux.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a heat flux vector from a given planar heat flux vector in the
  /// XY plane. This heat flux vector's z-component is initialized to zero.
  explicit constexpr HeatFlux(const PlanarHeatFlux<NumericType>& planar_heat_flux)
    : HeatFlux<NumericType>(Vector<NumericType>{planar_heat_flux.Value()}) {}

  /// \brief Constructor. Constructs a heat flux vector from a given scalar thermal conductivity and
  /// temperature gradient vector using Fourier's law of heat conduction. Since heat flows opposite
  /// the temperature gradient, the resulting heat flux direction is opposite the temperature
  /// gradient direction.
  constexpr HeatFlux(const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
                     const TemperatureGradient<NumericType>& temperature_gradient)
    : HeatFlux<NumericType>(-scalar_thermal_conductivity.Value() * temperature_gradient.Value()) {}

  /// \brief Constructor. Constructs a heat flux vector from a given thermal conductivity tensor and
  /// temperature gradient vector using Fourier's law of heat conduction. Since heat flows opposite
  /// the temperature gradient, the resulting heat flux direction is opposite the temperature
  /// gradient direction.
  constexpr HeatFlux(const ThermalConductivity<NumericType>& thermal_conductivity,
                     const TemperatureGradient<NumericType>& temperature_gradient)
    : HeatFlux<NumericType>(-1.0 * thermal_conductivity.Value() * temperature_gradient.Value()) {}

  /// \brief Destructor. Destroys this heat flux vector.
  ~HeatFlux() noexcept = default;

  /// \brief Copy constructor. Constructs a heat flux vector by copying another one.
  constexpr HeatFlux(const HeatFlux<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a heat flux vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr HeatFlux(const HeatFlux<OtherNumericType>& other)
    : HeatFlux(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a heat flux vector by moving another one.
  constexpr HeatFlux(HeatFlux<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this heat flux vector by copying another one.
  constexpr HeatFlux<NumericType>& operator=(const HeatFlux<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this heat flux vector by copying another one.
  template <typename OtherNumericType>
  constexpr HeatFlux<NumericType>& operator=(const HeatFlux<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this heat flux vector by moving another one.
  constexpr HeatFlux<NumericType>& operator=(HeatFlux<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a heat flux vector of zero.
  static constexpr HeatFlux<NumericType> Zero() {
    return HeatFlux<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a heat flux vector from the given x, y, and z Cartesian components
  /// expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return HeatFlux<NumericType>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
            Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a heat flux vector from the given x, y, and z Cartesian components
  /// expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return HeatFlux<NumericType>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
            Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a heat flux vector with a given value expressed in a given energy
  /// flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<NumericType> Create(const Vector<NumericType>& value) {
    return HeatFlux<NumericType>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  /// \brief Returns the x Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<NumericType> x() const noexcept {
    return ScalarHeatFlux<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<NumericType> y() const noexcept {
    return ScalarHeatFlux<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<NumericType> z() const noexcept {
    return ScalarHeatFlux<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this heat flux vector.
  [[nodiscard]] ScalarHeatFlux<NumericType> Magnitude() const {
    return ScalarHeatFlux<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this heat flux vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this heat flux vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const HeatFlux<NumericType>& heat_flux) const {
    return PhQ::Angle<NumericType>{*this, heat_flux};
  }

  constexpr HeatFlux<NumericType> operator+(const HeatFlux<NumericType>& heat_flux) const {
    return HeatFlux<NumericType>{this->value + heat_flux.value};
  }

  constexpr HeatFlux<NumericType> operator-(const HeatFlux<NumericType>& heat_flux) const {
    return HeatFlux<NumericType>{this->value - heat_flux.value};
  }

  constexpr HeatFlux<NumericType> operator*(const NumericType number) const {
    return HeatFlux<NumericType>{this->value * number};
  }

  constexpr HeatFlux<NumericType> operator/(const NumericType number) const {
    return HeatFlux<NumericType>{this->value / number};
  }

  constexpr void operator+=(const HeatFlux<NumericType>& heat_flux) noexcept {
    this->value += heat_flux.value;
  }

  constexpr void operator-=(const HeatFlux<NumericType>& heat_flux) noexcept {
    this->value -= heat_flux.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a heat flux vector with a given value expressed in the standard
  /// energy flux unit.
  explicit constexpr HeatFlux(const Vector<NumericType>& value)
    : DimensionalVector<Unit::EnergyFlux, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const HeatFlux<NumericType>& left, const HeatFlux<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const HeatFlux<NumericType>& left, const HeatFlux<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const HeatFlux<NumericType>& left, const HeatFlux<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const HeatFlux<NumericType>& left, const HeatFlux<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const HeatFlux<NumericType>& left, const HeatFlux<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const HeatFlux<NumericType>& left, const HeatFlux<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const HeatFlux<NumericType>& heat_flux) {
  stream << heat_flux.Print();
  return stream;
}

template <typename NumericType>
inline constexpr HeatFlux<NumericType> operator*(
    const NumericType number, const HeatFlux<NumericType>& heat_flux) {
  return heat_flux * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const HeatFlux<NumericType>& heat_flux)
  : Direction<NumericType>(heat_flux.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const HeatFlux<NumericType>& heat_flux_1, const HeatFlux<NumericType>& heat_flux_2)
  : Angle<NumericType>(heat_flux_1.Value(), heat_flux_2.Value()) {}

template <typename NumericType>
inline constexpr HeatFlux<NumericType> Direction<NumericType>::operator*(
    const ScalarHeatFlux<NumericType>& scalar_heat_flux) const {
  return HeatFlux<NumericType>{scalar_heat_flux, *this};
}

template <typename NumericType>
inline constexpr HeatFlux<NumericType> ScalarHeatFlux<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return HeatFlux<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr PlanarHeatFlux<NumericType>::PlanarHeatFlux(const HeatFlux<NumericType>& heat_flux)
  : PlanarHeatFlux(PlanarVector<NumericType>{heat_flux.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::HeatFlux<NumericType>> {
  inline size_t operator()(const PhQ::HeatFlux<NumericType>& heat_flux) const {
    return hash<PhQ::Vector<NumericType>>()(heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_FLUX_HPP
