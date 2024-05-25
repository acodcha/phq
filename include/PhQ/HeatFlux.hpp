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
#include "ScalarHeatFlux.hpp"
#include "ScalarThermalConductivity.hpp"
#include "TemperatureGradient.hpp"
#include "ThermalConductivity.hpp"
#include "Unit/EnergyFlux.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Heat flux vector. See also PhQ::ScalarHeatFlux.
template <typename Number = double>
class HeatFlux : public DimensionalVector<Unit::EnergyFlux, Number> {
public:
  /// \brief Default constructor. Constructs a heat flux vector with an uninitialized value.
  HeatFlux() = default;

  /// \brief Constructor. Constructs a heat flux vector with a given value expressed in a given
  /// energy flux unit.
  HeatFlux(const Vector<Number>& value, const Unit::EnergyFlux unit)
    : DimensionalVector<Unit::EnergyFlux, Number>(value, unit) {}

  /// \brief Constructor. Constructs a heat flux vector from a given scalar heat flux magnitude and
  /// direction.
  constexpr HeatFlux(
      const ScalarHeatFlux<Number>& scalar_heat_flux, const Direction<Number>& direction)
    : HeatFlux<Number>(scalar_heat_flux.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a heat flux vector from a given scalar thermal conductivity and
  /// temperature gradient vector using Fourier's law of heat conduction. Since heat flows opposite
  /// the temperature gradient, the resulting heat flux direction is opposite the temperature
  /// gradient direction.
  constexpr HeatFlux(const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
                     const TemperatureGradient<Number>& temperature_gradient)
    : HeatFlux<Number>(-scalar_thermal_conductivity.Value() * temperature_gradient.Value()) {}

  /// \brief Constructor. Constructs a heat flux vector from a given thermal conductivity tensor and
  /// temperature gradient vector using Fourier's law of heat conduction. Since heat flows opposite
  /// the temperature gradient, the resulting heat flux direction is opposite the temperature
  /// gradient direction.
  constexpr HeatFlux(const ThermalConductivity<Number>& thermal_conductivity,
                     const TemperatureGradient<Number>& temperature_gradient)
    : HeatFlux<Number>(-1.0 * thermal_conductivity.Value() * temperature_gradient.Value()) {}

  /// \brief Destructor. Destroys this heat flux vector.
  ~HeatFlux() noexcept = default;

  /// \brief Copy constructor. Constructs a heat flux vector by copying another one.
  constexpr HeatFlux(const HeatFlux<Number>& other) = default;

  /// \brief Copy constructor. Constructs a heat flux vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr HeatFlux(const HeatFlux<OtherNumber>& other)
    : HeatFlux(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a heat flux vector by moving another one.
  constexpr HeatFlux(HeatFlux<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this heat flux vector by copying another one.
  constexpr HeatFlux<Number>& operator=(const HeatFlux<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this heat flux vector by copying another one.
  template <typename OtherNumber>
  constexpr HeatFlux<Number>& operator=(const HeatFlux<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this heat flux vector by moving another one.
  constexpr HeatFlux<Number>& operator=(HeatFlux<Number>&& other) noexcept = default;

  /// \brief Statically creates a heat flux vector of zero.
  static constexpr HeatFlux<Number> Zero() {
    return HeatFlux<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a heat flux vector from the given x, y, and z Cartesian components
  /// expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<Number> Create(const Number x, const Number y, const Number z) {
    return HeatFlux<Number>{StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
        Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a heat flux vector from the given x, y, and z Cartesian components
  /// expressed in a given energy flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<Number> Create(const std::array<Number, 3>& x_y_z) {
    return HeatFlux<Number>{StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(
        Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a heat flux vector with a given value expressed in a given energy
  /// flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr HeatFlux<Number> Create(const Vector<Number>& value) {
    return HeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  /// \brief Returns the x Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> x() const noexcept {
    return ScalarHeatFlux<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> y() const noexcept {
    return ScalarHeatFlux<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this heat flux vector.
  [[nodiscard]] constexpr ScalarHeatFlux<Number> z() const noexcept {
    return ScalarHeatFlux<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this heat flux vector.
  [[nodiscard]] ScalarHeatFlux<Number> Magnitude() const {
    return ScalarHeatFlux<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this heat flux vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this heat flux vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const HeatFlux<Number>& heat_flux) const {
    return PhQ::Angle<Number>{*this, heat_flux};
  }

  constexpr HeatFlux<Number> operator+(const HeatFlux<Number>& heat_flux) const {
    return HeatFlux<Number>{this->value + heat_flux.value};
  }

  constexpr HeatFlux<Number> operator-(const HeatFlux<Number>& heat_flux) const {
    return HeatFlux<Number>{this->value - heat_flux.value};
  }

  constexpr HeatFlux<Number> operator*(const Number number) const {
    return HeatFlux<Number>{this->value * number};
  }

  constexpr HeatFlux<Number> operator/(const Number number) const {
    return HeatFlux<Number>{this->value / number};
  }

  constexpr void operator+=(const HeatFlux<Number>& heat_flux) noexcept {
    this->value += heat_flux.value;
  }

  constexpr void operator-=(const HeatFlux<Number>& heat_flux) noexcept {
    this->value -= heat_flux.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a heat flux vector with a given value expressed in the standard
  /// energy flux unit.
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
